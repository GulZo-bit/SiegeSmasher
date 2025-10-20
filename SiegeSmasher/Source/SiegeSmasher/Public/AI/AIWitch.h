// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AI/SplineController.h"
#include "../Enemies/EnemyBase.h"
#include "WitchAI/Witch_Projectile.h"
#include "AIWitch.generated.h"

UCLASS()
class SIEGESMASHER_API AAIWitch : public AEnemyBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAIWitch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FName Tag = FName(TEXT("SplineMovementActor")); //Tag used to find the correct child actor.
	UPROPERTY()
	TArray<ASplineController*> SplineControllerStore; //Stores the multiple splines in the scene
	UPROPERTY()
	AActor* CubeStore; //Stores the cube of the enmey.
	int32 SplineNum; //Number that will be set randomly based on how many splines are in the scene.
	float StartTime;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void PlayAttack();
	UPROPERTY(EditDefaultsOnly);
	TSubclassOf<AWitch_Projectile> SpellClass;
	UPROPERTY()
	AWitch_Projectile* Spell;

};
