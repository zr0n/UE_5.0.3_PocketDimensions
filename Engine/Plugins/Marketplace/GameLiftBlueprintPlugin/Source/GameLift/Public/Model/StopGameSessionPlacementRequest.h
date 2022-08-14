/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/StopGameSessionPlacementRequest.h"

#endif

#include "StopGameSessionPlacementRequest.generated.h"

USTRUCT(BlueprintType)
struct FStopGameSessionPlacementRequest {
    GENERATED_BODY()

    /**
    *  <p>Unique identifier for a game session placement to cancel.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString placementId;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::StopGameSessionPlacementRequest toAWS() const {
        Aws::GameLift::Model::StopGameSessionPlacementRequest awsStopGameSessionPlacementRequest;

        if (!(this->placementId.IsEmpty())) {
            awsStopGameSessionPlacementRequest.SetPlacementId(TCHAR_TO_UTF8(*this->placementId));
        }

        return awsStopGameSessionPlacementRequest;
    }

    bool IsEmpty() const {
        return this->placementId.IsEmpty();
    }
#endif
};
