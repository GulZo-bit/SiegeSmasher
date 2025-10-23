// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h" 
#include "ProjectileTowerBase.h" 

#include "BalistaTower.generated.h"





UCLASS()
class SIEGESMASHER_API ABalistaTower : public AProjectileTowerBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABalistaTower();


	void TowerActive(float& DeltaTime);  

protected:
	// Called when the game starts or when spawned

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BallistaMesh");
	UStaticMeshComponent* BallistaBase;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BallistaMesh");
	UStaticMeshComponent* BallistaTurret;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BallistaArrow");
	UStaticMeshComponent* BallistaArrow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BallistaRecoliTimeLine");
	UTimelineComponent * BallistaRecoliTimeline;

	

public:	

private: 



};
