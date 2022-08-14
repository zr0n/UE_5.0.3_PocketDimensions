/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/UpdateBuildResult.h"

#endif

#include "Model/Build.h"

#include "UpdateBuildResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateBuildResult {
    GENERATED_BODY()

    /**
    *  <p>Object that contains the updated build record.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FBuild build;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FUpdateBuildResult &fromAWS(const Aws::GameLift::Model::UpdateBuildResult &awsUpdateBuildResult) {
        this->build.fromAWS(awsUpdateBuildResult.GetBuild());

        return *this;
    }
#endif
};
