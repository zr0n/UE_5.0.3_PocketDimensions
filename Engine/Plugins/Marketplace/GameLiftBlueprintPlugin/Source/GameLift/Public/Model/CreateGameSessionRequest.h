/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreateGameSessionRequest.h"

#endif

#include "Model/GameProperty.h"
#include "Utils/GameLiftUtils.h"

#include "GameLiftGlobals.h"

#include "CreateGameSessionRequest.generated.h"

USTRUCT(BlueprintType)
struct FCreateGameSessionRequest {
GENERATED_BODY()

    /**
	 *<p>Unique identifier for a fleet or an alias to create a game session in. Each request must
	 * reference either a fleet ID or alias ID, but not both.</p>
	 * fleetId / aliasId
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Client")
	FString awsResourceName;

    /**
    *  <p>Maximum number of players that can be connected simultaneously to the game session.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int maximumPlayerSessionCount = 0;

    /**
    *  <p>Descriptive label that is associated with a game session. Session names do not need to be unique.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString name;

    /**
    *  <p>Set of custom properties for a game session, formatted as key:value pairs. These properties are passed to a game server process in the <a>GameSession</a> object with a request to start a new game session (see <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/gamelift-sdk-server-api.html#gamelift-sdk-server-startsession">Start a Game Session</a>).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FGameProperty> gameProperties;

    /**
    *  <p>Unique identifier for a player or entity creating the game session. This ID is used to enforce a resource protection policy (if one exists) that limits the number of concurrent active game sessions one player can have.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString creatorId;

    /**
    *  <p> <i>This parameter is no longer preferred. Please use <code>IdempotencyToken</code> instead.</i> Custom string that uniquely identifies a request for a new game session. Maximum token length is 48 characters. If provided, this string is included in the new game session's ID. (A game session ARN has the following format: <code>arn:aws:gamelift:&lt;region&gt;::gamesession/&lt;fleet ID&gt;/&lt;custom ID string or idempotency token&gt;</code>.) </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameSessionId;

    /**
    *  <p>Custom string that uniquely identifies a request for a new game session. Maximum token length is 48 characters. If provided, this string is included in the new game session's ID. (A game session ARN has the following format: <code>arn:aws:gamelift:&lt;region&gt;::gamesession/&lt;fleet ID&gt;/&lt;custom ID string or idempotency token&gt;</code>.) Idempotency tokens remain in use for 30 days after a game session has ended; game session objects are retained for this time period and then deleted.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString idempotencyToken;

    /**
    *  <p>Set of custom game session properties, formatted as a single string value. This data is passed to a game server process in the <a>GameSession</a> object with a request to start a new game session (see <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/gamelift-sdk-server-api.html#gamelift-sdk-server-startsession">Start a Game Session</a>).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameSessionData;

    /**
    *  <p>A fleet's remote location to place the new game session in. If this parameter is not set, the new game session is placed in the fleet's home Region. Specify a remote location with an AWS Region code such as <code>us-west-2</code>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString location;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::CreateGameSessionRequest toAWS() const {
        Aws::GameLift::Model::CreateGameSessionRequest awsCreateGameSessionRequest;

        switch (UGameLiftUtils::IdentifyGameLiftARNType(this->awsResourceName)) {
            case EGameLiftARNType::Fleet_Id:
                awsCreateGameSessionRequest.SetFleetId(TCHAR_TO_UTF8(*this->awsResourceName));
                break;
            case EGameLiftARNType::Alias_Id:
                awsCreateGameSessionRequest.SetAliasId(TCHAR_TO_UTF8(*this->awsResourceName));
                break;
            case EGameLiftARNType::GameSession_Id:
                LOG_GAMELIFT_ERROR("game session id is not avaliable");
                break;
            default:
                LOG_GAMELIFT_ERROR("Illegal string");
                break;
		}

        if (this->maximumPlayerSessionCount != 0) {
            awsCreateGameSessionRequest.SetMaximumPlayerSessionCount(this->maximumPlayerSessionCount);
        }

        if (!(this->name.IsEmpty())) {
            awsCreateGameSessionRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        for (const FGameProperty& elem : this->gameProperties) {
            awsCreateGameSessionRequest.AddGameProperties(elem.toAWS());
        }

        if (!(this->creatorId.IsEmpty())) {
            awsCreateGameSessionRequest.SetCreatorId(TCHAR_TO_UTF8(*this->creatorId));
        }

        if (!(this->gameSessionId.IsEmpty())) {
            awsCreateGameSessionRequest.SetGameSessionId(TCHAR_TO_UTF8(*this->gameSessionId));
        }

        if (!(this->idempotencyToken.IsEmpty())) {
            awsCreateGameSessionRequest.SetIdempotencyToken(TCHAR_TO_UTF8(*this->idempotencyToken));
        }

        if (!(this->gameSessionData.IsEmpty())) {
            awsCreateGameSessionRequest.SetGameSessionData(TCHAR_TO_UTF8(*this->gameSessionData));
        }

		if (!(this->location.IsEmpty())) {
            awsCreateGameSessionRequest.SetLocation(TCHAR_TO_UTF8(*this->location));
        }

        return awsCreateGameSessionRequest;
    }

    bool IsEmpty() const {
        return this->awsResourceName.IsEmpty() && this->maximumPlayerSessionCount == 0 && this->name.IsEmpty() && this->gameProperties.Num() == 0 && this->creatorId.IsEmpty() && this->gameSessionId.IsEmpty() && this->idempotencyToken.IsEmpty() && this->gameSessionData.IsEmpty() && this->location.IsEmpty();
    }
#endif
};
