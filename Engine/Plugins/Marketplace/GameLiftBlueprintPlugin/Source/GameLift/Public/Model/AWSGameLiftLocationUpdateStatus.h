/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSGameLiftLocationUpdateStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSGameLiftLocationUpdateStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    PENDING_UPDATE        UMETA(DisplayName = "pending update"),
};
