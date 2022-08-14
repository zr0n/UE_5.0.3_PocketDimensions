/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ListBuildsRequest.h"

#endif

#include "Model/BuildStatus.h"

#include "ListBuildsRequest.generated.h"

USTRUCT(BlueprintType)
struct FListBuildsRequest {
GENERATED_BODY()

    /**
    *  <p>Build status to filter results by. To retrieve all builds, leave this parameter empty.</p> <p>Possible build statuses include the following:</p> <ul> <li> <p> <b>INITIALIZED</b> -- A new build has been defined, but no files have been uploaded. You cannot create fleets for builds that are in this status. When a build is successfully created, the build status is set to this value. </p> </li> <li> <p> <b>READY</b> -- The game build has been successfully uploaded. You can now create new fleets for this build.</p> </li> <li> <p> <b>FAILED</b> -- The game build upload failed. You cannot create new fleets for this build. </p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EBuildStatus status = EBuildStatus::NOT_SET;

    /**
    *  <p>Maximum number of results to return. Use this parameter with <code>NextToken</code> to get results as a set of sequential pages.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int limit = 0;

    /**
    *  <p>Token that indicates the start of the next sequential page of results. Use the token that is returned with a previous call to this action. To start at the beginning of the result set, do not specify a value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::ListBuildsRequest toAWS() const {
        Aws::GameLift::Model::ListBuildsRequest awsListBuildsRequest;

        switch(this->status) {
            case EBuildStatus::INITIALIZED:
                awsListBuildsRequest.SetStatus(Aws::GameLift::Model::BuildStatus::INITIALIZED);
                break;
            case EBuildStatus::READY:
                awsListBuildsRequest.SetStatus(Aws::GameLift::Model::BuildStatus::READY);
                break;
            case EBuildStatus::FAILED:
                awsListBuildsRequest.SetStatus(Aws::GameLift::Model::BuildStatus::FAILED);
                break;
            default:
                break;
        }

        if (this->limit != 0) {
            awsListBuildsRequest.SetLimit(this->limit);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsListBuildsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsListBuildsRequest;
    }

    bool IsEmpty() const {
        return this->status == EBuildStatus::NOT_SET && this->limit == 0 && this->nextToken.IsEmpty();
    }
#endif
};
