/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "GameServerProtectionPolicy.generated.h"

UENUM(BlueprintType)
enum class EAWSGameServerProtectionPolicy : uint8 {
    NOT_SET                 UMETA(DisplayName = "not set"),
    NO_PROTECTION           UMETA(DisplayName = "no protection"),
    FULL_PROTECTION         UMETA(DisplayName = "full protection")
};
