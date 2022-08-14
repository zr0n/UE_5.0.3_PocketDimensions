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

public class GameLiftServerLibrary : ModuleRules
{
    public GameLiftServerLibrary(ReadOnlyTargetRules Target) : base(Target)
    {
        Type = ModuleType.External;

        PublicIncludePaths.Add(ModuleDirectory);

        string SDKDirectory = System.IO.Path.Combine(ModuleDirectory, Target.Platform.ToString());

        bool bHasGameLiftSDK = System.IO.Directory.Exists(SDKDirectory);

        if (bHasGameLiftSDK)
        {
            if (Target.Type == TargetRules.TargetType.Server)
            {
                if (Target.Platform == UnrealTargetPlatform.Linux)
                {
                    SDKDirectory = System.IO.Path.Combine(SDKDirectory, "x86_64-unknown-linux-gnu");
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(SDKDirectory, "libaws-cpp-sdk-gamelift-server.so"));
                    RuntimeDependencies.Add(System.IO.Path.Combine(SDKDirectory, "libaws-cpp-sdk-gamelift-server.so"));
                }
                else if (Target.Platform == UnrealTargetPlatform.Win64)
                {
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(SDKDirectory, "aws-cpp-sdk-gamelift-server.lib"));
                    PublicDelayLoadDLLs.Add("aws-cpp-sdk-gamelift-server.dll");
                    RuntimeDependencies.Add(System.IO.Path.Combine(SDKDirectory, "aws-cpp-sdk-gamelift-server.dll"));
                }
            }
        }
    }
}
