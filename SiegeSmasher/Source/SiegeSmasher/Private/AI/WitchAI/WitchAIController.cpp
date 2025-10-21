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
		PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		GetBlackboardComponent()->SetValueAsObject(TEXT("Player"), PlayerPawn);
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

	if (ControlledPawn != nullptr)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Green, FString::Printf(TEXT("Found Controlled Pawn")));
		//GLog->Log("Controlled Pawn Found");
		ChildActor = ControlledPawn->FindComponentByClass<UChildActorComponent>();

		if (ChildActor != nullptr)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Green, FString::Printf(TEXT("Child Pawn Found")));

			CubeStore = ChildActor->GetChildActor();
		}
	}

	GetWorldTimerManager().SetTimer(Timer, this, &AWitchAIController::setHealBool, 5.0f, true, 1.0f);
	
}

void AWitchAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	if (LineOfSightTo(PlayerPawn))
	{
		SetFocus(PlayerPawn);
		GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerSeen"), true);
		GetBlackboardComponent()->SetValueAsBool(TEXT("bCanHeal"), false);
	}

	else
	{
		ClearFocus(EAIFocusPriority::Gameplay);
		GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerSeen"), false);
		GetBlackboardComponent()->SetValueAsObject(TEXT("SplineMovementActor"), CubeStore);
	}
	
}

void AWitchAIController::setHealBool()
{
	GetBlackboardComponent()->SetValueAsBool(TEXT("bCanHeal"), true);
}
