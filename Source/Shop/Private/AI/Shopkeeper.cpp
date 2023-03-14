// Copyright 2022-2023 Eriars Game Studio, Inc. All Rights Reserved.

#include "AI/Shopkeeper.h"
#include "Components/SphereComponent.h"

AShopkeeper::AShopkeeper()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    CollisionComponent->InitSphereRadius(50.0f);
    CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    CollisionComponent->SetupAttachment(GetRootComponent());
}

void AShopkeeper::BeginPlay()
{
    Super::BeginPlay();
}

void AShopkeeper::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
