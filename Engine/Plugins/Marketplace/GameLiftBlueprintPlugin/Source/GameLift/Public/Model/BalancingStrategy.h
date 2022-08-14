/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "BalancingStrategy.generated.h"

UENUM(BlueprintType)
enum class EAWSBalancingStrategy : uint8 {
    NOT_SET                 UMETA(DisplayName = "not set"),
    SPOT_ONLY               UMETA(DisplayName = "spot only"),
    SPOT_PREFERRED          UMETA(DisplayName = "spot preferred"),
    ON_DEMAND_ONLY          UMETA(DisplayName = "on demand only"),
};
