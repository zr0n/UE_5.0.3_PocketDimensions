/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ResumeGameServerGroupRequest.h"

#endif

#include "Model/GameServerGroupAction.h"

#include "ResumeGameServerGroupRequest.generated.h"

USTRUCT(BlueprintType)
struct FResumeGameServerGroupRequest {
    GENERATED_BODY()

    /**
    *  <p>The unique identifier of the game server group to resume activity on. Use either the <a>GameServerGroup</a> name or ARN value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerGroupName;

    /**
    *  <p>The action to resume for this game server group.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<EAWSGameServerGroupAction> resumeActions;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::ResumeGameServerGroupRequest toAWS() const {
        Aws::GameLift::Model::ResumeGameServerGroupRequest awsResumeGameServerGroupRequest;

		if (!(this->gameServerGroupName.IsEmpty())) {
            awsResumeGameServerGroupRequest.SetGameServerGroupName(TCHAR_TO_UTF8(*this->gameServerGroupName));
        }

        for (const EAWSGameServerGroupAction& elem : this->resumeActions) {
		    switch(elem) {
                case EAWSGameServerGroupAction::NOT_SET:
                    awsResumeGameServerGroupRequest.AddResumeActions(Aws::GameLift::Model::GameServerGroupAction::NOT_SET);
                    break;
                case EAWSGameServerGroupAction::REPLACE_INSTANCE_TYPES:
                        awsResumeGameServerGroupRequest.AddResumeActions(Aws::GameLift::Model::GameServerGroupAction::REPLACE_INSTANCE_TYPES);
                        break;
                default:
                    break;
            };
        }

        return awsResumeGameServerGroupRequest;
    }

    bool IsEmpty() const {
        return this->gameServerGroupName.IsEmpty() && this->resumeActions.Num() == 0;
    }
#endif
};
