/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeFleetPortSettingsResult.h"

#endif

#include "Model/IpPermission.h"
#include "Model/AWSGameLiftLocationUpdateStatus.h"

#include "DescribeFleetPortSettingsResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeFleetPortSettingsResult {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the fleet that was requested. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) that is assigned to a GameLift fleet resource and uniquely identifies it. ARNs are unique across all Regions. Format is <code>arn:aws:gamelift:&lt;region&gt;::fleet/fleet-a1234567-b8c9-0d1e-2fa3-b45c6d7e8912</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetArn;


    /**
    *  <p>The port settings for the requested fleet ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FIpPermission> inboundPermissions;

    /**
    *  <p>The current status of updates to the fleet's port settings in the requested fleet location. A status of <code>PENDING_UPDATE</code> indicates that an update was requested for the fleet but has not yet been completed for the location.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EAWSGameLiftLocationUpdateStatus updateStatus = EAWSGameLiftLocationUpdateStatus::NOT_SET;

    /**
    *  <p>The requested fleet location, expressed as an AWS Region code, such as <code>us-west-2</code>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString location;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDescribeFleetPortSettingsResult &fromAWS(const Aws::GameLift::Model::DescribeFleetPortSettingsResult &awsDescribeFleetPortSettingsResult) {
        this->fleetId = UTF8_TO_TCHAR(awsDescribeFleetPortSettingsResult.GetFleetId().c_str());

        this->fleetArn = UTF8_TO_TCHAR(awsDescribeFleetPortSettingsResult.GetFleetArn().c_str());

        this->inboundPermissions.Empty();
        for (const Aws::GameLift::Model::IpPermission& elem : awsDescribeFleetPortSettingsResult.GetInboundPermissions()) {
            this->inboundPermissions.Add(FIpPermission().fromAWS(elem));
        }

        switch(awsDescribeFleetPortSettingsResult.GetUpdateStatus()) {
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

        this->location = UTF8_TO_TCHAR(awsDescribeFleetPortSettingsResult.GetLocation().c_str());

        return *this;
    }
#endif
};
