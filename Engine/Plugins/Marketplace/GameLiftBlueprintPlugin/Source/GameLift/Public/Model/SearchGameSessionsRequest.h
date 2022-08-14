/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/SearchGameSessionsRequest.h"

#endif

#include "Utils/GameLiftUtils.h"

#include "GameLiftGlobals.h"

#include "SearchGameSessionsRequest.generated.h"

USTRUCT(BlueprintType)
struct FSearchGameSessionsRequest {
GENERATED_BODY()

    /**
	 * <p>Unique identifier for a fleet and alias to search for active game sessions. Each
	 * request must reference either a fleet ID or alias ID, but not both.</p>
	 * fleetId / aliasId
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Client")
	FString awsResourceName;

    /**
    *  <p>A fleet location to search for game sessions. You can specify a fleet's home Region or a remote location. Use the AWS Region code format, such as <code>us-west-2</code>. </p> <p> </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString location;

    /**
    *  <p>String containing the search criteria for the session search. If no filter expression is included, the request returns results for all game sessions in the fleet that are in <code>ACTIVE</code> status.</p> <p>A filter expression can contain one or multiple conditions. Each condition consists of the following:</p> <ul> <li> <p> <b>Operand</b> -- Name of a game session attribute. Valid values are <code>gameSessionName</code>, <code>gameSessionId</code>, <code>gameSessionProperties</code>, <code>maximumSessions</code>, <code>creationTimeMillis</code>, <code>playerSessionCount</code>, <code>hasAvailablePlayerSessions</code>.</p> </li> <li> <p> <b>Comparator</b> -- Valid comparators are: <code>=</code>, <code>&lt;&gt;</code>, <code>&lt;</code>, <code>&gt;</code>, <code>&lt;=</code>, <code>&gt;=</code>. </p> </li> <li> <p> <b>Value</b> -- Value to be searched for. Values may be numbers, boolean values (true/false) or strings depending on the operand. String values are case sensitive and must be enclosed in single quotes. Special characters must be escaped. Boolean and string values can only be used with the comparators <code>=</code> and <code>&lt;&gt;</code>. For example, the following filter expression searches on <code>gameSessionName</code>: "<code>FilterExpression": "gameSessionName = 'Matt\\'s Awesome Game 1'"</code>. </p> </li> </ul> <p>To chain multiple conditions in a single expression, use the logical keywords <code>AND</code>, <code>OR</code>, and <code>NOT</code> and parentheses as needed. For example: <code>x AND y AND NOT z</code>, <code>NOT (x OR y)</code>.</p> <p>Session search evaluates conditions from left to right using the following precedence rules:</p> <ol> <li> <p> <code>=</code>, <code>&lt;&gt;</code>, <code>&lt;</code>, <code>&gt;</code>, <code>&lt;=</code>, <code>&gt;=</code> </p> </li> <li> <p>Parentheses</p> </li> <li> <p>NOT</p> </li> <li> <p>AND</p> </li> <li> <p>OR</p> </li> </ol> <p>For example, this filter expression retrieves game sessions hosting at least ten players that have an open player slot: <code>"maximumSessions&gt;=10 AND hasAvailablePlayerSessions=true"</code>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString filterExpression;

    /**
    *  <p>Instructions on how to sort the search results. If no sort expression is included, the request returns results in random order. A sort expression consists of the following elements:</p> <ul> <li> <p> <b>Operand</b> -- Name of a game session attribute. Valid values are <code>gameSessionName</code>, <code>gameSessionId</code>, <code>gameSessionProperties</code>, <code>maximumSessions</code>, <code>creationTimeMillis</code>, <code>playerSessionCount</code>, <code>hasAvailablePlayerSessions</code>.</p> </li> <li> <p> <b>Order</b> -- Valid sort orders are <code>ASC</code> (ascending) and <code>DESC</code> (descending).</p> </li> </ul> <p>For example, this sort expression returns the oldest active sessions first: <code>"SortExpression": "creationTimeMillis ASC"</code>. Results with a null value for the sort operand are returned at the end of the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString sortExpression;

    /**
    *  <p>The maximum number of results to return. Use this parameter with <code>NextToken</code> to get results as a set of sequential pages. The maximum number of results returned is 20, even if this value is not set or is set higher than 20. </p>
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
    Aws::GameLift::Model::SearchGameSessionsRequest toAWS() const {
        Aws::GameLift::Model::SearchGameSessionsRequest awsSearchGameSessionsRequest;

        switch (UGameLiftUtils::IdentifyGameLiftARNType(this->awsResourceName)) {
            case EGameLiftARNType::Fleet_Id:
                awsSearchGameSessionsRequest.SetFleetId(TCHAR_TO_UTF8(*this->awsResourceName));
                break;
            case EGameLiftARNType::Alias_Id:
                awsSearchGameSessionsRequest.SetAliasId(TCHAR_TO_UTF8(*this->awsResourceName));
                break;
            case EGameLiftARNType::GameSession_Id:
                LOG_GAMELIFT_ERROR("Game session id is not avaliable");
                break;
            default:
                LOG_GAMELIFT_ERROR("Illegal string");
                break;
		}

		if (!(this->location.IsEmpty())) {
            awsSearchGameSessionsRequest.SetLocation(TCHAR_TO_UTF8(*this->location));
        }

        if (!(this->filterExpression.IsEmpty())) {
            awsSearchGameSessionsRequest.SetFilterExpression(TCHAR_TO_UTF8(*this->filterExpression));
        }

        if (!(this->sortExpression.IsEmpty())) {
            awsSearchGameSessionsRequest.SetSortExpression(TCHAR_TO_UTF8(*this->sortExpression));
        }

        if (this->limit != 0) {
            awsSearchGameSessionsRequest.SetLimit(this->limit);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsSearchGameSessionsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsSearchGameSessionsRequest;
    }

    bool IsEmpty() const {
        return this->awsResourceName.IsEmpty() && this->location.IsEmpty() && this->filterExpression.IsEmpty() && this->sortExpression.IsEmpty() && this->limit == 0 && this->nextToken.IsEmpty();
    }
#endif
};
