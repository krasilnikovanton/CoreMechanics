

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SCoreTypes.h"
#include "SGameModeBase.generated.h"

/**
 *
 */
UCLASS()
class SHOP_API ASGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:
    ASGameModeBase();

    FOnMatchStateChangedSignature OnMatchStateChanged;

    virtual bool SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate = FCanUnpause()) override;
    virtual bool ClearPause() override;

    void SetMatchState(ESMatchState State);

private:
    ESMatchState MatchState = ESMatchState::WaitingToStart;
};
