/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/InstanceDefinition.h"

#endif

#include "Model/GameServerGroupInstanceType.h"

#include "InstanceDefinition.generated.h"

USTRUCT(BlueprintType)
struct FInstanceDefinition {
GENERATED_BODY()

    /**
    *  <p>An EC2 instance type designation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EAWSGameServerGroupInstanceType instanceType = EAWSGameServerGroupInstanceType::NOT_SET;

    /**
    *  <p>Instance weighting that indicates how much this instance type contributes to the total capacity of a game server group. Instance weights are used by GameLift FleetIQ to calculate the instance type's cost per unit hour and better identify the most cost-effective options. For detailed information on weighting instance capacity, see <a href="https://docs.aws.amazon.com/autoscaling/ec2/userguide/asg-instance-weighting.html">Instance Weighting</a> in the <i>Amazon EC2 Auto Scaling User Guide</i>. Default value is "1".</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString weightedCapacity;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::InstanceDefinition toAWS() const {
        Aws::GameLift::Model::InstanceDefinition awsInstanceDefinition;

        switch(this->instanceType) {
            case EAWSGameServerGroupInstanceType::c4_large:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::c4_large);
                break;
            case EAWSGameServerGroupInstanceType::c4_xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::c4_xlarge);
                break;
            case EAWSGameServerGroupInstanceType::c4_2xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::c4_2xlarge);
                break;
            case EAWSGameServerGroupInstanceType::c4_4xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::c4_4xlarge);
                break;
            case EAWSGameServerGroupInstanceType::c4_8xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::c4_8xlarge);
                break;
            case EAWSGameServerGroupInstanceType::c5_large:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::c5_large);
                break;
            case EAWSGameServerGroupInstanceType::c5_xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::c5_xlarge);
                break;
            case EAWSGameServerGroupInstanceType::c5_2xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::c5_2xlarge);
                break;
            case EAWSGameServerGroupInstanceType::c5_4xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::c5_4xlarge);
                break;
            case EAWSGameServerGroupInstanceType::c5_9xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::c5_9xlarge);
                break;
            case EAWSGameServerGroupInstanceType::c5_12xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::c5_12xlarge);
                break;
            case EAWSGameServerGroupInstanceType::c5_18xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::c5_18xlarge);
                break;
            case EAWSGameServerGroupInstanceType::c5_24xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::c5_24xlarge);
                break;
            case EAWSGameServerGroupInstanceType::c5a_large:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::c5a_large);
                break;
            case EAWSGameServerGroupInstanceType::c5a_xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::c5a_xlarge);
                break;
            case EAWSGameServerGroupInstanceType::c5a_2xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::c5a_2xlarge);
                break;
            case EAWSGameServerGroupInstanceType::c5a_4xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::c5a_4xlarge);
                break;
            case EAWSGameServerGroupInstanceType::c5a_8xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::c5a_8xlarge);
                break;
            case EAWSGameServerGroupInstanceType::c5a_12xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::c5a_12xlarge);
                break;
            case EAWSGameServerGroupInstanceType::c5a_16xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::c5a_16xlarge);
                break;
            case EAWSGameServerGroupInstanceType::c5a_24xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::c5a_24xlarge);
                break;
            case EAWSGameServerGroupInstanceType::r4_large:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::r4_large);
                break;
            case EAWSGameServerGroupInstanceType::r4_xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::r4_xlarge);
                break;
            case EAWSGameServerGroupInstanceType::r4_2xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::r4_2xlarge);
                break;
            case EAWSGameServerGroupInstanceType::r4_4xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::r4_4xlarge);
                break;
            case EAWSGameServerGroupInstanceType::r4_8xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::r4_8xlarge);
                break;
            case EAWSGameServerGroupInstanceType::r4_16xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::r4_16xlarge);
                break;
            case EAWSGameServerGroupInstanceType::r5_large:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::r5_large);
                break;
            case EAWSGameServerGroupInstanceType::r5_xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::r5_xlarge);
                break;
            case EAWSGameServerGroupInstanceType::r5_2xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::r5_2xlarge);
                break;
            case EAWSGameServerGroupInstanceType::r5_4xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::r5_4xlarge);
                break;
            case EAWSGameServerGroupInstanceType::r5_8xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::r5_8xlarge);
                break;
            case EAWSGameServerGroupInstanceType::r5_12xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::r5_12xlarge);
                break;
            case EAWSGameServerGroupInstanceType::r5_16xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::r5_16xlarge);
                break;
            case EAWSGameServerGroupInstanceType::r5_24xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::r5_24xlarge);
                break;
            case EAWSGameServerGroupInstanceType::r5a_large:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::r5a_large);
                break;
            case EAWSGameServerGroupInstanceType::r5a_xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::r5a_xlarge);
                break;
            case EAWSGameServerGroupInstanceType::r5a_2xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::r5a_2xlarge);
                break;
            case EAWSGameServerGroupInstanceType::r5a_4xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::r5a_4xlarge);
                break;
            case EAWSGameServerGroupInstanceType::r5a_8xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::r5a_8xlarge);
                break;
            case EAWSGameServerGroupInstanceType::r5a_12xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::r5a_12xlarge);
                break;
            case EAWSGameServerGroupInstanceType::r5a_16xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::r5a_16xlarge);
                break;
            case EAWSGameServerGroupInstanceType::r5a_24xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::r5a_24xlarge);
                break;
            case EAWSGameServerGroupInstanceType::m4_large:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::m4_large);
                break;
            case EAWSGameServerGroupInstanceType::m4_xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::m4_xlarge);
                break;
            case EAWSGameServerGroupInstanceType::m4_2xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::m4_2xlarge);
                break;
            case EAWSGameServerGroupInstanceType::m4_4xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::m4_4xlarge);
                break;
            case EAWSGameServerGroupInstanceType::m4_10xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::m4_10xlarge);
                break;
            case EAWSGameServerGroupInstanceType::m5_large:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::m5_large);
                break;
            case EAWSGameServerGroupInstanceType::m5_xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::m5_xlarge);
                break;
            case EAWSGameServerGroupInstanceType::m5_2xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::m5_2xlarge);
                break;
            case EAWSGameServerGroupInstanceType::m5_4xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::m5_4xlarge);
                break;
            case EAWSGameServerGroupInstanceType::m5_8xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::m5_8xlarge);
                break;
            case EAWSGameServerGroupInstanceType::m5_12xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::m5_12xlarge);
                break;
            case EAWSGameServerGroupInstanceType::m5_16xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::m5_16xlarge);
                break;
            case EAWSGameServerGroupInstanceType::m5_24xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::m5_24xlarge);
                break;
            case EAWSGameServerGroupInstanceType::m5a_large:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::m5a_large);
                break;
            case EAWSGameServerGroupInstanceType::m5a_xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::m5a_xlarge);
                break;
            case EAWSGameServerGroupInstanceType::m5a_2xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::m5a_2xlarge);
                break;
            case EAWSGameServerGroupInstanceType::m5a_4xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::m5a_4xlarge);
                break;
            case EAWSGameServerGroupInstanceType::m5a_8xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::m5a_8xlarge);
                break;
            case EAWSGameServerGroupInstanceType::m5a_12xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::m5a_12xlarge);
                break;
            case EAWSGameServerGroupInstanceType::m5a_16xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::m5a_16xlarge);
                break;
            case EAWSGameServerGroupInstanceType::m5a_24xlarge:
                awsInstanceDefinition.SetInstanceType(Aws::GameLift::Model::GameServerGroupInstanceType::m5a_24xlarge);
                break;
            default:
                break;
        }

		if (!(this->weightedCapacity.IsEmpty())) {
            awsInstanceDefinition.SetWeightedCapacity(TCHAR_TO_UTF8(*this->weightedCapacity));
        }

        return awsInstanceDefinition;
    }

    bool IsEmpty() const {
        return this->instanceType == EAWSGameServerGroupInstanceType::NOT_SET && this->weightedCapacity.IsEmpty();
    }

    FInstanceDefinition &fromAWS(const Aws::GameLift::Model::InstanceDefinition &awsInstanceDefinition) {
        switch(awsInstanceDefinition.GetInstanceType()) {
            case Aws::GameLift::Model::GameServerGroupInstanceType::NOT_SET:
                this->instanceType = EAWSGameServerGroupInstanceType::NOT_SET;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::c4_large:
                this->instanceType = EAWSGameServerGroupInstanceType::c4_large;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::c4_xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::c4_xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::c4_2xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::c4_2xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::c4_4xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::c4_4xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::c4_8xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::c4_8xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::c5_large:
                this->instanceType = EAWSGameServerGroupInstanceType::c5_large;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::c5_xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::c5_xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::c5_2xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::c5_2xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::c5_4xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::c5_4xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::c5_9xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::c5_9xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::c5_12xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::c5_12xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::c5_18xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::c5_18xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::c5_24xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::c5_24xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::c5a_large:
                this->instanceType = EAWSGameServerGroupInstanceType::c5a_large;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::c5a_xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::c5a_xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::c5a_2xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::c5a_2xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::c5a_4xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::c5a_4xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::c5a_8xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::c5a_8xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::c5a_12xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::c5a_12xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::c5a_16xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::c5a_16xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::c5a_24xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::c5a_24xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::r4_large:
                this->instanceType = EAWSGameServerGroupInstanceType::r4_large;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::r4_xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::r4_xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::r4_2xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::r4_2xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::r4_4xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::r4_4xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::r4_8xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::r4_8xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::r4_16xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::r4_16xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::r5_large:
                this->instanceType = EAWSGameServerGroupInstanceType::r5_large;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::r5_xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::r5_xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::r5_2xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::r5_2xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::r5_4xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::r5_4xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::r5_8xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::r5_8xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::r5_12xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::r5_12xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::r5_16xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::r5_16xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::r5_24xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::r5_24xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::r5a_large:
                this->instanceType = EAWSGameServerGroupInstanceType::r5a_large;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::r5a_xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::r5a_xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::r5a_2xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::r5a_2xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::r5a_4xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::r5a_4xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::r5a_8xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::r5a_8xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::r5a_12xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::r5a_12xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::r5a_16xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::r5a_16xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::r5a_24xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::r5a_24xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::m4_large:
                this->instanceType = EAWSGameServerGroupInstanceType::m4_large;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::m4_xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::m4_xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::m4_2xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::m4_2xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::m4_4xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::m4_4xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::m4_10xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::m4_10xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::m5_large:
                this->instanceType = EAWSGameServerGroupInstanceType::m5_large;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::m5_xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::m5_xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::m5_2xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::m5_2xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::m5_4xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::m5_4xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::m5_8xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::m5_8xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::m5_12xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::m5_12xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::m5_16xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::m5_16xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::m5_24xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::m5_24xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::m5a_large:
                this->instanceType = EAWSGameServerGroupInstanceType::m5a_large;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::m5a_xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::m5a_xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::m5a_2xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::m5a_2xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::m5a_4xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::m5a_4xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::m5a_8xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::m5a_8xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::m5a_12xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::m5a_12xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::m5a_16xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::m5a_16xlarge;
                break;
            case Aws::GameLift::Model::GameServerGroupInstanceType::m5a_24xlarge:
                this->instanceType = EAWSGameServerGroupInstanceType::m5a_24xlarge;
                break;
            default:
                this->instanceType = EAWSGameServerGroupInstanceType::NOT_SET;
                break;
        }

        this->weightedCapacity = UTF8_TO_TCHAR(awsInstanceDefinition.GetWeightedCapacity().c_str());

        return *this;
    }
#endif
};
