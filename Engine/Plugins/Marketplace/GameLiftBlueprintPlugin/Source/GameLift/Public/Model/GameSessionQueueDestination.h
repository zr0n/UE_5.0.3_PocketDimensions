/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/GameSessionQueueDestination.h"

#endif

#include "GameSessionQueueDestination.generated.h"

USTRUCT(BlueprintType)
struct FGameSessionQueueDestination {
GENERATED_BODY()

    /**
    *  <p>Amazon Resource Name (ARN) assigned to fleet or fleet alias. ARNs, which include a fleet ID or alias ID and a region name, provide a unique identifier across all regions. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString destinationArn;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::GameSessionQueueDestination toAWS() const {
        Aws::GameLift::Model::GameSessionQueueDestination awsGameSessionQueueDestination;

        if (!(this->destinationArn.IsEmpty())) {
            awsGameSessionQueueDestination.SetDestinationArn(TCHAR_TO_UTF8(*this->destinationArn));
        }

        return awsGameSessionQueueDestination;
    }

    bool IsEmpty() const {
        return this->destinationArn.IsEmpty();
    }
    FGameSessionQueueDestination &fromAWS(const Aws::GameLift::Model::GameSessionQueueDestination &awsGameSessionQueueDestination) {
        this->destinationArn = UTF8_TO_TCHAR(awsGameSessionQueueDestination.GetDestinationArn().c_str());

        return *this;
    }
#endif
};
