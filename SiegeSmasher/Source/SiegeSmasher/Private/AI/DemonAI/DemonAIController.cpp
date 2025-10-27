// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/DemonAI/DemonAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "SiegeSmasher/Towers/TowerBase.h"

ADemonAIController::ADemonAIController()
{
	/*AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	SightConfig->SightRadius = 3000;
	SightConfig->LoseSightRadius = 3500;
	SightConfig->PeripheralVisionAngleDegrees = 90;
	SightConfig->SetMaxAge(10.0f);
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = false;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = false;

	AIPerception->ConfigureSense(*SightConfig);
	AIPerception->SetDominantSense(SightConfig->GetSenseImplementation());*/
	
	
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

	TowerFindZone = Demon->FindComponentByClass<UBoxComponent>();
}

void ADemonAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CubeStore != nullptr)
	{
		GetBlackboardComponent()->SetValueAsObject(TEXT("SplineMovementActor"), CubeStore);
	}

	/*if (AIPerception != nullptr)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Red, FString::Printf(TEXT("Found Perception")));
	}*/
	
	//TowerSeen();
}

/*void ADemonAIController::HandlePerceptionUpdate(const TArray<AActor*>& UpdatedActors)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Red, FString::Printf(TEXT("Seen Tower")));
	for (AActor* Actor : UpdatedActors)
	{
		if (Actor)
		{
			UE_LOG(LogTemp, Warning, TEXT("Perception updated for actor: %s"), *Actor->GetName());
		}
	}
}*/

/*void ADemonAIController::TowerSeen()
{
	if (TowerFindZone != nullptr)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Green, FString::Printf(TEXT("Found Tower Find Zone")));
		TArray<AActor*> AllTowerStore;
		TowerFindZone->GetOverlappingActors(AllTowerStore);

		for (int i = 0; i < AllTowerStore.Num(); i++)
		{
			if (Cast<ATowerBase>(AllTowerStore[i]))
			{
				//GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Red, FString::Printf(TEXT("Found Tower")));
				ATowerBase* TempTowerStore = Cast<ATowerBase>(AllTowerStore[i]);
				GetBlackboardComponent()->SetValueAsBool(TEXT("bTowerSeen"), true);
				GetBlackboardComponent()->SetValueAsVector(TEXT("TowerLocation"), TempTowerStore->GetActorLocation());
			}

			else
			{
				GetBlackboardComponent()->SetValueAsBool(TEXT("bTowerSeen"), false);
			}
		}

	}
}*/

