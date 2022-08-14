/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DeleteMatchmakingConfigurationRequest.h"

#endif

#include "DeleteMatchmakingConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteMatchmakingConfigurationRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a matchmaking configuration</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString name;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DeleteMatchmakingConfigurationRequest toAWS() const {
        Aws::GameLift::Model::DeleteMatchmakingConfigurationRequest awsDeleteMatchmakingConfigurationRequest;

        if (!(this->name.IsEmpty())) {
            awsDeleteMatchmakingConfigurationRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        return awsDeleteMatchmakingConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->name.IsEmpty();
    }
#endif
};
