/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "ScalingAdjustmentType.generated.h"

UENUM(BlueprintType)
enum class EScalingAdjustmentType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ChangeInCapacity        UMETA(DisplayName = "changeincapacity"),
    ExactCapacity        UMETA(DisplayName = "exactcapacity"),
    PercentChangeInCapacity        UMETA(DisplayName = "percentchangeincapacity")
};
