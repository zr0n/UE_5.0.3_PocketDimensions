/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/UpdateGameSessionRequest.h"

#endif

#include "Model/PlayerSessionCreationPolicy.h"
#include "Model/ProtectionPolicy.h"
#include "Utils/GameLiftUtils.h"

#include "GameLiftGlobals.h"

#include "UpdateGameSessionRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateGameSessionRequest {
    GENERATED_BODY()

    /**
	 * <p>Unique identifier for the game session to update.</p>
	 * gameSessionId
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Client")
	FString awsResourceName;

    /**
    *  <p>Maximum number of players that can be connected simultaneously to the game session.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int maximumPlayerSessionCount = 0;

    /**
    *  <p>Descriptive label that is associated with a game session. Session names do not need to be unique.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString name;

    /**
    *  <p>Policy determining whether or not the game session accepts new players.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EPlayerSessionCreationPolicy playerSessionCreationPolicy = EPlayerSessionCreationPolicy::NOT_SET;

    /**
    *  <p>Game session protection policy to apply to this game session only.</p> <ul> <li> <p> <b>NoProtection</b> -- The game session can be terminated during a scale-down event.</p> </li> <li> <p> <b>FullProtection</b> -- If the game session is in an <code>ACTIVE</code> status, it cannot be terminated during a scale-down event.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EProtectionPolicy protectionPolicy = EProtectionPolicy::NOT_SET;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    public:
        Aws::GameLift::Model::UpdateGameSessionRequest toAWS() const {
            Aws::GameLift::Model::UpdateGameSessionRequest awsUpdateGameSessionRequest;

            switch (UGameLiftUtils::IdentifyGameLiftARNType(this->awsResourceName)) {
                case EGameLiftARNType::GameSession_Id:
                    awsUpdateGameSessionRequest.SetGameSessionId(TCHAR_TO_UTF8(*this->awsResourceName));
                    break;
                case EGameLiftARNType::Fleet_Id:
                case EGameLiftARNType::Alias_Id:
                    LOG_GAMELIFT_ERROR("fleet id or alias id is not avaliable");
                    break;
                default:
                    LOG_GAMELIFT_ERROR("Illegal string");
                    break;
            }

            if (this->maximumPlayerSessionCount != 0) {
                awsUpdateGameSessionRequest.SetMaximumPlayerSessionCount(this->maximumPlayerSessionCount);
            }

            if (!(this->name.IsEmpty())) {
                awsUpdateGameSessionRequest.SetName(TCHAR_TO_UTF8(*this->name));
            }

            switch(this->playerSessionCreationPolicy) {
                case EPlayerSessionCreationPolicy::ACCEPT_ALL:
                    awsUpdateGameSessionRequest.SetPlayerSessionCreationPolicy(Aws::GameLift::Model::PlayerSessionCreationPolicy::ACCEPT_ALL);
                    break;
                case EPlayerSessionCreationPolicy::DENY_ALL:
                    awsUpdateGameSessionRequest.SetPlayerSessionCreationPolicy(Aws::GameLift::Model::PlayerSessionCreationPolicy::DENY_ALL);
                    break;
                default:
                    break;
            }

            switch(this->protectionPolicy) {
                case EProtectionPolicy::NoProtection:
                    awsUpdateGameSessionRequest.SetProtectionPolicy(Aws::GameLift::Model::ProtectionPolicy::NoProtection);
                    break;
                case EProtectionPolicy::FullProtection:
                    awsUpdateGameSessionRequest.SetProtectionPolicy(Aws::GameLift::Model::ProtectionPolicy::FullProtection);
                    break;
                default:
                    break;
            }

            return awsUpdateGameSessionRequest;
        }

        bool IsEmpty() const {
            return this->awsResourceName.IsEmpty() && this->maximumPlayerSessionCount == 0 && this->name.IsEmpty() && this->playerSessionCreationPolicy == EPlayerSessionCreationPolicy::NOT_SET && this->protectionPolicy == EProtectionPolicy::NOT_SET;
        }
#endif
};
