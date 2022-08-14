/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreateVpcPeeringConnectionRequest.h"

#endif

#include "CreateVpcPeeringConnectionRequest.generated.h"

USTRUCT(BlueprintType)
struct FCreateVpcPeeringConnectionRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a fleet. This tells Amazon GameLift which GameLift VPC to peer with. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>Unique identifier for the AWS account with the VPC that you want to peer your Amazon GameLift fleet with. You can find your Account ID in the AWS Management Console under account settings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString peerVpcAwsAccountId;

    /**
    *  <p>Unique identifier for a VPC with resources to be accessed by your Amazon GameLift fleet. The VPC must be in the same region where your fleet is deployed. Look up a VPC ID using the <a href="https://console.aws.amazon.com/vpc/">VPC Dashboard</a> in the AWS Management Console. Learn more about VPC peering in <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/vpc-peering.html">VPC Peering with Amazon GameLift Fleets</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString peerVpcId;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::CreateVpcPeeringConnectionRequest toAWS() const {
        Aws::GameLift::Model::CreateVpcPeeringConnectionRequest awsCreateVpcPeeringConnectionRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsCreateVpcPeeringConnectionRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        if (!(this->peerVpcAwsAccountId.IsEmpty())) {
            awsCreateVpcPeeringConnectionRequest.SetPeerVpcAwsAccountId(TCHAR_TO_UTF8(*this->peerVpcAwsAccountId));
        }

        if (!(this->peerVpcId.IsEmpty())) {
            awsCreateVpcPeeringConnectionRequest.SetPeerVpcId(TCHAR_TO_UTF8(*this->peerVpcId));
        }

        return awsCreateVpcPeeringConnectionRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty() && this->peerVpcAwsAccountId.IsEmpty() && this->peerVpcId.IsEmpty();
    }
#endif
};
