

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SCoreTypes.h"
#include "SGameHUD.generated.h"

/**
 *
 */
UCLASS()
class SHOP_API ASGameHUD : public AHUD
{
    GENERATED_BODY()

public:
    virtual void DrawHUD() override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> PlayerHUDWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
    TSubclassOf<UUserWidget> ShopWidgetClass;

    virtual void BeginPlay() override;

private:
    UPROPERTY()
    TMap<ESMatchState, UUserWidget*> GameWidgets;

    UPROPERTY()
    UUserWidget* CurrentWidget = nullptr;

    void DrawCrossHair();
    void OnMatchStateChanged(ESMatchState State);
};
