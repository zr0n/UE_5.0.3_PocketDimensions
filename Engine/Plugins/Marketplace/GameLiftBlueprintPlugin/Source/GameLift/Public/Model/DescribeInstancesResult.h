/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeInstancesResult.h"

#endif

#include "Model/Instance.h"

#include "DescribeInstancesResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeInstancesResult {
GENERATED_BODY()

    /**
    *  <p>Collection of objects containing properties for each instance returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FInstance> instances;

    /**
    *  <p>Token that indicates where to resume retrieving results on the next call to this action. If no token is returned, these results represent the end of the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDescribeInstancesResult &fromAWS(const Aws::GameLift::Model::DescribeInstancesResult &awsDescribeInstancesResult) {
        this->instances.Empty();
        for (const Aws::GameLift::Model::Instance& elem : awsDescribeInstancesResult.GetInstances()) {
            this->instances.Add(FInstance().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsDescribeInstancesResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
