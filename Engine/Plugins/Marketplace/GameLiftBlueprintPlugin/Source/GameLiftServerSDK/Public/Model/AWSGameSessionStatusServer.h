/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFT

#include "aws/gamelift/server/model/GameSessionStatus.h"

#endif

#include "AWSGameSessionStatusServer.generated.h"

UENUM(BlueprintType)
enum class EGameSessionStatusServer : uint8 {
    NOT_SET     UMETA(DisplayName = "not set"),
    ACTIVE      UMETA(DisplayName = "active"),
    ACTIVATING  UMETA(DisplayName = "activating"),
    TERMINATED  UMETA(DisplayName = "terminated"),
    TERMINATING UMETA(DisplayName = "terminating")
};