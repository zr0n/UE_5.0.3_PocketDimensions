/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeVpcPeeringConnectionsRequest.h"

#endif

#include "DescribeVpcPeeringConnectionsRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeVpcPeeringConnectionsRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a fleet.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DescribeVpcPeeringConnectionsRequest toAWS() const {
        Aws::GameLift::Model::DescribeVpcPeeringConnectionsRequest awsDescribeVpcPeeringConnectionsRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsDescribeVpcPeeringConnectionsRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        return awsDescribeVpcPeeringConnectionsRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty();
    }
#endif
};
