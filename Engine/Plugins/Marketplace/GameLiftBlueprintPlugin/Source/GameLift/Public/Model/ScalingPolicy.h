/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ScalingPolicy.h"

#endif

#include "Model/ScalingStatusType.h"
#include "Model/ScalingAdjustmentType.h"
#include "Model/ComparisonOperatorType.h"
#include "Model/MetricName.h"
#include "Model/PolicyType.h"
#include "Model/TargetConfiguration.h"
#include "Model/AWSGameLiftLocationUpdateStatus.h"

#include "ScalingPolicy.generated.h"

USTRUCT(BlueprintType)
struct FScalingPolicy {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the fleet that is associated with this scaling policy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) that is assigned to a GameLift fleet resource and uniquely identifies it. ARNs are unique across all Regions. Format is <code>arn:aws:gamelift:&lt;region&gt;::fleet/fleet-a1234567-b8c9-0d1e-2fa3-b45c6d7e8912</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetArn;

    /**
    *  <p>A descriptive label that is associated with a fleet's scaling policy. Policy names do not need to be unique.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString name;

    /**
    *  <p>Current status of the scaling policy. The scaling policy can be in force only when in an <code>ACTIVE</code> status. Scaling policies can be suspended for individual fleets (see <a>StopFleetActions</a>; if suspended for a fleet, the policy status does not change. View a fleet's stopped actions by calling <a>DescribeFleetCapacity</a>.</p> <ul> <li> <p> <b>ACTIVE</b> -- The scaling policy can be used for auto-scaling a fleet.</p> </li> <li> <p> <b>UPDATE_REQUESTED</b> -- A request to update the scaling policy has been received.</p> </li> <li> <p> <b>UPDATING</b> -- A change is being made to the scaling policy.</p> </li> <li> <p> <b>DELETE_REQUESTED</b> -- A request to delete the scaling policy has been received.</p> </li> <li> <p> <b>DELETING</b> -- The scaling policy is being deleted.</p> </li> <li> <p> <b>DELETED</b> -- The scaling policy has been deleted.</p> </li> <li> <p> <b>ERROR</b> -- An error occurred in creating the policy. It should be removed and recreated.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EScalingStatusType status = EScalingStatusType::NOT_SET;

    /**
    *  <p>Amount of adjustment to make, based on the scaling adjustment type.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int scalingAdjustment = 0;

    /**
    *  <p>Type of adjustment to make to a fleet's instance count (see <a>FleetCapacity</a>):</p> <ul> <li> <p> <b>ChangeInCapacity</b> -- add (or subtract) the scaling adjustment value from the current instance count. Positive values scale up while negative values scale down.</p> </li> <li> <p> <b>ExactCapacity</b> -- set the instance count to the scaling adjustment value.</p> </li> <li> <p> <b>PercentChangeInCapacity</b> -- increase or reduce the current instance count by the scaling adjustment, read as a percentage. Positive values scale up while negative values scale down.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EScalingAdjustmentType scalingAdjustmentType = EScalingAdjustmentType::NOT_SET;

    /**
    *  <p>Comparison operator to use when measuring a metric against the threshold value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EComparisonOperatorType comparisonOperator = EComparisonOperatorType::NOT_SET;

    /**
    *  <p>Metric value used to trigger a scaling event.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    float threshold = 0.0f;

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
    *  <p>The type of scaling policy to create. For a target-based policy, set the parameter <i>MetricName</i> to 'PercentAvailableGameSessions' and specify a <i>TargetConfiguration</i>. For a rule-based policy set the following parameters: <i>MetricName</i>, <i>ComparisonOperator</i>, <i>Threshold</i>, <i>EvaluationPeriods</i>, <i>ScalingAdjustmentType</i>, and <i>ScalingAdjustment</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EPolicyType policyType = EPolicyType::NOT_SET;

    /**
    *  <p>An object that contains settings for a target-based scaling policy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FTargetConfiguration targetConfiguration;

    /**
    *  <p>The current status of the fleet's scaling policies in a requested fleet location. The status <code>PENDING_UPDATE</code> indicates that an update was requested for the fleet but has not yet been completed for the location.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EAWSGameLiftLocationUpdateStatus updateStatus = EAWSGameLiftLocationUpdateStatus::NOT_SET;

    /**
    *  <p> </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString location;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FScalingPolicy &fromAWS(const Aws::GameLift::Model::ScalingPolicy &awsScalingPolicy) {
        this->fleetId = UTF8_TO_TCHAR(awsScalingPolicy.GetFleetId().c_str());

        this->fleetArn = UTF8_TO_TCHAR(awsScalingPolicy.GetFleetArn().c_str());

        this->name = UTF8_TO_TCHAR(awsScalingPolicy.GetName().c_str());

        switch(awsScalingPolicy.GetStatus()) {
            case Aws::GameLift::Model::ScalingStatusType::NOT_SET:
                this->status = EScalingStatusType::NOT_SET;
                break;
            case Aws::GameLift::Model::ScalingStatusType::ACTIVE:
                this->status = EScalingStatusType::ACTIVE;
                break;
            case Aws::GameLift::Model::ScalingStatusType::UPDATE_REQUESTED:
                this->status = EScalingStatusType::UPDATE_REQUESTED;
                break;
            case Aws::GameLift::Model::ScalingStatusType::UPDATING:
                this->status = EScalingStatusType::UPDATING;
                break;
            case Aws::GameLift::Model::ScalingStatusType::DELETE_REQUESTED:
                this->status = EScalingStatusType::DELETE_REQUESTED;
                break;
            case Aws::GameLift::Model::ScalingStatusType::DELETING:
                this->status = EScalingStatusType::DELETING;
                break;
            case Aws::GameLift::Model::ScalingStatusType::DELETED:
                this->status = EScalingStatusType::DELETED;
                break;
            case Aws::GameLift::Model::ScalingStatusType::ERROR_:
                this->status = EScalingStatusType::ERROR_;
                break;
            default:
                this->status = EScalingStatusType::NOT_SET;
                break;
        }

        this->scalingAdjustment = awsScalingPolicy.GetScalingAdjustment();

        switch(awsScalingPolicy.GetScalingAdjustmentType()) {
            case Aws::GameLift::Model::ScalingAdjustmentType::NOT_SET:
                this->scalingAdjustmentType = EScalingAdjustmentType::NOT_SET;
                break;
            case Aws::GameLift::Model::ScalingAdjustmentType::ChangeInCapacity:
                this->scalingAdjustmentType = EScalingAdjustmentType::ChangeInCapacity;
                break;
            case Aws::GameLift::Model::ScalingAdjustmentType::ExactCapacity:
                this->scalingAdjustmentType = EScalingAdjustmentType::ExactCapacity;
                break;
            case Aws::GameLift::Model::ScalingAdjustmentType::PercentChangeInCapacity:
                this->scalingAdjustmentType = EScalingAdjustmentType::PercentChangeInCapacity;
                break;
            default:
                this->scalingAdjustmentType = EScalingAdjustmentType::NOT_SET;
                break;
        }

        switch(awsScalingPolicy.GetComparisonOperator()) {
            case Aws::GameLift::Model::ComparisonOperatorType::NOT_SET:
                this->comparisonOperator = EComparisonOperatorType::NOT_SET;
                break;
            case Aws::GameLift::Model::ComparisonOperatorType::GreaterThanOrEqualToThreshold:
                this->comparisonOperator = EComparisonOperatorType::GreaterThanOrEqualToThreshold;
                break;
            case Aws::GameLift::Model::ComparisonOperatorType::GreaterThanThreshold:
                this->comparisonOperator = EComparisonOperatorType::GreaterThanThreshold;
                break;
            case Aws::GameLift::Model::ComparisonOperatorType::LessThanThreshold:
                this->comparisonOperator = EComparisonOperatorType::LessThanThreshold;
                break;
            case Aws::GameLift::Model::ComparisonOperatorType::LessThanOrEqualToThreshold:
                this->comparisonOperator = EComparisonOperatorType::LessThanOrEqualToThreshold;
                break;
            default:
                this->comparisonOperator = EComparisonOperatorType::NOT_SET;
                break;
        }

        this->threshold = (float)awsScalingPolicy.GetThreshold();

        this->evaluationPeriods = awsScalingPolicy.GetEvaluationPeriods();

        switch(awsScalingPolicy.GetMetricName()) {
            case Aws::GameLift::Model::MetricName::NOT_SET:
                this->metricName = EMetricName::NOT_SET;
                break;
            case Aws::GameLift::Model::MetricName::ActivatingGameSessions:
                this->metricName = EMetricName::ActivatingGameSessions;
                break;
            case Aws::GameLift::Model::MetricName::ActiveGameSessions:
                this->metricName = EMetricName::ActiveGameSessions;
                break;
            case Aws::GameLift::Model::MetricName::ActiveInstances:
                this->metricName = EMetricName::ActiveInstances;
                break;
            case Aws::GameLift::Model::MetricName::AvailableGameSessions:
                this->metricName = EMetricName::AvailableGameSessions;
                break;
            case Aws::GameLift::Model::MetricName::AvailablePlayerSessions:
                this->metricName = EMetricName::AvailablePlayerSessions;
                break;
            case Aws::GameLift::Model::MetricName::CurrentPlayerSessions:
                this->metricName = EMetricName::CurrentPlayerSessions;
                break;
            case Aws::GameLift::Model::MetricName::IdleInstances:
                this->metricName = EMetricName::IdleInstances;
                break;
            case Aws::GameLift::Model::MetricName::PercentAvailableGameSessions:
                this->metricName = EMetricName::PercentAvailableGameSessions;
                break;
            case Aws::GameLift::Model::MetricName::PercentIdleInstances:
                this->metricName = EMetricName::PercentIdleInstances;
                break;
            case Aws::GameLift::Model::MetricName::QueueDepth:
                this->metricName = EMetricName::QueueDepth;
                break;
            case Aws::GameLift::Model::MetricName::WaitTime:
                this->metricName = EMetricName::WaitTime;
                break;
            default:
                this->metricName = EMetricName::NOT_SET;
                break;
        }

        switch(awsScalingPolicy.GetPolicyType()) {
            case Aws::GameLift::Model::PolicyType::NOT_SET:
                this->policyType = EPolicyType::NOT_SET;
                break;
            case Aws::GameLift::Model::PolicyType::RuleBased:
                this->policyType = EPolicyType::RuleBased;
                break;
            case Aws::GameLift::Model::PolicyType::TargetBased:
                this->policyType = EPolicyType::TargetBased;
                break;
            default:
                this->policyType = EPolicyType::NOT_SET;
                break;
        }

        this->targetConfiguration = FTargetConfiguration().fromAWS(awsScalingPolicy.GetTargetConfiguration());

        switch(awsScalingPolicy.GetUpdateStatus()) {
            case Aws::GameLift::Model::LocationUpdateStatus::NOT_SET:
                this->updateStatus = EAWSGameLiftLocationUpdateStatus::NOT_SET;
                break;
            case Aws::GameLift::Model::LocationUpdateStatus::PENDING_UPDATE:
                this->updateStatus = EAWSGameLiftLocationUpdateStatus::PENDING_UPDATE;
                break;
            default:
                this->updateStatus = EAWSGameLiftLocationUpdateStatus::NOT_SET;
                break;
        }

        this->location = UTF8_TO_TCHAR(awsScalingPolicy.GetLocation().c_str());

        return *this;
    }
#endif
};
