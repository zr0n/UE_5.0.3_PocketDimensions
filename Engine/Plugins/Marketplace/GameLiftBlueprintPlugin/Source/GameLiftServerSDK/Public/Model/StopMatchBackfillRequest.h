/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFT

#include "aws/gamelift/server/model/StopMatchBackfillRequest.h"

#endif

#include "StopMatchBackfillRequest.generated.h"

USTRUCT(BlueprintType)
struct FStopMatchBackfillRequest {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString ticketId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString matchmakingConfigurationArn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString gameSessionArn;

#if WITH_GAMELIFT
    public:
    Aws::GameLift::Server::Model::StopMatchBackfillRequest toAWS() const {
        Aws::GameLift::Server::Model::StopMatchBackfillRequest awsStopMatchBackfillRequest;

        awsStopMatchBackfillRequest.SetTicketId(TCHAR_TO_UTF8(*this->ticketId));
        awsStopMatchBackfillRequest.SetMatchmakingConfigurationArn(TCHAR_TO_UTF8(*this->matchmakingConfigurationArn));
        awsStopMatchBackfillRequest.SetGameSessionArn(TCHAR_TO_UTF8(*this->gameSessionArn));

        return awsStopMatchBackfillRequest;
    };

#endif
};