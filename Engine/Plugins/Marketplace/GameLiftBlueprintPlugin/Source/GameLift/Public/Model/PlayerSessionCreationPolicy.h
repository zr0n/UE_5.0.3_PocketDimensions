/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "PlayerSessionCreationPolicy.generated.h"

UENUM(BlueprintType)
enum class EPlayerSessionCreationPolicy : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ACCEPT_ALL        UMETA(DisplayName = "accept all"),
    DENY_ALL        UMETA(DisplayName = "deny all")
};
