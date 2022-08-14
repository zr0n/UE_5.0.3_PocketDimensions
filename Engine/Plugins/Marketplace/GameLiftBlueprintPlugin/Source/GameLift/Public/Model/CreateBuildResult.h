/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreateBuildResult.h"

#endif

#include "Model/Build.h"
#include "Model/GameLiftCredentials.h"
#include "Model/GameLiftS3Location.h"

#include "CreateBuildResult.generated.h"

USTRUCT(BlueprintType)
struct FCreateBuildResult {
GENERATED_BODY()

    /**
    *  <p>The newly created build record, including a unique build ID and status. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FBuild build;

    /**
    *  <p>This element is returned only when the operation is called without a storage location. It contains credentials to use when you are uploading a build file to an Amazon S3 bucket that is owned by Amazon GameLift. Credentials have a limited life span. To refresh these credentials, call <a>RequestUploadCredentials</a>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FGameLiftCredentials uploadCredentials;

    /**
    *  <p>Amazon S3 location for your game build file, including bucket name and key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FGameLiftS3Location storageLocation;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FCreateBuildResult &fromAWS(const Aws::GameLift::Model::CreateBuildResult &awsCreateBuildResult) {
        this->build.fromAWS(awsCreateBuildResult.GetBuild());

        this->uploadCredentials.fromAWS(awsCreateBuildResult.GetUploadCredentials());

        this->storageLocation.fromAWS(awsCreateBuildResult.GetStorageLocation());

        return *this;
    }
#endif
};
