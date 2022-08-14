/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeGameServerGroupRequest.h"

#endif

#include "DescribeGameServerGroupRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeGameServerGroupRequest {
    GENERATED_BODY()

    /**
    *  <p>The unique identifier for the game server group being requested. Use either the <a>GameServerGroup</a> name or ARN value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerGroupName;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DescribeGameServerGroupRequest toAWS() const {
        Aws::GameLift::Model::DescribeGameServerGroupRequest awsDescribeGameServerGroupRequest;

		if (!(this->gameServerGroupName.IsEmpty())) {
            awsDescribeGameServerGroupRequest.SetGameServerGroupName(TCHAR_TO_UTF8(*this->gameServerGroupName));
        }

        return awsDescribeGameServerGroupRequest;
    }

    bool IsEmpty() const {
        return this->gameServerGroupName.IsEmpty();
    }
#endif
};
