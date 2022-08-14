/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ListTagsForResourceRequest.h"

#endif

#include "GameLiftListTagsForResourceRequest.generated.h"

USTRUCT(BlueprintType)
struct FGameLiftListTagsForResourceRequest {
GENERATED_BODY()

    /**
    *  <p> The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) that is assigned to and uniquely identifies the GameLift resource that you want to retrieve tags for. GameLift resource ARNs are included in the data object for the resource, which can be retrieved by calling a List or Describe action for the resource type. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString resourceARN;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::ListTagsForResourceRequest toAWS() const {
        Aws::GameLift::Model::ListTagsForResourceRequest awsListTagsForResourceRequest;

		if (!(this->resourceARN.IsEmpty())) {
            awsListTagsForResourceRequest.SetResourceARN(TCHAR_TO_UTF8(*this->resourceARN));
        }

        return awsListTagsForResourceRequest;
    }

    bool IsEmpty() const {
        return this->resourceARN.IsEmpty();
    }
#endif
};
