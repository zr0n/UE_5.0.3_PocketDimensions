/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreatePlayerSessionRequest.h"

#endif

#include "Utils/GameLiftUtils.h"

#include "GameLiftGlobals.h"

#include "CreatePlayerSessionRequest.generated.h"

USTRUCT(BlueprintType)
struct FCreatePlayerSessionRequest {
GENERATED_BODY()

	/**
	* <p>Unique identifier for the game session to add players to.</p>
	* gameSessionId
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Client")
	FString awsResourceName;

    /**
    *  <p>Unique identifier for a player. Player IDs are developer-defined.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString playerId;

    /**
    *  <p>Developer-defined information related to a player. Amazon GameLift does not use this data, so it can be formatted as needed for use in the game.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString playerData;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::CreatePlayerSessionRequest toAWS() const {
        Aws::GameLift::Model::CreatePlayerSessionRequest awsCreatePlayerSessionRequest;

		switch (UGameLiftUtils::IdentifyGameLiftARNType(this->awsResourceName)) {
			case EGameLiftARNType::GameSession_Id:
				awsCreatePlayerSessionRequest.SetGameSessionId(TCHAR_TO_UTF8(*this->awsResourceName));
				break;
			case EGameLiftARNType::Fleet_Id:
			case EGameLiftARNType::Alias_Id:
				LOG_GAMELIFT_ERROR("fleet id or alias id is not avaliable");
				break;
			default:
				LOG_GAMELIFT_ERROR("Illegal string");
				break;
		}

        if (!(this->playerId.IsEmpty())) {
            awsCreatePlayerSessionRequest.SetPlayerId(TCHAR_TO_UTF8(*this->playerId));
        }

        if (!(this->playerData.IsEmpty())) {
            awsCreatePlayerSessionRequest.SetPlayerData(TCHAR_TO_UTF8(*this->playerData));
        }

        return awsCreatePlayerSessionRequest;
    }

    bool IsEmpty() const {
        return this->awsResourceName.IsEmpty() && this->playerId.IsEmpty() && this->playerData.IsEmpty();
    }
#endif
};
