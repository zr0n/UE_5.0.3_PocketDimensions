/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeScriptRequest.h"

#endif

#include "DescribeScriptRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeScriptRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a Realtime script to retrieve properties for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString scriptId;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DescribeScriptRequest toAWS() const {
        Aws::GameLift::Model::DescribeScriptRequest awsDescribeScriptRequest;

        if (!(this->scriptId.IsEmpty())) {
            awsDescribeScriptRequest.SetScriptId(TCHAR_TO_UTF8(*this->scriptId));
        }

        return awsDescribeScriptRequest;
    }

    bool IsEmpty() const {
        return this->scriptId.IsEmpty();
    }
#endif
};
