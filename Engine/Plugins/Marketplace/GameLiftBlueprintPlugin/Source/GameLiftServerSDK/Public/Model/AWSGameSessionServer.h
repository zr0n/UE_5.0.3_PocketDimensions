/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFT

#include "aws/gamelift/server/model/GameSession.h"

#endif

#include "Model/AWSGameSessionStatusServer.h"
#include "Model/GamePropertyServer.h"

#include "AWSGameSessionServer.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameSessionServer {
    GENERATED_BODY()

    /**
    * <p>Unique identifier for a game session.</p>
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Server")
    FString gameSessionId;

    /**
    * <p>Descriptive label associated with a game session. Session names do not need
    * to be unique.</p>
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Server")
    FString name;

    /**
    * <p>Unique identifier for a fleet.</p>
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Server")
    FString fleetId;

    /**
    * <p>Maximum number of players allowed in the game session.</p>
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Server")
    int maximumPlayerSessionCount = 0;

    /**
    * <p>Current status of the game session. A game session must be in an
    * <code>ACTIVE</code> state to have player sessions.</p>
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Server")
    EGameSessionStatusServer status = EGameSessionStatusServer::NOT_SET;

    /**
     * <p>Set of custom property for the game session.</p>
     * don't add more than 32 elements
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Server")
    TArray<FGamePropertyServer> gameProperties;

    /**
    * <p>IP address of the game session. To connect to a GameLift server process, an
    * app needs both the IP address and port number.</p>
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Server")
    FString ipAddress;

    /**
    * <p>Port number for the game session. To connect to a GameLift server process, an
    * app needs both the IP address and port number.</p>
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Server")
    int port = 0;

    /**
    * <p>Custom data for the game session.</p>
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Server")
    FString gameSessionData;

    /**
    * <p>Data generated from GameLift Matchmaking.</p>
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Server")
    FString matchmakerData;

    /**
    * The DNS name of the host running a GameLift server process, used for establishing a TLS connection for a game session.
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Server")
    FString dnsName;

#if WITH_GAMELIFT
    public:
    FAWSGameSessionServer& fromAWS(const Aws::GameLift::Server::Model::GameSession& awsGameSession) {
        this->gameSessionId = awsGameSession.GetGameSessionId();
        this->name = awsGameSession.GetName();
        this->fleetId = awsGameSession.GetFleetId();
        this->maximumPlayerSessionCount = awsGameSession.GetMaximumPlayerSessionCount();

        switch (awsGameSession.GetStatus()) {
            case Aws::GameLift::Server::Model::GameSessionStatus::NOT_SET:
                this->status = EGameSessionStatusServer::NOT_SET;
                break;
            case Aws::GameLift::Server::Model::GameSessionStatus::ACTIVE:
                this->status = EGameSessionStatusServer::ACTIVE;
                break;
            case Aws::GameLift::Server::Model::GameSessionStatus::ACTIVATING:
                this->status = EGameSessionStatusServer::ACTIVATING;
                break;
            case Aws::GameLift::Server::Model::GameSessionStatus::TERMINATED:
                this->status = EGameSessionStatusServer::TERMINATED;
                break;
            case Aws::GameLift::Server::Model::GameSessionStatus::TERMINATING:
                this->status = EGameSessionStatusServer::TERMINATING;
                break;
            default:
                break;
        }

        int count = 0;
        const Aws::GameLift::Server::Model::GameProperty* awsGameProperties = awsGameSession.GetGameProperties(count);
        this->gameProperties.Empty();
        for (int i = 0; i < count; i++) {
            this->gameProperties.Add(FGamePropertyServer().fromAWS(awsGameProperties[i]));
        }

        this->ipAddress = awsGameSession.GetIpAddress();
        this->port = awsGameSession.GetPort();
        this->gameSessionData = awsGameSession.GetGameSessionData();
        this->matchmakerData = awsGameSession.GetMatchmakerData();
        this->dnsName = awsGameSession.GetDnsName();

        return *this;
    };

#endif
};