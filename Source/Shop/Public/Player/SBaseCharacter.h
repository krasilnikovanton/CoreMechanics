// Copyright 2022-2023 Eriars Game Studio, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SBaseCharacter.generated.h"

class UCameraComponent;
class USceneComponent;

UENUM()
enum class EMovementStatus : uint8
{
    EMS_Walk UMETA(DisplayName = "Walking"),
    EMS_Run UMETA(DisplayName = "Running"),
    EMS_Crouch UMETA(DisplayName = "Crouching"),
    EMS_MAX UMETA(DisplayName = "MaxDefault"),
};

UCLASS()
class SHOP_API ASBaseCharacter : public ACharacter
{
    GENERATED_BODY()

protected:
    //////////////////////////////////////////////////////////////////////////
    // Player Character Movement Properties
    //////////////////////////////////////////////////////////////////////////

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Shop | Movement")
    EMovementStatus MovementStatus;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Shop | Movement")
    float SpeedWalking;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Shop | Movement")
    float SpeedRunning;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Shop | Movement")
    float SpeedCrouching;

public:
    // Sets default values for this character's properties
    ASBaseCharacter();

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Shop | Movement")
    bool isHoldingObject;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent* CameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USceneComponent* SceneCameraComponent;
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    void Crouching();
    UFUNCTION(BlueprintImplementableEvent)
    void CrouchInterp(const bool IsCrouching);

    void PickUp();
    UFUNCTION(BlueprintImplementableEvent)
    void PickUpInterp(const bool isHolding);

    void Launch();
    UFUNCTION(BlueprintImplementableEvent)
    void LaunchInterp(const bool isHolding);

    void StartRunning();
    void StopRunning();

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UFUNCTION(BlueprintCallable)
    void SetMovementStatus(EMovementStatus EMS);

private:
    void MoveForward(float Amount);
    void MoveRight(float Amount);
};
