/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreateFleetRequest.h"

#endif

#include "Model/EC2InstanceType.h"
#include "Model/IpPermission.h"
#include "Model/ProtectionPolicy.h"
#include "Model/RuntimeConfiguration.h"
#include "Model/ResourceCreationLimitPolicy.h"
#include "Model/FleetType.h"
#include "Model/CertificateConfiguration.h"
#include "Model/AWSGameLiftLocationConfiguration.h"
#include "Model/GameLiftTag.h"

#include "CreateFleetRequest.generated.h"

USTRUCT(BlueprintType)
struct FCreateFleetRequest {
GENERATED_BODY()

    /**
    *  <p>A descriptive label that is associated with a fleet. Fleet names do not need to be unique.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString name;

    /**
    *  <p>A human-readable description of the fleet.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString description;

    /**
    *  <p>The unique identifier for a custom game server build to be deployed on fleet instances. You can use either the build ID or ARN. The build must be uploaded to GameLift and in <code>READY</code> status. This fleet property cannot be changed later.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString buildId;

    /**
    *  <p>The unique identifier for a Realtime configuration script to be deployed on fleet instances. You can use either the script ID or ARN. Scripts must be uploaded to GameLift prior to creating the fleet. This fleet property cannot be changed later.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString scriptId;

    /**
    *  <p> <b>This parameter is no longer used.</b> Specify a server launch path using the <code>RuntimeConfiguration</code> parameter. Requests that use this parameter instead continue to be valid.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString serverLaunchPath;

    /**
    *  <p> <b>This parameter is no longer used.</b> Specify server launch parameters using the <code>RuntimeConfiguration</code> parameter. Requests that use this parameter instead continue to be valid.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString serverLaunchParameters;

    /**
    *  <p> <b>This parameter is no longer used.</b> To specify where GameLift should store log files once a server process shuts down, use the GameLift server API <code>ProcessReady()</code> and specify one or more directory paths in <code>logParameters</code>. See more information in the <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/gamelift-sdk-server-api-ref.html#gamelift-sdk-server-api-ref-dataypes-process">Server API Reference</a>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FString> logPaths;

    /**
    *  <p>The GameLift-supported EC2 instance type to use for all fleet instances. Instance type determines the computing resources that will be used to host your game servers, including CPU, memory, storage, and networking capacity. See <a href="http://aws.amazon.com/ec2/instance-types/">Amazon EC2 Instance Types</a> for detailed descriptions of EC2 instance types.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EEC2InstanceType eC2InstanceType = EEC2InstanceType::NOT_SET;

    /**
    *  <p>The allowed IP address ranges and port settings that allow inbound traffic to access game sessions on this fleet. If the fleet is hosting a custom game build, this property must be set before players can connect to game sessions. For Realtime Servers fleets, GameLift automatically sets TCP and UDP ranges. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FIpPermission> eC2InboundPermissions;

    /**
    *  <p>The status of termination protection for active game sessions on the fleet. By default, this property is set to <code>NoProtection</code>. You can also set game session protection for an individual game session by calling <a>UpdateGameSession</a>.</p> <ul> <li> <p> <b>NoProtection</b> - Game sessions can be terminated during active gameplay as a result of a scale-down event. </p> </li> <li> <p> <b>FullProtection</b> - Game sessions in <code>ACTIVE</code> status cannot be terminated during a scale-down event.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EProtectionPolicy newGameSessionProtectionPolicy = EProtectionPolicy::NOT_SET;

    /**
    *  <p>Instructions for how to launch and maintain server processes on instances in the fleet. The runtime configuration defines one or more server process configurations, each identifying a build executable or Realtime script file and the number of processes of that type to run concurrently. </p>  <p>The <code>RuntimeConfiguration</code> parameter is required unless the fleet is being configured using the older parameters <code>ServerLaunchPath</code> and <code>ServerLaunchParameters</code>, which are still supported for backward compatibility.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FRuntimeConfiguration runtimeConfiguration;

    /**
    *  <p>A policy that limits the number of game sessions that an individual player can create on instances in this fleet within a specified span of time.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FResourceCreationLimitPolicy resourceCreationLimitPolicy;

    /**
    *  <p>The name of an AWS CloudWatch metric group to add this fleet to. A metric group is used to aggregate the metrics for multiple fleets. You can specify an existing metric group name or set a new name to create a new metric group. A fleet can be included in only one metric group at a time. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FString> metricGroups;

    /**
    *  <p>Used when peering your GameLift fleet with a VPC, the unique identifier for the AWS account that owns the VPC. You can find your account ID in the AWS Management Console under account settings. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString peerVpcAwsAccountId;

    /**
    *  <p>A unique identifier for a VPC with resources to be accessed by your GameLift fleet. The VPC must be in the same Region as your fleet. To look up a VPC ID, use the <a href="https://console.aws.amazon.com/vpc/">VPC Dashboard</a> in the AWS Management Console. Learn more about VPC peering in <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/vpc-peering.html">VPC Peering with GameLift Fleets</a>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString peerVpcId;

    /**
    *  <p>Indicates whether to use On-Demand or Spot instances for this fleet. By default, this property is set to <code>ON_DEMAND</code>. Learn more about when to use <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/gamelift-ec2-instances.html#gamelift-ec2-instances-spot"> On-Demand versus Spot Instances</a>. This property cannot be changed after the fleet is created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EFleetType fleetType = EFleetType::NOT_SET;

    /**
    *  <p>A unique identifier for an AWS IAM role that manages access to your AWS services. With an instance role ARN set, any application that runs on an instance in this fleet can assume the role, including install scripts, server processes, and daemons (background processes). Create a role or look up a role's ARN by using the <a href="https://console.aws.amazon.com/iam/">IAM dashboard</a> in the AWS Management Console. Learn more about using on-box credentials for your game servers at <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/gamelift-sdk-server-resources.html"> Access external resources from a game server</a>. This property cannot be changed after the fleet is created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString instanceRoleArn;

    /**
    *  <p>Indicates whether to generate a TLS/SSL certificate for the new fleet. TLS certificates are used for encrypting traffic between game clients and game servers running on GameLift. If this parameter is not specified, the default value, DISABLED, is used. This fleet setting cannot be changed once the fleet is created. Learn more at <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/gamelift-howitworks.html#gamelift-howitworks-security">Securing Client/Server Communication</a>. </p> <p>Note: This feature requires the AWS Certificate Manager (ACM) service, which is available in the AWS global partition but not in all other partitions. When working in a partition that does not support this feature, a request for a new fleet with certificate generation results fails with a 4xx unsupported Region error.</p> <p>Valid values include: </p> <ul> <li> <p> <b>GENERATED</b> - Generate a TLS/SSL certificate for this fleet.</p> </li> <li> <p> <b>DISABLED</b> - (default) Do not generate a TLS/SSL certificate for this fleet.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FCertificateConfiguration certificateConfiguration;

    /**
    *  <p>A set of remote locations to deploy additional instances to and manage as part of the fleet. This parameter can only be used when creating fleets in AWS Regions that support multiple locations. You can add any GameLift-supported AWS Region as a remote location, in the form of an AWS Region code such as <code>us-west-2</code>. To create a fleet with instances in the home Region only, omit this parameter. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FAWSGameLiftLocationConfiguration> locations;

    /**
    *  <p>A list of labels to assign to the new fleet resource. Tags are developer-defined key-value pairs. Tagging AWS resources are useful for resource management, access management and cost allocation. For more information, see <a href="https://docs.aws.amazon.com/general/latest/gr/aws_tagging.html"> Tagging AWS Resources</a> in the <i>AWS General Reference</i>. Once the resource is created, you can use <a>TagResource</a>, <a>UntagResource</a>, and <a>ListTagsForResource</a> to add, remove, and view tags. The maximum tag limit may be lower than stated. See the AWS General Reference for actual tagging limits.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FGameLiftTag> tags;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::CreateFleetRequest toAWS() const {
        Aws::GameLift::Model::CreateFleetRequest awsCreateFleetRequest;

        if (!(this->name.IsEmpty())) {
            awsCreateFleetRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        if (!(this->description.IsEmpty())) {
            awsCreateFleetRequest.SetDescription(TCHAR_TO_UTF8(*this->description));
        }

        if (!(this->buildId.IsEmpty())) {
            awsCreateFleetRequest.SetBuildId(TCHAR_TO_UTF8(*this->buildId));
        }

        if (!(this->scriptId.IsEmpty())) {
            awsCreateFleetRequest.SetScriptId(TCHAR_TO_UTF8(*this->scriptId));
        }

        if (!(this->serverLaunchPath.IsEmpty())) {
            awsCreateFleetRequest.SetServerLaunchPath(TCHAR_TO_UTF8(*this->serverLaunchPath));
        }

        if (!(this->serverLaunchParameters.IsEmpty())) {
            awsCreateFleetRequest.SetServerLaunchParameters(TCHAR_TO_UTF8(*this->serverLaunchParameters));
        }

        for (const FString& elem : this->logPaths) {
            awsCreateFleetRequest.AddLogPaths(TCHAR_TO_UTF8(*elem));
        }

        switch(this->eC2InstanceType) {
            case EEC2InstanceType::t2_micro:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::t2_micro);
                break;
            case EEC2InstanceType::t2_small:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::t2_small);
                break;
            case EEC2InstanceType::t2_medium:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::t2_medium);
                break;
            case EEC2InstanceType::t2_large:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::t2_large);
                break;
            case EEC2InstanceType::c3_large:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c3_large);
                break;
            case EEC2InstanceType::c3_xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c3_xlarge);
                break;
            case EEC2InstanceType::c3_2xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c3_2xlarge);
                break;
            case EEC2InstanceType::c3_4xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c3_4xlarge);
                break;
            case EEC2InstanceType::c3_8xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c3_8xlarge);
                break;
            case EEC2InstanceType::c4_large:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c4_large);
                break;
            case EEC2InstanceType::c4_xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c4_xlarge);
                break;
            case EEC2InstanceType::c4_2xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c4_2xlarge);
                break;
            case EEC2InstanceType::c4_4xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c4_4xlarge);
                break;
            case EEC2InstanceType::c4_8xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c4_8xlarge);
                break;
            case EEC2InstanceType::c5_large:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c5_large);
                break;
            case EEC2InstanceType::c5_xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c5_xlarge);
                break;
            case EEC2InstanceType::c5_2xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c5_2xlarge);
                break;
            case EEC2InstanceType::c5_4xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c5_4xlarge);
                break;
            case EEC2InstanceType::c5_9xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c5_9xlarge);
                break;
            case EEC2InstanceType::c5_12xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c5_12xlarge);
                break;
            case EEC2InstanceType::c5_18xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c5_18xlarge);
                break;
            case EEC2InstanceType::c5_24xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c5_24xlarge);
                break;
            case EEC2InstanceType::c5a_large:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c5a_large);
                break;
            case EEC2InstanceType::c5a_xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c5a_xlarge);
                break;
            case EEC2InstanceType::c5a_2xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c5a_2xlarge);
                break;
            case EEC2InstanceType::c5a_4xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c5a_4xlarge);
                break;
            case EEC2InstanceType::c5a_8xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c5a_8xlarge);
                break;
            case EEC2InstanceType::c5a_12xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c5a_12xlarge);
                break;
            case EEC2InstanceType::c5a_16xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c5a_16xlarge);
                break;
            case EEC2InstanceType::c5a_24xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::c5a_24xlarge);
                break;
            case EEC2InstanceType::r3_large:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r3_large);
                break;
            case EEC2InstanceType::r3_xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r3_xlarge);
                break;
            case EEC2InstanceType::r3_2xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r3_2xlarge);
                break;
            case EEC2InstanceType::r3_4xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r3_4xlarge);
                break;
            case EEC2InstanceType::r3_8xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r3_8xlarge);
                break;
            case EEC2InstanceType::r4_large:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r4_large);
                break;
            case EEC2InstanceType::r4_xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r4_xlarge);
                break;
            case EEC2InstanceType::r4_2xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r4_2xlarge);
                break;
            case EEC2InstanceType::r4_4xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r4_4xlarge);
                break;
            case EEC2InstanceType::r4_8xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r4_8xlarge);
                break;
            case EEC2InstanceType::r4_16xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r4_16xlarge);
                break;
            case EEC2InstanceType::r5_large:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r5_large);
                break;
            case EEC2InstanceType::r5_xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r5_xlarge);
                break;
            case EEC2InstanceType::r5_2xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r5_2xlarge);
                break;
            case EEC2InstanceType::r5_4xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r5_4xlarge);
                break;
            case EEC2InstanceType::r5_8xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r5_8xlarge);
                break;
            case EEC2InstanceType::r5_12xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r5_12xlarge);
                break;
            case EEC2InstanceType::r5_16xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r5_16xlarge);
                break;
            case EEC2InstanceType::r5_24xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r5_24xlarge);
                break;
            case EEC2InstanceType::r5a_large:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r5a_large);
                break;
            case EEC2InstanceType::r5a_xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r5a_xlarge);
                break;
            case EEC2InstanceType::r5a_2xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r5a_2xlarge);
                break;
            case EEC2InstanceType::r5a_4xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r5a_4xlarge);
                break;
            case EEC2InstanceType::r5a_8xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r5a_8xlarge);
                break;
            case EEC2InstanceType::r5a_12xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r5a_12xlarge);
                break;
            case EEC2InstanceType::r5a_16xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r5a_16xlarge);
                break;
            case EEC2InstanceType::r5a_24xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::r5a_24xlarge);
                break;
            case EEC2InstanceType::m3_medium:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m3_medium);
                break;
            case EEC2InstanceType::m3_large:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m3_large);
                break;
            case EEC2InstanceType::m3_xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m3_xlarge);
                break;
            case EEC2InstanceType::m3_2xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m3_2xlarge);
                break;
            case EEC2InstanceType::m4_large:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m4_large);
                break;
            case EEC2InstanceType::m4_xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m4_xlarge);
                break;
            case EEC2InstanceType::m4_2xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m4_2xlarge);
                break;
            case EEC2InstanceType::m4_4xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m4_4xlarge);
                break;
            case EEC2InstanceType::m4_10xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m4_10xlarge);
                break;
            case EEC2InstanceType::m5_large:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m5_large);
                break;
            case EEC2InstanceType::m5_xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m5_xlarge);
                break;
            case EEC2InstanceType::m5_2xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m5_2xlarge);
                break;
            case EEC2InstanceType::m5_4xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m5_4xlarge);
                break;
            case EEC2InstanceType::m5_8xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m5_8xlarge);
                break;
            case EEC2InstanceType::m5_12xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m5_12xlarge);
                break;
            case EEC2InstanceType::m5_16xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m5_16xlarge);
                break;
            case EEC2InstanceType::m5_24xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m5_24xlarge);
                break;
            case EEC2InstanceType::m5a_large:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m5a_large);
                break;
            case EEC2InstanceType::m5a_xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m5a_xlarge);
                break;
            case EEC2InstanceType::m5a_2xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m5a_2xlarge);
                break;
            case EEC2InstanceType::m5a_4xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m5a_4xlarge);
                break;
            case EEC2InstanceType::m5a_8xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m5a_8xlarge);
                break;
            case EEC2InstanceType::m5a_12xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m5a_12xlarge);
                break;
            case EEC2InstanceType::m5a_16xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m5a_16xlarge);
                break;
            case EEC2InstanceType::m5a_24xlarge:
                awsCreateFleetRequest.SetEC2InstanceType(Aws::GameLift::Model::EC2InstanceType::m5a_24xlarge);
                break;
            default:
                break;
        }

        for (const FIpPermission& elem : this->eC2InboundPermissions) {
            awsCreateFleetRequest.AddEC2InboundPermissions(elem.toAWS());
        }

        switch(this->newGameSessionProtectionPolicy) {
            case EProtectionPolicy::NoProtection:
                awsCreateFleetRequest.SetNewGameSessionProtectionPolicy(Aws::GameLift::Model::ProtectionPolicy::NoProtection);
                break;
            case EProtectionPolicy::FullProtection:
                awsCreateFleetRequest.SetNewGameSessionProtectionPolicy(Aws::GameLift::Model::ProtectionPolicy::FullProtection);
                break;
            default:
                break;
        }

        if (!(this->runtimeConfiguration.IsEmpty())) {
            awsCreateFleetRequest.SetRuntimeConfiguration(this->runtimeConfiguration.toAWS());
        }

        if (!(this->resourceCreationLimitPolicy.IsEmpty())) {
            awsCreateFleetRequest.SetResourceCreationLimitPolicy(this->resourceCreationLimitPolicy.toAWS());
        }

        for (const FString& elem : this->metricGroups) {
            awsCreateFleetRequest.AddMetricGroups(TCHAR_TO_UTF8(*elem));
        }

        if (!(this->peerVpcAwsAccountId.IsEmpty())) {
            awsCreateFleetRequest.SetPeerVpcAwsAccountId(TCHAR_TO_UTF8(*this->peerVpcAwsAccountId));
        }

        if (!(this->peerVpcId.IsEmpty())) {
            awsCreateFleetRequest.SetPeerVpcId(TCHAR_TO_UTF8(*this->peerVpcId));
        }

        switch(this->fleetType) {
            case EFleetType::ON_DEMAND:
                awsCreateFleetRequest.SetFleetType(Aws::GameLift::Model::FleetType::ON_DEMAND);
                break;
            case EFleetType::SPOT:
                awsCreateFleetRequest.SetFleetType(Aws::GameLift::Model::FleetType::SPOT);
                break;
            default:
                break;
        }

        if (!(this->instanceRoleArn.IsEmpty())) {
            awsCreateFleetRequest.SetInstanceRoleArn(TCHAR_TO_UTF8(*this->instanceRoleArn));
        }

        if (!(this->certificateConfiguration.IsEmpty())) {
            awsCreateFleetRequest.SetCertificateConfiguration(this->certificateConfiguration.toAWS());
        }

        for (const FAWSGameLiftLocationConfiguration& elem : this->locations) {
            awsCreateFleetRequest.AddLocations(elem.toAWS());
        }

        for (const FGameLiftTag& elem : this->tags) {
            awsCreateFleetRequest.AddTags(elem.toAWS());
        }

        return awsCreateFleetRequest;
    }

    bool IsEmpty() const {
        return this->name.IsEmpty() && this->description.IsEmpty() && this->buildId.IsEmpty() && this->scriptId.IsEmpty() && this->serverLaunchPath.IsEmpty() && this->serverLaunchParameters.IsEmpty() && this->logPaths.Num() == 0 && this->eC2InstanceType == EEC2InstanceType::NOT_SET && this->eC2InboundPermissions.Num() == 0 && this->newGameSessionProtectionPolicy == EProtectionPolicy::NOT_SET && this->runtimeConfiguration.IsEmpty() && this->resourceCreationLimitPolicy.IsEmpty() && this->metricGroups.Num() == 0 && this->peerVpcAwsAccountId.IsEmpty() && this->peerVpcId.IsEmpty() && this->fleetType == EFleetType::NOT_SET && this->instanceRoleArn.IsEmpty() && this->certificateConfiguration.IsEmpty() && this->locations.Num() == 0 && this->tags.Num() == 0;
    }
#endif
};
