/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, May 2019
 */

#include "Utils/Crypto/Cipher.h"

FAWSByteBuffer USymmetricCipher::GenerateKey(int64 keyLengthBytes) {
#if WITH_CORE
    return FAWSByteBuffer().fromAWS(Aws::Utils::Crypto::SymmetricCipher::GenerateKey((size_t)keyLengthBytes));
#endif
    return FAWSByteBuffer();
}
