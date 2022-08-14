/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeFleetLocationUtilizationRequest.h"

#endif

#include "AWSGameLiftDescribeFleetLocationUtilizationRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftDescribeFleetLocationUtilizationRequest {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the fleet to request location utilization for. You can use either the fleet ID or ARN value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>The fleet location to retrieve utilization information for. Specify a location in the form of an AWS Region code, such as <code>us-west-2</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString location;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DescribeFleetLocationUtilizationRequest toAWS() const {
        Aws::GameLift::Model::DescribeFleetLocationUtilizationRequest awsDescribeFleetLocationUtilizationRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsDescribeFleetLocationUtilizationRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        if (!(this->location.IsEmpty())) {
            awsDescribeFleetLocationUtilizationRequest.SetLocation(TCHAR_TO_UTF8(*this->location));
        }

        return awsDescribeFleetLocationUtilizationRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty() && this->location.IsEmpty();
    }
#endif
};
