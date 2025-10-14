// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EnemyBTAISplineController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"


void AEnemyBTAISplineController::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Green, FString::Printf(TEXT("Begin play called")));
	if (AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);
		PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

		AIController = this;
		ControlledPawn = AIController->GetPawn();

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

	CheckDistanceToPlayer();
}

void AEnemyBTAISplineController::CheckPlayerDirection()
{

}

void AEnemyBTAISplineController::CheckDistanceToPlayer()
{
	FVector PlayerLocStore;
	FVector EnemyLocStore;
	float DistStore;
	PlayerLocStore = PlayerPawn->GetActorLocation();
	EnemyLocStore = ControlledPawn->GetActorLocation();
	DistStore = FMath::Sqrt(((PlayerLocStore.X - EnemyLocStore.X) * (PlayerLocStore.X - EnemyLocStore.X)) + ((PlayerLocStore.Y - EnemyLocStore.Y) * (PlayerLocStore.Y - EnemyLocStore.Y)) + ((PlayerLocStore.Z - EnemyLocStore.Z) * (PlayerLocStore.Z - EnemyLocStore.Z)));

	if (DistStore >= 0 && DistStore <= 200)
	{
		GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerNear"), true);
		SetFocus(PlayerPawn);
	}

	else
	{
		GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerNear"), false);
		ClearFocus(EAIFocusPriority::Gameplay);
	}
}
