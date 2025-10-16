// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CheckPointTest.h"
#include "AI/SplineController.h"
#include "EnemyBTAISplineController.h"
#include "../Enemies/EnemyBase.h"
#include "AICharTest.generated.h"

class ASword;

UCLASS()
class SIEGESMASHER_API AAICharTest : public AEnemyBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAICharTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "Checkpoints")
	TArray<AActor*> CheckpointStore;
	float CheckDistanceToPlayer();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	TArray<AActor*> getCheckpoints();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASword> SwordClass;

	UPROPERTY()
	ASword* Sword;

	UPROPERTY()
	APawn* PlayerPawn;

	FName Tag = FName(TEXT("SplineMovementActor")); //Tag used to find the correct child actor.
	UPROPERTY()
	TArray<ASplineController*> SplineControllerStore; //Stores the multiple splines in the scene
	UPROPERTY()
	AActor* CubeStore; //Stores the cube of the enmey.
	int32 SplineNum; //Number that will be set randomly based on how many splines are in the scene.
	float StartTime;

};
