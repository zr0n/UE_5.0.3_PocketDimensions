/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFT

#include "aws/gamelift/server/model/Player.h"

#endif

#include "AWSPlayerServer.generated.h"

USTRUCT(BlueprintType)
struct FNamedAttribute {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FAttributeValueServer value;

#if WITH_GAMELIFT
    public:
    Aws::GameLift::Server::Model::Player::NamedAttribute toAWS() const {
        return Aws::GameLift::Server::Model::Player::NamedAttribute(TCHAR_TO_UTF8(*this->name), this->value.toAWS());
    };

#endif
};

USTRUCT(BlueprintType)
struct FRegionAndLatency {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString region;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    int latencyMs = 0;

#if WITH_GAMELIFT
    public:
    Aws::GameLift::Server::Model::Player::RegionAndLatency toAWS() const {
        return Aws::GameLift::Server::Model::Player::RegionAndLatency(TCHAR_TO_UTF8(*this->region), this->latencyMs);
    };

#endif
};

USTRUCT(BlueprintType)
struct FAWSPlayerServer {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString playerId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString team;

    /*
     * don't add more than 10 elements
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    TArray<FNamedAttribute> playerAttributes;

    /*
     * don't add more than 20 elements
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    TArray<FRegionAndLatency> latencyInMs;

#if WITH_GAMELIFT
    public:
    Aws::GameLift::Server::Model::Player toAWS() const {
        Aws::GameLift::Server::Model::Player awsPlayer;

        awsPlayer.SetPlayerId(TCHAR_TO_UTF8(*this->playerId));
        awsPlayer.SetTeam(TCHAR_TO_UTF8(*this->team));

        for (const FNamedAttribute &playerAttribute : this->playerAttributes) {
            awsPlayer.AddPlayerAttribute(TCHAR_TO_UTF8(*playerAttribute.name), playerAttribute.value.toAWS());
        }

        for (const FRegionAndLatency &awsLatencyInMs : this->latencyInMs) {
            awsPlayer.AddLatencyMs(TCHAR_TO_UTF8(*awsLatencyInMs.region), awsLatencyInMs.latencyMs);
        }

        return awsPlayer;
    };

#endif
};