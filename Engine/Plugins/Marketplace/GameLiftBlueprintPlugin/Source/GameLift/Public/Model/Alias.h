/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/Alias.h"

#endif

#include "Model/RoutingStrategy.h"

#include "Alias.generated.h"

USTRUCT(BlueprintType)
struct FAlias {
    GENERATED_BODY()

    /**
    *  <p>Unique identifier for an alias; alias IDs are unique within a region.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString aliasId;

    /**
    *  <p>Descriptive label that is associated with an alias. Alias names do not need to be unique.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString name;

    /**
    *  <p>Unique identifier for an alias; alias ARNs are unique across all regions.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString aliasArn;

    /**
    *  <p>Human-readable description of an alias.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString description;

    /**
    *  <p>Alias configuration for the alias, including routing type and settings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FRoutingStrategy routingStrategy;

    /**
    *  <p>Time stamp indicating when this data object was created. Format is a number expressed in Unix time as milliseconds (for example "1469498468.057").</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FDateTime creationTime;

    /**
    *  <p>Time stamp indicating when this data object was last modified. Format is a number expressed in Unix time as milliseconds (for example "1469498468.057").</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FDateTime lastUpdatedTime;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FAlias &fromAWS(const Aws::GameLift::Model::Alias &awsAlias) {

        this->aliasId = UTF8_TO_TCHAR(awsAlias.GetAliasId().c_str());

        this->name = UTF8_TO_TCHAR(awsAlias.GetName().c_str());

        this->aliasArn = UTF8_TO_TCHAR(awsAlias.GetAliasArn().c_str());

        this->description = UTF8_TO_TCHAR(awsAlias.GetDescription().c_str());

        this->routingStrategy.fromAWS(awsAlias.GetRoutingStrategy());

        this->creationTime = FDateTime(1970, 1, 1) + FTimespan(awsAlias.GetCreationTime().Millis() * ETimespan::TicksPerMillisecond);

        this->lastUpdatedTime = FDateTime(1970, 1, 1) + FTimespan(awsAlias.GetLastUpdatedTime().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
