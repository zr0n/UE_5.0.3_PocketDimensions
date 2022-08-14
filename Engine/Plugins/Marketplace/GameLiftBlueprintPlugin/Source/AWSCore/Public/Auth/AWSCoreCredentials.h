/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, May 2019
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_CORE

#include "aws/core/auth/AWSCredentials.h"
#include "aws/core/auth/AWSCredentialsProvider.h"
#include "aws/core/utils/memory/stl/AWSAllocator.h"

#endif

#include "AWSCoreCredentials.generated.h"

USTRUCT(BlueprintType)
struct FAWSCredentials {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AWS Core")
    FString accessKeyId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AWS Core")
    FString secretKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AWS Core")
    FString sessionToken;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AWS Core")
    FDateTime expiration;

#if WITH_CORE
    public:
    Aws::Auth::AWSCredentials toAWS() const {
        return Aws::Auth::AWSCredentials(
                TCHAR_TO_UTF8(*this->accessKeyId),
                TCHAR_TO_UTF8(*this->secretKey),
                TCHAR_TO_UTF8(*this->sessionToken),
                Aws::Utils::DateTime((int64_t)((expiration - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond))
            );
        /*return std::allocate_shared<Aws::Auth::SimpleAWSCredentialsProvider, Aws::Allocator<Aws::Auth::SimpleAWSCredentialsProvider>>(
                Aws::Allocator<Aws::Auth::SimpleAWSCredentialsProvider>(),
                        Aws::Auth::AWSCredentials(
                                TCHAR_TO_UTF8(*this->accessKeyId),
                                             TCHAR_TO_UTF8(*this->secretKey),
                                             TCHAR_TO_UTF8(*this->sessionToken),
                                             Aws::Utils::DateTime((int64_t)((expiration - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond))));*/
    };
#endif
};
