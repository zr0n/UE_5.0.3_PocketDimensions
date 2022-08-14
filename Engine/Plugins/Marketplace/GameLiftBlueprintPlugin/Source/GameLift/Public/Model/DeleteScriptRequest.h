/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DeleteScriptRequest.h"

#endif

#include "DeleteScriptRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteScriptRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a Realtime script to delete.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString scriptId;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DeleteScriptRequest toAWS() const {
        Aws::GameLift::Model::DeleteScriptRequest awsDeleteScriptRequest;

        if (!(this->scriptId.IsEmpty())) {
            awsDeleteScriptRequest.SetScriptId(TCHAR_TO_UTF8(*this->scriptId));
        }

        return awsDeleteScriptRequest;
    }

    bool IsEmpty() const {
        return this->scriptId.IsEmpty();
    }
#endif
};
