/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "InstanceStatus.generated.h"

UENUM(BlueprintType)
enum class EInstanceStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    PENDING        UMETA(DisplayName = "pending"),
    ACTIVE        UMETA(DisplayName = "active"),
    TERMINATING        UMETA(DisplayName = "terminating")
};
