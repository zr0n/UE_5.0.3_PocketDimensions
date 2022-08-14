/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/UpdateRuntimeConfigurationResult.h"

#endif

#include "Model/RuntimeConfiguration.h"

#include "UpdateRuntimeConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateRuntimeConfigurationResult {
    GENERATED_BODY()

    /**
    *  <p>The run-time configuration currently in force. If the update was successful, this object matches the one in the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FRuntimeConfiguration runtimeConfiguration;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FUpdateRuntimeConfigurationResult &fromAWS(const Aws::GameLift::Model::UpdateRuntimeConfigurationResult &awsUpdateRuntimeConfigurationResult) {
        this->runtimeConfiguration.fromAWS(awsUpdateRuntimeConfigurationResult.GetRuntimeConfiguration());

        return *this;
    }
#endif
};
