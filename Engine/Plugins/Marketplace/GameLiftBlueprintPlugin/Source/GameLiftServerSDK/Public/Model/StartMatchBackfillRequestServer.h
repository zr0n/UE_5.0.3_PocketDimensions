/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFT

#include "aws/gamelift/server/model/StartMatchBackfillRequest.h"

#endif

#include "Model/AWSPlayerServer.h"

#include "StartMatchBackfillRequestServer.generated.h"

USTRUCT(BlueprintType)
struct FStartMatchBackfillRequestServer {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString ticketId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString matchmakingConfigurationArn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString gameSessionArn;

    /*
     * don't add more than 40 elements
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    TArray<FAWSPlayerServer> players;

#if WITH_GAMELIFT
    public:
    Aws::GameLift::Server::Model::StartMatchBackfillRequest toAWS() const {
        Aws::GameLift::Server::Model::StartMatchBackfillRequest awsStartMatchBackfillRequest;

        awsStartMatchBackfillRequest.SetTicketId(TCHAR_TO_UTF8(*this->ticketId));
        awsStartMatchBackfillRequest.SetMatchmakingConfigurationArn(TCHAR_TO_UTF8(*this->matchmakingConfigurationArn));
        awsStartMatchBackfillRequest.SetGameSessionArn(TCHAR_TO_UTF8(*this->gameSessionArn));

        for (const FAWSPlayerServer& player : this->players) {
            awsStartMatchBackfillRequest.AddPlayer(player.toAWS());
        }

        return awsStartMatchBackfillRequest;
    };

#endif
};