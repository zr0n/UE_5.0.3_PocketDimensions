/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeGameSessionDetailsResult.h"

#endif

#include "Model/GameSessionDetail.h"

#include "DescribeGameSessionDetailsResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeGameSessionDetailsResult {
GENERATED_BODY()

    /**
    *  <p>Collection of objects containing game session properties and the protection policy currently in force for each session matching the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FAWSGameSessionDetail> gameSessionDetails;

    /**
    *  <p>Token that indicates where to resume retrieving results on the next call to this action. If no token is returned, these results represent the end of the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDescribeGameSessionDetailsResult &fromAWS(const Aws::GameLift::Model::DescribeGameSessionDetailsResult &awsDescribeGameSessionDetailsResult) {
        this->gameSessionDetails.Empty();
        for (const Aws::GameLift::Model::GameSessionDetail& elem : awsDescribeGameSessionDetailsResult.GetGameSessionDetails()) {
            this->gameSessionDetails.Add(FAWSGameSessionDetail().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsDescribeGameSessionDetailsResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
