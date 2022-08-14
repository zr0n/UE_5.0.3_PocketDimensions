/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/TargetTrackingConfiguration.h"

#endif

#include "TargetTrackingConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FTargetTrackingConfiguration {
    GENERATED_BODY()

    /**
    *  <p>Desired value to use with a game server group target-based scaling policy. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    float targetValue = 0.0f;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::TargetTrackingConfiguration toAWS() const {
        Aws::GameLift::Model::TargetTrackingConfiguration awsTargetTrackingConfiguration;

        if (!(this->targetValue == 0)) {
            awsTargetTrackingConfiguration.SetTargetValue(this->targetValue);
        }

        return awsTargetTrackingConfiguration;
    }

    bool IsEmpty() const {
        return this->targetValue == 0;
    }
#endif
};
