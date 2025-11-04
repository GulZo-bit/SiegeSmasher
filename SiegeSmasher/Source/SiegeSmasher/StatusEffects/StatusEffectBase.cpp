// Fill out your copyright notice in the Description page of Project Settings.


#include "StatusEffectBase.h"

// Sets default values for this component's properties
UStatusEffectBase::UStatusEffectBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	

	// ...
}


// Called when the game starts
void UStatusEffectBase::BeginPlay()
{
	Super::BeginPlay();
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Status effect base begin play called")));
	// ...
	SetComponentTickEnabled(false);
}



// Called every frame
void UStatusEffectBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	CurrentDuration -= DeltaTime;
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f,FColor::Red,FString::Printf(TEXT("Bleed status effect duration %f"), CurrentDuration));
	if (CurrentDuration <= 0.0f) {
		SetComponentTickEnabled(false); 

		EnemyRef->RemoveStatusEffect(StatusEffectId);


	}
	




    
	 
}

void UStatusEffectBase::IncreaseDuration(float Increment)
{
	CurrentDuration += Increment;
	//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Magenta, FString::Printf(TEXT("Status effect duration increased to %f by %f"), CurrentDuration, Increment));

}

void UStatusEffectBase::SetCurrentDuration(float Duration)
{
	CurrentDuration = Duration;

}

void UStatusEffectBase::SetEnemyRef(AEnemyBase* Enemy)
{
	EnemyRef = Enemy;
}

