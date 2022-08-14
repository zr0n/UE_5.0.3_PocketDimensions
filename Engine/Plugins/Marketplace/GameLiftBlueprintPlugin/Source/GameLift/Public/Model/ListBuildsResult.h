/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ListBuildsResult.h"

#endif

#include "Model/Build.h"

#include "ListBuildsResult.generated.h"

USTRUCT(BlueprintType)
struct FListBuildsResult {
GENERATED_BODY()

    /**
    *  <p>Collection of build records that match the request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FBuild> builds;

    /**
    *  <p>Token that indicates where to resume retrieving results on the next call to this action. If no token is returned, these results represent the end of the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FListBuildsResult &fromAWS(const Aws::GameLift::Model::ListBuildsResult &awsListBuildsResult) {
        this->builds.Empty();
        for (const Aws::GameLift::Model::Build& elem : awsListBuildsResult.GetBuilds()) {
            this->builds.Add(FBuild().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListBuildsResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
