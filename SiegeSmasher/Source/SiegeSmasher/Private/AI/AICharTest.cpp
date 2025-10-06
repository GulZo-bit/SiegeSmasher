// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AICharTest.h"

// Sets default values
AAICharTest::AAICharTest()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAICharTest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAICharTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAICharTest::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

TArray<AActor*> AAICharTest::getCheckpoints()
{
	return CheckpointStore;
}

