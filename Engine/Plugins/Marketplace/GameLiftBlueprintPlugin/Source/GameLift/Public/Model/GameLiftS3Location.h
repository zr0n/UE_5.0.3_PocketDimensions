/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/S3Location.h"

#endif

#include "GameLiftS3Location.generated.h"

USTRUCT(BlueprintType)
struct FGameLiftS3Location {
GENERATED_BODY()

    /**
    *  <p>Amazon S3 bucket identifier. This is the name of the S3 bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString bucket;

    /**
    *  <p>Name of the zip file containing the build files or script files. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString key;

    /**
    *  <p>Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) for an IAM role that allows Amazon GameLift to access the S3 bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString roleArn;

    /**
    *  <p>Version of the file, if object versioning is turned on for the bucket. Amazon GameLift uses this information when retrieving files from an S3 bucket that you own. Use this parameter to specify a specific version of the file; if not set, the latest version of the file is retrieved. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString objectVersion;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::S3Location toAWS() const {
        Aws::GameLift::Model::S3Location awsS3Location;

        if (!(this->bucket.IsEmpty())) {
            awsS3Location.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->key.IsEmpty())) {
            awsS3Location.SetKey(TCHAR_TO_UTF8(*this->key));
        }

        if (!(this->roleArn.IsEmpty())) {
            awsS3Location.SetRoleArn(TCHAR_TO_UTF8(*this->roleArn));
        }

        if (!(this->objectVersion.IsEmpty())) {
            awsS3Location.SetObjectVersion(TCHAR_TO_UTF8(*this->objectVersion));
        }

        return awsS3Location;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->key.IsEmpty() && this->roleArn.IsEmpty() && this->objectVersion.IsEmpty();
    }
    FGameLiftS3Location &fromAWS(const Aws::GameLift::Model::S3Location &awsS3Location) {
        this->bucket = UTF8_TO_TCHAR(awsS3Location.GetBucket().c_str());

        this->key = UTF8_TO_TCHAR(awsS3Location.GetKey().c_str());

        this->roleArn = UTF8_TO_TCHAR(awsS3Location.GetRoleArn().c_str());

        this->objectVersion = UTF8_TO_TCHAR(awsS3Location.GetObjectVersion().c_str());

        return *this;
    }
#endif
};
