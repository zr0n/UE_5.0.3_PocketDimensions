/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/RuntimeConfiguration.h"

#endif

#include "Model/ServerProcess.h"

#include "RuntimeConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FRuntimeConfiguration {
GENERATED_BODY()

    /**
    *  <p>Collection of server process configurations that describe which server processes to run on each instance in a fleet.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FServerProcess> serverProcesses;

    /**
    *  <p>Maximum number of game sessions with status <code>ACTIVATING</code> to allow on an instance simultaneously. This setting limits the amount of instance resources that can be used for new game activations at any one time.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int maxConcurrentGameSessionActivations = 0;

    /**
    *  <p>Maximum amount of time (in seconds) that a game session can remain in status <code>ACTIVATING</code>. If the game session is not active before the timeout, activation is terminated and the game session status is changed to <code>TERMINATED</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int gameSessionActivationTimeoutSeconds = 0;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::RuntimeConfiguration toAWS() const {
        Aws::GameLift::Model::RuntimeConfiguration awsRuntimeConfiguration;

        for (const FServerProcess& elem : this->serverProcesses) {
            awsRuntimeConfiguration.AddServerProcesses(elem.toAWS());
        }

        if (this->maxConcurrentGameSessionActivations != 0) {
            awsRuntimeConfiguration.SetMaxConcurrentGameSessionActivations(this->maxConcurrentGameSessionActivations);
        }

        if (this->gameSessionActivationTimeoutSeconds != 0) {
            awsRuntimeConfiguration.SetGameSessionActivationTimeoutSeconds(this->gameSessionActivationTimeoutSeconds);
        }

        return awsRuntimeConfiguration;
    }

    bool IsEmpty() const {
        return this->serverProcesses.Num() == 0 && this->maxConcurrentGameSessionActivations == 0 && this->gameSessionActivationTimeoutSeconds == 0;
    }

    FRuntimeConfiguration &fromAWS(const Aws::GameLift::Model::RuntimeConfiguration &awsRuntimeConfiguration) {
        this->serverProcesses.Empty();
        for (const Aws::GameLift::Model::ServerProcess& elem : awsRuntimeConfiguration.GetServerProcesses()) {
            this->serverProcesses.Add(FServerProcess().fromAWS(elem));
        }

        this->maxConcurrentGameSessionActivations = awsRuntimeConfiguration.GetMaxConcurrentGameSessionActivations();

        this->gameSessionActivationTimeoutSeconds = awsRuntimeConfiguration.GetGameSessionActivationTimeoutSeconds();

        return *this;
    }
#endif
};
