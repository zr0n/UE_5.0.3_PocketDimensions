/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/AcceptMatchResult.h"

#endif

#include "AcceptMatchResult.generated.h"

USTRUCT(BlueprintType)
struct FAcceptMatchResult {
    GENERATED_BODY()

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FAcceptMatchResult &fromAWS(const Aws::GameLift::Model::AcceptMatchResult &awsAcceptMatchResult) {

        return *this;
    }
#endif
};
