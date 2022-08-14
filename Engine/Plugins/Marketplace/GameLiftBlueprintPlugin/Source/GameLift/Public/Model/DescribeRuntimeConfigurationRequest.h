/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeRuntimeConfigurationRequest.h"

#endif

#include "DescribeRuntimeConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeRuntimeConfigurationRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a fleet to get the run-time configuration for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DescribeRuntimeConfigurationRequest toAWS() const {
        Aws::GameLift::Model::DescribeRuntimeConfigurationRequest awsDescribeRuntimeConfigurationRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsDescribeRuntimeConfigurationRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        return awsDescribeRuntimeConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty();
    }
#endif
};
