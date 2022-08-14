/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeScriptResult.h"

#endif

#include "Model/Script.h"

#include "DescribeScriptResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeScriptResult {
GENERATED_BODY()

    /**
    *  <p>Set of properties describing the requested script.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FScript script;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDescribeScriptResult &fromAWS(const Aws::GameLift::Model::DescribeScriptResult &awsDescribeScriptResult) {
        this->script.fromAWS(awsDescribeScriptResult.GetScript());

        return *this;
    }
#endif
};
