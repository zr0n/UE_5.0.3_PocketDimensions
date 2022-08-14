/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeGameServerGroupResult.h"

#endif

#include "Model/GameServerGroup.h"

#include "DescribeGameServerGroupResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeGameServerGroupResult {
    GENERATED_BODY()

    /**
    *  <p>An object that describes the requested game server group resource. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FGameServerGroup gameServerGroup;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDescribeGameServerGroupResult &fromAWS(const Aws::GameLift::Model::DescribeGameServerGroupResult &awsDescribeGameServerGroupResult) {
        this->gameServerGroup.fromAWS(awsDescribeGameServerGroupResult.GetGameServerGroup());

        return *this;
    }
#endif
};
