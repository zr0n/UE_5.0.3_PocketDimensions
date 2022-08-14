/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/StartMatchmakingRequest.h"

#endif

#include "Model/AWSPlayer.h"

#include "StartMatchmakingRequest.generated.h"

USTRUCT(BlueprintType)
struct FStartMatchmakingRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a matchmaking ticket. If no ticket ID is specified here, Amazon GameLift will generate one in the form of a UUID. Use this identifier to track the matchmaking ticket status and retrieve match results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString ticketId;

    /**
    *  <p>Name of the matchmaking configuration to use for this request. Matchmaking configurations must exist in the same region as this request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString configurationName;

    /**
    *  <p>Information on each player to be matched. This information must include a player ID, and may contain player attributes and latency data to be used in the matchmaking process. After a successful match, <code>Player</code> objects contain the name of the team the player is assigned to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FAWSPlayer> players;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::StartMatchmakingRequest toAWS() const {
        Aws::GameLift::Model::StartMatchmakingRequest awsStartMatchmakingRequest;

        if (!(this->ticketId.IsEmpty())) {
            awsStartMatchmakingRequest.SetTicketId(TCHAR_TO_UTF8(*this->ticketId));
        }

        if (!(this->configurationName.IsEmpty())) {
            awsStartMatchmakingRequest.SetConfigurationName(TCHAR_TO_UTF8(*this->configurationName));
        }

        for (const FAWSPlayer& elem : this->players) {
            awsStartMatchmakingRequest.AddPlayers(elem.toAWS());
        }

        return awsStartMatchmakingRequest;
    }

    bool IsEmpty() const {
        return this->ticketId.IsEmpty() && this->configurationName.IsEmpty() && this->players.Num() == 0;
    }
#endif
};
