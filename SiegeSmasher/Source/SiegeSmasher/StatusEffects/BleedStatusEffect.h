// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StatusEffectBase.h"
#include "BleedStatusEffect.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SIEGESMASHER_API UBleedStatusEffect : public UStatusEffectBase
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBleedStatusEffect();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void SetBaseDamage(float Damage);
private:
	float BaseDamage = 0.0f;
		
};
