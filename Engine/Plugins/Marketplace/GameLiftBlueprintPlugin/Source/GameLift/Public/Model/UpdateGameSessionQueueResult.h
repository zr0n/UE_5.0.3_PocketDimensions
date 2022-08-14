/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/UpdateGameSessionQueueResult.h"

#endif

#include "Model/GameSessionQueue.h"

#include "UpdateGameSessionQueueResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateGameSessionQueueResult {
GENERATED_BODY()

    /**
    *  <p>Object that describes the newly updated game session queue.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FGameSessionQueue gameSessionQueue;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FUpdateGameSessionQueueResult &fromAWS(const Aws::GameLift::Model::UpdateGameSessionQueueResult &awsUpdateGameSessionQueueResult) {
        this->gameSessionQueue.fromAWS(awsUpdateGameSessionQueueResult.GetGameSessionQueue());

        return *this;
    }
#endif
};
