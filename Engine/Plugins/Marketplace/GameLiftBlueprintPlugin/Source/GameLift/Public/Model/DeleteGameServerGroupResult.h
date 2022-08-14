/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DeleteGameServerGroupResult.h"

#endif

#include "Model/GameServerGroup.h"

#include "DeleteGameServerGroupResult.generated.h"

USTRUCT(BlueprintType)
struct FDeleteGameServerGroupResult {
GENERATED_BODY()

    /**
    *  <p>An object that describes the deleted game server group resource, with status updated to DELETE_SCHEDULED. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FGameServerGroup gameServerGroup;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:

    FDeleteGameServerGroupResult &fromAWS(const Aws::GameLift::Model::DeleteGameServerGroupResult &awsDeleteGameServerGroupResult) {
// @TODO: check
            this->gameServerGroup.fromAWS(awsDeleteGameServerGroupResult.GetGameServerGroup());
        

        return *this;
    }
#endif
};
