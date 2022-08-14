/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSHttpTypes.generated.h"

UENUM(BlueprintType)
enum class EHttpMethod : uint8 {
    HTTP_GET          UMETA(DisplayName = "http get"),
    HTTP_POST             UMETA(DisplayName = "http post"),
    HTTP_DELETE         UMETA(DisplayName = "http delete"),
    HTTP_PUT         UMETA(DisplayName = "http put"),
    HTTP_HEAD         UMETA(DisplayName = "http head"),
    HTTP_PATCH         UMETA(DisplayName = "http patch")
};

UENUM(BlueprintType)
enum class ETransferLibType : uint8 {
    DEFAULT_CLIENT          UMETA(DisplayName = "default client"),
    CURL_CLIENT             UMETA(DisplayName = "curl client"),
    WIN_INET_CLIENT         UMETA(DisplayName = "win inet client"),
    WIN_HTTP_CLIENT         UMETA(DisplayName = "win http client")
};