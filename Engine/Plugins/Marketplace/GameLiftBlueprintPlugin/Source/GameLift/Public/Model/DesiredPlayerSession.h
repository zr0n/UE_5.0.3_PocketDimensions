/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DesiredPlayerSession.h"

#endif

#include "DesiredPlayerSession.generated.h"

USTRUCT(BlueprintType)
struct FDesiredPlayerSession {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a player to associate with the player session.</p>
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
    Aws::GameLift::Model::DesiredPlayerSession toAWS() const {
        Aws::GameLift::Model::DesiredPlayerSession awsDesiredPlayerSession;

        if (!(this->playerId.IsEmpty())) {
            awsDesiredPlayerSession.SetPlayerId(TCHAR_TO_UTF8(*this->playerId));
        }

        if (!(this->playerData.IsEmpty())) {
            awsDesiredPlayerSession.SetPlayerData(TCHAR_TO_UTF8(*this->playerData));
        }

        return awsDesiredPlayerSession;
    }

    bool IsEmpty() const {
        return this->playerId.IsEmpty() && this->playerData.IsEmpty();
    }
#endif
};
