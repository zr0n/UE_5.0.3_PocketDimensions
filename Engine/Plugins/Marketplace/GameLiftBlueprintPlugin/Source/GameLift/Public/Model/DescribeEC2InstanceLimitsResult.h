/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeEC2InstanceLimitsResult.h"

#endif

#include "Model/EC2InstanceLimit.h"

#include "DescribeEC2InstanceLimitsResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeEC2InstanceLimitsResult {
GENERATED_BODY()

    /**
    *  <p>Object that contains the maximum number of instances for the specified instance type.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FEC2InstanceLimit> EC2InstanceLimits;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDescribeEC2InstanceLimitsResult &fromAWS(const Aws::GameLift::Model::DescribeEC2InstanceLimitsResult &awsDescribeEC2InstanceLimitsResult) {
        this->EC2InstanceLimits.Empty();
        for (const Aws::GameLift::Model::EC2InstanceLimit& elem : awsDescribeEC2InstanceLimitsResult.GetEC2InstanceLimits()) {
            this->EC2InstanceLimits.Add(FEC2InstanceLimit().fromAWS(elem));
        }

        return *this;
    }
#endif
};
