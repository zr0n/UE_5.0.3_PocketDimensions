/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreateVpcPeeringAuthorizationResult.h"

#endif

#include "Model/VpcPeeringAuthorization.h"

#include "CreateVpcPeeringAuthorizationResult.generated.h"

USTRUCT(BlueprintType)
struct FCreateVpcPeeringAuthorizationResult {
GENERATED_BODY()

    /**
    *  <p>Details on the requested VPC peering authorization, including expiration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FVpcPeeringAuthorization vpcPeeringAuthorization;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FCreateVpcPeeringAuthorizationResult &fromAWS(const Aws::GameLift::Model::CreateVpcPeeringAuthorizationResult &awsCreateVpcPeeringAuthorizationResult) {
        this->vpcPeeringAuthorization.fromAWS(awsCreateVpcPeeringAuthorizationResult.GetVpcPeeringAuthorization());

        return *this;
    }
#endif
};
