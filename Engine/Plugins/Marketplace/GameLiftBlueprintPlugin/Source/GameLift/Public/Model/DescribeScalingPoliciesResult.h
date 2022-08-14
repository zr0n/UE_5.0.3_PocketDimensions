/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeScalingPoliciesResult.h"

#endif

#include "Model/ScalingPolicy.h"

#include "DescribeScalingPoliciesResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeScalingPoliciesResult {
GENERATED_BODY()

    /**
    *  <p>Collection of objects containing the scaling policies matching the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FScalingPolicy> scalingPolicies;

    /**
    *  <p>Token that indicates where to resume retrieving results on the next call to this action. If no token is returned, these results represent the end of the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDescribeScalingPoliciesResult &fromAWS(const Aws::GameLift::Model::DescribeScalingPoliciesResult &awsDescribeScalingPoliciesResult) {
        this->scalingPolicies.Empty();
        for (const Aws::GameLift::Model::ScalingPolicy& elem : awsDescribeScalingPoliciesResult.GetScalingPolicies()) {
            this->scalingPolicies.Add(FScalingPolicy().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsDescribeScalingPoliciesResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
