/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeFleetLocationUtilizationResult.h"

#endif

#include "Model/FleetUtilization.h"

#include "AWSGameLiftDescribeFleetLocationUtilizationResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftDescribeFleetLocationUtilizationResult {
GENERATED_BODY()

    /**
    *  <p>Utilization information for the requested fleet location. Utilization objects are returned only for fleets and locations that currently exist.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FFleetUtilization fleetUtilization;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FAWSGameLiftDescribeFleetLocationUtilizationResult &fromAWS(const Aws::GameLift::Model::DescribeFleetLocationUtilizationResult &awsDescribeFleetLocationUtilizationResult) {
        this->fleetUtilization = FFleetUtilization().fromAWS(awsDescribeFleetLocationUtilizationResult.GetFleetUtilization());

        return *this;
    }
#endif
};
