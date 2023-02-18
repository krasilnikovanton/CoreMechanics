// Copyright 2022-2023 Eriars Game Studio, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Activity/SBaseActivity.h"
#include "SShop.generated.h"

/**
 *
 */
UCLASS()
class SHOP_API ASShop : public ASBaseActivity
{
    GENERATED_BODY()
protected:
    UFUNCTION()
    virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
    UFUNCTION()
    virtual void NotifyActorEndOverlap(AActor* OtherActor) override;
    void OpenShopUMG();
    void OnPauseGame();
};
