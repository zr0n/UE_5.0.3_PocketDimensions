/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/UpdateGameSessionResult.h"

#endif

#include "Model/AWSGameSession.h"

#include "UpdateGameSessionResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateGameSessionResult {
    GENERATED_BODY()

    /**
    *  <p>Object that contains the updated game session metadata.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FAWSGameSession gameSession;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FUpdateGameSessionResult &fromAWS(const Aws::GameLift::Model::UpdateGameSessionResult &awsUpdateGameSessionResult) {
        this->gameSession.fromAWS(awsUpdateGameSessionResult.GetGameSession());

        return *this;
    }
#endif
};
