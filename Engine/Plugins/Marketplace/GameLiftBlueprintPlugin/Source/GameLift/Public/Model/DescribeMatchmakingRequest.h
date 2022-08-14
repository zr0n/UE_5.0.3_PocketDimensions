/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeMatchmakingRequest.h"

#endif

#include "DescribeMatchmakingRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeMatchmakingRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a matchmaking ticket. You can include up to 10 ID values. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FString> ticketIds;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DescribeMatchmakingRequest toAWS() const {
        Aws::GameLift::Model::DescribeMatchmakingRequest awsDescribeMatchmakingRequest;

        for (const FString& elem : this->ticketIds) {
            awsDescribeMatchmakingRequest.AddTicketIds(TCHAR_TO_UTF8(*elem));
        }

        return awsDescribeMatchmakingRequest;
    }

    bool IsEmpty() const {
        return this->ticketIds.Num() == 0;
    }
#endif
};
