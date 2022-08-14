/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeVpcPeeringConnectionsResult.h"

#endif

#include "Model/VpcPeeringConnection.h"

#include "DescribeVpcPeeringConnectionsResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeVpcPeeringConnectionsResult {
GENERATED_BODY()

    /**
    *  <p>Collection of VPC peering connection records that match the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FVpcPeeringConnection> vpcPeeringConnections;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDescribeVpcPeeringConnectionsResult &fromAWS(const Aws::GameLift::Model::DescribeVpcPeeringConnectionsResult &awsDescribeVpcPeeringConnectionsResult) {
        this->vpcPeeringConnections.Empty();
        for (const Aws::GameLift::Model::VpcPeeringConnection& elem : awsDescribeVpcPeeringConnectionsResult.GetVpcPeeringConnections()) {
            this->vpcPeeringConnections.Add(FVpcPeeringConnection().fromAWS(elem));
        }

        return *this;
    }
#endif
};
