/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/PutScalingPolicyResult.h"

#endif

#include "PutScalingPolicyResult.generated.h"

USTRUCT(BlueprintType)
struct FPutScalingPolicyResult {
GENERATED_BODY()

    /**
    *  <p>Descriptive label that is associated with a scaling policy. Policy names do not need to be unique.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString name;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FPutScalingPolicyResult &fromAWS(const Aws::GameLift::Model::PutScalingPolicyResult &awsPutScalingPolicyResult) {
        this->name = UTF8_TO_TCHAR(awsPutScalingPolicyResult.GetName().c_str());

        return *this;
    }
#endif
};
