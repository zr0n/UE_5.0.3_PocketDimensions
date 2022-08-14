/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/UpdateGameSessionQueueRequest.h"

#endif

#include "Model/PlayerLatencyPolicy.h"
#include "Model/GameSessionQueueDestination.h"
#include "Model/AWSGameLiftFilterConfiguration.h"
#include "Model/AWSGameLiftPriorityConfiguration.h"

#include "UpdateGameSessionQueueRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateGameSessionQueueRequest {
GENERATED_BODY()

    /**
    *  <p>A descriptive label that is associated with game session queue. Queue names must be unique within each Region. You can use either the queue ID or ARN value. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString name;

    /**
    *  <p>The maximum time, in seconds, that a new game session placement request remains in the queue. When a request exceeds this time, the game session placement changes to a <code>TIMED_OUT</code> status.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int timeoutInSeconds = 0;

    /**
    *  <p>A set of policies that act as a sliding cap on player latency. FleetIQ works to deliver low latency for most players in a game session. These policies ensure that no individual player can be placed into a game with unreasonably high latency. Use multiple policies to gradually relax latency requirements a step at a time. Multiple policies are applied based on their maximum allowed latency, starting with the lowest value. When updating policies, provide a complete collection of policies.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FPlayerLatencyPolicy> playerLatencyPolicies;

    /**
    *  <p>A list of fleets and/or fleet aliases that can be used to fulfill game session placement requests in the queue. Destinations are identified by either a fleet ARN or a fleet alias ARN, and are listed in order of placement preference. When updating this list, provide a complete list of destinations.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FGameSessionQueueDestination> destinations;

    /**
    *  <p>A list of locations where a queue is allowed to place new game sessions. Locations are specified in the form of AWS Region codes, such as <code>us-west-2</code>. If this parameter is not set, game sessions can be placed in any queue location. To remove an existing filter configuration, pass in an empty set.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FAWSGameLiftFilterConfiguration filterConfiguration;

    /**
    *  <p>Custom settings to use when prioritizing destinations and locations for game session placements. This configuration replaces the FleetIQ default prioritization process. Priority types that are not explicitly named will be automatically applied at the end of the prioritization process. To remove an existing priority configuration, pass in an empty set.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FAWSGameLiftPriorityConfiguration priorityConfiguration;

    /**
    *  <p> Information to be added to all events that are related to this game session queue. </p>
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
    Aws::GameLift::Model::UpdateGameSessionQueueRequest toAWS() const {
        Aws::GameLift::Model::UpdateGameSessionQueueRequest awsUpdateGameSessionQueueRequest;

        if (!(this->name.IsEmpty())) {
            awsUpdateGameSessionQueueRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        if (this->timeoutInSeconds != 0) {
            awsUpdateGameSessionQueueRequest.SetTimeoutInSeconds(this->timeoutInSeconds);
        }

        for (const FPlayerLatencyPolicy& elem : this->playerLatencyPolicies) {
            awsUpdateGameSessionQueueRequest.AddPlayerLatencyPolicies(elem.toAWS());
        }

        for (const FGameSessionQueueDestination& elem : this->destinations) {
            awsUpdateGameSessionQueueRequest.AddDestinations(elem.toAWS());
        }

        if (!(this->filterConfiguration.IsEmpty())) {
            awsUpdateGameSessionQueueRequest.SetFilterConfiguration(this->filterConfiguration.toAWS());
        }

        if (!(this->priorityConfiguration.IsEmpty())) {
            awsUpdateGameSessionQueueRequest.SetPriorityConfiguration(this->priorityConfiguration.toAWS());
        }

        if (!(this->customEventData.IsEmpty())) {
            awsUpdateGameSessionQueueRequest.SetCustomEventData(TCHAR_TO_UTF8(*this->customEventData));
        }

        if (!(this->notificationTarget.IsEmpty())) {
            awsUpdateGameSessionQueueRequest.SetNotificationTarget(TCHAR_TO_UTF8(*this->notificationTarget));
        }

        return awsUpdateGameSessionQueueRequest;
    }

    bool IsEmpty() const {
        return this->name.IsEmpty() && this->timeoutInSeconds == 0 && this->playerLatencyPolicies.Num() == 0 && this->destinations.Num() == 0 && this->filterConfiguration.IsEmpty() && this->priorityConfiguration.IsEmpty() && this->customEventData.IsEmpty() && this->notificationTarget.IsEmpty();
    }
#endif
};
