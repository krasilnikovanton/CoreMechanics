

#include "SGameModeBase.h"
#include "Player/SBaseCharacter.h"
#include "Player/SPlayerController.h"
#include "UI/SGameHUD.h"
#include "EngineUtils.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

ASGameModeBase ::ASGameModeBase()
{
    DefaultPawnClass = ASBaseCharacter::StaticClass();
    PlayerControllerClass = ASPlayerController::StaticClass();
    HUDClass = ASGameHUD::StaticClass();
};

void ASGameModeBase::SetMatchState(ESMatchState State)
{
    if (MatchState == State) return;

    MatchState = State;
    OnMatchStateChanged.Broadcast(MatchState);
}

bool ASGameModeBase::SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate)
{
    const auto pauseSet = Super::SetPause(PC, CanUnpauseDelegate);
    if (pauseSet && MatchState != ESMatchState::Shop)
    {
        UE_LOG(LogTemp, Display, TEXT("PAUSES"))
        SetMatchState(ESMatchState::Pause);
    }

    return pauseSet;
}

bool ASGameModeBase::ClearPause()
{
    const auto PauseCleared = Super::ClearPause();
    if (PauseCleared)
    {
        SetMatchState(ESMatchState::InProgress);
    }
    return PauseCleared;
}
