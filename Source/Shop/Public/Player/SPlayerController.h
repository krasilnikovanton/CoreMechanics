// Copyright 2022-2023 Eriars Game Studio, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SCoreTypes.h"
#include "SPlayerController.generated.h"

/**
 *
 */
UCLASS()
class SHOP_API ASPlayerController : public APlayerController
{
    GENERATED_BODY()
protected:
    virtual void BeginPlay() override;

private:
    void OnMatchStateChanged(ESMatchState State);
};
