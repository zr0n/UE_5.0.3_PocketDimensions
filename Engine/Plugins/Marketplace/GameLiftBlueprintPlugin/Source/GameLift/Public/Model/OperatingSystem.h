/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "OperatingSystem.generated.h"

UENUM(BlueprintType)
enum class EOperatingSystem : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    WINDOWS_2012        UMETA(DisplayName = "windows 2012"),
    AMAZON_LINUX        UMETA(DisplayName = "amazon linux"),
    AMAZON_LINUX_2        UMETA(DisplayName = "amazon linux 2")
};
