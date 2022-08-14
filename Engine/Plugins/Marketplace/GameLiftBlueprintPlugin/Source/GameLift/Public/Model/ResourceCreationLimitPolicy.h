/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ResourceCreationLimitPolicy.h"

#endif

#include "ResourceCreationLimitPolicy.generated.h"

USTRUCT(BlueprintType)
struct FResourceCreationLimitPolicy {
GENERATED_BODY()

    /**
    *  <p>Maximum number of game sessions that an individual can create during the policy period. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int newGameSessionsPerCreator = 0;

    /**
    *  <p>Time span used in evaluating the resource creation limit policy. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int policyPeriodInMinutes = 0;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::ResourceCreationLimitPolicy toAWS() const {
        Aws::GameLift::Model::ResourceCreationLimitPolicy awsResourceCreationLimitPolicy;

        if (this->newGameSessionsPerCreator != 0) {
            awsResourceCreationLimitPolicy.SetNewGameSessionsPerCreator(this->newGameSessionsPerCreator);
        }

        if (this->policyPeriodInMinutes != 0) {
            awsResourceCreationLimitPolicy.SetPolicyPeriodInMinutes(this->policyPeriodInMinutes);
        }

        return awsResourceCreationLimitPolicy;
    }

    bool IsEmpty() const {
        return this->newGameSessionsPerCreator == 0 && this->policyPeriodInMinutes == 0;
    }
    FResourceCreationLimitPolicy &fromAWS(const Aws::GameLift::Model::ResourceCreationLimitPolicy &awsResourceCreationLimitPolicy) {
        this->newGameSessionsPerCreator = awsResourceCreationLimitPolicy.GetNewGameSessionsPerCreator();

        this->policyPeriodInMinutes = awsResourceCreationLimitPolicy.GetPolicyPeriodInMinutes();

        return *this;
    }
#endif
};
