/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/RoutingStrategy.h"

#endif

#include "Model/RoutingStrategyType.h"

#include "RoutingStrategy.generated.h"

USTRUCT(BlueprintType)
struct FRoutingStrategy {
GENERATED_BODY()

    /**
    *  <p>Type of routing strategy.</p> <p>Possible routing types include the following:</p> <ul> <li> <p> <b>SIMPLE</b> -- The alias resolves to one specific fleet. Use this type when routing to active fleets.</p> </li> <li> <p> <b>TERMINAL</b> -- The alias does not resolve to a fleet but instead can be used to display a message to the user. A terminal alias throws a TerminalRoutingStrategyException with the <a>RoutingStrategy</a> message embedded.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    ERoutingStrategyType type = ERoutingStrategyType::NOT_SET;

    /**
    *  <p>Unique identifier for a fleet that the alias points to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>Message text to be used with a terminal routing strategy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString message;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::RoutingStrategy toAWS() const {
        Aws::GameLift::Model::RoutingStrategy awsRoutingStrategy;

        switch(this->type) {
            case ERoutingStrategyType::SIMPLE:
                awsRoutingStrategy.SetType(Aws::GameLift::Model::RoutingStrategyType::SIMPLE);
                break;
            case ERoutingStrategyType::TERMINAL:
                awsRoutingStrategy.SetType(Aws::GameLift::Model::RoutingStrategyType::TERMINAL);
                break;
            default:
                break;
        }

        if (!(this->fleetId.IsEmpty())) {
            awsRoutingStrategy.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        if (!(this->message.IsEmpty())) {
            awsRoutingStrategy.SetMessage(TCHAR_TO_UTF8(*this->message));
        }

        return awsRoutingStrategy;
    }

    bool IsEmpty() const {
        return this->type == ERoutingStrategyType::NOT_SET && this->fleetId.IsEmpty() && this->message.IsEmpty();
    }
    FRoutingStrategy &fromAWS(const Aws::GameLift::Model::RoutingStrategy &awsRoutingStrategy) {
        switch(awsRoutingStrategy.GetType()) {
            case Aws::GameLift::Model::RoutingStrategyType::NOT_SET:
                this->type = ERoutingStrategyType::NOT_SET;
                break;
            case Aws::GameLift::Model::RoutingStrategyType::SIMPLE:
                this->type = ERoutingStrategyType::SIMPLE;
                break;
            case Aws::GameLift::Model::RoutingStrategyType::TERMINAL:
                this->type = ERoutingStrategyType::TERMINAL;
                break;
            default:
                this->type = ERoutingStrategyType::NOT_SET;
                break;
        }

        this->fleetId = UTF8_TO_TCHAR(awsRoutingStrategy.GetFleetId().c_str());

        this->message = UTF8_TO_TCHAR(awsRoutingStrategy.GetMessage().c_str());

        return *this;
    }
#endif
};
