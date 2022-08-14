/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "GameSessionStatus.generated.h"

UENUM(BlueprintType)
enum class EGameSessionStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ACTIVE        UMETA(DisplayName = "active"),
    ACTIVATING        UMETA(DisplayName = "activating"),
    TERMINATED        UMETA(DisplayName = "terminated"),
    TERMINATING        UMETA(DisplayName = "terminating"),
    ERROR_        UMETA(DisplayName = "error ")
};
