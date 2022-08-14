/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreateVpcPeeringConnectionResult.h"

#endif

#include "CreateVpcPeeringConnectionResult.generated.h"

USTRUCT(BlueprintType)
struct FCreateVpcPeeringConnectionResult {
GENERATED_BODY()

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FCreateVpcPeeringConnectionResult &fromAWS(const Aws::GameLift::Model::CreateVpcPeeringConnectionResult &awsCreateVpcPeeringConnectionResult) {

        return *this;
    }
#endif
};
