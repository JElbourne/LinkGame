// Copyright Epic Games, Inc. All Rights Reserved.

#include "LinkGameGameMode.h"
#include "LinkGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALinkGameGameMode::ALinkGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
