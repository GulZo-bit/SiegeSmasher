// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h" 
#include "TowerBase.h" 
#include "../TowerProjectiles/TowerProjectileBase.h" 
#include "Math/Box.h"
#include "ProjectileTowerBase.generated.h"

#ifndef TowerNoLOSChannel
 #define TowerNoLOSChannel ECC_GameTraceChannel8
#endif // !TowerNoLOSChannel
#ifndef EnemyObjectChannel
 #define EnemyObjectChannel ECC_GameTraceChannel3
#endif // !EnemyObjectChannel



UCLASS()
class SIEGESMASHER_API AProjectileTowerBase : public ATowerBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileTowerBase();
	float GetTargetingRangeSqr();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerRange");
	float TargetingRange = 0.0f;

	UPROPERTY(editAnyWhere, BluePrintReadWrite, Category = "FOV Snapping");
	float FovSnappingThreshold = 0.5f;
	UPROPERTY(editAnyWhere, BluePrintReadWrite, Category = "Rotation Speed");
	float RotationLerpSpeed = 0.3f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerProjectile");
	TSubclassOf<ATowerProjectileBase> Projectile;
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileAppearDuringReloadPercent", meta = (ClampMin = "0.1", ClampMax = "1.0"));
	float ProjectileReappearPercent = 1.0f;

	void OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	TMap<AActor*, FVector> DirectionsToRegainLos;
	TArray<AActor*> EnemiesToTrackForLOS;
	AActor* EnemySingleTarget = nullptr;
	TMap<AActor*, int> IndicesForEnemiesInRange; 
	TSet<FVector> DirectionsLOSWasLostAt;
	bool CurrentEnemyOutOfRange = true;  
	FBox TriggerBoxAABB;
	float HalfTriggerBoxDimLength = 0.0f; 
	int ProjectileTowerBatchCount = 5; 
	int ProjectileBacthIndex = 0;
	//AEnemyBase* EnemyToTrackForLOS = nullptr;
	UWorld* World = nullptr;
	FHitResult LOSResult;
	void HandleNewEnemy(AEnemyBase* Enemy);
	FActorSpawnParameters ProjectileSpawnParameters;
	void ShootProjectile(FVector Position, FRotator Rotation); 
	virtual bool HasLineOfSite(FVector To);  
	void TrackEnemies(FVector Location);
	bool NoTargetsInRange = true; 
	TArray<AEnemyBase*> CurrentEnemiesInRange;
	bool CanLoseLOS = false;
	int MaxEnemiesInRangeIndex = 0;
	virtual void SortedClosestEnemiesInRange();
	// Called every frame
	virtual void Tick(float DeltaTime) override; 

};
