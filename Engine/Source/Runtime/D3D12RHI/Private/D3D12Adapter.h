// Copyright Epic Games, Inc. All Rights Reserved.

/*=============================================================================
D3D12Adapter.h: D3D12 Adapter Interfaces

The D3D12 RHI is layed out in the following stucture. 

	[Engine]--
			|
			|-[RHI]--
					|
					|-[Adapter]-- (LDA)
					|			|
					|			|- [Device]
					|			|
					|			|- [Device]
					|
					|-[Adapter]--
								|
								|- [Device]--
											|
											|-[CommandContext]
											|
											|-[CommandContext]---
																|
																|-[StateCache]

Under this scheme an FD3D12Device represents 1 node belonging to 1 physical adapter.

This structure allows a single RHI to control several different hardware setups. Some example arrangements:
	- Single-GPU systems (the common case)
	- Multi-GPU systems i.e. LDA (Crossfire/SLI)
	- Asymmetric Multi-GPU systems i.e. Discrete/Integrated GPU cooperation
=============================================================================*/

#pragma once

THIRD_PARTY_INCLUDES_START
#if PLATFORM_WINDOWS || PLATFORM_HOLOLENS
#include "dxgidebug.h"
#endif // PLATFORM_WINDOWS || PLATFORM_HOLOLENS
THIRD_PARTY_INCLUDES_END

class FD3D12DynamicRHI;

struct FD3D12AdapterDesc
{
	FD3D12AdapterDesc() = default;

	FD3D12AdapterDesc(const DXGI_ADAPTER_DESC& DescIn , int32 InAdapterIndex, D3D_FEATURE_LEVEL InMaxSupportedFeatureLevel, D3D_SHADER_MODEL InMaxSupportedShaderModel, uint32 NumNodes, bool InIsIntegrated
#if PLATFORM_WINDOWS || PLATFORM_HOLOLENS
		, DXGI_GPU_PREFERENCE InGpuPreference
#endif
	)
		: AdapterIndex(InAdapterIndex)
		, MaxSupportedFeatureLevel(InMaxSupportedFeatureLevel)
		, MaxSupportedShaderModel(InMaxSupportedShaderModel)
		, Desc(DescIn)
		, NumDeviceNodes(NumNodes)
		, bIsIntegrated(InIsIntegrated)
#if PLATFORM_WINDOWS || PLATFORM_HOLOLENS
		, GpuPreference(InGpuPreference)
#endif
	{
	}

	bool IsValid() const { return MaxSupportedFeatureLevel != (D3D_FEATURE_LEVEL)0 && AdapterIndex >= 0; }

#if PLATFORM_WINDOWS || PLATFORM_HOLOLENS
	static HRESULT EnumAdapters(int32 AdapterIndex, DXGI_GPU_PREFERENCE GpuPreference, IDXGIFactory* DxgiFactory, IDXGIFactory6* DxgiFactory6, IDXGIAdapter** TempAdapter)
	{
		if (!DxgiFactory6 || GpuPreference == DXGI_GPU_PREFERENCE_UNSPECIFIED)
		{
			return DxgiFactory->EnumAdapters(AdapterIndex, TempAdapter);
		}
		else
		{
			return DxgiFactory6->EnumAdapterByGpuPreference(AdapterIndex, GpuPreference, IID_PPV_ARGS(TempAdapter));
		}
	}

	HRESULT EnumAdapters(IDXGIFactory* DxgiFactory, IDXGIFactory6* DxgiFactory6, IDXGIAdapter** TempAdapter) const
	{
		return EnumAdapters(AdapterIndex, GpuPreference, DxgiFactory, DxgiFactory6, TempAdapter);
	}
#endif

	/** -1 if not supported or FindAdpater() wasn't called. Ideally we would store a pointer to IDXGIAdapter but it's unlikely the adpaters change during engine init. */
	int32 AdapterIndex{ -1 };

	/** The maximum D3D12 feature level supported. 0 if not supported or FindAdpater() wasn't called */
	D3D_FEATURE_LEVEL MaxSupportedFeatureLevel{ (D3D_FEATURE_LEVEL)0 };

	D3D_SHADER_MODEL MaxSupportedShaderModel{ D3D_SHADER_MODEL_5_1 };

	DXGI_ADAPTER_DESC Desc{};

	uint32 NumDeviceNodes{ 0 };

	/** Whether the GPU is integrated or discrete. */
	bool bIsIntegrated = false;

#if PLATFORM_WINDOWS || PLATFORM_HOLOLENS
	DXGI_GPU_PREFERENCE GpuPreference = DXGI_GPU_PREFERENCE_UNSPECIFIED;
#endif
};

struct FD3D12MemoryInfo
{
	DXGI_QUERY_VIDEO_MEMORY_INFO LocalMemoryInfo{};
	DXGI_QUERY_VIDEO_MEMORY_INFO NonLocalMemoryInfo{};

	uint32 UpdateFrameNumber = ~uint32(0);

	uint64 AvailableLocalMemory = 0;
	uint64 DemotedLocalMemory = 0;

	bool IsOverBudget() const
	{
		return DemotedLocalMemory > 0;
	}
};

class FTransientUniformBufferAllocator : public FD3D12FastConstantAllocator, public TThreadSingleton<FTransientUniformBufferAllocator>
{
public:
	FTransientUniformBufferAllocator(FD3D12Adapter* InAdapter, FD3D12Device* Parent, FRHIGPUMask VisibiltyMask) : FD3D12FastConstantAllocator(Parent, VisibiltyMask), Adapter(InAdapter) {}
	~FTransientUniformBufferAllocator();

	void Cleanup();
private:
	FD3D12Adapter* Adapter = nullptr;
};

enum class ED3D12GPUCrashDebuggingModes
{
	None				= 0x0,
	BreadCrumbs			= 0x1,
	NvAftermath			= 0x2,
	DRED				= 0x4,

	All					= BreadCrumbs | NvAftermath | DRED,
};
ENUM_CLASS_FLAGS(ED3D12GPUCrashDebuggingModes)

// Represents a set of linked D3D12 device nodes (LDA i.e 1 or more identical GPUs). In most cases there will be only 1 node, however if the system supports
// SLI/Crossfire and the app enables it an Adapter will have 2 or more nodes. This class will own anything that can be shared
// across LDA including: System Pool Memory,.Pipeline State Objects, Root Signatures etc.
class FD3D12Adapter : public FNoncopyable
{
public:

	FD3D12Adapter(FD3D12AdapterDesc& DescIn);
	virtual ~FD3D12Adapter() { }

	void Initialize(FD3D12DynamicRHI* RHI);
	void InitializeDevices();
	void InitializeRayTracing();

	// Getters
	FORCEINLINE const uint32 GetAdapterIndex() const { return Desc.AdapterIndex; }
	FORCEINLINE const D3D_FEATURE_LEVEL GetFeatureLevel() const { return Desc.MaxSupportedFeatureLevel; }
	FORCEINLINE D3D_SHADER_MODEL GetHighestShaderModel() const { return Desc.MaxSupportedShaderModel; }
	FORCEINLINE ID3D12Device* GetD3DDevice() const { return RootDevice.GetReference(); }
#if D3D12_MAX_DEVICE_INTERFACE >= 1
	FORCEINLINE ID3D12Device1* GetD3DDevice1() const { return RootDevice1.GetReference(); }
#endif
#if D3D12_MAX_DEVICE_INTERFACE >= 2
	FORCEINLINE ID3D12Device2* GetD3DDevice2() const { return RootDevice2.GetReference(); }
#endif
#if D3D12_MAX_DEVICE_INTERFACE >= 5
	FORCEINLINE ID3D12Device5* GetD3DDevice5() { return RootDevice5.GetReference(); }
#endif
#if D3D12_MAX_DEVICE_INTERFACE >= 7
	FORCEINLINE ID3D12Device7* GetD3DDevice7() { return RootDevice7.GetReference(); }
#endif // D3D12_RHI_RAYTRACING
	FORCEINLINE void SetDeviceRemoved(bool value) { bDeviceRemoved = value; }
	FORCEINLINE const bool IsDeviceRemoved() const { return bDeviceRemoved; }
	FORCEINLINE const bool IsDebugDevice() const { return bDebugDevice; }
	FORCEINLINE const ED3D12GPUCrashDebuggingModes GetGPUCrashDebuggingModes() const { return GPUCrashDebuggingModes; }
	FORCEINLINE FD3D12DynamicRHI* GetOwningRHI() { return OwningRHI; }
	FORCEINLINE const D3D12_RESOURCE_HEAP_TIER GetResourceHeapTier() const { return ResourceHeapTier; }
	FORCEINLINE const D3D12_RESOURCE_BINDING_TIER GetResourceBindingTier() const { return ResourceBindingTier; }
	FORCEINLINE const D3D_ROOT_SIGNATURE_VERSION GetRootSignatureVersion() const { return RootSignatureVersion; }
	FORCEINLINE const bool IsDepthBoundsTestSupported() const { return bDepthBoundsTestSupported; }
	FORCEINLINE const bool IsHeapNotZeroedSupported() const { return bHeapNotZeroedSupported; }
	FORCEINLINE const DXGI_ADAPTER_DESC& GetD3DAdapterDesc() const { return Desc.Desc; }
	FORCEINLINE IDXGIAdapter* GetAdapter() { return DxgiAdapter; }
	FORCEINLINE const FD3D12AdapterDesc& GetDesc() const { return Desc; }
	FORCEINLINE TArray<FD3D12Viewport*>& GetViewports() { return Viewports; }
	FORCEINLINE FD3D12Viewport* GetDrawingViewport() { return DrawingViewport; }
	FORCEINLINE void SetDrawingViewport(FD3D12Viewport* InViewport) { DrawingViewport = InViewport; }

	FORCEINLINE ID3D12CommandSignature* GetDrawIndirectCommandSignature() { return DrawIndirectCommandSignature; }
	FORCEINLINE ID3D12CommandSignature* GetDrawIndexedIndirectCommandSignature() { return DrawIndexedIndirectCommandSignature; }
	FORCEINLINE ID3D12CommandSignature* GetDispatchIndirectGraphicsCommandSignature() { return DispatchIndirectGraphicsCommandSignature; }
	FORCEINLINE ID3D12CommandSignature* GetDispatchIndirectComputeCommandSignature() { return DispatchIndirectComputeCommandSignature; }
#if PLATFORM_SUPPORTS_MESH_SHADERS
	FORCEINLINE ID3D12CommandSignature* GetDispatchIndirectMeshCommandSignature() { return DispatchIndirectMeshCommandSignature; }
#endif
	FORCEINLINE ID3D12CommandSignature* GetDispatchRaysIndirectCommandSignature() { return DispatchRaysIndirectCommandSignature; }

	FORCEINLINE FD3D12PipelineStateCache& GetPSOCache() { return PipelineStateCache; }

	FORCEINLINE FD3D12FenceCorePool& GetFenceCorePool() { return FenceCorePool; }

#if USE_STATIC_ROOT_SIGNATURE
	FORCEINLINE const FD3D12RootSignature* GetStaticGraphicsRootSignature()
	{
		static const FD3D12RootSignature StaticGraphicsRootSignature(this, FD3D12RootSignatureDesc::GetStaticGraphicsRootSignatureDesc());
		return &StaticGraphicsRootSignature;
	}
	FORCEINLINE const FD3D12RootSignature* GetStaticComputeRootSignature()
	{
		static const FD3D12RootSignature StaticComputeRootSignature(this, FD3D12RootSignatureDesc::GetStaticComputeRootSignatureDesc());
		return &StaticComputeRootSignature;
	}
	FORCEINLINE const FD3D12RootSignature* GetStaticRayTracingGlobalRootSignature()
	{
		static const FD3D12RootSignature StaticRootSignature(this, FD3D12RootSignatureDesc::GetStaticRayTracingGlobalRootSignatureDesc(), 1 /*RAY_TRACING_REGISTER_SPACE_GLOBAL*/);
		return &StaticRootSignature;
	}
	FORCEINLINE const FD3D12RootSignature* GetStaticRayTracingLocalRootSignature()
	{
		static const FD3D12RootSignature StaticRootSignature(this, FD3D12RootSignatureDesc::GetStaticRayTracingLocalRootSignatureDesc(), 0 /*RAY_TRACING_REGISTER_SPACE_LOCAL*/);
		return &StaticRootSignature;
	}
#else // USE_STATIC_ROOT_SIGNATURE
	FORCEINLINE const FD3D12RootSignature* GetStaticGraphicsRootSignature() { return nullptr; }
#if PLATFORM_SUPPORTS_MESH_SHADERS
	FORCEINLINE const FD3D12RootSignature* GetStaticMeshRootSignature() { return nullptr; }
#endif
	FORCEINLINE const FD3D12RootSignature* GetStaticComputeRootSignature() { return nullptr; }
	FORCEINLINE const FD3D12RootSignature* GetStaticRayTracingGlobalRootSignature() { return nullptr; }
	FORCEINLINE const FD3D12RootSignature* GetStaticRayTracingLocalRootSignature() { return nullptr; }
#endif // USE_STATIC_ROOT_SIGNATURE

	FORCEINLINE FD3D12RootSignature* GetRootSignature(const FD3D12QuantizedBoundShaderState& QBSS) 
	{
		return RootSignatureManager.GetRootSignature(QBSS);
	}

	FORCEINLINE FD3D12RootSignatureManager* GetRootSignatureManager()
	{
		return &RootSignatureManager;
	}

	FORCEINLINE FD3D12DeferredDeletionQueue& GetDeferredDeletionQueue() { return DeferredDeletionQueue; }

	FORCEINLINE FD3D12ManualFence& GetFrameFence()  { check(FrameFence); return *FrameFence; }

	FORCEINLINE FD3D12Fence* GetStagingFence()  { return StagingFence.GetReference(); }

	FORCEINLINE FD3D12Device* GetDevice(uint32 GPUIndex)
	{
		check(GPUIndex < GNumExplicitGPUsForRendering);
		return Devices[GPUIndex];
	}

	FORCEINLINE uint32 GetVRSTileSize() const { return VRSTileSize; }

	void CreateDXGIFactory(bool bWithDebug);
	FORCEINLINE IDXGIFactory* GetDXGIFactory() const { return DxgiFactory; }
	FORCEINLINE IDXGIFactory2* GetDXGIFactory2() const { return DxgiFactory2; }
#if PLATFORM_WINDOWS || PLATFORM_HOLOLENS
	FORCEINLINE IDXGIFactory6* GetDXGIFactory6() const { return DxgiFactory6; }
#endif

	FORCEINLINE FD3D12UploadHeapAllocator& GetUploadHeapAllocator(uint32 GPUIndex)
	{ 
		return *(UploadHeapAllocator[GPUIndex]); 
	}

	FORCEINLINE uint32 GetDebugFlags() const { return DebugFlags; }

	void Cleanup();

	void EndFrame();

	// Resource Creation
	HRESULT CreateCommittedResource(const FD3D12ResourceDesc& InDesc,
		FRHIGPUMask CreationNode,
		const D3D12_HEAP_PROPERTIES& HeapProps,
		D3D12_RESOURCE_STATES InInitialState,
		const D3D12_CLEAR_VALUE* ClearValue,
		FD3D12Resource** ppOutResource,
		const TCHAR* Name,
		bool bVerifyHResult = true)
	{
		return CreateCommittedResource(InDesc, CreationNode, HeapProps, InInitialState, ED3D12ResourceStateMode::Default, D3D12_RESOURCE_STATE_TBD, ClearValue, ppOutResource, Name, bVerifyHResult);
	}

	HRESULT CreateCommittedResource(const FD3D12ResourceDesc& Desc,
		FRHIGPUMask CreationNode,
		const D3D12_HEAP_PROPERTIES& HeapProps,
		D3D12_RESOURCE_STATES InInitialState,
		ED3D12ResourceStateMode InResourceStateMode,
		D3D12_RESOURCE_STATES InDefaultState,
		const D3D12_CLEAR_VALUE* ClearValue,
		FD3D12Resource** ppOutResource,
		const TCHAR* Name,
		bool bVerifyHResult = true);

	HRESULT CreatePlacedResource(const FD3D12ResourceDesc& InDesc,
		FD3D12Heap* BackingHeap,
		uint64 HeapOffset,
		D3D12_RESOURCE_STATES InInitialState,
		const D3D12_CLEAR_VALUE* ClearValue,
		FD3D12Resource** ppOutResource,
		const TCHAR* Name,
		bool bVerifyHResult = true)
	{
		return CreatePlacedResource(InDesc, BackingHeap, HeapOffset, InInitialState, ED3D12ResourceStateMode::Default, D3D12_RESOURCE_STATE_TBD, ClearValue, ppOutResource, Name, bVerifyHResult);
	}

	HRESULT CreatePlacedResource(const FD3D12ResourceDesc& Desc,
		FD3D12Heap* BackingHeap,
		uint64 HeapOffset,
		D3D12_RESOURCE_STATES InInitialState,
		ED3D12ResourceStateMode InResourceStateMode,
		D3D12_RESOURCE_STATES InDefaultState,
		const D3D12_CLEAR_VALUE* ClearValue,
		FD3D12Resource** ppOutResource,
		const TCHAR* Name,
		bool bVerifyHResult = true);

	HRESULT CreateBuffer(D3D12_HEAP_TYPE HeapType,
		FRHIGPUMask CreationNode,
		FRHIGPUMask VisibleNodes,
		uint64 HeapSize,
		FD3D12Resource** ppOutResource,
		const TCHAR* Name,
		D3D12_RESOURCE_FLAGS Flags = D3D12_RESOURCE_FLAG_NONE);

	HRESULT CreateBuffer(D3D12_HEAP_TYPE HeapType,
		FRHIGPUMask CreationNode,
		FRHIGPUMask VisibleNodes,
		D3D12_RESOURCE_STATES InitialState,
		ED3D12ResourceStateMode InResourceStateMode,
		uint64 HeapSize,
		FD3D12Resource** ppOutResource,
		const TCHAR* Name,
		D3D12_RESOURCE_FLAGS Flags = D3D12_RESOURCE_FLAG_NONE);

	HRESULT CreateBuffer(const D3D12_HEAP_PROPERTIES& HeapProps,
		FRHIGPUMask CreationNode,
		D3D12_RESOURCE_STATES InInitialState,
		ED3D12ResourceStateMode InResourceStateMode,
		D3D12_RESOURCE_STATES InDefaultState,
		uint64 HeapSize,
		FD3D12Resource** ppOutResource,
		const TCHAR* Name,
		D3D12_RESOURCE_FLAGS Flags = D3D12_RESOURCE_FLAG_NONE);

	FD3D12Buffer* CreateRHIBuffer(
		const D3D12_RESOURCE_DESC& Desc,
		uint32 Alignment, uint32 Stride, uint32 Size, EBufferUsageFlags InUsage,
		ED3D12ResourceStateMode InResourceStateMode,
		D3D12_RESOURCE_STATES InCreateState,
		bool bHasInitialData,
		const FRHIGPUMask& InGPUMask,
		ED3D12ResourceTransientMode TransientMode,
		ID3D12ResourceAllocator* ResourceAllocator,
		const TCHAR* InDebugName);

	template <typename ObjectType, typename CreationCoreFunction>
	inline ObjectType* CreateLinkedObject(FRHIGPUMask GPUMask, const CreationCoreFunction& pfnCreationCore)
	{
		return FD3D12LinkedAdapterObject<typename ObjectType::LinkedObjectType>::template CreateLinkedObjects<ObjectType>(
			GPUMask,
			[this](uint32 GPUIndex) { return GetDevice(GPUIndex); },
			pfnCreationCore
		);
	}

	template <typename ResourceType, typename ViewType, typename CreationCoreFunction>
	inline ViewType* CreateLinkedViews(ResourceType* Resource, const CreationCoreFunction& pfnCreationCore)
	{
		return FD3D12LinkedAdapterObject<typename ViewType::LinkedObjectType>::template CreateLinkedObjects<ViewType>(
			Resource->GetLinkedObjectsGPUMask(),
			[Resource](uint32 GPUIndex) { return static_cast<ResourceType*>(Resource->GetLinkedObject(GPUIndex)); },
			pfnCreationCore
		);
	}

	inline FD3D12CommandContextRedirector& GetDefaultContextRedirector() { return DefaultContextRedirector; }
	inline FD3D12CommandContextRedirector& GetDefaultAsyncComputeContextRedirector() { return DefaultAsyncComputeContextRedirector; }

	FD3D12TransientHeapCache& GetOrCreateTransientHeapCache();

	FD3D12TemporalEffect* GetTemporalEffect(const FName& EffectName);

	FD3D12FastConstantAllocator& GetTransientUniformBufferAllocator();
	void ReleaseTransientUniformBufferAllocator(FTransientUniformBufferAllocator* InAllocator);

	void BlockUntilIdle();

	void UpdateMemoryInfo();
	FORCEINLINE const FD3D12MemoryInfo& GetMemoryInfo() const { return MemoryInfo; }

	FORCEINLINE uint32 GetFrameCount() const { return FrameCounter; }

	bool IsTrackingAllAllocations() const { return bTrackAllAllocation; }
	void TrackAllocationData(FD3D12ResourceLocation* InAllocation, uint64 InAllocationSize, bool bCollectCallstack);
	void ReleaseTrackedAllocationData(FD3D12ResourceLocation* InAllocation, bool bDefragFree);
	void TrackHeapAllocation(FD3D12Heap* InHeap);
	void ReleaseTrackedHeap(FD3D12Heap* InHeap);
	void DumpTrackedAllocationData(FOutputDevice& OutputDevice, bool bResidentOnly, bool bWithCallstack);

	struct FAllocatedResourceResult
	{
		FD3D12ResourceLocation* Allocation = nullptr;
		uint64 Distance = 0;
	};
	void FindResourcesNearGPUAddress(D3D12_GPU_VIRTUAL_ADDRESS InGPUVirtualAddress, uint64 InRange, TArray<FAllocatedResourceResult>& OutResources);
	void FindHeapsContainingGPUAddress(D3D12_GPU_VIRTUAL_ADDRESS InGPUVirtualAddress, TArray<FD3D12Heap*>& OutHeaps);
	
	struct FReleasedAllocationData
	{
		D3D12_GPU_VIRTUAL_ADDRESS GPUVirtualAddress = 0;
		uint64 AllocationSize = 0;
		FName ResourceName;
		D3D12_RESOURCE_DESC ResourceDesc = {};
		uint64 ReleasedFrameID = 0;
		bool bDefragFree = false;
		bool bBackBuffer = false;
		bool bTransient = false;
		bool bHeap = false;
	};
	void FindReleasedAllocationData(D3D12_GPU_VIRTUAL_ADDRESS InGPUVirtualAddress, TArray<FReleasedAllocationData>& OutAllocationData);

#if D3D12_SUBMISSION_GAP_RECORDER
	FD3D12SubmissionGapRecorder SubmissionGapRecorder;

	void SubmitGapRecorderTimestamps();
#endif

protected:

	virtual void CreateRootDevice(bool bWithDebug);

	virtual void AllocateBuffer(FD3D12Device* Device,
		const D3D12_RESOURCE_DESC& Desc,
		uint32 Size,
		EBufferUsageFlags InUsage,
		ED3D12ResourceStateMode InResourceStateMode,
		D3D12_RESOURCE_STATES InCreateState,
		uint32 Alignment,
		FD3D12Buffer* Buffer,
		FD3D12ResourceLocation& ResourceLocation,
		ED3D12ResourceTransientMode TransientMode,
		ID3D12ResourceAllocator* ResourceAllocator,
		const TCHAR* InDebugName);

	// Creates default root and execute indirect signatures
	virtual void CreateCommandSignatures();

	FD3D12DynamicRHI* OwningRHI;

	// LDA setups have one ID3D12Device
	TRefCountPtr<ID3D12Device> RootDevice;
#if D3D12_MAX_DEVICE_INTERFACE >= 1
	TRefCountPtr<ID3D12Device1> RootDevice1;
#endif
#if D3D12_MAX_DEVICE_INTERFACE >= 2
	TRefCountPtr<ID3D12Device2> RootDevice2;
#endif
#if D3D12_MAX_DEVICE_INTERFACE >= 3
	TRefCountPtr<ID3D12Device3> RootDevice3;
#endif
#if D3D12_MAX_DEVICE_INTERFACE >= 4
	TRefCountPtr<ID3D12Device4> RootDevice4;
#endif
#if D3D12_MAX_DEVICE_INTERFACE >= 5
	TRefCountPtr<ID3D12Device5> RootDevice5;
#endif
#if D3D12_MAX_DEVICE_INTERFACE >= 6
	TRefCountPtr<ID3D12Device6> RootDevice6;
#endif
#if D3D12_MAX_DEVICE_INTERFACE >= 7
	TRefCountPtr<ID3D12Device7> RootDevice7;
#endif

#if PLATFORM_WINDOWS || PLATFORM_HOLOLENS
	TRefCountPtr<IDXGIDebug> DXGIDebug;
	HANDLE ExceptionHandlerHandle = INVALID_HANDLE_VALUE;
#endif

	D3D12_RESOURCE_HEAP_TIER ResourceHeapTier;
	D3D12_RESOURCE_BINDING_TIER ResourceBindingTier;
	D3D_ROOT_SIGNATURE_VERSION RootSignatureVersion;
	bool bDepthBoundsTestSupported;
	bool bHeapNotZeroedSupported;

	uint32 VRSTileSize;

	/** Running with debug device */
	bool bDebugDevice;

	/** GPU Crash debugging modes */
	ED3D12GPUCrashDebuggingModes GPUCrashDebuggingModes;

	/** True if the device being used has been removed. */
	bool bDeviceRemoved;

	FD3D12AdapterDesc Desc;
	TRefCountPtr<IDXGIAdapter> DxgiAdapter;

	FD3D12RootSignatureManager RootSignatureManager;

	FD3D12PipelineStateCache PipelineStateCache;

	TRefCountPtr<ID3D12CommandSignature> DrawIndirectCommandSignature;
	TRefCountPtr<ID3D12CommandSignature> DrawIndexedIndirectCommandSignature;
	TRefCountPtr<ID3D12CommandSignature> DispatchIndirectGraphicsCommandSignature;
	TRefCountPtr<ID3D12CommandSignature> DispatchIndirectComputeCommandSignature;
#if PLATFORM_SUPPORTS_MESH_SHADERS
	TRefCountPtr<ID3D12CommandSignature> DispatchIndirectMeshCommandSignature;
#endif
	TRefCountPtr<ID3D12CommandSignature> DispatchRaysIndirectCommandSignature;

	FD3D12FenceCorePool FenceCorePool;

	FD3D12UploadHeapAllocator*	UploadHeapAllocator[MAX_NUM_GPUS];

	/** A list of all viewport RHIs that have been created. */
	TArray<FD3D12Viewport*> Viewports;

	/** The viewport which is currently being drawn. */
	TRefCountPtr<FD3D12Viewport> DrawingViewport;

	TRefCountPtr<IDXGIFactory> DxgiFactory;
	TRefCountPtr<IDXGIFactory2> DxgiFactory2;
#if PLATFORM_WINDOWS || PLATFORM_HOLOLENS
	TRefCountPtr<IDXGIFactory6> DxgiFactory6;
#endif

	/** A Fence whos value increases every frame*/
	TRefCountPtr<FD3D12ManualFence> FrameFence;

	/** A Fence used to synchronize FD3D12GPUFence and FD3D12StagingBuffer */
	TRefCountPtr<FD3D12Fence> StagingFence;

	FD3D12DeferredDeletionQueue DeferredDeletionQueue;

	FD3D12CommandContextRedirector DefaultContextRedirector;
	FD3D12CommandContextRedirector DefaultAsyncComputeContextRedirector;

	uint32 FrameCounter;

	bool bTrackAllAllocation = false;

	/** Information about an allocated resource. */
	struct FTrackedAllocationData
	{
		static const int32 MaxStackDepth = 30;

		FD3D12ResourceLocation* ResourceAllocation;
		uint64 AllocationSize;
		uint32 StackDepth;
		uint64 Stack[MaxStackDepth];
	};

	/** Tracked resource information. */
	TMap<FD3D12ResourceLocation*, FTrackedAllocationData> TrackedAllocationData;
	TArray<FD3D12Heap*> TrackedHeaps;
	TArray<FReleasedAllocationData> ReleasedAllocationData;
	FCriticalSection TrackedAllocationDataCS;

	FD3D12MemoryInfo MemoryInfo;

#if D3D12_SUBMISSION_GAP_RECORDER
	TArray<uint64> StartOfSubmissionTimestamps;
	TArray<uint64> EndOfSubmissionTimestamps;
#endif

#if WITH_MGPU
	TMap<FName, FD3D12TemporalEffect> TemporalEffectMap;
#endif

	TArray<FTransientUniformBufferAllocator*> TransientUniformBufferAllocators;
	FCriticalSection TransientUniformBufferAllocatorsCS;

	TUniquePtr<IRHITransientMemoryCache> TransientMemoryCache;

	// Each of these devices represents a physical GPU 'Node'
	FD3D12Device* Devices[MAX_NUM_GPUS];

	uint32 DebugFlags;
};
