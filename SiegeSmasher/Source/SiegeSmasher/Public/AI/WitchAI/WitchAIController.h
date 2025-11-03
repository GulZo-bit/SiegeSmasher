// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AI/SplineMovementActor.h"
#include "../MainCharacter.h"
#include "../AIWitch.h"
#include "WitchAIController.generated.h"

/**
 * 
 */
UCLASS()
class SIEGESMASHER_API AWitchAIController : public AAIController
{
	GENERATED_BODY()
public:

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY()
	APawn* ControlledPawn;
	UPROPERTY()
	UChildActorComponent* ChildActor;
	UPROPERTY()
	AActor* CubeStore;

	AAIWitch* Witch;

	UPROPERTY()
	TArray<AActor*> PlayerActorArray;
	FTimerHandle Timer;

public:
	virtual void Tick(float DeltaTime) override;

	void setHealBool();
	void CheckDeath();
private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;
};
