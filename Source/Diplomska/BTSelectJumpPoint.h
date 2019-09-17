// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTSelectJumpPoint.generated.h"

/**
 * 
 */
UCLASS()
class DIPLOMSKA_API UBTSelectJumpPoint : public UBTTaskNode
{
	GENERATED_BODY()

private:

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};
