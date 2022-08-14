/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeBuildRequest.h"

#endif

#include "DescribeBuildRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeBuildRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a build to retrieve properties for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString buildId;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DescribeBuildRequest toAWS() const {
        Aws::GameLift::Model::DescribeBuildRequest awsDescribeBuildRequest;

        if (!(this->buildId.IsEmpty())) {
            awsDescribeBuildRequest.SetBuildId(TCHAR_TO_UTF8(*this->buildId));
        }

        return awsDescribeBuildRequest;
    }

    bool IsEmpty() const {
        return this->buildId.IsEmpty();
    }
#endif
};
