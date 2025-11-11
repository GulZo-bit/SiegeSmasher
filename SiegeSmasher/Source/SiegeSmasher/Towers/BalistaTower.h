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




protected:
	// Called when the game starts or when spawned

	// static meshes for loo of the ballista tower 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BallistaMesh");
	UStaticMeshComponent* BallistaBase;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BallistaMesh");
	UStaticMeshComponent* BallistaTurret;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BallistaArrow");
	UStaticMeshComponent* BallistaArrow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BallistaRecoliTimeLine");
	UTimelineComponent * BallistaRecoliTimeline; 

	// override has line of sight method in projectile tower base 
	bool HasLineOfSite(FVector To);
	// implment the active state for the state machine in the tower base class
	void TowerActive(float& DeltaTime);
	// implment the dormant state for the state machine in the tower base class

	void TowerDormant(float& DeltaTime);
	virtual void BeginPlay() override;


	// used to unhide and hide the arrow to indicates the ballista is reloading to the player 
	// this is done on a multicast on the authoritative server object to ensure that the 
	// unhiding and hiding of this mesh is synced across the clients and the sever 
	UFUNCTION(NetMulticast,Reliable) 
	void Multicast_SetArrowHidden(bool HideBallistaArrow);
	void Multicast_SetArrowHidden_Implementation(bool HideBallistaArrow);


	void HideArrow(bool ShouldHideArrow);



public:	

private:
	FVector LOSRayFiringPoint;
	TArray<FVector> LineOfSightRays;
	TArray<FVector> ObstaclePointsForLos;
	void EstablishLineOfSightRays();
	float RayDirectionAngleInc = 20.0f;


};
