/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreateAliasResult.h"

#endif

#include "Model/Alias.h"

#include "GameLiftCreateAliasResult.generated.h"

USTRUCT(BlueprintType)
struct FGameLiftCreateAliasResult {
GENERATED_BODY()

    /**
    *  <p>Object that describes the newly created alias record.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FAlias alias;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FGameLiftCreateAliasResult &fromAWS(const Aws::GameLift::Model::CreateAliasResult &awsCreateAliasResult) {
        this->alias.fromAWS(awsCreateAliasResult.GetAlias());

        return *this;
    }
#endif
};
