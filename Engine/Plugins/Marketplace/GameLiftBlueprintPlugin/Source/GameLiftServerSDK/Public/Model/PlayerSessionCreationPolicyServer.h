/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#include "PlayerSessionCreationPolicyServer.generated.h"

UENUM(BlueprintType)
enum class EPlayerSessionCreationPolicyServer : uint8 {
    NOT_SET     UMETA(DisplayName = "not set"),
    ACCEPT_ALL  UMETA(DisplayName = "accept all"),
    DENY_ALL    UMETA(DisplayName = "deny all")
};