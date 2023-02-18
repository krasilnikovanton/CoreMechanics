// Copyright 2022-2023 Eriars Game Studio, Inc. All Rights Reserved.

#include "Activity/SShop.h"
#include "Gameframework/GameModeBase.h"
#include <Shop/Public/Player/SBaseCharacter.h>
#include <Shop/Public/SGameModeBase.h>
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>


void ASShop::NotifyActorBeginOverlap(AActor* OtherActor)
{
    Super::NotifyActorBeginOverlap(OtherActor);

    ASBaseCharacter* shopActivity = Cast<ASBaseCharacter>(OtherActor);
    if (shopActivity != nullptr)
    {
        UE_LOG(LogTemp, Display, TEXT("In"))
        EnableInput(GetWorld()->GetFirstPlayerController());
        if (!InputComponent) return;
        InputComponent->BindAction("PickUp", IE_Released, this, &ASShop::OpenShopUMG);
    }
}

void ASShop::NotifyActorEndOverlap(AActor* OtherActor)
{
    Super::NotifyActorBeginOverlap(OtherActor);

    ASBaseCharacter* shopActivity = Cast<ASBaseCharacter>(OtherActor);
    if (shopActivity != nullptr)
    {
        DisableInput(GetWorld()->GetFirstPlayerController());
    }
}

void ASShop::OpenShopUMG()
{
    ASGameModeBase* gameMode = Cast<ASGameModeBase>(GetWorld()->GetAuthGameMode());
    gameMode->SetMatchState(ESMatchState::Shop);

    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    PlayerPawn->DisableInput(GetWorld()->GetFirstPlayerController());

    /*OnPauseGame();*/
}

void ASShop::OnPauseGame()
{
    if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;

    GetWorld()->GetAuthGameMode()->SetPause(GetWorld()->GetFirstPlayerController());
}