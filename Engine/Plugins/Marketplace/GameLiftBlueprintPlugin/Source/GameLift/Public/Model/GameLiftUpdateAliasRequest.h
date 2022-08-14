/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/UpdateAliasRequest.h"

#endif

#include "Model/RoutingStrategy.h"

#include "GameLiftUpdateAliasRequest.generated.h"

USTRUCT(BlueprintType)
struct FGameLiftUpdateAliasRequest {
    GENERATED_BODY()

    /**
    *  <p>Unique identifier for a fleet alias. Specify the alias you want to update.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString aliasId;

    /**
    *  <p>Descriptive label that is associated with an alias. Alias names do not need to be unique.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString name;

    /**
    *  <p>Human-readable description of an alias.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString description;

    /**
    *  <p>Object that specifies the fleet and routing type to use for the alias.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FRoutingStrategy routingStrategy;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::UpdateAliasRequest toAWS() const {
        Aws::GameLift::Model::UpdateAliasRequest awsUpdateAliasRequest;

        if (!(this->aliasId.IsEmpty())) {
            awsUpdateAliasRequest.SetAliasId(TCHAR_TO_UTF8(*this->aliasId));
        }

        if (!(this->name.IsEmpty())) {
            awsUpdateAliasRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        if (!(this->description.IsEmpty())) {
            awsUpdateAliasRequest.SetDescription(TCHAR_TO_UTF8(*this->description));
        }

        if (!(this->routingStrategy.IsEmpty())) {
            awsUpdateAliasRequest.SetRoutingStrategy(this->routingStrategy.toAWS());
        }

        return awsUpdateAliasRequest;
    }

    bool IsEmpty() const {
        return this->aliasId.IsEmpty() && this->name.IsEmpty() && this->description.IsEmpty() && this->routingStrategy.IsEmpty();
    }
#endif
};
