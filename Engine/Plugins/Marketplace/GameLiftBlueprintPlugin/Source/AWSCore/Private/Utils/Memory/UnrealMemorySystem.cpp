/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, Jun 2022
 */

#include "Utils/Memory/UnrealMemorySystem.h"

#include "AWSCoreGlobals.h"

#if WITH_CORE

#include "HAL/UnrealMemory.h"

void* UnrealMemorySystem::AllocateMemory(std::size_t blockSize, std::size_t alignment, const char *allocationTag) {
    AWS_UNREFERENCED_PARAM(allocationTag);

    return FMemory::Malloc(blockSize, alignment);
}

void UnrealMemorySystem::FreeMemory(void* memoryPtr) {
    FMemory::Free(memoryPtr);
}
#endif
