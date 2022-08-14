/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/UpdateGameServerResult.h"

#endif

#include "Model/GameServer.h"

#include "UpdateGameServerResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateGameServerResult {
    GENERATED_BODY()

    /**
    *  <p>Object that describes the newly updated game server resource.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FGameServer gameServer;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FUpdateGameServerResult &fromAWS(const Aws::GameLift::Model::UpdateGameServerResult &awsUpdateGameServerResult) {
        this->gameServer.fromAWS(awsUpdateGameServerResult.GetGameServer());

        return *this;
    }
#endif
};
