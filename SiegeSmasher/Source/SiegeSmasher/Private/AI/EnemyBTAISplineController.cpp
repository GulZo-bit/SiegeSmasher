// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EnemyBTAISplineController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BrainComponent.h"
#include "Kismet/GameplayStatics.h"


void AEnemyBTAISplineController::BeginPlay()
{
	Super::BeginPlay();
	if (AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);

		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMainCharacterTest::StaticClass(), PlayerActorArray);
	}
}

void AEnemyBTAISplineController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Always checking death because if the enemy dies we need to stop their AI behaviour
	CheckDeath();

	//Their default is to move to the the spline movement actor which is moving along the spline.
	GetBlackboardComponent()->SetValueAsObject(TEXT("SplineMovementActor"), CubeStore);

	CheckDistanceAndDirectionToPlayer();
	
}

void AEnemyBTAISplineController::CheckDeath()
{
	//If the enemy dies we need to play their death animation and disable their behaviour tree.
	if (Vampire->GetHealth() <= 0)
	{
		GetBlackboardComponent()->SetValueAsBool(TEXT("bIsDead"), true);
		if (Vampire->getDeathAnimFinsihed() == true)
		{
			UBrainComponent* BrainComp = this->GetBrainComponent();
			if (BrainComp != nullptr)
			{
				BrainComp->StopLogic(TEXT("Stopped by user action"));
			}
		}
	}

	//Once they get respawned we need to re-enable their behaviour tree
	else if(Vampire->getHasBeenReset() == true)
	{
		RunBehaviorTree(AIBehavior);
		GetBlackboardComponent()->SetValueAsBool(TEXT("bIsDead"), false);
		Vampire->setHasBeenReset(false);
	}
}

void AEnemyBTAISplineController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	ControlledPawn = GetPawn();
	Vampire = Cast<AAICharTest>(ControlledPawn);

	if (ControlledPawn != nullptr)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Green, FString::Printf(TEXT("Found Controlled Pawn")));
		//GLog->Log("Controlled Pawn Found");
		//ChildActor = ControlledPawn->FindComponentByClass<UChildActorComponent>();
		ChildActor = ControlledPawn->FindComponentByTag<UChildActorComponent>(FName("SplineMovementActor"));

		if (ChildActor != nullptr)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Green, FString::Printf(TEXT("Child Pawn Found")));
			
			CubeStore = ChildActor->GetChildActor();
		}
	}
}



void AEnemyBTAISplineController::CheckDistanceAndDirectionToPlayer()
{
	FVector PlayerLocStore;
	FVector PawnForwardVector = ControlledPawn->GetActorForwardVector();
	FVector EnemyLocStore = ControlledPawn->GetActorLocation();
	
	//Checking the distance and direction between this enemy and each player.
	for (int i =0 ; i < PlayerActorArray.Num(); i++)
	{
		PlayerLocStore = PlayerActorArray[i]->GetActorLocation();
		DistStoreArray[i] = (FMath::Sqrt(((PlayerLocStore.X - EnemyLocStore.X) * (PlayerLocStore.X - EnemyLocStore.X)) + ((PlayerLocStore.Y - EnemyLocStore.Y) * (PlayerLocStore.Y - EnemyLocStore.Y)) + ((PlayerLocStore.Z - EnemyLocStore.Z) * (PlayerLocStore.Z - EnemyLocStore.Z))));
		
		DotProductArray[i] = FVector::DotProduct(PawnForwardVector, (PlayerLocStore - EnemyLocStore).GetSafeNormal());
		
	}

	//Chooses the correct if statement based on how many players are playing the game.
	//If a player is close the attack animation plays.
	switch (PlayerActorArray.Num())
	{
	case(1):
		if (DistStoreArray[0] >= 0 && DistStoreArray[0] <= 200 && DotProductArray[0] >= 0)
		{
			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerNear"), true);
			Vampire->setbCanActorMove(false);
		}

		else
		{
			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerNear"), false);
			Vampire->setbCanActorMove(true);
		}
		break;
	case(2):
		if (DistStoreArray[0] >= 0 && DistStoreArray[0] <= 200 && DotProductArray[0] >= 0 || DistStoreArray[1] >= 0 && DistStoreArray[1] <= 200 && DotProductArray[1] >= 0)
		{
			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerNear"), true);
			Vampire->setbCanActorMove(false);
		}

		else
		{
			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerNear"), false);
			Vampire->setbCanActorMove(true);
		}
		break;
	case(3):
		if (DistStoreArray[0] >= 0 && DistStoreArray[0] <= 200 && DotProductArray[0] >= 0 || DistStoreArray[1] >= 0 && DistStoreArray[1] <= 200 && DotProductArray[1] >= 0
			|| DistStoreArray[2] >= 0 && DistStoreArray[2] <= 200 && DotProductArray[2] >= 0)
		{
			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerNear"), true);
			Vampire->setbCanActorMove(false);
		}

		else
		{
			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerNear"), false);
			Vampire->setbCanActorMove(true);
		}
		break;
	case(4):
		if (DistStoreArray[0] >= 0 && DistStoreArray[0] <= 200 && DotProductArray[0] >= 0 || DistStoreArray[1] >= 0 && DistStoreArray[1] <= 200 && DotProductArray[1] >= 0
			|| DistStoreArray[2] >= 0 && DistStoreArray[2] <= 200 && DotProductArray[2] >= 0 || DistStoreArray[3] >= 0 && DistStoreArray[3] <= 200 && DotProductArray[3] >= 0)
		{
			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerNear"), true);
			Vampire->setbCanActorMove(false);
		}

		else
		{
			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerNear"), false);
			Vampire->setbCanActorMove(true);
		}
		break;
	}
	

	
		
	
	
	
	
	
	
}
