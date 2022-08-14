/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/PlayerLatency.h"

#endif

#include "PlayerLatency.generated.h"

USTRUCT(BlueprintType)
struct FPlayerLatency {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a player associated with the latency data.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString playerId;

    /**
    *  <p>Name of the region that is associated with the latency value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString regionIdentifier;

    /**
    *  <p>Amount of time that represents the time lag experienced by the player when connected to the specified region.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    float latencyInMilliseconds = 0.0f;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::PlayerLatency toAWS() const {
        Aws::GameLift::Model::PlayerLatency awsPlayerLatency;

        if (!(this->playerId.IsEmpty())) {
            awsPlayerLatency.SetPlayerId(TCHAR_TO_UTF8(*this->playerId));
        }

        if (!(this->regionIdentifier.IsEmpty())) {
            awsPlayerLatency.SetRegionIdentifier(TCHAR_TO_UTF8(*this->regionIdentifier));
        }

        if (this->latencyInMilliseconds != 0) {
            awsPlayerLatency.SetLatencyInMilliseconds(this->latencyInMilliseconds);
        }

        return awsPlayerLatency;
    }

    bool IsEmpty() const {
        return this->playerId.IsEmpty() && this->regionIdentifier.IsEmpty() && this->latencyInMilliseconds == 0;
    }

    FPlayerLatency &fromAWS(const Aws::GameLift::Model::PlayerLatency &awsPlayerLatency) {
        this->playerId = UTF8_TO_TCHAR(awsPlayerLatency.GetPlayerId().c_str());

        this->regionIdentifier = UTF8_TO_TCHAR(awsPlayerLatency.GetRegionIdentifier().c_str());

        this->latencyInMilliseconds = (float)awsPlayerLatency.GetLatencyInMilliseconds();

        return *this;
    }
#endif
};
