/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "FleetType.generated.h"

UENUM(BlueprintType)
enum class EFleetType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ON_DEMAND        UMETA(DisplayName = "on demand"),
    SPOT        UMETA(DisplayName = "spot")
};
