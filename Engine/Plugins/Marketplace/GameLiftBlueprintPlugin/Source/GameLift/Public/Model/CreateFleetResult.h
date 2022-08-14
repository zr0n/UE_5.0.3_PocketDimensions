/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreateFleetResult.h"

#endif

#include "Model/FleetAttributes.h"

#include "CreateFleetResult.generated.h"

USTRUCT(BlueprintType)
struct FCreateFleetResult {
GENERATED_BODY()

    /**
    *  <p>Properties for the newly created fleet.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FFleetAttributes fleetAttributes;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FCreateFleetResult &fromAWS(const Aws::GameLift::Model::CreateFleetResult &awsCreateFleetResult) {
        this->fleetAttributes.fromAWS(awsCreateFleetResult.GetFleetAttributes());

        return *this;
    }
#endif
};
