/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeInstancesRequest.h"

#endif

#include "DescribeInstancesRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeInstancesRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a fleet to retrieve instance information for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>Unique identifier for an instance to retrieve. Specify an instance ID or leave blank to retrieve all instances in the fleet.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString instanceId;

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

    /**
    *  <p>A fleet location to get game sessions for. You can specify a fleet's home Region or a remote location. Use the AWS Region code format, such as <code>us-west-2</code>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString location;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DescribeInstancesRequest toAWS() const {
        Aws::GameLift::Model::DescribeInstancesRequest awsDescribeInstancesRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsDescribeInstancesRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        if (!(this->instanceId.IsEmpty())) {
            awsDescribeInstancesRequest.SetInstanceId(TCHAR_TO_UTF8(*this->instanceId));
        }

        if (this->limit != 0) {
            awsDescribeInstancesRequest.SetLimit(this->limit);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsDescribeInstancesRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

		if (!(this->location.IsEmpty())) {
            awsDescribeInstancesRequest.SetLocation(TCHAR_TO_UTF8(*this->location));
        }

        return awsDescribeInstancesRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty() && this->instanceId.IsEmpty() && this->limit == 0 && this->nextToken.IsEmpty() && this->location.IsEmpty();
    }
#endif
};
