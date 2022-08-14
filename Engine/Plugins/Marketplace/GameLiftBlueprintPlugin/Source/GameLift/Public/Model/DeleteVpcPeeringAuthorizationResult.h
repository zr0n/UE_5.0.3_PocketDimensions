/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DeleteVpcPeeringAuthorizationResult.h"

#endif

#include "DeleteVpcPeeringAuthorizationResult.generated.h"

USTRUCT(BlueprintType)
struct FDeleteVpcPeeringAuthorizationResult {
GENERATED_BODY()

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDeleteVpcPeeringAuthorizationResult &fromAWS(const Aws::GameLift::Model::DeleteVpcPeeringAuthorizationResult &awsDeleteVpcPeeringAuthorizationResult) {

        return *this;
    }
#endif
};
