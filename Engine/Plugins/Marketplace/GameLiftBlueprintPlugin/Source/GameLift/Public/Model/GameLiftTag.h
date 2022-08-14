/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/Tag.h"

#endif

#include "GameLiftTag.generated.h"

USTRUCT(BlueprintType)
struct FGameLiftTag {
    GENERATED_BODY()

    /**
    *  <p> The key for a developer-defined key:value pair for tagging an AWS resource. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString key;

    /**
    *  <p> The value for a developer-defined key:value pair for tagging an AWS resource. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString value;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::Tag toAWS() const {
        Aws::GameLift::Model::Tag awsTag;

		if (!(this->key.IsEmpty())) {
            awsTag.SetKey(TCHAR_TO_UTF8(*this->key));
        }

		if (!(this->value.IsEmpty())) {
            awsTag.SetValue(TCHAR_TO_UTF8(*this->value));
        }

        return awsTag;
    }

    bool IsEmpty() const {
        return this->key.IsEmpty() && this->value.IsEmpty();
    }

    FGameLiftTag &fromAWS(const Aws::GameLift::Model::Tag &awsTag) {
        this->key = UTF8_TO_TCHAR(awsTag.GetKey().c_str());

        this->value = UTF8_TO_TCHAR(awsTag.GetValue().c_str());

        return *this;
    }
#endif
};
