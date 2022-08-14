/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/UntagResourceRequest.h"

#endif

#include "GameLiftUntagResourceRequest.generated.h"

USTRUCT(BlueprintType)
struct FGameLiftUntagResourceRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) that is assigned to and uniquely identifies the GameLift resource that you want to remove tags from. GameLift resource ARNs are included in the data object for the resource, which can be retrieved by calling a List or Describe action for the resource type. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString resourceARN;

    /**
    *  <p>A list of one or more tag keys to remove from the specified GameLift resource. An AWS resource can have only one tag with a specific tag key, so specifying the tag key identifies which tag to remove. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FString> tagKeys;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::UntagResourceRequest toAWS() const {
        Aws::GameLift::Model::UntagResourceRequest awsUntagResourceRequest;

		if (!(this->resourceARN.IsEmpty())) {
            awsUntagResourceRequest.SetResourceARN(TCHAR_TO_UTF8(*this->resourceARN));
        }

        for (const FString& elem : this->tagKeys) {
            awsUntagResourceRequest.AddTagKeys(TCHAR_TO_UTF8(*elem));
        }

        return awsUntagResourceRequest;
    }

    bool IsEmpty() const {
        return this->resourceARN.IsEmpty() && this->tagKeys.Num() == 0;
    }
#endif
};
