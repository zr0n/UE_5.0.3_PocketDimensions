/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeGameSessionQueuesResult.h"

#endif

#include "Model/GameSessionQueue.h"

#include "DescribeGameSessionQueuesResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeGameSessionQueuesResult {
GENERATED_BODY()

    /**
    *  <p>Collection of objects that describes the requested game session queues.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FGameSessionQueue> gameSessionQueues;

    /**
    *  <p>Token that indicates where to resume retrieving results on the next call to this action. If no token is returned, these results represent the end of the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDescribeGameSessionQueuesResult &fromAWS(const Aws::GameLift::Model::DescribeGameSessionQueuesResult &awsDescribeGameSessionQueuesResult) {
        this->gameSessionQueues.Empty();
        for (const Aws::GameLift::Model::GameSessionQueue& elem : awsDescribeGameSessionQueuesResult.GetGameSessionQueues()) {
            this->gameSessionQueues.Add(FGameSessionQueue().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsDescribeGameSessionQueuesResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
