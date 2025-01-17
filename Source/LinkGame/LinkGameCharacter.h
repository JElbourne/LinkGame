// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LinkGameCharacter.generated.h"

UCLASS(config=Game)
class ALinkGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ALinkGameCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkGame | Player")
	bool bIsMovementFrozen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkGame | Player")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkGame | Player")
	float MaxHealth;

private:

	bool bIsMovingForward = false;


public:
	UFUNCTION(BlueprintCallable, Category = "LinkGame | Player")
	bool IsFullHealth();

protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

};

