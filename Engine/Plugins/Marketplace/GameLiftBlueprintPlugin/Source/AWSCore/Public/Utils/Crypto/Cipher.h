/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#if WITH_CORE

#include "aws/core/utils/crypto/Cipher.h"

#endif

#include "Utils/Array.h"

#include "Cipher.generated.h"

/**
* Interface for symmetric encryption and decryption providers. An instance of this class is good for exactly one encryption or decryption run.
* It should not be used to encrypt or decrypt multiple messages.
*/
UCLASS(BlueprintType)
class AWSCORE_API USymmetricCipher : public UObject {
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Amazon")
    static FAWSByteBuffer GenerateKey(int64 keyLengthBytes = 32);
};
