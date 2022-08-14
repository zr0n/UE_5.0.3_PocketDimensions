/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeGameSessionPlacementResult.h"

#endif

#include "Model/GameSessionPlacement.h"

#include "DescribeGameSessionPlacementResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeGameSessionPlacementResult {
GENERATED_BODY()

    /**
    *  <p>Object that describes the requested game session placement.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FGameSessionPlacement gameSessionPlacement;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDescribeGameSessionPlacementResult &fromAWS(const Aws::GameLift::Model::DescribeGameSessionPlacementResult &awsDescribeGameSessionPlacementResult) {
        this->gameSessionPlacement.fromAWS(awsDescribeGameSessionPlacementResult.GetGameSessionPlacement());

        return *this;
    }
#endif
};
