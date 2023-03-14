// Copyright 2022-2023 Eriars Game Studio, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/SBaseCharacter.h"
#include "Shopkeeper.generated.h"

class USphereComponent;

/**
 *
 */
UCLASS()
class SHOP_API AShopkeeper : public ASBaseCharacter
{
    GENERATED_BODY()
public:
    AShopkeeper();

protected:
    UPROPERTY(VisibleAnywhere, Category = "Activity")
    USphereComponent* CollisionComponent;
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
};
