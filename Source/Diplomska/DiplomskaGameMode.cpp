// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "DiplomskaGameMode.h"
#include "DiplomskaCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADiplomskaGameMode::ADiplomskaGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
