/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/StopGameSessionPlacementResult.h"

#endif

#include "Model/GameSessionPlacement.h"

#include "StopGameSessionPlacementResult.generated.h"

USTRUCT(BlueprintType)
struct FStopGameSessionPlacementResult {
GENERATED_BODY()

    /**
    *  <p>Object that describes the canceled game session placement, with <code>CANCELLED</code> status and an end time stamp. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FGameSessionPlacement gameSessionPlacement;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FStopGameSessionPlacementResult &fromAWS(const Aws::GameLift::Model::StopGameSessionPlacementResult &awsStopGameSessionPlacementResult) {
        this->gameSessionPlacement.fromAWS(awsStopGameSessionPlacementResult.GetGameSessionPlacement());

        return *this;
    }
#endif
};
