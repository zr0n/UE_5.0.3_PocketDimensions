/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeRuntimeConfigurationResult.h"

#endif

#include "Model/RuntimeConfiguration.h"

#include "DescribeRuntimeConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeRuntimeConfigurationResult {
GENERATED_BODY()

    /**
    *  <p>Instructions describing how server processes should be launched and maintained on each instance in the fleet.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FRuntimeConfiguration runtimeConfiguration;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDescribeRuntimeConfigurationResult &fromAWS(const Aws::GameLift::Model::DescribeRuntimeConfigurationResult &awsDescribeRuntimeConfigurationResult) {
        this->runtimeConfiguration.fromAWS(awsDescribeRuntimeConfigurationResult.GetRuntimeConfiguration());

        return *this;
    }
#endif
};
