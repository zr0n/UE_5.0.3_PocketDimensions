/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "ScalingStatusType.generated.h"

UENUM(BlueprintType)
enum class EScalingStatusType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ACTIVE        UMETA(DisplayName = "active"),
    UPDATE_REQUESTED        UMETA(DisplayName = "update requested"),
    UPDATING        UMETA(DisplayName = "updating"),
    DELETE_REQUESTED        UMETA(DisplayName = "delete requested"),
    DELETING        UMETA(DisplayName = "deleting"),
    DELETED        UMETA(DisplayName = "deleted"),
    ERROR_        UMETA(DisplayName = "error ")
};
