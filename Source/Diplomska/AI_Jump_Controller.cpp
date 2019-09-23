// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Jump_Controller.h"
#include "AI_Jump_Character.h"
#include "AI_Jump_Point.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Behaviortree/Blackboard/BlackboardKeyAllTypes.h"
#include "Kismet/GameplayStatics.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

AAI_Jump_Controller::AAI_Jump_Controller()
{

	/*Initialize Blackboard and Behavior Tree*/
	BehaviorTree = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Behavior Component"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard Component"));

	/*Initialize Blackboard Keys*/
	PlayerKey = "Target";
	LocationToGoKey = "LocationToGo";

	/*Initialize perception*/
	PerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComp"));
	SightConfing = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));

	if (PerceptionComp && SightConfing)
	{
		PerceptionComp->ConfigureSense(*SightConfing);
		PerceptionComp->SetDominantSense(SightConfing->GetSenseImplementation());

		SightConfing->SightRadius = 2000.0f;
		SightConfing->LoseSightRadius = 2200.0f;
		SightConfing->PeripheralVisionAngleDegrees = 90.0;

		SightConfing->DetectionByAffiliation.bDetectEnemies = true;
		SightConfing->DetectionByAffiliation.bDetectFriendlies = true;
		SightConfing->DetectionByAffiliation.bDetectNeutrals = true;

		GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &AAI_Jump_Controller::OnPawnDetected);

	}

	CurrentJumpPoint = 0;
}

void AAI_Jump_Controller::BeginPlay()
{
	Super::BeginPlay();
}

FRotator AAI_Jump_Controller::GetControlRotation() const
{
	if (GetPawn() == nullptr)
	{
		return FRotator(0.0f, 0.0f, 0.0f);
	}
	return FRotator(0.0f, GetPawn()->GetActorRotation().Yaw, 0.0f);
}

void AAI_Jump_Controller::OnObsticleDetected(TArray<AActor*> DetectedObsticles)
{
	/*
		Logika za presmetka i ovozmozuvanje na skok
		- Start position - pocetna pozicija
		- End position - krajna destinacija
		- Apex position - pozicija na najvisoka tocka vo skokot
		- Dali e uspeshen skokot - dali so variabla
	*/
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