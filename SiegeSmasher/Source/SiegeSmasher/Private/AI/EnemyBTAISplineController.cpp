// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EnemyBTAISplineController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"


void AEnemyBTAISplineController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);
		
		AIController = this;
		APawn* ControlledPawn = AIController->GetPawn();

		if (ControlledPawn != nullptr)
		{
			GLog->Log("Controlled Pawn Found");
			ChildActor = ControlledPawn->FindComponentByClass<UChildActorComponent>();

			if (ChildActor != nullptr)
			{
				GLog->Log("Child Pawn Found");
				CubeStore = ChildActor->GetChildActor();
				GetBlackboardComponent()->SetValueAsObject(TEXT("SplineMovementActor"), CubeStore);
			}
		}

	}
}

void AEnemyBTAISplineController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}
