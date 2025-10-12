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
		
		//Get the actors attached to the spline.
		TArray<AActor*> TempActorStore;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASplineMovementActor::StaticClass(), TempActorStore);

		for (int i = 0; i < TempActorStore.Num(); i++)
		{
			SplineMovementActorStore.Add(Cast<ASplineMovementActor>(TempActorStore[i]));
		}

		//Assign which spline to follow randomly to create variation.
		GetBlackboardComponent()->SetValueAsObject(TEXT("SplineMovementActor"), SplineMovementActorStore[FMath::RandRange(0, SplineMovementActorStore.Num() - 1)]);
	}
}

void AEnemyBTAISplineController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}
