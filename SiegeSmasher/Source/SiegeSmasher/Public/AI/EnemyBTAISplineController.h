// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SplineMovementActor.h"
#include "../MainCharacter.h"
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
	
	float CheckDistanceToPlayer();
	float CheckPlayerDirection();

	virtual void OnPossess(APawn* InPawn) override;
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	APawn* PlayerPawn;
	UPROPERTY()
	APawn* ControlledPawn;
	UPROPERTY()
	UChildActorComponent* ChildActor;
	UPROPERTY()
	AActor* CubeStore;

	UPROPERTY()
	TArray<AActor*> PlayerActorArray;
	
private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;

	int32 Loop = 0;
};
