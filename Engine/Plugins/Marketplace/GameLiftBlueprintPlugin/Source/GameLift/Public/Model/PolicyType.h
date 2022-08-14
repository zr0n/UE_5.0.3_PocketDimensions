/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "PolicyType.generated.h"

UENUM(BlueprintType)
enum class EPolicyType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    RuleBased        UMETA(DisplayName = "rulebased"),
    TargetBased        UMETA(DisplayName = "targetbased")
};
