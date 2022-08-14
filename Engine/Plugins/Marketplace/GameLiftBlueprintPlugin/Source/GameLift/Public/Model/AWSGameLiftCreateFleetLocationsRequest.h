/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreateFleetLocationsRequest.h"

#endif

#include "Model/AWSGameLiftLocationConfiguration.h"

#include "AWSGameLiftCreateFleetLocationsRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftCreateFleetLocationsRequest {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the fleet to add locations to. You can use either the fleet ID or ARN value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>A list of locations to deploy additional instances to and manage as part of the fleet. You can add any GameLift-supported AWS Region as a remote location, in the form of an AWS Region code such as <code>us-west-2</code>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FAWSGameLiftLocationConfiguration> locations;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::CreateFleetLocationsRequest toAWS() const {
        Aws::GameLift::Model::CreateFleetLocationsRequest awsCreateFleetLocationsRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsCreateFleetLocationsRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        for (const FAWSGameLiftLocationConfiguration& elem : this->locations) {
            awsCreateFleetLocationsRequest.AddLocations(elem.toAWS());
        }

        return awsCreateFleetLocationsRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty() && this->locations.Num() == 0;
    }
#endif
};
