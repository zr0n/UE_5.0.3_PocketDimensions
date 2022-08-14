/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/RequestUploadCredentialsResult.h"

#endif

#include "Model/GameLiftCredentials.h"
#include "Model/GameLiftS3Location.h"

#include "RequestUploadCredentialsResult.generated.h"

USTRUCT(BlueprintType)
struct FRequestUploadCredentialsResult {
GENERATED_BODY()

    /**
    *  <p>AWS credentials required when uploading a game build to the storage location. These credentials have a limited lifespan and are valid only for the build they were issued for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FGameLiftCredentials uploadCredentials;

    /**
    *  <p>Amazon S3 path and key, identifying where the game build files are stored.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FGameLiftS3Location storageLocation;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FRequestUploadCredentialsResult &fromAWS(const Aws::GameLift::Model::RequestUploadCredentialsResult &awsRequestUploadCredentialsResult) {
        this->uploadCredentials.fromAWS(awsRequestUploadCredentialsResult.GetUploadCredentials());

        this->storageLocation.fromAWS(awsRequestUploadCredentialsResult.GetStorageLocation());

        return *this;
    }
#endif
};
