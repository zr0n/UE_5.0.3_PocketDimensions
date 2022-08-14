/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/GameSessionQueue.h"

#endif

#include "Model/PlayerLatencyPolicy.h"
#include "Model/GameSessionQueueDestination.h"
#include "Model/AWSGameLiftFilterConfiguration.h"
#include "Model/AWSGameLiftPriorityConfiguration.h"

#include "GameSessionQueue.generated.h"

USTRUCT(BlueprintType)
struct FGameSessionQueue {
GENERATED_BODY()

    /**
    *  <p>A descriptive label that is associated with game session queue. Queue names must be unique within each Region.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString name;

    /**
    *  <p>The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) that is assigned to a GameLift game session queue resource and uniquely identifies it. ARNs are unique across all Regions. Format is <code>arn:aws:gamelift:&lt;region&gt;::gamesessionqueue/&lt;queue name&gt;</code>. In a GameLift game session queue ARN, the resource ID matches the <i>Name</i> value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameSessionQueueArn;

    /**
    *  <p>The maximum time, in seconds, that a new game session placement request remains in the queue. When a request exceeds this time, the game session placement changes to a <code>TIMED_OUT</code> status.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int timeoutInSeconds = 0;

    /**
    *  <p>A set of policies that act as a sliding cap on player latency. FleetIQ works to deliver low latency for most players in a game session. These policies ensure that no individual player can be placed into a game with unreasonably high latency. Use multiple policies to gradually relax latency requirements a step at a time. Multiple policies are applied based on their maximum allowed latency, starting with the lowest value. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FPlayerLatencyPolicy> playerLatencyPolicies;

    /**
    *  <p>A list of fleets and/or fleet aliases that can be used to fulfill game session placement requests in the queue. Destinations are identified by either a fleet ARN or a fleet alias ARN, and are listed in order of placement preference.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FGameSessionQueueDestination> destinations;

    /**
    *  <p>A list of locations where a queue is allowed to place new game sessions. Locations are specified in the form of AWS Region codes, such as <code>us-west-2</code>. If this parameter is not set, game sessions can be placed in any queue location. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FAWSGameLiftFilterConfiguration filterConfiguration;

    /**
    *  <p>Custom settings to use when prioritizing destinations and locations for game session placements. This configuration replaces the FleetIQ default prioritization process. Priority types that are not explicitly named will be automatically applied at the end of the prioritization process. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FAWSGameLiftPriorityConfiguration priorityConfiguration;

    /**
    *  <p> Information that is added to all events that are related to this game session queue. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString customEventData;

    /**
    *  <p>An SNS topic ARN that is set up to receive game session placement notifications. See <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/queue-notification.html"> Setting up notifications for game session placement</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString notificationTarget;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FGameSessionQueue &fromAWS(const Aws::GameLift::Model::GameSessionQueue &awsGameSessionQueue) {
        this->name = UTF8_TO_TCHAR(awsGameSessionQueue.GetName().c_str());

        this->gameSessionQueueArn = UTF8_TO_TCHAR(awsGameSessionQueue.GetGameSessionQueueArn().c_str());

        this->timeoutInSeconds = awsGameSessionQueue.GetTimeoutInSeconds();

        this->playerLatencyPolicies.Empty();
        for (const Aws::GameLift::Model::PlayerLatencyPolicy& elem : awsGameSessionQueue.GetPlayerLatencyPolicies()) {
            this->playerLatencyPolicies.Add(FPlayerLatencyPolicy().fromAWS(elem));
        }

        this->destinations.Empty();
        for (const Aws::GameLift::Model::GameSessionQueueDestination& elem : awsGameSessionQueue.GetDestinations()) {
            this->destinations.Add(FGameSessionQueueDestination().fromAWS(elem));
        }

        this->filterConfiguration = FAWSGameLiftFilterConfiguration().fromAWS(awsGameSessionQueue.GetFilterConfiguration());

        this->priorityConfiguration = FAWSGameLiftPriorityConfiguration().fromAWS(awsGameSessionQueue.GetPriorityConfiguration());

        this->customEventData = UTF8_TO_TCHAR(awsGameSessionQueue.GetCustomEventData().c_str());

        this->notificationTarget = UTF8_TO_TCHAR(awsGameSessionQueue.GetNotificationTarget().c_str());

        return *this;
    }
#endif
};
