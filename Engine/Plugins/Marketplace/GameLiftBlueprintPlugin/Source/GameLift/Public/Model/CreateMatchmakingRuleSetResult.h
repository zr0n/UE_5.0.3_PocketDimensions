/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreateMatchmakingRuleSetResult.h"

#endif

#include "Model/MatchmakingRuleSet.h"

#include "CreateMatchmakingRuleSetResult.generated.h"

USTRUCT(BlueprintType)
struct FCreateMatchmakingRuleSetResult {
GENERATED_BODY()

    /**
    *  <p>Object that describes the newly created matchmaking rule set.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FMatchmakingRuleSet ruleSet;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FCreateMatchmakingRuleSetResult &fromAWS(const Aws::GameLift::Model::CreateMatchmakingRuleSetResult &awsCreateMatchmakingRuleSetResult) {
        this->ruleSet.fromAWS(awsCreateMatchmakingRuleSetResult.GetRuleSet());

        return *this;
    }
#endif
};
