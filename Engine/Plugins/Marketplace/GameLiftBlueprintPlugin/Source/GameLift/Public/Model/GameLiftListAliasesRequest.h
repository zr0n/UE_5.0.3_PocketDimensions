/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ListAliasesRequest.h"

#endif

#include "Model/RoutingStrategyType.h"

#include "GameLiftListAliasesRequest.generated.h"

USTRUCT(BlueprintType)
struct FGameLiftListAliasesRequest {
GENERATED_BODY()

    /**
    *  <p>Type of routing to filter results on. Use this parameter to retrieve only aliases of a certain type. To retrieve all aliases, leave this parameter empty.</p> <p>Possible routing types include the following:</p> <ul> <li> <p> <b>SIMPLE</b> -- The alias resolves to one specific fleet. Use this type when routing to active fleets.</p> </li> <li> <p> <b>TERMINAL</b> -- The alias does not resolve to a fleet but instead can be used to display a message to the user. A terminal alias throws a TerminalRoutingStrategyException with the <a>RoutingStrategy</a> message embedded.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    ERoutingStrategyType routingStrategyType = ERoutingStrategyType::NOT_SET;

    /**
    *  <p>Descriptive label that is associated with an alias. Alias names do not need to be unique.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString name;

    /**
    *  <p>Maximum number of results to return. Use this parameter with <code>NextToken</code> to get results as a set of sequential pages.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int limit = 0;

    /**
    *  <p>Token that indicates the start of the next sequential page of results. Use the token that is returned with a previous call to this action. To start at the beginning of the result set, do not specify a value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::ListAliasesRequest toAWS() const {
        Aws::GameLift::Model::ListAliasesRequest awsListAliasesRequest;

        switch(this->routingStrategyType) {
            case ERoutingStrategyType::SIMPLE:
                awsListAliasesRequest.SetRoutingStrategyType(Aws::GameLift::Model::RoutingStrategyType::SIMPLE);
                break;
            case ERoutingStrategyType::TERMINAL:
                awsListAliasesRequest.SetRoutingStrategyType(Aws::GameLift::Model::RoutingStrategyType::TERMINAL);
                break;
            default:
                break;
        }

        if (!(this->name.IsEmpty())) {
            awsListAliasesRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        if (this->limit != 0) {
            awsListAliasesRequest.SetLimit(this->limit);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsListAliasesRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsListAliasesRequest;
    }

    bool IsEmpty() const {
        return this->routingStrategyType == ERoutingStrategyType::NOT_SET  && this->name.IsEmpty() && this->limit == 0 && this->nextToken.IsEmpty();
    }
#endif
};
