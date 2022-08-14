/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#include "ServerHelper.h"
#include "GenericPlatform/GenericPlatformOutputDevices.h"
#include "Misc/OutputDeviceFile.h"
#include "Engine/Engine.h"

void UServerHelper::ServerIPAndPort(UObject * WorldContextObject, FString &ip, int &port) {
    UWorld *world = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert);
    if (world->IsNetMode(ENetMode::NM_DedicatedServer)) {
        ip = world->URL.Host;
        port = world->URL.Port;
    }
    return;
}

void UServerHelper::LogFilePath(FString &logFilePath) {
    FOutputDevice* OutputDevice = FGenericPlatformOutputDevices::GetLog();
    if (OutputDevice != nullptr)
    {
        FOutputDeviceFile* OutputDeviceFile =
                static_cast<FOutputDeviceFile*>(OutputDevice);

        logFilePath = OutputDeviceFile->GetFilename();
    }
    return;
}

void UServerHelper::QuitServer(bool force) {
	FGenericPlatformMisc::RequestExit(force);
}
