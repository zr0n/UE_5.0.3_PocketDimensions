/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/PlacedPlayerSession.h"

#endif

#include "PlacedPlayerSession.generated.h"

USTRUCT(BlueprintType)
struct FPlacedPlayerSession {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a player that is associated with this player session.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString playerId;

    /**
    *  <p>Unique identifier for a player session.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString playerSessionId;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FPlacedPlayerSession &fromAWS(const Aws::GameLift::Model::PlacedPlayerSession &awsPlacedPlayerSession) {
        this->playerId = UTF8_TO_TCHAR(awsPlacedPlayerSession.GetPlayerId().c_str());

        this->playerSessionId = UTF8_TO_TCHAR(awsPlacedPlayerSession.GetPlayerSessionId().c_str());

        return *this;
    }
#endif
};
