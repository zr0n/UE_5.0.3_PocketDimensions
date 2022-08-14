/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/Instance.h"

#endif

#include "Model/OperatingSystem.h"
#include "Model/EC2InstanceType.h"
#include "Model/InstanceStatus.h"

#include "Instance.generated.h"

USTRUCT(BlueprintType)
struct FInstance {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the fleet that the instance is in.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) that is assigned to a GameLift fleet resource and uniquely identifies it. ARNs are unique across all Regions. Format is <code>arn:aws:gamelift:&lt;region&gt;::fleet/fleet-a1234567-b8c9-0d1e-2fa3-b45c6d7e8912</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetArn;

    /**
    *  <p>A unique identifier for the instance.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString instanceId;

    /**
    *  <p>IP address that is assigned to the instance.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString ipAddress;

    /**
    *  <p>The DNS identifier assigned to the instance that is running the game session. Values have the following format:</p> <ul> <li> <p>TLS-enabled fleets: <code>&lt;unique identifier&gt;.&lt;region identifier&gt;.amazongamelift.com</code>.</p> </li> <li> <p>Non-TLS-enabled fleets: <code>ec2-&lt;unique identifier&gt;.compute.amazonaws.com</code>. (See <a href="https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/using-instance-addressing.html#concepts-public-addresses">Amazon EC2 Instance IP Addressing</a>.)</p> </li> </ul> <p>When connecting to a game session that is running on a TLS-enabled fleet, you must use the DNS name, not the IP address.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString dnsName;

    /**
    *  <p>Operating system that is running on this instance. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EOperatingSystem operatingSystem = EOperatingSystem::NOT_SET;

    /**
    *  <p>EC2 instance type that defines the computing resources of this instance. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EEC2InstanceType type = EEC2InstanceType::NOT_SET;

    /**
    *  <p>Current status of the instance. Possible statuses include the following:</p> <ul> <li> <p> <b>PENDING</b> -- The instance is in the process of being created and launching server processes as defined in the fleet's run-time configuration. </p> </li> <li> <p> <b>ACTIVE</b> -- The instance has been successfully created and at least one server process has successfully launched and reported back to GameLift that it is ready to host a game session. The instance is now considered ready to host game sessions. </p> </li> <li> <p> <b>TERMINATING</b> -- The instance is in the process of shutting down. This may happen to reduce capacity during a scaling down event or to recycle resources in the event of a problem.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EInstanceStatus status = EInstanceStatus::NOT_SET;

    /**
    *  <p>A time stamp indicating when this data object was created. Format is a number expressed in Unix time as milliseconds (for example <code>"1469498468.057"</code>).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FDateTime creationTime;

    /**
    *  <p>The fleet location of the instance, expressed as an AWS Region code, such as <code>us-west-2</code>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString location;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FInstance &fromAWS(const Aws::GameLift::Model::Instance &awsInstance) {
        this->fleetId = UTF8_TO_TCHAR(awsInstance.GetFleetId().c_str());

        this->fleetArn = UTF8_TO_TCHAR(awsInstance.GetFleetArn().c_str());

        this->instanceId = UTF8_TO_TCHAR(awsInstance.GetInstanceId().c_str());

        this->ipAddress = UTF8_TO_TCHAR(awsInstance.GetIpAddress().c_str());

        this->dnsName = UTF8_TO_TCHAR(awsInstance.GetDnsName().c_str());

        switch(awsInstance.GetOperatingSystem()) {
            case Aws::GameLift::Model::OperatingSystem::NOT_SET:
                this->operatingSystem = EOperatingSystem::NOT_SET;
                break;
            case Aws::GameLift::Model::OperatingSystem::WINDOWS_2012:
                this->operatingSystem = EOperatingSystem::WINDOWS_2012;
                break;
            case Aws::GameLift::Model::OperatingSystem::AMAZON_LINUX:
                this->operatingSystem = EOperatingSystem::AMAZON_LINUX;
                break;
            case Aws::GameLift::Model::OperatingSystem::AMAZON_LINUX_2:
                this->operatingSystem = EOperatingSystem::AMAZON_LINUX_2;
                break;
            default:
                this->operatingSystem = EOperatingSystem::NOT_SET;
                break;
        }

        switch(awsInstance.GetType()) {
            case Aws::GameLift::Model::EC2InstanceType::NOT_SET:
                this->type = EEC2InstanceType::NOT_SET;
                break;
            case Aws::GameLift::Model::EC2InstanceType::t2_micro:
                this->type = EEC2InstanceType::t2_micro;
                break;
            case Aws::GameLift::Model::EC2InstanceType::t2_small:
                this->type = EEC2InstanceType::t2_small;
                break;
            case Aws::GameLift::Model::EC2InstanceType::t2_medium:
                this->type = EEC2InstanceType::t2_medium;
                break;
            case Aws::GameLift::Model::EC2InstanceType::t2_large:
                this->type = EEC2InstanceType::t2_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c3_large:
                this->type = EEC2InstanceType::c3_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c3_xlarge:
                this->type = EEC2InstanceType::c3_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c3_2xlarge:
                this->type = EEC2InstanceType::c3_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c3_4xlarge:
                this->type = EEC2InstanceType::c3_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c3_8xlarge:
                this->type = EEC2InstanceType::c3_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c4_large:
                this->type = EEC2InstanceType::c4_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c4_xlarge:
                this->type = EEC2InstanceType::c4_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c4_2xlarge:
                this->type = EEC2InstanceType::c4_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c4_4xlarge:
                this->type = EEC2InstanceType::c4_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c4_8xlarge:
                this->type = EEC2InstanceType::c4_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5_large:
                this->type = EEC2InstanceType::c5_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5_xlarge:
                this->type = EEC2InstanceType::c5_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5_2xlarge:
                this->type = EEC2InstanceType::c5_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5_4xlarge:
                this->type = EEC2InstanceType::c5_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5_9xlarge:
                this->type = EEC2InstanceType::c5_9xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5_12xlarge:
                this->type = EEC2InstanceType::c5_12xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5_18xlarge:
                this->type = EEC2InstanceType::c5_18xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5_24xlarge:
                this->type = EEC2InstanceType::c5_24xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5a_large:
                this->type = EEC2InstanceType::c5a_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5a_xlarge:
                this->type = EEC2InstanceType::c5a_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5a_2xlarge:
                this->type = EEC2InstanceType::c5a_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5a_4xlarge:
                this->type = EEC2InstanceType::c5a_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5a_8xlarge:
                this->type = EEC2InstanceType::c5a_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5a_12xlarge:
                this->type = EEC2InstanceType::c5a_12xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5a_16xlarge:
                this->type = EEC2InstanceType::c5a_16xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5a_24xlarge:
                this->type = EEC2InstanceType::c5a_24xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r3_large:
                this->type = EEC2InstanceType::r3_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r3_xlarge:
                this->type = EEC2InstanceType::r3_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r3_2xlarge:
                this->type = EEC2InstanceType::r3_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r3_4xlarge:
                this->type = EEC2InstanceType::r3_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r3_8xlarge:
                this->type = EEC2InstanceType::r3_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r4_large:
                this->type = EEC2InstanceType::r4_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r4_xlarge:
                this->type = EEC2InstanceType::r4_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r4_2xlarge:
                this->type = EEC2InstanceType::r4_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r4_4xlarge:
                this->type = EEC2InstanceType::r4_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r4_8xlarge:
                this->type = EEC2InstanceType::r4_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r4_16xlarge:
                this->type = EEC2InstanceType::r4_16xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5_large:
                this->type = EEC2InstanceType::r5_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5_xlarge:
                this->type = EEC2InstanceType::r5_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5_2xlarge:
                this->type = EEC2InstanceType::r5_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5_4xlarge:
                this->type = EEC2InstanceType::r5_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5_8xlarge:
                this->type = EEC2InstanceType::r5_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5_12xlarge:
                this->type = EEC2InstanceType::r5_12xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5_16xlarge:
                this->type = EEC2InstanceType::r5_16xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5_24xlarge:
                this->type = EEC2InstanceType::r5_24xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5a_large:
                this->type = EEC2InstanceType::r5a_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5a_xlarge:
                this->type = EEC2InstanceType::r5a_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5a_2xlarge:
                this->type = EEC2InstanceType::r5a_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5a_4xlarge:
                this->type = EEC2InstanceType::r5a_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5a_8xlarge:
                this->type = EEC2InstanceType::r5a_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5a_12xlarge:
                this->type = EEC2InstanceType::r5a_12xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5a_16xlarge:
                this->type = EEC2InstanceType::r5a_16xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5a_24xlarge:
                this->type = EEC2InstanceType::r5a_24xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m3_medium:
                this->type = EEC2InstanceType::m3_medium;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m3_large:
                this->type = EEC2InstanceType::m3_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m3_xlarge:
                this->type = EEC2InstanceType::m3_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m3_2xlarge:
                this->type = EEC2InstanceType::m3_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m4_large:
                this->type = EEC2InstanceType::m4_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m4_xlarge:
                this->type = EEC2InstanceType::m4_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m4_2xlarge:
                this->type = EEC2InstanceType::m4_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m4_4xlarge:
                this->type = EEC2InstanceType::m4_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m4_10xlarge:
                this->type = EEC2InstanceType::m4_10xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5_large:
                this->type = EEC2InstanceType::m5_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5_xlarge:
                this->type = EEC2InstanceType::m5_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5_2xlarge:
                this->type = EEC2InstanceType::m5_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5_4xlarge:
                this->type = EEC2InstanceType::m5_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5_8xlarge:
                this->type = EEC2InstanceType::m5_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5_12xlarge:
                this->type = EEC2InstanceType::m5_12xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5_16xlarge:
                this->type = EEC2InstanceType::m5_16xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5_24xlarge:
                this->type = EEC2InstanceType::m5_24xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5a_large:
                this->type = EEC2InstanceType::m5a_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5a_xlarge:
                this->type = EEC2InstanceType::m5a_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5a_2xlarge:
                this->type = EEC2InstanceType::m5a_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5a_4xlarge:
                this->type = EEC2InstanceType::m5a_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5a_8xlarge:
                this->type = EEC2InstanceType::m5a_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5a_12xlarge:
                this->type = EEC2InstanceType::m5a_12xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5a_16xlarge:
                this->type = EEC2InstanceType::m5a_16xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5a_24xlarge:
                this->type = EEC2InstanceType::m5a_24xlarge;
                break;
            default:
                this->type = EEC2InstanceType::NOT_SET;
                break;
        }

        switch(awsInstance.GetStatus()) {
            case Aws::GameLift::Model::InstanceStatus::NOT_SET:
                this->status = EInstanceStatus::NOT_SET;
                break;
            case Aws::GameLift::Model::InstanceStatus::PENDING:
                this->status = EInstanceStatus::PENDING;
                break;
            case Aws::GameLift::Model::InstanceStatus::ACTIVE:
                this->status = EInstanceStatus::ACTIVE;
                break;
            case Aws::GameLift::Model::InstanceStatus::TERMINATING:
                this->status = EInstanceStatus::TERMINATING;
                break;
            default:
                this->status = EInstanceStatus::NOT_SET;
                break;
        }

        this->creationTime = FDateTime(1970, 1, 1) + FTimespan(awsInstance.GetCreationTime().Millis() * ETimespan::TicksPerMillisecond);

        this->location = UTF8_TO_TCHAR(awsInstance.GetLocation().c_str());

        return *this;
    }
#endif
};
