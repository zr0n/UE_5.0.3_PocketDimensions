/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/PutScalingPolicyRequest.h"

#endif

#include "Model/ScalingAdjustmentType.h"
#include "Model/ComparisonOperatorType.h"
#include "Model/MetricName.h"
#include "Model/PolicyType.h"
#include "Model/TargetConfiguration.h"

#include "PutScalingPolicyRequest.generated.h"

USTRUCT(BlueprintType)
struct FPutScalingPolicyRequest {
GENERATED_BODY()

    /**
    *  <p>Descriptive label that is associated with a scaling policy. Policy names do not need to be unique. A fleet can have only one scaling policy with the same name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString name;

    /**
    *  <p>Unique identifier for a fleet to apply this policy to. The fleet cannot be in any of the following statuses: ERROR or DELETING.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>Amount of adjustment to make, based on the scaling adjustment type.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int scalingAdjustment = 0;

    /**
    *  <p>Type of adjustment to make to a fleet's instance count (see <a>FleetCapacity</a>):</p> <ul> <li> <p> <b>ChangeInCapacity</b> -- add (or subtract) the scaling adjustment value from the current instance count. Positive values scale up while negative values scale down.</p> </li> <li> <p> <b>ExactCapacity</b> -- set the instance count to the scaling adjustment value.</p> </li> <li> <p> <b>PercentChangeInCapacity</b> -- increase or reduce the current instance count by the scaling adjustment, read as a percentage. Positive values scale up while negative values scale down; for example, a value of "-10" scales the fleet down by 10%.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EScalingAdjustmentType scalingAdjustmentType = EScalingAdjustmentType::NOT_SET;

    /**
    *  <p>Metric value used to trigger a scaling event.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    float threshold = 0.0f;

    /**
    *  <p>Comparison operator to use when measuring the metric against the threshold value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EComparisonOperatorType comparisonOperator = EComparisonOperatorType::NOT_SET;

    /**
    *  <p>Length of time (in minutes) the metric must be at or beyond the threshold before a scaling event is triggered.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int evaluationPeriods = 0;

    /**
    *  <p>Name of the Amazon GameLift-defined metric that is used to trigger a scaling adjustment. For detailed descriptions of fleet metrics, see <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/monitoring-cloudwatch.html">Monitor Amazon GameLift with Amazon CloudWatch</a>. </p> <ul> <li> <p> <b>ActivatingGameSessions</b> -- Game sessions in the process of being created.</p> </li> <li> <p> <b>ActiveGameSessions</b> -- Game sessions that are currently running.</p> </li> <li> <p> <b>ActiveInstances</b> -- Fleet instances that are currently running at least one game session.</p> </li> <li> <p> <b>AvailableGameSessions</b> -- Additional game sessions that fleet could host simultaneously, given current capacity.</p> </li> <li> <p> <b>AvailablePlayerSessions</b> -- Empty player slots in currently active game sessions. This includes game sessions that are not currently accepting players. Reserved player slots are not included.</p> </li> <li> <p> <b>CurrentPlayerSessions</b> -- Player slots in active game sessions that are being used by a player or are reserved for a player. </p> </li> <li> <p> <b>IdleInstances</b> -- Active instances that are currently hosting zero game sessions. </p> </li> <li> <p> <b>PercentAvailableGameSessions</b> -- Unused percentage of the total number of game sessions that a fleet could host simultaneously, given current capacity. Use this metric for a target-based scaling policy.</p> </li> <li> <p> <b>PercentIdleInstances</b> -- Percentage of the total number of active instances that are hosting zero game sessions.</p> </li> <li> <p> <b>QueueDepth</b> -- Pending game session placement requests, in any queue, where the current fleet is the top-priority destination.</p> </li> <li> <p> <b>WaitTime</b> -- Current wait time for pending game session placement requests, in any queue, where the current fleet is the top-priority destination. </p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EMetricName metricName = EMetricName::NOT_SET;

    /**
    *  <p>Type of scaling policy to create. For a target-based policy, set the parameter <i>MetricName</i> to 'PercentAvailableGameSessions' and specify a <i>TargetConfiguration</i>. For a rule-based policy set the following parameters: <i>MetricName</i>, <i>ComparisonOperator</i>, <i>Threshold</i>, <i>EvaluationPeriods</i>, <i>ScalingAdjustmentType</i>, and <i>ScalingAdjustment</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EPolicyType policyType = EPolicyType::NOT_SET;

    /**
    *  <p>Object that contains settings for a target-based scaling policy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FTargetConfiguration targetConfiguration;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::PutScalingPolicyRequest toAWS() const {
        Aws::GameLift::Model::PutScalingPolicyRequest awsPutScalingPolicyRequest;

        if (!(this->name.IsEmpty())) {
            awsPutScalingPolicyRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        if (!(this->fleetId.IsEmpty())) {
            awsPutScalingPolicyRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        if (this->scalingAdjustment != 0) {
            awsPutScalingPolicyRequest.SetScalingAdjustment(this->scalingAdjustment);
        }

        switch(this->scalingAdjustmentType) {
            case EScalingAdjustmentType::ChangeInCapacity:
                awsPutScalingPolicyRequest.SetScalingAdjustmentType(Aws::GameLift::Model::ScalingAdjustmentType::ChangeInCapacity);
                break;
            case EScalingAdjustmentType::ExactCapacity:
                awsPutScalingPolicyRequest.SetScalingAdjustmentType(Aws::GameLift::Model::ScalingAdjustmentType::ExactCapacity);
                break;
            case EScalingAdjustmentType::PercentChangeInCapacity:
                awsPutScalingPolicyRequest.SetScalingAdjustmentType(Aws::GameLift::Model::ScalingAdjustmentType::PercentChangeInCapacity);
                break;
            default:
                break;
        }

        if (this->threshold != 0) {
            awsPutScalingPolicyRequest.SetThreshold(this->threshold);
        }

        switch(this->comparisonOperator) {
            case EComparisonOperatorType::GreaterThanOrEqualToThreshold:
                awsPutScalingPolicyRequest.SetComparisonOperator(Aws::GameLift::Model::ComparisonOperatorType::GreaterThanOrEqualToThreshold);
                break;
            case EComparisonOperatorType::GreaterThanThreshold:
                awsPutScalingPolicyRequest.SetComparisonOperator(Aws::GameLift::Model::ComparisonOperatorType::GreaterThanThreshold);
                break;
            case EComparisonOperatorType::LessThanThreshold:
                awsPutScalingPolicyRequest.SetComparisonOperator(Aws::GameLift::Model::ComparisonOperatorType::LessThanThreshold);
                break;
            case EComparisonOperatorType::LessThanOrEqualToThreshold:
                awsPutScalingPolicyRequest.SetComparisonOperator(Aws::GameLift::Model::ComparisonOperatorType::LessThanOrEqualToThreshold);
                break;
            default:
                break;
        }

        if (this->evaluationPeriods != 0) {
            awsPutScalingPolicyRequest.SetEvaluationPeriods(this->evaluationPeriods);
        }

        switch(this->metricName) {
            case EMetricName::ActivatingGameSessions:
                awsPutScalingPolicyRequest.SetMetricName(Aws::GameLift::Model::MetricName::ActivatingGameSessions);
                break;
            case EMetricName::ActiveGameSessions:
                awsPutScalingPolicyRequest.SetMetricName(Aws::GameLift::Model::MetricName::ActiveGameSessions);
                break;
            case EMetricName::ActiveInstances:
                awsPutScalingPolicyRequest.SetMetricName(Aws::GameLift::Model::MetricName::ActiveInstances);
                break;
            case EMetricName::AvailableGameSessions:
                awsPutScalingPolicyRequest.SetMetricName(Aws::GameLift::Model::MetricName::AvailableGameSessions);
                break;
            case EMetricName::AvailablePlayerSessions:
                awsPutScalingPolicyRequest.SetMetricName(Aws::GameLift::Model::MetricName::AvailablePlayerSessions);
                break;
            case EMetricName::CurrentPlayerSessions:
                awsPutScalingPolicyRequest.SetMetricName(Aws::GameLift::Model::MetricName::CurrentPlayerSessions);
                break;
            case EMetricName::IdleInstances:
                awsPutScalingPolicyRequest.SetMetricName(Aws::GameLift::Model::MetricName::IdleInstances);
                break;
            case EMetricName::PercentAvailableGameSessions:
                awsPutScalingPolicyRequest.SetMetricName(Aws::GameLift::Model::MetricName::PercentAvailableGameSessions);
                break;
            case EMetricName::PercentIdleInstances:
                awsPutScalingPolicyRequest.SetMetricName(Aws::GameLift::Model::MetricName::PercentIdleInstances);
                break;
            case EMetricName::QueueDepth:
                awsPutScalingPolicyRequest.SetMetricName(Aws::GameLift::Model::MetricName::QueueDepth);
                break;
            case EMetricName::WaitTime:
                awsPutScalingPolicyRequest.SetMetricName(Aws::GameLift::Model::MetricName::WaitTime);
                break;
            default:
                break;
        }

        switch(this->policyType) {
            case EPolicyType::RuleBased:
                awsPutScalingPolicyRequest.SetPolicyType(Aws::GameLift::Model::PolicyType::RuleBased);
                break;
            case EPolicyType::TargetBased:
                awsPutScalingPolicyRequest.SetPolicyType(Aws::GameLift::Model::PolicyType::TargetBased);
                break;
            default:
                break;
        }

        if (!(this->targetConfiguration.IsEmpty())) {
            awsPutScalingPolicyRequest.SetTargetConfiguration(this->targetConfiguration.toAWS());
        }

        return awsPutScalingPolicyRequest;
    }

    bool IsEmpty() const {
        return this->name.IsEmpty() && this->fleetId.IsEmpty() && this->scalingAdjustment == 0 && this->scalingAdjustmentType == EScalingAdjustmentType::NOT_SET && this->threshold == 0 && this->comparisonOperator == EComparisonOperatorType::NOT_SET && this->evaluationPeriods == 0 && this->metricName == EMetricName::NOT_SET && this->policyType == EPolicyType::NOT_SET && this->targetConfiguration.IsEmpty();
    }
#endif
};
