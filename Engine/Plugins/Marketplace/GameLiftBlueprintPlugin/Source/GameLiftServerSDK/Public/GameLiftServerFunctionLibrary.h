/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "ProcessParameters.h"

#if WITH_GAMELIFT

#include "aws/gamelift/server/GameLiftServerAPI.h"

#endif

#include "GameLiftServerError.h"

#include "Model/AttributeValueServer.h"
#include "Model/AWSPlayerServer.h"
#include "Model/AWSPlayerSessionServer.h"
#include "Model/DescribePlayerSessionsRequestServer.h"
#include "Model/DescribePlayerSessionsResultServer.h"
#include "Model/GetInstanceCertificateResult.h"
#include "Model/PlayerSessionCreationPolicyServer.h"
#include "Model/PlayerSessionStatusServer.h"
#include "Model/StartMatchBackfillRequestServer.h"
#include "Model/StartMatchBackfillResultServer.h"
#include "Model/StopMatchBackfillRequest.h"

#include "GameLiftServerFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class GAMELIFTSERVERSDK_API UGameLiftServerFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()

public:
    /**
    @return The current SDK version.
    */
    UFUNCTION(BlueprintCallable, Category = "Game Lift Server")
    static FString GetSdkVersion(bool &success, EGameLiftServerError &errorType, FString &errorMessage);

    /**
    Initializes the GameLift server.
    Should be called when the server starts, before any GameLift-dependent initialization happens.
    @return Pointer to the internal server state for use with InitializeWithExisting().
    */
    UFUNCTION(BlueprintCallable, Category = "Game Lift Server")
    static void InitSDK(bool &success, EGameLiftServerError &errorType, FString &errorMessage);

    /**
    Signals GameLift that the process is ready to receive GameSessions.
    The onStartGameSession callback will be invoked when the server is bound to a GameSession. Game-property-dependent initialization (such as loading a
    user-requested map) should take place at that time. The onHealthCheck callback is invoked asynchronously. There is no mechanism to
    to destroy the resulting thread. If it does not complete in a given time period the server status will be reported as unhealthy.
    @param processParameters The parameters required to successfully run the process.
    */
    UFUNCTION(BlueprintCallable, Category = "Game Lift Server")
    static void ProcessReady(bool &success, EGameLiftServerError &errorType, FString &errorMessage, const UProcessParameters *processParameters);

    /**
    Signals GameLift that the process is ending.
    GameLift will eventually terminate the process and recycle the host. Once the process is marked as Ending,
    */
    UFUNCTION(BlueprintCallable, Category = "Game Lift Server")
    static void ProcessEnding(bool &success, EGameLiftServerError &errorType, FString &errorMessage);

    /**
    Reports to GameLift that the server process is now ready to receive player sessions.
    Should be called once all GameSession initialization has finished.
    */
    UFUNCTION(BlueprintCallable, Category = "Game Lift Server")
    static void ActivateGameSession(bool &success, EGameLiftServerError &errorType, FString &errorMessage);

    /**
    Processes and validates a player session connection. This method should be called when a client requests a
    connection to the server. The client should send the PlayerSessionID which it received from RequestPlayerSession
    or GameLift::CreatePlayerSession to be passed into this function.
    This method will return an UNEXPECTED_PLAYER_SESSION error if the player session ID is invalid.
    @param playerSessionId the ID of the joining player's session.
    */
    UFUNCTION(BlueprintCallable, Category = "Game Lift Server")
    static void AcceptPlayerSession(bool &success, EGameLiftServerError &errorType, FString &errorMessage, const FString &playerSessionId);

    /**
    Processes a player session disconnection. Should be called when a player leaves or otherwise disconnects from
    the server.
    @param playerSessionId the ID of the joining player's session.
    */
    UFUNCTION(BlueprintCallable, Category = "Game Lift Server")
    static void RemovePlayerSession(bool &success, EGameLiftServerError &errorType, FString &errorMessage, const FString &playerSessionId);

    /**
    update player session policy on the GameSession
    */
    UFUNCTION(BlueprintCallable, Category = "Game Lift Server")
    static void UpdatePlayerSessionCreationPolicy(bool &success, EGameLiftServerError &errorType, FString &errorMessage,
                                                  const EPlayerSessionCreationPolicyServer &policy);

    /**
    @return The server's bound GameSession Id, if the server is Active.
    */
    UFUNCTION(BlueprintCallable, Category = "Game Lift Server")
    static FString GetGameSessionId(bool &success, EGameLiftServerError &errorType, FString &errorMessage);

    /**
   Gets the time remaining before GameLift will shut down the server process. Use this method in your onProcessTerminate() callback implementation to learn when the process will be terminated.
   @return The server's terminationTime in epoch seconds. Value will be -1 if GameLift is not scheduled to terminate the server process.
   */
    UFUNCTION(BlueprintCallable, Category = "Game Lift Server")
    static FDateTime GetTerminationTime(bool &success, EGameLiftServerError &errorType, FString &errorMessage);

    /**
    Reports to GameLift that we need to backfill a match using FlexMatch.
    When the match has been succeessfully backfilled updated matchmaker data will be sent to
    the OnUpdateGameSession callback.
    */
    UFUNCTION(BlueprintCallable, Category = "Game Lift Server")
    static FStartMatchBackfillResultServer StartMatchBackfill(bool &success, EGameLiftServerError &errorType, FString &errorMessage,
                                                              const FStartMatchBackfillRequestServer &startMatchBackfillRequestServer);

    /**
    Reports to GameLift that we need to stop a request to backfill a match using FlexMatch.
    */
    UFUNCTION(BlueprintCallable, Category = "Game Lift Server")
    static void StopMatchBackfill(bool &success, EGameLiftServerError &errorType, FString &errorMessage, const FStopMatchBackfillRequest &stopMatchBackfillRequest);

    /**
        <p>Retrieves properties for one or more player sessions. This action can be used
        in several ways: (1) provide a <code>PlayerSessionId</code> parameter to request
        properties for a specific player session; (2) provide a
        <code>GameSessionId</code> parameter to request properties for all player
        sessions in the specified game session; (3) provide a <code>PlayerId</code>
        parameter to request properties for all player sessions of a specified player.
        </p> <p>You can filter this request by player session status. Use the pagination
        parameters to retrieve results as a set of sequential pages. If successful, a
        <a>PlayerSession</a> object is returned for each session matching the request.</p>
    */
    UFUNCTION(BlueprintCallable, Category = "Game Lift Server")
    static FDescribePlayerSessionsResultServer DescribePlayerSessions(bool &success, EGameLiftServerError &errorType, FString &errorMessage,
                                                                      const FDescribePlayerSessionsRequestServer &describePlayerSessionsRequest);

    /**
    <p>Destroys allocated resources.</p>
    */
    UFUNCTION(BlueprintCallable, Category = "Game Lift Server")
    static void Destroy(bool &success, EGameLiftServerError &errorType, FString &errorMessage);

    /**
   <p>Retrieves the certificate, private key and password in PEM format.
   Will only succeed if the certificate generation is enabled on the fleet.</p>
   */
    UFUNCTION(BlueprintCallable, Category = "Game Lift Server")
    static FGetInstanceCertificateResult GetInstanceCertificate(bool &success, EGameLiftServerError &errorType, FString &errorMessage);
};
