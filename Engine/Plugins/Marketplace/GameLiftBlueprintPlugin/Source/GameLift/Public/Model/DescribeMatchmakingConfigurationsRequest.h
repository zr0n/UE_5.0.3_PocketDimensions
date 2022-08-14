/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeMatchmakingConfigurationsRequest.h"

#endif

#include "DescribeMatchmakingConfigurationsRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeMatchmakingConfigurationsRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a matchmaking configuration(s) to retrieve. To request all existing configurations, leave this parameter empty.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FString> names;

    /**
    *  <p>Unique identifier for a matchmaking rule set. Use this parameter to retrieve all matchmaking configurations that use this rule set.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString ruleSetName;

    /**
    *  <p>Maximum number of results to return. Use this parameter with <code>NextToken</code> to get results as a set of sequential pages. This parameter is limited to 10.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int limit = 0;

    /**
    *  <p>Token that indicates the start of the next sequential page of results. Use the token that is returned with a previous call to this action. To start at the beginning of the result set, do not specify a value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DescribeMatchmakingConfigurationsRequest toAWS() const {
        Aws::GameLift::Model::DescribeMatchmakingConfigurationsRequest awsDescribeMatchmakingConfigurationsRequest;

        for (const FString& elem : this->names) {
            awsDescribeMatchmakingConfigurationsRequest.AddNames(TCHAR_TO_UTF8(*elem));
        }

        if (!(this->ruleSetName.IsEmpty())) {
            awsDescribeMatchmakingConfigurationsRequest.SetRuleSetName(TCHAR_TO_UTF8(*this->ruleSetName));
        }

        if (this->limit != 0) {
            awsDescribeMatchmakingConfigurationsRequest.SetLimit(this->limit);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsDescribeMatchmakingConfigurationsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsDescribeMatchmakingConfigurationsRequest;
    }

    bool IsEmpty() const {
        return this->names.Num() == 0 && this->ruleSetName.IsEmpty() && this->limit == 0 && this->nextToken.IsEmpty();
    }
#endif
};
