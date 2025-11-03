// Fill out your copyright notice in the Description page of Project Settings.


#include "BallistaTowerProjectile.h"

// Sets default values
ABallistaTowerProjectile::ABallistaTowerProjectile()
{
	bReplicates = true; 
	SetReplicateMovement(true);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABallistaTowerProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABallistaTowerProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

