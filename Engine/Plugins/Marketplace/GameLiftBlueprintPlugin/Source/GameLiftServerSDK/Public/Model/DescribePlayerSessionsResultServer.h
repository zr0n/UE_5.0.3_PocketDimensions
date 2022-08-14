/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFT

#include "aws/gamelift/server/model/DescribePlayerSessionsResult.h"

#endif

#include "DescribePlayerSessionsResultServer.generated.h"

USTRUCT(BlueprintType)
    struct FDescribePlayerSessionsResultServer {
        GENERATED_BODY()

     /**
     * <p>Collection of objects containing properties for each player session that
     * matches the request.</p>
	 * don't add more than 50 elements
	 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    TArray<FAWSPlayerSessionServer> playerSessions;

    /**
    * <p>Token indicating where to resume retrieving results on the next call to this
    * action. If no token is returned, these results represent the end of the
    * list.</p>
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString nextToken;

#if WITH_GAMELIFT
    public:
    FDescribePlayerSessionsResultServer& fromAWS(const Aws::GameLift::Server::Model::DescribePlayerSessionsResult& awsDescribePlayerSessionsResult) {
    	int count = 0;
    	const Aws::GameLift::Server::Model::PlayerSession* awsPlayerSessions = awsDescribePlayerSessionsResult.GetPlayerSessions(count);
        this->playerSessions.Empty();
        for (int i = 0; i < count; i++) {
            this->playerSessions.Add(FAWSPlayerSessionServer().fromAWS(awsPlayerSessions[i]));
        }
        this->nextToken = awsDescribePlayerSessionsResult.GetNextToken();

        return *this;
    };

#endif
};