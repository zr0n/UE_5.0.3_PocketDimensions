/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/VpcPeeringAuthorization.h"

#endif

#include "VpcPeeringAuthorization.generated.h"

USTRUCT(BlueprintType)
struct FVpcPeeringAuthorization {
    GENERATED_BODY()

    /**
    *  <p>Unique identifier for the AWS account that you use to manage your Amazon GameLift fleet. You can find your Account ID in the AWS Management Console under account settings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameLiftAwsAccountId;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString peerVpcAwsAccountId;

    /**
    *  <p>Unique identifier for a VPC with resources to be accessed by your Amazon GameLift fleet. The VPC must be in the same region where your fleet is deployed. Look up a VPC ID using the <a href="https://console.aws.amazon.com/vpc/">VPC Dashboard</a> in the AWS Management Console. Learn more about VPC peering in <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/vpc-peering.html">VPC Peering with Amazon GameLift Fleets</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString peerVpcId;

    /**
    *  <p>Time stamp indicating when this authorization was issued. Format is a number expressed in Unix time as milliseconds (for example "1469498468.057").</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FDateTime creationTime;

    /**
    *  <p>Time stamp indicating when this authorization expires (24 hours after issuance). Format is a number expressed in Unix time as milliseconds (for example "1469498468.057").</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FDateTime expirationTime;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FVpcPeeringAuthorization &fromAWS(const Aws::GameLift::Model::VpcPeeringAuthorization &awsVpcPeeringAuthorization) {
        this->gameLiftAwsAccountId = UTF8_TO_TCHAR(awsVpcPeeringAuthorization.GetGameLiftAwsAccountId().c_str());

        this->peerVpcAwsAccountId = UTF8_TO_TCHAR(awsVpcPeeringAuthorization.GetPeerVpcAwsAccountId().c_str());

        this->peerVpcId = UTF8_TO_TCHAR(awsVpcPeeringAuthorization.GetPeerVpcId().c_str());

        this->creationTime = FDateTime(1970, 1, 1) + FTimespan(awsVpcPeeringAuthorization.GetCreationTime().Millis() * ETimespan::TicksPerMillisecond);

        this->expirationTime = FDateTime(1970, 1, 1) + FTimespan(awsVpcPeeringAuthorization.GetExpirationTime().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
