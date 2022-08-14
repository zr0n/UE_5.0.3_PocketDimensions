/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFT

#include "aws/gamelift/server/model/GetInstanceCertificateResult.h"

#endif

#include "GetInstanceCertificateResult.generated.h"

USTRUCT(BlueprintType)
struct FGetInstanceCertificateResult {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString CertificatePath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString CertificateChainPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString PrivateKeyPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString Hostname;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString RootCertificatePath;

#if WITH_GAMELIFT
    public:
    FGetInstanceCertificateResult& fromAWS(const Aws::GameLift::Server::Model::GetInstanceCertificateResult& awsGetInstanceCertificateResult) {
        this->CertificatePath = awsGetInstanceCertificateResult.GetCertificatePath();

        this->CertificateChainPath = awsGetInstanceCertificateResult.GetCertificateChainPath();

        this->PrivateKeyPath = awsGetInstanceCertificateResult.GetPrivateKeyPath();

        this->Hostname = awsGetInstanceCertificateResult.GetHostName();

        this->RootCertificatePath = awsGetInstanceCertificateResult.GetRootCertificatePath();

        return *this;
    };

#endif
};