/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSGameLiftFlexMatchMode.generated.h"

UENUM(BlueprintType)
enum class EAWSGameLiftFlexMatchMode : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    STANDALONE        UMETA(DisplayName = "standalone"),
    WITH_QUEUE        UMETA(DisplayName = "with queue"),
};
