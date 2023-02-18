// Copyright 2022-2023 Eriars Game Studio, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Items/BaseItemActor.h"
#include "SShopWidget.generated.h"

class UButton;

UCLASS()
class SHOP_API USShopWidget : public UUserWidget
{
    GENERATED_BODY()
public:
    virtual bool Initialize() override;

protected:
    UPROPERTY(meta = (BindWidget))
    UButton* Leave;

    UPROPERTY(meta = (BindWidget))
    UButton* Buy;

    UPROPERTY(EditAnywhere)
    TSubclassOf<ABaseItemActor> CubeClass;

private:
    UFUNCTION()
    void OnClearPause();

    UFUNCTION()
    void OnBuy();

    UFUNCTION()
    void OnCloseShop();
};
