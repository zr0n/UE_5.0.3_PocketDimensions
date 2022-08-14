/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/InstanceCredentials.h"

#endif

#include "InstanceCredentials.generated.h"

USTRUCT(BlueprintType)
struct FInstanceCredentials {
GENERATED_BODY()

    /**
    *  <p>User login string.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString userName;

    /**
    *  <p>Secret string. For Windows instances, the secret is a password for use with Windows Remote Desktop. For Linux instances, it is a private key (which must be saved as a <code>.pem</code> file) for use with SSH.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString secret;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FInstanceCredentials &fromAWS(const Aws::GameLift::Model::InstanceCredentials &awsInstanceCredentials) {
        this->userName = UTF8_TO_TCHAR(awsInstanceCredentials.GetUserName().c_str());

        this->secret = UTF8_TO_TCHAR(awsInstanceCredentials.GetSecret().c_str());

        return *this;
    }
#endif
};
