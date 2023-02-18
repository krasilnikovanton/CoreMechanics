// Copyright 2022-2023 Eriars Game Studio, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SBaseActivity.generated.h"

class USphereComponent;

UCLASS()
class SHOP_API ASBaseActivity : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ASBaseActivity();

protected:
    UPROPERTY(VisibleAnywhere, Category = "Activity")
    USphereComponent* CollisionComponent; 
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    /*virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;*/


public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
};
