/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "GameServerInstanceStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSGameServerInstanceStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ACTIVE        UMETA(DisplayName = "active"),
    DRAINING        UMETA(DisplayName = "draining"),
    SPOT_TERMINATING        UMETA(DisplayName = "spot terminating"),
};
