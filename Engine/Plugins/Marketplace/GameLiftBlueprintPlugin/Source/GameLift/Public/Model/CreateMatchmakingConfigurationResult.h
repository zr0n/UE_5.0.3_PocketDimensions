/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreateMatchmakingConfigurationResult.h"

#endif

#include "Model/MatchmakingConfiguration.h"

#include "CreateMatchmakingConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FCreateMatchmakingConfigurationResult {
GENERATED_BODY()

    /**
    *  <p>Object that describes the newly created matchmaking configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FMatchmakingConfiguration configuration;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FCreateMatchmakingConfigurationResult &fromAWS(const Aws::GameLift::Model::CreateMatchmakingConfigurationResult &awsCreateMatchmakingConfigurationResult) {
        this->configuration.fromAWS(awsCreateMatchmakingConfigurationResult.GetConfiguration());

        return *this;
    }
#endif
};
