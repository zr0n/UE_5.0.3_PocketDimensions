/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/LaunchTemplateSpecification.h"

#endif

#include "LaunchTemplateSpecification.generated.h"

USTRUCT(BlueprintType)
struct FLaunchTemplateSpecification {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for an existing EC2 launch template.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString launchTemplateId;

    /**
    *  <p>A readable identifier for an existing EC2 launch template. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString launchTemplateName;

    /**
    *  <p>The version of the EC2 launch template to use. If no version is specified, the default version will be used. EC2 allows you to specify a default version for a launch template, if none is set, the default is the first version created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString version;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::LaunchTemplateSpecification toAWS() const {
        Aws::GameLift::Model::LaunchTemplateSpecification awsLaunchTemplateSpecification;

// @TODO: check
		if (!(this->launchTemplateId.IsEmpty())) {
            awsLaunchTemplateSpecification.SetLaunchTemplateId(TCHAR_TO_UTF8(*this->launchTemplateId));
        }

// @TODO: check
		if (!(this->launchTemplateName.IsEmpty())) {
            awsLaunchTemplateSpecification.SetLaunchTemplateName(TCHAR_TO_UTF8(*this->launchTemplateName));
        }

// @TODO: check
		if (!(this->version.IsEmpty())) {
            awsLaunchTemplateSpecification.SetVersion(TCHAR_TO_UTF8(*this->version));
        }

        return awsLaunchTemplateSpecification;
    }

    bool IsEmpty() const {
        return this->launchTemplateId.IsEmpty() && this->launchTemplateName.IsEmpty() && this->version.IsEmpty() && true;
    }
#endif
};
