/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ResumeGameServerGroupResult.h"

#endif

#include "Model/GameServerGroup.h"

#include "ResumeGameServerGroupResult.generated.h"

USTRUCT(BlueprintType)
struct FResumeGameServerGroupResult {
    GENERATED_BODY()

    /**
    *  <p>An object that describes the game server group resource, with the <i>SuspendedActions</i> property updated to reflect the resumed activity.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FGameServerGroup gameServerGroup;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:

    FResumeGameServerGroupResult &fromAWS(const Aws::GameLift::Model::ResumeGameServerGroupResult &awsResumeGameServerGroupResult) {
        this->gameServerGroup.fromAWS(awsResumeGameServerGroupResult.GetGameServerGroup());

        return *this;
    }
#endif
};
