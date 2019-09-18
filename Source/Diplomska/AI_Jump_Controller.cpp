// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Jump_Controller.h"
#include "AI_Jump_Character.h"
#include "AI_Jump_Point.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Behaviortree/Blackboard/BlackboardKeyAllTypes.h"
#include "Kismet/GameplayStatics.h"

AAI_Jump_Controller::AAI_Jump_Controller()
{

	/*Initialize Blackboard and Behavior Tree*/
	BehaviorTree = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Behavior Component"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard Component"));

	/*Initialize Blackboard Keys*/
	PlayerKey = "Target";
	LocationToGoKey = "LocationToGo";

	CurrentJumpPoint = 0;
}

void AAI_Jump_Controller::OnPossess(APawn * Pawn)
{
	Super::OnPossess(Pawn);

	/*Get reference to the character*/
	AAI_Jump_Character* AI_Character = Cast<AAI_Jump_Character>(Pawn);

	if (AI_Character && AI_Character->BehaviorTree)
	{
		if (AI_Character->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*(AI_Character->BehaviorTree->BlackboardAsset));
		}

		/*Populate jump point array*/
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAI_Jump_Point::StaticClass(), JumpPoints);

		BehaviorTree->StartTree(*AI_Character->BehaviorTree);
	}
}