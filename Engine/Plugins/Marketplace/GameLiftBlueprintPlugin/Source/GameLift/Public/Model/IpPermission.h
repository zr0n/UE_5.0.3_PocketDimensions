/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/IpPermission.h"

#endif

#include "Model/IpProtocol.h"

#include "IpPermission.generated.h"

USTRUCT(BlueprintType)
struct FIpPermission {
GENERATED_BODY()

    /**
    *  <p>Starting value for a range of allowed port numbers.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int fromPort = 0;

    /**
    *  <p>Ending value for a range of allowed port numbers. Port numbers are end-inclusive. This value must be higher than <code>FromPort</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int toPort = 0;

    /**
    *  <p>Range of allowed IP addresses. This value must be expressed in CIDR notation. Example: "<code>000.000.000.000/[subnet mask]</code>" or optionally the shortened version "<code>0.0.0.0/[subnet mask]</code>".</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString ipRange;

    /**
    *  <p>Network communication protocol used by the fleet.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EIpProtocol protocol = EIpProtocol::NOT_SET;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::IpPermission toAWS() const {
        Aws::GameLift::Model::IpPermission awsIpPermission;

        if (!(this->fromPort == 0)) {
            awsIpPermission.SetFromPort(this->fromPort);
        }

        if (!(this->toPort == 0)) {
            awsIpPermission.SetToPort(this->toPort);
        }

        if (!(this->ipRange.IsEmpty())) {
            awsIpPermission.SetIpRange(TCHAR_TO_UTF8(*this->ipRange));
        }

        switch(this->protocol) {
            case EIpProtocol::TCP:
                awsIpPermission.SetProtocol(Aws::GameLift::Model::IpProtocol::TCP);
                break;
            case EIpProtocol::UDP:
                awsIpPermission.SetProtocol(Aws::GameLift::Model::IpProtocol::UDP);
                break;
            default:
                break;
        }

        return awsIpPermission;
    }

    bool IsEmpty() const {
        return this->fromPort == 0 && this->toPort == 0 && this->ipRange.IsEmpty() && this->protocol == EIpProtocol::NOT_SET;
    }
    FIpPermission &fromAWS(const Aws::GameLift::Model::IpPermission &awsIpPermission) {
        this->fromPort = awsIpPermission.GetFromPort();

        this->toPort = awsIpPermission.GetToPort();

        this->ipRange = UTF8_TO_TCHAR(awsIpPermission.GetIpRange().c_str());

        switch(awsIpPermission.GetProtocol()) {
            case Aws::GameLift::Model::IpProtocol::NOT_SET:
                this->protocol = EIpProtocol::NOT_SET;
                break;
            case Aws::GameLift::Model::IpProtocol::TCP:
                this->protocol = EIpProtocol::TCP;
                break;
            case Aws::GameLift::Model::IpProtocol::UDP:
                this->protocol = EIpProtocol::UDP;
                break;
            default:
                this->protocol = EIpProtocol::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
