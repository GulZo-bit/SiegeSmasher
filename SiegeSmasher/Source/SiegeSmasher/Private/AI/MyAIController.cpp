// Fill out your copyright notice in the Description page of Project Settings.

#include "Containers/Array.h" 
#include "AI/MyAIController.h"
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

	if (AActor::GetActorLocation().X >= CheckpointStore[IndexStart]->GetActorLocation().X + 50 || AActor::GetActorLocation().X <= CheckpointStore[IndexStart]->GetActorLocation().X - 50)
	{
		MoveToLocation(CheckpointStore[IndexStart]->GetActorLocation());
	}
	
	else
	{
		IndexStart += 1;
		if (IndexStart == CheckpointStore.Num())
		{
			IndexStart = CheckpointStore.Num() - 1;
		}
	}
}