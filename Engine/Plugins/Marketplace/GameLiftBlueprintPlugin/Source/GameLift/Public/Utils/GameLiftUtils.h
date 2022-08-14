/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, May 2019
 */

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameLiftUtils.generated.h"

UENUM(BlueprintType)
enum class EGameLiftARNType : uint8 {
    UNKNOWN         UMETA(DisplayName = "unknown"),
    Fleet_Id        UMETA(DisplayName = "fleet id"),
    Alias_Id        UMETA(DisplayName = "alias id"),
    GameSession_Id  UMETA(DisplayName = "game session id")
};

/**
 * 
 */
UCLASS(BlueprintType)
class GAMELIFT_API UGameLiftUtils : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Amazon")
    static EGameLiftARNType IdentifyGameLiftARNType(const FString &awsResourceName);
};
