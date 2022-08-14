/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/PriorityConfiguration.h"

#endif

#include "Model/AWSGameLiftPriorityType.h"

#include "AWSGameLiftPriorityConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftPriorityConfiguration {
GENERATED_BODY()

    /**
    *  <p>The recommended sequence to use when prioritizing where to place new game sessions. Each type can only be listed once.</p> <ul> <li> <p> <code>LATENCY</code> -- FleetIQ prioritizes locations where the average player latency (provided in each game session request) is lowest. </p> </li> <li> <p> <code>COST</code> -- FleetIQ prioritizes destinations with the lowest current hosting costs. Cost is evaluated based on the location, instance type, and fleet type (Spot or On-Demand) for each destination in the queue.</p> </li> <li> <p> <code>DESTINATION</code> -- FleetIQ prioritizes based on the order that destinations are listed in the queue configuration.</p> </li> <li> <p> <code>LOCATION</code> -- FleetIQ prioritizes based on the provided order of locations, as defined in <code>LocationOrder</code>. </p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<EAWSGameLiftPriorityType> priorityOrder;

    /**
    *  <p>The prioritization order to use for fleet locations, when the <code>PriorityOrder</code> property includes <code>LOCATION</code>. Locations are identified by AWS Region codes such as <code>us-west-2</code>. Each location can only be listed once. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FString> locationOrder;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::PriorityConfiguration toAWS() const {
        Aws::GameLift::Model::PriorityConfiguration awsPriorityConfiguration;
        for (const EAWSGameLiftPriorityType& elem : this->priorityOrder) {
		    switch(elem) {
                case EAWSGameLiftPriorityType::LATENCY:
                    awsPriorityConfiguration.AddPriorityOrder(Aws::GameLift::Model::PriorityType::LATENCY);
                    break;
                case EAWSGameLiftPriorityType::COST:
                    awsPriorityConfiguration.AddPriorityOrder(Aws::GameLift::Model::PriorityType::COST);
                    break;
                case EAWSGameLiftPriorityType::DESTINATION:
                    awsPriorityConfiguration.AddPriorityOrder(Aws::GameLift::Model::PriorityType::DESTINATION);
                    break;
                case EAWSGameLiftPriorityType::LOCATION:
                    awsPriorityConfiguration.AddPriorityOrder(Aws::GameLift::Model::PriorityType::LOCATION);
                    break;
                default:
                    break;
            };
        }

        for (const FString& elem : this->locationOrder) {
            awsPriorityConfiguration.AddLocationOrder(TCHAR_TO_UTF8(*elem));
        }

        return awsPriorityConfiguration;
    }

    bool IsEmpty() const {
        return this->priorityOrder.Num() == 0 && this->locationOrder.Num() == 0;
    }

    FAWSGameLiftPriorityConfiguration &fromAWS(const Aws::GameLift::Model::PriorityConfiguration &awsPriorityConfiguration) {
        this->priorityOrder.Empty();
        for (const Aws::GameLift::Model::PriorityType& elem : awsPriorityConfiguration.GetPriorityOrder()) {
            switch(elem) {
                case Aws::GameLift::Model::PriorityType::NOT_SET:
                    this->priorityOrder.Add(EAWSGameLiftPriorityType::NOT_SET);
                    break;
                case Aws::GameLift::Model::PriorityType::LATENCY:
                    this->priorityOrder.Add(EAWSGameLiftPriorityType::LATENCY);
                    break;
                case Aws::GameLift::Model::PriorityType::COST:
                    this->priorityOrder.Add(EAWSGameLiftPriorityType::COST);
                    break;
                case Aws::GameLift::Model::PriorityType::DESTINATION:
                    this->priorityOrder.Add(EAWSGameLiftPriorityType::DESTINATION);
                    break;
                case Aws::GameLift::Model::PriorityType::LOCATION:
                    this->priorityOrder.Add(EAWSGameLiftPriorityType::LOCATION);
                    break;
                default:
                    break;
		    };
        }

        this->locationOrder.Empty();
        for (const Aws::String& elem : awsPriorityConfiguration.GetLocationOrder()) {
            this->locationOrder.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        return *this;
    }
#endif
};
