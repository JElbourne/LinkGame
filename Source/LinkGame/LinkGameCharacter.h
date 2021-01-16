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
	bool bIsCameraMoving;

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

