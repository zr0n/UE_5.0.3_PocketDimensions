/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/UpdateFleetAttributesRequest.h"

#endif

#include "Model/ProtectionPolicy.h"
#include "Model/ResourceCreationLimitPolicy.h"

#include "UpdateFleetAttributesRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateFleetAttributesRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a fleet to update attribute metadata for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>Descriptive label that is associated with a fleet. Fleet names do not need to be unique.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString name;

    /**
    *  <p>Human-readable description of a fleet.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString description;

    /**
    *  <p>Game session protection policy to apply to all new instances created in this fleet. Instances that already exist are not affected. You can set protection for individual instances using <a>UpdateGameSession</a>.</p> <ul> <li> <p> <b>NoProtection</b> -- The game session can be terminated during a scale-down event.</p> </li> <li> <p> <b>FullProtection</b> -- If the game session is in an <code>ACTIVE</code> status, it cannot be terminated during a scale-down event.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EProtectionPolicy newGameSessionProtectionPolicy = EProtectionPolicy::NOT_SET;

    /**
    *  <p>Policy that limits the number of game sessions an individual player can create over a span of time. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FResourceCreationLimitPolicy resourceCreationLimitPolicy;

    /**
    *  <p>Names of metric groups to include this fleet in. Amazon CloudWatch uses a fleet metric group is to aggregate metrics from multiple fleets. Use an existing metric group name to add this fleet to the group. Or use a new name to create a new metric group. A fleet can only be included in one metric group at a time.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FString> metricGroups;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::UpdateFleetAttributesRequest toAWS() const {
        Aws::GameLift::Model::UpdateFleetAttributesRequest awsUpdateFleetAttributesRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsUpdateFleetAttributesRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        if (!(this->name.IsEmpty())) {
            awsUpdateFleetAttributesRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        if (!(this->description.IsEmpty())) {
            awsUpdateFleetAttributesRequest.SetDescription(TCHAR_TO_UTF8(*this->description));
        }

        switch(this->newGameSessionProtectionPolicy) {
            case EProtectionPolicy::NoProtection:
                awsUpdateFleetAttributesRequest.SetNewGameSessionProtectionPolicy(Aws::GameLift::Model::ProtectionPolicy::NoProtection);
                break;
            case EProtectionPolicy::FullProtection:
                awsUpdateFleetAttributesRequest.SetNewGameSessionProtectionPolicy(Aws::GameLift::Model::ProtectionPolicy::FullProtection);
                break;
            default:
                break;
        }

        if (!(this->resourceCreationLimitPolicy.IsEmpty())) {
            awsUpdateFleetAttributesRequest.SetResourceCreationLimitPolicy(this->resourceCreationLimitPolicy.toAWS());
        }

        for (const FString& elem : this->metricGroups) {
            awsUpdateFleetAttributesRequest.AddMetricGroups(TCHAR_TO_UTF8(*elem));
        }

        return awsUpdateFleetAttributesRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty() && this->name.IsEmpty() && this->description.IsEmpty() && this->newGameSessionProtectionPolicy == EProtectionPolicy::NOT_SET && this->resourceCreationLimitPolicy.IsEmpty() && this->metricGroups.Num() == 0;
    }
#endif
};
