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
		GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Green, FString::Printf(TEXT("Found Behaviour tree")));
		RunBehaviorTree(AIBehavior);
		PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMainCharacter::StaticClass(), PlayerActorArray);
		for (int i = 0; i < PlayerActorArray.Num(); i++)
		{
			if (PlayerActorArray[i] != nullptr)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Red, FString::Printf(TEXT("Player Found")));
			}
		}
	}
}

void AEnemyBTAISplineController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GetBlackboardComponent()->SetValueAsObject(TEXT("SplineMovementActor"), CubeStore);

	if (CheckDistanceToPlayer() >= 0 && CheckDistanceToPlayer() <= 200 && CheckPlayerDirection() >= 0)
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

void AEnemyBTAISplineController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	ControlledPawn = GetPawn();

	if (ControlledPawn != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Green, FString::Printf(TEXT("Found Controlled Pawn")));
		GLog->Log("Controlled Pawn Found");
		ChildActor = ControlledPawn->FindComponentByClass<UChildActorComponent>();

		if (ChildActor != nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Green, FString::Printf(TEXT("Child Pawn Found")));
			
			CubeStore = ChildActor->GetChildActor();
		}
	}
}

float AEnemyBTAISplineController::CheckPlayerDirection()
{
	FVector PawnForwardVector = ControlledPawn->GetActorForwardVector();
	FVector PawnCurrentLocation = ControlledPawn->GetActorLocation();
	FVector PlayerLocation = PlayerPawn->GetActorLocation();
	
	float DotProductResult = FVector::DotProduct(PawnForwardVector, (PlayerLocation - PawnCurrentLocation).GetSafeNormal());

	return DotProductResult;
}



float AEnemyBTAISplineController::CheckDistanceToPlayer()
{
	FVector PlayerLocStore;
	FVector EnemyLocStore;
	float DistStore;
	EnemyLocStore = ControlledPawn->GetActorLocation();
	
	//if (Loop < PlayerActorArray.Num())
	//{
		for (int i =0; i < PlayerActorArray.Num(); i++)
		{
			PlayerLocStore = PlayerActorArray[Loop]->GetActorLocation();
			DistStore = FMath::Sqrt(((PlayerLocStore.X - EnemyLocStore.X) * (PlayerLocStore.X - EnemyLocStore.X)) + ((PlayerLocStore.Y - EnemyLocStore.Y) * (PlayerLocStore.Y - EnemyLocStore.Y)) + ((PlayerLocStore.Z - EnemyLocStore.Z) * (PlayerLocStore.Z - EnemyLocStore.Z)));

		}
	//}
		return DistStore;
	/*else
	{
		Loop = 0;
		return DistStore;
	}*/
	
	
}
