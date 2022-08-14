/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "FleetStatus.generated.h"

UENUM(BlueprintType)
enum class EFleetStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    NEW_        UMETA(DisplayName = "new "),
    DOWNLOADING        UMETA(DisplayName = "downloading"),
    VALIDATING        UMETA(DisplayName = "validating"),
    BUILDING        UMETA(DisplayName = "building"),
    ACTIVATING        UMETA(DisplayName = "activating"),
    ACTIVE        UMETA(DisplayName = "active"),
    DELETING        UMETA(DisplayName = "deleting"),
    ERROR_        UMETA(DisplayName = "error "),
    TERMINATED        UMETA(DisplayName = "terminated")
};
