/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/LatentActionManager.h"

#if WITH_CORE

#include "aws/core/utils/crypto/EncryptionMaterials.h"
#include "aws/core/utils/memory/stl/AWSAllocator.h"

#endif

#include "EncryptionMaterials.generated.h"

UENUM(BlueprintType)
enum class ECryptoErrors : uint8 {
    ENCRYPT_CONTENT_ENCRYPTION_KEY_FAILED  UMETA(DisplayName = "encrypt content encryption key failed"),
    DECRYPT_CONTENT_ENCRYPTION_KEY_FAILED  UMETA(DisplayName = "decrypt content encryption key failed"),
    GENERATE_CONTENT_ENCRYPTION_KEY_FAILED  UMETA(DisplayName = "generate content encryption key failed")
};

/**
* Interface for symmetric encryption and decryption providers. An instance of this class is good for exactly one encryption or decryption run.
* It should not be used to encrypt or decrypt multiple messages.
*/
UCLASS(BlueprintType)
class AWSCORE_API UEncryptionMaterials : public UObject {
    GENERATED_BODY()

public:
#if WITH_CORE
    virtual std::shared_ptr<Aws::Utils::Crypto::EncryptionMaterials> toAWS() const {
        return nullptr;
    }
#endif

    virtual FString EncryptionMaterialsName() const {
        return "Encryption Materials";
    }
};
