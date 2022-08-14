/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/GameServerInstance.h"

#endif

#include "Model/GameServerInstanceStatus.h"

#include "GameServerInstance.generated.h"

USTRUCT(BlueprintType)
struct FGameServerInstance {
GENERATED_BODY()

    /**
    *  <p>A developer-defined identifier for the game server group that includes the game server instance. The name is unique for each Region in each AWS account.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerGroupName;

    /**
    *  <p>A generated unique identifier for the game server group that includes the game server instance. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerGroupArn;

    /**
    *  <p>The unique identifier for the instance where the game server is running. This ID is available in the instance metadata. EC2 instance IDs use a 17-character format, for example: <code>i-1234567890abcdef0</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString instanceId;

    /**
    *  <p> Current status of the game server instance. </p> <ul> <li> <p> <b>ACTIVE</b> -- The instance is viable for hosting game servers. </p> </li> <li> <p> <b>DRAINING</b> -- The instance is not viable for hosting game servers. Existing game servers are in the process of ending, and new game servers are not started on this instance unless no other resources are available. When the instance is put in DRAINING, a new instance is started up to replace it. Once the instance has no UTILIZED game servers, it will be terminated in favor of the new instance.</p> </li> <li> <p> <b>SPOT_TERMINATING</b> -- The instance is in the process of shutting down due to a Spot instance interruption. No new game servers are started on this instance.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EAWSGameServerInstanceStatus instanceStatus = EAWSGameServerInstanceStatus::NOT_SET;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FGameServerInstance &fromAWS(const Aws::GameLift::Model::GameServerInstance &awsGameServerInstance) {
        this->gameServerGroupName = UTF8_TO_TCHAR(awsGameServerInstance.GetGameServerGroupName().c_str());

        this->gameServerGroupArn = UTF8_TO_TCHAR(awsGameServerInstance.GetGameServerGroupArn().c_str());

        this->instanceId = UTF8_TO_TCHAR(awsGameServerInstance.GetInstanceId().c_str());

        switch(awsGameServerInstance.GetInstanceStatus()) {
            case Aws::GameLift::Model::GameServerInstanceStatus::NOT_SET:
                this->instanceStatus = EAWSGameServerInstanceStatus::NOT_SET;
                break;
            case Aws::GameLift::Model::GameServerInstanceStatus::ACTIVE:
                this->instanceStatus = EAWSGameServerInstanceStatus::ACTIVE;
                break;
            case Aws::GameLift::Model::GameServerInstanceStatus::DRAINING:
                this->instanceStatus = EAWSGameServerInstanceStatus::DRAINING;
                break;
            case Aws::GameLift::Model::GameServerInstanceStatus::SPOT_TERMINATING:
                this->instanceStatus = EAWSGameServerInstanceStatus::SPOT_TERMINATING;
                break;
            default:
                this->instanceStatus = EAWSGameServerInstanceStatus::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
