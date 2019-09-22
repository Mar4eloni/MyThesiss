// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obsticle.generated.h"

UCLASS()
class DIPLOMSKA_API AObsticle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObsticle();

	UPROPERTY(BlueprintReadWrite, Category = "Obsticle")
	float ObsticleHight = 0.0f;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
