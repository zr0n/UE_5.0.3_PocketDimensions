/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/GetGameSessionLogUrlRequest.h"

#endif

#include "GetGameSessionLogUrlRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetGameSessionLogUrlRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for the game session to get logs for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameSessionId;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::GetGameSessionLogUrlRequest toAWS() const {
        Aws::GameLift::Model::GetGameSessionLogUrlRequest awsGetGameSessionLogUrlRequest;

        if (!(this->gameSessionId.IsEmpty())) {
            awsGetGameSessionLogUrlRequest.SetGameSessionId(TCHAR_TO_UTF8(*this->gameSessionId));
        }

        return awsGetGameSessionLogUrlRequest;
    }

    bool IsEmpty() const {
        return this->gameSessionId.IsEmpty();
    }
#endif
};
