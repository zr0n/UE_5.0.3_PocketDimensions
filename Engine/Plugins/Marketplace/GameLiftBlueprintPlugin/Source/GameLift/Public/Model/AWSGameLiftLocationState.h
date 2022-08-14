/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/LocationState.h"

#endif

#include "Model/FleetStatus.h"

#include "AWSGameLiftLocationState.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftLocationState {
GENERATED_BODY()

    /**
    *  <p>The fleet location, expressed as an AWS Region code such as <code>us-west-2</code>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString location;

    /**
    *  <p>The life-cycle status of a fleet location. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EFleetStatus status = EFleetStatus::NOT_SET;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FAWSGameLiftLocationState &fromAWS(const Aws::GameLift::Model::LocationState &awsLocationState) {
        this->location = UTF8_TO_TCHAR(awsLocationState.GetLocation().c_str());

        switch(awsLocationState.GetStatus()) {
            case Aws::GameLift::Model::FleetStatus::NOT_SET:
                this->status = EFleetStatus::NOT_SET;
                break;
            case Aws::GameLift::Model::FleetStatus::NEW_:
                this->status = EFleetStatus::NEW_;
                break;
            case Aws::GameLift::Model::FleetStatus::DOWNLOADING:
                this->status = EFleetStatus::DOWNLOADING;
                break;
            case Aws::GameLift::Model::FleetStatus::VALIDATING:
                this->status = EFleetStatus::VALIDATING;
                break;
            case Aws::GameLift::Model::FleetStatus::BUILDING:
                this->status = EFleetStatus::BUILDING;
                break;
            case Aws::GameLift::Model::FleetStatus::ACTIVATING:
                this->status = EFleetStatus::ACTIVATING;
                break;
            case Aws::GameLift::Model::FleetStatus::ACTIVE:
                this->status = EFleetStatus::ACTIVE;
                break;
            case Aws::GameLift::Model::FleetStatus::DELETING:
                this->status = EFleetStatus::DELETING;
                break;
            case Aws::GameLift::Model::FleetStatus::ERROR_:
                this->status = EFleetStatus::ERROR_;
                break;
            case Aws::GameLift::Model::FleetStatus::TERMINATED:
                this->status = EFleetStatus::TERMINATED;
                break;
            default:
                this->status = EFleetStatus::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
