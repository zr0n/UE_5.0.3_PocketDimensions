/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/StopMatchmakingRequest.h"

#endif

#include "StopMatchmakingRequest.generated.h"

USTRUCT(BlueprintType)
struct FStopMatchmakingRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a matchmaking ticket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString ticketId;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::StopMatchmakingRequest toAWS() const {
        Aws::GameLift::Model::StopMatchmakingRequest awsStopMatchmakingRequest;

        if (!(this->ticketId.IsEmpty())) {
            awsStopMatchmakingRequest.SetTicketId(TCHAR_TO_UTF8(*this->ticketId));
        }

        return awsStopMatchmakingRequest;
    }

    bool IsEmpty() const {
        return this->ticketId.IsEmpty();
    }
#endif
};
