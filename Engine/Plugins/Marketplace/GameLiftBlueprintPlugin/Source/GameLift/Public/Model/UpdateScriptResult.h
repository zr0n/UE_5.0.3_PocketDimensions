/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/UpdateScriptResult.h"

#endif

#include "Model/Script.h"

#include "UpdateScriptResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateScriptResult {
GENERATED_BODY()

    /**
    *  <p>The newly created script record with a unique script ID. The new script's storage location reflects an Amazon S3 location: (1) If the script was uploaded from an S3 bucket under your account, the storage location reflects the information that was provided in the <i>CreateScript</i> request; (2) If the script file was uploaded from a local zip file, the storage location reflects an S3 location controls by the Amazon GameLift service.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FScript script;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FUpdateScriptResult &fromAWS(const Aws::GameLift::Model::UpdateScriptResult &awsUpdateScriptResult) {
        this->script.fromAWS(awsUpdateScriptResult.GetScript());

        return *this;
    }
#endif
};
