/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/StartMatchBackfillRequest.h"

#endif

#include "Model/AWSPlayer.h"

#include "StartMatchBackfillRequest.generated.h"

USTRUCT(BlueprintType)
struct FStartMatchBackfillRequest {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a matchmaking ticket. If no ticket ID is specified here, Amazon GameLift will generate one in the form of a UUID. Use this identifier to track the match backfill ticket status and retrieve match results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString ticketId;

    /**
    *  <p>Name of the matchmaker to use for this request. The name of the matchmaker that was used with the original game session is listed in the <a>GameSession</a> object, <code>MatchmakerData</code> property. This property contains a matchmaking configuration ARN value, which includes the matchmaker name. (In the ARN value "arn:aws:gamelift:us-west-2:111122223333:matchmakingconfiguration/MM-4v4", the matchmaking configuration name is "MM-4v4".) Use only the name for this parameter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString configurationName;

    /**
    *  <p>Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) that is assigned to a game session and uniquely identifies it. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameSessionArn;

    /**
    *  <p>Match information on all players that are currently assigned to the game session. This information is used by the matchmaker to find new players and add them to the existing game.</p> <ul> <li> <p>PlayerID, PlayerAttributes, Team -\\- This information is maintained in the <a>GameSession</a> object, <code>MatchmakerData</code> property, for all players who are currently assigned to the game session. The matchmaker data is in JSON syntax, formatted as a string. For more details, see <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/match-server.html#match-server-data"> Match Data</a>. </p> </li> <li> <p>LatencyInMs -\\- If the matchmaker uses player latency, include a latency value, in milliseconds, for the region that the game session is currently in. Do not include latency values for any other region.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FAWSPlayer> players;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::StartMatchBackfillRequest toAWS() const {
        Aws::GameLift::Model::StartMatchBackfillRequest awsStartMatchBackfillRequest;

        if (!(this->ticketId.IsEmpty())) {
            awsStartMatchBackfillRequest.SetTicketId(TCHAR_TO_UTF8(*this->ticketId));
        }

        if (!(this->configurationName.IsEmpty())) {
            awsStartMatchBackfillRequest.SetConfigurationName(TCHAR_TO_UTF8(*this->configurationName));
        }

        if (!(this->gameSessionArn.IsEmpty())) {
            awsStartMatchBackfillRequest.SetGameSessionArn(TCHAR_TO_UTF8(*this->gameSessionArn));
        }

        for (const FAWSPlayer& elem : this->players) {
            awsStartMatchBackfillRequest.AddPlayers(elem.toAWS());
        }

        return awsStartMatchBackfillRequest;
    }

    bool IsEmpty() const {
        return this->ticketId.IsEmpty() && this->configurationName.IsEmpty() && this->gameSessionArn.IsEmpty() && this->players.Num() == 0;
    }
#endif
};
