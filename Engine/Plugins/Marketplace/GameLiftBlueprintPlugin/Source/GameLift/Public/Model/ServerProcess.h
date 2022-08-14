/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ServerProcess.h"

#endif

#include "ServerProcess.generated.h"

USTRUCT(BlueprintType)
struct FServerProcess {
GENERATED_BODY()

    /**
    *  <p>Location of the server executable in a custom game build or the name of the Realtime script file that contains the <code>Init()</code> function. Game builds and Realtime scripts are installed on instances at the root: </p> <ul> <li> <p>Windows (for custom game builds only): <code>C:\game</code>. Example: "<code>C:\game\MyGame\server.exe</code>" </p> </li> <li> <p>Linux: <code>/local/game</code>. Examples: "<code>/local/game/MyGame/server.exe</code>" or "<code>/local/game/MyRealtimeScript.js</code>"</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString launchPath;

    /**
    *  <p>Optional list of parameters to pass to the server executable or Realtime script on launch.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString parameters;

    /**
    *  <p>Number of server processes using this configuration to run concurrently on an instance.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int concurrentExecutions = 0;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::ServerProcess toAWS() const {
        Aws::GameLift::Model::ServerProcess awsServerProcess;

        if (!(this->launchPath.IsEmpty())) {
            awsServerProcess.SetLaunchPath(TCHAR_TO_UTF8(*this->launchPath));
        }

        if (!(this->parameters.IsEmpty())) {
            awsServerProcess.SetParameters(TCHAR_TO_UTF8(*this->parameters));
        }

        if (this->concurrentExecutions != 0) {
            awsServerProcess.SetConcurrentExecutions(this->concurrentExecutions);
        }

        return awsServerProcess;
    }

    bool IsEmpty() const {
        return this->launchPath.IsEmpty() && this->parameters.IsEmpty() && this->concurrentExecutions == 0;
    }

    FServerProcess &fromAWS(const Aws::GameLift::Model::ServerProcess &awsServerProcess) {
        this->launchPath = UTF8_TO_TCHAR(awsServerProcess.GetLaunchPath().c_str());

        this->parameters = UTF8_TO_TCHAR(awsServerProcess.GetParameters().c_str());

        this->concurrentExecutions = awsServerProcess.GetConcurrentExecutions();

        return *this;
    }
#endif
};
