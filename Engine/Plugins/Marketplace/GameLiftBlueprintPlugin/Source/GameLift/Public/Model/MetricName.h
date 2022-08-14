/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "MetricName.generated.h"

UENUM(BlueprintType)
enum class EMetricName : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ActivatingGameSessions        UMETA(DisplayName = "activatinggamesessions"),
    ActiveGameSessions        UMETA(DisplayName = "activegamesessions"),
    ActiveInstances        UMETA(DisplayName = "activeinstances"),
    AvailableGameSessions        UMETA(DisplayName = "availablegamesessions"),
    AvailablePlayerSessions        UMETA(DisplayName = "availableplayersessions"),
    CurrentPlayerSessions        UMETA(DisplayName = "currentplayersessions"),
    IdleInstances        UMETA(DisplayName = "idleinstances"),
    PercentAvailableGameSessions        UMETA(DisplayName = "percentavailablegamesessions"),
    PercentIdleInstances        UMETA(DisplayName = "percentidleinstances"),
    QueueDepth        UMETA(DisplayName = "queuedepth"),
    WaitTime        UMETA(DisplayName = "waittime")
};
