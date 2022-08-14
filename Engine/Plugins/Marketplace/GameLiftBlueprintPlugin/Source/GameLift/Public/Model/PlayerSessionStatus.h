/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "PlayerSessionStatus.generated.h"

UENUM(BlueprintType)
enum class EPlayerSessionStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    RESERVED        UMETA(DisplayName = "reserved"),
    ACTIVE        UMETA(DisplayName = "active"),
    COMPLETED        UMETA(DisplayName = "completed"),
    TIMEDOUT        UMETA(DisplayName = "timedout")
};
