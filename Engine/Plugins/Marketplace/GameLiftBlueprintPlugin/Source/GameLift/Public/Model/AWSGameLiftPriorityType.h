/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSGameLiftPriorityType.generated.h"

UENUM(BlueprintType)
enum class EAWSGameLiftPriorityType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    LATENCY        UMETA(DisplayName = "latency"),
    COST        UMETA(DisplayName = "cost"),
    DESTINATION        UMETA(DisplayName = "destination"),
    LOCATION        UMETA(DisplayName = "location"),
};
