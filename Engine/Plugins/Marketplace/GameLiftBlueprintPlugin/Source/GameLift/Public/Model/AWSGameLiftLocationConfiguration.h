/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/LocationConfiguration.h"

#endif

#include "AWSGameLiftLocationConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftLocationConfiguration {
GENERATED_BODY()

    /**
    *  <p>An AWS Region code, such as <code>us-west-2</code>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString location;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::LocationConfiguration toAWS() const {
        Aws::GameLift::Model::LocationConfiguration awsLocationConfiguration;

        if (!(this->location.IsEmpty())) {
            awsLocationConfiguration.SetLocation(TCHAR_TO_UTF8(*this->location));
        }

        return awsLocationConfiguration;
    }

    bool IsEmpty() const {
        return this->location.IsEmpty();
    }
#endif
};
