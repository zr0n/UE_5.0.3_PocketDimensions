/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DeleteMatchmakingRuleSetRequest.h"

#endif

#include "DeleteMatchmakingRuleSetRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteMatchmakingRuleSetRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a matchmaking rule set to be deleted. (Note: The rule set name is different from the optional "name" field in the rule set body.) </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString name;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DeleteMatchmakingRuleSetRequest toAWS() const {
        Aws::GameLift::Model::DeleteMatchmakingRuleSetRequest awsDeleteMatchmakingRuleSetRequest;

        if (!(this->name.IsEmpty())) {
            awsDeleteMatchmakingRuleSetRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        return awsDeleteMatchmakingRuleSetRequest;
    }

    bool IsEmpty() const {
        return this->name.IsEmpty();
    }
#endif
};
