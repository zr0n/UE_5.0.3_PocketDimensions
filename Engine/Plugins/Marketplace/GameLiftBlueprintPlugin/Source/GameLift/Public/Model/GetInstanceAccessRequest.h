/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/GetInstanceAccessRequest.h"

#endif

#include "GetInstanceAccessRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetInstanceAccessRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a fleet that contains the instance you want access to. The fleet can be in any of the following statuses: <code>ACTIVATING</code>, <code>ACTIVE</code>, or <code>ERROR</code>. Fleets with an <code>ERROR</code> status may be accessible for a short time before they are deleted.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>Unique identifier for an instance you want to get access to. You can access an instance in any status.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString instanceId;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::GetInstanceAccessRequest toAWS() const {
        Aws::GameLift::Model::GetInstanceAccessRequest awsGetInstanceAccessRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsGetInstanceAccessRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        if (!(this->instanceId.IsEmpty())) {
            awsGetInstanceAccessRequest.SetInstanceId(TCHAR_TO_UTF8(*this->instanceId));
        }

        return awsGetInstanceAccessRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty() && this->instanceId.IsEmpty();
    }
#endif
};
