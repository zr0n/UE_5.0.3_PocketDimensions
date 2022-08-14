/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/RegisterGameServerResult.h"

#endif

#include "Model/GameServer.h"

#include "RegisterGameServerResult.generated.h"

USTRUCT(BlueprintType)
struct FRegisterGameServerResult {
GENERATED_BODY()

    /**
    *  <p>Object that describes the newly created game server resource.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FGameServer gameServer;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FRegisterGameServerResult &fromAWS(const Aws::GameLift::Model::RegisterGameServerResult &awsRegisterGameServerResult) {
        this->gameServer.fromAWS(awsRegisterGameServerResult.GetGameServer());

        return *this;
    }
#endif
};
