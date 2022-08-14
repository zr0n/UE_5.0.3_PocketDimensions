/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/MatchedPlayerSession.h"

#endif

#include "MatchedPlayerSession.generated.h"

USTRUCT(BlueprintType)
struct FMatchedPlayerSession {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a player </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString playerId;

    /**
    *  <p>Unique identifier for a player session</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString playerSessionId;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FMatchedPlayerSession &fromAWS(const Aws::GameLift::Model::MatchedPlayerSession &awsMatchedPlayerSession) {
        this->playerId = UTF8_TO_TCHAR(awsMatchedPlayerSession.GetPlayerId().c_str());

        this->playerSessionId = UTF8_TO_TCHAR(awsMatchedPlayerSession.GetPlayerSessionId().c_str());

        return *this;
    }
#endif
};
