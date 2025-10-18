// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"  
#include "TowerBase.h" 
#include "Components/TimelineComponent.h"
#include "WallSpikeTrapTower.generated.h"

UCLASS()
class SIEGESMASHER_API AWallSpikeTrapTower : public ATowerBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWallSpikeTrapTower();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SwingingTimeLine");
	UTimelineComponent* SwingingTimeLine; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WallTrapMesh") 
	UStaticMeshComponent* WallTrapHinge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WallTrapMesh")
	UStaticMeshComponent* WallTrapSpikes;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
