/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "IpProtocol.generated.h"

UENUM(BlueprintType)
enum class EIpProtocol : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    TCP        UMETA(DisplayName = "tcp"),
    UDP        UMETA(DisplayName = "udp")
};
