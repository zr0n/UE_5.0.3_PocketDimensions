/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/MatchmakingRuleSet.h"

#endif

#include "MatchmakingRuleSet.generated.h"

USTRUCT(BlueprintType)
struct FMatchmakingRuleSet {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a matchmaking rule set</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString ruleSetName;

    /**
    *  <p>Amazon Resource Name (<a href="https://docs.aws.amazon.com/general/latest/gr/aws-arns-and-namespaces.html">ARN</a>) that is assigned to a GameLift matchmaking rule set resource and uniquely identifies it. ARNs are unique across all Regions. In a GameLift rule set ARN, the resource ID matches the <i>RuleSetName</i> value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString ruleSetArn;

    /**
    *  <p>Collection of matchmaking rules, formatted as a JSON string. Comments are not allowed in JSON, but most elements support a description field.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString ruleSetBody;

    /**
    *  <p>Time stamp indicating when this data object was created. Format is a number expressed in Unix time as milliseconds (for example "1469498468.057").</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FDateTime creationTime;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FMatchmakingRuleSet &fromAWS(const Aws::GameLift::Model::MatchmakingRuleSet &awsMatchmakingRuleSet) {
        this->ruleSetName = UTF8_TO_TCHAR(awsMatchmakingRuleSet.GetRuleSetName().c_str());

        this->ruleSetArn = UTF8_TO_TCHAR(awsMatchmakingRuleSet.GetRuleSetArn().c_str());

        this->ruleSetBody = UTF8_TO_TCHAR(awsMatchmakingRuleSet.GetRuleSetBody().c_str());

        this->creationTime = FDateTime(1970, 1, 1) + FTimespan(awsMatchmakingRuleSet.GetCreationTime().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
