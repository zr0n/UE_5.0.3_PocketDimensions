/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/SuspendGameServerGroupRequest.h"

#endif

#include "Model/GameServerGroupAction.h"

#include "SuspendGameServerGroupRequest.generated.h"

USTRUCT(BlueprintType)
struct FSuspendGameServerGroupRequest {
    GENERATED_BODY()

    /**
    *  <p>The unique identifier of the game server group to stop activity on. Use either the <a>GameServerGroup</a> name or ARN value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerGroupName;

    /**
    *  <p>The action to suspend for this game server group.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<EAWSGameServerGroupAction> suspendActions;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::SuspendGameServerGroupRequest toAWS() const {
        Aws::GameLift::Model::SuspendGameServerGroupRequest awsSuspendGameServerGroupRequest;

		if (!(this->gameServerGroupName.IsEmpty())) {
            awsSuspendGameServerGroupRequest.SetGameServerGroupName(TCHAR_TO_UTF8(*this->gameServerGroupName));
        }

        for (const EAWSGameServerGroupAction& elem : this->suspendActions) {
		    switch(elem) {
                case EAWSGameServerGroupAction::NOT_SET:
                    awsSuspendGameServerGroupRequest.AddSuspendActions(Aws::GameLift::Model::GameServerGroupAction::NOT_SET);
                    break;
                case EAWSGameServerGroupAction::REPLACE_INSTANCE_TYPES:
                        awsSuspendGameServerGroupRequest.AddSuspendActions(Aws::GameLift::Model::GameServerGroupAction::REPLACE_INSTANCE_TYPES);
                        break;
                default:
                    break;
            };
        }

        return awsSuspendGameServerGroupRequest;
    }

    bool IsEmpty() const {
        return this->gameServerGroupName.IsEmpty() && this->suspendActions.Num() == 0;
    }
#endif
};
