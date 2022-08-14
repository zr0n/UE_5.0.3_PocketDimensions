/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/GetInstanceAccessResult.h"

#endif

#include "Model/InstanceAccess.h"

#include "GetInstanceAccessResult.generated.h"

USTRUCT(BlueprintType)
struct FGetInstanceAccessResult {
GENERATED_BODY()

    /**
    *  <p>Object that contains connection information for a fleet instance, including IP address and access credentials.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FInstanceAccess instanceAccess;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FGetInstanceAccessResult &fromAWS(const Aws::GameLift::Model::GetInstanceAccessResult &awsGetInstanceAccessResult) {
        this->instanceAccess.fromAWS(awsGetInstanceAccessResult.GetInstanceAccess());

        return *this;
    }
#endif
};
