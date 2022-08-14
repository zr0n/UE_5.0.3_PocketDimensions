/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/FilterConfiguration.h"

#endif

#include "AWSGameLiftFilterConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftFilterConfiguration {
GENERATED_BODY()

    /**
    *  <p> A list of locations to allow game session placement in, in the form of AWS Region codes such as <code>us-west-2</code>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FString> allowedLocations;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::FilterConfiguration toAWS() const {
        Aws::GameLift::Model::FilterConfiguration awsFilterConfiguration;

        for (const FString& elem : this->allowedLocations) {
            awsFilterConfiguration.AddAllowedLocations(TCHAR_TO_UTF8(*elem));
        }

        return awsFilterConfiguration;
    }

    bool IsEmpty() const {
        return this->allowedLocations.Num() == 0;
    }

    FAWSGameLiftFilterConfiguration &fromAWS(const Aws::GameLift::Model::FilterConfiguration &awsFilterConfiguration) {
        this->allowedLocations.Empty();
        for (const Aws::String& elem : awsFilterConfiguration.GetAllowedLocations()) {
            this->allowedLocations.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        return *this;
    }
#endif
};
