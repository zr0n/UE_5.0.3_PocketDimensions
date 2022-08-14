/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeGameServerInstancesResult.h"

#endif

#include "Model/GameServerInstance.h"

#include "DescribeGameServerInstancesResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeGameServerInstancesResult {
GENERATED_BODY()

    /**
    *  <p> The collection of requested game server instances. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FGameServerInstance> gameServerInstances;

    /**
    *  <p> A token that indicates where to resume retrieving results on the next call to this operation. If no token is returned, these results represent the end of the list. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:

    FDescribeGameServerInstancesResult &fromAWS(const Aws::GameLift::Model::DescribeGameServerInstancesResult &awsDescribeGameServerInstancesResult) {
// @TODO: check
        this->gameServerInstances.Empty();
        for (const Aws::GameLift::Model::GameServerInstance& elem : awsDescribeGameServerInstancesResult.GetGameServerInstances()) {
            this->gameServerInstances.Add(FGameServerInstance().fromAWS(elem));
        }

// @TODO: check
        this->nextToken = UTF8_TO_TCHAR(awsDescribeGameServerInstancesResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
