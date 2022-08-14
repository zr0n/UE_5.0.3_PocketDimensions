/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreateGameSessionResult.h"

#endif

#include "Model/AWSGameSession.h"

#include "CreateGameSessionResult.generated.h"

USTRUCT(BlueprintType)
struct FCreateGameSessionResult {
GENERATED_BODY()

    /**
    *  <p>Object that describes the newly created game session record.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FAWSGameSession gameSession;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FCreateGameSessionResult &fromAWS(const Aws::GameLift::Model::CreateGameSessionResult &awsCreateGameSessionResult) {
        this->gameSession.fromAWS(awsCreateGameSessionResult.GetGameSession());

        return *this;
    }
#endif
};
