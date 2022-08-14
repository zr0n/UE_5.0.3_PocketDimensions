/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ListAliasesResult.h"

#endif

#include "Model/Alias.h"

#include "GameLiftListAliasesResult.generated.h"

USTRUCT(BlueprintType)
struct FGameLiftListAliasesResult {
GENERATED_BODY()

    /**
    *  <p>Collection of alias records that match the list request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FAlias> aliases;

    /**
    *  <p>Token that indicates where to resume retrieving results on the next call to this action. If no token is returned, these results represent the end of the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FGameLiftListAliasesResult &fromAWS(const Aws::GameLift::Model::ListAliasesResult &awsListAliasesResult) {
        this->aliases.Empty();
        for (const Aws::GameLift::Model::Alias& elem : awsListAliasesResult.GetAliases()) {
            this->aliases.Add(FAlias().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListAliasesResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
