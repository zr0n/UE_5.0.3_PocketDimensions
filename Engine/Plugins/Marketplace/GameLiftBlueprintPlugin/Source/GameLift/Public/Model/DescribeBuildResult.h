/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeBuildResult.h"

#endif

#include "Model/Build.h"

#include "DescribeBuildResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeBuildResult {
GENERATED_BODY()

    /**
    *  <p>Set of properties describing the requested build.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FBuild build;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDescribeBuildResult &fromAWS(const Aws::GameLift::Model::DescribeBuildResult &awsDescribeBuildResult) {
        this->build.fromAWS(awsDescribeBuildResult.GetBuild());

        return *this;
    }
#endif
};
