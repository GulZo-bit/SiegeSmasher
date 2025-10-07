// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EnemyBTAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

void AEnemyBTAIController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);

		PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

		GetBlackboardComponent()->SetValueAsObject(TEXT("PlayerActor"), PlayerPawn);

		GetBlackboardComponent()->SetValueAsVector(TEXT("EnemyStartPositon"), GetPawn()->GetActorLocation());
	}
}

void AEnemyBTAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (LineOfSightTo(PlayerPawn))
	{
		GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerSeen"), true);
	}

	else
	{
		GetBlackboardComponent()->SetValueAsBool(TEXT("bIsPlayerSeen"), false);
	}
}
