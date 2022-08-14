/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeFleetPortSettingsRequest.h"

#endif

#include "DescribeFleetPortSettingsRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeFleetPortSettingsRequest {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the fleet to retrieve port settings for. You can use either the fleet ID or ARN value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>A remote location to check for status of port setting updates. Use the AWS Region code format, such as <code>us-west-2</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString location;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DescribeFleetPortSettingsRequest toAWS() const {
        Aws::GameLift::Model::DescribeFleetPortSettingsRequest awsDescribeFleetPortSettingsRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsDescribeFleetPortSettingsRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

		if (!(this->location.IsEmpty())) {
            awsDescribeFleetPortSettingsRequest.SetLocation(TCHAR_TO_UTF8(*this->location));
        }

        return awsDescribeFleetPortSettingsRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty() && this->location.IsEmpty();
    }
#endif
};
