/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/StartMatchmakingResult.h"

#endif

#include "Model/MatchmakingTicket.h"

#include "StartMatchmakingResult.generated.h"

USTRUCT(BlueprintType)
struct FStartMatchmakingResult {
    GENERATED_BODY()

    /**
    *  <p>Ticket representing the matchmaking request. This object include the information included in the request, ticket status, and match results as generated during the matchmaking process.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FMatchmakingTicket matchmakingTicket;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FStartMatchmakingResult &fromAWS(const Aws::GameLift::Model::StartMatchmakingResult &awsStartMatchmakingResult) {
        this->matchmakingTicket.fromAWS(awsStartMatchmakingResult.GetMatchmakingTicket());

        return *this;
    }
#endif
};
