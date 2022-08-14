/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeFleetEventsRequest.h"

#endif

#include "DescribeFleetEventsRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeFleetEventsRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a fleet to get event logs for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>Earliest date to retrieve event logs for. If no start time is specified, this call returns entries starting from when the fleet was created to the specified end time. Format is a number expressed in Unix time as milliseconds (ex: "1469498468.057").</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FDateTime startTime;

    /**
    *  <p>Most recent date to retrieve event logs for. If no end time is specified, this call returns entries from the specified start time up to the present. Format is a number expressed in Unix time as milliseconds (ex: "1469498468.057").</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FDateTime endTime;

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
    Aws::GameLift::Model::DescribeFleetEventsRequest toAWS() const {
        Aws::GameLift::Model::DescribeFleetEventsRequest awsDescribeFleetEventsRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsDescribeFleetEventsRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        awsDescribeFleetEventsRequest.SetStartTime(Aws::Utils::DateTime((int64_t)((this->startTime - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));

        awsDescribeFleetEventsRequest.SetEndTime(Aws::Utils::DateTime((int64_t)((this->endTime - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));

        if (this->limit != 0) {
            awsDescribeFleetEventsRequest.SetLimit(this->limit);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsDescribeFleetEventsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsDescribeFleetEventsRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty() && false && false && this->limit == 0 && this->nextToken.IsEmpty();
    }
#endif
};
