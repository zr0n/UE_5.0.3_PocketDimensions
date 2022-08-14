/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, Jun 2022
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_CORE
#include "aws/core/utils/memory/MemorySystemInterface.h"
#endif

#if WITH_CORE
class AWSCORE_API UnrealMemorySystem : public Aws::Utils::Memory::MemorySystemInterface
{
public:
        UnrealMemorySystem() {};
        virtual ~UnrealMemorySystem() {}

        virtual void Begin() override {}
        virtual void End() override {}

        virtual void* AllocateMemory(std::size_t blockSize, std::size_t alignment, const char *allocationTag = nullptr) override;
        virtual void FreeMemory(void* memoryPtr) override;
};
#endif
