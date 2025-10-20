// Fill out your copyright notice in the Description page of Project Settings.


#include "WallSpikeTrapTower.h"

// Sets default values
AWallSpikeTrapTower::AWallSpikeTrapTower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	
	WallTrapHinge = CreateDefaultSubobject<UStaticMeshComponent>("WallTrapHinge");
	WallTrapHinge->SetupAttachment(RootComponent); 
	WallTrapSpikes = CreateDefaultSubobject<UStaticMeshComponent>("WallTrapSpikes");
	WallTrapSpikes->SetupAttachment(RootComponent);
	TowerTimeLine = CreateDefaultSubobject<UTimelineComponent>("TowerTimeLine");

	




}







void AWallSpikeTrapTower::TowerTimeLineEnd() {

}