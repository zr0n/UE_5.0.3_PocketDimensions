/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ValidateMatchmakingRuleSetRequest.h"

#endif

#include "ValidateMatchmakingRuleSetRequest.generated.h"

USTRUCT(BlueprintType)
struct FValidateMatchmakingRuleSetRequest {
    GENERATED_BODY()

    /**
    *  <p>Collection of matchmaking rules to validate, formatted as a JSON string.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString ruleSetBody;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::ValidateMatchmakingRuleSetRequest toAWS() const {
        Aws::GameLift::Model::ValidateMatchmakingRuleSetRequest awsValidateMatchmakingRuleSetRequest;

        if (!(this->ruleSetBody.IsEmpty())) {
            awsValidateMatchmakingRuleSetRequest.SetRuleSetBody(TCHAR_TO_UTF8(*this->ruleSetBody));
        }

        return awsValidateMatchmakingRuleSetRequest;
    }

    bool IsEmpty() const {
        return this->ruleSetBody.IsEmpty();
    }
#endif
};
