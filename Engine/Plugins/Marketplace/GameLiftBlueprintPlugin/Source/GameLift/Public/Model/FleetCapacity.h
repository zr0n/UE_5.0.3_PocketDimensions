/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/FleetCapacity.h"

#endif

#include "Model/EC2InstanceType.h"
#include "Model/EC2InstanceCounts.h"

#include "FleetCapacity.generated.h"

USTRUCT(BlueprintType)
struct FFleetCapacity {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the fleet associated with the location.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) that is assigned to a GameLift fleet resource and uniquely identifies it. ARNs are unique across all Regions. Format is <code>arn:aws:gamelift:&lt;region&gt;::fleet/fleet-a1234567-b8c9-0d1e-2fa3-b45c6d7e8912</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetArn;

    /**
    *  <p>The EC2 instance type that is used for all instances in a fleet. The instance type determines the computing resources in use, including CPU, memory, storage, and networking capacity. See <a href="http://aws.amazon.com/ec2/instance-types/">Amazon EC2 Instance Types</a> for detailed descriptions.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EEC2InstanceType instanceType = EEC2InstanceType::NOT_SET;

    /**
    *  <p>The current instance count and capacity settings for the fleet location. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FEC2InstanceCounts instanceCounts;

    /**
    *  <p>The fleet location for the instance count information, expressed as an AWS Region code, such as <code>us-west-2</code>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString location;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FFleetCapacity &fromAWS(const Aws::GameLift::Model::FleetCapacity &awsFleetCapacity) {
        this->fleetId = UTF8_TO_TCHAR(awsFleetCapacity.GetFleetId().c_str());

        this->fleetArn = UTF8_TO_TCHAR(awsFleetCapacity.GetFleetArn().c_str());

        switch(awsFleetCapacity.GetInstanceType()) {
            case Aws::GameLift::Model::EC2InstanceType::NOT_SET:
                this->instanceType = EEC2InstanceType::NOT_SET;
                break;
            case Aws::GameLift::Model::EC2InstanceType::t2_micro:
                this->instanceType = EEC2InstanceType::t2_micro;
                break;
            case Aws::GameLift::Model::EC2InstanceType::t2_small:
                this->instanceType = EEC2InstanceType::t2_small;
                break;
            case Aws::GameLift::Model::EC2InstanceType::t2_medium:
                this->instanceType = EEC2InstanceType::t2_medium;
                break;
            case Aws::GameLift::Model::EC2InstanceType::t2_large:
                this->instanceType = EEC2InstanceType::t2_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c3_large:
                this->instanceType = EEC2InstanceType::c3_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c3_xlarge:
                this->instanceType = EEC2InstanceType::c3_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c3_2xlarge:
                this->instanceType = EEC2InstanceType::c3_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c3_4xlarge:
                this->instanceType = EEC2InstanceType::c3_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c3_8xlarge:
                this->instanceType = EEC2InstanceType::c3_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c4_large:
                this->instanceType = EEC2InstanceType::c4_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c4_xlarge:
                this->instanceType = EEC2InstanceType::c4_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c4_2xlarge:
                this->instanceType = EEC2InstanceType::c4_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c4_4xlarge:
                this->instanceType = EEC2InstanceType::c4_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c4_8xlarge:
                this->instanceType = EEC2InstanceType::c4_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5_large:
                this->instanceType = EEC2InstanceType::c5_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5_xlarge:
                this->instanceType = EEC2InstanceType::c5_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5_2xlarge:
                this->instanceType = EEC2InstanceType::c5_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5_4xlarge:
                this->instanceType = EEC2InstanceType::c5_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5_9xlarge:
                this->instanceType = EEC2InstanceType::c5_9xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5_12xlarge:
                this->instanceType = EEC2InstanceType::c5_12xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5_18xlarge:
                this->instanceType = EEC2InstanceType::c5_18xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5_24xlarge:
                this->instanceType = EEC2InstanceType::c5_24xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5a_large:
                this->instanceType = EEC2InstanceType::c5a_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5a_xlarge:
                this->instanceType = EEC2InstanceType::c5a_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5a_2xlarge:
                this->instanceType = EEC2InstanceType::c5a_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5a_4xlarge:
                this->instanceType = EEC2InstanceType::c5a_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5a_8xlarge:
                this->instanceType = EEC2InstanceType::c5a_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5a_12xlarge:
                this->instanceType = EEC2InstanceType::c5a_12xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5a_16xlarge:
                this->instanceType = EEC2InstanceType::c5a_16xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5a_24xlarge:
                this->instanceType = EEC2InstanceType::c5a_24xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r3_large:
                this->instanceType = EEC2InstanceType::r3_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r3_xlarge:
                this->instanceType = EEC2InstanceType::r3_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r3_2xlarge:
                this->instanceType = EEC2InstanceType::r3_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r3_4xlarge:
                this->instanceType = EEC2InstanceType::r3_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r3_8xlarge:
                this->instanceType = EEC2InstanceType::r3_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r4_large:
                this->instanceType = EEC2InstanceType::r4_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r4_xlarge:
                this->instanceType = EEC2InstanceType::r4_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r4_2xlarge:
                this->instanceType = EEC2InstanceType::r4_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r4_4xlarge:
                this->instanceType = EEC2InstanceType::r4_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r4_8xlarge:
                this->instanceType = EEC2InstanceType::r4_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r4_16xlarge:
                this->instanceType = EEC2InstanceType::r4_16xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5_large:
                this->instanceType = EEC2InstanceType::r5_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5_xlarge:
                this->instanceType = EEC2InstanceType::r5_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5_2xlarge:
                this->instanceType = EEC2InstanceType::r5_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5_4xlarge:
                this->instanceType = EEC2InstanceType::r5_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5_8xlarge:
                this->instanceType = EEC2InstanceType::r5_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5_12xlarge:
                this->instanceType = EEC2InstanceType::r5_12xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5_16xlarge:
                this->instanceType = EEC2InstanceType::r5_16xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5_24xlarge:
                this->instanceType = EEC2InstanceType::r5_24xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5a_large:
                this->instanceType = EEC2InstanceType::r5a_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5a_xlarge:
                this->instanceType = EEC2InstanceType::r5a_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5a_2xlarge:
                this->instanceType = EEC2InstanceType::r5a_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5a_4xlarge:
                this->instanceType = EEC2InstanceType::r5a_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5a_8xlarge:
                this->instanceType = EEC2InstanceType::r5a_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5a_12xlarge:
                this->instanceType = EEC2InstanceType::r5a_12xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5a_16xlarge:
                this->instanceType = EEC2InstanceType::r5a_16xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5a_24xlarge:
                this->instanceType = EEC2InstanceType::r5a_24xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m3_medium:
                this->instanceType = EEC2InstanceType::m3_medium;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m3_large:
                this->instanceType = EEC2InstanceType::m3_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m3_xlarge:
                this->instanceType = EEC2InstanceType::m3_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m3_2xlarge:
                this->instanceType = EEC2InstanceType::m3_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m4_large:
                this->instanceType = EEC2InstanceType::m4_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m4_xlarge:
                this->instanceType = EEC2InstanceType::m4_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m4_2xlarge:
                this->instanceType = EEC2InstanceType::m4_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m4_4xlarge:
                this->instanceType = EEC2InstanceType::m4_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m4_10xlarge:
                this->instanceType = EEC2InstanceType::m4_10xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5_large:
                this->instanceType = EEC2InstanceType::m5_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5_xlarge:
                this->instanceType = EEC2InstanceType::m5_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5_2xlarge:
                this->instanceType = EEC2InstanceType::m5_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5_4xlarge:
                this->instanceType = EEC2InstanceType::m5_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5_8xlarge:
                this->instanceType = EEC2InstanceType::m5_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5_12xlarge:
                this->instanceType = EEC2InstanceType::m5_12xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5_16xlarge:
                this->instanceType = EEC2InstanceType::m5_16xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5_24xlarge:
                this->instanceType = EEC2InstanceType::m5_24xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5a_large:
                this->instanceType = EEC2InstanceType::m5a_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5a_xlarge:
                this->instanceType = EEC2InstanceType::m5a_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5a_2xlarge:
                this->instanceType = EEC2InstanceType::m5a_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5a_4xlarge:
                this->instanceType = EEC2InstanceType::m5a_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5a_8xlarge:
                this->instanceType = EEC2InstanceType::m5a_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5a_12xlarge:
                this->instanceType = EEC2InstanceType::m5a_12xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5a_16xlarge:
                this->instanceType = EEC2InstanceType::m5a_16xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5a_24xlarge:
                this->instanceType = EEC2InstanceType::m5a_24xlarge;
                break;
            default:
                this->instanceType = EEC2InstanceType::NOT_SET;
                break;
        }

        this->instanceCounts = FEC2InstanceCounts().fromAWS(awsFleetCapacity.GetInstanceCounts());

        this->location = UTF8_TO_TCHAR(awsFleetCapacity.GetLocation().c_str());

        return *this;
    }
#endif
};
