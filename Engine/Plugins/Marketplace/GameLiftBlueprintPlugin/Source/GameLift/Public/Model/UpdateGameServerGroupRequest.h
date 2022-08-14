/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/UpdateGameServerGroupRequest.h"

#endif

#include "Model/InstanceDefinition.h"
#include "Model/GameServerProtectionPolicy.h"
#include "Model/BalancingStrategy.h"

#include "UpdateGameServerGroupRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateGameServerGroupRequest {
    GENERATED_BODY()

    /**
    *  <p>The unique identifier of the game server group to update. Use either the <a>GameServerGroup</a> name or ARN value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerGroupName;

    /**
    *  <p>The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) for an IAM role that allows Amazon GameLift to access your EC2 Auto Scaling groups. The submitted role is validated to ensure that it contains the necessary permissions for game server groups.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString roleArn;

    /**
    *  <p>An updated list of EC2 instance types to use when creating instances in the group. The instance definition must specify instance types that are supported by GameLift FleetIQ, and must include at least two instance types. This updated list replaces the entire current list of instance definitions for the game server group. For more information on instance types, see <a href="https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/instance-types.html">EC2 Instance Types</a> in the <i>Amazon EC2 User Guide</i>..</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FInstanceDefinition> instanceDefinitions;

    /**
    *  <p>A flag that indicates whether instances in the game server group are protected from early termination. Unprotected instances that have active game servers running may by terminated during a scale-down event, causing players to be dropped from the game. Protected instances cannot be terminated while there are active game servers running. An exception to this is Spot Instances, which may be terminated by AWS regardless of protection status. This property is set to NO_PROTECTION by default.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EAWSGameServerProtectionPolicy gameServerProtectionPolicy = EAWSGameServerProtectionPolicy::NOT_SET;

    /**
    *  <p>The fallback balancing method to use for the game server group when Spot instances in a Region become unavailable or are not viable for game hosting. Once triggered, this method remains active until Spot instances can once again be used. Method options include:</p> <ul> <li> <p>SPOT_ONLY -- If Spot instances are unavailable, the game server group provides no hosting capacity. No new instances are started, and the existing nonviable Spot instances are terminated (once current gameplay ends) and not replaced.</p> </li> <li> <p>SPOT_PREFERRED -- If Spot instances are unavailable, the game server group continues to provide hosting capacity by using On-Demand instances. Existing nonviable Spot instances are terminated (once current gameplay ends) and replaced with new On-Demand instances. </p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EAWSBalancingStrategy balancingStrategy = EAWSBalancingStrategy::NOT_SET;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::UpdateGameServerGroupRequest toAWS() const {
        Aws::GameLift::Model::UpdateGameServerGroupRequest awsUpdateGameServerGroupRequest;

		if (!(this->gameServerGroupName.IsEmpty())) {
            awsUpdateGameServerGroupRequest.SetGameServerGroupName(TCHAR_TO_UTF8(*this->gameServerGroupName));
        }

		if (!(this->roleArn.IsEmpty())) {
            awsUpdateGameServerGroupRequest.SetRoleArn(TCHAR_TO_UTF8(*this->roleArn));
        }

        for (const FInstanceDefinition& elem : this->instanceDefinitions) {
            awsUpdateGameServerGroupRequest.AddInstanceDefinitions(elem.toAWS());
        }

        switch(this->gameServerProtectionPolicy) {
            case EAWSGameServerProtectionPolicy::NO_PROTECTION:
                awsUpdateGameServerGroupRequest.SetGameServerProtectionPolicy(Aws::GameLift::Model::GameServerProtectionPolicy::NO_PROTECTION);
                break;
            case EAWSGameServerProtectionPolicy::FULL_PROTECTION:
                awsUpdateGameServerGroupRequest.SetGameServerProtectionPolicy(Aws::GameLift::Model::GameServerProtectionPolicy::FULL_PROTECTION);
                break;
            default:
                break;
            }

        switch(this->balancingStrategy) {
            case EAWSBalancingStrategy::SPOT_ONLY:
                awsUpdateGameServerGroupRequest.SetBalancingStrategy(Aws::GameLift::Model::BalancingStrategy::SPOT_ONLY);
                break;
            case EAWSBalancingStrategy::SPOT_PREFERRED:
                awsUpdateGameServerGroupRequest.SetBalancingStrategy(Aws::GameLift::Model::BalancingStrategy::SPOT_PREFERRED);
                break;
            case EAWSBalancingStrategy::ON_DEMAND_ONLY:
                awsUpdateGameServerGroupRequest.SetBalancingStrategy(Aws::GameLift::Model::BalancingStrategy::ON_DEMAND_ONLY);
                break;
            default:
                break;
            }

        return awsUpdateGameServerGroupRequest;
    }

    bool IsEmpty() const {
        return this->gameServerGroupName.IsEmpty() && this->roleArn.IsEmpty() && this->instanceDefinitions.Num() == 0 && gameServerProtectionPolicy == EAWSGameServerProtectionPolicy::NOT_SET && balancingStrategy == EAWSBalancingStrategy::NOT_SET;
    }
#endif
};
