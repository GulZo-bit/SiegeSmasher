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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WallTrapMesh") 
	UStaticMeshComponent* WallTrapHinge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WallTrapMesh")
	UStaticMeshComponent* WallTrapSpikes; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SwingAngle")
	float SwingRotationAngle = 90.0f;

	
	
	
protected:
	void TowerSetUp();
	void TowerActive(float& DeltaTime);
	void TowerTimeLineEnd();
	void TowerReset();
	void TowerDormant(float& DeltaTime);
	void HandleNewEnemy(AEnemyBase* Enemy);
	void TowerTimeLineInterp(float value);
	void ApplyDamage(AEnemyBase* Enemy);
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;
	UPROPERTY(Replicated);
	bool HasSwung = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SwingPlayBackSpeed"); 
	float SwingPlayBackSpeed = 0.0f;
	UPROPERTY(Replicated); 
	bool IsSwinging = false;  

protected:
	FVector EulerAnglesOfSpikesOnPlace;


public:	



private: 


};
