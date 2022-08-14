/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/EC2InstanceCounts.h"

#endif

#include "EC2InstanceCounts.generated.h"

USTRUCT(BlueprintType)
struct FEC2InstanceCounts {
GENERATED_BODY()

    /**
    *  <p>Ideal number of active instances in the fleet.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int DESIRED = 0;

    /**
    *  <p>Minimum value allowed for the fleet's instance count.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int MINIMUM = 0;

    /**
    *  <p>Maximum value allowed for the fleet's instance count.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int MAXIMUM = 0;

    /**
    *  <p>Number of instances in the fleet that are starting but not yet active.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int PENDING = 0;

    /**
    *  <p>Actual number of active instances in the fleet.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int ACTIVE = 0;

    /**
    *  <p>Number of active instances in the fleet that are not currently hosting a game session.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int IDLE = 0;

    /**
    *  <p>Number of instances in the fleet that are no longer active but haven't yet been terminated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int TERMINATING = 0;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FEC2InstanceCounts &fromAWS(const Aws::GameLift::Model::EC2InstanceCounts &awsEC2InstanceCounts) {
        this->DESIRED = awsEC2InstanceCounts.GetDESIRED();

        this->MINIMUM = awsEC2InstanceCounts.GetMINIMUM();

        this->MAXIMUM = awsEC2InstanceCounts.GetMAXIMUM();

        this->PENDING = awsEC2InstanceCounts.GetPENDING();

        this->ACTIVE = awsEC2InstanceCounts.GetACTIVE();

        this->IDLE = awsEC2InstanceCounts.GetIDLE();

        this->TERMINATING = awsEC2InstanceCounts.GetTERMINATING();

        return *this;
    }
#endif
};
