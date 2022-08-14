/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DeleteFleetRequest.h"

#endif

#include "DeleteFleetRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteFleetRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a fleet to be deleted.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DeleteFleetRequest toAWS() const {
        Aws::GameLift::Model::DeleteFleetRequest awsDeleteFleetRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsDeleteFleetRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        return awsDeleteFleetRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty();
    }
#endif
};
