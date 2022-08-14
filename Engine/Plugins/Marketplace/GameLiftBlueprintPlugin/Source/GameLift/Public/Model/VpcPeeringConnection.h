/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/VpcPeeringConnection.h"

#endif

#include "Model/VpcPeeringConnectionStatus.h"

#include "VpcPeeringConnection.generated.h"

USTRUCT(BlueprintType)
struct FVpcPeeringConnection {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a fleet. This ID determines the ID of the Amazon GameLift VPC for your fleet.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p> The Amazon Resource Name (<a href="https://docs.aws.amazon.com/general/latest/gr/aws-arns-and-namespaces.html">ARN</a>) associated with the GameLift fleet resource for this connection. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetArn;

    /**
    *  <p>CIDR block of IPv4 addresses assigned to the VPC peering connection for the GameLift VPC. The peered VPC also has an IPv4 CIDR block associated with it; these blocks cannot overlap or the peering connection cannot be created. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString ipV4CidrBlock;

    /**
    *  <p>Unique identifier that is automatically assigned to the connection record. This ID is referenced in VPC peering connection events, and is used when deleting a connection with <a>DeleteVpcPeeringConnection</a>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString vpcPeeringConnectionId;

    /**
    *  <p>Object that contains status information about the connection. Status indicates if a connection is pending, successful, or failed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FVpcPeeringConnectionStatus status;

    /**
    *  <p>Unique identifier for a VPC with resources to be accessed by your Amazon GameLift fleet. The VPC must be in the same region where your fleet is deployed. Look up a VPC ID using the <a href="https://console.aws.amazon.com/vpc/">VPC Dashboard</a> in the AWS Management Console. Learn more about VPC peering in <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/vpc-peering.html">VPC Peering with Amazon GameLift Fleets</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString peerVpcId;

    /**
    *  <p>Unique identifier for the VPC that contains the Amazon GameLift fleet for this connection. This VPC is managed by Amazon GameLift and does not appear in your AWS account. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameLiftVpcId;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FVpcPeeringConnection &fromAWS(const Aws::GameLift::Model::VpcPeeringConnection &awsVpcPeeringConnection) {
        this->fleetId = UTF8_TO_TCHAR(awsVpcPeeringConnection.GetFleetId().c_str());

        this->fleetArn = UTF8_TO_TCHAR(awsVpcPeeringConnection.GetFleetArn().c_str());

        this->ipV4CidrBlock = UTF8_TO_TCHAR(awsVpcPeeringConnection.GetIpV4CidrBlock().c_str());

        this->vpcPeeringConnectionId = UTF8_TO_TCHAR(awsVpcPeeringConnection.GetVpcPeeringConnectionId().c_str());

        this->status.fromAWS(awsVpcPeeringConnection.GetStatus());

        this->peerVpcId = UTF8_TO_TCHAR(awsVpcPeeringConnection.GetPeerVpcId().c_str());

        this->gameLiftVpcId = UTF8_TO_TCHAR(awsVpcPeeringConnection.GetGameLiftVpcId().c_str());

        return *this;
    }
#endif
};
