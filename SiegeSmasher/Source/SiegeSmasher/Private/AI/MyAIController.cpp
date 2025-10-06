// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/MyAIController.h"
#include "Containers/Array.h" 
#include <Kismet/GameplayStatics.h>

void AMyAIController::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACheckpointTest::StaticClass(), CheckpointStore);
	CheckpointStore.Sort();

}

void AMyAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	CheckpointTrigger = CheckpointStore[IndexStart]->FindComponentByClass<UCheckPointTrigger>();

	int32 IndexTemp = IndexStart + 1;
	if (IndexTemp == CheckpointStore.Num())
	{
		IndexTemp = CheckpointStore.Num() - 1;
	}
	CheckpointTrigger->setIndexTrigger(IndexTemp);

	if (CheckpointTrigger->getIndexTrigger() == CheckpointStore.Num())
	{
		CheckpointTrigger->setIndexTrigger(CheckpointStore.Num() - 1);
	}
	MoveToLocation(CheckpointStore[CheckpointTrigger->getIndexTrigger()]->GetActorLocation());
	IndexStart += 1;

	if (IndexStart == CheckpointStore.Num())
	{
		IndexStart = CheckpointStore.Num() - 1;
	}
}