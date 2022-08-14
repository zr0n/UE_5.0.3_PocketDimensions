/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/UpdateBuildRequest.h"

#endif

#include "UpdateBuildRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateBuildRequest {
    GENERATED_BODY()

    /**
    *  <p>Unique identifier for a build to update.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString buildId;

    /**
    *  <p>Descriptive label that is associated with a build. Build names do not need to be unique. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString name;

    /**
    *  <p>Version that is associated with a build or script. Version strings do not need to be unique.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString version;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::UpdateBuildRequest toAWS() const {
        Aws::GameLift::Model::UpdateBuildRequest awsUpdateBuildRequest;

        if (!(this->buildId.IsEmpty())) {
            awsUpdateBuildRequest.SetBuildId(TCHAR_TO_UTF8(*this->buildId));
        }

        if (!(this->name.IsEmpty())) {
            awsUpdateBuildRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        if (!(this->version.IsEmpty())) {
            awsUpdateBuildRequest.SetVersion(TCHAR_TO_UTF8(*this->version));
        }

        return awsUpdateBuildRequest;
    }

    bool IsEmpty() const {
        return this->buildId.IsEmpty() && this->name.IsEmpty() && this->version.IsEmpty();
    }
#endif
};
