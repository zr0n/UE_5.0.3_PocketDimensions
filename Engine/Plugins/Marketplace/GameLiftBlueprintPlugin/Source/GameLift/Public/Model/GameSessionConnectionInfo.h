/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/GameSessionConnectionInfo.h"

#endif

#include "Model/MatchedPlayerSession.h"

#include "GameSessionConnectionInfo.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameSessionConnectionInfo {
GENERATED_BODY()

    /**
    *  <p>Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) that is assigned to a game session and uniquely identifies it.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameSessionArn;

    /**
    *  <p>IP address of the game session. To connect to a Amazon GameLift game server, an app needs both the IP address and port number.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString ipAddress;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString dnsName;

    /**
    *  <p>Port number for the game session. To connect to a Amazon GameLift game server, an app needs both the IP address and port number.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int port = 0;

    /**
    *  <p>Collection of player session IDs, one for each player ID that was included in the original matchmaking request. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FMatchedPlayerSession> matchedPlayerSessions;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FAWSGameSessionConnectionInfo &fromAWS(const Aws::GameLift::Model::GameSessionConnectionInfo &awsGameSessionConnectionInfo) {
        this->gameSessionArn = UTF8_TO_TCHAR(awsGameSessionConnectionInfo.GetGameSessionArn().c_str());

        this->ipAddress = UTF8_TO_TCHAR(awsGameSessionConnectionInfo.GetIpAddress().c_str());

        this->dnsName = UTF8_TO_TCHAR(awsGameSessionConnectionInfo.GetDnsName().c_str());

        this->port = awsGameSessionConnectionInfo.GetPort();

        this->matchedPlayerSessions.Empty();
        for (const Aws::GameLift::Model::MatchedPlayerSession& elem : awsGameSessionConnectionInfo.GetMatchedPlayerSessions()) {
            this->matchedPlayerSessions.Add(FMatchedPlayerSession().fromAWS(elem));
        }

        return *this;
    }
#endif
};
