// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CheckPointTest.h"
#include "AICharTest.generated.h"

UCLASS()
class SIEGESMASHER_API AAICharTest : public ACharacter
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
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	TArray<AActor*> getCheckpoints();
};
