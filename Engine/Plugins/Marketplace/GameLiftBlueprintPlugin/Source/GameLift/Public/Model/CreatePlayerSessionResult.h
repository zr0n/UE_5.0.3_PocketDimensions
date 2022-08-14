/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreatePlayerSessionResult.h"

#endif

#include "Model/PlayerSession.h"

#include "CreatePlayerSessionResult.generated.h"

USTRUCT(BlueprintType)
struct FCreatePlayerSessionResult {
GENERATED_BODY()

    /**
    *  <p>Object that describes the newly created player session record.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FAWSPlayerSession playerSession;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FCreatePlayerSessionResult &fromAWS(const Aws::GameLift::Model::CreatePlayerSessionResult &awsCreatePlayerSessionResult) {
        this->playerSession.fromAWS(awsCreatePlayerSessionResult.GetPlayerSession());

        return *this;
    }
#endif
};
