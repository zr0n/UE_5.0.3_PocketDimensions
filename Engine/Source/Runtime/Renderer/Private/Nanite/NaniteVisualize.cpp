// Copyright Epic Games, Inc. All Rights Reserved.

#include "NaniteVisualize.h"
#include "NaniteVisualizationData.h"
#include "PostProcess/SceneFilterRendering.h"
#include "PostProcess/PostProcessing.h"
#include "PostProcess/PostProcessVisualizeComplexity.h"
#include "PostProcess/SceneRenderTargets.h"
#include "PixelShaderUtils.h"
#include "SceneTextureReductions.h"
#include "SceneManagement.h"
#include "Rendering/NaniteStreamingManager.h"
#include "DebugViewModeHelpers.h"

// Specifies if visualization only shows Nanite information that passes full scene depth test
// -1: Use default composition specified the each mode
//  0: Force composition with scene depth off
//  1: Force composition with scene depth on
int32 GNaniteVisualizeComposite = -1;
FAutoConsoleVariableRef CVarNaniteVisualizeComposite(
	TEXT("r.Nanite.Visualize.Composite"),
	GNaniteVisualizeComposite,
	TEXT("")
);

int32 GNaniteVisualizeEdgeDetect = 1;
static FAutoConsoleVariableRef CVarNaniteVisualizeEdgeDetect(
	TEXT("r.Nanite.Visualize.EdgeDetect"),
	GNaniteVisualizeEdgeDetect,
	TEXT("")
);

int32 GNaniteVisualizeOverdrawScale = 15; // % of contribution per pixel evaluation (up to 100%)
FAutoConsoleVariableRef CVarNaniteVisualizeOverdrawScale(
	TEXT("r.Nanite.Visualize.OverdrawScale"),
	GNaniteVisualizeOverdrawScale,
	TEXT("")
);

int32 GNaniteVisualizeComplexityScale = 80; // % of contribution per material evaluation (up to 100%)
FAutoConsoleVariableRef CVarNaniteVisualizeComplexityScale(
	TEXT("r.Nanite.Visualize.ComplexityScale"),
	GNaniteVisualizeComplexityScale,
	TEXT("")
);

// Fudge factor chosen by visually comparing Nanite vs non-Nanite cube shader complexity using default material, and choosing value where colors match.
int32 GNaniteVisualizeComplexityOverhead = 7400; // Baseline overhead of Nanite ALU (added to global shader budget)
FAutoConsoleVariableRef CVarNaniteVisualizeComplexityOverhead(
	TEXT("r.Nanite.Visualize.ComplexityOverhead"),
	GNaniteVisualizeComplexityOverhead,
	TEXT("")
);

static FIntVector4 GetVisualizeConfig(int32 ModeID, bool bCompositeScene, bool bEdgeDetect)
{
	if (ModeID != INDEX_NONE)
	{
		return FIntVector4(ModeID, 0 /* Unused */, bCompositeScene ? 1 : 0, bEdgeDetect ? 1 : 0);
	}

	return FIntVector4(INDEX_NONE, 0, 0, 0);
}

static FIntVector4 GetVisualizeScales(int32 ModeID)
{
	if (ModeID != INDEX_NONE)
	{
		return FIntVector4(GNaniteVisualizeOverdrawScale, GNaniteVisualizeComplexityScale, 0 /* Unused */, 0 /* Unused */);
	}

	return FIntVector4(INDEX_NONE, 0, 0, 0);
}

class FNaniteVisualizeCS : public FNaniteGlobalShader
{
	DECLARE_GLOBAL_SHADER(FNaniteVisualizeCS);
	SHADER_USE_PARAMETER_STRUCT(FNaniteVisualizeCS, FNaniteGlobalShader);

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return DoesPlatformSupportNanite(Parameters.Platform);
	}

	static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FNaniteGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
		OutEnvironment.SetDefine(TEXT("NANITE_USE_VIEW_UNIFORM_BUFFER"), 1);
	}

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<float4>, DebugOutput)
		SHADER_PARAMETER(FIntVector4, VisualizeConfig)
		SHADER_PARAMETER(FIntVector4, VisualizeScales)
		SHADER_PARAMETER(FIntVector4, PageConstants)
		SHADER_PARAMETER(uint32, MaxVisibleClusters)
		SHADER_PARAMETER(uint32, RenderFlags)
		SHADER_PARAMETER_STRUCT_REF(FViewUniformShaderParameters, View)
		SHADER_PARAMETER_SRV(ByteAddressBuffer, ClusterPageData)
		SHADER_PARAMETER_RDG_BUFFER_SRV(ByteAddressBuffer, VisibleClustersSWHW)
		SHADER_PARAMETER_RDG_TEXTURE(Texture2D<UlongType>, VisBuffer64)
		SHADER_PARAMETER_RDG_TEXTURE(Texture2D<UlongType>, DbgBuffer64)
		SHADER_PARAMETER_RDG_TEXTURE(Texture2D<uint>, DbgBuffer32)
		SHADER_PARAMETER_RDG_TEXTURE(Texture2D<uint>, MaterialResolve)
		SHADER_PARAMETER_RDG_TEXTURE(Texture2D<float>, SceneDepth)
		SHADER_PARAMETER_RDG_TEXTURE(Texture2D<uint>, MaterialComplexity)
		SHADER_PARAMETER_SRV(ByteAddressBuffer, MaterialSlotTable)
		SHADER_PARAMETER_SRV(ByteAddressBuffer, MaterialDepthTable)
		SHADER_PARAMETER_SRV(ByteAddressBuffer, MaterialHitProxyTable)
	END_SHADER_PARAMETER_STRUCT()
};
IMPLEMENT_GLOBAL_SHADER(FNaniteVisualizeCS, "/Engine/Private/Nanite/NaniteVisualize.usf", "VisualizeCS", SF_Compute);

class FMaterialComplexityCS : public FNaniteGlobalShader
{
public:
	DECLARE_GLOBAL_SHADER(FMaterialComplexityCS);
	SHADER_USE_PARAMETER_STRUCT(FMaterialComplexityCS, FNaniteGlobalShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_STRUCT_REF(FViewUniformShaderParameters, View)
		SHADER_PARAMETER_RDG_BUFFER_SRV(ByteAddressBuffer, VisibleClustersSWHW)
		SHADER_PARAMETER(FIntVector4, PageConstants)
		SHADER_PARAMETER(FIntVector4, ViewRect)
		SHADER_PARAMETER_SRV(ByteAddressBuffer, ClusterPageData)
		SHADER_PARAMETER_RDG_TEXTURE(Texture2D<UlongType>, VisBuffer64)
		SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<uint>, MaterialComplexity)
		SHADER_PARAMETER_SRV(ByteAddressBuffer, MaterialSlotTable)
		SHADER_PARAMETER_SRV(ByteAddressBuffer, MaterialDepthTable)
	END_SHADER_PARAMETER_STRUCT()

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return DoesPlatformSupportNanite(Parameters.Platform);
	}

	static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FNaniteGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
	}
};
IMPLEMENT_GLOBAL_SHADER(FMaterialComplexityCS, "/Engine/Private/Nanite/NaniteMaterialComplexity.usf", "CalculateMaterialComplexity", SF_Compute);

class FExportDebugViewPS : public FNaniteGlobalShader
{
public:
	DECLARE_GLOBAL_SHADER(FExportDebugViewPS);
	SHADER_USE_PARAMETER_STRUCT(FExportDebugViewPS, FNaniteGlobalShader);

	class FSearchBufferCountDim : SHADER_PERMUTATION_INT("EDITOR_SELECTED_BUFFER_COUNT_LOG_2", 25);
	using FPermutationDomain = TShaderPermutationDomain<FSearchBufferCountDim>;

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_STRUCT_REF(FViewUniformShaderParameters, View)
		SHADER_PARAMETER_RDG_BUFFER_SRV(ByteAddressBuffer, VisibleClustersSWHW)
		SHADER_PARAMETER(FIntVector4, PageConstants)
		SHADER_PARAMETER(FIntVector4, ViewRect)
		SHADER_PARAMETER(float, InvShaderBudget)
		SHADER_PARAMETER(FVector3f, SelectionColor)
		SHADER_PARAMETER(uint32, DebugViewMode)
		SHADER_PARAMETER_SRV(ByteAddressBuffer, ClusterPageData)
		SHADER_PARAMETER_RDG_TEXTURE(Texture2D<UlongType>, VisBuffer64)
		SHADER_PARAMETER_RDG_TEXTURE(Texture2D<float>, SceneDepth)
		SHADER_PARAMETER_RDG_TEXTURE(Texture2D<uint>, MaterialResolve)
		SHADER_PARAMETER_SRV(ByteAddressBuffer, MaterialSlotTable)
		SHADER_PARAMETER_SRV(ByteAddressBuffer, MaterialDepthTable)
		SHADER_PARAMETER_SRV(ByteAddressBuffer, MaterialEditorTable)
		SHADER_PARAMETER_SRV(ByteAddressBuffer, MaterialHitProxyTable)
		RENDER_TARGET_BINDING_SLOTS()
	END_SHADER_PARAMETER_STRUCT()


	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return DoesPlatformSupportNanite(Parameters.Platform) && FDataDrivenShaderPlatformInfo::GetSupportsDebugViewShaders(Parameters.Platform);
	}

	static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FNaniteGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
		OutEnvironment.SetDefine(TEXT("NANITE_USE_VIEW_UNIFORM_BUFFER"), 1);

		FPermutationDomain PermutationVector(Parameters.PermutationId);
		uint32 SelectedBufferCount = 1u << (uint32)PermutationVector.Get<FSearchBufferCountDim>();
		OutEnvironment.SetDefine(TEXT("EDITOR_SELECTED_BUFFER_COUNT"), SelectedBufferCount);
	}
};
IMPLEMENT_GLOBAL_SHADER(FExportDebugViewPS, "/Engine/Private/Nanite/NaniteDebugViews.usf", "ExportDebugViewPS", SF_Pixel);

// TODO: Move to common location outside of Nanite
class FHTileVisualizeCS : public FNaniteGlobalShader
{
	DECLARE_GLOBAL_SHADER(FHTileVisualizeCS);
	SHADER_USE_PARAMETER_STRUCT(FHTileVisualizeCS, FNaniteGlobalShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_RDG_TEXTURE_SRV(TextureMetadata, HTileBuffer)
		SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<float4>, HTileDisplay)
		SHADER_PARAMETER(FIntVector4, HTileConfig)
		SHADER_PARAMETER_STRUCT_REF(FViewUniformShaderParameters, View)
	END_SHADER_PARAMETER_STRUCT()
};
IMPLEMENT_GLOBAL_SHADER(FHTileVisualizeCS, "/Engine/Private/HTileVisualize.usf", "VisualizeHTile", SF_Compute);

namespace Nanite
{

void AddVisualizationPasses(
	FRDGBuilder& GraphBuilder,
	const FScene* Scene,
	const FSceneTextures& SceneTextures,
	const FEngineShowFlags& EngineShowFlags,
	TArrayView<const FViewInfo> Views,
	TArrayView<Nanite::FRasterResults> Results
)
{
	checkSlow(DoesPlatformSupportNanite(GMaxRHIShaderPlatform));

	const FNaniteVisualizationData& VisualizationData = GetNaniteVisualizationData();

	// We only support debug visualization on the first view (at the moment)
	if (Scene && Views.Num() > 0 && VisualizationData.IsActive() && EngineShowFlags.VisualizeNanite)
	{
		// These should always match 1:1
		if (ensure(Views.Num() == Results.Num()))
		{
			Nanite::FRasterResults& Data = Results[0];
			const FViewInfo& View = Views[0];

			// TODO: Don't currently support offset views.
			checkf(View.ViewRect.Min.X == 0 && View.ViewRect.Min.Y == 0, TEXT("Viewport offset support is not implemented."));

			const int32 ViewWidth  = View.ViewRect.Max.X - View.ViewRect.Min.X;
			const int32 ViewHeight = View.ViewRect.Max.Y - View.ViewRect.Min.Y;
			const FIntPoint ViewSize = FIntPoint(ViewWidth, ViewHeight);

			LLM_SCOPE_BYTAG(Nanite);
			RDG_EVENT_SCOPE(GraphBuilder, "Nanite::Visualization");
			RDG_GPU_STAT_SCOPE(GraphBuilder, NaniteDebug);

			const FRDGSystemTextures& SystemTextures = FRDGSystemTextures::Get(GraphBuilder);

			FRDGTextureRef VisBuffer64		= Data.VisBuffer64 ? Data.VisBuffer64 : SystemTextures.Black;
			FRDGTextureRef DbgBuffer64		= Data.DbgBuffer64 ? Data.DbgBuffer64 : SystemTextures.Black;
			FRDGTextureRef DbgBuffer32		= Data.DbgBuffer32 ? Data.DbgBuffer32 : SystemTextures.Black;
			FRDGTextureRef MaterialResolve	= Data.MaterialResolve ? Data.MaterialResolve : SystemTextures.Black;

			FRDGBufferRef VisibleClustersSWHW = Data.VisibleClustersSWHW;

			// Generate material complexity
			FRDGTextureRef MaterialComplexity = nullptr;
			{
				const FIntPoint TileGridDim = FMath::DivideAndRoundUp(ViewSize, { 8, 8 });

				FRDGTextureDesc MaterialComplexityDesc = FRDGTextureDesc::Create2D(TileGridDim, PF_R32_UINT, FClearValueBinding::Black, TexCreate_ShaderResource | TexCreate_UAV);
				MaterialComplexity = GraphBuilder.CreateTexture(MaterialComplexityDesc, TEXT("Nanite.MaterialComplexity"));
				FRDGTextureUAVRef MaterialComplexityUAV = GraphBuilder.CreateUAV(MaterialComplexity);

				FMaterialComplexityCS::FParameters* PassParameters = GraphBuilder.AllocParameters<FMaterialComplexityCS::FParameters>();
				PassParameters->View					= View.ViewUniformBuffer;
				PassParameters->VisibleClustersSWHW		= GraphBuilder.CreateSRV(VisibleClustersSWHW);
				PassParameters->PageConstants			= Data.PageConstants;
				PassParameters->ClusterPageData			= Nanite::GStreamingManager.GetClusterPageDataSRV();
				PassParameters->VisBuffer64				= VisBuffer64;
				PassParameters->MaterialSlotTable		= Scene->NaniteMaterials[ENaniteMeshPass::BasePass].GetMaterialSlotSRV();
				PassParameters->MaterialDepthTable		= Scene->NaniteMaterials[ENaniteMeshPass::BasePass].GetMaterialDepthSRV();
				PassParameters->MaterialComplexity		= MaterialComplexityUAV;

				auto ComputeShader = View.ShaderMap->GetShader<FMaterialComplexityCS>();
				FComputeShaderUtils::AddPass(
					GraphBuilder,
					RDG_EVENT_NAME("MaterialComplexity"),
					ERDGPassFlags::Compute | ERDGPassFlags::NeverCull,
					ComputeShader,
					PassParameters,
					FComputeShaderUtils::GetGroupCount(ViewSize, 8)
				);
			}

			Data.Visualizations.Reset();

			if (VisualizationData.GetActiveModeID() > 0)
			{
				// Single visualization
				FVisualizeResult Visualization = {};
				Visualization.ModeName			= VisualizationData.GetActiveModeName();
				Visualization.ModeID			= VisualizationData.GetActiveModeID();
				Visualization.bCompositeScene	= VisualizationData.GetActiveModeDefaultComposited();
				Visualization.bSkippedTile		= false;
				Data.Visualizations.Emplace(Visualization);
			}
			else if (VisualizationData.GetActiveModeID() == 0)
			{
				// Overview mode
				const auto& OverviewModeNames = VisualizationData.GetOverviewModeNames();
				for (const FName& ModeName : OverviewModeNames)
				{
					FVisualizeResult Visualization = {};
					Visualization.ModeName			= ModeName;
					Visualization.ModeID			= VisualizationData.GetModeID(Visualization.ModeName);
					Visualization.bCompositeScene	= VisualizationData.GetModeDefaultComposited(Visualization.ModeName);
					Visualization.bSkippedTile		= Visualization.ModeName == NAME_None;
					Data.Visualizations.Emplace(Visualization);
				}
			}

			for (FVisualizeResult& Visualization : Data.Visualizations)
			{
				if (Visualization.bSkippedTile)
				{
					continue;
				}

				// Apply force off/on scene composition
				if (GNaniteVisualizeComposite == 0)
				{
					// Force off
					Visualization.bCompositeScene = false;
				}
				else if (GNaniteVisualizeComposite == 1)
				{
					// Force on
					Visualization.bCompositeScene = true;
				}

				FRDGTextureDesc VisualizationOutputDesc = FRDGTextureDesc::Create2D(
					View.ViewRect.Max,
					PF_A32B32G32R32F,
					FClearValueBinding::None,
					TexCreate_ShaderResource | TexCreate_UAV);

				Visualization.ModeOutput = GraphBuilder.CreateTexture(VisualizationOutputDesc, TEXT("Nanite.Visualization"));

				FNaniteVisualizeCS::FParameters* PassParameters = GraphBuilder.AllocParameters<FNaniteVisualizeCS::FParameters>();

				PassParameters->View = View.ViewUniformBuffer;
				PassParameters->ClusterPageData = Nanite::GStreamingManager.GetClusterPageDataSRV();
				PassParameters->VisualizeConfig = GetVisualizeConfig(Visualization.ModeID, Visualization.bCompositeScene, GNaniteVisualizeEdgeDetect != 0);
				PassParameters->VisualizeScales = GetVisualizeScales(Visualization.ModeID);
				PassParameters->PageConstants = Data.PageConstants;
				PassParameters->MaxVisibleClusters = Data.MaxVisibleClusters;
				PassParameters->RenderFlags = Data.RenderFlags;
				PassParameters->VisibleClustersSWHW = GraphBuilder.CreateSRV(VisibleClustersSWHW);
				PassParameters->VisBuffer64 = VisBuffer64;
				PassParameters->DbgBuffer64 = DbgBuffer64;
				PassParameters->DbgBuffer32 = DbgBuffer32;
				PassParameters->MaterialResolve = MaterialResolve;
				PassParameters->SceneDepth = SceneTextures.Depth.Target;
				PassParameters->MaterialComplexity = MaterialComplexity ? MaterialComplexity : SystemTextures.Black;
				PassParameters->MaterialSlotTable = Scene->NaniteMaterials[ENaniteMeshPass::BasePass].GetMaterialSlotSRV();
				PassParameters->MaterialDepthTable = Scene->NaniteMaterials[ENaniteMeshPass::BasePass].GetMaterialDepthSRV();
			#if WITH_EDITOR
				PassParameters->MaterialHitProxyTable = Scene->NaniteMaterials[ENaniteMeshPass::BasePass].GetHitProxyTableSRV();
			#else
				// TODO: Permutation with hit proxy support to keep this clean?
				// For now, bind a valid SRV
				PassParameters->MaterialHitProxyTable = Scene->NaniteMaterials[ENaniteMeshPass::BasePass].GetMaterialSlotSRV();
			#endif
				PassParameters->DebugOutput = GraphBuilder.CreateUAV(Visualization.ModeOutput);

				auto ComputeShader = View.ShaderMap->GetShader<FNaniteVisualizeCS>();
				FComputeShaderUtils::AddPass(
					GraphBuilder,
					RDG_EVENT_NAME("Nanite::Visualize"),
					ERDGPassFlags::Compute | ERDGPassFlags::NeverCull,
					ComputeShader,
					PassParameters,
					FComputeShaderUtils::GetGroupCount(ViewSize, 8)
				);
			}
		}
	}
}

#if 0 // TODO: NANITE_VIEW_MODES: Reimplement HTILE
void DrawVisualization(
	FRDGBuilder& GraphBuilder,
	FRDGTextureRef SceneDepth,
	const FScene& Scene,
	const FViewInfo& View,
	const FRasterResults& RasterResults
)
{
	checkSlow(DoesPlatformSupportNanite(GMaxRHIShaderPlatform));

	LLM_SCOPE_BYTAG(Nanite);
	RDG_EVENT_SCOPE(GraphBuilder, "NaniteVisualization");
	RDG_GPU_STAT_SCOPE(GraphBuilder, NaniteDebug);

	const int32 ViewWidth    = View.ViewRect.Max.X - View.ViewRect.Min.X;
	const int32 ViewHeight   = View.ViewRect.Max.Y - View.ViewRect.Min.Y;
	const FIntPoint ViewSize = FIntPoint(ViewWidth, ViewHeight);

	// Visualize Debug Views
	if (ShouldExportDebugBuffers())
	{
		// TODO: Don't currently support offset views.
		checkf(View.ViewRect.Min.X == 0 && View.ViewRect.Min.Y == 0, TEXT("Viewport offset support is not implemented."));

		const FRDGSystemTextures& SystemTextures = FRDGSystemTextures::Get(GraphBuilder);

		FRDGTextureRef VisBuffer64		= RasterResults.VisBuffer64 ? RasterResults.VisBuffer64 : SystemTextures.Black;
		FRDGTextureRef DbgBuffer64		= RasterResults.DbgBuffer64 ? RasterResults.DbgBuffer64 : SystemTextures.Black;
		FRDGTextureRef DbgBuffer32		= RasterResults.DbgBuffer32 ? RasterResults.DbgBuffer32 : SystemTextures.Black;
		FRDGTextureRef NaniteMask		= RasterResults.NaniteMask ? RasterResults.NaniteMask : SystemTextures.Black;
		FRDGTextureRef VelocityBuffer	= RasterResults.VelocityBuffer ? RasterResults.VelocityBuffer : SystemTextures.Black;

		FRDGBufferRef VisibleClustersSWHW = RasterResults.VisibleClustersSWHW;

		FRDGTextureDesc VisualizeOutputDesc = FRDGTextureDesc::Create2D(
			View.ViewRect.Max,
			PF_A32B32G32R32F,
			FClearValueBinding::None,
			TexCreate_ShaderResource | TexCreate_UAV);

		FRDGTextureRef DebugOutput = GraphBuilder.CreateTexture(VisualizeOutputDesc, TEXT("Nanite.Visualize"));

		FNaniteVisualizeCS::FParameters* PassParameters = GraphBuilder.AllocParameters<FNaniteVisualizeCS::FParameters>();

		PassParameters->View					= View.ViewUniformBuffer;
		PassParameters->ClusterPageData			= Nanite::GStreamingManager.GetClusterPageDataSRV();
		PassParameters->VisualizeConfig			= GetVisualizeConfig();
		PassParameters->PageConstants			= RasterResults.PageConstants;
		PassParameters->MaxVisibleClusters		= RasterResults.MaxVisibleClusters;
		PassParameters->RenderFlags				= RasterResults.RenderFlags;
		PassParameters->VisibleClustersSWHW		= GraphBuilder.CreateSRV(VisibleClustersSWHW);
		PassParameters->VisBuffer64				= VisBuffer64;
		PassParameters->DbgBuffer64				= DbgBuffer64;
		PassParameters->DbgBuffer32				= DbgBuffer32;
		PassParameters->NaniteMask				= NaniteMask;
		PassParameters->SceneDepth				= SceneDepth;
		PassParameters->MaterialSlotTable		= Scene.NaniteMaterials[ENaniteMeshPass::BasePass].GetMaterialSlotSRV();
		PassParameters->MaterialDepthTable		= Scene.NaniteMaterials[ENaniteMeshPass::BasePass].GetMaterialDepthSRV();
	#if WITH_EDITOR
		PassParameters->MaterialHitProxyTable	= Scene.NaniteMaterials[ENaniteMeshPass::BasePass].GetHitProxyTableSRV();
	#else
		// TODO: Permutation with hit proxy support to keep this clean?
		// For now, bind a valid SRV
		PassParameters->MaterialHitProxyTable	= Scene->NaniteMaterials[ENaniteMeshPass::BasePass].GetMaterialSlotSRV();
	#endif
		PassParameters->DebugOutput				= GraphBuilder.CreateUAV(DebugOutput);

		auto ComputeShader = View.ShaderMap->GetShader<FNaniteVisualizeCS>();
		FComputeShaderUtils::AddPass(
			GraphBuilder,
			RDG_EVENT_NAME("Visualization"),
			ERDGPassFlags::Compute | ERDGPassFlags::NeverCull,
			ComputeShader,
			PassParameters,
			FComputeShaderUtils::GetGroupCount(ViewSize, 8)
		);
	}

	if (IsVisualizingHTile())
	{
		// TODO: Don't currently support offset views.
		checkf(View.ViewRect.Min.X == 0 && View.ViewRect.Min.Y == 0, TEXT("Viewport offset support is not implemented."));

		FRDGTextureSRVRef HTileSRV = nullptr;

		if (RasterResults.MaterialDepth)
		{
			if (GNaniteDebugVisualize == VISUALIZE_MAT_HTILE_MINZ ||
				GNaniteDebugVisualize == VISUALIZE_MAT_HTILE_MAXZ ||
				GNaniteDebugVisualize == VISUALIZE_MAT_HTILE_DELTAZ ||
				GNaniteDebugVisualize == VISUALIZE_MAT_HTILE_ZMASK)
			{
				HTileSRV = GraphBuilder.CreateSRV(FRDGTextureSRVDesc::CreateForMetaData(RasterResults.MaterialDepth, ERDGTextureMetaDataAccess::HTile));
			}
		}

		if (!HTileSRV)
		{
			HTileSRV = GraphBuilder.CreateSRV(FRDGTextureSRVDesc::CreateForMetaData(SceneDepth, ERDGTextureMetaDataAccess::HTile));
		}

		FRDGTextureRef DebugOutput = GraphBuilder.CreateTexture(
			FRDGTextureDesc::Create2D(
			SceneDepth->Desc.Extent,
			PF_A32B32G32R32F,
			FClearValueBinding::None,
			TexCreate_ShaderResource | TexCreate_UAV),
			TEXT("Nanite.Debug"));

		FHTileVisualizeCS::FParameters* PassParameters = GraphBuilder.AllocParameters<FHTileVisualizeCS::FParameters>();

		const uint32 PixelsWide = uint32(ViewSize.X);
		const uint32 PixelsTall = uint32(ViewSize.Y);
		const uint32 PlatformConfig = RHIGetHTilePlatformConfig(PixelsWide, PixelsTall);

		PassParameters->HTileBuffer = HTileSRV;
		PassParameters->HTileDisplay = GraphBuilder.CreateUAV(DebugOutput);
		PassParameters->HTileConfig  = FIntVector4(PlatformConfig, PixelsWide, GNaniteDebugVisualize, 0);

		auto ComputeShader = View.ShaderMap->GetShader<FHTileVisualizeCS>();

		FComputeShaderUtils::AddPass(
			GraphBuilder,
			RDG_EVENT_NAME("HTileVisualize"),
			ERDGPassFlags::Compute | ERDGPassFlags::NeverCull,
			ComputeShader,
			PassParameters,
			FComputeShaderUtils::GetGroupCount(ViewSize, 8)
		);
	}
}
#endif

#if WITH_DEBUG_VIEW_MODES

void RenderDebugViewMode(
	FRDGBuilder& GraphBuilder,
	EDebugViewMode DebugViewMode,
	const FScene& Scene,
	const FViewInfo& View,
	const FSceneViewFamily& ViewFamily,
	const FRasterResults& RasterResults,
	FRDGTextureRef OutputColorTexture,
	FRDGTextureRef InputDepthTexture,
	FRDGTextureRef QuadOverdrawTexture
)
{
	LLM_SCOPE_BYTAG(Nanite);
	RDG_EVENT_SCOPE(GraphBuilder, "Nanite::DebugView");
	RDG_GPU_STAT_SCOPE(GraphBuilder, NaniteDebug);

	const uint32 GlobalShaderBudget = GetMaxShaderComplexityCount(View.GetFeatureLevel());

	// Increase the shader budget for Nanite meshes to account for baseline ALU overhead.
	const uint32 NaniteShaderBudget = GlobalShaderBudget + uint32(GNaniteVisualizeComplexityOverhead);

	const FLinearColor SelectionColor = GetSelectionColor(FLinearColor::White, true /* selected */, false /* hovered */, false /* use overlay intensity */);

	// TODO: Need to apply hover intensity to per-primitive wireframe color, not white
	//const FLinearColor HoveredColor = GetSelectionColor(FLinearColor::White, false /* selected */, true /* hovered */);

	FExportDebugViewPS::FParameters* PassParameters = GraphBuilder.AllocParameters<FExportDebugViewPS::FParameters>();
	PassParameters->View = View.ViewUniformBuffer;
	PassParameters->VisibleClustersSWHW = GraphBuilder.CreateSRV(RasterResults.VisibleClustersSWHW);
	PassParameters->PageConstants = RasterResults.PageConstants;
	PassParameters->ViewRect = FIntVector4(View.ViewRect.Min.X, View.ViewRect.Min.Y, View.ViewRect.Max.X, View.ViewRect.Max.Y);
	PassParameters->InvShaderBudget = 1.0f / float(NaniteShaderBudget);
	PassParameters->SelectionColor = FVector3f(SelectionColor.R, SelectionColor.G, SelectionColor.B);
	PassParameters->DebugViewMode = uint32(DebugViewMode);
	PassParameters->ClusterPageData = Nanite::GStreamingManager.GetClusterPageDataSRV();
	PassParameters->VisBuffer64 = RasterResults.VisBuffer64;
	PassParameters->SceneDepth = InputDepthTexture;
	PassParameters->MaterialResolve = RasterResults.MaterialResolve;
	PassParameters->MaterialSlotTable = Scene.NaniteMaterials[ENaniteMeshPass::BasePass].GetMaterialSlotSRV();
	PassParameters->MaterialDepthTable = Scene.NaniteMaterials[ENaniteMeshPass::BasePass].GetMaterialDepthSRV();
	PassParameters->MaterialEditorTable = Scene.NaniteMaterials[ENaniteMeshPass::BasePass].GetMaterialEditorSRV();
#if WITH_EDITOR
	PassParameters->MaterialHitProxyTable = Scene.NaniteMaterials[ENaniteMeshPass::BasePass].GetHitProxyTableSRV();
#endif
	PassParameters->RenderTargets[0] = FRenderTargetBinding(OutputColorTexture, ERenderTargetLoadAction::ELoad, 0);

#if WITH_EDITOR
	const uint32 HitProxyIdCount = View.EditorSelectedHitProxyIds.Num();
#else
	const uint32 HitProxyIdCount = 0;
#endif

	const uint32 SelectionCount = FMath::RoundUpToPowerOfTwo(HitProxyIdCount);
	const uint32 SearchBufferCountDim = FMath::Min(uint32(FExportDebugViewPS::FSearchBufferCountDim::MaxValue), FMath::FloorLog2(SelectionCount));

	FExportDebugViewPS::FPermutationDomain PermutationVector;
	PermutationVector.Set<FExportDebugViewPS::FSearchBufferCountDim>(SearchBufferCountDim);

	auto PixelShader = View.ShaderMap->GetShader<FExportDebugViewPS>(PermutationVector.ToDimensionValueId());

	FPixelShaderUtils::AddFullscreenPass(
		GraphBuilder,
		View.ShaderMap,
		RDG_EVENT_NAME("Export Debug View"),
		PixelShader,
		PassParameters,
		View.ViewRect
	);
}

#endif // WITH_DEBUG_VIEW_MODES

} // namespace Nanite
