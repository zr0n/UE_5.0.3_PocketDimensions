/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreateGameServerGroupResult.h"

#endif

#include "Model/GameServerGroup.h"

#include "CreateGameServerGroupResult.generated.h"

USTRUCT(BlueprintType)
struct FCreateGameServerGroupResult {
GENERATED_BODY()

    /**
    *  <p>The newly created game server group object, including the new ARN value for the GameLift FleetIQ game server group and the object's status. The EC2 Auto Scaling group ARN is initially null, since the group has not yet been created. This value is added once the game server group status reaches ACTIVE. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FGameServerGroup gameServerGroup;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FCreateGameServerGroupResult &fromAWS(const Aws::GameLift::Model::CreateGameServerGroupResult &awsCreateGameServerGroupResult) {
        this->gameServerGroup.fromAWS(awsCreateGameServerGroupResult.GetGameServerGroup());

        return *this;
    }
#endif
};
