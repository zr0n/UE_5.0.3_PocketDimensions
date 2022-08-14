/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFT

#include "aws/gamelift/server/model/StartMatchBackfillResult.h"

#endif

#include "StartMatchBackfillResultServer.generated.h"

USTRUCT(BlueprintType)
struct FStartMatchBackfillResultServer {
    GENERATED_BODY()

    /**
     * <p>TicketId used for the submitted match backfill request.</p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString ticketId;

#if WITH_GAMELIFT
    public:
    FStartMatchBackfillResultServer& fromAWS(const Aws::GameLift::Server::Model::StartMatchBackfillResult& awsStartMatchBackfillResult) {
        this->ticketId = awsStartMatchBackfillResult.GetTicketId();

        return *this;
    };

#endif
};