/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, May 2019
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_CORE

#include "aws/core/auth/AWSAuthSigner.h"

#endif

#include "AWSAuthSigner.generated.h"

UENUM(BlueprintType)
enum class EAWSPayloadSigningPolicy : uint8 {
    /**
     * Sign the request based on the value returned by AmazonWebServiceRequest::SignBody()
     */
    RequestDependent     UMETA(DisplayName = "Request Dependent"),
    /**
     * Always sign the body of the request.
     */
    Always      UMETA(DisplayName = "Always"),
    /**
     * Never sign the body of the request
     */
    Never      UMETA(DisplayName = "Never")
};
