/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"
#include "HAL/PlatformFileManager.h"
#include "GenericPlatform/GenericPlatformFile.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/UpdateScriptRequest.h"

#endif

#include "Model/GameLiftS3Location.h"

#include "UpdateScriptRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateScriptRequest {
    GENERATED_BODY()

    /**
    *  <p>Unique identifier for a Realtime script to update.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString scriptId;

    /**
    *  <p>Descriptive label that is associated with a script. Script names do not need to be unique.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString name;

    /**
    *  <p>Version that is associated with a build or script. Version strings do not need to be unique.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString version;

    /**
    *  <p>Location of the Amazon S3 bucket where a zipped file containing your Realtime scripts is stored. The storage location must specify the Amazon S3 bucket name, the zip file name (the "key"), and a role ARN that allows Amazon GameLift to access the Amazon S3 storage location. The S3 bucket must be in the same region where you want to create a new script. By default, Amazon GameLift uploads the latest version of the zip file; if you have S3 object versioning turned on, you can use the <code>ObjectVersion</code> parameter to specify an earlier version. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FGameLiftS3Location storageLocation;

    /**
    *  <p>Data object containing your Realtime scripts and dependencies as a zip file. The zip file can have one or multiple files. Maximum size of a zip file is 5 MB.</p> <p>When using the AWS CLI tool to create a script, this parameter is set to the zip file name. It must be prepended with the string "fileb://" to indicate that the file data is a binary object. For example: <code>--zip-file fileb://myRealtimeScript.zip</code>.</p>
     *  unsupported
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString zipFile;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    public:
        Aws::GameLift::Model::UpdateScriptRequest toAWS() const {
            Aws::GameLift::Model::UpdateScriptRequest awsUpdateScriptRequest;

            if (!(this->scriptId.IsEmpty())) {
                awsUpdateScriptRequest.SetScriptId(TCHAR_TO_UTF8(*this->scriptId));
            }

            if (!(this->name.IsEmpty())) {
                awsUpdateScriptRequest.SetName(TCHAR_TO_UTF8(*this->name));
            }

            if (!(this->version.IsEmpty())) {
                awsUpdateScriptRequest.SetVersion(TCHAR_TO_UTF8(*this->version));
            }

            if (!(this->storageLocation.IsEmpty())) {
                awsUpdateScriptRequest.SetStorageLocation(this->storageLocation.toAWS());
            }

            if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*this->zipFile)) {
            IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

            IFileHandle* FileHandle = PlatformFile.OpenRead(*this->zipFile);
            if(FileHandle) {
                uint8* ByteBuffer = (uint8*)FMemory::Malloc(FPlatformFileManager::Get().GetPlatformFile().FileSize(*this->zipFile));

                FileHandle->Read(ByteBuffer, sizeof(ByteBuffer));

                awsUpdateScriptRequest.SetZipFile(Aws::Utils::CryptoBuffer(Aws::Utils::ByteBuffer(ByteBuffer, sizeof(ByteBuffer))));

                delete FileHandle;
                FMemory::Free(ByteBuffer);
            }
        }

            return awsUpdateScriptRequest;
        }

        bool IsEmpty() const {
            return this->scriptId.IsEmpty() && this->name.IsEmpty() && this->version.IsEmpty() && this->storageLocation.IsEmpty() && !FPlatformFileManager::Get().GetPlatformFile().FileExists(*this->zipFile);
        }
#endif
};
