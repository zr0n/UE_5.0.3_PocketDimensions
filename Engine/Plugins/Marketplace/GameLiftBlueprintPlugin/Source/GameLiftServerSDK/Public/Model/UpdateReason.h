/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFT

#include "aws/gamelift/server/model/UpdateReason.h"

#endif

#include "UpdateReason.generated.h"

UENUM(BlueprintType)
enum class EUpdateReason : uint8 {
    MATCHMAKING_DATA_UPDATED    UMETA(DisplayName = "matchmaking data updated"),
    BACKFILL_FAILED             UMETA(DisplayName = "backfill failed"),
    BACKFILL_TIMED_OUT          UMETA(DisplayName = "backfill time out"),
    BACKFILL_CANCELLED          UMETA(DisplayName = "backfill cancelled"),
    UNKNOWN                     UMETA(DisplayName = "unknown")
};