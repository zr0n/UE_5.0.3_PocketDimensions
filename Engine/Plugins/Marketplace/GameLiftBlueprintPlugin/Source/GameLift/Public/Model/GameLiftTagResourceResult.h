/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/TagResourceResult.h"

#endif

#include "GameLiftTagResourceResult.generated.h"

USTRUCT(BlueprintType)
struct FGameLiftTagResourceResult {
    GENERATED_BODY()

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FGameLiftTagResourceResult &fromAWS(const Aws::GameLift::Model::TagResourceResult &awsTagResourceResult) {
        return *this;
    }
#endif
};
