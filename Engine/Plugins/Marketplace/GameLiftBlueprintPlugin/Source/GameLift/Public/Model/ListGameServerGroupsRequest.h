/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ListGameServerGroupsRequest.h"

#endif

#include "ListGameServerGroupsRequest.generated.h"

USTRUCT(BlueprintType)
struct FListGameServerGroupsRequest {
GENERATED_BODY()

    /**
    *  <p>The maximum number of results to return. Use this parameter with <code>NextToken</code> to get results as a set of sequential pages.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int limit = 0;

    /**
    *  <p>A token that indicates the start of the next sequential page of results. Use the token that is returned with a previous call to this action. To start at the beginning of the result set, do not specify a value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::ListGameServerGroupsRequest toAWS() const {
        Aws::GameLift::Model::ListGameServerGroupsRequest awsListGameServerGroupsRequest;

        if (!(this->limit == 0)) {
            awsListGameServerGroupsRequest.SetLimit(this->limit);
        }

		if (!(this->nextToken.IsEmpty())) {
            awsListGameServerGroupsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsListGameServerGroupsRequest;
    }

    bool IsEmpty() const {
        return this->limit == 0 && this->nextToken.IsEmpty();
    }
#endif
};
