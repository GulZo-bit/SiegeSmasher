// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SplineMovementActor.h"
#include "../MainCharacter.h"
#include "AICharTest.h"
#include "EnemyBTAISplineController.generated.h"

/**
 * 
 */
UCLASS()
class SIEGESMASHER_API AEnemyBTAISplineController : public AAIController
{
	GENERATED_BODY()
public:
protected:
	
	void CheckDistanceAndDirectionToPlayer(); //Responsible for checking how far the players are from the enemy and if the enemy is facing them.

	virtual void OnPossess(APawn* InPawn) override;
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	APawn* ControlledPawn;
	UPROPERTY()
	UChildActorComponent* ChildActor;
	UPROPERTY()
	AActor* CubeStore;

	UPROPERTY()
	TArray<AActor*> PlayerActorArray;

	float DistStoreArray[4];
	float DotProductArray[4];

	UPROPERTY()
	AAICharTest* Vampire;

	void CheckDeath();
private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;

	int32 Loop = 0;
};
