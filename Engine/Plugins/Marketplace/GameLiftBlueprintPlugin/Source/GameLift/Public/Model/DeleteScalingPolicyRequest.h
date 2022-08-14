/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DeleteScalingPolicyRequest.h"

#endif

#include "DeleteScalingPolicyRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteScalingPolicyRequest {
GENERATED_BODY()

    /**
    *  <p>Descriptive label that is associated with a scaling policy. Policy names do not need to be unique.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString name;

    /**
    *  <p>Unique identifier for a fleet to be deleted.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DeleteScalingPolicyRequest toAWS() const {
        Aws::GameLift::Model::DeleteScalingPolicyRequest awsDeleteScalingPolicyRequest;

        if (!(this->name.IsEmpty())) {
            awsDeleteScalingPolicyRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        if (!(this->fleetId.IsEmpty())) {
            awsDeleteScalingPolicyRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        return awsDeleteScalingPolicyRequest;
    }

    bool IsEmpty() const {
        return this->name.IsEmpty() && this->fleetId.IsEmpty();
    }
#endif
};
