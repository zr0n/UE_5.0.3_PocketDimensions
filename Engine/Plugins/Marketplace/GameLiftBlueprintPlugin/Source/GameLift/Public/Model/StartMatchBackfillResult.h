/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/StartMatchBackfillResult.h"

#endif

#include "Model/MatchmakingTicket.h"

#include "StartMatchBackfillResult.generated.h"

USTRUCT(BlueprintType)
struct FStartMatchBackfillResult {
GENERATED_BODY()

    /**
    *  <p>Ticket representing the backfill matchmaking request. This object includes the information in the request, ticket status, and match results as generated during the matchmaking process.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FMatchmakingTicket matchmakingTicket;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FStartMatchBackfillResult &fromAWS(const Aws::GameLift::Model::StartMatchBackfillResult &awsStartMatchBackfillResult) {
        this->matchmakingTicket.fromAWS(awsStartMatchBackfillResult.GetMatchmakingTicket());

        return *this;
    }
#endif
};
