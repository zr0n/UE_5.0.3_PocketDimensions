/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreateGameSessionQueueResult.h"

#endif

#include "Model/GameSessionQueue.h"

#include "CreateGameSessionQueueResult.generated.h"

USTRUCT(BlueprintType)
struct FCreateGameSessionQueueResult {
GENERATED_BODY()

    /**
    *  <p>Object that describes the newly created game session queue.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FGameSessionQueue gameSessionQueue;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FCreateGameSessionQueueResult &fromAWS(const Aws::GameLift::Model::CreateGameSessionQueueResult &awsCreateGameSessionQueueResult) {
        this->gameSessionQueue.fromAWS(awsCreateGameSessionQueueResult.GetGameSessionQueue());

        return *this;
    }
#endif
};
