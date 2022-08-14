/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CertificateConfiguration.h"

#endif

#include "Model/CertificateType.h"

#include "CertificateConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FCertificateConfiguration {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    ECertificateType certificateType = ECertificateType::NOT_SET;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::CertificateConfiguration toAWS() const {
        Aws::GameLift::Model::CertificateConfiguration awsCertificateConfiguration;

        switch(this->certificateType) {
            case ECertificateType::DISABLED:
                awsCertificateConfiguration.SetCertificateType(Aws::GameLift::Model::CertificateType::DISABLED);
                break;
            case ECertificateType::GENERATED:
                awsCertificateConfiguration.SetCertificateType(Aws::GameLift::Model::CertificateType::GENERATED);
                break;
            default:
                break;
        }

        return awsCertificateConfiguration;
    }

    bool IsEmpty() const {
        return this->certificateType == ECertificateType::NOT_SET;
    }

    FCertificateConfiguration &fromAWS(const Aws::GameLift::Model::CertificateConfiguration &awsCertificateConfiguration) {
        switch(awsCertificateConfiguration.GetCertificateType()) {
            case Aws::GameLift::Model::CertificateType::NOT_SET:
                this->certificateType = ECertificateType::NOT_SET;
                break;
            case Aws::GameLift::Model::CertificateType::DISABLED:
                this->certificateType = ECertificateType::DISABLED;
                break;
            case Aws::GameLift::Model::CertificateType::GENERATED:
                this->certificateType = ECertificateType::GENERATED;
                break;
            default:
                this->certificateType = ECertificateType::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
