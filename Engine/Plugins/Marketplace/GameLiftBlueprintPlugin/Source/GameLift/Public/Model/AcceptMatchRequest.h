/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/AcceptMatchRequest.h"

#endif

#include "Model/AcceptanceType.h"

#include "AcceptMatchRequest.generated.h"

USTRUCT(BlueprintType)
struct FAcceptMatchRequest {
    GENERATED_BODY()

    /**
    *  <p>Unique identifier for a matchmaking ticket. The ticket must be in status <code>REQUIRES_ACCEPTANCE</code>; otherwise this request will fail.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString ticketId;

    /**
    *  <p>Unique identifier for a player delivering the response. This parameter can include one or multiple player IDs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FString> playerIds;

    /**
    *  <p>Player response to the proposed match.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EAcceptanceType acceptanceType = EAcceptanceType::NOT_SET;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::AcceptMatchRequest toAWS() const {
        Aws::GameLift::Model::AcceptMatchRequest awsAcceptMatchRequest;

        if (!(this->ticketId.IsEmpty())) {
            awsAcceptMatchRequest.SetTicketId(TCHAR_TO_UTF8(*this->ticketId));
        }

        for (const FString& elem : this->playerIds) {
            awsAcceptMatchRequest.AddPlayerIds(TCHAR_TO_UTF8(*elem));
        }

        switch(this->acceptanceType) {
            case EAcceptanceType::ACCEPT:
                awsAcceptMatchRequest.SetAcceptanceType(Aws::GameLift::Model::AcceptanceType::ACCEPT);
                break;
            case EAcceptanceType::REJECT:
                awsAcceptMatchRequest.SetAcceptanceType(Aws::GameLift::Model::AcceptanceType::REJECT);
                break;
            default:
                break;
        }

        return awsAcceptMatchRequest;
    }

    bool IsEmpty() const {
        return this->ticketId.IsEmpty() && this->playerIds.Num() == 0 && this->acceptanceType == EAcceptanceType::NOT_SET;
    }
#endif
};
