/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/StartFleetActionsRequest.h"

#endif

#include "Model/FleetAction.h"

#include "StartFleetActionsRequest.generated.h"

USTRUCT(BlueprintType)
struct FStartFleetActionsRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a fleet</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>List of actions to restart on the fleet.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<EFleetAction> actions;

    /**
    *  <p>The fleet location to restart fleet actions for. Specify a location in the form of an AWS Region code, such as <code>us-west-2</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString location;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::StartFleetActionsRequest toAWS() const {
        Aws::GameLift::Model::StartFleetActionsRequest awsStartFleetActionsRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsStartFleetActionsRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        for (const EFleetAction& elem : this->actions) {
            switch(elem) {
                case EFleetAction::AUTO_SCALING:
                    awsStartFleetActionsRequest.AddActions(Aws::GameLift::Model::FleetAction::AUTO_SCALING);
                    break;
                default:
                    break;
            };
        }

		if (!(this->location.IsEmpty())) {
            awsStartFleetActionsRequest.SetLocation(TCHAR_TO_UTF8(*this->location));
        }

        return awsStartFleetActionsRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty() && this->actions.Num() == 0 && this->location.IsEmpty();
    }
#endif
};
