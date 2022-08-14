/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/VpcPeeringConnectionStatus.h"

#endif

#include "VpcPeeringConnectionStatus.generated.h"

USTRUCT(BlueprintType)
struct FVpcPeeringConnectionStatus {
    GENERATED_BODY()

    /**
    *  <p>Code indicating the status of a VPC peering connection.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString code;

    /**
    *  <p>Additional messaging associated with the connection status. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString message;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FVpcPeeringConnectionStatus &fromAWS(const Aws::GameLift::Model::VpcPeeringConnectionStatus &awsVpcPeeringConnectionStatus) {
        this->code = UTF8_TO_TCHAR(awsVpcPeeringConnectionStatus.GetCode().c_str());

        this->message = UTF8_TO_TCHAR(awsVpcPeeringConnectionStatus.GetMessage().c_str());

        return *this;
    }
#endif
};
