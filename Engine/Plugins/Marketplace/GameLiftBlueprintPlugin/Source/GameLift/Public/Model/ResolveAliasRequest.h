/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ResolveAliasRequest.h"

#endif

#include "ResolveAliasRequest.generated.h"

USTRUCT(BlueprintType)
struct FResolveAliasRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for the alias you want to resolve.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString aliasId;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::ResolveAliasRequest toAWS() const {
        Aws::GameLift::Model::ResolveAliasRequest awsResolveAliasRequest;

        if (!(this->aliasId.IsEmpty())) {
            awsResolveAliasRequest.SetAliasId(TCHAR_TO_UTF8(*this->aliasId));
        }

        return awsResolveAliasRequest;
    }

    bool IsEmpty() const {
        return this->aliasId.IsEmpty();
    }
#endif
};
