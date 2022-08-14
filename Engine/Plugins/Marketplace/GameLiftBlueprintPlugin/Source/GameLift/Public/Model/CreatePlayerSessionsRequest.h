/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreatePlayerSessionsRequest.h"

#endif

#include "Utils/GameLiftUtils.h"

#include "GameLiftGlobals.h"

#include "CreatePlayerSessionsRequest.generated.h"

USTRUCT(BlueprintType)
struct FCreatePlayerSessionsRequest {
GENERATED_BODY()

    /**
    * <p>Unique identifier for the game session to add players to.</p>
    * gameSessionId
    */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Client")
	FString awsResourceName;

    /**
    *  <p>List of unique identifiers for the players to be added.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FString> playerIds;

    /**
    *  <p>Map of string pairs, each specifying a player ID and a set of developer-defined information related to the player. Amazon GameLift does not use this data, so it can be formatted as needed for use in the game. Player data strings for player IDs not included in the <code>PlayerIds</code> parameter are ignored. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TMap<FString, FString> playerDataMap;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::CreatePlayerSessionsRequest toAWS() const {
        Aws::GameLift::Model::CreatePlayerSessionsRequest awsCreatePlayerSessionsRequest;

        switch (UGameLiftUtils::IdentifyGameLiftARNType(this->awsResourceName)) {
            case EGameLiftARNType::GameSession_Id:
                awsCreatePlayerSessionsRequest.SetGameSessionId(TCHAR_TO_UTF8(*this->awsResourceName));
                break;
            case EGameLiftARNType::Fleet_Id:
            case EGameLiftARNType::Alias_Id:
                LOG_GAMELIFT_ERROR("fleet id or alias id is not avaliable");
                break;
            default:
                LOG_GAMELIFT_ERROR("Illegal string");
                break;
		}

        for (const FString& elem : this->playerIds) {
            awsCreatePlayerSessionsRequest.AddPlayerIds(TCHAR_TO_UTF8(*elem));
        }

        for (const TPair<FString, FString>& elem : this->playerDataMap) {
            awsCreatePlayerSessionsRequest.AddPlayerDataMap(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsCreatePlayerSessionsRequest;
    }

    bool IsEmpty() const {
        return this->awsResourceName.IsEmpty() && this->playerIds.Num() == 0 && this->playerDataMap.Num() == 0;
    }
#endif
};
