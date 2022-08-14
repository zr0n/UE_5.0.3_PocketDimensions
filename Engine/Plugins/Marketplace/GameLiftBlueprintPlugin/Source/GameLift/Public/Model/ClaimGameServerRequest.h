/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ClaimGameServerRequest.h"

#endif

#include "ClaimGameServerRequest.generated.h"

USTRUCT(BlueprintType)
struct FClaimGameServerRequest {
    GENERATED_BODY()

    /**
    *  <p>An identifier for the game server group. When claiming a specific game server, this is the game server group whether the game server is located. When requesting that GameLift FleetIQ locate an available game server, this is the game server group to search on. You can use either the <a>GameServerGroup</a> name or ARN value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerGroupName;

    /**
    *  <p>A custom string that uniquely identifies the game server to claim. If this parameter is left empty, GameLift FleetIQ searches for an available game server in the specified game server group.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerId;

    /**
    *  <p>A set of custom game server properties, formatted as a single string value, to be passed to the claimed game server. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerData;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::ClaimGameServerRequest toAWS() const {
        Aws::GameLift::Model::ClaimGameServerRequest awsClaimGameServerRequest;

		if (!(this->gameServerGroupName.IsEmpty())) {
            awsClaimGameServerRequest.SetGameServerGroupName(TCHAR_TO_UTF8(*this->gameServerGroupName));
        }

		if (!(this->gameServerId.IsEmpty())) {
            awsClaimGameServerRequest.SetGameServerId(TCHAR_TO_UTF8(*this->gameServerId));
        }

		if (!(this->gameServerData.IsEmpty())) {
            awsClaimGameServerRequest.SetGameServerData(TCHAR_TO_UTF8(*this->gameServerData));
        }

        return awsClaimGameServerRequest;
    }

    bool IsEmpty() const {
        return this->gameServerGroupName.IsEmpty() && this->gameServerId.IsEmpty() && this->gameServerData.IsEmpty();
    }
#endif
};
