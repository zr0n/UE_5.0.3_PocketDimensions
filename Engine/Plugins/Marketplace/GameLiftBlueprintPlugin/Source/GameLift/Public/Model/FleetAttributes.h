/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/FleetAttributes.h"

#endif

#include "Model/FleetType.h"
#include "Model/EC2InstanceType.h"
#include "Model/FleetStatus.h"
#include "Model/ProtectionPolicy.h"
#include "Model/OperatingSystem.h"
#include "Model/ResourceCreationLimitPolicy.h"
#include "Model/FleetAction.h"
#include "Model/CertificateConfiguration.h"

#include "FleetAttributes.generated.h"

USTRUCT(BlueprintType)
struct FFleetAttributes {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the fleet.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) that is assigned to a GameLift fleet resource and uniquely identifies it. ARNs are unique across all Regions. Format is <code>arn:aws:gamelift:&lt;region&gt;::fleet/fleet-a1234567-b8c9-0d1e-2fa3-b45c6d7e8912</code>. In a GameLift fleet ARN, the resource ID matches the <code>FleetId</code> value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetArn;

    /**
    *  <p>The kind of instances, On-Demand or Spot, that this fleet uses.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EFleetType fleetType = EFleetType::NOT_SET;

    /**
    *  <p>The EC2 instance type that determines the computing resources of each instance in the fleet. Instance type defines the CPU, memory, storage, and networking capacity. See <a href="http://aws.amazon.com/ec2/instance-types/">Amazon EC2 Instance Types</a> for detailed descriptions.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EEC2InstanceType instanceType = EEC2InstanceType::NOT_SET;

    /**
    *  <p>A human-readable description of the fleet.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString description;

    /**
    *  <p>A descriptive label that is associated with a fleet. Fleet names do not need to be unique.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString name;

    /**
    *  <p>A time stamp indicating when this data object was created. Format is a number expressed in Unix time as milliseconds (for example <code>"1469498468.057"</code>).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FDateTime creationTime;

    /**
    *  <p>A time stamp indicating when this data object was terminated. Format is a number expressed in Unix time as milliseconds (for example <code>"1469498468.057"</code>).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FDateTime terminationTime;

    /**
    *  <p>Current status of the fleet. Possible fleet statuses include the following:</p> <ul> <li> <p> <b>NEW</b> -- A new fleet has been defined and desired instances is set to 1. </p> </li> <li> <p> <b>DOWNLOADING/VALIDATING/BUILDING/ACTIVATING</b> -- GameLift is setting up the new fleet, creating new instances with the game build or Realtime script and starting server processes.</p> </li> <li> <p> <b>ACTIVE</b> -- Hosts can now accept game sessions.</p> </li> <li> <p> <b>ERROR</b> -- An error occurred when downloading, validating, building, or activating the fleet.</p> </li> <li> <p> <b>DELETING</b> -- Hosts are responding to a delete fleet request.</p> </li> <li> <p> <b>TERMINATED</b> -- The fleet no longer exists.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EFleetStatus status = EFleetStatus::NOT_SET;

    /**
    *  <p>A unique identifier for the build resource that is deployed on instances in this fleet.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString buildId;

    /**
    *  <p> The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) associated with the GameLift build resource that is deployed on instances in this fleet. In a GameLift build ARN, the resource ID matches the <code>BuildId</code> value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString buildArn;

    /**
    *  <p>A unique identifier for the Realtime script resource that is deployed on instances in this fleet.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString scriptId;

    /**
    *  <p> The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) associated with the GameLift script resource that is deployed on instances in this fleet. In a GameLift script ARN, the resource ID matches the <code>ScriptId</code> value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString scriptArn;

    /**
    *  <p> <b>This parameter is no longer used.</b> Server launch paths are now defined using the fleet's <a>RuntimeConfiguration</a> parameter. Requests that use this parameter instead continue to be valid.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString serverLaunchPath;

    /**
    *  <p> <b>This parameter is no longer used.</b> Server launch parameters are now defined using the fleet's <a>RuntimeConfiguration</a> parameter. Requests that use this parameter instead continue to be valid.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString serverLaunchParameters;

    /**
    *  <p> <b>This parameter is no longer used.</b> Game session log paths are now defined using the GameLift server API <code>ProcessReady()</code> <code>logParameters</code>. See more information in the <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/gamelift-sdk-server-api-ref.html#gamelift-sdk-server-api-ref-dataypes-process">Server API Reference</a>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FString> logPaths;

    /**
    *  <p>The type of game session protection to set on all new instances that are started in the fleet.</p> <ul> <li> <p> <b>NoProtection</b> -- The game session can be terminated during a scale-down event.</p> </li> <li> <p> <b>FullProtection</b> -- If the game session is in an <code>ACTIVE</code> status, it cannot be terminated during a scale-down event.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EProtectionPolicy newGameSessionProtectionPolicy = EProtectionPolicy::NOT_SET;

    /**
    *  <p>The operating system of the fleet's computing resources. A fleet's operating system is determined by the OS of the build or script that is deployed on this fleet.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EOperatingSystem operatingSystem = EOperatingSystem::NOT_SET;

    /**
    *  <p>The fleet policy that limits the number of game sessions an individual player can create over a span of time.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FResourceCreationLimitPolicy resourceCreationLimitPolicy;

    /**
    *  <p>Name of a metric group that metrics for this fleet are added to. In Amazon CloudWatch, you can view aggregated metrics for fleets that are in a metric group. A fleet can be included in only one metric group at a time.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FString> metricGroups;

    /**
    *  <p>A list of fleet activity that has been suspended using <a>StopFleetActions</a>. This includes fleet auto-scaling.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<EFleetAction> stoppedActions;

    /**
    *  <p>A unique identifier for an AWS IAM role that manages access to your AWS services. With an instance role ARN set, any application that runs on an instance in this fleet can assume the role, including install scripts, server processes, and daemons (background processes). Create a role or look up a role's ARN by using the <a href="https://console.aws.amazon.com/iam/">IAM dashboard</a> in the AWS Management Console. Learn more about using on-box credentials for your game servers at <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/gamelift-sdk-server-resources.html"> Access external resources from a game server</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString instanceRoleArn;

    /**
    *  <p>Indicates whether a TLS/SSL certificate was generated for the fleet. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FCertificateConfiguration certificateConfiguration;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FFleetAttributes &fromAWS(const Aws::GameLift::Model::FleetAttributes &awsFleetAttributes) {
        this->fleetId = UTF8_TO_TCHAR(awsFleetAttributes.GetFleetId().c_str());

        this->fleetArn = UTF8_TO_TCHAR(awsFleetAttributes.GetFleetArn().c_str());

        switch(awsFleetAttributes.GetFleetType()) {
            case Aws::GameLift::Model::FleetType::NOT_SET:
                this->fleetType = EFleetType::NOT_SET;
                break;
            case Aws::GameLift::Model::FleetType::ON_DEMAND:
                this->fleetType = EFleetType::ON_DEMAND;
                break;
            case Aws::GameLift::Model::FleetType::SPOT:
                this->fleetType = EFleetType::SPOT;
                break;
            default:
                this->fleetType = EFleetType::NOT_SET;
                break;
        }

        switch(awsFleetAttributes.GetInstanceType()) {
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

        this->description = UTF8_TO_TCHAR(awsFleetAttributes.GetDescription().c_str());

        this->name = UTF8_TO_TCHAR(awsFleetAttributes.GetName().c_str());

        this->creationTime = FDateTime(1970, 1, 1) + FTimespan(awsFleetAttributes.GetCreationTime().Millis() * ETimespan::TicksPerMillisecond);

        this->terminationTime = FDateTime(1970, 1, 1) + FTimespan(awsFleetAttributes.GetTerminationTime().Millis() * ETimespan::TicksPerMillisecond);

        switch(awsFleetAttributes.GetStatus()) {
            case Aws::GameLift::Model::FleetStatus::NOT_SET:
                this->status = EFleetStatus::NOT_SET;
                break;
            case Aws::GameLift::Model::FleetStatus::NEW_:
                this->status = EFleetStatus::NEW_;
                break;
            case Aws::GameLift::Model::FleetStatus::DOWNLOADING:
                this->status = EFleetStatus::DOWNLOADING;
                break;
            case Aws::GameLift::Model::FleetStatus::VALIDATING:
                this->status = EFleetStatus::VALIDATING;
                break;
            case Aws::GameLift::Model::FleetStatus::BUILDING:
                this->status = EFleetStatus::BUILDING;
                break;
            case Aws::GameLift::Model::FleetStatus::ACTIVATING:
                this->status = EFleetStatus::ACTIVATING;
                break;
            case Aws::GameLift::Model::FleetStatus::ACTIVE:
                this->status = EFleetStatus::ACTIVE;
                break;
            case Aws::GameLift::Model::FleetStatus::DELETING:
                this->status = EFleetStatus::DELETING;
                break;
            case Aws::GameLift::Model::FleetStatus::ERROR_:
                this->status = EFleetStatus::ERROR_;
                break;
            case Aws::GameLift::Model::FleetStatus::TERMINATED:
                this->status = EFleetStatus::TERMINATED;
                break;
            default:
                this->status = EFleetStatus::NOT_SET;
                break;
        }

        this->buildId = UTF8_TO_TCHAR(awsFleetAttributes.GetBuildId().c_str());

        this->buildArn = UTF8_TO_TCHAR(awsFleetAttributes.GetBuildArn().c_str());

        this->scriptId = UTF8_TO_TCHAR(awsFleetAttributes.GetScriptId().c_str());

        this->scriptArn = UTF8_TO_TCHAR(awsFleetAttributes.GetScriptArn().c_str());

        this->serverLaunchPath = UTF8_TO_TCHAR(awsFleetAttributes.GetServerLaunchPath().c_str());

        this->serverLaunchParameters = UTF8_TO_TCHAR(awsFleetAttributes.GetServerLaunchParameters().c_str());

        this->logPaths.Empty();
        for (const Aws::String& elem : awsFleetAttributes.GetLogPaths()) {
            this->logPaths.Add(elem.c_str());
        }

        switch(awsFleetAttributes.GetNewGameSessionProtectionPolicy()) {
            case Aws::GameLift::Model::ProtectionPolicy::NOT_SET:
                this->newGameSessionProtectionPolicy = EProtectionPolicy::NOT_SET;
                break;
            case Aws::GameLift::Model::ProtectionPolicy::NoProtection:
                this->newGameSessionProtectionPolicy = EProtectionPolicy::NoProtection;
                break;
            case Aws::GameLift::Model::ProtectionPolicy::FullProtection:
                this->newGameSessionProtectionPolicy = EProtectionPolicy::FullProtection;
                break;
            default:
                this->newGameSessionProtectionPolicy = EProtectionPolicy::NOT_SET;
                break;
        }

        switch(awsFleetAttributes.GetOperatingSystem()) {
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

        this->resourceCreationLimitPolicy.fromAWS(awsFleetAttributes.GetResourceCreationLimitPolicy());

        this->metricGroups.Empty();
        for (const Aws::String& elem : awsFleetAttributes.GetMetricGroups()) {
            this->metricGroups.Add(elem.c_str());
        }

        this->stoppedActions.Empty();
        for (const Aws::GameLift::Model::FleetAction& elem : awsFleetAttributes.GetStoppedActions()) {
            switch(elem) {
                case Aws::GameLift::Model::FleetAction::NOT_SET:
                    this->stoppedActions.Add(EFleetAction::NOT_SET);
                    break;
                case Aws::GameLift::Model::FleetAction::AUTO_SCALING:
                    this->stoppedActions.Add(EFleetAction::AUTO_SCALING);
                    break;
                default:
                    this->stoppedActions.Add(EFleetAction::NOT_SET);
                    break;
            };
        }

        this->instanceRoleArn = UTF8_TO_TCHAR(awsFleetAttributes.GetInstanceRoleArn().c_str());

        this->certificateConfiguration.fromAWS(awsFleetAttributes.GetCertificateConfiguration());

        return *this;
    }
#endif
};
