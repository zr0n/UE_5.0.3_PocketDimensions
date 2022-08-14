/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/StartGameSessionPlacementResult.h"

#endif

#include "Model/GameSessionPlacement.h"

#include "StartGameSessionPlacementResult.generated.h"

USTRUCT(BlueprintType)
struct FStartGameSessionPlacementResult {
GENERATED_BODY()

    /**
    *  <p>Object that describes the newly created game session placement. This object includes all the information provided in the request, as well as start/end time stamps and placement status. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FGameSessionPlacement gameSessionPlacement;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FStartGameSessionPlacementResult &fromAWS(const Aws::GameLift::Model::StartGameSessionPlacementResult &awsStartGameSessionPlacementResult) {
        this->gameSessionPlacement.fromAWS(awsStartGameSessionPlacementResult.GetGameSessionPlacement());

        return *this;
    }
#endif
};
