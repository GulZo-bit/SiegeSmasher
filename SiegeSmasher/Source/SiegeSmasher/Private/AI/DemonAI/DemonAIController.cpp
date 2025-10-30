// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/DemonAI/DemonAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "SiegeSmasher/Towers/TowerBase.h"

ADemonAIController::ADemonAIController()
{
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	SightConfig->SightRadius = 3000;
	SightConfig->LoseSightRadius = 3500;
	SightConfig->PeripheralVisionAngleDegrees = 90;
	SightConfig->SetMaxAge(30.0f);
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = false;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = false;

	AIPerception->ConfigureSense(*SightConfig);
	AIPerception->SetDominantSense(SightConfig->GetSenseImplementation());
	
}

void ADemonAIController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);
		//AIPerception->OnPerceptionUpdated.AddDynamic(this, &ADemonAIController::HandlePerceptionUpdate);
		
	}
	
}

void ADemonAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	ControlledPawn = GetPawn();
	Demon = Cast<AAIDemon>(ControlledPawn);

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

	AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &ADemonAIController::HandleTargetPerceptionUpdate);
	AIPerception->OnTargetPerceptionForgotten.AddDynamic(this, &ADemonAIController::HandleTargetPerceptionForgotten);
}

void ADemonAIController::DistanceToTower()
{
	FVector TowerLocStore;
	FVector EnemyLocStore = Demon->GetActorLocation();

	if (TowerStore != nullptr && IsValid(TowerStore))
	{
		TowerLocStore = TowerStore->GetActorLocation();
		float DistStore = (FMath::Sqrt(((TowerLocStore.X - EnemyLocStore.X) * (TowerLocStore.X - EnemyLocStore.X)) + ((TowerLocStore.Y - EnemyLocStore.Y) * (TowerLocStore.Y - EnemyLocStore.Y)) + ((TowerLocStore.Z - EnemyLocStore.Z) * (TowerLocStore.Z - EnemyLocStore.Z))));

		if (DistStore >= 0 && DistStore <= 325)
		{
			GetBlackboardComponent()->SetValueAsBool(TEXT("bInRange"), true);
			Demon->setbCanActorMove(false);
		}

		else
		{
			GetBlackboardComponent()->SetValueAsBool(TEXT("bInRange"), false);
			//Demon->setbCanActorMove(true);
		}
	}

	else
	{
		GetBlackboardComponent()->SetValueAsBool(TEXT("bInRange"), false);
		GetBlackboardComponent()->SetValueAsBool(TEXT("bTowerSeen"), false);
		TowerStore = nullptr;
		Demon->setbCanActorMove(true);
	}
	
}

void ADemonAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckDeath();

	if (GetBlackboardComponent()->GetValueAsBool(TEXT("bTowerSeen")) == true)
	{
		DistanceToTower();
	}
	
	if (GetBlackboardComponent()->GetValueAsBool(TEXT("bTowerSeen")) == true && GetBlackboardComponent()->GetValueAsBool(TEXT("bInRange")) == false)
	{
		GetBlackboardComponent()->SetValueAsVector(TEXT("TowerLocation"), TowerStore->GetActorLocation());
		Demon->setbCanActorMove(true);
	}

	
	
	GetBlackboardComponent()->SetValueAsObject(TEXT("SplineMovementActor"), CubeStore);
	
}

void ADemonAIController::HandleTargetPerceptionUpdate(AActor* Actor, FAIStimulus Stim)
{
	
	if (Actor != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Red, FString::Printf(TEXT("Actor is not null")));

		if (Stim.WasSuccessfullySensed())
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Red, FString::Printf(TEXT("Seen Tower")));
			GetBlackboardComponent()->SetValueAsBool(TEXT("bTowerSeen"), true);

			if (TowerStore == nullptr)
			{
				TowerStore = Actor;
			}
			
			//Demon->setbCanActorMove(false);
		}

	}

}

void ADemonAIController::HandleTargetPerceptionForgotten(AActor* Actor)
{
	
	GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Red, FString::Printf(TEXT("Forgotten Tower")));
	GetBlackboardComponent()->SetValueAsBool(TEXT("bTowerSeen"), false);
	GetBlackboardComponent()->SetValueAsBool(TEXT("bInRange"), false);
	TowerStore = nullptr;
	Demon->setbCanActorMove(true);
	
}

void ADemonAIController::CheckDeath()
{
	if (Demon->GetHealth() <= 0)
	{
		GetBlackboardComponent()->SetValueAsBool(TEXT("bIsDead"), true);
	}

	else
	{
		GetBlackboardComponent()->SetValueAsBool(TEXT("bIsDead"), false);
	}
}


