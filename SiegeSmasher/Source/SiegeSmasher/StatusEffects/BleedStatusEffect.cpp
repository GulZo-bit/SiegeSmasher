// Fill out your copyright notice in the Description page of Project Settings.


#include "BleedStatusEffect.h"
// Sets default values for this component's properties
UBleedStatusEffect::UBleedStatusEffect()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	StatusEffectId = EnemyStatusEffect::BLEED;




	// ...
}


// Called when the game starts
void UBleedStatusEffect::BeginPlay()
{
	Super::BeginPlay();
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("BLEED STATUS EFFECT BEGIN PLAY")));
	// ...
	
}


// Called every frame
void UBleedStatusEffect::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	if (EnemyRef->GetHealth() <= 0.0f) {


		EnemyRef->RemoveTowerStatusEffect(StatusEffectId);
		IncrementAssignedPlayerScore(EnemyRef->GetScoreIncOnKill());
		SetComponentTickEnabled(false);
		return;


	}
	EnemyRef->DamageEnemy((BaseDamage * DeltaTime) );

	


}

void UBleedStatusEffect::SetBaseDamage(float Damage)
{
	BaseDamage = Damage;

}

