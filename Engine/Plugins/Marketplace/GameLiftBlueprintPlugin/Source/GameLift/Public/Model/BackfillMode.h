/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "BackfillMode.generated.h"

UENUM(BlueprintType)
enum class EBackfillMode : uint8 {
    NOT_SET     UMETA(DisplayName = "not set"),
    AUTOMATIC   UMETA(DisplayName = "automatic"),
    MANUAL      UMETA(DisplayName = "manual")
};
