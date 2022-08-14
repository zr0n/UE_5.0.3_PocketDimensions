/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeFleetLocationCapacityRequest.h"

#endif

#include "AWSGameLiftDescribeFleetLocationCapacityRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftDescribeFleetLocationCapacityRequest {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the fleet to request location capacity for. You can use either the fleet ID or ARN value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>The fleet location to retrieve capacity information for. Specify a location in the form of an AWS Region code, such as <code>us-west-2</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString location;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DescribeFleetLocationCapacityRequest toAWS() const {
        Aws::GameLift::Model::DescribeFleetLocationCapacityRequest awsDescribeFleetLocationCapacityRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsDescribeFleetLocationCapacityRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        if (!(this->location.IsEmpty())) {
            awsDescribeFleetLocationCapacityRequest.SetLocation(TCHAR_TO_UTF8(*this->location));
        }

        return awsDescribeFleetLocationCapacityRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty() && this->location.IsEmpty();
    }
#endif
};
