/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/MatchmakingTicket.h"

#endif

#include "Model/MatchmakingConfigurationStatus.h"
#include "Model/AWSPlayer.h"
#include "Model/GameSessionConnectionInfo.h"

#include "MatchmakingTicket.generated.h"

USTRUCT(BlueprintType)
struct FMatchmakingTicket {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a matchmaking ticket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString ticketId;

    /**
    *  <p>Name of the <a>MatchmakingConfiguration</a> that is used with this ticket. Matchmaking configurations determine how players are grouped into a match and how a new game session is created for the match.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString configurationName;

    /**
    *  <p>The Amazon Resource Name (<a href="https://docs.aws.amazon.com/general/latest/gr/aws-arns-and-namespaces.html">ARN</a>) associated with the GameLift matchmaking configuration resource that is used with this ticket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString configurationArn;

    /**
    *  <p>Current status of the matchmaking request.</p> <ul> <li> <p> <b>QUEUED</b> -- The matchmaking request has been received and is currently waiting to be processed.</p> </li> <li> <p> <b>SEARCHING</b> -- The matchmaking request is currently being processed. </p> </li> <li> <p> <b>REQUIRES_ACCEPTANCE</b> -- A match has been proposed and the players must accept the match (see <a>AcceptMatch</a>). This status is used only with requests that use a matchmaking configuration with a player acceptance requirement.</p> </li> <li> <p> <b>PLACING</b> -- The FlexMatch engine has matched players and is in the process of placing a new game session for the match.</p> </li> <li> <p> <b>COMPLETED</b> -- Players have been matched and a game session is ready to host the players. A ticket in this state contains the necessary connection information for players.</p> </li> <li> <p> <b>FAILED</b> -- The matchmaking request was not completed.</p> </li> <li> <p> <b>CANCELLED</b> -- The matchmaking request was canceled. This may be the result of a call to <a>StopMatchmaking</a> or a proposed match that one or more players failed to accept.</p> </li> <li> <p> <b>TIMED_OUT</b> -- The matchmaking request was not successful within the duration specified in the matchmaking configuration. </p> </li> </ul> <note> <p>Matchmaking requests that fail to successfully complete (statuses FAILED, CANCELLED, TIMED_OUT) can be resubmitted as new requests with new ticket IDs.</p> </note>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EMatchmakingConfigurationStatus status = EMatchmakingConfigurationStatus::NOT_SET;

    /**
    *  <p>Code to explain the current status. For example, a status reason may indicate when a ticket has returned to <code>SEARCHING</code> status after a proposed match fails to receive player acceptances.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString statusReason;

    /**
    *  <p>Additional information about the current status.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString statusMessage;

    /**
    *  <p>Time stamp indicating when this matchmaking request was received. Format is a number expressed in Unix time as milliseconds (for example "1469498468.057").</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FDateTime startTime;

    /**
    *  <p>Time stamp indicating when this matchmaking request stopped being processed due to success, failure, or cancellation. Format is a number expressed in Unix time as milliseconds (for example "1469498468.057").</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FDateTime endTime;

    /**
    *  <p>A set of <code>Player</code> objects, each representing a player to find matches for. Players are identified by a unique player ID and may include latency data for use during matchmaking. If the ticket is in status <code>COMPLETED</code>, the <code>Player</code> objects include the team the players were assigned to in the resulting match.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FAWSPlayer> players;

    /**
    *  <p>Identifier and connection information of the game session created for the match. This information is added to the ticket only after the matchmaking request has been successfully completed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FAWSGameSessionConnectionInfo gameSessionConnectionInfo;

    /**
    *  <p>Average amount of time (in seconds) that players are currently waiting for a match. If there is not enough recent data, this property may be empty.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int estimatedWaitTime = 0;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FMatchmakingTicket &fromAWS(const Aws::GameLift::Model::MatchmakingTicket &awsMatchmakingTicket) {
        this->ticketId = UTF8_TO_TCHAR(awsMatchmakingTicket.GetTicketId().c_str());

        this->configurationName = UTF8_TO_TCHAR(awsMatchmakingTicket.GetConfigurationName().c_str());

        this->configurationArn = UTF8_TO_TCHAR(awsMatchmakingTicket.GetConfigurationArn().c_str());

        switch(awsMatchmakingTicket.GetStatus()) {
            case Aws::GameLift::Model::MatchmakingConfigurationStatus::NOT_SET:
                this->status = EMatchmakingConfigurationStatus::NOT_SET;
                break;
            case Aws::GameLift::Model::MatchmakingConfigurationStatus::CANCELLED:
                this->status = EMatchmakingConfigurationStatus::CANCELLED;
                break;
            case Aws::GameLift::Model::MatchmakingConfigurationStatus::COMPLETED:
                this->status = EMatchmakingConfigurationStatus::COMPLETED;
                break;
            case Aws::GameLift::Model::MatchmakingConfigurationStatus::FAILED:
                this->status = EMatchmakingConfigurationStatus::FAILED;
                break;
            case Aws::GameLift::Model::MatchmakingConfigurationStatus::PLACING:
                this->status = EMatchmakingConfigurationStatus::PLACING;
                break;
            case Aws::GameLift::Model::MatchmakingConfigurationStatus::QUEUED:
                this->status = EMatchmakingConfigurationStatus::QUEUED;
                break;
            case Aws::GameLift::Model::MatchmakingConfigurationStatus::REQUIRES_ACCEPTANCE:
                this->status = EMatchmakingConfigurationStatus::REQUIRES_ACCEPTANCE;
                break;
            case Aws::GameLift::Model::MatchmakingConfigurationStatus::SEARCHING:
                this->status = EMatchmakingConfigurationStatus::SEARCHING;
                break;
            case Aws::GameLift::Model::MatchmakingConfigurationStatus::TIMED_OUT:
                this->status = EMatchmakingConfigurationStatus::TIMED_OUT;
                break;
            default:
                this->status = EMatchmakingConfigurationStatus::NOT_SET;
                break;
        }

        this->statusReason = UTF8_TO_TCHAR(awsMatchmakingTicket.GetStatusReason().c_str());

        this->statusMessage = UTF8_TO_TCHAR(awsMatchmakingTicket.GetStatusMessage().c_str());

        this->startTime = FDateTime(1970, 1, 1) + FTimespan(awsMatchmakingTicket.GetStartTime().Millis() * ETimespan::TicksPerMillisecond);

        this->endTime = FDateTime(1970, 1, 1) + FTimespan(awsMatchmakingTicket.GetEndTime().Millis() * ETimespan::TicksPerMillisecond);

        this->players.Empty();
        for (const Aws::GameLift::Model::Player& elem : awsMatchmakingTicket.GetPlayers()) {
            this->players.Add(FAWSPlayer().fromAWS(elem));
        }

        this->gameSessionConnectionInfo.fromAWS(awsMatchmakingTicket.GetGameSessionConnectionInfo());

        this->estimatedWaitTime = awsMatchmakingTicket.GetEstimatedWaitTime();

        return *this;
    }
#endif
};
