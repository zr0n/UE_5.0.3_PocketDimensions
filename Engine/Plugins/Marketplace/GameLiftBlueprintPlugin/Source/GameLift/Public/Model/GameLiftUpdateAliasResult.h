/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/UpdateAliasResult.h"

#endif

#include "Model/Alias.h"

#include "GameLiftUpdateAliasResult.generated.h"

USTRUCT(BlueprintType)
struct FGameLiftUpdateAliasResult {
    GENERATED_BODY()

    /**
    *  <p>Object that contains the updated alias configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FAlias alias;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FGameLiftUpdateAliasResult &fromAWS(const Aws::GameLift::Model::UpdateAliasResult &awsUpdateAliasResult) {
        this->alias.fromAWS(awsUpdateAliasResult.GetAlias());

        return *this;
    }
#endif
};
