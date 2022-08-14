/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/PlayerLatencyPolicy.h"

#endif

#include "PlayerLatencyPolicy.generated.h"

USTRUCT(BlueprintType)
struct FPlayerLatencyPolicy {
GENERATED_BODY()

    /**
    *  <p>The maximum latency value that is allowed for any player, in milliseconds. All policies must have a value set for this property.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int maximumIndividualPlayerLatencyMilliseconds = 0;

    /**
    *  <p>The length of time, in seconds, that the policy is enforced while placing a new game session. A null value for this property means that the policy is enforced until the queue times out.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int policyDurationSeconds = 0;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::PlayerLatencyPolicy toAWS() const {
        Aws::GameLift::Model::PlayerLatencyPolicy awsPlayerLatencyPolicy;

        if (this->maximumIndividualPlayerLatencyMilliseconds != 0) {
            awsPlayerLatencyPolicy.SetMaximumIndividualPlayerLatencyMilliseconds(this->maximumIndividualPlayerLatencyMilliseconds);
        }

        if (this->policyDurationSeconds != 0) {
            awsPlayerLatencyPolicy.SetPolicyDurationSeconds(this->policyDurationSeconds);
        }

        return awsPlayerLatencyPolicy;
    }

    bool IsEmpty() const {
        return this->maximumIndividualPlayerLatencyMilliseconds == 0 && this->policyDurationSeconds == 0;
    }

    FPlayerLatencyPolicy &fromAWS(const Aws::GameLift::Model::PlayerLatencyPolicy &awsPlayerLatencyPolicy) {
        this->maximumIndividualPlayerLatencyMilliseconds = awsPlayerLatencyPolicy.GetMaximumIndividualPlayerLatencyMilliseconds();

        this->policyDurationSeconds = awsPlayerLatencyPolicy.GetPolicyDurationSeconds();

        return *this;
    }
#endif
};
