// Copyright Epic Games, Inc. All Rights Reserved.

#include "LinkGameCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

//////////////////////////////////////////////////////////////////////////
// ALinkGameCharacter

ALinkGameCharacter::ALinkGameCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	bIsMovingForward = false;

	Health = MaxHealth;

	
}

//////////////////////////////////////////////////////////////////////////
// Input

void ALinkGameCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ALinkGameCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ALinkGameCharacter::MoveRight);
}


bool ALinkGameCharacter::IsFullHealth()
{
	return Health == MaxHealth;
}

void ALinkGameCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f) && (!bIsMovementFrozen))
	{
		bIsMovingForward = true;
		FRotator Direction = (Value > 0.0f) ? FRotator(0.f, 0.f, 0.f) : FRotator(0.f, 180.f, 0.f);
		SetActorRotation(Direction);

		AddMovementInput(FVector(1.0f, 0.f,0.f), Value);
	}
	else {
		bIsMovingForward = false;
	}
}

void ALinkGameCharacter::MoveRight(float Value)
{
	if ( (Controller != nullptr) && (Value != 0.0f) && (!bIsMovementFrozen) && (!bIsMovingForward))
	{
		FRotator Direction = (Value > 0.0f) ? FRotator(0.f, 90.f, 0.f) : FRotator(0.f, 270.f, 0.f);
		SetActorRotation(Direction);

		AddMovementInput(FVector(0.f, 1.f, 0.f), Value);
	}
}
