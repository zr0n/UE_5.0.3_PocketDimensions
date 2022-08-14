/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DeleteMatchmakingConfigurationResult.h"

#endif

#include "DeleteMatchmakingConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FDeleteMatchmakingConfigurationResult {
GENERATED_BODY()

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDeleteMatchmakingConfigurationResult &fromAWS(const Aws::GameLift::Model::DeleteMatchmakingConfigurationResult &awsDeleteMatchmakingConfigurationResult) {

        return *this;
    }
#endif
};
