/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "FleetAction.generated.h"

UENUM(BlueprintType)
enum class EFleetAction : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    AUTO_SCALING        UMETA(DisplayName = "auto scaling")
};
