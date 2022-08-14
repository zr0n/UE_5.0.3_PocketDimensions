/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DeleteFleetLocationsRequest.h"

#endif

#include "AWSGameLiftDeleteFleetLocationsRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftDeleteFleetLocationsRequest {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the fleet to delete locations for. You can use either the fleet ID or ARN value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>The list of fleet locations to delete. Specify locations in the form of an AWS Region code, such as <code>us-west-2</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FString> locations;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DeleteFleetLocationsRequest toAWS() const {
        Aws::GameLift::Model::DeleteFleetLocationsRequest awsDeleteFleetLocationsRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsDeleteFleetLocationsRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        for (const FString& elem : this->locations) {
            awsDeleteFleetLocationsRequest.AddLocations(TCHAR_TO_UTF8(*elem));
        }

        return awsDeleteFleetLocationsRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty() && this->locations.Num() == 0;
    }

    
#endif
};
