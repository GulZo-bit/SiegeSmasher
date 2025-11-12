// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/WitchAI/WitchAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "BrainComponent.h"
#include "TimerManager.h"

void AWitchAIController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);

		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMainCharacterTest::StaticClass(), PlayerActorArray);
	}
}

void AWitchAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	ControlledPawn = GetPawn();
	Witch = Cast<AAIWitch>(ControlledPawn);

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

	GetWorldTimerManager().SetTimer(Timer, this, &AWitchAIController::setHealBool, 12.0f, true, 10.0f);
}

void AWitchAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Always checking death because if the enemy dies we need to stop their AI behaviour
	CheckDeath();
	CheckDistanceAndDirectionToPlayer();

	//Switch for checking line of sight to each player.
	switch (PlayerActorArray.Num())
	{
	case(1):
		if (LineOfSightTo(PlayerActorArray[0]) && (DistStoreArray[0] >= 0 && DistStoreArray[0] <= MaxEyeRange && DotProductArray[0] >= 0))
		{
			SetFocus(PlayerActorArray[0]);
			if (Witch != nullptr && Witch->getSpell() != nullptr)
			{
				
				//Sets the index for the fireball to attack the player that is being focused on.
				Witch->getSpell()->setPlayerIndex(0);
				
			}

			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerSeen"), true);
			Witch->setbCanActorMove(false);
		}

		else
		{
			ClearFocus(EAIFocusPriority::Gameplay);
			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerSeen"), false);
			GetBlackboardComponent()->SetValueAsObject(TEXT("SplineMovementActor"), CubeStore);
			Witch->setbCanActorMove(true);
		}
		break;

	case(2):
		if (LineOfSightTo(PlayerActorArray[0]) && (DistStoreArray[0] >= 0 && DistStoreArray[0] <= MaxEyeRange && DotProductArray[0] >= 0))
		{
			SetFocus(PlayerActorArray[0]);

			if (Witch != nullptr && Witch->getSpell() != nullptr)
			{
				Witch->getSpell()->setPlayerIndex(0);
			}

			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerSeen"), true);
			Witch->setbCanActorMove(false);
		}

		else if (LineOfSightTo(PlayerActorArray[1]) && (DistStoreArray[1] >= 0 && DistStoreArray[1] <= MaxEyeRange && DotProductArray[1] >= 0))
		{
			SetFocus(PlayerActorArray[1]);
			if (Witch != nullptr && Witch->getSpell() != nullptr)
			{
				Witch->getSpell()->setPlayerIndex(1);
			}

			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerSeen"), true);
			Witch->setbCanActorMove(false);
		}

		else
		{
			ClearFocus(EAIFocusPriority::Gameplay);
			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerSeen"), false);
			GetBlackboardComponent()->SetValueAsObject(TEXT("SplineMovementActor"), CubeStore);
			Witch->setbCanActorMove(true);
		}
		break;

	case(3):
		if (LineOfSightTo(PlayerActorArray[0]) && (DistStoreArray[0] >= 0 && DistStoreArray[0] <= MaxEyeRange && DotProductArray[0] >= 0))
		{
			SetFocus(PlayerActorArray[0]);

			if (Witch != nullptr && Witch->getSpell() != nullptr)
			{
				Witch->getSpell()->setPlayerIndex(0);
			}

			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerSeen"), true);
			Witch->setbCanActorMove(false);
		}

		else if (LineOfSightTo(PlayerActorArray[1]) && (DistStoreArray[1] >= 0 && DistStoreArray[1] <= MaxEyeRange && DotProductArray[1] >= 0))
		{
			SetFocus(PlayerActorArray[1]);
			if (Witch != nullptr && Witch->getSpell() != nullptr)
			{
				Witch->getSpell()->setPlayerIndex(1);
			}

			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerSeen"), true);
			Witch->setbCanActorMove(false);
		}

		else if (LineOfSightTo(PlayerActorArray[2]) && (DistStoreArray[2] >= 0 && DistStoreArray[2] <= MaxEyeRange && DotProductArray[2] >= 0))
		{
			SetFocus(PlayerActorArray[2]);
			if (Witch != nullptr && Witch->getSpell() != nullptr)
			{
				Witch->getSpell()->setPlayerIndex(2);
			}

			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerSeen"), true);
			Witch->setbCanActorMove(false);
		}

		else
		{
			ClearFocus(EAIFocusPriority::Gameplay);
			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerSeen"), false);
			GetBlackboardComponent()->SetValueAsObject(TEXT("SplineMovementActor"), CubeStore);
			Witch->setbCanActorMove(true);
		}
		break;
		
	case(4):
		if (LineOfSightTo(PlayerActorArray[0]) && (DistStoreArray[0] >= 0 && DistStoreArray[0] <= MaxEyeRange && DotProductArray[0] >= 0))
		{
			SetFocus(PlayerActorArray[0]);

			if (Witch != nullptr && Witch->getSpell() != nullptr)
			{
				Witch->getSpell()->setPlayerIndex(0);
			}

			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerSeen"), true);
			Witch->setbCanActorMove(false);
		}

		else if (LineOfSightTo(PlayerActorArray[1]) && (DistStoreArray[1] >= 0 && DistStoreArray[1] <= MaxEyeRange && DotProductArray[1] >= 0))
		{
			SetFocus(PlayerActorArray[1]);
			if (Witch != nullptr && Witch->getSpell() != nullptr)
			{
				Witch->getSpell()->setPlayerIndex(1);
			}

			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerSeen"), true);
			Witch->setbCanActorMove(false);
		}

		else if (LineOfSightTo(PlayerActorArray[2]) && (DistStoreArray[2] >= 0 && DistStoreArray[2] <= MaxEyeRange && DotProductArray[2] >= 0))
		{
			SetFocus(PlayerActorArray[2]);
			if (Witch != nullptr && Witch->getSpell() != nullptr)
			{
				Witch->getSpell()->setPlayerIndex(2);
			}

			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerSeen"), true);
			Witch->setbCanActorMove(false);
		}

		else if (LineOfSightTo(PlayerActorArray[3]) && (DistStoreArray[3] >= 0 && DistStoreArray[3] <= MaxEyeRange && DotProductArray[3] >= 0))
		{
			SetFocus(PlayerActorArray[3]);
			if (Witch != nullptr && Witch->getSpell() != nullptr)
			{
				Witch->getSpell()->setPlayerIndex(3);
			}

			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerSeen"), true);
			Witch->setbCanActorMove(false);
		}

		else
		{
			ClearFocus(EAIFocusPriority::Gameplay);
			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerSeen"), false);
			GetBlackboardComponent()->SetValueAsObject(TEXT("SplineMovementActor"), CubeStore);
			Witch->setbCanActorMove(true);
		}
		break;

	}

}

void AWitchAIController::setHealBool()
{
	GetBlackboardComponent()->SetValueAsBool(TEXT("bCanHeal"), true);
}

void AWitchAIController::CheckDeath()
{
	//If the enemy dies we need to play their death animation and disable their behaviour tree.
	if (Witch->GetHealth() <= 0)
	{
		GetBlackboardComponent()->SetValueAsBool(TEXT("bIsDead"), true);

		if (Witch->getDeathAnimFinsihed() == true)
		{
			UBrainComponent* BrainComp = this->GetBrainComponent();
			if (BrainComp != nullptr)
			{
				BrainComp->StopLogic(TEXT("Stopped by user action"));
			}
		}
	}

	//Once they get respawned we need to re-enable their behaviour tree
	else if(Witch->getHasBeenReset() == true)
	{
		RunBehaviorTree(AIBehavior);
		GetBlackboardComponent()->SetValueAsBool(TEXT("bIsDead"), false);
		Witch->setHasBeenReset(false);
	}
}

void AWitchAIController::CheckDistanceAndDirectionToPlayer()
{
	FVector PlayerLocStore;
	FVector PawnForwardVector = ControlledPawn->GetActorForwardVector();
	FVector EnemyLocStore = ControlledPawn->GetActorLocation();

	//Checking the distance and direction between this enemy and each player.
	for (int i = 0; i < PlayerActorArray.Num(); i++)
	{
		PlayerLocStore = PlayerActorArray[i]->GetActorLocation();
		DistStoreArray[i] = (FMath::Sqrt(((PlayerLocStore.X - EnemyLocStore.X) * (PlayerLocStore.X - EnemyLocStore.X)) + ((PlayerLocStore.Y - EnemyLocStore.Y) * (PlayerLocStore.Y - EnemyLocStore.Y)) + ((PlayerLocStore.Z - EnemyLocStore.Z) * (PlayerLocStore.Z - EnemyLocStore.Z))));

		DotProductArray[i] = FVector::DotProduct(PawnForwardVector, (PlayerLocStore - EnemyLocStore).GetSafeNormal());

	}
}


