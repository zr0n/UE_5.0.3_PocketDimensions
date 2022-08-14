/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFT

#include "aws/gamelift/server/model/PlayerSession.h"

#endif

#include "Model/PlayerSessionStatusServer.h"

#include "AWSPlayerSessionServer.generated.h"

USTRUCT(BlueprintType)
struct FAWSPlayerSessionServer {
    GENERATED_BODY()

    /**
     * <p>Unique identifier for a player session.</p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString playerSessionId;

    /**
     * <p>Unique identifier for a player.</p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString playerId;

    /**
     * <p>Unique identifier for the game session that the player session is connected
     * to.</p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString gameSessionId;

    /**
     * <p>Unique identifier for a fleet.</p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString fleetId;

    /**
     * <p>Time stamp indicating when this data object was created.</p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FDateTime creationTime;

    /**
     * <p>Time stamp indicating when this data object was terminated. Format is a
     * number expressed in Unix time as milliseconds (ex: "1469498468.057".</p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FDateTime terminationTime;

    /**
     * <p>Current status of the player session.</p> <p>Possible player session statuses
     * include the following:</p> <ul> <li> <p> <b>RESERVED</b> – The player session
     * request has been received, but the player has not yet connected to the server
     * process and/or been validated. </p> </li> <li> <p> <b>ACTIVE</b> – The player
     * has been validated by the server process and is currently connected.</p> </li>
     * <li> <p> <b>COMPLETED</b> – The player connection has been dropped.</p> </li>
     * <li> <p> <b>TIMEDOUT</b> – A player session request was received, but the player
     * did not connect and/or was not validated within the time-out limit (60
     * seconds).</p> </li> </ul>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    EPlayerSessionStatusServer status = EPlayerSessionStatusServer::NOT_SET;

    /**
     * <p>Game session IP address. All player sessions reference the game session
     * location.</p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString ipAddress;

    /**
     * <p>Port number for the game session. To connect to a GameLift server process, an
     * app needs both the IP address and port number.</p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    int port = 0;

    /**
     * <p>Custom player data.</p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString playerData;

    /**
    * <p>Game session DNS name. All player sessions reference the game session
    * location.</p>
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString dnsName;

#if WITH_GAMELIFT
    public:
    FAWSPlayerSessionServer& fromAWS(const Aws::GameLift::Server::Model::PlayerSession& awsPlayerSession) {
        this->playerSessionId = awsPlayerSession.GetPlayerSessionId();
        this->playerId = awsPlayerSession.GetPlayerId();
        this->gameSessionId = awsPlayerSession.GetGameSessionId();
        this->fleetId = awsPlayerSession.GetFleetId();
        this->creationTime = FDateTime::FromUnixTimestamp(awsPlayerSession.GetCreationTime());
        this->terminationTime = FDateTime::FromUnixTimestamp(awsPlayerSession.GetTerminationTime());

        switch (awsPlayerSession.GetStatus()) {
            case Aws::GameLift::Server::Model::PlayerSessionStatus::NOT_SET:
                this->status = EPlayerSessionStatusServer::NOT_SET;
                break;
            case Aws::GameLift::Server::Model::PlayerSessionStatus::RESERVED:
                this->status = EPlayerSessionStatusServer::RESERVED;
                break;
            case Aws::GameLift::Server::Model::PlayerSessionStatus::ACTIVE:
                this->status = EPlayerSessionStatusServer::ACTIVE;
                break;
            case Aws::GameLift::Server::Model::PlayerSessionStatus::COMPLETED:
                this->status = EPlayerSessionStatusServer::COMPLETED;
                break;
            case Aws::GameLift::Server::Model::PlayerSessionStatus::TIMEDOUT:
                this->status = EPlayerSessionStatusServer::TIMEDOUT;
                break;
            default:
                break;
        }

        this->ipAddress = awsPlayerSession.GetIpAddress();
        this->port = awsPlayerSession.GetPort();
        this->playerData = awsPlayerSession.GetPlayerData();
        this->dnsName = awsPlayerSession.GetDnsName();

        return *this;
    };

#endif
};