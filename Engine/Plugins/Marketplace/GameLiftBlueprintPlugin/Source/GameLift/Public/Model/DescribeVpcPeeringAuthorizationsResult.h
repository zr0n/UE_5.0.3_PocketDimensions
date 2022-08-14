/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeVpcPeeringAuthorizationsResult.h"

#endif

#include "Model/VpcPeeringAuthorization.h"

#include "DescribeVpcPeeringAuthorizationsResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeVpcPeeringAuthorizationsResult {
GENERATED_BODY()

    /**
    *  <p>Collection of objects that describe all valid VPC peering operations for the current AWS account.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FVpcPeeringAuthorization> vpcPeeringAuthorizations;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDescribeVpcPeeringAuthorizationsResult &fromAWS(const Aws::GameLift::Model::DescribeVpcPeeringAuthorizationsResult &awsDescribeVpcPeeringAuthorizationsResult) {
        this->vpcPeeringAuthorizations.Empty();
        for (const Aws::GameLift::Model::VpcPeeringAuthorization& elem : awsDescribeVpcPeeringAuthorizationsResult.GetVpcPeeringAuthorizations()) {
            this->vpcPeeringAuthorizations.Add(FVpcPeeringAuthorization().fromAWS(elem));
        }

        return *this;
    }
#endif
};
