/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFT

#include "aws/gamelift/common/GameLiftErrors.h"

#endif

#include "GameLiftServerError.generated.h"

UENUM(BlueprintType)
enum class EGameLiftServerError : uint8 {
    ALREADY_INITIALIZED UMETA(DisplayName = "Already Initialized"),            // The GameLift Server or Client has already been initialized with Initialize().
    FLEET_MISMATCH UMETA(DisplayName = "Fleet Mismatch"),                 // The target fleet does not match the fleet of a gameSession or playerSession.
    GAMELIFT_CLIENT_NOT_INITIALIZED UMETA(DisplayName = "GameLift Client Not Initialized"),// The GameLift client has not been initialized.
    GAMELIFT_SERVER_NOT_INITIALIZED UMETA(DisplayName = "GameLift Server Not Initialized"),// The GameLift server has not been initialized.
    GAME_SESSION_ENDED_FAILED UMETA(DisplayName = "Game Session Ended Failed"),      // The GameLift Server SDK could not contact the service to report the game session ended.
    GAME_SESSION_NOT_READY UMETA(DisplayName = "Game Session Not Ready"),         // The GameLift Server Game Session was not activated.
    GAME_SESSION_READY_FAILED UMETA(DisplayName = "Game Session Ready Failed"),      // The GameLift Server SDK could not contact the service to report the game session is ready.
    INITIALIZATION_MISMATCH UMETA(DisplayName = "Initialization Mismatch"),        // A client method was called after Server::Initialize(), or vice versa.
    NOT_INITIALIZED UMETA(DisplayName = "Not Initialized"),                // The GameLift Server or Client has not been initialized with Initialize().
    NO_TARGET_ALIASID_SET UMETA(DisplayName = "No Target AliasID Set"),          // A target aliasId has not been set.
    NO_TARGET_FLEET_SET UMETA(DisplayName = "No Target Fleet Set"),            // A target fleet has not been set.
    PROCESS_ENDING_FAILED UMETA(DisplayName = "Process Ending Failed"),          // The GameLift Server SDK could not contact the service to report the process is ending.
    PROCESS_NOT_ACTIVE UMETA(DisplayName = "Process Not Active"),             // The server process is not yet active, not bound to a GameSession, and cannot accept or process PlayerSessions.
    PROCESS_NOT_READY UMETA(DisplayName = "Process Not Ready"),              // The server process is not yet ready to be activated.
    PROCESS_READY_FAILED UMETA(DisplayName = "Process Ready Failed"),           // The GameLift Server SDK could not contact the service to report the process is ready.
    SDK_VERSION_DETECTION_FAILED UMETA(DisplayName = "SDK Version Detection Failed"),   // SDK version detection failed.
    SERVICE_CALL_FAILED UMETA(DisplayName = "Service Call Failed"),            // A call to an AWS service has failed.
    STX_CALL_FAILED UMETA(DisplayName = "Stx Call Failed"),                // A call to the XStx server backend component has failed.
    STX_INITIALIZATION_FAILED UMETA(DisplayName = "Stx Initialization Failed"),      // The XStx server backend component has failed to initialize.
    UNEXPECTED_PLAYER_SESSION UMETA(DisplayName = "Unexpected Player Session"),       // An unregistered player session was encountered by the server.
    BAD_REQUEST_EXCEPTION UMETA(DisplayName = "Bad Request Exception"),
    INTERNAL_SERVICE_EXCEPTION UMETA(DisplayName = "Internal Service Exception"),
    UNKNOWN_ERROR UMETA(DisplayName = "Unknown Error"),
};