/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/UpdateRuntimeConfigurationRequest.h"

#endif

#include "Model/RuntimeConfiguration.h"

#include "UpdateRuntimeConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateRuntimeConfigurationRequest {
    GENERATED_BODY()

    /**
    *  <p>Unique identifier for a fleet to update run-time configuration for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>Instructions for launching server processes on each instance in the fleet. Server processes run either a custom game build executable or a Realtime Servers script. The run-time configuration lists the types of server processes to run on an instance and includes the following configuration settings: the server executable or launch script file, launch parameters, and the number of processes to run concurrently on each instance. A CreateFleet request must include a run-time configuration with at least one server process configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FRuntimeConfiguration runtimeConfiguration;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::UpdateRuntimeConfigurationRequest toAWS() const {
        Aws::GameLift::Model::UpdateRuntimeConfigurationRequest awsUpdateRuntimeConfigurationRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsUpdateRuntimeConfigurationRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        if (!(this->runtimeConfiguration.IsEmpty())) {
            awsUpdateRuntimeConfigurationRequest.SetRuntimeConfiguration(this->runtimeConfiguration.toAWS());
        }

        return awsUpdateRuntimeConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty() && this->runtimeConfiguration.IsEmpty();
    }
#endif
};
