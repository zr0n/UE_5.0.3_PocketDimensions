/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeGameServerRequest.h"

#endif

#include "DescribeGameServerRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeGameServerRequest {
GENERATED_BODY()

    /**
    *  <p>An identifier for the game server group where the game server is running. Use either the <a>GameServerGroup</a> name or ARN value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerGroupName;

    /**
    *  <p>The identifier for the game server to be retrieved.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerId;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DescribeGameServerRequest toAWS() const {
        Aws::GameLift::Model::DescribeGameServerRequest awsDescribeGameServerRequest;

		if (!(this->gameServerGroupName.IsEmpty())) {
            awsDescribeGameServerRequest.SetGameServerGroupName(TCHAR_TO_UTF8(*this->gameServerGroupName));
        }

		if (!(this->gameServerId.IsEmpty())) {
            awsDescribeGameServerRequest.SetGameServerId(TCHAR_TO_UTF8(*this->gameServerId));
        }

        return awsDescribeGameServerRequest;
    }

    bool IsEmpty() const {
        return this->gameServerGroupName.IsEmpty() && this->gameServerId.IsEmpty();
    }
#endif
};
