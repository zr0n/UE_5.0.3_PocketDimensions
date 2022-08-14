/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeGameSessionsResult.h"

#endif

#include "Model/AWSGameSession.h"

#include "DescribeGameSessionsResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeGameSessionsResult {
GENERATED_BODY()

    /**
    *  <p>Collection of objects containing game session properties for each session matching the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FAWSGameSession> gameSessions;

    /**
    *  <p>Token that indicates where to resume retrieving results on the next call to this action. If no token is returned, these results represent the end of the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDescribeGameSessionsResult &fromAWS(const Aws::GameLift::Model::DescribeGameSessionsResult &awsDescribeGameSessionsResult) {
        this->gameSessions.Empty();
        for (const Aws::GameLift::Model::GameSession& elem : awsDescribeGameSessionsResult.GetGameSessions()) {
            this->gameSessions.Add(FAWSGameSession().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsDescribeGameSessionsResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
