/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribePlayerSessionsResult.h"

#endif

#include "Model/PlayerSession.h"

#include "DescribePlayerSessionsResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribePlayerSessionsResult {
GENERATED_BODY()

    /**
    *  <p>Collection of objects containing properties for each player session that matches the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FAWSPlayerSession> playerSessions;

    /**
    *  <p>Token that indicates where to resume retrieving results on the next call to this action. If no token is returned, these results represent the end of the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDescribePlayerSessionsResult &fromAWS(const Aws::GameLift::Model::DescribePlayerSessionsResult &awsDescribePlayerSessionsResult) {
        this->playerSessions.Empty();
        for (const Aws::GameLift::Model::PlayerSession& elem : awsDescribePlayerSessionsResult.GetPlayerSessions()) {
            this->playerSessions.Add(FAWSPlayerSession().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsDescribePlayerSessionsResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
