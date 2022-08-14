/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeFleetLocationCapacityResult.h"

#endif

#include "Model/FleetCapacity.h"

#include "AWSGameLiftDescribeFleetLocationCapacityResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftDescribeFleetLocationCapacityResult {
GENERATED_BODY()

    /**
    *  <p>Resource capacity information for the requested fleet location. Capacity objects are returned only for fleets and locations that currently exist.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FFleetCapacity fleetCapacity;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FAWSGameLiftDescribeFleetLocationCapacityResult &fromAWS(const Aws::GameLift::Model::DescribeFleetLocationCapacityResult &awsDescribeFleetLocationCapacityResult) {
        this->fleetCapacity = FFleetCapacity().fromAWS(awsDescribeFleetLocationCapacityResult.GetFleetCapacity());

        return *this;
    }
#endif
};
