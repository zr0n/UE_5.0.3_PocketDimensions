/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, May 2019
 */

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#if WITH_CORE

#include "aws/core/utils/UUID.h"

#endif

#include "UUID.generated.h"

USTRUCT(BlueprintType)
struct FAWSUUID {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Client")
    FString uuid;

#if WITH_CORE
public:
    FAWSUUID& fromAWS(const Aws::Utils::UUID& awsUUID) {
        this->uuid = UTF8_TO_TCHAR(Aws::String(awsUUID).c_str());

        return *this;
    };
#endif
};

/**
 *
 */
UCLASS(BlueprintType)
class AWSCORE_API UUUID : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Amazon")
    static FAWSUUID RandomUUID();
};
