/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DeleteAliasRequest.h"

#endif

#include "GameLiftDeleteAliasRequest.generated.h"

USTRUCT(BlueprintType)
struct FGameLiftDeleteAliasRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a fleet alias. Specify the alias you want to delete.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString aliasId;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DeleteAliasRequest toAWS() const {
        Aws::GameLift::Model::DeleteAliasRequest awsDeleteAliasRequest;

        if (!(this->aliasId.IsEmpty())) {
            awsDeleteAliasRequest.SetAliasId(TCHAR_TO_UTF8(*this->aliasId));
        }

        return awsDeleteAliasRequest;
    }

    bool IsEmpty() const {
        return this->aliasId.IsEmpty();
    }
#endif
};
