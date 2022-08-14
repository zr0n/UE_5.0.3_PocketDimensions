/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreateGameServerGroupRequest.h"

#endif

#include "Model/LaunchTemplateSpecification.h"
#include "Model/InstanceDefinition.h"
#include "Model/GameServerGroupAutoScalingPolicy.h"
#include "Model/BalancingStrategy.h"
#include "Model/GameServerProtectionPolicy.h"
#include "Model/GameLiftTag.h"

#include "CreateGameServerGroupRequest.generated.h"

USTRUCT(BlueprintType)
struct FCreateGameServerGroupRequest {
GENERATED_BODY()

    /**
    *  <p>An identifier for the new game server group. This value is used to generate unique ARN identifiers for the EC2 Auto Scaling group and the GameLift FleetIQ game server group. The name must be unique per Region per AWS account.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerGroupName;

    /**
    *  <p>The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) for an IAM role that allows Amazon GameLift to access your EC2 Auto Scaling groups. The submitted role is validated to ensure that it contains the necessary permissions for game server groups.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString roleArn;

    /**
    *  <p>The minimum number of instances allowed in the EC2 Auto Scaling group. During autoscaling events, GameLift FleetIQ and EC2 do not scale down the group below this minimum. In production, this value should be set to at least 1.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int minSize = 0;

    /**
    *  <p>The maximum number of instances allowed in the EC2 Auto Scaling group. During autoscaling events, GameLift FleetIQ and EC2 do not scale up the group above this maximum.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int maxSize = 0;

    /**
    *  <p>The EC2 launch template that contains configuration settings and game server code to be deployed to all instances in the game server group. You can specify the template using either the template name or ID. For help with creating a launch template, see <a href="https://docs.aws.amazon.com/autoscaling/ec2/userguide/create-launch-template.html">Creating a Launch Template for an Auto Scaling Group</a> in the <i>Amazon EC2 Auto Scaling User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FLaunchTemplateSpecification launchTemplate;

    /**
    *  <p>A set of EC2 instance types to use when creating instances in the group. The instance definitions must specify at least two different instance types that are supported by GameLift FleetIQ. For more information on instance types, see <a href="https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/instance-types.html">EC2 Instance Types</a> in the <i>Amazon EC2 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FInstanceDefinition> instanceDefinitions;

    /**
    *  <p>Configuration settings to define a scaling policy for the Auto Scaling group that is optimized for game hosting. The scaling policy uses the metric "PercentUtilizedGameServers" to maintain a buffer of idle game servers that can immediately accommodate new games and players. Once the game server and Auto Scaling groups are created, you can update the scaling policy settings directly in Auto Scaling Groups.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FGameServerGroupAutoScalingPolicy autoScalingPolicy;

    /**
    *  <p>The fallback balancing method to use for the game server group when Spot instances in a Region become unavailable or are not viable for game hosting. Once triggered, this method remains active until Spot instances can once again be used. Method options include:</p> <ul> <li> <p>SPOT_ONLY -- If Spot instances are unavailable, the game server group provides no hosting capacity. No new instances are started, and the existing nonviable Spot instances are terminated (once current gameplay ends) and not replaced.</p> </li> <li> <p>SPOT_PREFERRED -- If Spot instances are unavailable, the game server group continues to provide hosting capacity by using On-Demand instances. Existing nonviable Spot instances are terminated (once current gameplay ends) and replaced with new On-Demand instances. </p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EAWSBalancingStrategy balancingStrategy = EAWSBalancingStrategy::NOT_SET;

    /**
    *  <p>A flag that indicates whether instances in the game server group are protected from early termination. Unprotected instances that have active game servers running may by terminated during a scale-down event, causing players to be dropped from the game. Protected instances cannot be terminated while there are active game servers running. An exception to this is Spot Instances, which may be terminated by AWS regardless of protection status. This property is set to NO_PROTECTION by default.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EAWSGameServerProtectionPolicy gameServerProtectionPolicy = EAWSGameServerProtectionPolicy::NOT_SET;

    /**
    *  <p>A list of virtual private cloud (VPC) subnets to use with instances in the game server group. By default, all GameLift FleetIQ-supported availability zones are used; this parameter allows you to specify VPCs that you've set up. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FString> vpcSubnets;

    /**
    *  <p>A list of labels to assign to the new game server group resource. Tags are developer-defined key-value pairs. Tagging AWS resources are useful for resource management, access management, and cost allocation. For more information, see <a href="https://docs.aws.amazon.com/general/latest/gr/aws_tagging.html"> Tagging AWS Resources</a> in the <i>AWS General Reference</i>. Once the resource is created, you can use <a>TagResource</a>, <a>UntagResource</a>, and <a>ListTagsForResource</a> to add, remove, and view tags. The maximum tag limit may be lower than stated. See the AWS General Reference for actual tagging limits.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FGameLiftTag> tags;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::CreateGameServerGroupRequest toAWS() const {
        Aws::GameLift::Model::CreateGameServerGroupRequest awsCreateGameServerGroupRequest;

		if (!(this->gameServerGroupName.IsEmpty())) {
            awsCreateGameServerGroupRequest.SetGameServerGroupName(TCHAR_TO_UTF8(*this->gameServerGroupName));
        }

		if (!(this->roleArn.IsEmpty())) {
            awsCreateGameServerGroupRequest.SetRoleArn(TCHAR_TO_UTF8(*this->roleArn));
        }

        if (!(this->minSize == 0)) {
            awsCreateGameServerGroupRequest.SetMinSize(this->minSize);
        }

        if (!(this->maxSize == 0)) {
            awsCreateGameServerGroupRequest.SetMaxSize(this->maxSize);
        }

        if (!(this->launchTemplate.IsEmpty())) {
            awsCreateGameServerGroupRequest.SetLaunchTemplate(this->launchTemplate.toAWS());
        }

        for (const FInstanceDefinition& elem : this->instanceDefinitions) {
            awsCreateGameServerGroupRequest.AddInstanceDefinitions(elem.toAWS());
        }

        if (!(this->autoScalingPolicy.IsEmpty())) {
            awsCreateGameServerGroupRequest.SetAutoScalingPolicy(this->autoScalingPolicy.toAWS());
        }

        switch(this->balancingStrategy) {
            case EAWSBalancingStrategy::SPOT_ONLY:
                awsCreateGameServerGroupRequest.SetBalancingStrategy(Aws::GameLift::Model::BalancingStrategy::SPOT_ONLY);
                break;
            case EAWSBalancingStrategy::SPOT_PREFERRED:
                awsCreateGameServerGroupRequest.SetBalancingStrategy(Aws::GameLift::Model::BalancingStrategy::SPOT_PREFERRED);
                break;
            case EAWSBalancingStrategy::ON_DEMAND_ONLY:
                awsCreateGameServerGroupRequest.SetBalancingStrategy(Aws::GameLift::Model::BalancingStrategy::ON_DEMAND_ONLY);
                break;
            default:
                break;
        }

        switch(this->gameServerProtectionPolicy) {
            case EAWSGameServerProtectionPolicy::NO_PROTECTION:
                awsCreateGameServerGroupRequest.SetGameServerProtectionPolicy(Aws::GameLift::Model::GameServerProtectionPolicy::NO_PROTECTION);
                break;
            case EAWSGameServerProtectionPolicy::FULL_PROTECTION:
                awsCreateGameServerGroupRequest.SetGameServerProtectionPolicy(Aws::GameLift::Model::GameServerProtectionPolicy::FULL_PROTECTION);
                break;
            default:
                break;
        }

        for (const FString& elem : this->vpcSubnets) {
            awsCreateGameServerGroupRequest.AddVpcSubnets(TCHAR_TO_UTF8(*elem));
        }

        for (const FGameLiftTag& elem : this->tags) {
            awsCreateGameServerGroupRequest.AddTags(elem.toAWS());
        }

        return awsCreateGameServerGroupRequest;
    }

    bool IsEmpty() const {
        return this->gameServerGroupName.IsEmpty() && this->roleArn.IsEmpty() && this->minSize == 0 && this->maxSize == 0 && this->launchTemplate.IsEmpty() && this->instanceDefinitions.Num() == 0 && this->autoScalingPolicy.IsEmpty() && balancingStrategy == EAWSBalancingStrategy::NOT_SET && gameServerProtectionPolicy == EAWSGameServerProtectionPolicy::NOT_SET && this->vpcSubnets.Num() == 0 && this->tags.Num() == 0;
    }
#endif
};
