/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "SortOrder.generated.h"

UENUM(BlueprintType)
enum class EAWSSortOrder : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ASCENDING        UMETA(DisplayName = "ascending"),
    DESCENDING        UMETA(DisplayName = "descending")
};
