/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeFleetLocationAttributesResult.h"

#endif

#include "Model/AWSGameLiftLocationAttributes.h"

#include "AWSGameLiftDescribeFleetLocationAttributesResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftDescribeFleetLocationAttributesResult {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the fleet that location attributes were requested for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) that is assigned to a GameLift fleet resource and uniquely identifies it. ARNs are unique across all Regions. Format is <code>arn:aws:gamelift:&lt;region&gt;::fleet/fleet-a1234567-b8c9-0d1e-2fa3-b45c6d7e8912</code>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetArn;

    /**
    *  <p> Location-specific information on the requested fleet's remote locations. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FAWSGameLiftLocationAttributes> locationAttributes;

    /**
    *  <p>A token that indicates where to resume retrieving results on the next call to this operation. If no token is returned, these results represent the end of the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FAWSGameLiftDescribeFleetLocationAttributesResult &fromAWS(const Aws::GameLift::Model::DescribeFleetLocationAttributesResult &awsDescribeFleetLocationAttributesResult) {
        this->fleetId = UTF8_TO_TCHAR(awsDescribeFleetLocationAttributesResult.GetFleetId().c_str());

        this->fleetArn = UTF8_TO_TCHAR(awsDescribeFleetLocationAttributesResult.GetFleetArn().c_str());

        this->locationAttributes.Empty();
        for (const Aws::GameLift::Model::LocationAttributes& elem : awsDescribeFleetLocationAttributesResult.GetLocationAttributes()) {
            this->locationAttributes.Add(FAWSGameLiftLocationAttributes().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsDescribeFleetLocationAttributesResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
