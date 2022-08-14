/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DeleteGameServerGroupRequest.h"

#endif

#include "Model/GameServerGroupDeleteOption.h"

#include "DeleteGameServerGroupRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteGameServerGroupRequest {
GENERATED_BODY()

    /**
    *  <p>The unique identifier of the game server group to delete. Use either the <a>GameServerGroup</a> name or ARN value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerGroupName;

    /**
    *  <p>The type of delete to perform. Options include:</p> <ul> <li> <p>SAFE_DELETE – Terminates the game server group and EC2 Auto Scaling group only when it has no game servers that are in IN_USE status.</p> </li> <li> <p>FORCE_DELETE – Terminates the game server group, including all active game servers regardless of their utilization status, and the EC2 Auto Scaling group. </p> </li> <li> <p>RETAIN – Does a safe delete of the game server group but retains the EC2 Auto Scaling group as is.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EAWSGameServerGroupDeleteOption deleteOption = EAWSGameServerGroupDeleteOption::NOT_SET;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DeleteGameServerGroupRequest toAWS() const {
        Aws::GameLift::Model::DeleteGameServerGroupRequest awsDeleteGameServerGroupRequest;

		if (!(this->gameServerGroupName.IsEmpty())) {
            awsDeleteGameServerGroupRequest.SetGameServerGroupName(TCHAR_TO_UTF8(*this->gameServerGroupName));
        }

        switch(this->deleteOption) {
            case EAWSGameServerGroupDeleteOption::SAFE_DELETE:
                awsDeleteGameServerGroupRequest.SetDeleteOption(Aws::GameLift::Model::GameServerGroupDeleteOption::SAFE_DELETE);
                break;
            case EAWSGameServerGroupDeleteOption::FORCE_DELETE:
                awsDeleteGameServerGroupRequest.SetDeleteOption(Aws::GameLift::Model::GameServerGroupDeleteOption::FORCE_DELETE);
                break;
            case EAWSGameServerGroupDeleteOption::RETAIN:
                awsDeleteGameServerGroupRequest.SetDeleteOption(Aws::GameLift::Model::GameServerGroupDeleteOption::RETAIN);
                break;
            default:
                break;
            }

        return awsDeleteGameServerGroupRequest;
    }

    bool IsEmpty() const {
        return this->gameServerGroupName.IsEmpty() && deleteOption == EAWSGameServerGroupDeleteOption::NOT_SET;
    }
#endif
};
