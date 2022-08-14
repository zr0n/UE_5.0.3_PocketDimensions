/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DeleteBuildRequest.h"

#endif

#include "DeleteBuildRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteBuildRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a build to delete.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString buildId;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DeleteBuildRequest toAWS() const {
        Aws::GameLift::Model::DeleteBuildRequest awsDeleteBuildRequest;

        if (!(this->buildId.IsEmpty())) {
            awsDeleteBuildRequest.SetBuildId(TCHAR_TO_UTF8(*this->buildId));
        }

        return awsDeleteBuildRequest;
    }

    bool IsEmpty() const {
        return this->buildId.IsEmpty();
    }
#endif
};
