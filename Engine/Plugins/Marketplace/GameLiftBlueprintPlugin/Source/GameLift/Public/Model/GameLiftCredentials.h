/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/AwsCredentials.h"

#endif

#include "GameLiftCredentials.generated.h"

USTRUCT(BlueprintType)
struct FGameLiftCredentials {
    GENERATED_BODY()

    /**
    *  <p>Temporary key allowing access to the Amazon GameLift S3 account.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString accessKeyId;

    /**
    *  <p>Temporary secret key allowing access to the Amazon GameLift S3 account.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString secretAccessKey;

    /**
    *  <p>Token used to associate a specific build ID with the files uploaded using these credentials.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString sessionToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FGameLiftCredentials &fromAWS(const Aws::GameLift::Model::AwsCredentials &awsGameLiftCredentials) {

        this->accessKeyId = UTF8_TO_TCHAR(awsGameLiftCredentials.GetAccessKeyId().c_str());

        this->secretAccessKey = UTF8_TO_TCHAR(awsGameLiftCredentials.GetSecretAccessKey().c_str());

        this->sessionToken = UTF8_TO_TCHAR(awsGameLiftCredentials.GetSessionToken().c_str());

        return *this;
    }
#endif
};
