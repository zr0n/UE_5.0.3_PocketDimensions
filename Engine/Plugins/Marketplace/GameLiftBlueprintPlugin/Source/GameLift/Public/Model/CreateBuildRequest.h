/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreateBuildRequest.h"

#endif

#include "Model/GameLiftTag.h"

#include "Model/GameLiftS3Location.h"
#include "Model/OperatingSystem.h"

#include "CreateBuildRequest.generated.h"

USTRUCT(BlueprintType)
struct FCreateBuildRequest {
GENERATED_BODY()

    /**
    *  <p>Descriptive label that is associated with a build. Build names do not need to be unique. You can use <a>UpdateBuild</a> to change this value later. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString name;

    /**
    *  <p>Version that is associated with a build or script. Version strings do not need to be unique. You can use <a>UpdateBuild</a> to change this value later. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString version;

    /**
    *  <p>Information indicating where your game build files are stored. Use this parameter only when creating a build with files stored in an Amazon S3 bucket that you own. The storage location must specify an Amazon S3 bucket name and key, as well as a the ARN for a role that you set up to allow Amazon GameLift to access your Amazon S3 bucket. The S3 bucket must be in the same region that you want to create a new build in.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FGameLiftS3Location storageLocation;

    /**
    *  <p>Operating system that the game server binaries are built to run on. This value determines the type of fleet resources that you can use for this build. If your game build contains multiple executables, they all must run on the same operating system. If an operating system is not specified when creating a build, Amazon GameLift uses the default value (WINDOWS_2012). This value cannot be changed later.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EOperatingSystem operatingSystem = EOperatingSystem::NOT_SET;

    /**
    *  <p>A list of labels to assign to the new build resource. Tags are developer-defined key-value pairs. Tagging AWS resources are useful for resource management, access management and cost allocation. For more information, see <a href="https://docs.aws.amazon.com/general/latest/gr/aws_tagging.html"> Tagging AWS Resources</a> in the <i>AWS General Reference</i>. Once the resource is created, you can use <a>TagResource</a>, <a>UntagResource</a>, and <a>ListTagsForResource</a> to add, remove, and view tags. The maximum tag limit may be lower than stated. See the AWS General Reference for actual tagging limits.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FGameLiftTag> tags;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::CreateBuildRequest toAWS() const {
        Aws::GameLift::Model::CreateBuildRequest awsCreateBuildRequest;

        if (!(this->name.IsEmpty())) {
            awsCreateBuildRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        if (!(this->version.IsEmpty())) {
            awsCreateBuildRequest.SetVersion(TCHAR_TO_UTF8(*this->version));
        }

        if (!(this->storageLocation.IsEmpty())) {
            awsCreateBuildRequest.SetStorageLocation(this->storageLocation.toAWS());
        }

        switch(this->operatingSystem) {
            case EOperatingSystem::WINDOWS_2012:
                awsCreateBuildRequest.SetOperatingSystem(Aws::GameLift::Model::OperatingSystem::WINDOWS_2012);
                break;
            case EOperatingSystem::AMAZON_LINUX:
                awsCreateBuildRequest.SetOperatingSystem(Aws::GameLift::Model::OperatingSystem::AMAZON_LINUX);
                break;
            case EOperatingSystem::AMAZON_LINUX_2:
                awsCreateBuildRequest.SetOperatingSystem(Aws::GameLift::Model::OperatingSystem::AMAZON_LINUX_2);
                break;
            default:
                break;
        }

        for (const FGameLiftTag& elem : this->tags) {
            awsCreateBuildRequest.AddTags(elem.toAWS());
        }

        return awsCreateBuildRequest;
    }

    bool IsEmpty() const {
        return this->name.IsEmpty() && this->version.IsEmpty() && this->storageLocation.IsEmpty() && this->operatingSystem == EOperatingSystem::NOT_SET && this->tags.Num() == 0;
    }
#endif
};
