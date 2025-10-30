// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/WitchAI/WitchAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

void AWitchAIController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehavior != nullptr)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Green, FString::Printf(TEXT("Found Behaviour tree")));
		RunBehaviorTree(AIBehavior);

		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMainCharacter::StaticClass(), PlayerActorArray);
		//GetBlackboardComponent()->SetValueAsObject(TEXT("Player"), PlayerPawn);
		/*for (int i = 0; i < PlayerActorArray.Num(); i++)
		{
			if (PlayerActorArray[i] != nullptr)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Red, FString::Printf(TEXT("Player Found")));
			}
		}*/

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

	CheckDeath();

	//Switch for checking line of sight to each player.
	switch (PlayerActorArray.Num())
	{
	case(1):
		if (LineOfSightTo(PlayerActorArray[0]))
		{
			SetFocus(PlayerActorArray[0]);

			if (Witch != nullptr)
			{
				if (Witch->getSpell() != nullptr)
				{
					//Sets the index for the fireball to attack the player that is being focused on.
					Witch->getSpell()->setPlayerIndex(0);
				}
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
		if (LineOfSightTo(PlayerActorArray[0]))
		{
			SetFocus(PlayerActorArray[0]);

			if (Witch != nullptr)
			{
				if (Witch->getSpell() != nullptr)
				{
					Witch->getSpell()->setPlayerIndex(0);
				}
			}

			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerSeen"), true);
			Witch->setbCanActorMove(false);
		}

		else if (LineOfSightTo(PlayerActorArray[1]))
		{
			SetFocus(PlayerActorArray[1]);
			if (Witch != nullptr)
			{
				if (Witch->getSpell() != nullptr)
				{
					Witch->getSpell()->setPlayerIndex(1);
				}
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
		if (LineOfSightTo(PlayerActorArray[0]))
		{
			SetFocus(PlayerActorArray[0]);

			if (Witch != nullptr)
			{
				if (Witch->getSpell() != nullptr)
				{
					Witch->getSpell()->setPlayerIndex(0);
				}
			}

			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerSeen"), true);
			Witch->setbCanActorMove(false);
		}

		else if (LineOfSightTo(PlayerActorArray[1]))
		{
			SetFocus(PlayerActorArray[1]);
			if (Witch != nullptr)
			{
				if (Witch->getSpell() != nullptr)
				{
					Witch->getSpell()->setPlayerIndex(1);
				}
			}

			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerSeen"), true);
			Witch->setbCanActorMove(false);
		}

		else if (LineOfSightTo(PlayerActorArray[2]))
		{
			SetFocus(PlayerActorArray[2]);
			if (Witch != nullptr)
			{
				if (Witch->getSpell() != nullptr)
				{
					Witch->getSpell()->setPlayerIndex(2);
				}
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
		if (LineOfSightTo(PlayerActorArray[0]))
		{
			SetFocus(PlayerActorArray[0]);

			if (Witch != nullptr)
			{
				if (Witch->getSpell() != nullptr)
				{
					Witch->getSpell()->setPlayerIndex(0);
				}
			}

			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerSeen"), true);
			Witch->setbCanActorMove(false);
		}

		else if (LineOfSightTo(PlayerActorArray[1]))
		{
			SetFocus(PlayerActorArray[1]);
			if (Witch != nullptr)
			{
				if (Witch->getSpell() != nullptr)
				{
					Witch->getSpell()->setPlayerIndex(1);
				}
			}

			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerSeen"), true);
			Witch->setbCanActorMove(false);
		}

		else if (LineOfSightTo(PlayerActorArray[2]))
		{
			SetFocus(PlayerActorArray[2]);
			if (Witch != nullptr)
			{
				if (Witch->getSpell() != nullptr)
				{
					Witch->getSpell()->setPlayerIndex(2);
				}
			}

			GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerSeen"), true);
			Witch->setbCanActorMove(false);
		}

		else if (LineOfSightTo(PlayerActorArray[3]))
		{
			SetFocus(PlayerActorArray[3]);
			if (Witch != nullptr)
			{
				if (Witch->getSpell() != nullptr)
				{
					Witch->getSpell()->setPlayerIndex(3);
				}
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
	if (Witch->GetHealth() <= 0)
	{
		GetBlackboardComponent()->SetValueAsBool(TEXT("bIsDead"), true);
	}

	else
	{
		GetBlackboardComponent()->SetValueAsBool(TEXT("bIsDead"), false);
	}
}

