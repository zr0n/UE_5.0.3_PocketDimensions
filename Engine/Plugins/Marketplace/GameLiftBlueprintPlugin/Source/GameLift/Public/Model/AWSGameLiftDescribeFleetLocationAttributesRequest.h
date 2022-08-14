/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeFleetLocationAttributesRequest.h"

#endif

#include "AWSGameLiftDescribeFleetLocationAttributesRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftDescribeFleetLocationAttributesRequest {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the fleet to retrieve remote locations for. You can use either the fleet ID or ARN value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>A list of fleet locations to retrieve information for. Specify locations in the form of an AWS Region code, such as <code>us-west-2</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FString> locations;

    /**
    *  <p>The maximum number of results to return. Use this parameter with <code>NextToken</code> to get results as a set of sequential pages. This limit is not currently enforced. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int limit = 0;

    /**
    *  <p>A token that indicates the start of the next sequential page of results. Use the token that is returned with a previous call to this operation. To start at the beginning of the result set, do not specify a value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DescribeFleetLocationAttributesRequest toAWS() const {
        Aws::GameLift::Model::DescribeFleetLocationAttributesRequest awsDescribeFleetLocationAttributesRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsDescribeFleetLocationAttributesRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        for (const FString& elem : this->locations) {
            awsDescribeFleetLocationAttributesRequest.AddLocations(TCHAR_TO_UTF8(*elem));
        }

        if (!(this->limit == 0)) {
            awsDescribeFleetLocationAttributesRequest.SetLimit(this->limit);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsDescribeFleetLocationAttributesRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsDescribeFleetLocationAttributesRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty() && this->locations.Num() == 0 && this->limit == 0 && this->nextToken.IsEmpty();
    }
#endif
};
