/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeGameSessionsRequest.h"

#endif

#include "Utils/GameLiftUtils.h"

#include "GameLiftGlobals.h"

#include "DescribeGameSessionsRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeGameSessionsRequest {
GENERATED_BODY()

    /**
	 * <p>Unique identifier for a fleet, game session and an alias to retrieve all game sessions for.</p>
	 * fleetId / gameSessionId / aliasId
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Client")
	FString awsResourceName;

    /**
    *  <p>A fleet location to get game sessions for. You can specify a fleet's home Region or a remote location. Use the AWS Region code format, such as <code>us-west-2</code>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString location;

    /**
    *  <p>Game session status to filter results on. Possible game session statuses include <code>ACTIVE</code>, <code>TERMINATED</code>, <code>ACTIVATING</code>, and <code>TERMINATING</code> (the last two are transitory). </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString statusFilter;

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
    Aws::GameLift::Model::DescribeGameSessionsRequest toAWS() const {
        Aws::GameLift::Model::DescribeGameSessionsRequest awsDescribeGameSessionsRequest;

        switch (UGameLiftUtils::IdentifyGameLiftARNType(this->awsResourceName)) {
            case EGameLiftARNType::Fleet_Id:
				awsDescribeGameSessionsRequest.SetFleetId(TCHAR_TO_UTF8(*this->awsResourceName));
                break;
            case EGameLiftARNType::GameSession_Id:
				awsDescribeGameSessionsRequest.SetGameSessionId(TCHAR_TO_UTF8(*this->awsResourceName));
                break;
            case EGameLiftARNType::Alias_Id:
				awsDescribeGameSessionsRequest.SetAliasId(TCHAR_TO_UTF8(*this->awsResourceName));
                break;
            default:
                LOG_GAMELIFT_ERROR("Illegal string");
                break;
		}

		if (!(this->location.IsEmpty())) {
            awsDescribeGameSessionsRequest.SetLocation(TCHAR_TO_UTF8(*this->location));
        }

        if (!(this->statusFilter.IsEmpty())) {
            awsDescribeGameSessionsRequest.SetStatusFilter(TCHAR_TO_UTF8(*this->statusFilter));
        }

        if (this->limit != 0) {
            awsDescribeGameSessionsRequest.SetLimit(this->limit);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsDescribeGameSessionsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsDescribeGameSessionsRequest;
    }

    bool IsEmpty() const {
        return this->awsResourceName.IsEmpty() && this->location.IsEmpty() && this->statusFilter.IsEmpty() && this->limit == 0 && this->nextToken.IsEmpty();
    }
#endif
};
