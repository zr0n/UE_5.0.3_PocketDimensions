/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeGameSessionPlacementRequest.h"

#endif

#include "DescribeGameSessionPlacementRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeGameSessionPlacementRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a game session placement to retrieve.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString placementId;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DescribeGameSessionPlacementRequest toAWS() const {
        Aws::GameLift::Model::DescribeGameSessionPlacementRequest awsDescribeGameSessionPlacementRequest;

        if (!(this->placementId.IsEmpty())) {
            awsDescribeGameSessionPlacementRequest.SetPlacementId(TCHAR_TO_UTF8(*this->placementId));
        }

        return awsDescribeGameSessionPlacementRequest;
    }

    bool IsEmpty() const {
        return this->placementId.IsEmpty();
    }
#endif
};
