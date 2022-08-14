/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "GameServerHealthCheck.generated.h"

UENUM(BlueprintType)
enum class EAWSGameServerHealthCheck : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    HEALTHY        UMETA(DisplayName = "healthy")
};
