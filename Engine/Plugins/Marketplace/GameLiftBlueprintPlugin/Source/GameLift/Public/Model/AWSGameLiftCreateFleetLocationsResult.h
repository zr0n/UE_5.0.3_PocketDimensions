/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreateFleetLocationsResult.h"

#endif

#include "Model/AWSGameLiftLocationState.h"

#include "AWSGameLiftCreateFleetLocationsResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftCreateFleetLocationsResult {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the fleet that was updated with new locations.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) that is assigned to a GameLift fleet resource and uniquely identifies it. ARNs are unique across all Regions. Format is <code>arn:aws:gamelift:&lt;region&gt;::fleet/fleet-a1234567-b8c9-0d1e-2fa3-b45c6d7e8912</code>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetArn;

    /**
    *  <p>The remote locations that are being added to the fleet, and the life-cycle status of each location. For new locations, the status is set to <code>NEW</code>. During location creation, GameLift updates each location's status as instances are deployed there and prepared for game hosting. This list does not include the fleet home Region or any remote locations that were already added to the fleet.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FAWSGameLiftLocationState> locationStates;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FAWSGameLiftCreateFleetLocationsResult &fromAWS(const Aws::GameLift::Model::CreateFleetLocationsResult &awsCreateFleetLocationsResult) {
        this->fleetId = UTF8_TO_TCHAR(awsCreateFleetLocationsResult.GetFleetId().c_str());

        this->fleetArn = UTF8_TO_TCHAR(awsCreateFleetLocationsResult.GetFleetArn().c_str());

        this->locationStates.Empty();
        for (const Aws::GameLift::Model::LocationState& elem : awsCreateFleetLocationsResult.GetLocationStates()) {
            this->locationStates.Add(FAWSGameLiftLocationState().fromAWS(elem));
        }

        return *this;
    }
#endif
};
