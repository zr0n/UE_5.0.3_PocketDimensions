/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, May 2019
 */

#include "Utils/UUID.h"

FAWSUUID UUUID::RandomUUID() {
#if WITH_CORE
    return FAWSUUID().fromAWS(Aws::Utils::UUID::RandomUUID());
#endif
    return FAWSUUID();
}
