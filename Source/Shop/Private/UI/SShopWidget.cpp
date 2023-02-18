// Copyright 2022-2023 Eriars Game Studio, Inc. All Rights Reserved.

#include "UI/SShopWidget.h"
#include "GameFramework/GameModeBase.h"
#include "Components/Button.h"
#include "SBaseCharacter.h"
#include <Shop/Public/SGameModeBase.h>
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

bool USShopWidget::Initialize()
{
    const auto InitStatus = Super::Initialize();

    if (Leave)
    {
        Leave->OnClicked.AddDynamic(this, &USShopWidget::OnCloseShop);
    }

    if (Buy)
    {
        Buy->OnClicked.AddDynamic(this, &USShopWidget::OnBuy);
    }

    return InitStatus;
}

void USShopWidget::OnClearPause()
{
    if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;

    GetWorld()->GetAuthGameMode()->ClearPause();
}

void USShopWidget::OnBuy()
{
    UWorld* World = GetWorld();
    if (World)
    {
        const FTransform ItemTransform = FTransform(FRotator::ZeroRotator, FVector(-1300.0f, -2930.0f, 1800.0f));
        ABaseItemActor* CubeActor = World->SpawnActor<ABaseItemActor>(CubeClass, ItemTransform);
    }
}

void USShopWidget::OnCloseShop()
{
    ASGameModeBase* gameMode = Cast<ASGameModeBase>(GetWorld()->GetAuthGameMode());
    gameMode->SetMatchState(ESMatchState::InProgress);

    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    PlayerPawn->EnableInput(GetWorld()->GetFirstPlayerController());
}
