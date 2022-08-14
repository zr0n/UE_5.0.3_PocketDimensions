/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ListFleetsResult.h"

#endif

#include "ListFleetsResult.generated.h"

USTRUCT(BlueprintType)
struct FListFleetsResult {
GENERATED_BODY()

    /**
    *  <p>Set of fleet IDs matching the list request. You can retrieve additional information about all returned fleets by passing this result set to a call to <a>DescribeFleetAttributes</a>, <a>DescribeFleetCapacity</a>, or <a>DescribeFleetUtilization</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FString> fleetIds;

    /**
    *  <p>Token that indicates where to resume retrieving results on the next call to this action. If no token is returned, these results represent the end of the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FListFleetsResult &fromAWS(const Aws::GameLift::Model::ListFleetsResult &awsListFleetsResult) {
        this->fleetIds.Empty();
        for (const Aws::String& elem : awsListFleetsResult.GetFleetIds()) {
            this->fleetIds.Add(elem.c_str());
        }

        this->nextToken = UTF8_TO_TCHAR(awsListFleetsResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
