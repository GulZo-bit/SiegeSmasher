// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h" 
#include "TowerBase.h" 
#include "../TowerProjectiles/TowerProjectileBase.h"
#include "ProjectileTowerBase.generated.h"

UCLASS()
class SIEGESMASHER_API AProjectileTowerBase : public ATowerBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileTowerBase();

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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerFiringPoint");
	USceneComponent* TowerFiringPoint;
	void OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	AEnemyBase* EnemySingleTarget = nullptr;
	bool NoTargetsInRange = true; 
	UWorld* World = nullptr;
	void HandleNewEnemy(AEnemyBase* Enemy);
	FActorSpawnParameters ProjectileSpawnParameters;
	void ShootProjectile(FRotator rotation);
	// Called every frame
	virtual void Tick(float DeltaTime) override; 


};
