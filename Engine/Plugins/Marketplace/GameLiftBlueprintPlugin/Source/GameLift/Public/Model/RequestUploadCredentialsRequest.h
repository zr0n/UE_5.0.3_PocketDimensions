/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/RequestUploadCredentialsRequest.h"

#endif

#include "RequestUploadCredentialsRequest.generated.h"

USTRUCT(BlueprintType)
struct FRequestUploadCredentialsRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a build to get credentials for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString buildId;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::RequestUploadCredentialsRequest toAWS() const {
        Aws::GameLift::Model::RequestUploadCredentialsRequest awsRequestUploadCredentialsRequest;

        if (!(this->buildId.IsEmpty())) {
            awsRequestUploadCredentialsRequest.SetBuildId(TCHAR_TO_UTF8(*this->buildId));
        }

        return awsRequestUploadCredentialsRequest;
    }

    bool IsEmpty() const {
        return this->buildId.IsEmpty();
    }
#endif
};
