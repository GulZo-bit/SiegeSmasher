// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AI/SplineMovementActor.h"
#include "../MainCharacter.h"
#include "AIDemon.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "DemonAIController.generated.h"

/**
 * 
 */
UCLASS()
class SIEGESMASHER_API ADemonAIController : public AAIController
{
	GENERATED_BODY()
public:
	ADemonAIController();
protected:
	virtual void OnPossess(APawn* InPawn) override;

	void TowerSeen();
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UBoxComponent* TowerFindZone;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Perception")
	UAIPerceptionComponent* AIPerception;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Perception")
	UAISenseConfig_Sight* SightConfig;*/

	UPROPERTY()
	APawn* ControlledPawn;
	UPROPERTY()
	UChildActorComponent* ChildActor;
	UPROPERTY()
	AActor* CubeStore;

	UPROPERTY()
	AAIDemon* Demon;

	/*UFUNCTION()
	void HandlePerceptionUpdate(const TArray<AActor*>& UpdatedActors);*/
private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;
};
