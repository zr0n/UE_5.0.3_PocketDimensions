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

using UnrealBuildTool;
using System.IO;

public class GameLiftServerSDK : ModuleRules
{
    public GameLiftServerSDK(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivatePCHHeaderFile = "Private/GameLiftServerSDKPrivatePCH.h";

        PublicIncludePaths.Add(
            Path.Combine(ModuleDirectory, "Public")
            );

        PrivateIncludePaths.Add(
            Path.Combine(ModuleDirectory, "Private")
            );

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
            "Core",
            "CoreUObject",
            "Projects",
            "Engine",
            "GameLiftServerLibrary"
            }
            );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
            }
            );


        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
            }
            );

        bEnableExceptions = true;

        if (Target.Type == TargetRules.TargetType.Server)
        {
            if (Target.Platform == UnrealTargetPlatform.Linux/*  || Target.Platform == UnrealTargetPlatform.LinuxArm64 */)
            {
                PublicDefinitions.Add("WITH_GAMELIFT=1");
            }
            else if (Target.Platform == UnrealTargetPlatform.Win64)
            {
                PublicDefinitions.Add("WITH_GAMELIFT=1");
            }
            else
            {
                PublicDefinitions.Add("WITH_GAMELIFT=0");
            }
        }
        else
        {
            PublicDefinitions.Add("WITH_GAMELIFT=0");
        }
    }
}
