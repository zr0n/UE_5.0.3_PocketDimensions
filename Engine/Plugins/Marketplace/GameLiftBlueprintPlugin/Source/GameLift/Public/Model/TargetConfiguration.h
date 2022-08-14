/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/TargetConfiguration.h"

#endif

#include "TargetConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FTargetConfiguration {
    GENERATED_BODY()

    /**
    *  <p>Desired value to use with a target-based scaling policy. The value must be relevant for whatever metric the scaling policy is using. For example, in a policy using the metric PercentAvailableGameSessions, the target value should be the preferred size of the fleet's buffer (the percent of capacity that should be idle and ready for new game sessions).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    float targetValue = 0.0f;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::TargetConfiguration toAWS() const {
        Aws::GameLift::Model::TargetConfiguration awsTargetConfiguration;

        if (this->targetValue != 0) {
            awsTargetConfiguration.SetTargetValue(this->targetValue);
        }

        return awsTargetConfiguration;
    }

    bool IsEmpty() const {
        return this->targetValue == 0;
    }

    FTargetConfiguration &fromAWS(const Aws::GameLift::Model::TargetConfiguration &awsTargetConfiguration) {
        this->targetValue = (float)awsTargetConfiguration.GetTargetValue();

        return *this;
    }
#endif
};
