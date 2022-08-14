/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "RoutingStrategyType.generated.h"

UENUM(BlueprintType)
enum class ERoutingStrategyType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    SIMPLE        UMETA(DisplayName = "simple"),
    TERMINAL        UMETA(DisplayName = "terminal")
};
