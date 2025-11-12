// Fill out your copyright notice in the Description page of Project Settings.


#include "StatusEffectBase.h"
#include "../MyMainCharacterTest.h"
// Sets default values for this component's properties
UStatusEffectBase::UStatusEffectBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	

	
}


// Called when the game starts
void UStatusEffectBase::BeginPlay()
{
	Super::BeginPlay();
	
	SetComponentTickEnabled(false);

	
}



// Called every frame
void UStatusEffectBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction); 
	// decrement the current duration of the status effect
	CurrentDuration -= DeltaTime;
	if (CurrentDuration <= 0.0f) {
		/// if the duration for the status effect hit 0 
		SetComponentTickEnabled(false); 

		EnemyRef->RemoveTowerStatusEffect(StatusEffectId);


	}
	

	 
}

void UStatusEffectBase::IncreaseDuration(float Increment)
{
	CurrentDuration += Increment;

}

void UStatusEffectBase::SetCurrentDuration(float Duration)
{
	CurrentDuration = Duration;

}

void UStatusEffectBase::SetEnemyRef(AEnemyBase* Enemy)
{
	EnemyRef = Enemy;
}

void UStatusEffectBase::SetPlayerRef(AMainCharacterTest* PlayerScorePtr)
{
	PlayerRef = PlayerScorePtr;
}

void UStatusEffectBase::IncrementAssignedPlayerScore(int Increment,float EnemyHealth)
{
	// determine if the player should gain points based on hit or kill for the status effect child class calling this method 
	if (PlayerRef != nullptr ) {
		PlayerRef->IncrementPlayerScore(Increment); 
		PlayerRef->IncrementPlayerKills(1 * (EnemyHealth <= 0.0f));
	}



}

