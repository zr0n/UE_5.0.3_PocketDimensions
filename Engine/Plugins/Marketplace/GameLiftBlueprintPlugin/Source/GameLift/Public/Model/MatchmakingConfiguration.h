/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/MatchmakingConfiguration.h"

#endif

#include "Model/GameProperty.h"
#include "Model/BackfillMode.h"
#include "Model/AWSGameLiftFlexMatchMode.h"

#include "MatchmakingConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FMatchmakingConfiguration {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the matchmaking configuration. This name is used to identify the configuration associated with a matchmaking request or ticket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString name;

    /**
    *  <p>The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) that is assigned to a GameLift matchmaking configuration resource and uniquely identifies it. ARNs are unique across all Regions. Format is <code>arn:aws:gamelift:&lt;region&gt;::matchmakingconfiguration/&lt;matchmaking configuration name&gt;</code>. In a GameLift configuration ARN, the resource ID matches the <i>Name</i> value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString configurationArn;

    /**
    *  <p>A descriptive label that is associated with matchmaking configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString description;

    /**
    *  <p>The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) that is assigned to a GameLift game session queue resource and uniquely identifies it. ARNs are unique across all Regions. Format is <code>arn:aws:gamelift:&lt;region&gt;::gamesessionqueue/&lt;queue name&gt;</code>. Queues can be located in any Region. Queues are used to start new GameLift-hosted game sessions for matches that are created with this matchmaking configuration. This property is not set when <code>FlexMatchMode</code> is set to <code>STANDALONE</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FString> gameSessionQueueArns;

    /**
    *  <p>The maximum duration, in seconds, that a matchmaking ticket can remain in process before timing out. Requests that fail due to timing out can be resubmitted as needed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int requestTimeoutSeconds = 0;

    /**
    *  <p>The length of time (in seconds) to wait for players to accept a proposed match, if acceptance is required. If any player rejects the match or fails to accept before the timeout, the ticket continues to look for an acceptable match.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int acceptanceTimeoutSeconds = 0;

    /**
    *  <p>A flag that indicates whether a match that was created with this configuration must be accepted by the matched players. To require acceptance, set to TRUE. When this option is enabled, matchmaking tickets use the status <code>REQUIRES_ACCEPTANCE</code> to indicate when a completed potential match is waiting for player acceptance.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    bool acceptanceRequired = false;

    /**
    *  <p>A unique identifier for the matchmaking rule set to use with this configuration. A matchmaking configuration can only use rule sets that are defined in the same Region.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString ruleSetName;

    /**
    *  <p>The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) associated with the GameLift matchmaking rule set resource that this configuration uses.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString ruleSetArn;

    /**
    *  <p>An SNS topic ARN that is set up to receive matchmaking notifications.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString notificationTarget;

    /**
    *  <p>The number of player slots in a match to keep open for future players. For example, if the configuration's rule set specifies a match for a single 12-person team, and the additional player count is set to 2, only 10 players are selected for the match. This parameter is not used when <code>FlexMatchMode</code> is set to <code>STANDALONE</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int additionalPlayerCount = 0;

    /**
    *  <p>Information to attach to all events related to the matchmaking configuration. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString customEventData;

    /**
    *  <p>A time stamp indicating when this data object was created. Format is a number expressed in Unix time as milliseconds (for example <code>"1469498468.057"</code>).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FDateTime creationTime;

    /**
    *  <p>A set of custom properties for a game session, formatted as key:value pairs. These properties are passed to a game server process in the <a>GameSession</a> object with a request to start a new game session (see <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/gamelift-sdk-server-api.html#gamelift-sdk-server-startsession">Start a Game Session</a>). This information is added to the new <a>GameSession</a> object that is created for a successful match. This parameter is not used when <code>FlexMatchMode</code> is set to <code>STANDALONE</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FGameProperty> gameProperties;

    /**
    *  <p>A set of custom game session properties, formatted as a single string value. This data is passed to a game server process in the <a>GameSession</a> object with a request to start a new game session (see <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/gamelift-sdk-server-api.html#gamelift-sdk-server-startsession">Start a Game Session</a>). This information is added to the new <a>GameSession</a> object that is created for a successful match. This parameter is not used when <code>FlexMatchMode</code> is set to <code>STANDALONE</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameSessionData;

    /**
    *  <p>The method used to backfill game sessions created with this matchmaking configuration. MANUAL indicates that the game makes backfill requests or does not use the match backfill feature. AUTOMATIC indicates that GameLift creates <a>StartMatchBackfill</a> requests whenever a game session has one or more open slots. Learn more about manual and automatic backfill in <a href="https://docs.aws.amazon.com/gamelift/latest/flexmatchguide/match-backfill.html">Backfill existing games with FlexMatch</a>. Automatic backfill is not available when <code>FlexMatchMode</code> is set to <code>STANDALONE</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EBackfillMode backfillMode = EBackfillMode::NOT_SET;

    /**
    *  <p>Indicates whether this matchmaking configuration is being used with GameLift hosting or as a standalone matchmaking solution. </p> <ul> <li> <p> <b>STANDALONE</b> - FlexMatch forms matches and returns match information, including players and team assignments, in a <a href="https://docs.aws.amazon.com/gamelift/latest/flexmatchguide/match-events.html#match-events-matchmakingsucceeded"> MatchmakingSucceeded</a> event.</p> </li> <li> <p> <b>WITH_QUEUE</b> - FlexMatch forms matches and uses the specified GameLift queue to start a game session for the match. </p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EAWSGameLiftFlexMatchMode flexMatchMode = EAWSGameLiftFlexMatchMode::NOT_SET;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FMatchmakingConfiguration &fromAWS(const Aws::GameLift::Model::MatchmakingConfiguration &awsMatchmakingConfiguration) {
        this->name = UTF8_TO_TCHAR(awsMatchmakingConfiguration.GetName().c_str());

        this->configurationArn = UTF8_TO_TCHAR(awsMatchmakingConfiguration.GetConfigurationArn().c_str());

        this->description = UTF8_TO_TCHAR(awsMatchmakingConfiguration.GetDescription().c_str());

        this->gameSessionQueueArns.Empty();
        for (const Aws::String& elem : awsMatchmakingConfiguration.GetGameSessionQueueArns()) {
            this->gameSessionQueueArns.Add(elem.c_str());
        }

        this->requestTimeoutSeconds = awsMatchmakingConfiguration.GetRequestTimeoutSeconds();

        this->acceptanceTimeoutSeconds = awsMatchmakingConfiguration.GetAcceptanceTimeoutSeconds();

        this->acceptanceRequired = awsMatchmakingConfiguration.GetAcceptanceRequired();

        this->ruleSetName = UTF8_TO_TCHAR(awsMatchmakingConfiguration.GetRuleSetName().c_str());

        this->ruleSetArn = UTF8_TO_TCHAR(awsMatchmakingConfiguration.GetRuleSetArn().c_str());

        this->notificationTarget = UTF8_TO_TCHAR(awsMatchmakingConfiguration.GetNotificationTarget().c_str());

        this->additionalPlayerCount = awsMatchmakingConfiguration.GetAdditionalPlayerCount();

        this->customEventData = UTF8_TO_TCHAR(awsMatchmakingConfiguration.GetCustomEventData().c_str());

        this->creationTime = FDateTime(1970, 1, 1) + FTimespan(awsMatchmakingConfiguration.GetCreationTime().Millis() * ETimespan::TicksPerMillisecond);

        this->gameProperties.Empty();
        for (const Aws::GameLift::Model::GameProperty& elem : awsMatchmakingConfiguration.GetGameProperties()) {
            this->gameProperties.Add(FGameProperty().fromAWS(elem));
        }

        this->gameSessionData = UTF8_TO_TCHAR(awsMatchmakingConfiguration.GetGameSessionData().c_str());

        switch(awsMatchmakingConfiguration.GetBackfillMode()) {
            case Aws::GameLift::Model::BackfillMode::NOT_SET:
                this->backfillMode = EBackfillMode::NOT_SET;
                break;
            case Aws::GameLift::Model::BackfillMode::AUTOMATIC:
                this->backfillMode = EBackfillMode::AUTOMATIC;
                break;
            case Aws::GameLift::Model::BackfillMode::MANUAL:
                this->backfillMode = EBackfillMode::MANUAL;
                break;
            default:
                this->backfillMode = EBackfillMode::NOT_SET;
                break;
        }

        switch(awsMatchmakingConfiguration.GetFlexMatchMode()) {
            case Aws::GameLift::Model::FlexMatchMode::NOT_SET:
                this->flexMatchMode = EAWSGameLiftFlexMatchMode::NOT_SET;
                break;
            case Aws::GameLift::Model::FlexMatchMode::STANDALONE:
                this->flexMatchMode = EAWSGameLiftFlexMatchMode::STANDALONE;
                break;
            case Aws::GameLift::Model::FlexMatchMode::WITH_QUEUE:
                this->flexMatchMode = EAWSGameLiftFlexMatchMode::WITH_QUEUE;
                break;
            default:
                this->flexMatchMode = EAWSGameLiftFlexMatchMode::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
