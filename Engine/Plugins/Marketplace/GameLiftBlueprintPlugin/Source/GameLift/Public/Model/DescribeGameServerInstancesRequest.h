/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeGameServerInstancesRequest.h"

#endif

#include "DescribeGameServerInstancesRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeGameServerInstancesRequest {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the game server group. Use either the <a>GameServerGroup</a> name or ARN value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerGroupName;

    /**
    *  <p>The EC2 instance IDs that you want to retrieve status on. EC2 instance IDs use a 17-character format, for example: <code>i-1234567890abcdef0</code>. To retrieve all instances in the game server group, leave this parameter empty. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FString> instanceIds;

    /**
    *  <p> The maximum number of results to return. Use this parameter with <code>NextToken</code> to get results as a set of sequential segments. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int limit = 0;

    /**
    *  <p> A token that indicates the start of the next sequential segment of results. Use the token returned with the previous call to this operation. To start at the beginning of the result set, do not specify a value. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DescribeGameServerInstancesRequest toAWS() const {
        Aws::GameLift::Model::DescribeGameServerInstancesRequest awsDescribeGameServerInstancesRequest;

		if (!(this->gameServerGroupName.IsEmpty())) {
            awsDescribeGameServerInstancesRequest.SetGameServerGroupName(TCHAR_TO_UTF8(*this->gameServerGroupName));
        }

        for (const FString& elem : this->instanceIds) {
            awsDescribeGameServerInstancesRequest.AddInstanceIds(TCHAR_TO_UTF8(*elem));
        }

        if (!(this->limit == 0)) {
            awsDescribeGameServerInstancesRequest.SetLimit(this->limit);
        }

		if (!(this->nextToken.IsEmpty())) {
            awsDescribeGameServerInstancesRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsDescribeGameServerInstancesRequest;
    }

    bool IsEmpty() const {
        return this->gameServerGroupName.IsEmpty() && this->instanceIds.Num() == 0 && this->limit == 0 && this->nextToken.IsEmpty();
    }
#endif
};
