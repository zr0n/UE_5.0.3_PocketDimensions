/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeScalingPoliciesRequest.h"

#endif

#include "Model/ScalingStatusType.h"

#include "DescribeScalingPoliciesRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeScalingPoliciesRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a fleet to retrieve scaling policies for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>Scaling policy status to filter results on. A scaling policy is only in force when in an <code>ACTIVE</code> status.</p> <ul> <li> <p> <b>ACTIVE</b> -- The scaling policy is currently in force.</p> </li> <li> <p> <b>UPDATEREQUESTED</b> -- A request to update the scaling policy has been received.</p> </li> <li> <p> <b>UPDATING</b> -- A change is being made to the scaling policy.</p> </li> <li> <p> <b>DELETEREQUESTED</b> -- A request to delete the scaling policy has been received.</p> </li> <li> <p> <b>DELETING</b> -- The scaling policy is being deleted.</p> </li> <li> <p> <b>DELETED</b> -- The scaling policy has been deleted.</p> </li> <li> <p> <b>ERROR</b> -- An error occurred in creating the policy. It should be removed and recreated.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EScalingStatusType statusFilter = EScalingStatusType::NOT_SET;

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

    /**
    *  <p>A fleet location to get game sessions for. You can specify a fleet's home Region or a remote location. Use the AWS Region code format, such as <code>us-west-2</code>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString location;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DescribeScalingPoliciesRequest toAWS() const {
        Aws::GameLift::Model::DescribeScalingPoliciesRequest awsDescribeScalingPoliciesRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsDescribeScalingPoliciesRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        switch(this->statusFilter) {
            case EScalingStatusType::ACTIVE:
                awsDescribeScalingPoliciesRequest.SetStatusFilter(Aws::GameLift::Model::ScalingStatusType::ACTIVE);
                break;
            case EScalingStatusType::UPDATE_REQUESTED:
                awsDescribeScalingPoliciesRequest.SetStatusFilter(Aws::GameLift::Model::ScalingStatusType::UPDATE_REQUESTED);
                break;
            case EScalingStatusType::UPDATING:
                awsDescribeScalingPoliciesRequest.SetStatusFilter(Aws::GameLift::Model::ScalingStatusType::UPDATING);
                break;
            case EScalingStatusType::DELETE_REQUESTED:
                awsDescribeScalingPoliciesRequest.SetStatusFilter(Aws::GameLift::Model::ScalingStatusType::DELETE_REQUESTED);
                break;
            case EScalingStatusType::DELETING:
                awsDescribeScalingPoliciesRequest.SetStatusFilter(Aws::GameLift::Model::ScalingStatusType::DELETING);
                break;
            case EScalingStatusType::DELETED:
                awsDescribeScalingPoliciesRequest.SetStatusFilter(Aws::GameLift::Model::ScalingStatusType::DELETED);
                break;
            case EScalingStatusType::ERROR_:
                awsDescribeScalingPoliciesRequest.SetStatusFilter(Aws::GameLift::Model::ScalingStatusType::ERROR_);
                break;
            default:
                break;
        }

        if (this->limit != 0) {
            awsDescribeScalingPoliciesRequest.SetLimit(this->limit);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsDescribeScalingPoliciesRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

		if (!(this->location.IsEmpty())) {
            awsDescribeScalingPoliciesRequest.SetLocation(TCHAR_TO_UTF8(*this->location));
        }

        return awsDescribeScalingPoliciesRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty() && this->statusFilter == EScalingStatusType::NOT_SET && this->limit == 0 && this->nextToken.IsEmpty() && this->location.IsEmpty();
    }
#endif
};
