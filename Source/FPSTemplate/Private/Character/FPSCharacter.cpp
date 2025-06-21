// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/FPSCharacter.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

AFPSCharacter::AFPSCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	const APlayerController* PC = GetController<APlayerController>();
	const ULocalPlayer* LP = PC->GetLocalPlayer();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);

	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(DefaultIMC, 0);
	UEnhancedInputComponent* InputComp = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	InputComp->BindAction(Input_Move, ETriggerEvent::Triggered, this, &AFPSCharacter::MoveInput);
	InputComp->BindAction(Input_MouseLook, ETriggerEvent::Triggered, this, &AFPSCharacter::LookInput);
	InputComp->BindAction(Input_Look, ETriggerEvent::Triggered, this, &AFPSCharacter::LookInput);

	InputComp->BindAction(Input_Jump, ETriggerEvent::Started, this, &ACharacter::Jump);
	InputComp->BindAction(Input_Jump, ETriggerEvent::Canceled, this, &ACharacter::StopJumping);
	InputComp->BindAction(Input_Jump, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
}

/** Input Functions **/
void AFPSCharacter::MoveInput(const FInputActionValue& InputValue)
{
	FVector2D Value = InputValue.Get<FVector2D>();
	TryMove(Value.X, Value.Y);
}

void AFPSCharacter::LookInput(const FInputActionValue& InputValue)
{
	FVector2D Value = InputValue.Get<FVector2D>();
	TryLook(Value.X, Value.Y);
}


void AFPSCharacter::TryMove(const float X, const float Y)
{
	AddMovementInput(GetActorRightVector(), X);
	AddMovementInput(GetActorForwardVector(), Y);
}

void AFPSCharacter::TryLook(const float X, const float Y)
{
	AddControllerYawInput(X);
	AddControllerPitchInput(Y);
}