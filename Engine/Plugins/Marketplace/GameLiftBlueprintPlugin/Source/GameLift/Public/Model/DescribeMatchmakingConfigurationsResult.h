/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeMatchmakingConfigurationsResult.h"

#endif

#include "Model/MatchmakingConfiguration.h"

#include "DescribeMatchmakingConfigurationsResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeMatchmakingConfigurationsResult {
GENERATED_BODY()

    /**
    *  <p>Collection of requested matchmaking configuration objects.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FMatchmakingConfiguration> configurations;

    /**
    *  <p>Token that indicates where to resume retrieving results on the next call to this action. If no token is returned, these results represent the end of the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDescribeMatchmakingConfigurationsResult &fromAWS(const Aws::GameLift::Model::DescribeMatchmakingConfigurationsResult &awsDescribeMatchmakingConfigurationsResult) {
        this->configurations.Empty();
        for (const Aws::GameLift::Model::MatchmakingConfiguration& elem : awsDescribeMatchmakingConfigurationsResult.GetConfigurations()) {
            this->configurations.Add(FMatchmakingConfiguration().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsDescribeMatchmakingConfigurationsResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
