/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "GameSessionStatusReason.generated.h"

UENUM(BlueprintType)
enum class EGameSessionStatusReason : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    INTERRUPTED        UMETA(DisplayName = "interrupted")
};
