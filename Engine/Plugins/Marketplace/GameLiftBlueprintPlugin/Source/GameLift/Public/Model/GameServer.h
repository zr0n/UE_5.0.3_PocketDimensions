/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/GameServer.h"

#endif

#include "Model/GameServerClaimStatus.h"
#include "Model/GameServerUtilizationStatus.h"

#include "GameServer.generated.h"

USTRUCT(BlueprintType)
struct FGameServer {
    GENERATED_BODY()

    /**
    *  <p>The name identifier for the game server group where the game server is located.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerGroupName;

    /**
    *  <p>The ARN identifier for the game server group where the game server is located.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerGroupArn;

    /**
    *  <p>A custom string that uniquely identifies the game server. Game server IDs are developer-defined and are unique across all game server groups in an AWS account.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerId;

    /**
    *  <p>The unique identifier for the instance where the game server is located.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString instanceId;

    /**
    *  <p>The port and IP address that must be used to establish a client connection to the game server.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString connectionInfo;

    /**
    *  <p>A set of custom game server properties, formatted as a single string value. This data is passed to a game client or service in response to requests <a>ListGameServers</a> or <a>ClaimGameServer</a>. This property can be updated using <a>UpdateGameServer</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerData;

    /**
    *  <p>Indicates when an available game server has been reserved but has not yet started hosting a game. Once it is claimed, game server remains in CLAIMED status for a maximum of one minute. During this time, game clients must connect to the game server and start the game, which triggers the game server to update its utilization status. After one minute, the game server claim status reverts to null.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EAWSGameServerClaimStatus claimStatus = EAWSGameServerClaimStatus::NOT_SET;

    /**
    *  <p>Indicates whether the game server is currently available for new games or is busy. Possible statuses include:</p> <ul> <li> <p>AVAILABLE - The game server is available to be claimed. A game server that has been claimed remains in this status until it reports game hosting activity. </p> </li> <li> <p>IN_USE - The game server is currently hosting a game session with players. </p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EAWSGameServerUtilizationStatus utilizationStatus = EAWSGameServerUtilizationStatus::NOT_SET;

    /**
    *  <p>Time stamp indicating when the game server resource was created with a <a>RegisterGameServer</a> request. Format is a number expressed in Unix time as milliseconds (for example "1469498468.057").</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FDateTime registrationTime;

    /**
    *  <p>Time stamp indicating the last time the game server was claimed with a <a>ClaimGameServer</a> request. Format is a number expressed in Unix time as milliseconds (for example "1469498468.057"). This value is used to calculate when the game server's claim status.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FDateTime lastClaimTime;

    /**
    *  <p>Time stamp indicating the last time the game server was updated with health status using an <a>UpdateGameServer</a> request. Format is a number expressed in Unix time as milliseconds (for example "1469498468.057"). After game server registration, this property is only changed when a game server update specifies a health check value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FDateTime lastHealthCheckTime;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FGameServer &fromAWS(const Aws::GameLift::Model::GameServer &awsGameServer) {
        this->gameServerGroupName = UTF8_TO_TCHAR(awsGameServer.GetGameServerGroupName().c_str());

        this->gameServerGroupArn = UTF8_TO_TCHAR(awsGameServer.GetGameServerGroupArn().c_str());

        this->gameServerId = UTF8_TO_TCHAR(awsGameServer.GetGameServerId().c_str());

        this->instanceId = UTF8_TO_TCHAR(awsGameServer.GetInstanceId().c_str());

        this->connectionInfo = UTF8_TO_TCHAR(awsGameServer.GetConnectionInfo().c_str());

        this->gameServerData = UTF8_TO_TCHAR(awsGameServer.GetGameServerData().c_str());

        switch(awsGameServer.GetClaimStatus()) {
            case Aws::GameLift::Model::GameServerClaimStatus::NOT_SET:
                this->claimStatus = EAWSGameServerClaimStatus::NOT_SET;
                break;
            case Aws::GameLift::Model::GameServerClaimStatus::CLAIMED:
                this->claimStatus = EAWSGameServerClaimStatus::CLAIMED;
                break;
            default:
                this->claimStatus = EAWSGameServerClaimStatus::NOT_SET;
                break;
        }

        switch(awsGameServer.GetUtilizationStatus()) {
            case Aws::GameLift::Model::GameServerUtilizationStatus::NOT_SET:
                this->utilizationStatus = EAWSGameServerUtilizationStatus::NOT_SET;
                break;
            case Aws::GameLift::Model::GameServerUtilizationStatus::AVAILABLE:
                this->utilizationStatus = EAWSGameServerUtilizationStatus::AVAILABLE;
                break;
            case Aws::GameLift::Model::GameServerUtilizationStatus::UTILIZED:
                this->utilizationStatus = EAWSGameServerUtilizationStatus::UTILIZED;
                break;
            default:
                this->utilizationStatus = EAWSGameServerUtilizationStatus::NOT_SET;
                break;
        }

        this->registrationTime = FDateTime(1970, 1, 1) + FTimespan(awsGameServer.GetRegistrationTime().Millis() * ETimespan::TicksPerMillisecond);

        this->lastClaimTime = FDateTime(1970, 1, 1) + FTimespan(awsGameServer.GetLastClaimTime().Millis() * ETimespan::TicksPerMillisecond);

        this->lastHealthCheckTime = FDateTime(1970, 1, 1) + FTimespan(awsGameServer.GetLastHealthCheckTime().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
