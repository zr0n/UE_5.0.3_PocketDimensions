/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DeleteGameSessionQueueRequest.h"

#endif

#include "DeleteGameSessionQueueRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteGameSessionQueueRequest {
GENERATED_BODY()

    /**
    *  <p>Descriptive label that is associated with game session queue. Queue names must be unique within each region.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString name;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DeleteGameSessionQueueRequest toAWS() const {
        Aws::GameLift::Model::DeleteGameSessionQueueRequest awsDeleteGameSessionQueueRequest;

        if (!(this->name.IsEmpty())) {
            awsDeleteGameSessionQueueRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        return awsDeleteGameSessionQueueRequest;
    }

    bool IsEmpty() const {
        return this->name.IsEmpty();
    }
#endif
};
