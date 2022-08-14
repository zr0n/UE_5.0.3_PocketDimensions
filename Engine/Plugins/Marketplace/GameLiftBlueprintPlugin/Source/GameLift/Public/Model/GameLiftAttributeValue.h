/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/AttributeValue.h"

#endif

#include "GameLiftAttributeValue.generated.h"

USTRUCT(BlueprintType)
struct FGameLiftAttributeValue {
    GENERATED_BODY()

    /**
    *  <p>For single string values. Maximum string length is 100 characters.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString s;

    /**
    *  <p>For number values, expressed as double.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    float n = 0.0f;

    /**
    *  <p>For a list of up to 10 strings. Maximum length for each string is 100 characters. Duplicate values are not recognized; all occurrences of the repeated value after the first of a repeated value are ignored.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FString> sL;

    /**
    *  <p>For a map of up to 10 data type:value pairs. Maximum length for each string value is 100 characters. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TMap<FString, float> sDM;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::AttributeValue toAWS() const {
        Aws::GameLift::Model::AttributeValue awsAttributeValue;

        if (!(this->s.IsEmpty())) {
            awsAttributeValue.SetS(TCHAR_TO_UTF8(*this->s));
        }

        if (this->n != 0) {
            awsAttributeValue.SetN(this->n);
        }

        for (const FString& elem : this->sL) {
            awsAttributeValue.AddSL(TCHAR_TO_UTF8(*elem));
        }

        for (const TPair<FString, float>& elem : this->sDM) {
            awsAttributeValue.AddSDM(TCHAR_TO_UTF8(*elem.Key), elem.Value);
        }

        return awsAttributeValue;
    }

    bool IsEmpty() const {
        return this->s.IsEmpty() && this->n == 0 && this->sL.Num() == 0 && this->sDM.Num() == 0;
    }

    FGameLiftAttributeValue &fromAWS(const Aws::GameLift::Model::AttributeValue &awsAttributeValue) {
        this->s = UTF8_TO_TCHAR(awsAttributeValue.GetS().c_str());

        this->n = (float)awsAttributeValue.GetN();

        this->sL.Empty();
        for (const Aws::String& elem : awsAttributeValue.GetSL()) {
            this->sL.Add(elem.c_str());
        }

        this->sDM.Empty();
        for (const auto& elem : awsAttributeValue.GetSDM()) {
            this->sDM.Add(elem.first.c_str(), (float)elem.second);
        }

        return *this;
    }
#endif
};
