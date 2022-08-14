/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/InstanceAccess.h"

#endif

#include "Model/OperatingSystem.h"
#include "Model/InstanceCredentials.h"

#include "InstanceAccess.generated.h"

USTRUCT(BlueprintType)
struct FInstanceAccess {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a fleet containing the instance being accessed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>Unique identifier for an instance being accessed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString instanceId;

    /**
    *  <p>IP address assigned to the instance.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString ipAddress;

    /**
    *  <p>Operating system that is running on the instance.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EOperatingSystem operatingSystem = EOperatingSystem::NOT_SET;

    /**
    *  <p>Credentials required to access the instance.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FInstanceCredentials credentials;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FInstanceAccess &fromAWS(const Aws::GameLift::Model::InstanceAccess &awsInstanceAccess) {
        this->fleetId = UTF8_TO_TCHAR(awsInstanceAccess.GetFleetId().c_str());

        this->instanceId = UTF8_TO_TCHAR(awsInstanceAccess.GetInstanceId().c_str());

        this->ipAddress = UTF8_TO_TCHAR(awsInstanceAccess.GetIpAddress().c_str());

        switch(awsInstanceAccess.GetOperatingSystem()) {
            case Aws::GameLift::Model::OperatingSystem::NOT_SET:
                this->operatingSystem = EOperatingSystem::NOT_SET;
                break;
            case Aws::GameLift::Model::OperatingSystem::WINDOWS_2012:
                this->operatingSystem = EOperatingSystem::WINDOWS_2012;
                break;
            case Aws::GameLift::Model::OperatingSystem::AMAZON_LINUX:
                this->operatingSystem = EOperatingSystem::AMAZON_LINUX;
                break;
            case Aws::GameLift::Model::OperatingSystem::AMAZON_LINUX_2:
                this->operatingSystem = EOperatingSystem::AMAZON_LINUX_2;
                break;
            default:
                this->operatingSystem = EOperatingSystem::NOT_SET;
                break;
        }

        this->credentials.fromAWS(awsInstanceAccess.GetCredentials());

        return *this;
    }
#endif
};
