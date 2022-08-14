/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreateMatchmakingConfigurationRequest.h"

#endif

#include "Model/GameProperty.h"
#include "Model/BackfillMode.h"
#include "Model/AWSGameLiftFlexMatchMode.h"
#include "Model/GameLiftTag.h"

#include "CreateMatchmakingConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FCreateMatchmakingConfigurationRequest {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the matchmaking configuration. This name is used to identify the configuration associated with a matchmaking request or ticket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString name;

    /**
    *  <p>A human-readable description of the matchmaking configuration. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString description;

    /**
    *  <p>The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) that is assigned to a GameLift game session queue resource and uniquely identifies it. ARNs are unique across all Regions. Format is <code>arn:aws:gamelift:&lt;region&gt;::gamesessionqueue/&lt;queue name&gt;</code>. Queues can be located in any Region. Queues are used to start new GameLift-hosted game sessions for matches that are created with this matchmaking configuration. If <code>FlexMatchMode</code> is set to <code>STANDALONE</code>, do not set this parameter. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FString> gameSessionQueueArns;

    /**
    *  <p>The maximum duration, in seconds, that a matchmaking ticket can remain in process before timing out. Requests that fail due to timing out can be resubmitted as needed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int requestTimeoutSeconds = 0;

    /**
    *  <p>The length of time (in seconds) to wait for players to accept a proposed match, if acceptance is required. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int acceptanceTimeoutSeconds = 0;

    /**
    *  <p>A flag that determines whether a match that was created with this configuration must be accepted by the matched players. To require acceptance, set to <code>TRUE</code>. With this option enabled, matchmaking tickets use the status <code>REQUIRES_ACCEPTANCE</code> to indicate when a completed potential match is waiting for player acceptance. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    bool acceptanceRequired = false;

    /**
    *  <p>A unique identifier for the matchmaking rule set to use with this configuration. You can use either the rule set name or ARN value. A matchmaking configuration can only use rule sets that are defined in the same Region.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString ruleSetName;

    /**
    *  <p>An SNS topic ARN that is set up to receive matchmaking notifications. See <a href="https://docs.aws.amazon.com/gamelift/latest/flexmatchguide/match-notification.html"> Setting up notifications for matchmaking</a> for more information.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString notificationTarget;

    /**
    *  <p>The number of player slots in a match to keep open for future players. For example, if the configuration's rule set specifies a match for a single 12-person team, and the additional player count is set to 2, only 10 players are selected for the match. This parameter is not used if <code>FlexMatchMode</code> is set to <code>STANDALONE</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int additionalPlayerCount = 0;

    /**
    *  <p>Information to be added to all events related to this matchmaking configuration. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString customEventData;

    /**
    *  <p>A set of custom properties for a game session, formatted as key:value pairs. These properties are passed to a game server process in the <a>GameSession</a> object with a request to start a new game session (see <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/gamelift-sdk-server-api.html#gamelift-sdk-server-startsession">Start a Game Session</a>). This information is added to the new <a>GameSession</a> object that is created for a successful match. This parameter is not used if <code>FlexMatchMode</code> is set to <code>STANDALONE</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FGameProperty> gameProperties;

    /**
    *  <p>A set of custom game session properties, formatted as a single string value. This data is passed to a game server process in the <a>GameSession</a> object with a request to start a new game session (see <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/gamelift-sdk-server-api.html#gamelift-sdk-server-startsession">Start a Game Session</a>). This information is added to the new <a>GameSession</a> object that is created for a successful match. This parameter is not used if <code>FlexMatchMode</code> is set to <code>STANDALONE</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameSessionData;

    /**
    *  <p>The method used to backfill game sessions that are created with this matchmaking configuration. Specify <code>MANUAL</code> when your game manages backfill requests manually or does not use the match backfill feature. Specify <code>AUTOMATIC</code> to have GameLift create a <a>StartMatchBackfill</a> request whenever a game session has one or more open slots. Learn more about manual and automatic backfill in <a href="https://docs.aws.amazon.com/gamelift/latest/flexmatchguide/match-backfill.html"> Backfill Existing Games with FlexMatch</a>. Automatic backfill is not available when <code>FlexMatchMode</code> is set to <code>STANDALONE</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EBackfillMode backfillMode = EBackfillMode::NOT_SET;

    /**
    *  <p>Indicates whether this matchmaking configuration is being used with GameLift hosting or as a standalone matchmaking solution. </p> <ul> <li> <p> <b>STANDALONE</b> - FlexMatch forms matches and returns match information, including players and team assignments, in a <a href="https://docs.aws.amazon.com/gamelift/latest/flexmatchguide/match-events.html#match-events-matchmakingsucceeded"> MatchmakingSucceeded</a> event.</p> </li> <li> <p> <b>WITH_QUEUE</b> - FlexMatch forms matches and uses the specified GameLift queue to start a game session for the match. </p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EAWSGameLiftFlexMatchMode flexMatchMode = EAWSGameLiftFlexMatchMode::NOT_SET;

    /**
    *  <p>A list of labels to assign to the new matchmaking configuration resource. Tags are developer-defined key-value pairs. Tagging AWS resources are useful for resource management, access management and cost allocation. For more information, see <a href="https://docs.aws.amazon.com/general/latest/gr/aws_tagging.html"> Tagging AWS Resources</a> in the <i>AWS General Reference</i>. Once the resource is created, you can use <a>TagResource</a>, <a>UntagResource</a>, and <a>ListTagsForResource</a> to add, remove, and view tags. The maximum tag limit may be lower than stated. See the AWS General Reference for actual tagging limits.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FGameLiftTag> tags;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::CreateMatchmakingConfigurationRequest toAWS() const {
        Aws::GameLift::Model::CreateMatchmakingConfigurationRequest awsCreateMatchmakingConfigurationRequest;

        if (!(this->name.IsEmpty())) {
            awsCreateMatchmakingConfigurationRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        if (!(this->description.IsEmpty())) {
            awsCreateMatchmakingConfigurationRequest.SetDescription(TCHAR_TO_UTF8(*this->description));
        }

        for (const FString& elem : this->gameSessionQueueArns) {
            awsCreateMatchmakingConfigurationRequest.AddGameSessionQueueArns(TCHAR_TO_UTF8(*elem));
        }

        if (this->requestTimeoutSeconds != 0) {
            awsCreateMatchmakingConfigurationRequest.SetRequestTimeoutSeconds(this->requestTimeoutSeconds);
        }

        if (this->acceptanceTimeoutSeconds != 0) {
            awsCreateMatchmakingConfigurationRequest.SetAcceptanceTimeoutSeconds(this->acceptanceTimeoutSeconds);
        }

        awsCreateMatchmakingConfigurationRequest.SetAcceptanceRequired(this->acceptanceRequired);

        if (!(this->ruleSetName.IsEmpty())) {
            awsCreateMatchmakingConfigurationRequest.SetRuleSetName(TCHAR_TO_UTF8(*this->ruleSetName));
        }

        if (!(this->notificationTarget.IsEmpty())) {
            awsCreateMatchmakingConfigurationRequest.SetNotificationTarget(TCHAR_TO_UTF8(*this->notificationTarget));
        }

        if (this->additionalPlayerCount != 0) {
            awsCreateMatchmakingConfigurationRequest.SetAdditionalPlayerCount(this->additionalPlayerCount);
        }

        if (!(this->customEventData.IsEmpty())) {
            awsCreateMatchmakingConfigurationRequest.SetCustomEventData(TCHAR_TO_UTF8(*this->customEventData));
        }

        for (const FGameProperty& elem : this->gameProperties) {
            awsCreateMatchmakingConfigurationRequest.AddGameProperties(elem.toAWS());
        }

        if (!(this->gameSessionData.IsEmpty())) {
            awsCreateMatchmakingConfigurationRequest.SetGameSessionData(TCHAR_TO_UTF8(*this->gameSessionData));
        }

        switch(this->backfillMode) {
            case EBackfillMode::AUTOMATIC:
                awsCreateMatchmakingConfigurationRequest.SetBackfillMode(Aws::GameLift::Model::BackfillMode::AUTOMATIC);
                break;
            case EBackfillMode::MANUAL:
                awsCreateMatchmakingConfigurationRequest.SetBackfillMode(Aws::GameLift::Model::BackfillMode::MANUAL);
                break;
            default:
                break;
        }

        switch(this->flexMatchMode) {
            case EAWSGameLiftFlexMatchMode::STANDALONE:
                awsCreateMatchmakingConfigurationRequest.SetFlexMatchMode(Aws::GameLift::Model::FlexMatchMode::STANDALONE);
                break;
            case EAWSGameLiftFlexMatchMode::WITH_QUEUE:
                awsCreateMatchmakingConfigurationRequest.SetFlexMatchMode(Aws::GameLift::Model::FlexMatchMode::WITH_QUEUE);
                break;
            default:
                break;
        }

        for (const FGameLiftTag& elem : this->tags) {
            awsCreateMatchmakingConfigurationRequest.AddTags(elem.toAWS());
        }

        return awsCreateMatchmakingConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->name.IsEmpty() && this->description.IsEmpty() && this->gameSessionQueueArns.Num() == 0 && this->requestTimeoutSeconds == 0 && this->acceptanceTimeoutSeconds == 0 && false && this->ruleSetName.IsEmpty() && this->notificationTarget.IsEmpty() && this->additionalPlayerCount == 0 && this->customEventData.IsEmpty() && this->gameProperties.Num() == 0 && this->gameSessionData.IsEmpty() && this->backfillMode == EBackfillMode::NOT_SET && this->flexMatchMode == EAWSGameLiftFlexMatchMode::NOT_SET && this->tags.Num() == 0;
    }
#endif
};
