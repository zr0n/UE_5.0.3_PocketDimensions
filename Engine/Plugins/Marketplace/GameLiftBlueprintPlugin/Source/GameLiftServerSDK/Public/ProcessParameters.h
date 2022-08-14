/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#if WITH_GAMELIFT

#include "aws/gamelift/server/model/GameSessionStatus.h"
#include "aws/gamelift/server/model/GameProperty.h"
#include "aws/gamelift/server/model/GameSession.h"
#include "aws/gamelift/server/model/UpdateReason.h"
#include "aws/gamelift/server/model/UpdateGameSession.h"

#include "aws/gamelift/server/ProcessParameters.h"

#endif

#include "Model/AWSGameSessionServer.h"
#include "Model/UpdateGameSessionServer.h"

#include "ProcessParameters.generated.h"

UCLASS(Blueprintable)
class GAMELIFTSERVERSDK_API UProcessParameters : public UObject {
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Server", Meta = (ExposeOnSpawn = true))
    int port;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Server", Meta = (ExposeOnSpawn = true))
    TArray<FString> logPaths;

    UFUNCTION(BlueprintNativeEvent, Category = "Game Lift Server")
    void StartGameSession(FAWSGameSessionServer gameSession);

    UFUNCTION(BlueprintNativeEvent, Category = "Game Lift Server")
    void UpdateGameSession(FUpdateGameSessionServer updateGameSession);

    UFUNCTION(BlueprintNativeEvent, Category = "Game Lift Server")
    void ProcessTerminate();

    UFUNCTION(BlueprintNativeEvent, Category = "Game Lift Server")
    bool HealthCheck();

#if WITH_GAMELIFT
    Aws::GameLift::Server::ProcessParameters toAWS() const {
        const char *awsLogPaths[MAX_LOG_PATHS];
        for (int i = 0; i < FMath::Min(this->logPaths.Num(), MAX_LOG_PATHS); i++) {
            awsLogPaths[i] = TCHAR_TO_UTF8(*this->logPaths[i]);
        }

        Aws::GameLift::Server::StartGameSessionFn onStartGameSession = [](Aws::GameLift::Server::Model::GameSession awsGameSession, void *state) -> void {
            UProcessParameters* processParameters = (UProcessParameters*) state;
            processParameters->StartGameSession(FAWSGameSessionServer().fromAWS(awsGameSession));
        };

        Aws::GameLift::Server::UpdateGameSessionFn onUpdateGameSession = [](
                Aws::GameLift::Server::Model::UpdateGameSession awsUpdateGameSession, void *state) -> void {
            UProcessParameters* processParameters = (UProcessParameters*) state;
            processParameters->UpdateGameSession(FUpdateGameSessionServer().fromAWS(awsUpdateGameSession));
        };

        Aws::GameLift::Server::ProcessTerminateFn onProcessTerminate = [](void *state) -> void {
            UProcessParameters* processParameters = (UProcessParameters*) state;
            processParameters->ProcessTerminate();
        };

        Aws::GameLift::Server::HealthCheckFn onHealthCheck = [](void *state) -> bool {
            UProcessParameters* processParameters = (UProcessParameters*) state;
            return processParameters->HealthCheck();
        };

        return Aws::GameLift::Server::ProcessParameters(
                onStartGameSession,
                (void*)this,
                onUpdateGameSession,
                (void*)this,
                onProcessTerminate,
                (void*)this,
                onHealthCheck,
                (void*)this,
                this->port,
                Aws::GameLift::Server::LogParameters(awsLogPaths, this->logPaths.Num())
        );
    }

#endif
};
