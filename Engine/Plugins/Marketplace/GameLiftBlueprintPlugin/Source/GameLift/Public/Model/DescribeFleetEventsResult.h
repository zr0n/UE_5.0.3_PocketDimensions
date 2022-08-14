/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeFleetEventsResult.h"

#endif

#include "Model/AWSEvent.h"

#include "DescribeFleetEventsResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeFleetEventsResult {
GENERATED_BODY()

    /**
    *  <p>Collection of objects containing event log entries for the specified fleet.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FAWSEvent> events;

    /**
    *  <p>Token that indicates where to resume retrieving results on the next call to this action. If no token is returned, these results represent the end of the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDescribeFleetEventsResult &fromAWS(const Aws::GameLift::Model::DescribeFleetEventsResult &awsDescribeFleetEventsResult) {
        this->events.Empty();
        for (const Aws::GameLift::Model::Event& elem : awsDescribeFleetEventsResult.GetEvents()) {
            this->events.Add(FAWSEvent().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsDescribeFleetEventsResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
