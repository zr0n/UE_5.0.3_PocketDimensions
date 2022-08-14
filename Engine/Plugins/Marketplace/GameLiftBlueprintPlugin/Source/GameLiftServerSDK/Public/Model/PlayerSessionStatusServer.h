/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFT

#include "aws/gamelift/server/model/PlayerSessionStatus.h"

#endif

#include "PlayerSessionStatusServer.generated.h"

UENUM(BlueprintType)
enum class EPlayerSessionStatusServer : uint8 {
    NOT_SET     UMETA(DisplayName = "not set"),
    RESERVED    UMETA(DisplayName = "reserved"),
    ACTIVE      UMETA(DisplayName = "active"),
    COMPLETED   UMETA(DisplayName = "completed"),
    TIMEDOUT    UMETA(DisplayName = "timeout")
};