/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ListGameServersRequest.h"

#endif

#include "Model/SortOrder.h"

#include "ListGameServersRequest.generated.h"

USTRUCT(BlueprintType)
struct FListGameServersRequest {
    GENERATED_BODY()

    /**
    *  <p>An identifier for the game server group for the game server you want to list. Use either the <a>GameServerGroup</a> name or ARN value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerGroupName;

    /**
    *  <p>Indicates how to sort the returned data based on the game servers' custom key sort value. If this parameter is left empty, the list of game servers is returned in no particular order.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EAWSSortOrder sortOrder = EAWSSortOrder::NOT_SET;

    /**
    *  <p>The maximum number of results to return. Use this parameter with <code>NextToken</code> to get results as a set of sequential pages.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int limit = 0;

    /**
    *  <p>A token that indicates the start of the next sequential page of results. Use the token that is returned with a previous call to this action. To start at the beginning of the result set, do not specify a value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::ListGameServersRequest toAWS() const {
        Aws::GameLift::Model::ListGameServersRequest awsListGameServersRequest;

		if (!(this->gameServerGroupName.IsEmpty())) {
            awsListGameServersRequest.SetGameServerGroupName(TCHAR_TO_UTF8(*this->gameServerGroupName));
        }

        switch(this->sortOrder) {
            case EAWSSortOrder::ASCENDING:
                awsListGameServersRequest.SetSortOrder(Aws::GameLift::Model::SortOrder::ASCENDING);
                break;
            case EAWSSortOrder::DESCENDING:
                awsListGameServersRequest.SetSortOrder(Aws::GameLift::Model::SortOrder::DESCENDING);
                break;
            default:
                break;
		}

        if (!(this->limit == 0)) {
            awsListGameServersRequest.SetLimit(this->limit);
        }

		if (!(this->nextToken.IsEmpty())) {
            awsListGameServersRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsListGameServersRequest;
    }

    bool IsEmpty() const {
        return this->gameServerGroupName.IsEmpty() && sortOrder == EAWSSortOrder::NOT_SET && this->limit == 0 && this->nextToken.IsEmpty();
    }
#endif
};
