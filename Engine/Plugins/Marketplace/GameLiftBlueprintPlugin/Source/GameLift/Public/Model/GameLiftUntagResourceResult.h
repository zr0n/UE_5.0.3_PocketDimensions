/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/UntagResourceResult.h"

#endif

#include "GameLiftUntagResourceResult.generated.h"

USTRUCT(BlueprintType)
struct FUntagResourceResult {
    GENERATED_BODY()

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:

    FUntagResourceResult &fromAWS(const Aws::GameLift::Model::UntagResourceResult &awsUntagResourceResult) {
        return *this;
    }
#endif
};
