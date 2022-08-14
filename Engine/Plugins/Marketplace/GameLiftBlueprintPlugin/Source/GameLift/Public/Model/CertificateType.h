/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "CertificateType.generated.h"

UENUM(BlueprintType)
enum class ECertificateType : uint8 {
    NOT_SET         UMETA(DisplayName = "not set"),
    DISABLED        UMETA(DisplayName = "disabled"),
    GENERATED       UMETA(DisplayName = "generated")
};
