// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "../Enemies/EnemyBase.h" 
#include "Math/MathFwd.h" 
#include "Math/Vector.h"
#include "TowerBase.generated.h"


// enum bit flags for chekcing if an enemy already has a status effect we can have each enum go up in a power of two as that will give 
// us a binary number of 32 bits where only one bit is positive allowing us to easily combine bit field flags using bitwise operators
// to check if an enemy already has a status effect applied to them(so we dont reapply status effects or add them when its not neccessary)
UENUM()
enum class TowerStatusEffect : int32
{
	PHYSCIALDOT = 1,
	SLOW = 2,

};

static inline  TowerStatusEffect operator |  (TowerStatusEffect  other, TowerStatusEffect other1) {

	return static_cast<TowerStatusEffect>(static_cast<int32>(other) | static_cast<int32>(other1));

}
static inline  int32 operator &  (TowerStatusEffect  other, TowerStatusEffect other1) {

	return (static_cast<int32>(other) & static_cast<int32>(other1));

}

UCLASS()
class SIEGESMASHER_API ATowerBase : public AActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	ATowerBase();
	UFUNCTION(BlueprintCallable, Category = "PlacementCollisionResolution")
	FVector GetPlacementColliderHalfExtents();
	UFUNCTION(BlueprintCallable, Category = "PlacementCollisionResolution")
	void ResolvePlacement(FVector SurfaceHalfExtents, FVector SurfacePos, FVector PlacementPosition, FVector CamDir,FVector CamPos, FTransform surfaceTransform);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool CurrentyActive = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MeshForTower");
	USkeletalMeshComponent * MeshForTower;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlacementCollider");
	UBoxComponent* BoxColliderForObjectPlacement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerTriggerBox")
	UBoxComponent* TriggerRangeBox;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerTriggerBoxDim")
	FVector TriggerBoxDim; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerProjectile(Optional)"); 
	AActor* Projectile;

protected:
	AEnemyBase* FirstTarget = nullptr; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActiveRange");
	float TargetingRange = 0.0f;
	bool ShouldGetTargets = true;
	virtual void OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void HandleNewEnemy(AEnemyBase* EnemyBase);
	virtual void TowerSetUp();
	virtual void TowerActive() ;
	virtual void CheckForEnemies();
	virtual void DamageEnemy(AEnemyBase* EnemyBase) ; 



public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};