/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/RegisterGameServerRequest.h"

#endif

#include "Model/GameLiftTag.h"

#include "RegisterGameServerRequest.generated.h"

USTRUCT(BlueprintType)
struct FRegisterGameServerRequest {
GENERATED_BODY()

    /**
    *  <p>An identifier for the game server group where the game server is running. You can use either the <a>GameServerGroup</a> name or ARN value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerGroupName;

    /**
    *  <p>A custom string that uniquely identifies the new game server. Game server IDs are developer-defined and must be unique across all game server groups in your AWS account.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerId;

    /**
    *  <p>The unique identifier for the instance where the game server is running. This ID is available in the instance metadata.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString instanceId;

    /**
    *  <p>Information needed to make inbound client connections to the game server. This might include IP address and port, DNS name, etc.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString connectionInfo;

    /**
    *  <p>A set of custom game server properties, formatted as a single string value. This data is passed to a game client or service when it requests information on a game servers using <a>ListGameServers</a> or <a>ClaimGameServer</a>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerData;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::RegisterGameServerRequest toAWS() const {
        Aws::GameLift::Model::RegisterGameServerRequest awsRegisterGameServerRequest;

		if (!(this->gameServerGroupName.IsEmpty())) {
            awsRegisterGameServerRequest.SetGameServerGroupName(TCHAR_TO_UTF8(*this->gameServerGroupName));
        }

		if (!(this->gameServerId.IsEmpty())) {
            awsRegisterGameServerRequest.SetGameServerId(TCHAR_TO_UTF8(*this->gameServerId));
        }

		if (!(this->instanceId.IsEmpty())) {
            awsRegisterGameServerRequest.SetInstanceId(TCHAR_TO_UTF8(*this->instanceId));
        }

		if (!(this->connectionInfo.IsEmpty())) {
            awsRegisterGameServerRequest.SetConnectionInfo(TCHAR_TO_UTF8(*this->connectionInfo));
        }

		if (!(this->gameServerData.IsEmpty())) {
            awsRegisterGameServerRequest.SetGameServerData(TCHAR_TO_UTF8(*this->gameServerData));
        }

        return awsRegisterGameServerRequest;
    }

    bool IsEmpty() const {
        return this->gameServerGroupName.IsEmpty() && this->gameServerId.IsEmpty() && this->instanceId.IsEmpty() && this->connectionInfo.IsEmpty() && this->gameServerData.IsEmpty();
    }
#endif
};
