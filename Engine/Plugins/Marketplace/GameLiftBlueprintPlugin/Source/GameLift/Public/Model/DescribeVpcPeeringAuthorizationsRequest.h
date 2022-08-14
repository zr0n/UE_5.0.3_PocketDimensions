/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeVpcPeeringAuthorizationsRequest.h"

#endif

#include "DescribeVpcPeeringAuthorizationsRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeVpcPeeringAuthorizationsRequest {
GENERATED_BODY()

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DescribeVpcPeeringAuthorizationsRequest toAWS() const {
        Aws::GameLift::Model::DescribeVpcPeeringAuthorizationsRequest awsDescribeVpcPeeringAuthorizationsRequest;

        return awsDescribeVpcPeeringAuthorizationsRequest;
    }

    bool IsEmpty() const {
        return true;
    }
#endif
};
