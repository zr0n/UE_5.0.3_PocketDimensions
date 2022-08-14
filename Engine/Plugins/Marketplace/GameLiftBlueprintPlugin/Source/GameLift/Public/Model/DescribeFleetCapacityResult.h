/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeFleetCapacityResult.h"

#endif

#include "Model/FleetCapacity.h"

#include "DescribeFleetCapacityResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeFleetCapacityResult {
GENERATED_BODY()

    /**
    *  <p>Collection of objects containing capacity information for each requested fleet ID. Leave this parameter empty to retrieve capacity information for all fleets.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FFleetCapacity> fleetCapacity;

    /**
    *  <p>Token that indicates where to resume retrieving results on the next call to this action. If no token is returned, these results represent the end of the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDescribeFleetCapacityResult &fromAWS(const Aws::GameLift::Model::DescribeFleetCapacityResult &awsDescribeFleetCapacityResult) {
        this->fleetCapacity.Empty();
        for (const Aws::GameLift::Model::FleetCapacity& elem : awsDescribeFleetCapacityResult.GetFleetCapacity()) {
            this->fleetCapacity.Add(FFleetCapacity().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsDescribeFleetCapacityResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
