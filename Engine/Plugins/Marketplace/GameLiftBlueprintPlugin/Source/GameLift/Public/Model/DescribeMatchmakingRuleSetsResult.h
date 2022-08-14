/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeMatchmakingRuleSetsResult.h"

#endif

#include "Model/MatchmakingRuleSet.h"

#include "DescribeMatchmakingRuleSetsResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeMatchmakingRuleSetsResult {
GENERATED_BODY()

    /**
    *  <p>Collection of requested matchmaking rule set objects. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FMatchmakingRuleSet> ruleSets;

    /**
    *  <p>Token that indicates where to resume retrieving results on the next call to this action. If no token is returned, these results represent the end of the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDescribeMatchmakingRuleSetsResult &fromAWS(const Aws::GameLift::Model::DescribeMatchmakingRuleSetsResult &awsDescribeMatchmakingRuleSetsResult) {
        this->ruleSets.Empty();
        for (const Aws::GameLift::Model::MatchmakingRuleSet& elem : awsDescribeMatchmakingRuleSetsResult.GetRuleSets()) {
            this->ruleSets.Add(FMatchmakingRuleSet().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsDescribeMatchmakingRuleSetsResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
