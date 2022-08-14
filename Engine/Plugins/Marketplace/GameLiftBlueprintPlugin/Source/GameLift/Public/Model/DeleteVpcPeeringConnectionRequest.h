/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DeleteVpcPeeringConnectionRequest.h"

#endif

#include "DeleteVpcPeeringConnectionRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteVpcPeeringConnectionRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a fleet. This value must match the fleet ID referenced in the VPC peering connection record.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>Unique identifier for a VPC peering connection. This value is included in the <a>VpcPeeringConnection</a> object, which can be retrieved by calling <a>DescribeVpcPeeringConnections</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString vpcPeeringConnectionId;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DeleteVpcPeeringConnectionRequest toAWS() const {
        Aws::GameLift::Model::DeleteVpcPeeringConnectionRequest awsDeleteVpcPeeringConnectionRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsDeleteVpcPeeringConnectionRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        if (!(this->vpcPeeringConnectionId.IsEmpty())) {
            awsDeleteVpcPeeringConnectionRequest.SetVpcPeeringConnectionId(TCHAR_TO_UTF8(*this->vpcPeeringConnectionId));
        }

        return awsDeleteVpcPeeringConnectionRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty() && this->vpcPeeringConnectionId.IsEmpty();
    }
#endif
};
