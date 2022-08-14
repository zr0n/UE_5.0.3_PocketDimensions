/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/UpdateMatchmakingConfigurationResult.h"

#endif

#include "Model/MatchmakingConfiguration.h"

#include "UpdateMatchmakingConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateMatchmakingConfigurationResult {
    GENERATED_BODY()

    /**
    *  <p>Object that describes the updated matchmaking configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FMatchmakingConfiguration configuration;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FUpdateMatchmakingConfigurationResult &fromAWS(const Aws::GameLift::Model::UpdateMatchmakingConfigurationResult &awsUpdateMatchmakingConfigurationResult) {
        this->configuration.fromAWS(awsUpdateMatchmakingConfigurationResult.GetConfiguration());

        return *this;
    }
#endif
};
