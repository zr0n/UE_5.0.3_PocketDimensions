/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/GameProperty.h"

#endif

#include "GameProperty.generated.h"

USTRUCT(BlueprintType)
struct FGameProperty {
GENERATED_BODY()

    /**
    *  <p>Game property identifier.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString key;

    /**
    *  <p>Game property value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString value;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::GameProperty toAWS() const {
        Aws::GameLift::Model::GameProperty awsGameProperty;

        if (!(this->key.IsEmpty())) {
            awsGameProperty.SetKey(TCHAR_TO_UTF8(*this->key));
        }

        if (!(this->value.IsEmpty())) {
            awsGameProperty.SetValue(TCHAR_TO_UTF8(*this->value));
        }

        return awsGameProperty;
    }

    bool IsEmpty() const {
        return this->key.IsEmpty() && this->value.IsEmpty();
    }

    FGameProperty &fromAWS(const Aws::GameLift::Model::GameProperty &awsGameProperty) {
        this->key = UTF8_TO_TCHAR(awsGameProperty.GetKey().c_str());

        this->value = UTF8_TO_TCHAR(awsGameProperty.GetValue().c_str());

        return *this;
    }
#endif
};
