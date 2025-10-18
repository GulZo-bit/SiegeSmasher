// Fill out your copyright notice in the Description page of Project Settings.


#include "WallSpikeTrapTower.h"

// Sets default values
AWallSpikeTrapTower::AWallSpikeTrapTower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	WallTrapHinge = CreateDefaultSubobject<UStaticMeshComponent>("WallTrapHinge");
	WallTrapHinge->SetupAttachment(RootComponent); 

	WallTrapSpikes = CreateDefaultSubobject<UStaticMeshComponent>("WallTrapSpikes");
	WallTrapSpikes->SetupAttachment(RootComponent);




}

// Called when the game starts or when spawned
void AWallSpikeTrapTower::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWallSpikeTrapTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

