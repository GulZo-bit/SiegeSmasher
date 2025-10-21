// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"  
#include "TowerBase.h" 
#include "WallSpikeTrapTower.generated.h"

UCLASS()
class SIEGESMASHER_API AWallSpikeTrapTower : public ATowerBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWallSpikeTrapTower();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "");
	UTimelineComponent* TowerTimeLine;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WallTrapMesh") 
	UStaticMeshComponent* WallTrapHinge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WallTrapMesh")
	UStaticMeshComponent* WallTrapSpikes;
protected:

	void TowerTimeLineEnd();


	

public:	



private: 


	bool IsSwinging = false;

};
