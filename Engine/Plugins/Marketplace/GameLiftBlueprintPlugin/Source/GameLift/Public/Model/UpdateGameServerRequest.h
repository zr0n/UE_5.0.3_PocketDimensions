/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/UpdateGameServerRequest.h"

#endif

#include "Model/GameServerUtilizationStatus.h"
#include "Model/GameServerHealthCheck.h"

#include "UpdateGameServerRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateGameServerRequest {
    GENERATED_BODY()

    /**
    *  <p>An identifier for the game server group where the game server is running. Use either the <a>GameServerGroup</a> name or ARN value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerGroupName;

    /**
    *  <p>The identifier for the game server to be updated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerId;

    /**
    *  <p>A set of custom game server properties, formatted as a single string value. This data is passed to a game client or service when it requests information on a game servers using <a>DescribeGameServer</a> or <a>ClaimGameServer</a>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameServerData;

    /**
    *  <p>Indicates whether the game server is available or is currently hosting gameplay.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EAWSGameServerUtilizationStatus utilizationStatus = EAWSGameServerUtilizationStatus::NOT_SET;

    /**
    *  <p>Indicates health status of the game server. An update that explicitly includes this parameter updates the game server's <i>LastHealthCheckTime</i> time stamp. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EAWSGameServerHealthCheck healthCheck = EAWSGameServerHealthCheck::NOT_SET;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::UpdateGameServerRequest toAWS() const {
        Aws::GameLift::Model::UpdateGameServerRequest awsUpdateGameServerRequest;

		if (!(this->gameServerGroupName.IsEmpty())) {
            awsUpdateGameServerRequest.SetGameServerGroupName(TCHAR_TO_UTF8(*this->gameServerGroupName));
        }

		if (!(this->gameServerId.IsEmpty())) {
            awsUpdateGameServerRequest.SetGameServerId(TCHAR_TO_UTF8(*this->gameServerId));
        }

		if (!(this->gameServerData.IsEmpty())) {
            awsUpdateGameServerRequest.SetGameServerData(TCHAR_TO_UTF8(*this->gameServerData));
        }

        switch(this->utilizationStatus) {
            case EAWSGameServerUtilizationStatus::AVAILABLE:
                awsUpdateGameServerRequest.SetUtilizationStatus(Aws::GameLift::Model::GameServerUtilizationStatus::AVAILABLE);
                break;
            case EAWSGameServerUtilizationStatus::UTILIZED:
                awsUpdateGameServerRequest.SetUtilizationStatus(Aws::GameLift::Model::GameServerUtilizationStatus::UTILIZED);
                break;
            default:
                break;
		}

        switch(this->healthCheck) {
            case EAWSGameServerHealthCheck::HEALTHY:
                awsUpdateGameServerRequest.SetHealthCheck(Aws::GameLift::Model::GameServerHealthCheck::HEALTHY);
                break;
            default:
                break;
		}

        return awsUpdateGameServerRequest;
    }

    bool IsEmpty() const {
        return this->gameServerGroupName.IsEmpty() && this->gameServerId.IsEmpty() && this->gameServerData.IsEmpty() && utilizationStatus == EAWSGameServerUtilizationStatus::NOT_SET && healthCheck == EAWSGameServerHealthCheck::NOT_SET;
    }
#endif
};
