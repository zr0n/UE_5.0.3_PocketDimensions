/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#include "ProcessParameters.h"
#include "GameLiftServerFunctionLibrary.h"

void UProcessParameters::StartGameSession_Implementation(FAWSGameSessionServer gameSession) {
    bool success = false;
    EGameLiftServerError errorType;
    FString errorMessage;
    UGameLiftServerFunctionLibrary::ActivateGameSession(success, errorType, errorMessage);
}

void UProcessParameters::UpdateGameSession_Implementation(FUpdateGameSessionServer updateGameSession) {

}

void UProcessParameters::ProcessTerminate_Implementation() {
    bool success = false;
    EGameLiftServerError errorType;
    FString errorMessage;
    UGameLiftServerFunctionLibrary::ProcessEnding(success, errorType, errorMessage);

    FGenericPlatformMisc::RequestExit(false);
}

bool UProcessParameters::HealthCheck_Implementation() {
    return true;
}
