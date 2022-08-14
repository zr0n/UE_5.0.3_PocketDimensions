/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/GameSessionDetail.h"

#endif

#include "Model/AWSGameSession.h"
#include "Model/ProtectionPolicy.h"

#include "GameSessionDetail.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameSessionDetail {
GENERATED_BODY()

    /**
    *  <p>Object that describes a game session.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FAWSGameSession gameSession;

    /**
    *  <p>Current status of protection for the game session.</p> <ul> <li> <p> <b>NoProtection</b> -- The game session can be terminated during a scale-down event.</p> </li> <li> <p> <b>FullProtection</b> -- If the game session is in an <code>ACTIVE</code> status, it cannot be terminated during a scale-down event.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EProtectionPolicy protectionPolicy = EProtectionPolicy::NOT_SET;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FAWSGameSessionDetail &fromAWS(const Aws::GameLift::Model::GameSessionDetail &awsGameSessionDetail) {
        this->gameSession.fromAWS(awsGameSessionDetail.GetGameSession());

        switch(awsGameSessionDetail.GetProtectionPolicy()) {
            case Aws::GameLift::Model::ProtectionPolicy::NOT_SET:
                this->protectionPolicy = EProtectionPolicy::NOT_SET;
                break;
            case Aws::GameLift::Model::ProtectionPolicy::NoProtection:
                this->protectionPolicy = EProtectionPolicy::NoProtection;
                break;
            case Aws::GameLift::Model::ProtectionPolicy::FullProtection:
                this->protectionPolicy = EProtectionPolicy::FullProtection;
                break;
            default:
                this->protectionPolicy = EProtectionPolicy::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
