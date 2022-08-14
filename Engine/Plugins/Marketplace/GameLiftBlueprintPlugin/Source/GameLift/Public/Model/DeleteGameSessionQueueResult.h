/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DeleteGameSessionQueueResult.h"

#endif

#include "DeleteGameSessionQueueResult.generated.h"

USTRUCT(BlueprintType)
struct FDeleteGameSessionQueueResult {
GENERATED_BODY()

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDeleteGameSessionQueueResult &fromAWS(const Aws::GameLift::Model::DeleteGameSessionQueueResult &awsDeleteGameSessionQueueResult) {

        return *this;
    }
#endif
};
