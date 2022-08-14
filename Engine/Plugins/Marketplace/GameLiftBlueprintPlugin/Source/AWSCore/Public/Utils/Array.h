/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, May 2019
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_CORE

#include "aws/core/utils/Array.h"
#include "aws/core/utils/memory/stl/AWSStringStream.h"
#include "aws/core/utils/memory/stl/SimpleStringStream.h"
#include <iomanip>

#endif

#include "Array.generated.h"

USTRUCT(BlueprintType)
struct FAWSByteBuffer {
    GENERATED_BODY()

    /*
     * don't modify it if you don't understand it
     * each bytes should be splitted by whitespace. for example: e0 af dc
     * */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Client")
    FString byteBuffer;

#if WITH_CORE
public:
    Aws::Utils::ByteBuffer toAWS() const {
        if (!(this->byteBuffer.IsEmpty())) {
            Aws::String awsString = TCHAR_TO_UTF8(*this->byteBuffer);

            Aws::SimpleStringStream hex_chars_stream(awsString);
            Aws::Vector<unsigned char> bytes;
            
            unsigned int c;
            while (hex_chars_stream >> std::hex >> c)
            {
                bytes.push_back(c);
            }
            
            Aws::Utils::ByteBuffer awsByteBuffer(bytes.data(), bytes.size());

            return awsByteBuffer;
            
        } else {
            return Aws::Utils::ByteBuffer();
        }
    };
    
    bool IsEmpty() const {
        return this->byteBuffer.IsEmpty();
    }
    
    FAWSByteBuffer& fromAWS(const Aws::Utils::ByteBuffer& awsByteBuffer) {
        Aws::StringStream buffer;
        for (int i = 0; i < awsByteBuffer.GetLength(); i++) {
            if (i != 0) {
                buffer << " ";
            }
            buffer << std::hex << std::setfill('0');
            buffer << std::setw(2)  << (0xff & (unsigned char)awsByteBuffer[i]);
        }
        Aws::String hexString = buffer.str();
        this->byteBuffer = UTF8_TO_TCHAR(hexString.c_str());

        return *this;
    };
#endif
};
