/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeFleetUtilizationResult.h"

#endif

#include "Model/FleetUtilization.h"

#include "DescribeFleetUtilizationResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeFleetUtilizationResult {
GENERATED_BODY()

    /**
    *  <p>Collection of objects containing utilization information for each requested fleet ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FFleetUtilization> fleetUtilization;

    /**
    *  <p>Token that indicates where to resume retrieving results on the next call to this action. If no token is returned, these results represent the end of the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDescribeFleetUtilizationResult &fromAWS(const Aws::GameLift::Model::DescribeFleetUtilizationResult &awsDescribeFleetUtilizationResult) {
        this->fleetUtilization.Empty();
        for (const Aws::GameLift::Model::FleetUtilization& elem : awsDescribeFleetUtilizationResult.GetFleetUtilization()) {
            this->fleetUtilization.Add(FFleetUtilization().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsDescribeFleetUtilizationResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
