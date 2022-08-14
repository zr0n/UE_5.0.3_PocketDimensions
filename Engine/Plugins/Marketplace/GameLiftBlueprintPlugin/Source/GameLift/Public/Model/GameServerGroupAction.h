/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "GameServerGroupAction.generated.h"

UENUM(BlueprintType)
enum class EAWSGameServerGroupAction : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    REPLACE_INSTANCE_TYPES        UMETA(DisplayName = "replace instance types")
};
