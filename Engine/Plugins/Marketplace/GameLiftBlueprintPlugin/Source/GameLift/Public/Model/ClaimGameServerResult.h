/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ClaimGameServerResult.h"

#endif

#include "Model/GameServer.h"

#include "ClaimGameServerResult.generated.h"

USTRUCT(BlueprintType)
struct FClaimGameServerResult {
    GENERATED_BODY()

    /**
    *  <p>Object that describes the newly claimed game server resource.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FGameServer gameServer;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FClaimGameServerResult &fromAWS(const Aws::GameLift::Model::ClaimGameServerResult &awsClaimGameServerResult) {
        this->gameServer.fromAWS(awsClaimGameServerResult.GetGameServer());

        return *this;
    }
#endif
};
