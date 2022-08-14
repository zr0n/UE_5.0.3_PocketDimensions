/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DeleteMatchmakingRuleSetResult.h"

#endif

#include "DeleteMatchmakingRuleSetResult.generated.h"

USTRUCT(BlueprintType)
struct FDeleteMatchmakingRuleSetResult {
GENERATED_BODY()

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDeleteMatchmakingRuleSetResult &fromAWS(const Aws::GameLift::Model::DeleteMatchmakingRuleSetResult &awsDeleteMatchmakingRuleSetResult) {

        return *this;
    }
#endif
};
