/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/UpdateGameServerGroupResult.h"

#endif

#include "Model/GameServerGroup.h"

#include "UpdateGameServerGroupResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateGameServerGroupResult {
    GENERATED_BODY()

    /**
    *  <p>An object that describes the game server group resource with updated properties. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FGameServerGroup gameServerGroup;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FUpdateGameServerGroupResult &fromAWS(const Aws::GameLift::Model::UpdateGameServerGroupResult &awsUpdateGameServerGroupResult) {
        this->gameServerGroup.fromAWS(awsUpdateGameServerGroupResult.GetGameServerGroup());
        

        return *this;
    }
#endif
};
