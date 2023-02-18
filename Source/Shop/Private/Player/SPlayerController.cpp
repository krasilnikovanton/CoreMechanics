// Copyright 2022-2023 Eriars Game Studio, Inc. All Rights Reserved.


#include "Player/SPlayerController.h"
#include "SGameModeBase.h"

void ASPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (GetWorld())
    {
        const auto GameMode = Cast<ASGameModeBase>(GetWorld()->GetAuthGameMode());
        if (GameMode)
        {
            GameMode->OnMatchStateChanged.AddUObject(this, &ASPlayerController::OnMatchStateChanged);
        }
    }
}

void ASPlayerController::OnMatchStateChanged(ESMatchState State)
{
    if (State == ESMatchState::InProgress)
    {
        UE_LOG(LogTemp, Display, TEXT("GameOnly"))
        SetInputMode(FInputModeGameOnly());
        bShowMouseCursor = false;
    }
    else
    {
        UE_LOG(LogTemp, Display, TEXT("UIOnly"))
        SetInputMode(FInputModeUIOnly());
        bShowMouseCursor = true;
    }
}

