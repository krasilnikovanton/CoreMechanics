// Copyright 2022-2023 Eriars Game Studio, Inc. All Rights Reserved.

#include "Player/SBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "Components/InputComponent.h"
#include "Activity/SShop.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseCharacter, All, All);

// Sets default values
ASBaseCharacter::ASBaseCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(GetRootComponent());

    SceneCameraComponent = CreateDefaultSubobject<USceneComponent>("SceneCameraComponent");
    SceneCameraComponent->SetupAttachment(CameraComponent);

    /** Character's Default Properties **/
    /** Movements **/
    MovementStatus = EMovementStatus::EMS_Walk;
    SpeedWalking = 400.f;
    SpeedRunning = 700.f;
    SpeedCrouching = 300.f;
    isHoldingObject = false;
}

// Called when the game starts or when spawned
void ASBaseCharacter::BeginPlay()
{
    Super::BeginPlay();

    /** TODO: Add more movement settings **/
    GetCharacterMovement()->MaxWalkSpeed = SpeedWalking;
    GetCharacterMovement()->MaxWalkSpeedCrouched = SpeedCrouching;
}

// Called every frame
void ASBaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    if (!ensure(PlayerInputComponent)) return;

    PlayerInputComponent->BindAxis("MoveForward", this, &ASBaseCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ASBaseCharacter::MoveRight);
    PlayerInputComponent->BindAxis("LookUp", this, &ASBaseCharacter::AddControllerPitchInput);
    PlayerInputComponent->BindAxis("TurnAround", this, &ASBaseCharacter::AddControllerYawInput);

    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ASBaseCharacter::Jump);
    PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &ASBaseCharacter::Crouching);
    PlayerInputComponent->BindAction("Run", IE_Pressed, this, &ASBaseCharacter::StartRunning);
    PlayerInputComponent->BindAction("Run", IE_Released, this, &ASBaseCharacter::StopRunning);
    PlayerInputComponent->BindAction("PickUp", IE_Pressed, this, &ASBaseCharacter::PickUp);
    PlayerInputComponent->BindAction("Launch", IE_Pressed, this, &ASBaseCharacter::Launch);
}

//////////////////////////////////////////////////////////////////////////
/// BEGIN Movement's functional
//////////////////////////////////////////////////////////////////////////

void ASBaseCharacter::SetMovementStatus(EMovementStatus EMS)
{
    if (EMS == MovementStatus) return;

    switch (EMS)
    {
        case EMovementStatus::EMS_Walk: GetCharacterMovement()->MaxWalkSpeed = SpeedWalking; break;
        case EMovementStatus::EMS_Run:
            if (MovementStatus == EMovementStatus::EMS_Crouch) Crouching();
            GetCharacterMovement()->MaxWalkSpeed = SpeedRunning;
            break;
        case EMovementStatus::EMS_Crouch: GetCharacterMovement()->MaxWalkSpeed = SpeedWalking; break;
        case EMovementStatus::EMS_MAX: break;
        default:;
    }

    MovementStatus = EMS;
}

void ASBaseCharacter::MoveForward(float Amount)
{
    if (Amount == 0) return;
    AddMovementInput(GetActorForwardVector(), Amount);
}

void ASBaseCharacter::MoveRight(float Amount)
{
    if (Amount == 0) return;
    AddMovementInput(GetActorRightVector(), Amount);
}

void ASBaseCharacter::StartRunning()
{
    if (MovementStatus == EMovementStatus::EMS_Run) return;
    SetMovementStatus(EMovementStatus::EMS_Run);
}

void ASBaseCharacter::StopRunning()
{
    if (MovementStatus != EMovementStatus::EMS_Run) return;
    SetMovementStatus(EMovementStatus::EMS_Walk);
}

void ASBaseCharacter::Crouching()
{
    if (MovementStatus == EMovementStatus::EMS_Crouch)
    {
        UE_LOG(LogTemp, Warning, TEXT("Chrouching"));
        SetMovementStatus(EMovementStatus::EMS_Walk);
        CrouchInterp(false);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("UnChrouching"));
        SetMovementStatus(EMovementStatus::EMS_Crouch);
        GetCharacterMovement()->MaxWalkSpeed = SpeedCrouching;
        CrouchInterp(true);
    }
}

void ASBaseCharacter::PickUp()
{

    PickUpInterp(isHoldingObject);
}

void ASBaseCharacter::Launch()
{
    LaunchInterp(isHoldingObject);
}
