/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeMatchmakingResult.h"

#endif

#include "Model/MatchmakingTicket.h"

#include "DescribeMatchmakingResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeMatchmakingResult {
GENERATED_BODY()

    /**
    *  <p>Collection of existing matchmaking ticket objects matching the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FMatchmakingTicket> ticketList;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDescribeMatchmakingResult &fromAWS(const Aws::GameLift::Model::DescribeMatchmakingResult &awsDescribeMatchmakingResult) {
        this->ticketList.Empty();
        for (const Aws::GameLift::Model::MatchmakingTicket& elem : awsDescribeMatchmakingResult.GetTicketList()) {
            this->ticketList.Add(FMatchmakingTicket().fromAWS(elem));
        }

        return *this;
    }
#endif
};
