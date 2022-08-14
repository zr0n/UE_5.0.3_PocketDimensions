/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "GameServerGroupStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSGameServerGroupStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    NEW_        UMETA(DisplayName = "new "),
    ACTIVATING        UMETA(DisplayName = "activating"),
    ACTIVE        UMETA(DisplayName = "active"),
    DELETE_SCHEDULED        UMETA(DisplayName = "delete scheduled"),
    DELETING        UMETA(DisplayName = "deleting"),
    DELETED        UMETA(DisplayName = "deleted"),
    ERROR_        UMETA(DisplayName = "error ")
};
