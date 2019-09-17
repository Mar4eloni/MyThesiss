// Fill out your copyright notice in the Description page of Project Settings.


#include "BTSelectJumpPoint.h"
#include "AI_Jump_Point.h"
#include "AI_Jump_Controller.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UBTSelectJumpPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	AAI_Jump_Controller* AIController = Cast<AAI_Jump_Controller>(OwnerComp.GetAIOwner());

	if (AIController)
	{
		/*Get Blacboard Component*/
		UBlackboardComponent* BlacboardComp = AIController->GetBlackboardComponent();
		 
		AAI_Jump_Point* CurrentPoint = Cast<AAI_Jump_Point>(BlacboardComp->GetValueAsObject("LocationToGo"));

		TArray<AActor*> AvailableJumpPoints = AIController->GetJumpPoints();

		AAI_Jump_Point* NextJumpPoint = nullptr;

		if(AIController->CurrentJumpPoint != AvailableJumpPoints.Num() - 1)
		{
			NextJumpPoint = Cast<AAI_Jump_Point>(AvailableJumpPoints[++AIController->CurrentJumpPoint]);
		}
		else // if there are no more jump points go to start
		{
			NextJumpPoint = Cast<AAI_Jump_Point>(AvailableJumpPoints[0]);
			AIController->CurrentJumpPoint = 0;
		}

		BlacboardComp->SetValueAsObject("LocationToGo", NextJumpPoint);
		return EBTNodeResult::Succeeded;

	}
	
	return EBTNodeResult::Failed;

}