/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "MatchmakingConfigurationStatus.generated.h"

UENUM(BlueprintType)
enum class EMatchmakingConfigurationStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    CANCELLED        UMETA(DisplayName = "cancelled"),
    COMPLETED        UMETA(DisplayName = "completed"),
    FAILED        UMETA(DisplayName = "failed"),
    PLACING        UMETA(DisplayName = "placing"),
    QUEUED        UMETA(DisplayName = "queued"),
    REQUIRES_ACCEPTANCE        UMETA(DisplayName = "requires acceptance"),
    SEARCHING        UMETA(DisplayName = "searching"),
    TIMED_OUT        UMETA(DisplayName = "timed out")
};
