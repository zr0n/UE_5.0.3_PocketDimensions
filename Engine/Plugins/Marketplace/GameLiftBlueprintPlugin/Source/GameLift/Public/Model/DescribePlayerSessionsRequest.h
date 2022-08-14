/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribePlayerSessionsRequest.h"

#endif

#include "Utils/GameLiftUtils.h"

#include "GameLiftGlobals.h"

#include "DescribePlayerSessionsRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribePlayerSessionsRequest {
GENERATED_BODY()

    /**
	 * <p>Unique identifier for the game session to retrieve player sessions for.</p>
	 * gameSessionId
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Client")
	FString awsResourceName;

    /**
    *  <p>Unique identifier for a player to retrieve player sessions for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString playerId;

    /**
    *  <p>Unique identifier for a player session to retrieve.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString playerSessionId;

    /**
    *  <p>Player session status to filter results on.</p> <p>Possible player session statuses include the following:</p> <ul> <li> <p> <b>RESERVED</b> -- The player session request has been received, but the player has not yet connected to the server process and/or been validated. </p> </li> <li> <p> <b>ACTIVE</b> -- The player has been validated by the server process and is currently connected.</p> </li> <li> <p> <b>COMPLETED</b> -- The player connection has been dropped.</p> </li> <li> <p> <b>TIMEDOUT</b> -- A player session request was received, but the player did not connect and/or was not validated within the timeout limit (60 seconds).</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString playerSessionStatusFilter;

    /**
    *  <p>Maximum number of results to return. Use this parameter with <code>NextToken</code> to get results as a set of sequential pages. If a player session ID is specified, this parameter is ignored.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int limit = 0;

    /**
    *  <p>Token that indicates the start of the next sequential page of results. Use the token that is returned with a previous call to this action. To start at the beginning of the result set, do not specify a value. If a player session ID is specified, this parameter is ignored.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DescribePlayerSessionsRequest toAWS() const {
        Aws::GameLift::Model::DescribePlayerSessionsRequest awsDescribePlayerSessionsRequest;

        if (!(this->awsResourceName.IsEmpty())) {
            switch (UGameLiftUtils::IdentifyGameLiftARNType(this->awsResourceName)) {
                case EGameLiftARNType::GameSession_Id:
                    awsDescribePlayerSessionsRequest.SetGameSessionId(TCHAR_TO_UTF8(*this->awsResourceName));
                    break;
                case EGameLiftARNType::Fleet_Id:
                case EGameLiftARNType::Alias_Id:
                    LOG_GAMELIFT_ERROR("fleet id or alias id is not avaliable");
                    break;
                default:
                    break;
            }
        }

        if (!(this->playerId.IsEmpty())) {
            awsDescribePlayerSessionsRequest.SetPlayerId(TCHAR_TO_UTF8(*this->playerId));
        }

        if (!(this->playerSessionId.IsEmpty())) {
            awsDescribePlayerSessionsRequest.SetPlayerSessionId(TCHAR_TO_UTF8(*this->playerSessionId));
        }

        if (!(this->playerSessionStatusFilter.IsEmpty())) {
        awsDescribePlayerSessionsRequest.SetPlayerSessionStatusFilter(TCHAR_TO_UTF8(*this->playerSessionStatusFilter));
        }

        if (this->limit != 0) {
            awsDescribePlayerSessionsRequest.SetLimit(this->limit);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsDescribePlayerSessionsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsDescribePlayerSessionsRequest;
    }

    bool IsEmpty() const {
        return this->awsResourceName.IsEmpty() && this->playerId.IsEmpty() && this->playerSessionId.IsEmpty() && this->playerSessionStatusFilter.IsEmpty() && this->limit == 0 && this->nextToken.IsEmpty();
    }
#endif
};
