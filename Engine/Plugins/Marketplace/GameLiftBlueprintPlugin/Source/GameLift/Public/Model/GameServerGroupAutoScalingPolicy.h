/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/GameServerGroupAutoScalingPolicy.h"

#endif

#include "Model/TargetTrackingConfiguration.h"

#include "GameServerGroupAutoScalingPolicy.generated.h"

USTRUCT(BlueprintType)
struct FGameServerGroupAutoScalingPolicy {
    GENERATED_BODY()

    /**
    *  <p>Length of time, in seconds, it takes for a new instance to start new game server processes and register with GameLift FleetIQ. Specifying a warm-up time can be useful, particularly with game servers that take a long time to start up, because it avoids prematurely starting new instances </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int estimatedInstanceWarmup = 0;

    /**
    *  <p>Settings for a target-based scaling policy applied to Auto Scaling group. These settings are used to create a target-based policy that tracks the GameLift FleetIQ metric "PercentUtilizedGameServers" and specifies a target value for the metric. As player usage changes, the policy triggers to adjust the game server group capacity so that the metric returns to the target value. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FTargetTrackingConfiguration targetTrackingConfiguration;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::GameServerGroupAutoScalingPolicy toAWS() const {
        Aws::GameLift::Model::GameServerGroupAutoScalingPolicy awsGameServerGroupAutoScalingPolicy;

        if (!(this->estimatedInstanceWarmup == 0)) {
            awsGameServerGroupAutoScalingPolicy.SetEstimatedInstanceWarmup(this->estimatedInstanceWarmup);
        }

        if (!(this->targetTrackingConfiguration.IsEmpty())) {
            awsGameServerGroupAutoScalingPolicy.SetTargetTrackingConfiguration(this->targetTrackingConfiguration.toAWS());
        }

        return awsGameServerGroupAutoScalingPolicy;
    }

    bool IsEmpty() const {
        return this->estimatedInstanceWarmup == 0 && this->targetTrackingConfiguration.IsEmpty();
    }
#endif
};
