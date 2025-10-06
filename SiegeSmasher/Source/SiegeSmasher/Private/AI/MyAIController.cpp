// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/MyAIController.h"
#include "Containers/Array.h" 
#include <Kismet/GameplayStatics.h>

void AMyAIController::BeginPlay()
{
	Super::BeginPlay();

	AEnemy = UGameplayStatics::GetActorOfClass(GetWorld(), AAICharTest::StaticClass());
	AEnemyCast = Cast<AAICharTest>(AEnemy);
	for (int i = 0; i < AEnemyCast->getCheckpoints().Num(); i++)
	{
		TriggerStore.Add(AEnemyCast->getCheckpoints()[i]->FindComponentByClass<UCheckPointTrigger>());
	}
}

void AMyAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (IndexStart >= AEnemyCast->getCheckpoints().Num())
	{
		IndexStart = AEnemyCast->getCheckpoints().Num() - 1;
	}

	if (TriggerStore[IndexStart]->getIndexTrigger() >= AEnemyCast->getCheckpoints().Num())
	{
		TriggerStore[IndexStart]->setIndexTrigger(AEnemyCast->getCheckpoints().Num() - 1);
	}
	/*GLog->Log(FString::Printf(TEXT("IndexStart: %d"), IndexStart));
	GLog->Log(FString::Printf(TEXT("TriggerIndex: %d"), TriggerStore[IndexStart]->getIndexTrigger()));*/
	MoveToLocation(AEnemyCast->getCheckpoints()[TriggerStore[IndexStart]->getIndexTrigger()]->GetActorLocation());

	if (TriggerStore[IndexStart]->getBDone() == true)
	{
		IndexStart += 1;

		if (IndexStart >= AEnemyCast->getCheckpoints().Num())
		{
			IndexStart = AEnemyCast->getCheckpoints().Num() - 1;
		}

		TriggerStore[IndexStart]->setIndexTrigger(TriggerStore[IndexStart - 1]->getIndexTrigger());

		if (TriggerStore[IndexStart]->getIndexTrigger() >= AEnemyCast->getCheckpoints().Num())
		{
			TriggerStore[IndexStart]->setIndexTrigger(AEnemyCast->getCheckpoints().Num() - 1);
		}
	}

}