/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/UpdateFleetAttributesResult.h"

#endif

#include "UpdateFleetAttributesResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateFleetAttributesResult {
    GENERATED_BODY()

    /**
    *  <p>Unique identifier for a fleet that was updated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FUpdateFleetAttributesResult &fromAWS(const Aws::GameLift::Model::UpdateFleetAttributesResult &awsUpdateFleetAttributesResult) {
        this->fleetId = UTF8_TO_TCHAR(awsUpdateFleetAttributesResult.GetFleetId().c_str());

        return *this;
    }
#endif
};
