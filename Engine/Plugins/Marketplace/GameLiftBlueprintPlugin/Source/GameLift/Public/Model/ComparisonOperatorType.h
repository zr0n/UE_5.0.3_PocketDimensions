/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "ComparisonOperatorType.generated.h"

UENUM(BlueprintType)
enum class EComparisonOperatorType : uint8 {
    NOT_SET                             UMETA(DisplayName = "not set"),
    GreaterThanOrEqualToThreshold       UMETA(DisplayName = "greaterthanorequaltothreshold"),
    GreaterThanThreshold                UMETA(DisplayName = "greaterthanthreshold"),
    LessThanThreshold                   UMETA(DisplayName = "lessthanthreshold"),
    LessThanOrEqualToThreshold          UMETA(DisplayName = "lessthanorequaltothreshold")
};
