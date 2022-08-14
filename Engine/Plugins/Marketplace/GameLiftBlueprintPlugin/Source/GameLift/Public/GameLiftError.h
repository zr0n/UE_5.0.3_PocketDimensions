/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK

#include "aws/gamelift/GameLiftErrors.h"

#endif

#include "GameLiftError.generated.h"

UENUM(BlueprintType)
enum class EGameLiftError : uint8 {
    //From Core//
    //////////////////////////////////////////////////////////////////////////////////////////
    INCOMPLETE_SIGNATURE UMETA(DisplayName = "Incomplete Signature"),
    INTERNAL_FAILURE UMETA(DisplayName = "Internal Failure"),
    INVALID_ACTION UMETA(DisplayName = "Invalid Action"),
    INVALID_CLIENT_TOKEN_ID UMETA(DisplayName = "Invalid Client Token ID"),
    INVALID_PARAMETER_COMBINATION UMETA(DisplayName = "Invalid Parameter Combination"),
    INVALID_QUERY_PARAMETER UMETA(DisplayName = "Invalid Query Parameter"),
    INVALID_PARAMETER_VALUE UMETA(DisplayName = "Invalid Parameter value"),
    MISSING_ACTION UMETA(DisplayName = "Missing Action"), // SDK should never allow
    MISSING_AUTHENTICATION_TOKEN UMETA(DisplayName = "Missing Authentication"), // SDK should never allow
    MISSING_PARAMETER UMETA(DisplayName = "Missing Parameter"), // SDK should never allow
    OPT_IN_REQUIRED UMETA(DisplayName = "Opt In Required"),
    REQUEST_EXPIRED UMETA(DisplayName = "Request Expired"),
    SERVICE_UNAVAILABLE UMETA(DisplayName = "Service Unavailable"),
    THROTTLING UMETA(DisplayName = "Throttling"),
    VALIDATION UMETA(DisplayName = "Validation"),
    ACCESS_DENIED UMETA(DisplayName = "Access Denied"),
    RESOURCE_NOT_FOUND UMETA(DisplayName = "Resource Not Found"),
    UNRECOGNIZED_CLIENT UMETA(DisplayName = "Unrecognized Client"),
    MALFORMED_QUERY_STRING UMETA(DisplayName = "Malformed Query String"),
    SLOW_DOWN UMETA(DisplayName = "Slow Down"),
    REQUEST_TIME_TOO_SKEWED UMETA(DisplayName = "Request Time Too Skewed"),
    INVALID_SIGNATURE UMETA(DisplayName = "Invalid Signature"),
    SIGNATURE_DOES_NOT_MATCH UMETA(DisplayName = "Signature Does Not Match"),
    INVALID_ACCESS_KEY_ID UMETA(DisplayName = "Invalid Access Key ID"),
    REQUEST_TIMEOUT UMETA(DisplayName = "Request Timeout"),
    NETWORK_CONNECTION UMETA(DisplayName = "Network Connection"),

    UNKNOWN UMETA(DisplayName = "Unknown"),
    ///////////////////////////////////////////////////////////////////////////////////////////

    CONFLICT UMETA(DisplayName = "Conflict"),
    FLEET_CAPACITY_EXCEEDED UMETA(DisplayName = "Fleet Capacity Exceeded"),
    GAME_SESSION_FULL UMETA(DisplayName = "Game Session Full"),
    IDEMPOTENT_PARAMETER_MISMATCH UMETA(DisplayName = "Idempotent Parameter Mismatch"),
    INTERNAL_SERVICE UMETA(DisplayName = "Internal Service"),
    INVALID_FLEET_STATUS UMETA(DisplayName = "Invalid Fleet Status"),
    INVALID_GAME_SESSION_STATUS UMETA(DisplayName = "Invalid Game Session Status"),
    INVALID_REQUEST UMETA(DisplayName = "Invalid Request"),
    LIMIT_EXCEEDED UMETA(DisplayName = "Limit Exceeded"),
    NOT_FOUND UMETA(DisplayName = "Not Found"),
    OUT_OF_CAPACITY UMETA(DisplayName = "Out of Capacity"),
    TAGGING_FAILED UMETA(DisplayName = "Tagging Failed"),
    TERMINAL_ROUTING_STRATEGY UMETA(DisplayName = "Terminal Routing Strategy"),
    UNAUTHORIZED UMETA(DisplayName = "Unauthorized"),
    UNSUPPORTED_REGION UMETA(DisplayName = "Unsupported Region"),
};
