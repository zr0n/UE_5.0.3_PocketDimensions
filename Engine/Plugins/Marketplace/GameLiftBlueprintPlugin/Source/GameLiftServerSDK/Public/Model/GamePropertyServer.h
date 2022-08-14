/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFT

#include "aws/gamelift/server/model/GameProperty.h"

#endif

#include "GamePropertyServer.generated.h"

USTRUCT(BlueprintType)
struct FGamePropertyServer {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Server")
    FString key;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Server")
    FString value;

#if WITH_GAMELIFT
    public:
    Aws::GameLift::Server::Model::GameProperty toAWS() const {
        Aws::GameLift::Server::Model::GameProperty awsGameProperty;

        if (!this->key.IsEmpty()) {
            awsGameProperty.SetKey(TCHAR_TO_UTF8(*this->key));
        }

        if (!this->value.IsEmpty()) {
            awsGameProperty.SetValue(TCHAR_TO_UTF8(*this->value));
        }

        return awsGameProperty;
    }

    FGamePropertyServer &fromAWS(const Aws::GameLift::Server::Model::GameProperty &awsGameProperty) {
        this->key = awsGameProperty.GetKey();
        this->value = awsGameProperty.GetValue();

        return *this;
    }

#endif
};