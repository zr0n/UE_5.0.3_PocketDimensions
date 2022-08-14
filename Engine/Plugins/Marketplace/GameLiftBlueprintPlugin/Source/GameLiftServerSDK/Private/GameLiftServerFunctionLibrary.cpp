/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#include "GameLiftServerFunctionLibrary.h"

#if WITH_GAMELIFT

EGameLiftServerError fromAWS(Aws::GameLift::GAMELIFT_ERROR_TYPE awsErrorType) {
    switch (awsErrorType) {
        case Aws::GameLift::GAMELIFT_ERROR_TYPE::ALREADY_INITIALIZED:
            return EGameLiftServerError::ALREADY_INITIALIZED;
            break;
        case Aws::GameLift::GAMELIFT_ERROR_TYPE::FLEET_MISMATCH:
            return EGameLiftServerError::FLEET_MISMATCH;
            break;
        case Aws::GameLift::GAMELIFT_ERROR_TYPE::GAMELIFT_CLIENT_NOT_INITIALIZED:
            return EGameLiftServerError::GAMELIFT_CLIENT_NOT_INITIALIZED;
            break;
        case Aws::GameLift::GAMELIFT_ERROR_TYPE::GAMELIFT_SERVER_NOT_INITIALIZED:
            return EGameLiftServerError::GAMELIFT_SERVER_NOT_INITIALIZED;
            break;
        case Aws::GameLift::GAMELIFT_ERROR_TYPE::GAME_SESSION_ENDED_FAILED:
            return EGameLiftServerError::GAME_SESSION_ENDED_FAILED;
            break;
        case Aws::GameLift::GAMELIFT_ERROR_TYPE::GAME_SESSION_NOT_READY:
            return EGameLiftServerError::GAME_SESSION_NOT_READY;
            break;
        case Aws::GameLift::GAMELIFT_ERROR_TYPE::GAME_SESSION_READY_FAILED:
            return EGameLiftServerError::GAME_SESSION_READY_FAILED;
            break;
        case Aws::GameLift::GAMELIFT_ERROR_TYPE::INITIALIZATION_MISMATCH:
            return EGameLiftServerError::INITIALIZATION_MISMATCH;
            break;
        case Aws::GameLift::GAMELIFT_ERROR_TYPE::NOT_INITIALIZED:
            return EGameLiftServerError::NOT_INITIALIZED;
            break;
        case Aws::GameLift::GAMELIFT_ERROR_TYPE::NO_TARGET_ALIASID_SET:
            return EGameLiftServerError::NO_TARGET_ALIASID_SET;
            break;
        case Aws::GameLift::GAMELIFT_ERROR_TYPE::NO_TARGET_FLEET_SET:
            return EGameLiftServerError::NO_TARGET_FLEET_SET;
            break;
        case Aws::GameLift::GAMELIFT_ERROR_TYPE::PROCESS_ENDING_FAILED:
            return EGameLiftServerError::PROCESS_ENDING_FAILED;
            break;
        case Aws::GameLift::GAMELIFT_ERROR_TYPE::PROCESS_NOT_ACTIVE:
            return EGameLiftServerError::PROCESS_NOT_ACTIVE;
            break;
        case Aws::GameLift::GAMELIFT_ERROR_TYPE::PROCESS_NOT_READY:
            return EGameLiftServerError::PROCESS_NOT_READY;
            break;
        case Aws::GameLift::GAMELIFT_ERROR_TYPE::PROCESS_READY_FAILED:
            return EGameLiftServerError::PROCESS_READY_FAILED;
            break;
        case Aws::GameLift::GAMELIFT_ERROR_TYPE::SDK_VERSION_DETECTION_FAILED:
            return EGameLiftServerError::SDK_VERSION_DETECTION_FAILED;
            break;
        case Aws::GameLift::GAMELIFT_ERROR_TYPE::SERVICE_CALL_FAILED:
            return EGameLiftServerError::SERVICE_CALL_FAILED;
            break;
        case Aws::GameLift::GAMELIFT_ERROR_TYPE::STX_CALL_FAILED:
            return EGameLiftServerError::STX_CALL_FAILED;
            break;
        case Aws::GameLift::GAMELIFT_ERROR_TYPE::STX_INITIALIZATION_FAILED:
            return EGameLiftServerError::STX_INITIALIZATION_FAILED;
            break;
        case Aws::GameLift::GAMELIFT_ERROR_TYPE::UNEXPECTED_PLAYER_SESSION:
            return EGameLiftServerError::UNEXPECTED_PLAYER_SESSION;
            break;
        case Aws::GameLift::GAMELIFT_ERROR_TYPE::BAD_REQUEST_EXCEPTION:
            return EGameLiftServerError::BAD_REQUEST_EXCEPTION;
            break;
        case Aws::GameLift::GAMELIFT_ERROR_TYPE::INTERNAL_SERVICE_EXCEPTION:
            return EGameLiftServerError::INTERNAL_SERVICE_EXCEPTION;
            break;
        default:
            return EGameLiftServerError::UNKNOWN_ERROR;
            break;
    }
}

#endif

FString UGameLiftServerFunctionLibrary::GetSdkVersion(bool &success, EGameLiftServerError &errorType, FString &errorMessage) {
#if WITH_GAMELIFT
    Aws::GameLift::AwsStringOutcome awsStringOutcome = Aws::GameLift::Server::GetSdkVersion();
    success = awsStringOutcome.IsSuccess();

    errorType = fromAWS(awsStringOutcome.GetError().GetErrorType());
    errorMessage = (std::string("GameLift Server GetSdkVersion error: ") + awsStringOutcome.GetError().GetErrorMessage()).c_str();

    return awsStringOutcome.GetResult();
#endif
    return FString();
}

void UGameLiftServerFunctionLibrary::InitSDK(bool &success, EGameLiftServerError &errorType, FString &errorMessage) {
#if WITH_GAMELIFT
    Aws::GameLift::GenericOutcome awsGenericOutcome = Aws::GameLift::Server::InitSDK();
    success = awsGenericOutcome.IsSuccess();

    errorType = fromAWS(awsGenericOutcome.GetError().GetErrorType());
    errorMessage = (std::string("GameLift Server InitSDK error: ") + awsGenericOutcome.GetError().GetErrorMessage()).c_str();
#endif
}

void UGameLiftServerFunctionLibrary::ProcessReady(bool &success, EGameLiftServerError &errorType, FString &errorMessage,
                                                  const UProcessParameters* processParameters) {
#if WITH_GAMELIFT
    Aws::GameLift::GenericOutcome awsGenericOutcome = Aws::GameLift::Server::ProcessReady(processParameters->toAWS());
    success = awsGenericOutcome.IsSuccess();

    errorType = fromAWS(awsGenericOutcome.GetError().GetErrorType());
    errorMessage = (std::string("GameLift Server ProcessReady error: ") + awsGenericOutcome.GetError().GetErrorMessage()).c_str();
#endif
}

void UGameLiftServerFunctionLibrary::ProcessEnding(bool &success, EGameLiftServerError &errorType, FString &errorMessage) {
#if WITH_GAMELIFT
    Aws::GameLift::GenericOutcome awsGenericOutcome = Aws::GameLift::Server::ProcessEnding();
    success = awsGenericOutcome.IsSuccess();

    errorType = fromAWS(awsGenericOutcome.GetError().GetErrorType());
    errorMessage = (std::string("GameLift Server ProcessEnding error: ") + awsGenericOutcome.GetError().GetErrorMessage()).c_str();
#endif
}

void UGameLiftServerFunctionLibrary::ActivateGameSession(bool &success, EGameLiftServerError &errorType, FString &errorMessage) {
#if WITH_GAMELIFT
    Aws::GameLift::GenericOutcome awsGenericOutcome = Aws::GameLift::Server::ActivateGameSession();
    success = awsGenericOutcome.IsSuccess();

    errorType = fromAWS(awsGenericOutcome.GetError().GetErrorType());
    errorMessage = (std::string("GameLift Server ActivateGameSession error: ") + awsGenericOutcome.GetError().GetErrorMessage()).c_str();
#endif
}

void UGameLiftServerFunctionLibrary::AcceptPlayerSession(bool &success, EGameLiftServerError &errorType, FString &errorMessage,
                                                         const FString &playerSessionId) {
#if WITH_GAMELIFT
    Aws::GameLift::GenericOutcome awsGenericOutcome = Aws::GameLift::Server::AcceptPlayerSession(
            TCHAR_TO_UTF8(*playerSessionId));
    success = awsGenericOutcome.IsSuccess();

    errorType = fromAWS(awsGenericOutcome.GetError().GetErrorType());
    errorMessage = (std::string("GameLift Server AcceptPlayerSession error: ") + awsGenericOutcome.GetError().GetErrorMessage()).c_str();
#endif
}

void UGameLiftServerFunctionLibrary::RemovePlayerSession(bool &success, EGameLiftServerError &errorType, FString &errorMessage,
                                                         const FString &playerSessionId) {
#if WITH_GAMELIFT
    Aws::GameLift::GenericOutcome awsGenericOutcome = Aws::GameLift::Server::RemovePlayerSession(
            TCHAR_TO_UTF8(*playerSessionId));
    success = awsGenericOutcome.IsSuccess();

    errorType = fromAWS(awsGenericOutcome.GetError().GetErrorType());
    errorMessage = (std::string("GameLift Server RemovePlayerSession error: ") + awsGenericOutcome.GetError().GetErrorMessage()).c_str();
#endif
}

void UGameLiftServerFunctionLibrary::UpdatePlayerSessionCreationPolicy(bool &success, EGameLiftServerError &errorType, FString &errorMessage,
                                                                       const EPlayerSessionCreationPolicyServer &policy) {
#if WITH_GAMELIFT
    Aws::GameLift::Server::Model::PlayerSessionCreationPolicy awsPlayerSessionCreationPolicy = Aws::GameLift::Server::Model::PlayerSessionCreationPolicy::NOT_SET;

    switch (policy) {
        case EPlayerSessionCreationPolicyServer::NOT_SET:
            awsPlayerSessionCreationPolicy = Aws::GameLift::Server::Model::PlayerSessionCreationPolicy::NOT_SET;
            break;
        case EPlayerSessionCreationPolicyServer::ACCEPT_ALL:
            awsPlayerSessionCreationPolicy = Aws::GameLift::Server::Model::PlayerSessionCreationPolicy::ACCEPT_ALL;
            break;
        case EPlayerSessionCreationPolicyServer::DENY_ALL:
            awsPlayerSessionCreationPolicy = Aws::GameLift::Server::Model::PlayerSessionCreationPolicy::DENY_ALL;
            break;
    }

    Aws::GameLift::GenericOutcome awsGenericOutcome = Aws::GameLift::Server::UpdatePlayerSessionCreationPolicy(
            awsPlayerSessionCreationPolicy);
    success = awsGenericOutcome.IsSuccess();

    errorType = fromAWS(awsGenericOutcome.GetError().GetErrorType());
    errorMessage = (std::string("GameLift Server UpdatePlayerSessionCreationPolicy error: ") + awsGenericOutcome.GetError().GetErrorMessage()).c_str();
#endif
}

FString UGameLiftServerFunctionLibrary::GetGameSessionId(bool &success, EGameLiftServerError &errorType, FString &errorMessage) {
#if WITH_GAMELIFT
    Aws::GameLift::AwsStringOutcome awsStringOutcome = Aws::GameLift::Server::GetGameSessionId();
    success = awsStringOutcome.IsSuccess();

    errorType = fromAWS(awsStringOutcome.GetError().GetErrorType());
    errorMessage = (std::string("GameLift Server GetGameSessionId error: ") + awsStringOutcome.GetError().GetErrorMessage()).c_str();

    return awsStringOutcome.GetResult();
#endif
    return FString();
}

FDateTime UGameLiftServerFunctionLibrary::GetTerminationTime(bool &success, EGameLiftServerError &errorType, FString &errorMessage) {
#if WITH_GAMELIFT
    Aws::GameLift::AwsLongOutcome awsLongOutcome = Aws::GameLift::Server::GetTerminationTime();
    success = awsLongOutcome.IsSuccess();

    errorType = fromAWS(awsLongOutcome.GetError().GetErrorType());
    errorMessage = (std::string("GameLift Server GetTerminationTime error: ") + awsLongOutcome.GetError().GetErrorMessage()).c_str();

    return FDateTime(1970, 1, 1) + FTimespan(
            awsLongOutcome.GetResult() * ETimespan::TicksPerMillisecond);
#endif
    return FDateTime(0);
}

FStartMatchBackfillResultServer UGameLiftServerFunctionLibrary::StartMatchBackfill(bool &success, EGameLiftServerError &errorType, FString &errorMessage,
                                                                                   const FStartMatchBackfillRequestServer &startMatchBackfillRequestServer) {
#if WITH_GAMELIFT
    Aws::GameLift::StartMatchBackfillOutcome awsStartMatchBackfillOutcome = Aws::GameLift::Server::StartMatchBackfill(
            startMatchBackfillRequestServer.toAWS());
    success = awsStartMatchBackfillOutcome.IsSuccess();

    errorType = fromAWS(awsStartMatchBackfillOutcome.GetError().GetErrorType());
    errorMessage = (std::string("GameLift Server StartMatchBackfill error: ") + awsStartMatchBackfillOutcome.GetError().GetErrorMessage()).c_str();

    return FStartMatchBackfillResultServer().fromAWS(awsStartMatchBackfillOutcome.GetResult());
#endif
    return FStartMatchBackfillResultServer();
}

void UGameLiftServerFunctionLibrary::StopMatchBackfill(bool &success, EGameLiftServerError &errorType, FString &errorMessage,
                                                       const FStopMatchBackfillRequest &stopMatchBackfillRequest) {
#if WITH_GAMELIFT
    Aws::GameLift::GenericOutcome awsGenericOutcome = Aws::GameLift::Server::StopMatchBackfill(
            stopMatchBackfillRequest.toAWS());
    success = awsGenericOutcome.IsSuccess();

    errorType = fromAWS(awsGenericOutcome.GetError().GetErrorType());
    errorMessage = (std::string("GameLift Server StopMatchBackfill error: ") + awsGenericOutcome.GetError().GetErrorMessage()).c_str();
#endif
}

FDescribePlayerSessionsResultServer
UGameLiftServerFunctionLibrary::DescribePlayerSessions(bool &success, EGameLiftServerError &errorType, FString &errorMessage,
                                                       const FDescribePlayerSessionsRequestServer &describePlayerSessionsRequest) {
#if WITH_GAMELIFT
    Aws::GameLift::DescribePlayerSessionsOutcome awsDescribePlayerSessionsOutcome = Aws::GameLift::Server::DescribePlayerSessions(
            describePlayerSessionsRequest.toAWS());
    success = awsDescribePlayerSessionsOutcome.IsSuccess();

    errorType = fromAWS(awsDescribePlayerSessionsOutcome.GetError().GetErrorType());
    errorMessage = (std::string("GameLift Server DescribePlayerSessions error: ") + awsDescribePlayerSessionsOutcome.GetError().GetErrorMessage()).c_str();

    return FDescribePlayerSessionsResultServer().fromAWS(awsDescribePlayerSessionsOutcome.GetResult());
#endif
    return FDescribePlayerSessionsResultServer();
}

void UGameLiftServerFunctionLibrary::Destroy(bool &success, EGameLiftServerError &errorType, FString &errorMessage) {
#if WITH_GAMELIFT
    Aws::GameLift::GenericOutcome awsGenericOutcome = Aws::GameLift::Server::Destroy();
    success = awsGenericOutcome.IsSuccess();

    errorType = fromAWS(awsGenericOutcome.GetError().GetErrorType());
    errorMessage = (std::string("GameLift Server Destroy error: ") + awsGenericOutcome.GetError().GetErrorMessage()).c_str();
#endif
}

FGetInstanceCertificateResult UGameLiftServerFunctionLibrary::GetInstanceCertificate(bool &success, EGameLiftServerError &errorType, FString &errorMessage) {
#if WITH_GAMELIFT
    Aws::GameLift::GetInstanceCertificateOutcome awsGetInstanceCertificateOutcome = Aws::GameLift::Server::GetInstanceCertificate();
    success = awsGetInstanceCertificateOutcome.IsSuccess();

    errorType = fromAWS(awsGetInstanceCertificateOutcome.GetError().GetErrorType());
    errorMessage = (std::string("GameLift Server GetInstanceCertificate error: ") + awsGetInstanceCertificateOutcome.GetError().GetErrorMessage()).c_str();

    return FGetInstanceCertificateResult().fromAWS(awsGetInstanceCertificateOutcome.GetResult());
#endif
    return FGetInstanceCertificateResult();
}