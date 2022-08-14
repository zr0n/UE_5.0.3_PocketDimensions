/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ListTagsForResourceResult.h"

#endif

#include "Model/GameLiftTag.h"

#include "GameLiftListTagsForResourceResult.generated.h"

USTRUCT(BlueprintType)
struct FGameLiftListTagsForResourceResult {
GENERATED_BODY()

    /**
    *  <p> The collection of tags that have been assigned to the specified resource. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FGameLiftTag> tags;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FGameLiftListTagsForResourceResult &fromAWS(const Aws::GameLift::Model::ListTagsForResourceResult &awsListTagsForResourceResult) {
        this->tags.Empty();
        for (const Aws::GameLift::Model::Tag& elem : awsListTagsForResourceResult.GetTags()) {
            this->tags.Add(FGameLiftTag().fromAWS(elem));
        }

        return *this;
    }
#endif
};
