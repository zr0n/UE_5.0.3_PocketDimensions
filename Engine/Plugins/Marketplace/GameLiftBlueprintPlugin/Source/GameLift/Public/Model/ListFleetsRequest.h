/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ListFleetsRequest.h"

#endif

#include "ListFleetsRequest.generated.h"

USTRUCT(BlueprintType)
struct FListFleetsRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a build to return fleets for. Use this parameter to return only fleets using the specified build. To retrieve all fleets, leave this parameter empty.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString buildId;

    /**
    *  <p>Unique identifier for a Realtime script to return fleets for. Use this parameter to return only fleets using the specified script. To retrieve all fleets, leave this parameter empty.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString scriptId;

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
    Aws::GameLift::Model::ListFleetsRequest toAWS() const {
        Aws::GameLift::Model::ListFleetsRequest awsListFleetsRequest;

        if (!(this->buildId.IsEmpty())) {
            awsListFleetsRequest.SetBuildId(TCHAR_TO_UTF8(*this->buildId));
        }

        if (!(this->scriptId.IsEmpty())) {
            awsListFleetsRequest.SetScriptId(TCHAR_TO_UTF8(*this->scriptId));
        }

        if (this->limit != 0) {
            awsListFleetsRequest.SetLimit(this->limit);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsListFleetsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsListFleetsRequest;
    }

    bool IsEmpty() const {
        return this->buildId.IsEmpty() && this->scriptId.IsEmpty() && this->limit == 0 && this->nextToken.IsEmpty();
    }
#endif
};
