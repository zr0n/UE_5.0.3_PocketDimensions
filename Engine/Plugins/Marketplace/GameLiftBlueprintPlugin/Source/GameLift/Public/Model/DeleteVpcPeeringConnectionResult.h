/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DeleteVpcPeeringConnectionResult.h"

#endif

#include "DeleteVpcPeeringConnectionResult.generated.h"

USTRUCT(BlueprintType)
struct FDeleteVpcPeeringConnectionResult {
GENERATED_BODY()

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDeleteVpcPeeringConnectionResult &fromAWS(const Aws::GameLift::Model::DeleteVpcPeeringConnectionResult &awsDeleteVpcPeeringConnectionResult) {

        return *this;
    }
#endif
};
