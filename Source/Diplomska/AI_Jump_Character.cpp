// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Jump_Character.h"

// Sets default values
AAI_Jump_Character::AAI_Jump_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AAI_Jump_Character::GetPerceptionLocRot_Implementation(FVector& OutLocation, FRotator& OutRotation) const
{
	OutLocation = GetActorLocation() + FVector(0.0f, 0.0f, 50.0f);
	OutRotation = GetActirRotation();
}

// Called when the game starts or when spawned
void AAI_Jump_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAI_Jump_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAI_Jump_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAI_Jump_Character::GetActorEyesViewPoint(FVector& Location, FRotator& Rotation) const
{
	GetPerceptionLocRot(Location, Rotation);
}

