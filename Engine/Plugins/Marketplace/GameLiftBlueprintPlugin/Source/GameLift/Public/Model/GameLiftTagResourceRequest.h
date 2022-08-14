/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/TagResourceRequest.h"

#endif

#include "Model/GameLiftTag.h"

#include "GameLiftTagResourceRequest.generated.h"

USTRUCT(BlueprintType)
struct FGameLiftTagResourceRequest {
    GENERATED_BODY()

    /**
    *  <p> The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) that is assigned to and uniquely identifies the GameLift resource that you want to assign tags to. GameLift resource ARNs are included in the data object for the resource, which can be retrieved by calling a List or Describe action for the resource type. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString resourceARN;

    /**
    *  <p>A list of one or more tags to assign to the specified GameLift resource. Tags are developer-defined and structured as key-value pairs. The maximum tag limit may be lower than stated. See <a href="https://docs.aws.amazon.com/general/latest/gr/aws_tagging.html"> Tagging AWS Resources</a> for actual tagging limits.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FGameLiftTag> tags;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::TagResourceRequest toAWS() const {
        Aws::GameLift::Model::TagResourceRequest awsTagResourceRequest;

		if (!(this->resourceARN.IsEmpty())) {
            awsTagResourceRequest.SetResourceARN(TCHAR_TO_UTF8(*this->resourceARN));
        }

        for (const FGameLiftTag& elem : this->tags) {
            awsTagResourceRequest.AddTags(elem.toAWS());
        }

        return awsTagResourceRequest;
    }

    bool IsEmpty() const {
        return this->resourceARN.IsEmpty() && this->tags.Num() == 0;
    }
#endif
};
