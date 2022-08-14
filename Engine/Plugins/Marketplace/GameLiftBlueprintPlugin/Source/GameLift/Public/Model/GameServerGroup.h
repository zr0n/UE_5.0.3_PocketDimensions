/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/GameServerGroup.h"

#endif

#include "Model/InstanceDefinition.h"
#include "Model/BalancingStrategy.h"
#include "Model/GameServerProtectionPolicy.h"
#include "Model/GameServerGroupStatus.h"
#include "Model/GameServerGroupAction.h"

#include "GameServerGroup.generated.h"

USTRUCT(BlueprintType)
struct FGameServerGroup {
    GENERATED_BODY()

    /**
    *  <p>A developer-defined identifier for the game server group. The name is unique per Region per AWS account.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerGroupName;

    /**
    *  <p>A generated unique ID for the game server group.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerGroupArn;

    /**
    *  <p>The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) for an IAM role that allows Amazon GameLift to access your EC2 Auto Scaling groups. The submitted role is validated to ensure that it contains the necessary permissions for game server groups.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString roleArn;

    /**
    *  <p>The set of EC2 instance types that GameLift FleetIQ can use when rebalancing and autoscaling instances in the group. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FInstanceDefinition> instanceDefinitions;

    /**
    *  <p>The fallback balancing method to use for the game server group when Spot instances in a Region become unavailable or are not viable for game hosting. Once triggered, this method remains active until Spot instances can once again be used. Method options include:</p> <ul> <li> <p>SPOT_ONLY -- If Spot instances are unavailable, the game server group provides no hosting capacity. No new instances are started, and the existing nonviable Spot instances are terminated (once current gameplay ends) and not replaced.</p> </li> <li> <p>SPOT_PREFERRED -- If Spot instances are unavailable, the game server group continues to provide hosting capacity by using On-Demand instances. Existing nonviable Spot instances are terminated (once current gameplay ends) and replaced with new On-Demand instances. </p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EAWSBalancingStrategy balancingStrategy = EAWSBalancingStrategy::NOT_SET;

    /**
    *  <p>A flag that indicates whether instances in the game server group are protected from early termination. Unprotected instances that have active game servers running may be terminated during a scale-down event, causing players to be dropped from the game. Protected instances cannot be terminated while there are active game servers running except in the event of a forced game server group deletion (see <a>DeleteGameServerGroup</a>). An exception to this is Spot Instances, which may be terminated by AWS regardless of protection status.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EAWSGameServerProtectionPolicy gameServerProtectionPolicy = EAWSGameServerProtectionPolicy::NOT_SET;

    /**
    *  <p>A generated unique ID for the EC2 Auto Scaling group with is associated with this game server group.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString autoScalingGroupArn;

    /**
    *  <p>The current status of the game server group. Possible statuses include:</p> <ul> <li> <p> NEW - GameLift FleetIQ has validated the <code>CreateGameServerGroup()</code> request. </p> </li> <li> <p>ACTIVATING - GameLift FleetIQ is setting up a game server group, which includes creating an autoscaling group in your AWS account. </p> </li> <li> <p>ACTIVE - The game server group has been successfully created. </p> </li> <li> <p>DELETE_SCHEDULED - A request to delete the game server group has been received. </p> </li> <li> <p>DELETING - GameLift FleetIQ has received a valid <code>DeleteGameServerGroup()</code> request and is processing it. GameLift FleetIQ must first complete and release hosts before it deletes the autoscaling group and the game server group. </p> </li> <li> <p>DELETED - The game server group has been successfully deleted. </p> </li> <li> <p>ERROR - The asynchronous processes of activating or deleting a game server group has failed, resulting in an error state.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EAWSGameServerGroupStatus status = EAWSGameServerGroupStatus::NOT_SET;

    /**
    *  <p>Additional information about the current game server group status. This information may provide additional insight on groups that in ERROR status.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString statusReason;

    /**
    *  <p>A list of activities that are currently suspended for this game server group. If this property is empty, all activities are occurring.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<EAWSGameServerGroupAction> suspendedActions;

    /**
    *  <p>A time stamp indicating when this data object was created. Format is a number expressed in Unix time as milliseconds (for example "1469498468.057").</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FDateTime creationTime;

    /**
    *  <p>A time stamp indicating when this game server group was last updated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FDateTime lastUpdatedTime;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FGameServerGroup &fromAWS(const Aws::GameLift::Model::GameServerGroup &awsGameServerGroup) {
        this->gameServerGroupName = UTF8_TO_TCHAR(awsGameServerGroup.GetGameServerGroupName().c_str());

        this->gameServerGroupArn = UTF8_TO_TCHAR(awsGameServerGroup.GetGameServerGroupArn().c_str());

        this->roleArn = UTF8_TO_TCHAR(awsGameServerGroup.GetRoleArn().c_str());

        this->instanceDefinitions.Empty();
        for (const Aws::GameLift::Model::InstanceDefinition& elem : awsGameServerGroup.GetInstanceDefinitions()) {
            this->instanceDefinitions.Add(FInstanceDefinition().fromAWS(elem));
        }

        switch(awsGameServerGroup.GetBalancingStrategy()) {
            case Aws::GameLift::Model::BalancingStrategy::NOT_SET:
                this->balancingStrategy = EAWSBalancingStrategy::NOT_SET;
                break;
            case Aws::GameLift::Model::BalancingStrategy::SPOT_ONLY:
                this->balancingStrategy = EAWSBalancingStrategy::SPOT_ONLY;
                break;
            case Aws::GameLift::Model::BalancingStrategy::SPOT_PREFERRED:
                this->balancingStrategy = EAWSBalancingStrategy::SPOT_PREFERRED;
                break;
            case Aws::GameLift::Model::BalancingStrategy::ON_DEMAND_ONLY:
                this->balancingStrategy = EAWSBalancingStrategy::ON_DEMAND_ONLY;
                break;
            default:
                this->balancingStrategy = EAWSBalancingStrategy::NOT_SET;
                break;
        }

        switch(awsGameServerGroup.GetGameServerProtectionPolicy()) {
            case Aws::GameLift::Model::GameServerProtectionPolicy::NOT_SET:
                this->gameServerProtectionPolicy = EAWSGameServerProtectionPolicy::NOT_SET;
                break;
            case Aws::GameLift::Model::GameServerProtectionPolicy::NO_PROTECTION:
                this->gameServerProtectionPolicy = EAWSGameServerProtectionPolicy::NO_PROTECTION;
                break;
            case Aws::GameLift::Model::GameServerProtectionPolicy::FULL_PROTECTION:
                this->gameServerProtectionPolicy = EAWSGameServerProtectionPolicy::FULL_PROTECTION;
                break;
            default:
                this->gameServerProtectionPolicy = EAWSGameServerProtectionPolicy::NOT_SET;
                break;
        }

        this->autoScalingGroupArn = UTF8_TO_TCHAR(awsGameServerGroup.GetAutoScalingGroupArn().c_str());

        switch(awsGameServerGroup.GetStatus()) {
            case Aws::GameLift::Model::GameServerGroupStatus::NOT_SET:
                this->status = EAWSGameServerGroupStatus::NOT_SET;
                break;
            case Aws::GameLift::Model::GameServerGroupStatus::NEW_:
                this->status = EAWSGameServerGroupStatus::NEW_;
                break;
            case Aws::GameLift::Model::GameServerGroupStatus::ACTIVATING:
                this->status = EAWSGameServerGroupStatus::ACTIVATING;
                break;
            case Aws::GameLift::Model::GameServerGroupStatus::ACTIVE:
                this->status = EAWSGameServerGroupStatus::ACTIVE;
                break;
            case Aws::GameLift::Model::GameServerGroupStatus::DELETE_SCHEDULED:
                this->status = EAWSGameServerGroupStatus::DELETE_SCHEDULED;
                break;
            case Aws::GameLift::Model::GameServerGroupStatus::DELETING:
                this->status = EAWSGameServerGroupStatus::DELETING;
                break;
            case Aws::GameLift::Model::GameServerGroupStatus::DELETED:
                this->status = EAWSGameServerGroupStatus::DELETED;
                break;
            case Aws::GameLift::Model::GameServerGroupStatus::ERROR_:
                this->status = EAWSGameServerGroupStatus::ERROR_;
                break;
            default:
                this->status = EAWSGameServerGroupStatus::NOT_SET;
                break;
        }

        this->statusReason = UTF8_TO_TCHAR(awsGameServerGroup.GetStatusReason().c_str());

        this->suspendedActions.Empty();
        for (const Aws::GameLift::Model::GameServerGroupAction& elem : awsGameServerGroup.GetSuspendedActions()) {
            switch(elem) {
                case Aws::GameLift::Model::GameServerGroupAction::NOT_SET:
                    this->suspendedActions.Add(EAWSGameServerGroupAction::NOT_SET);
                    break;
                case Aws::GameLift::Model::GameServerGroupAction::REPLACE_INSTANCE_TYPES:
                    this->suspendedActions.Add(EAWSGameServerGroupAction::REPLACE_INSTANCE_TYPES);
                    break;
                default:
                    this->suspendedActions.Add(EAWSGameServerGroupAction::NOT_SET);
                    break;
		    };
        }

        this->creationTime = FDateTime(1970, 1, 1) + FTimespan(awsGameServerGroup.GetCreationTime().Millis() * ETimespan::TicksPerMillisecond);

        this->lastUpdatedTime = FDateTime(1970, 1, 1) + FTimespan(awsGameServerGroup.GetLastUpdatedTime().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
