/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ListScriptsResult.h"

#endif

#include "Model/Script.h"

#include "ListScriptsResult.generated.h"

USTRUCT(BlueprintType)
struct FListScriptsResult {
GENERATED_BODY()

    /**
    *  <p>Set of properties describing the requested script.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FScript> scripts;

    /**
    *  <p>Token that indicates where to resume retrieving results on the next call to this action. If no token is returned, these results represent the end of the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FListScriptsResult &fromAWS(const Aws::GameLift::Model::ListScriptsResult &awsListScriptsResult) {
        this->scripts.Empty();
        for (const Aws::GameLift::Model::Script& elem : awsListScriptsResult.GetScripts()) {
            this->scripts.Add(FScript().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListScriptsResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
