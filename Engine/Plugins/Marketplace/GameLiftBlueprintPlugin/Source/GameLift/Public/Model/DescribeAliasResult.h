/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeAliasResult.h"

#endif

#include "Model/Alias.h"

#include "DescribeAliasResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeAliasResult {
GENERATED_BODY()

    /**
    *  <p>Object that contains the requested alias.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FAlias alias;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDescribeAliasResult &fromAWS(const Aws::GameLift::Model::DescribeAliasResult &awsDescribeAliasResult) {
        this->alias.fromAWS(awsDescribeAliasResult.GetAlias());

        return *this;
    }
#endif
};
