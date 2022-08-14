/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeFleetCapacityRequest.h"

#endif

#include "DescribeFleetCapacityRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeFleetCapacityRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a fleet(s) to retrieve capacity information for. To request capacity information for all fleets, leave this parameter empty.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FString> fleetIds;

    /**
    *  <p>Maximum number of results to return. Use this parameter with <code>NextToken</code> to get results as a set of sequential pages. This parameter is ignored when the request specifies one or a list of fleet IDs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int limit = 0;

    /**
    *  <p>Token that indicates the start of the next sequential page of results. Use the token that is returned with a previous call to this action. To start at the beginning of the result set, do not specify a value. This parameter is ignored when the request specifies one or a list of fleet IDs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DescribeFleetCapacityRequest toAWS() const {
        Aws::GameLift::Model::DescribeFleetCapacityRequest awsDescribeFleetCapacityRequest;

        for (const FString& elem : this->fleetIds) {
            awsDescribeFleetCapacityRequest.AddFleetIds(TCHAR_TO_UTF8(*elem));
        }

        if (this->limit != 0) {
            awsDescribeFleetCapacityRequest.SetLimit(this->limit);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsDescribeFleetCapacityRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsDescribeFleetCapacityRequest;
    }

    bool IsEmpty() const {
        return this->fleetIds.Num() == 0 && this->limit == 0 && this->nextToken.IsEmpty();
    }
#endif
};
