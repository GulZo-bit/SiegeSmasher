// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CheckpointTest.h"
#include "CheckPointTrigger.h"
#include "AICharTest.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class SIEGESMASHER_API AMyAIController : public AAIController
{
	GENERATED_BODY()
public:
	
protected:
	virtual void BeginPlay() override;

	int32 IndexStart = 0;
	UCheckPointTrigger* CheckpointTrigger;
	AActor* AEnemy;
	AAICharTest* AEnemyCast;
	TArray<UCheckPointTrigger*> TriggerStore;
public:
	virtual void Tick(float DeltaSeconds) override;
};
