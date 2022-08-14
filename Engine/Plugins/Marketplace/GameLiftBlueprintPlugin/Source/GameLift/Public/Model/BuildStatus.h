/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "BuildStatus.generated.h"

UENUM(BlueprintType)
enum class EBuildStatus : uint8 {
    NOT_SET         UMETA(DisplayName = "not set"),
    INITIALIZED     UMETA(DisplayName = "initialized"),
    READY           UMETA(DisplayName = "ready"),
    FAILED          UMETA(DisplayName = "failed")
};
