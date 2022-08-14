/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/Player.h"

#endif

#include "Model/GameLiftAttributeValue.h"

#include "AWSPlayer.generated.h"

USTRUCT(BlueprintType)
struct FAWSPlayer {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a player</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString playerId;

    /**
    *  <p>Collection of key:value pairs containing player information for use in matchmaking. Player attribute keys must match the <i>playerAttributes</i> used in a matchmaking rule set. Example: <code>"PlayerAttributes": {"skill": {"N": "23"}, "gameMode": {"S": "deathmatch"}}</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TMap<FString, FGameLiftAttributeValue> playerAttributes;

    /**
    *  <p>Name of the team that the player is assigned to in a match. Team names are defined in a matchmaking rule set.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString team;

    /**
    *  <p>Set of values, expressed in milliseconds, indicating the amount of latency that a player experiences when connected to AWS regions. If this property is present, FlexMatch considers placing the match only in regions for which latency is reported. </p> <p>If a matchmaker has a rule that evaluates player latency, players must report latency in order to be matched. If no latency is reported in this scenario, FlexMatch assumes that no regions are available to the player and the ticket is not matchable. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TMap<FString, int> latencyInMs;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::Player toAWS() const {
        Aws::GameLift::Model::Player awsPlayer;

        if (!(this->playerId.IsEmpty())) {
            awsPlayer.SetPlayerId(TCHAR_TO_UTF8(*this->playerId));
        }

        for (const TPair<FString, FGameLiftAttributeValue>& elem : this->playerAttributes) {
            awsPlayer.AddPlayerAttributes(TCHAR_TO_UTF8(*elem.Key), elem.Value.toAWS());
        }

        if (!(this->team.IsEmpty())) {
            awsPlayer.SetTeam(TCHAR_TO_UTF8(*this->team));
        }

        for (const TPair<FString, int>& elem : this->latencyInMs) {
            awsPlayer.AddLatencyInMs(TCHAR_TO_UTF8(*elem.Key), elem.Value);
        }

        return awsPlayer;
    }

    bool IsEmpty() const {
        return this->playerId.IsEmpty() && this->playerAttributes.Num() == 0 && this->team.IsEmpty() && this->latencyInMs.Num() == 0;
    }

    FAWSPlayer &fromAWS(const Aws::GameLift::Model::Player &awsPlayer) {
        this->playerId = UTF8_TO_TCHAR(awsPlayer.GetPlayerId().c_str());

        this->playerAttributes.Empty();
        for (const auto& elem : awsPlayer.GetPlayerAttributes()) {
            this->playerAttributes.Add(elem.first.c_str(), FGameLiftAttributeValue().fromAWS(elem.second));
        }

        this->team = UTF8_TO_TCHAR(awsPlayer.GetTeam().c_str());

        this->latencyInMs.Empty();
        for (const auto& elem : awsPlayer.GetLatencyInMs()) {
            this->latencyInMs.Add(elem.first.c_str(), elem.second);
        }

        return *this;
    }
#endif
};
