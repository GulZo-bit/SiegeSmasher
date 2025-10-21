// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h" 
#include "TowerProjectileBase.h"
#include "BallistaTowerProjectile.generated.h"

UCLASS()
class SIEGESMASHER_API ABallistaTowerProjectile : public ATowerProjectileBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallistaTowerProjectile();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
