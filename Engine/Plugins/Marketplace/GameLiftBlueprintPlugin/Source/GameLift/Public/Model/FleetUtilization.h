/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/FleetUtilization.h"

#endif

#include "FleetUtilization.generated.h"

USTRUCT(BlueprintType)
struct FFleetUtilization {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the fleet associated with the location.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) that is assigned to a GameLift fleet resource and uniquely identifies it. ARNs are unique across all Regions. Format is <code>arn:aws:gamelift:&lt;region&gt;::fleet/fleet-a1234567-b8c9-0d1e-2fa3-b45c6d7e8912</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetArn;

    /**
    *  <p>The number of server processes in <code>ACTIVE</code> status that are currently running across all instances in the fleet location. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int activeServerProcessCount = 0;

    /**
    *  <p>The number of active game sessions that are currently being hosted across all instances in the fleet location.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int activeGameSessionCount = 0;

    /**
    *  <p>The number of active player sessions that are currently being hosted across all instances in the fleet location.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int currentPlayerSessionCount = 0;

    /**
    *  <p>The maximum number of players allowed across all game sessions that are currently being hosted across all instances in the fleet location.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int maximumPlayerSessionCount = 0;

    /**
    *  <p>The fleet location for the fleet utilization information, expressed as an AWS Region code, such as <code>us-west-2</code>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString location;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FFleetUtilization &fromAWS(const Aws::GameLift::Model::FleetUtilization &awsFleetUtilization) {
        this->fleetId = UTF8_TO_TCHAR(awsFleetUtilization.GetFleetId().c_str());

        this->fleetArn = UTF8_TO_TCHAR(awsFleetUtilization.GetFleetArn().c_str());

        this->activeServerProcessCount = awsFleetUtilization.GetActiveServerProcessCount();

        this->activeGameSessionCount = awsFleetUtilization.GetActiveGameSessionCount();

        this->currentPlayerSessionCount = awsFleetUtilization.GetCurrentPlayerSessionCount();

        this->maximumPlayerSessionCount = awsFleetUtilization.GetMaximumPlayerSessionCount();

        this->location = UTF8_TO_TCHAR(awsFleetUtilization.GetLocation().c_str());

        return *this;
    }
#endif
};
