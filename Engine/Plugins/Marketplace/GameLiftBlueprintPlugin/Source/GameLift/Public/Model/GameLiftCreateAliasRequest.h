/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreateAliasRequest.h"

#endif

#include "Model/GameLiftTag.h"

#include "Model/RoutingStrategy.h"

#include "GameLiftCreateAliasRequest.generated.h"

USTRUCT(BlueprintType)
struct FGameLiftCreateAliasRequest {
GENERATED_BODY()

    /**
    *  <p>Descriptive label that is associated with an alias. Alias names do not need to be unique.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString name;

    /**
    *  <p>Human-readable description of an alias.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString description;

    /**
    *  <p>Object that specifies the fleet and routing type to use for the alias.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FRoutingStrategy routingStrategy;

    /**
    *  <p>A list of labels to assign to the new alias resource. Tags are developer-defined key-value pairs. Tagging AWS resources are useful for resource management, access management and cost allocation. For more information, see <a href="https://docs.aws.amazon.com/general/latest/gr/aws_tagging.html"> Tagging AWS Resources</a> in the <i>AWS General Reference</i>. Once the resource is created, you can use <a>TagResource</a>, <a>UntagResource</a>, and <a>ListTagsForResource</a> to add, remove, and view tags. The maximum tag limit may be lower than stated. See the AWS General Reference for actual tagging limits.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FGameLiftTag> tags;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::CreateAliasRequest toAWS() const {
        Aws::GameLift::Model::CreateAliasRequest awsCreateAliasRequest;

        if (!(this->name.IsEmpty())) {
            awsCreateAliasRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        if (!(this->description.IsEmpty())) {
            awsCreateAliasRequest.SetDescription(TCHAR_TO_UTF8(*this->description));
        }

        if (!(this->routingStrategy.IsEmpty())) {
            awsCreateAliasRequest.SetRoutingStrategy(this->routingStrategy.toAWS());
        }

        for (const FGameLiftTag& elem : this->tags) {
            awsCreateAliasRequest.AddTags(elem.toAWS());
        }

        return awsCreateAliasRequest;
    }

    bool IsEmpty() const {
        return this->name.IsEmpty() && this->description.IsEmpty() && this->routingStrategy.IsEmpty() && this->tags.Num() == 0;
    }
#endif
};
