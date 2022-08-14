/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "GameSessionPlacementState.generated.h"

UENUM(BlueprintType)
enum class EGameSessionPlacementState : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    PENDING        UMETA(DisplayName = "pending"),
    FULFILLED        UMETA(DisplayName = "fulfilled"),
    CANCELLED        UMETA(DisplayName = "cancelled"),
    TIMED_OUT        UMETA(DisplayName = "timed out"),
    FAILED        UMETA(DisplayName = "failed")
};
