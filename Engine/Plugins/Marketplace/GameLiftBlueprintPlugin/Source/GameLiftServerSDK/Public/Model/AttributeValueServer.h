/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFT

#include "aws/gamelift/server/model/AttributeValue.h"

#endif

#include "AttributeValueServer.generated.h"

USTRUCT(BlueprintType)
struct FKeyAndValue {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString key;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    float value = 0.0f;

#if WITH_GAMELIFT
    public:
    Aws::GameLift::Server::Model::AttributeValue::KeyAndValue toAWS() const {
        return Aws::GameLift::Server::Model::AttributeValue::KeyAndValue(TCHAR_TO_UTF8(*this->key), this->value);
    };

#endif
};

UENUM(BlueprintType)
enum class EAttrType : uint8 {
    NONE                UMETA(DisplayName = "none"),
    STRING              UMETA(DisplayName = "string"),
    FLOAT               UMETA(DisplayName = "float"),
    STRING_LIST         UMETA(DisplayName = "string list"),
    STRING_FLOAT_MAP    UMETA(DisplayName = "string float map")
};

USTRUCT(BlueprintType)
struct FAttributeValueServer {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString s;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    float n = 0.0f;

    /*
	 * don't add more than 10 elements
	 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    TArray<FString> sL;

    /*
	 * don't add more than 10 elements
	 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    TArray<FKeyAndValue> sDM;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    EAttrType attrType = EAttrType::NONE;

#if WITH_GAMELIFT
    public:
    Aws::GameLift::Server::Model::AttributeValue toAWS() const {
        Aws::GameLift::Server::Model::AttributeValue awsAttributeValue;

        switch (this->attrType) {
            case EAttrType::NONE:
                break;
            case EAttrType::STRING:
                awsAttributeValue = Aws::GameLift::Server::Model::AttributeValue(TCHAR_TO_UTF8(*this->s));
                break;
            case EAttrType::FLOAT:
                awsAttributeValue = Aws::GameLift::Server::Model::AttributeValue(this->n);
                break;
            case EAttrType::STRING_LIST:
                awsAttributeValue = Aws::GameLift::Server::Model::AttributeValue(Aws::GameLift::Server::Model::AttributeValue::AttrType::STRING_LIST);

                for (const FString& awsS : this->sL) {
                    awsAttributeValue.AddString(TCHAR_TO_UTF8(*awsS));
                }
                break;
            case EAttrType::STRING_FLOAT_MAP:
                awsAttributeValue = Aws::GameLift::Server::Model::AttributeValue(Aws::GameLift::Server::Model::AttributeValue::AttrType::STRING_DOUBLE_MAP);

                for (const FKeyAndValue& awsSDM : this->sDM) {
                    awsAttributeValue.AddStringAndDouble(TCHAR_TO_UTF8(*awsSDM.key), awsSDM.value);
                }
                break;
            default:
                break;
        }

        return awsAttributeValue;
    };

#endif
};