/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreatePlayerSessionsResult.h"

#endif

#include "Model/PlayerSession.h"

#include "CreatePlayerSessionsResult.generated.h"

USTRUCT(BlueprintType)
struct FCreatePlayerSessionsResult {
GENERATED_BODY()

    /**
    *  <p>Collection of player session objects created for the added players.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FAWSPlayerSession> playerSessions;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FCreatePlayerSessionsResult &fromAWS(const Aws::GameLift::Model::CreatePlayerSessionsResult &awsCreatePlayerSessionsResult) {
        this->playerSessions.Empty();
        for (const Aws::GameLift::Model::PlayerSession& elem : awsCreatePlayerSessionsResult.GetPlayerSessions()) {
            this->playerSessions.Add(FAWSPlayerSession().fromAWS(elem));
        }

        return *this;
    }
#endif
};
