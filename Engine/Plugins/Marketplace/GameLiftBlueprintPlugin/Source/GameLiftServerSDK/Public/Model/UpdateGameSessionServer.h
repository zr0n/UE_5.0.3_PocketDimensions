/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFT

#include "aws/gamelift/server/model/UpdateGameSession.h"

#endif

#include "Model/AWSGameSessionServer.h"
#include "Model/UpdateReason.h"

#include "UpdateGameSessionServer.generated.h"

USTRUCT(BlueprintType)
struct FUpdateGameSessionServer {
    GENERATED_BODY()

    /**
     * <p>The ticketId used for the submitted match backfill request that this update is in
     *    response to.  Empty if this update was not in response to a backfill.</p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Server")
    FString backfillTicketId;

    /**
     * <p>The current state of the GameSession.</p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Server")
    FAWSGameSessionServer gameSession;

    /**
     * <p>The reason that this update is being posted to the game server.</p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Server")
    EUpdateReason updateReason = EUpdateReason::UNKNOWN;

#if WITH_GAMELIFT
    public:
	FUpdateGameSessionServer& fromAWS(const Aws::GameLift::Server::Model::UpdateGameSession& awsUpdateGameSession) {
        this->backfillTicketId = awsUpdateGameSession.GetBackfillTicketId();

        this->gameSession.fromAWS(awsUpdateGameSession.GetGameSession());

        switch (awsUpdateGameSession.GetUpdateReason()) {
            case Aws::GameLift::Server::Model::UpdateReason::MATCHMAKING_DATA_UPDATED:
                this->updateReason = EUpdateReason ::MATCHMAKING_DATA_UPDATED;
                break;
            case Aws::GameLift::Server::Model::UpdateReason::BACKFILL_FAILED:
                this->updateReason = EUpdateReason ::BACKFILL_FAILED;
                break;
            case Aws::GameLift::Server::Model::UpdateReason::BACKFILL_TIMED_OUT:
                this->updateReason = EUpdateReason ::BACKFILL_TIMED_OUT;
                break;
            case Aws::GameLift::Server::Model::UpdateReason::BACKFILL_CANCELLED:
                this->updateReason = EUpdateReason ::BACKFILL_CANCELLED;
                break;
            case Aws::GameLift::Server::Model::UpdateReason::UNKNOWN:
                this->updateReason = EUpdateReason ::UNKNOWN;
                break;
            default:
                break;
        }

        return *this;
    };

#endif
};