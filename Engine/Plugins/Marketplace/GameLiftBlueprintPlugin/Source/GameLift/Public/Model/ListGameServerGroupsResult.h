/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ListGameServerGroupsResult.h"

#endif

#include "Model/GameServerGroup.h"

#include "ListGameServerGroupsResult.generated.h"

USTRUCT(BlueprintType)
struct FListGameServerGroupsResult {
GENERATED_BODY()

    /**
    *  <p>A collection of game server group objects that match the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FGameServerGroup> gameServerGroups;

    /**
    *  <p>A token that indicates where to resume retrieving results on the next call to this action. If no token is returned, these results represent the end of the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FListGameServerGroupsResult &fromAWS(const Aws::GameLift::Model::ListGameServerGroupsResult &awsListGameServerGroupsResult) {
        this->gameServerGroups.Empty();
        for (const Aws::GameLift::Model::GameServerGroup& elem : awsListGameServerGroupsResult.GetGameServerGroups()) {
            this->gameServerGroups.Add(FGameServerGroup().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListGameServerGroupsResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
