// Copyright 2022-2023 Eriars Game Studio, Inc. All Rights Reserved.

#include "Activity/SBaseActivity.h"
#include "Components/SphereComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseActivity, All, All);

// Sets default values
ASBaseActivity::ASBaseActivity()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    CollisionComponent->InitSphereRadius(50.0f);
    CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    SetRootComponent(CollisionComponent);

    /*CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ASBaseActivity::OnActorBeginOverlap);*/
}

// Called when the game starts or when spawned
void ASBaseActivity::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ASBaseActivity::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

//void ASBaseActivity::NotifyActorBeginOverlap(AActor* OtherActor)
//{
//    Super::NotifyActorBeginOverlap(OtherActor);
//    UE_LOG(LogBaseActivity, Display, TEXT("Activity was taken"))
//}