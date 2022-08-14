/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "ProtectionPolicy.generated.h"

UENUM(BlueprintType)
enum class EProtectionPolicy : uint8 {
    NOT_SET         UMETA(DisplayName = "not set"),
    NoProtection    UMETA(DisplayName = "noprotection"),
    FullProtection  UMETA(DisplayName = "fullprotection")
};
