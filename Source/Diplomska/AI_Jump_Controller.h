// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AI_Jump_Controller.generated.h"

/**
 * 
 */
UCLASS()
class DIPLOMSKA_API AAI_Jump_Controller : public AAIController
{
	GENERATED_BODY()

private:

	/* Blackboard Component */
	class UBlackboardComponent* BlackboardComp;

	/*Behavior Tree Component */
	class UBehaviorTreeComponent* BehaviorTree;

	/*Behavior Keys*/
	UPROPERTY(EditDefaultsOnly, Category = AI)
	FName LocationToGoKey;

	UPROPERTY(EditDefaultsOnly, Category = AI)
	FName PlayerKey;

	TArray<AActor*> JumpPoints;

	virtual void OnPossess(APawn* Pawn) override;

public:
	AAI_Jump_Controller();

	/* Getter functions */
	FORCEINLINE UBlackboardComponent* GetBlackboardComponent() const { return BlackboardComp; };
	FORCEINLINE TArray<AActor*> GetJumpPoints() const { return JumpPoints; };

	int32 CurrentJumpPoint = 0;

};
