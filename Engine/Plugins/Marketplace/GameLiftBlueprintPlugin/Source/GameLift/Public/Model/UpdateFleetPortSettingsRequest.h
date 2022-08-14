/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/UpdateFleetPortSettingsRequest.h"

#endif

#include "Model/IpPermission.h"
#include "Model/IpPermission.h"

#include "UpdateFleetPortSettingsRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateFleetPortSettingsRequest {
    GENERATED_BODY()

    /**
    *  <p>Unique identifier for a fleet to update port settings for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>Collection of port settings to be added to the fleet record.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FIpPermission> inboundPermissionAuthorizations;

    /**
    *  <p>Collection of port settings to be removed from the fleet record.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FIpPermission> inboundPermissionRevocations;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::UpdateFleetPortSettingsRequest toAWS() const {
        Aws::GameLift::Model::UpdateFleetPortSettingsRequest awsUpdateFleetPortSettingsRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsUpdateFleetPortSettingsRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        for (const FIpPermission& elem : this->inboundPermissionAuthorizations) {
            awsUpdateFleetPortSettingsRequest.AddInboundPermissionAuthorizations(elem.toAWS());
        }

        for (const FIpPermission& elem : this->inboundPermissionRevocations) {
            awsUpdateFleetPortSettingsRequest.AddInboundPermissionRevocations(elem.toAWS());
        }

        return awsUpdateFleetPortSettingsRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty() && this->inboundPermissionAuthorizations.Num() == 0 && this->inboundPermissionRevocations.Num() == 0;
    }
#endif
};
