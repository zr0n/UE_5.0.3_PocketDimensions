// Copyright Epic Games, Inc. All Rights Reserved..

/*=============================================================================
	VulkanDevice.h: Private Vulkan RHI definitions.
=============================================================================*/

#pragma once

#include "VulkanMemory.h"

class FVulkanDescriptorSetCache;
class FVulkanDescriptorPool;
class FVulkanDescriptorPoolsManager;
class FVulkanCommandListContextImmediate;
class FVulkanTransientHeapCache;
#if VULKAN_USE_NEW_QUERIES
class FVulkanOcclusionQueryPool;
#else
class FOLDVulkanQueryPool;
#endif

#if VULKAN_RHI_RAYTRACING
class FVulkanBasicRaytracingPipeline;
#endif

#define VULKAN_USE_DEBUG_NAMES 1

#if VULKAN_USE_DEBUG_NAMES
#define VULKAN_SET_DEBUG_NAME(Device, Type, Handle, Format, ...) Device.VulkanSetObjectName(Type, (uint64)Handle, *FString::Printf(Format, __VA_ARGS__))
#else
#define VULKAN_SET_DEBUG_NAME(Device, Type, Handle, Format, ...) do{}while(0)
#endif

struct FOptionalVulkanDeviceExtensions
{
	union
	{
		struct
		{
			uint64 HasKHRMaintenance1 : 1;
			uint64 HasKHRMaintenance2 : 1;
			uint64 HasKHRDedicatedAllocation : 1;
			uint64 HasEXTValidationCache : 1;
			uint64 HasAMDBufferMarker : 1;
			uint64 HasNVDiagnosticCheckpoints : 1;
			uint64 HasNVDeviceDiagnosticConfig : 1;
			uint64 HasYcbcrSampler : 1;
			uint64 HasMemoryPriority : 1;
			uint64 HasMemoryBudget : 1;
			uint64 HasDriverProperties : 1;
			uint64 HasEXTFragmentDensityMap : 1;
			uint64 HasEXTFragmentDensityMap2 : 1;
			uint64 HasKHRFragmentShadingRate : 1;
			uint64 HasKHRRenderPass2 : 1;
			uint64 HasEXTFullscreenExclusive : 1;
			uint64 HasKHRImageFormatList : 1;
			uint64 HasEXTTextureCompressionASTCHDR : 1;
			uint64 HasEXTASTCDecodeMode : 1;
			uint64 HasQcomRenderPassTransform : 1;
			uint64 HasImageAtomicInt64 : 1;
			uint64 HasBufferAtomicInt64 : 1;
			uint64 HasScalarBlockLayoutFeatures : 1;
			uint64 HasKHRMultiview : 1;
			uint64 HasAccelerationStructure : 1;
			uint64 HasRayTracingPipeline : 1;
			uint64 HasRayQuery : 1;
			uint64 HasDescriptorIndexing : 1;
			uint64 HasBufferDeviceAddress : 1;
			uint64 HasDeferredHostOperations : 1;
			uint64 HasSPIRV_14 : 1;
			uint64 HasShaderFloatControls : 1;
			uint64 HasEXTShaderViewportIndexLayer : 1;
		};
		uint64 Packed;
	};

	FOptionalVulkanDeviceExtensions()
	{
		static_assert(sizeof(Packed) == sizeof(FOptionalVulkanDeviceExtensions), "More bits needed for Packed!");
		Packed = 0;
	}

	void Setup(const TArray<const ANSICHAR*>& InDeviceExtensions);

	inline bool HasGPUCrashDumpExtensions() const
	{
		return HasAMDBufferMarker || HasNVDiagnosticCheckpoints;
	}

#if VULKAN_RHI_RAYTRACING
	inline bool HasRaytracingExtensions() const
	{
		return 
			HasAccelerationStructure && 
			(HasRayTracingPipeline || HasRayQuery) &&
			HasDescriptorIndexing && 
			HasBufferDeviceAddress && 
			HasDeferredHostOperations && 
			HasSPIRV_14 && 
			HasShaderFloatControls;
	}
#endif
};

struct FOptionalVulkanDeviceFeatures
{
#if VULKAN_SUPPORTS_SEPARATE_DEPTH_STENCIL_LAYOUTS
	VkPhysicalDeviceSeparateDepthStencilLayoutsFeaturesKHR SeparateDepthStencilLayoutsFeatures;
#endif
#if VULKAN_SUPPORTS_SCALAR_BLOCK_LAYOUT
	VkPhysicalDeviceScalarBlockLayoutFeaturesEXT ScalarBlockLayoutFeatures;
#endif
#if VULKAN_RHI_RAYTRACING
	VkPhysicalDeviceBufferDeviceAddressFeaturesKHR BufferDeviceAddressFeatures;
	VkPhysicalDeviceAccelerationStructureFeaturesKHR AccelerationStructureFeatures;
	VkPhysicalDeviceRayTracingPipelineFeaturesKHR RayTracingPipelineFeatures;
	VkPhysicalDeviceDescriptorIndexingFeaturesEXT DescriptorIndexingFeatures;
	VkPhysicalDeviceRayQueryFeaturesKHR RayQueryFeatures;
#endif
};

#if VULKAN_RHI_RAYTRACING
struct FRayTracingProperties
{
	VkPhysicalDeviceAccelerationStructurePropertiesKHR AccelerationStructure;
	VkPhysicalDeviceRayTracingPipelinePropertiesKHR RayTracingPipeline;
};
#endif // VULKAN_RHI_RAYTRACING

namespace VulkanRHI
{
	class FDeferredDeletionQueue2 : public FDeviceChild
	{

	public:
		FDeferredDeletionQueue2(FVulkanDevice* InDevice);
		~FDeferredDeletionQueue2();

		enum class EType
		{
			RenderPass,
			Buffer,
			BufferView,
			Image,
			ImageView,
			Pipeline,
			PipelineLayout,
			Framebuffer,
			DescriptorSetLayout,
			Sampler,
			Semaphore,
			ShaderModule,
			Event,
			ResourceAllocation,
			DeviceMemoryAllocation,
			BufferSuballocation,
			AccelerationStructure,
		};

		template <typename T>
		inline void EnqueueResource(EType Type, T Handle)
		{
			static_assert(sizeof(T) <= sizeof(uint64), "Vulkan resource handle type size too large.");
			EnqueueGenericResource(Type, (uint64)Handle);
		}


		void EnqueueResourceAllocation(FVulkanAllocation& Allocation);
		void EnqueueDeviceAllocation(FDeviceMemoryAllocation* DeviceMemoryAllocation);

		void ReleaseResources(bool bDeleteImmediately = false);

		inline void Clear()
		{
			ReleaseResources(true);
		}

		void OnCmdBufferDeleted(FVulkanCmdBuffer* CmdBuffer);
	private:
		void EnqueueGenericResource(EType Type, uint64 Handle);

		struct FEntry
		{
			EType StructureType;
			uint32 FrameNumber;
			uint64 FenceCounter;
			FVulkanCmdBuffer* CmdBuffer;

			uint64 Handle;
			FVulkanAllocation Allocation;
			FDeviceMemoryAllocation* DeviceMemoryAllocation;
		};
		FCriticalSection CS;
		TArray<FEntry> Entries;
	};
}


class FVulkanDevice
{
public:
	FVulkanDevice(FVulkanDynamicRHI* InRHI, VkPhysicalDevice Gpu);

	~FVulkanDevice();

	// Returns true if this is a viable candidate for main GPU
	bool QueryGPU(int32 DeviceIndex);

	void InitGPU(int32 DeviceIndex);

	void CreateDevice();

	void PrepareForDestroy();
	void Destroy();

	void WaitUntilIdle();

	inline EGpuVendorId GetVendorId() const
	{
		return VendorId;
	}

	inline bool HasAsyncComputeQueue() const
	{
		return bAsyncComputeQueue;
	}

	inline bool CanPresentOnComputeQueue() const
	{
		return bPresentOnComputeQueue;
	}

	inline bool IsRealAsyncComputeContext(const FVulkanCommandListContext* InContext) const
	{
		if (bAsyncComputeQueue)
		{
			ensure((FVulkanCommandListContext*)ImmediateContext != ComputeContext);
			return InContext == ComputeContext;
		}
	
		return false;
	}

	inline FVulkanQueue* GetGraphicsQueue()
	{
		return GfxQueue;
	}

	inline FVulkanQueue* GetComputeQueue()
	{
		return ComputeQueue;
	}

	inline FVulkanQueue* GetTransferQueue()
	{
		return TransferQueue;
	}

	inline FVulkanQueue* GetPresentQueue()
	{
		return PresentQueue;
	}

	inline VkPhysicalDevice GetPhysicalHandle() const
	{
		return Gpu;
	}

	inline const VkPhysicalDeviceProperties& GetDeviceProperties() const
	{
		return GpuProps;
	}

#if VULKAN_SUPPORTS_FRAGMENT_DENSITY_MAP
	inline const VkPhysicalDeviceFragmentDensityMapFeaturesEXT& GetFragmentDensityMapFeatures() const
	{
		return FragmentDensityMapFeatures;
	}
#endif

#if VULKAN_SUPPORTS_FRAGMENT_DENSITY_MAP2
	inline const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT& GetFragmentDensityMap2Features() const
	{
		return FragmentDensityMap2Features;
	}
#endif

#if VULKAN_SUPPORTS_FRAGMENT_SHADING_RATE
	inline const VkPhysicalDeviceFragmentShadingRateFeaturesKHR& GetFragmentShadingRateFeatures() const
	{
		return FragmentShadingRateFeatures;
	}

	inline const VkPhysicalDeviceFragmentShadingRatePropertiesKHR& GetFragmentShadingRateProperties() const
	{
		return FragmentShadingRateProperties;
	}

	VkExtent2D GetBestMatchedShadingRateExtents(EVRSShadingRate Rate) const;
#endif
	
#if VULKAN_SUPPORTS_MULTIVIEW
	inline const VkPhysicalDeviceMultiviewFeatures& GetMultiviewFeatures() const
	{
		return MultiviewFeatures;
	}
#endif

	inline const VkPhysicalDeviceLimits& GetLimits() const
	{
		return GpuProps.limits;
	}

#if VULKAN_SUPPORTS_PHYSICAL_DEVICE_PROPERTIES2
	inline const VkPhysicalDeviceIDPropertiesKHR& GetDeviceIdProperties() const
	{
		check(RHI->GetOptionalExtensions().HasKHRGetPhysicalDeviceProperties2);
		return GpuIdProps;
	}

#if VULKAN_RHI_RAYTRACING
	inline const FRayTracingProperties& GetRayTracingProperties() const
	{
		check(OptionalDeviceExtensions.HasRaytracingExtensions());
		return RayTracingProperties;
	}

	void InitializeRayTracing();
	void CleanUpRayTracing();
#endif // VULKAN_RHI_RAYTRACING
#endif // VULKAN_SUPPORTS_PHYSICAL_DEVICE_PROPERTIES2

#if VULKAN_SUPPORTS_VALIDATION_CACHE
	inline VkValidationCacheEXT GetValidationCache() const
	{
		return ValidationCache;
	}
#endif

	inline const VkPhysicalDeviceFeatures& GetPhysicalFeatures() const
	{
		return PhysicalFeatures;
	}

	inline bool HasSeparateDepthStencilLayouts() const
	{
		return bHasSeparateDepthStencilLayouts;
	}

	inline bool HasUnifiedMemory() const
	{
		return DeviceMemoryManager.HasUnifiedMemory();
	}

	inline uint64 GetTimestampValidBitsMask() const
	{
		return TimestampValidBitsMask;
	}

	const VkComponentMapping& GetFormatComponentMapping(EPixelFormat UEFormat) const;

	inline VkDevice GetInstanceHandle() const
	{
		return Device;
	}

	inline const FVulkanSamplerState& GetDefaultSampler() const
	{
		return *DefaultSampler;
	}

	inline const FVulkanTextureView& GetDefaultImageView() const
	{
		return DefaultTextureView;
	}

	inline const VkFormatProperties* GetFormatProperties() const
	{
		return FormatProperties;
	}

	inline VulkanRHI::FDeviceMemoryManager& GetDeviceMemoryManager()
	{
		return DeviceMemoryManager;
	}

	inline const VkPhysicalDeviceMemoryProperties& GetDeviceMemoryProperties() const
	{
		return DeviceMemoryManager.GetMemoryProperties();
	}

	inline VulkanRHI::FMemoryManager& GetMemoryManager()
	{
		return MemoryManager;
	}

	inline VulkanRHI::FDeferredDeletionQueue2& GetDeferredDeletionQueue()
	{
		return DeferredDeletionQueue;
	}

	inline VulkanRHI::FStagingManager& GetStagingManager()
	{
		return StagingManager;
	}

	inline VulkanRHI::FFenceManager& GetFenceManager()
	{
		return FenceManager;
	}

	inline FVulkanDescriptorSetCache& GetDescriptorSetCache()
	{
		return *DescriptorSetCache;
	}

	inline FVulkanDescriptorPoolsManager& GetDescriptorPoolsManager()
	{
		return *DescriptorPoolsManager;
	}

	inline TMap<uint32, FSamplerStateRHIRef>& GetSamplerMap()
	{
		return SamplerMap;
	}

	inline FVulkanShaderFactory& GetShaderFactory()
	{
		return ShaderFactory;
	}

	FVulkanCommandListContextImmediate& GetImmediateContext();

	inline FVulkanCommandListContext& GetImmediateComputeContext()
	{
		return *ComputeContext;
	}

	void NotifyDeletedImage(VkImage Image, bool bRenderTarget);

#if VULKAN_ENABLE_DRAW_MARKERS
	inline PFN_vkCmdDebugMarkerBeginEXT GetCmdDbgMarkerBegin() const
	{
		return DebugMarkers.CmdBegin;
	}

	inline PFN_vkCmdDebugMarkerEndEXT GetCmdDbgMarkerEnd() const
	{
		return DebugMarkers.CmdEnd;
	}

	inline PFN_vkDebugMarkerSetObjectNameEXT GetDebugMarkerSetObjectName() const
	{
		return DebugMarkers.CmdSetObjectName;
	}

#if 0//VULKAN_SUPPORTS_DEBUG_UTILS
	inline PFN_vkCmdBeginDebugUtilsLabelEXT GetCmdBeginDebugLabel() const
	{
		return DebugMarkers.CmdBeginDebugLabel;
	}

	inline PFN_vkCmdEndDebugUtilsLabelEXT GetCmdEndDebugLabel() const
	{
		return DebugMarkers.CmdEndDebugLabel;
	}

	inline PFN_vkSetDebugUtilsObjectNameEXT GetSetDebugName() const
	{
		return DebugMarkers.SetDebugName;
	}
#endif

#endif

	void PrepareForCPURead();

	void SubmitCommandsAndFlushGPU();

	FVulkanOcclusionQueryPool* AcquireOcclusionQueryPool(FVulkanCommandBufferManager* CommandBufferManager, uint32 NumQueries);
	void ReleaseUnusedOcclusionQueryPools();

	inline class FVulkanPipelineStateCacheManager* GetPipelineStateCache()
	{
		return PipelineStateCache;
	}

	void NotifyDeletedGfxPipeline(class FVulkanRHIGraphicsPipelineState* Pipeline);
	void NotifyDeletedComputePipeline(class FVulkanComputePipeline* Pipeline);

	FVulkanCommandListContext* AcquireDeferredContext();
	void ReleaseDeferredContext(FVulkanCommandListContext* InContext);
	void VulkanSetObjectName(VkObjectType Type, uint64_t Handle, const TCHAR* Name);
	inline const FOptionalVulkanDeviceExtensions& GetOptionalExtensions() const
	{
		return OptionalDeviceExtensions;
	}

	inline FOptionalVulkanDeviceFeatures& GetOptionalFeatures()
	{
		return OptionalFeatures;
	}

#if VULKAN_SUPPORTS_GPU_CRASH_DUMPS
	VkBuffer GetCrashMarkerBuffer() const
	{
		return CrashMarker.Buffer;
	}

	void* GetCrashMarkerMappedPointer() const
	{
		return (CrashMarker.Allocation != nullptr) ? CrashMarker.Allocation->GetMappedPointer() : nullptr;
	}
#endif

	void SetupPresentQueue(VkSurfaceKHR Surface);

#if VULKAN_SUPPORTS_COLOR_CONVERSIONS
	VkSamplerYcbcrConversion CreateSamplerColorConversion(const VkSamplerYcbcrConversionCreateInfo& CreateInfo);
#endif

	inline const TArray<VkQueueFamilyProperties>& GetQueueFamilyProps()
	{
		return QueueFamilyProps;
	}

	FVulkanTransientHeapCache& GetOrCreateTransientHeapCache();


private:
	const VkFormatProperties& GetFormatProperties(VkFormat InFormat);
	void MapBufferFormatSupport(FPixelFormatInfo& PixelFormatInfo, EPixelFormat UEFormat, VkFormat VulkanFormat);
	void MapImageFormatSupport(FPixelFormatInfo& PixelFormatInfo, const TArrayView<const VkFormat>& PrioritizedFormats, EPixelFormatCapabilities RequiredCapabilities);
	void MapFormatSupport(EPixelFormat UEFormat, std::initializer_list<VkFormat> PrioritizedFormats, const VkComponentMapping& ComponentMapping, EPixelFormatCapabilities RequiredCapabilities, int32 BlockBytes);
	void MapFormatSupport(EPixelFormat UEFormat, std::initializer_list<VkFormat> PrioritizedFormats, const VkComponentMapping& ComponentMapping);
	void MapFormatSupport(EPixelFormat UEFormat, std::initializer_list<VkFormat> PrioritizedFormats, const VkComponentMapping& ComponentMapping, int32 BlockBytes);
	void MapFormatSupport(EPixelFormat UEFormat, std::initializer_list<VkFormat> PrioritizedFormats, const VkComponentMapping& ComponentMapping, EPixelFormatCapabilities RequiredCapabilities);

	void SubmitCommands(FVulkanCommandListContext* Context);


	VkDevice Device;

	VulkanRHI::FDeviceMemoryManager DeviceMemoryManager;

	VulkanRHI::FMemoryManager MemoryManager;

	VulkanRHI::FDeferredDeletionQueue2 DeferredDeletionQueue;

	VulkanRHI::FStagingManager StagingManager;

	VulkanRHI::FFenceManager FenceManager;

	FVulkanTransientHeapCache* TransientHeapCache = nullptr;

	// Active on ES3.1
	FVulkanDescriptorSetCache* DescriptorSetCache = nullptr;
	// Active on >= SM4
	FVulkanDescriptorPoolsManager* DescriptorPoolsManager = nullptr;

	FVulkanShaderFactory ShaderFactory;

	FVulkanSamplerState* DefaultSampler;
	FVulkanSurface* DefaultImage;
	FVulkanTextureView DefaultTextureView;

	VkPhysicalDevice Gpu;
	VkPhysicalDeviceProperties GpuProps;
#if VULKAN_SUPPORTS_FRAGMENT_DENSITY_MAP
	VkPhysicalDeviceFragmentDensityMapFeaturesEXT FragmentDensityMapFeatures;
#endif

#if VULKAN_SUPPORTS_FRAGMENT_DENSITY_MAP2
	VkPhysicalDeviceFragmentDensityMap2FeaturesEXT FragmentDensityMap2Features;
#endif

#if VULKAN_SUPPORTS_FRAGMENT_SHADING_RATE
	VkPhysicalDeviceFragmentShadingRatePropertiesKHR FragmentShadingRateProperties;
	VkPhysicalDeviceFragmentShadingRateFeaturesKHR FragmentShadingRateFeatures;
	TArray<VkPhysicalDeviceFragmentShadingRateKHR> FragmentShadingRates;
#endif

#if VULKAN_SUPPORTS_MULTIVIEW
	VkPhysicalDeviceMultiviewFeatures MultiviewFeatures;
#endif

#if VULKAN_SUPPORTS_PHYSICAL_DEVICE_PROPERTIES2
	VkPhysicalDeviceIDPropertiesKHR GpuIdProps;

#if VULKAN_RHI_RAYTRACING
	FRayTracingProperties RayTracingProperties;
	FVulkanBasicRaytracingPipeline* BasicRayTracingPipeline = nullptr;
#endif // VULKAN_RHI_RAYTRACING
#endif // VULKAN_SUPPORTS_PHYSICAL_DEVICE_PROPERTIES2

	VkPhysicalDeviceFeatures PhysicalFeatures;
	FOptionalVulkanDeviceFeatures OptionalFeatures;

	bool bHasSeparateDepthStencilLayouts = false;

	TArray<VkQueueFamilyProperties> QueueFamilyProps;
	VkFormatProperties FormatProperties[VK_FORMAT_RANGE_SIZE];
	// Info for formats that are not in the core Vulkan spec (i.e. extensions)
	mutable TMap<VkFormat, VkFormatProperties> ExtensionFormatProperties;

	TArray<FVulkanOcclusionQueryPool*> UsedOcclusionQueryPools;
	TArray<FVulkanOcclusionQueryPool*> FreeOcclusionQueryPools;

	uint64 TimestampValidBitsMask = 0;

	FVulkanQueue* GfxQueue;
	FVulkanQueue* ComputeQueue;
	FVulkanQueue* TransferQueue;
	FVulkanQueue* PresentQueue;
	bool bAsyncComputeQueue = false;
	bool bPresentOnComputeQueue = false;

	EGpuVendorId VendorId = EGpuVendorId::NotQueried;

#if VULKAN_SUPPORTS_GPU_CRASH_DUMPS
	struct
	{
		VkBuffer Buffer = VK_NULL_HANDLE;
		VulkanRHI::FDeviceMemoryAllocation* Allocation = nullptr;
	} CrashMarker;
#endif

	VkComponentMapping PixelFormatComponentMapping[PF_MAX];

	TMap<uint32, FSamplerStateRHIRef> SamplerMap;

	FVulkanCommandListContextImmediate* ImmediateContext;
	FVulkanCommandListContext* ComputeContext;
	TArray<FVulkanCommandListContext*> CommandContexts;
#if VULKAN_SUPPORTS_COLOR_CONVERSIONS
	TMap<uint32, VkSamplerYcbcrConversion> SamplerColorConversionMap;
#endif

	FVulkanDynamicRHI* RHI = nullptr;
	bool bDebugMarkersFound = false;
	TArray<const ANSICHAR*> DeviceExtensions;
	TArray<const ANSICHAR*> ValidationLayers;

	static void GetDeviceExtensionsAndLayers(VkPhysicalDevice Gpu, EGpuVendorId VendorId, TArray<const ANSICHAR*>& OutDeviceExtensions, TArray<const ANSICHAR*>& OutDeviceLayers, TArray<FString>& OutAllDeviceExtensions, TArray<FString>& OutAllDeviceLayers, bool& bOutDebugMarkers);

	FOptionalVulkanDeviceExtensions OptionalDeviceExtensions;

	void SetupFormats();

#if VULKAN_SUPPORTS_VALIDATION_CACHE
	VkValidationCacheEXT ValidationCache = VK_NULL_HANDLE;
#endif

#if VULKAN_ENABLE_DRAW_MARKERS
	struct
	{
		PFN_vkCmdDebugMarkerBeginEXT		CmdBegin = nullptr;
		PFN_vkCmdDebugMarkerEndEXT			CmdEnd = nullptr;
		PFN_vkDebugMarkerSetObjectNameEXT	CmdSetObjectName = nullptr;
		PFN_vkSetDebugUtilsObjectNameEXT	SetDebugName = nullptr;

#if 0//VULKAN_SUPPORTS_DEBUG_UTILS
		PFN_vkCmdBeginDebugUtilsLabelEXT	CmdBeginDebugLabel = nullptr;
		PFN_vkCmdEndDebugUtilsLabelEXT		CmdEndDebugLabel = nullptr;
#endif
	} DebugMarkers;
	friend class FVulkanCommandListContext;
#endif
	void SetupDrawMarkers();

	class FVulkanPipelineStateCacheManager* PipelineStateCache;
	friend class FVulkanDynamicRHI;
	friend class FVulkanRHIGraphicsPipelineState;
};
