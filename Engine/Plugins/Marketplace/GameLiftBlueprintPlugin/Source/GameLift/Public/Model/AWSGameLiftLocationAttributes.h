/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/LocationAttributes.h"

#endif

#include "Model/AWSGameLiftLocationState.h"
#include "Model/FleetAction.h"
#include "Model/AWSGameLiftLocationUpdateStatus.h"

#include "AWSGameLiftLocationAttributes.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftLocationAttributes {
GENERATED_BODY()

    /**
    *  <p>A fleet location and its current life-cycle state.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FAWSGameLiftLocationState locationState;

    /**
    *  <p>A list of fleet actions that have been suspended in the fleet location.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<EFleetAction> stoppedActions;

    /**
    *  <p>The status of fleet activity updates to the location. The status <code>PENDING_UPDATE</code> indicates that <a>StopFleetActions</a> or <a>StartFleetActions</a> has been requested but the update has not yet been completed for the location.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EAWSGameLiftLocationUpdateStatus updateStatus = EAWSGameLiftLocationUpdateStatus::NOT_SET;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FAWSGameLiftLocationAttributes &fromAWS(const Aws::GameLift::Model::LocationAttributes &awsLocationAttributes) {
        this->locationState = FAWSGameLiftLocationState().fromAWS(awsLocationAttributes.GetLocationState());

        this->stoppedActions.Empty();
        for (const Aws::GameLift::Model::FleetAction& elem : awsLocationAttributes.GetStoppedActions()) {
            switch(elem) {
                case Aws::GameLift::Model::FleetAction::NOT_SET:
                    this->stoppedActions.Add(EFleetAction::NOT_SET);
                    break;
                case Aws::GameLift::Model::FleetAction::AUTO_SCALING:
                    this->stoppedActions.Add(EFleetAction::AUTO_SCALING);
                    break;
                default:
                    break;
		    };
        }

        switch(awsLocationAttributes.GetUpdateStatus()) {
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

        return *this;
    }
#endif
};
