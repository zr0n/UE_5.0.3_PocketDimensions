/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeAliasRequest.h"

#endif

#include "DescribeAliasRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeAliasRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a fleet alias. Specify the alias you want to retrieve.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString aliasId;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DescribeAliasRequest toAWS() const {
        Aws::GameLift::Model::DescribeAliasRequest awsDescribeAliasRequest;

        if (!(this->aliasId.IsEmpty())) {
            awsDescribeAliasRequest.SetAliasId(TCHAR_TO_UTF8(*this->aliasId));
        }

        return awsDescribeAliasRequest;
    }

    bool IsEmpty() const {
        return this->aliasId.IsEmpty();
    }
#endif
};
