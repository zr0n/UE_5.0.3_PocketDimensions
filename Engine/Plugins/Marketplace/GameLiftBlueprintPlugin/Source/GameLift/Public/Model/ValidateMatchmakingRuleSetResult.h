/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ValidateMatchmakingRuleSetResult.h"

#endif

#include "ValidateMatchmakingRuleSetResult.generated.h"

USTRUCT(BlueprintType)
struct FValidateMatchmakingRuleSetResult {
    GENERATED_BODY()

    /**
    *  <p>Response indicating whether the rule set is valid.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    bool valid = false;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FValidateMatchmakingRuleSetResult &fromAWS(const Aws::GameLift::Model::ValidateMatchmakingRuleSetResult &awsValidateMatchmakingRuleSetResult) {
        this->valid = awsValidateMatchmakingRuleSetResult.GetValid();

        return *this;
    }
#endif
};
