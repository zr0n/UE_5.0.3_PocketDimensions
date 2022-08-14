/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/SuspendGameServerGroupResult.h"

#endif

#include "Model/GameServerGroup.h"

#include "SuspendGameServerGroupResult.generated.h"

USTRUCT(BlueprintType)
struct FSuspendGameServerGroupResult {
    GENERATED_BODY()

    /**
    *  <p>An object that describes the game server group resource, with the <i>SuspendedActions</i> property updated to reflect the suspended activity.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FGameServerGroup gameServerGroup;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FSuspendGameServerGroupResult &fromAWS(const Aws::GameLift::Model::SuspendGameServerGroupResult &awsSuspendGameServerGroupResult) {
        this->gameServerGroup.fromAWS(awsSuspendGameServerGroupResult.GetGameServerGroup());

        return *this;
    }
#endif
};
