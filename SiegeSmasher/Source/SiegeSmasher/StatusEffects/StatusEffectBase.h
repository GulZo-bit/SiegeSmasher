// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Enemies/EnemyBase.h"
#include "StatusEffectBase.generated.h"



class AMainCharacterTest;
// base class for tower status effects that can be applied to enemies 
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SIEGESMASHER_API UStatusEffectBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStatusEffectBase();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
    // properties for the status effect shared across all status effect child classes
	float CurrentDuration = 0.0f; 
	AEnemyBase* EnemyRef = nullptr;
	EnemyStatusEffect StatusEffectId;
	float CurrentDeltaTime = 0.0f; 
    AMainCharacterTest* PlayerRef= nullptr;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void IncreaseDuration(float Increment);
	void SetCurrentDuration(float Duration); 
	void SetEnemyRef(AEnemyBase* Enemy); 
	void SetPlayerRef(AMainCharacterTest* PlayerScorePtr);
	 
	void IncrementAssignedPlayerScore(int Increment,float EnemyHealth);

		
};
