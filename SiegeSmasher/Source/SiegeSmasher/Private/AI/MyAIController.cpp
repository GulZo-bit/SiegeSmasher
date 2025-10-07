// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/MyAIController.h"
#include "Containers/Array.h" 
#include <Kismet/GameplayStatics.h>

void AMyAIController::BeginPlay()
{
	Super::BeginPlay();

	//Get the AAICharTest class as an Actor.
	AEnemy = UGameplayStatics::GetActorOfClass(GetWorld(), AAICharTest::StaticClass());
	AEnemyCast = Cast<AAICharTest>(AEnemy);//Cast the Actor reference to AAICharTest.

	//Go through each index in the checkpoint array to add the Actor Componenet of each checkpoint to a dynamic array called TriggerStore.
	for (int i = 0; i < AEnemyCast->getCheckpoints().Num(); i++)
	{
		TriggerStore.Add(AEnemyCast->getCheckpoints()[i]->FindComponentByClass<UCheckPointTrigger>());
	}
}

void AMyAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//if to make sure IndexStart doesn't go above the size of the array to crash the game.
	if (IndexStart >= AEnemyCast->getCheckpoints().Num())
	{
		IndexStart = AEnemyCast->getCheckpoints().Num() - 1;
	}

	//Need to do the same for the TriggerIndex which is in CheckPointTrigger.cpp
	if (TriggerStore[IndexStart]->getIndexTrigger() >= AEnemyCast->getCheckpoints().Num())
	{
		TriggerStore[IndexStart]->setIndexTrigger(AEnemyCast->getCheckpoints().Num() - 1);
	}
	/*GLog->Log(FString::Printf(TEXT("IndexStart: %d"), IndexStart));
	GLog->Log(FString::Printf(TEXT("TriggerIndex: %d"), TriggerStore[IndexStart]->getIndexTrigger()));*/

	//Moves the actor to a checkpoint which is dictated by the TriggerIndex.
	MoveToLocation(AEnemyCast->getCheckpoints()[TriggerStore[IndexStart]->getIndexTrigger()]->GetActorLocation());

	//Once the actor reaches a trigger the TriggerIndex gets incremented and bDone gets switched to true.
	if (TriggerStore[IndexStart]->getBDone() == true)
	{
		//Once the TriggerIndex changes we need to increment the IndexStart so that we can go through the TriggerStore Array.
		IndexStart += 1;

		if (IndexStart >= AEnemyCast->getCheckpoints().Num())
		{
			IndexStart = AEnemyCast->getCheckpoints().Num() - 1;
		}

		//We need to set the TriggerIndex value to the one stored in the previous CheckpointTrigger because every time the trigger changes. The TriggerIndex goes back to 0.
		TriggerStore[IndexStart]->setIndexTrigger(TriggerStore[IndexStart - 1]->getIndexTrigger());

		if (TriggerStore[IndexStart]->getIndexTrigger() >= AEnemyCast->getCheckpoints().Num())
		{
			TriggerStore[IndexStart]->setIndexTrigger(AEnemyCast->getCheckpoints().Num() - 1);
		}
	}

}