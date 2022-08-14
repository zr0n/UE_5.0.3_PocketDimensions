/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/GetGameSessionLogUrlResult.h"

#endif

#include "GetGameSessionLogUrlResult.generated.h"

USTRUCT(BlueprintType)
struct FGetGameSessionLogUrlResult {
GENERATED_BODY()

    /**
    *  <p>Location of the requested game session logs, available for download. This URL is valid for 15 minutes, after which S3 will reject any download request using this URL. You can request a new URL any time within the 14-day period that the logs are retained.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString preSignedUrl;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FGetGameSessionLogUrlResult &fromAWS(const Aws::GameLift::Model::GetGameSessionLogUrlResult &awsGetGameSessionLogUrlResult) {
        this->preSignedUrl = UTF8_TO_TCHAR(awsGetGameSessionLogUrlResult.GetPreSignedUrl().c_str());

        return *this;
    }
#endif
};
