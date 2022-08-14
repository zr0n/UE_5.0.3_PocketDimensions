// AMAZON CONFIDENTIAL

/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/
#include "GameLiftServerSDK.h"
#include "GameLiftServerSDKPrivatePCH.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "Misc/MessageDialog.h"
#include "HAL/PlatformProcess.h"

#define LOCTEXT_NAMESPACE "FGameLiftServerSDKModule"

void* FGameLiftServerSDKModule::GameLiftServerSDKLibraryHandle = nullptr;

void FGameLiftServerSDKModule::StartupModule()
{
#if WITH_GAMELIFT
    #if PLATFORM_WINDOWS
        #if PLATFORM_64BITS
            FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
            const FString SDKDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("GameLiftServerLibrary"));
            const FString LibName = TEXT("aws-cpp-sdk-gamelift-server");
            const FString LibDir = FPaths::Combine(*SDKDir, TEXT("Win64"));
            if (!LoadDependency(LibDir, LibName, GameLiftServerSDKLibraryHandle))
            {
                FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT(LOCTEXT_NAMESPACE, "Failed to load aws-cpp-sdk-gamelift-server library. Plug-in will not be functional."));
                FreeDependency(GameLiftServerSDKLibraryHandle);
            }
        #endif
    #endif
#endif
}

bool FGameLiftServerSDKModule::LoadDependency(const FString& Dir, const FString& Name, void*& Handle)
{
    FString Lib = Name + TEXT(".") + FPlatformProcess::GetModuleExtension();
    FString Path = Dir.IsEmpty() ? *Lib : FPaths::Combine(*Dir, *Lib);

    Handle = FPlatformProcess::GetDllHandle(*Path);

    if (Handle == nullptr)
    {
        return false;
    }

    return true;
}

void FGameLiftServerSDKModule::FreeDependency(void*& Handle)
{
#if !PLATFORM_LINUX
    if (Handle != nullptr)
    {
        FPlatformProcess::FreeDllHandle(Handle);
        Handle = nullptr;
    }
#endif
}

void FGameLiftServerSDKModule::ShutdownModule()
{
    FreeDependency(GameLiftServerSDKLibraryHandle);
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGameLiftServerSDKModule, GameLiftServerSDK)
