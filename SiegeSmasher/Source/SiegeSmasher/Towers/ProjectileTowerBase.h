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



// this particualr class is here to make a disction between tower that shoot projectiles and those that do not 
// while still inheriting the interface that can be implmeneted for the state machine inside of the tower base class 
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

	// how aligned does the turret for the projecilte tower have to be to shoot the enemy it is targeting 
	UPROPERTY(editAnyWhere, BluePrintReadWrite, Category = "FOV Snapping");
	float FovSnappingThreshold = 0.5f;
	// how fast the tower rotates
	UPROPERTY(editAnyWhere, BluePrintReadWrite, Category = "Rotation Speed");
	float RotationLerpSpeed = 0.3f;
	// the projectile object to be spawned by the projectile tower when shooting 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerProjectile");
	TSubclassOf<ATowerProjectileBase> Projectile;
	
	// at what point should the projectile tower prep its projecilte during reload(before shooting)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileAppearDuringReloadPercent", meta = (ClampMin = "0.1", ClampMax = "1.0"));
	float ProjectileReappearPercent = 1.0f;

	// overriden overlap begin that will be bound to the trigger box in the base class
	void OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	// in this case we impment an on overlap end for when the enemy walks out of range of the projectile towers
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	// variables explained in cpp
	TMap<AActor*, FVector> DirectionsToRegainLos;
	TArray<AActor*> EnemiesToTrackForLOS;
	UPROPERTY(Replicated);
	AEnemyBase* EnemySingleTarget = nullptr;
	TMap<AActor*, int> IndicesForEnemiesInRange; 
	TSet<FVector> DirectionsLOSWasLostAt; 
	UPROPERTY(Replicated);
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
	UPROPERTY(Replicated);
	bool NoTargetsInRange = true; 
	TArray<AEnemyBase*> CurrentEnemiesInRange;
	bool CanLoseLOS = false;
	int MaxEnemiesInRangeIndex = 0;
	virtual void SortedClosestEnemiesInRange();
	// Called every frame
	virtual void Tick(float DeltaTime) override;   

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)const;


};
