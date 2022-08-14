/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ListGameServersResult.h"

#endif

#include "Model/GameServer.h"

#include "ListGameServersResult.generated.h"

USTRUCT(BlueprintType)
struct FListGameServersResult {
    GENERATED_BODY()

    /**
    *  <p>A collection of game server objects that match the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FGameServer> gameServers;

    /**
    *  <p>A token that indicates where to resume retrieving results on the next call to this action. If no token is returned, these results represent the end of the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FListGameServersResult &fromAWS(const Aws::GameLift::Model::ListGameServersResult &awsListGameServersResult) {
        this->gameServers.Empty();
        for (const Aws::GameLift::Model::GameServer& elem : awsListGameServersResult.GetGameServers()) {
            this->gameServers.Add(FGameServer().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListGameServersResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
