/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "EventCode.generated.h"

UENUM(BlueprintType)
enum class EEventCode : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    GENERIC_EVENT        UMETA(DisplayName = "generic event"),
    FLEET_CREATED        UMETA(DisplayName = "fleet created"),
    FLEET_DELETED        UMETA(DisplayName = "fleet deleted"),
    FLEET_SCALING_EVENT        UMETA(DisplayName = "fleet scaling event"),
    FLEET_STATE_DOWNLOADING        UMETA(DisplayName = "fleet state downloading"),
    FLEET_STATE_VALIDATING        UMETA(DisplayName = "fleet state validating"),
    FLEET_STATE_BUILDING        UMETA(DisplayName = "fleet state building"),
    FLEET_STATE_ACTIVATING        UMETA(DisplayName = "fleet state activating"),
    FLEET_STATE_ACTIVE        UMETA(DisplayName = "fleet state active"),
    FLEET_STATE_ERROR        UMETA(DisplayName = "fleet state error"),
    FLEET_INITIALIZATION_FAILED        UMETA(DisplayName = "fleet initialization failed"),
    FLEET_BINARY_DOWNLOAD_FAILED        UMETA(DisplayName = "fleet binary download failed"),
    FLEET_VALIDATION_LAUNCH_PATH_NOT_FOUND        UMETA(DisplayName = "fleet validation launch path not found"),
    FLEET_VALIDATION_EXECUTABLE_RUNTIME_FAILURE        UMETA(DisplayName = "fleet validation executable runtime failure"),
    FLEET_VALIDATION_TIMED_OUT        UMETA(DisplayName = "fleet validation timed out"),
    FLEET_ACTIVATION_FAILED        UMETA(DisplayName = "fleet activation failed"),
    FLEET_ACTIVATION_FAILED_NO_INSTANCES        UMETA(DisplayName = "fleet activation failed no instances"),
    FLEET_NEW_GAME_SESSION_PROTECTION_POLICY_UPDATED        UMETA(DisplayName = "fleet new game session protection policy updated"),
    SERVER_PROCESS_INVALID_PATH        UMETA(DisplayName = "server process invalid path"),
    SERVER_PROCESS_SDK_INITIALIZATION_TIMEOUT        UMETA(DisplayName = "server process sdk initialization timeout"),
    SERVER_PROCESS_PROCESS_READY_TIMEOUT        UMETA(DisplayName = "server process process ready timeout"),
    SERVER_PROCESS_CRASHED        UMETA(DisplayName = "server process crashed"),
    SERVER_PROCESS_TERMINATED_UNHEALTHY        UMETA(DisplayName = "server process terminated unhealthy"),
    SERVER_PROCESS_FORCE_TERMINATED        UMETA(DisplayName = "server process force terminated"),
    SERVER_PROCESS_PROCESS_EXIT_TIMEOUT        UMETA(DisplayName = "server process process exit timeout"),
    GAME_SESSION_ACTIVATION_TIMEOUT        UMETA(DisplayName = "game session activation timeout"),
    FLEET_CREATION_EXTRACTING_BUILD        UMETA(DisplayName = "fleet creation extracting build"),
    FLEET_CREATION_RUNNING_INSTALLER        UMETA(DisplayName = "fleet creation running installer"),
    FLEET_CREATION_VALIDATING_RUNTIME_CONFIG        UMETA(DisplayName = "fleet creation validating runtime config"),
    FLEET_VPC_PEERING_SUCCEEDED        UMETA(DisplayName = "fleet vpc peering succeeded"),
    FLEET_VPC_PEERING_FAILED        UMETA(DisplayName = "fleet vpc peering failed"),
    FLEET_VPC_PEERING_DELETED        UMETA(DisplayName = "fleet vpc peering deleted"),
    INSTANCE_INTERRUPTED        UMETA(DisplayName = "instance interrupted")
};
