#pragma once

#include "SCoreTypes.generated.h"

UENUM(BlueprintType)
enum class ESMatchState : uint8
{
    WaitingToStart = 0,
    InProgress,
    Pause,
    Shop,
    GameOver
};

DECLARE_MULTICAST_DELEGATE_OneParam(FOnMatchStateChangedSignature, ESMatchState);