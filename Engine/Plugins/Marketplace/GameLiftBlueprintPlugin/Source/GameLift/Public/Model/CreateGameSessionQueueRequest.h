/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreateGameSessionQueueRequest.h"

#endif

#include "Model/PlayerLatencyPolicy.h"
#include "Model/GameSessionQueueDestination.h"
#include "Model/AWSGameLiftFilterConfiguration.h"
#include "Model/AWSGameLiftPriorityConfiguration.h"
#include "Model/GameLiftTag.h"

#include "CreateGameSessionQueueRequest.generated.h"

USTRUCT(BlueprintType)
struct FCreateGameSessionQueueRequest {
GENERATED_BODY()

    /**
    *  <p>A descriptive label that is associated with game session queue. Queue names must be unique within each Region.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString name;

    /**
    *  <p>The maximum time, in seconds, that a new game session placement request remains in the queue. When a request exceeds this time, the game session placement changes to a <code>TIMED_OUT</code> status.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int timeoutInSeconds = 0;

    /**
    *  <p>Collection of latency policies to apply when processing game sessions placement requests with player latency information. Multiple policies are evaluated in order of the maximum latency value, starting with the lowest latency values. With just one policy, it is enforced at the start of the game session placement for the duration period. With multiple policies, each policy is enforced consecutively for its duration period. For example, a queue might enforce a 60-second policy followed by a 120-second policy, and then no policy for the remainder of the placement. A player latency policy must set a value for MaximumIndividualPlayerLatencyMilliseconds; if none is set, this API requests will fail.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FPlayerLatencyPolicy> playerLatencyPolicies;

    /**
    *  <p>List of fleets that can be used to fulfill game session placement requests in the queue. Fleets are identified by either a fleet ARN or a fleet alias ARN. Destinations are listed in default preference order.</p>
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
    *  <p> Information to be added to all events that are related to this game session queue. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString customEventData;

    /**
    *  <p>An SNS topic ARN that is set up to receive game session placement notifications. See <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/queue-notification.html"> Setting up notifications for game session placement</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString notificationTarget;

    /**
    *  <p>A list of labels to assign to the new game session queue resource. Tags are developer-defined key-value pairs. Tagging AWS resources are useful for resource management, access management and cost allocation. For more information, see <a href="https://docs.aws.amazon.com/general/latest/gr/aws_tagging.html"> Tagging AWS Resources</a> in the <i>AWS General Reference</i>. Once the resource is created, you can use <a>TagResource</a>, <a>UntagResource</a>, and <a>ListTagsForResource</a> to add, remove, and view tags. The maximum tag limit may be lower than stated. See the AWS General Reference for actual tagging limits.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FGameLiftTag> tags;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::CreateGameSessionQueueRequest toAWS() const {
        Aws::GameLift::Model::CreateGameSessionQueueRequest awsCreateGameSessionQueueRequest;

        if (!(this->name.IsEmpty())) {
            awsCreateGameSessionQueueRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        if (this->timeoutInSeconds != 0) {
            awsCreateGameSessionQueueRequest.SetTimeoutInSeconds(this->timeoutInSeconds);
        }

        for (const FPlayerLatencyPolicy& elem : this->playerLatencyPolicies) {
            awsCreateGameSessionQueueRequest.AddPlayerLatencyPolicies(elem.toAWS());
        }

        for (const FGameSessionQueueDestination& elem : this->destinations) {
            awsCreateGameSessionQueueRequest.AddDestinations(elem.toAWS());
        }


        if (!(this->filterConfiguration.IsEmpty())) {
            awsCreateGameSessionQueueRequest.SetFilterConfiguration(this->filterConfiguration.toAWS());
        }

        if (!(this->priorityConfiguration.IsEmpty())) {
            awsCreateGameSessionQueueRequest.SetPriorityConfiguration(this->priorityConfiguration.toAWS());
        }

        if (!(this->customEventData.IsEmpty())) {
            awsCreateGameSessionQueueRequest.SetCustomEventData(TCHAR_TO_UTF8(*this->customEventData));
        }

        if (!(this->notificationTarget.IsEmpty())) {
            awsCreateGameSessionQueueRequest.SetNotificationTarget(TCHAR_TO_UTF8(*this->notificationTarget));
        }

        for (const FGameLiftTag& elem : this->tags) {
            awsCreateGameSessionQueueRequest.AddTags(elem.toAWS());
        }

        return awsCreateGameSessionQueueRequest;
    }

    bool IsEmpty() const {
        return this->name.IsEmpty() && this->timeoutInSeconds == 0 && this->playerLatencyPolicies.Num() == 0 && this->destinations.Num() == 0 && this->filterConfiguration.IsEmpty() && this->priorityConfiguration.IsEmpty() && this->customEventData.IsEmpty() && this->notificationTarget.IsEmpty() && this->tags.Num() == 0;
    }
#endif
};
