// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h" 
#include "TowerBase.h"
#include "FloorSpikeTrapTower.generated.h"

UCLASS()
class SIEGESMASHER_API AFloorSpikeTrapTower : public ATowerBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloorSpikeTrapTower();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spikes"); 
	UStaticMeshComponent* SpikesMesh; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpikeTrapBase");
	UStaticMeshComponent* SpikeTrapBaseMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UpwardPlayBackSpeed");
	float UpwardPlayBackSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DownwardPlayBackSpeed");
	float DownWardPlayBackSpeed;

	void TowerSetUp();
	void TowerActive(float& DeltaTime);
	void TowerReset();
	void TowerTimeLineInterp(float value);
	void TowerTimeLineEnd();
	void TowerDormant(float& DeltaTime);
	void ApplyDamage(AEnemyBase* Enemy); 
	UPROPERTY(Replicated);
	bool SpikesUp = false;  
	float CurrentDeltaTime = 0.0f; 
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

	FVector SpikesStartPos;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
