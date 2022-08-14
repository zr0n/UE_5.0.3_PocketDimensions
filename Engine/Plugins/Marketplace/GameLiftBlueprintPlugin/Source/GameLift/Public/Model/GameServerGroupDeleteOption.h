/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "GameServerGroupDeleteOption.generated.h"

UENUM(BlueprintType)
enum class EAWSGameServerGroupDeleteOption : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    SAFE_DELETE        UMETA(DisplayName = "safe delete"),
    FORCE_DELETE        UMETA(DisplayName = "force delete"),
    RETAIN        UMETA(DisplayName = "retain")
};
