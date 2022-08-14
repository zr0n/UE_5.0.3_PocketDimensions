/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeGameServerResult.h"

#endif

#include "Model/GameServer.h"

#include "DescribeGameServerResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeGameServerResult {
GENERATED_BODY()

    /**
    *  <p>Object that describes the requested game server resource.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FGameServer gameServer;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDescribeGameServerResult &fromAWS(const Aws::GameLift::Model::DescribeGameServerResult &awsDescribeGameServerResult) {
        this->gameServer.fromAWS(awsDescribeGameServerResult.GetGameServer());

        return *this;
    }
#endif
};
