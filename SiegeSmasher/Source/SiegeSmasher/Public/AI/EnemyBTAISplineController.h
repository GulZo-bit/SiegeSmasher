// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SplineMovementActor.h"
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
	
	void CheckDistanceToPlayer();
	void CheckPlayerDirection();
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	APawn* PlayerPawn;
	APawn* ControlledPawn;
	ASplineMovementActor* SplineMovementActor;
	TArray<ASplineMovementActor*> SplineMovementActorStore;
	AAIController* AIController;
	UChildActorComponent* ChildActor;
	AActor* CubeStore;
private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;
};
