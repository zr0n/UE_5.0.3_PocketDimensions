/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/GameSessionPlacement.h"

#endif

#include "Model/GameSessionPlacementState.h"
#include "Model/GameProperty.h"
#include "Model/PlayerLatency.h"
#include "Model/PlacedPlayerSession.h"

#include "GameSessionPlacement.generated.h"

USTRUCT(BlueprintType)
struct FGameSessionPlacement {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a game session placement.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString placementId;

    /**
    *  <p>Descriptive label that is associated with game session queue. Queue names must be unique within each region.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameSessionQueueName;

    /**
    *  <p>Current status of the game session placement request.</p> <ul> <li> <p> <b>PENDING</b> -- The placement request is currently in the queue waiting to be processed.</p> </li> <li> <p> <b>FULFILLED</b> -- A new game session and player sessions (if requested) have been successfully created. Values for <i>GameSessionArn</i> and <i>GameSessionRegion</i> are available. </p> </li> <li> <p> <b>CANCELLED</b> -- The placement request was canceled with a call to <a>StopGameSessionPlacement</a>.</p> </li> <li> <p> <b>TIMED_OUT</b> -- A new game session was not successfully created before the time limit expired. You can resubmit the placement request as needed.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EGameSessionPlacementState status = EGameSessionPlacementState::NOT_SET;

    /**
    *  <p>Set of custom properties for a game session, formatted as key:value pairs. These properties are passed to a game server process in the <a>GameSession</a> object with a request to start a new game session (see <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/gamelift-sdk-server-api.html#gamelift-sdk-server-startsession">Start a Game Session</a>).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FGameProperty> gameProperties;

    /**
    *  <p>Maximum number of players that can be connected simultaneously to the game session.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int maximumPlayerSessionCount = 0;

    /**
    *  <p>Descriptive label that is associated with a game session. Session names do not need to be unique.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameSessionName;

    /**
    *  <p>Unique identifier for the game session. This value is set once the new game session is placed (placement status is <code>FULFILLED</code>).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameSessionId;

    /**
    *  <p>Identifier for the game session created by this placement request. This value is set once the new game session is placed (placement status is <code>FULFILLED</code>). This identifier is unique across all regions. You can use this value as a <code>GameSessionId</code> value as needed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameSessionArn;

    /**
    *  <p>Name of the region where the game session created by this placement request is running. This value is set once the new game session is placed (placement status is <code>FULFILLED</code>).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameSessionRegion;

    /**
    *  <p>Set of values, expressed in milliseconds, indicating the amount of latency that a player experiences when connected to AWS regions.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FPlayerLatency> playerLatencies;

    /**
    *  <p>Time stamp indicating when this request was placed in the queue. Format is a number expressed in Unix time as milliseconds (for example "1469498468.057").</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FDateTime startTime;

    /**
    *  <p>Time stamp indicating when this request was completed, canceled, or timed out.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FDateTime endTime;

    /**
    *  <p>IP address of the game session. To connect to a Amazon GameLift game server, an app needs both the IP address and port number. This value is set once the new game session is placed (placement status is <code>FULFILLED</code>). </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString ipAddress;

    /**
    *  <p>DNS identifier assigned to the instance that is running the game session. Values have the following format:</p> <ul> <li> <p>TLS-enabled fleets: <code>&lt;unique identifier&gt;.&lt;region identifier&gt;.amazongamelift.com</code>.</p> </li> <li> <p>Non-TLS-enabled fleets: <code>ec2-&lt;unique identifier&gt;.compute.amazonaws.com</code>. (See <a href="https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/using-instance-addressing.html#concepts-public-addresses">Amazon EC2 Instance IP Addressing</a>.)</p> </li> </ul> <p>When connecting to a game session that is running on a TLS-enabled fleet, you must use the DNS name, not the IP address.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString dnsName;

    /**
    *  <p>Port number for the game session. To connect to a Amazon GameLift game server, an app needs both the IP address and port number. This value is set once the new game session is placed (placement status is <code>FULFILLED</code>).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int port = 0;

    /**
    *  <p>Collection of information on player sessions created in response to the game session placement request. These player sessions are created only once a new game session is successfully placed (placement status is <code>FULFILLED</code>). This information includes the player ID (as provided in the placement request) and the corresponding player session ID. Retrieve full player sessions by calling <a>DescribePlayerSessions</a> with the player session ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FPlacedPlayerSession> placedPlayerSessions;

    /**
    *  <p>Set of custom game session properties, formatted as a single string value. This data is passed to a game server process in the <a>GameSession</a> object with a request to start a new game session (see <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/gamelift-sdk-server-api.html#gamelift-sdk-server-startsession">Start a Game Session</a>).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameSessionData;

    /**
    *  <p>Information on the matchmaking process for this game. Data is in JSON syntax, formatted as a string. It identifies the matchmaking configuration used to create the match, and contains data on all players assigned to the match, including player attributes and team assignments. For more details on matchmaker data, see <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/match-server.html#match-server-data">Match Data</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString matchmakerData;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FGameSessionPlacement &fromAWS(const Aws::GameLift::Model::GameSessionPlacement &awsGameSessionPlacement) {
        this->placementId = UTF8_TO_TCHAR(awsGameSessionPlacement.GetPlacementId().c_str());

        this->gameSessionQueueName = UTF8_TO_TCHAR(awsGameSessionPlacement.GetGameSessionQueueName().c_str());

        switch(awsGameSessionPlacement.GetStatus()) {
            case Aws::GameLift::Model::GameSessionPlacementState::NOT_SET:
                this->status = EGameSessionPlacementState::NOT_SET;
                break;
            case Aws::GameLift::Model::GameSessionPlacementState::PENDING:
                this->status = EGameSessionPlacementState::PENDING;
                break;
            case Aws::GameLift::Model::GameSessionPlacementState::FULFILLED:
                this->status = EGameSessionPlacementState::FULFILLED;
                break;
            case Aws::GameLift::Model::GameSessionPlacementState::CANCELLED:
                this->status = EGameSessionPlacementState::CANCELLED;
                break;
            case Aws::GameLift::Model::GameSessionPlacementState::TIMED_OUT:
                this->status = EGameSessionPlacementState::TIMED_OUT;
                break;
            case Aws::GameLift::Model::GameSessionPlacementState::FAILED:
                this->status = EGameSessionPlacementState::FAILED;
                break;
            default:
                this->status = EGameSessionPlacementState::NOT_SET;
                break;
        }

        this->gameProperties.Empty();
        for (const Aws::GameLift::Model::GameProperty& elem : awsGameSessionPlacement.GetGameProperties()) {
            this->gameProperties.Add(FGameProperty().fromAWS(elem));
        }

        this->maximumPlayerSessionCount = awsGameSessionPlacement.GetMaximumPlayerSessionCount();

        this->gameSessionName = UTF8_TO_TCHAR(awsGameSessionPlacement.GetGameSessionName().c_str());

        this->gameSessionId = UTF8_TO_TCHAR(awsGameSessionPlacement.GetGameSessionId().c_str());

        this->gameSessionArn = UTF8_TO_TCHAR(awsGameSessionPlacement.GetGameSessionArn().c_str());

        this->gameSessionRegion = UTF8_TO_TCHAR(awsGameSessionPlacement.GetGameSessionRegion().c_str());

        this->playerLatencies.Empty();
        for (const Aws::GameLift::Model::PlayerLatency& elem : awsGameSessionPlacement.GetPlayerLatencies()) {
            this->playerLatencies.Add(FPlayerLatency().fromAWS(elem));
        }

        this->startTime = FDateTime(1970, 1, 1) + FTimespan(awsGameSessionPlacement.GetStartTime().Millis() * ETimespan::TicksPerMillisecond);

        this->endTime = FDateTime(1970, 1, 1) + FTimespan(awsGameSessionPlacement.GetEndTime().Millis() * ETimespan::TicksPerMillisecond);

        this->ipAddress = UTF8_TO_TCHAR(awsGameSessionPlacement.GetIpAddress().c_str());

        this->dnsName = UTF8_TO_TCHAR(awsGameSessionPlacement.GetDnsName().c_str());

        this->port = awsGameSessionPlacement.GetPort();

        this->placedPlayerSessions.Empty();
        for (const Aws::GameLift::Model::PlacedPlayerSession& elem : awsGameSessionPlacement.GetPlacedPlayerSessions()) {
            this->placedPlayerSessions.Add(FPlacedPlayerSession().fromAWS(elem));
        }

        this->gameSessionData = UTF8_TO_TCHAR(awsGameSessionPlacement.GetGameSessionData().c_str());

        this->matchmakerData = UTF8_TO_TCHAR(awsGameSessionPlacement.GetMatchmakerData().c_str());

        return *this;
    }
#endif
};
