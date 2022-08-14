/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/StartGameSessionPlacementRequest.h"

#endif

#include "Model/GameProperty.h"
#include "Model/PlayerLatency.h"
#include "Model/DesiredPlayerSession.h"

#include "StartGameSessionPlacementRequest.generated.h"

USTRUCT(BlueprintType)
struct FStartGameSessionPlacementRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier to assign to the new game session placement. This value is developer-defined. The value must be unique across all regions and cannot be reused unless you are resubmitting a canceled or timed-out placement request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString placementId;

    /**
    *  <p>Name of the queue to use to place the new game session.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameSessionQueueName;

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
    *  <p>Set of values, expressed in milliseconds, indicating the amount of latency that a player experiences when connected to AWS regions. This information is used to try to place the new game session where it can offer the best possible gameplay experience for the players. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FPlayerLatency> playerLatencies;

    /**
    *  <p>Set of information on each player to create a player session for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FDesiredPlayerSession> desiredPlayerSessions;

    /**
    *  <p>Set of custom game session properties, formatted as a single string value. This data is passed to a game server process in the <a>GameSession</a> object with a request to start a new game session (see <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/gamelift-sdk-server-api.html#gamelift-sdk-server-startsession">Start a Game Session</a>).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameSessionData;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::StartGameSessionPlacementRequest toAWS() const {
        Aws::GameLift::Model::StartGameSessionPlacementRequest awsStartGameSessionPlacementRequest;

        if (!(this->placementId.IsEmpty())) {
            awsStartGameSessionPlacementRequest.SetPlacementId(TCHAR_TO_UTF8(*this->placementId));
        }

        if (!(this->gameSessionQueueName.IsEmpty())) {
            awsStartGameSessionPlacementRequest.SetGameSessionQueueName(TCHAR_TO_UTF8(*this->gameSessionQueueName));
        }

        for (const FGameProperty& elem : this->gameProperties) {
            awsStartGameSessionPlacementRequest.AddGameProperties(elem.toAWS());
        }

        if (this->maximumPlayerSessionCount != 0) {
            awsStartGameSessionPlacementRequest.SetMaximumPlayerSessionCount(this->maximumPlayerSessionCount);
        }

        if (!(this->gameSessionName.IsEmpty())) {
            awsStartGameSessionPlacementRequest.SetGameSessionName(TCHAR_TO_UTF8(*this->gameSessionName));
        }

        for (const FPlayerLatency& elem : this->playerLatencies) {
            awsStartGameSessionPlacementRequest.AddPlayerLatencies(elem.toAWS());
        }

        for (const FDesiredPlayerSession& elem : this->desiredPlayerSessions) {
            awsStartGameSessionPlacementRequest.AddDesiredPlayerSessions(elem.toAWS());
        }

        if (!(this->gameSessionData.IsEmpty())) {
            awsStartGameSessionPlacementRequest.SetGameSessionData(TCHAR_TO_UTF8(*this->gameSessionData));
        }

        return awsStartGameSessionPlacementRequest;
    }

    bool IsEmpty() const {
        return this->placementId.IsEmpty() && this->gameSessionQueueName.IsEmpty() && this->gameProperties.Num() == 0 && this->maximumPlayerSessionCount == 0 && this->gameSessionName.IsEmpty() && this->playerLatencies.Num() == 0 && this->desiredPlayerSessions.Num() == 0 && this->gameSessionData.IsEmpty();
    }
#endif
};
