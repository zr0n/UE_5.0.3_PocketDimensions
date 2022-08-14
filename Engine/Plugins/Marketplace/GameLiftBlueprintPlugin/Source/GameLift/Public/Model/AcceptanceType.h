/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "AcceptanceType.generated.h"

UENUM(BlueprintType)
enum class EAcceptanceType : uint8 {
    NOT_SET     UMETA(DisplayName = "not set"),
    ACCEPT      UMETA(DisplayName = "accept"),
    REJECT      UMETA(DisplayName = "reject")
};