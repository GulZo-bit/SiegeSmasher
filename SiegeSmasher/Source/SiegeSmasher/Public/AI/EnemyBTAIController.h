// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CheckpointTest.h"
#include "CheckPointTrigger.h"
#include "AICharTest.h"
#include "SiegeSmasher/MainCharacter.h"
#include "EnemyBTAIController.generated.h"

/**
 * 
 */
UCLASS()
class SIEGESMASHER_API AEnemyBTAIController : public AAIController
{
	GENERATED_BODY()
public:

protected:
	virtual void BeginPlay() override;
	void CheckDistanceToPlayer();
public:
	virtual void Tick(float DeltaTime) override;
	APawn* PlayerPawn;

	int32 IndexStart = 0;
	UCheckPointTrigger* CheckpointTrigger;
	AActor* AEnemy;
	AAICharTest* AEnemyCast;
	TArray<UCheckPointTrigger*> TriggerStore;

private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;
};
