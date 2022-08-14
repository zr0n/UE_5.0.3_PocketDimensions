/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ListScriptsRequest.h"

#endif

#include "ListScriptsRequest.generated.h"

USTRUCT(BlueprintType)
struct FListScriptsRequest {
GENERATED_BODY()

    /**
    *  <p>Maximum number of results to return. Use this parameter with <code>NextToken</code> to get results as a set of sequential pages.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int limit = 0;

    /**
    *  <p>Token that indicates the start of the next sequential page of results. Use the token that is returned with a previous call to this action. To start at the beginning of the result set, do not specify a value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::ListScriptsRequest toAWS() const {
        Aws::GameLift::Model::ListScriptsRequest awsListScriptsRequest;

        if (this->limit != 0) {
            awsListScriptsRequest.SetLimit(this->limit);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsListScriptsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsListScriptsRequest;
    }

    bool IsEmpty() const {
        return this->limit == 0 && this->nextToken.IsEmpty();
    }
#endif
};
