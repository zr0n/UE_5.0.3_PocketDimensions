/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeFleetAttributesResult.h"

#endif

#include "Model/FleetAttributes.h"

#include "DescribeFleetAttributesResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeFleetAttributesResult {
GENERATED_BODY()

    /**
    *  <p>Collection of objects containing attribute metadata for each requested fleet ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FFleetAttributes> fleetAttributes;

    /**
    *  <p>Token that indicates where to resume retrieving results on the next call to this action. If no token is returned, these results represent the end of the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FDescribeFleetAttributesResult &fromAWS(const Aws::GameLift::Model::DescribeFleetAttributesResult &awsDescribeFleetAttributesResult) {
        this->fleetAttributes.Empty();
        for (const Aws::GameLift::Model::FleetAttributes& elem : awsDescribeFleetAttributesResult.GetFleetAttributes()) {
            this->fleetAttributes.Add(FFleetAttributes().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsDescribeFleetAttributesResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
