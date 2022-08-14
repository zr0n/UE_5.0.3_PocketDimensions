/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/UpdateFleetCapacityRequest.h"

#endif

#include "UpdateFleetCapacityRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateFleetCapacityRequest {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the fleet to update capacity settings for. You can use either the fleet ID or ARN value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>The number of EC2 instances you want to maintain in the specified fleet location. This value must fall between the minimum and maximum size limits.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int desiredInstances = 0;

    /**
    *  <p>The minimum number of instances that are allowed in the specified fleet location. If this parameter is not set, the default is 0.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int minSize = 0;

    /**
    *  <p>The maximum number of instances that are allowed in the specified fleet location. If this parameter is not set, the default is 1.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int maxSize = 0;

    /**
    *  <p>The name of a remote location to update fleet capacity settings for, in the form of an AWS Region code such as <code>us-west-2</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString location;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::UpdateFleetCapacityRequest toAWS() const {
        Aws::GameLift::Model::UpdateFleetCapacityRequest awsUpdateFleetCapacityRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsUpdateFleetCapacityRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        if (this->desiredInstances != 0) {
            awsUpdateFleetCapacityRequest.SetDesiredInstances(this->desiredInstances);
        }

        if (this->minSize != 0) {
            awsUpdateFleetCapacityRequest.SetMinSize(this->minSize);
        }

        if (this->maxSize != 0) {
            awsUpdateFleetCapacityRequest.SetMaxSize(this->maxSize);
        }

        if (!(this->location.IsEmpty())) {
            awsUpdateFleetCapacityRequest.SetLocation(TCHAR_TO_UTF8(*this->location));
        }

        return awsUpdateFleetCapacityRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty() && this->desiredInstances == 0 && this->minSize == 0 && this->maxSize == 0 && this->location.IsEmpty();
    }
#endif
};
