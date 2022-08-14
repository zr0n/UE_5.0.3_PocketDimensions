/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFT

#include "aws/gamelift/server/model/DescribePlayerSessionsRequest.h"

#endif

#include "DescribePlayerSessionsRequestServer.generated.h"

USTRUCT(BlueprintType)
struct FDescribePlayerSessionsRequestServer {
    GENERATED_BODY()

    /**
     * <p>Unique identifier for the game session to get player sessions for.Game
     * session ID format is as follows:
     * "arn:aws:gamelift:&lt;region&gt;::gamesession/fleet-&lt;fleet ID&gt;/&lt;ID
     * string&gt;". The value of &lt;ID string&gt; is either a custom ID string (if one
     * was specified when the game session was created) an auto-generated string. </p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString gameSessionId;

    /**
     * <p>Unique identifier for a player.</p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString playerId;

    /**
     * <p>Unique identifier for a player session.</p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString playerSessionId;

    /**
     * <p>Player session status to filter results on.</p> <p>Possible player session
     * statuses include the following:</p> <ul> <li> <p> <b>RESERVED</b> – The player
     * session request has been received, but the player has not yet connected to the
     * server process and/or been validated. </p> </li> <li> <p> <b>ACTIVE</b> – The
     * player has been validated by the server process and is currently connected.</p>
     * </li> <li> <p> <b>COMPLETED</b> – The player connection has been dropped.</p>
     * </li> <li> <p> <b>TIMEDOUT</b> – A player session request was received, but the
     * player did not connect and/or was not validated within the time-out limit (60
     * seconds).</p> </li> </ul>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString playerSessionStatusFilter;

    /**
     * <p>Maximum number of results to return. Use this parameter with
     * <code>NextToken</code> to get results as a set of sequential pages. If a player
     * session ID is specified, this parameter is ignored.</p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    int limit = 0;

    /**
     * <p>Token indicating the start of the next sequential page of results. Use the
     * token that is returned with a previous call to this action. To specify the start
     * of the result set, do not specify a value. If a player session ID is specified,
     * this parameter is ignored.</p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString nextToken;

#if WITH_GAMELIFT
    public:
    Aws::GameLift::Server::Model::DescribePlayerSessionsRequest toAWS() const {
        Aws::GameLift::Server::Model::DescribePlayerSessionsRequest awsDescribePlayerSessionsRequest;

        awsDescribePlayerSessionsRequest.SetGameSessionId(TCHAR_TO_UTF8(*this->gameSessionId));
        awsDescribePlayerSessionsRequest.SetPlayerId(TCHAR_TO_UTF8(*this->playerId));
        awsDescribePlayerSessionsRequest.SetPlayerSessionId(TCHAR_TO_UTF8(*this->playerSessionId));
        awsDescribePlayerSessionsRequest.SetPlayerSessionStatusFilter(TCHAR_TO_UTF8(*this->playerSessionStatusFilter));
        awsDescribePlayerSessionsRequest.SetLimit(this->limit);
        awsDescribePlayerSessionsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));

        return awsDescribePlayerSessionsRequest;
    };

#endif
};