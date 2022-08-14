/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/StopMatchmakingResult.h"

#endif

#include "StopMatchmakingResult.generated.h"

USTRUCT(BlueprintType)
struct FStopMatchmakingResult {
GENERATED_BODY()

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FStopMatchmakingResult &fromAWS(const Aws::GameLift::Model::StopMatchmakingResult &awsStopMatchmakingResult) {

        return *this;
    }
#endif
};
