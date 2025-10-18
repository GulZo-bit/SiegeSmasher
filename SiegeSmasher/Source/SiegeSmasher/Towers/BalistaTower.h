// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h" 
#include "TowerBase.h"
#include "BalistaTower.generated.h"



UCLASS()
class SIEGESMASHER_API ABalistaTower : public ATowerBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABalistaTower();


	void HandleNewEnemy(AEnemyBase * Enemy);
	void TowerActive();  

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(editAnyWhere, BluePrintReadWrite, Category = "FOV Snapping");
	float FovSnappingThreshold = 0.5f; 
	UPROPERTY(editAnyWhere, BluePrintReadWrite, Category = "Rotation Speed");
	float RotationLerpSpeed = 0.3f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
