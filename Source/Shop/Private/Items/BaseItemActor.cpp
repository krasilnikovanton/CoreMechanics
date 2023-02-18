// Copyright 2022-2023 Eriars Game Studio, Inc. All Rights Reserved.

#include "Items/BaseItemActor.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values
ABaseItemActor::ABaseItemActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
    SetRootComponent(BaseMesh);
}

// Called when the game starts or when spawned
void ABaseItemActor::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ABaseItemActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
