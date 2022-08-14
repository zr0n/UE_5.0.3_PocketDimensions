/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "ServerHelper.generated.h"

/**
 * 
 */
UCLASS()
class GAMELIFTSERVERSDK_API UServerHelper : public UBlueprintFunctionLibrary {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure,
              meta = (WorldContext = WorldContextObject, DisplayName = "Get Server IP Address", CompactNodeTitle = "GetServerIP", Keywords = "Server IP Address"),
              Category = Game)
    static void ServerIPAndPort(UObject * WorldContextObject, FString &ip, int &port);

    UFUNCTION(BlueprintPure,
              meta = (DisplayName = "Get Log File Path", CompactNodeTitle = "GetLogFilePath", Keywords = "Log File Path"),
              Category = Game)
              static void LogFilePath(FString &logFilePath);

	UFUNCTION(BlueprintCallable, Category = "Game", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", Keywords = "Quit Server"))
	static void QuitServer(bool force);
};
