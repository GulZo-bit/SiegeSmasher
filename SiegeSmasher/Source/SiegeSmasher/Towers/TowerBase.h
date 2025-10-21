// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "../Enemies/EnemyBase.h" 
#include "Components/TimelineComponent.h"
#include "Math/MathFwd.h" 
#include "Math/Vector.h" 

#include "TowerBase.generated.h" 


  #define PlacingSurface ECC_GameTraceChannel1

 // !PlacingSurface


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
	void DisableTick();
	UFUNCTION(BlueprintCallable, Category = "PlacementCollisionResolution")
	FVector GetPlacementColliderHalfExtents();
	UFUNCTION(BlueprintCallable, Category = "PlacementCollisionResolution")
	void ResolvePlacement(FVector SurfaceHalfExtents, FVector SurfacePos, FVector PlacementPosition, FVector CamDir,FVector CamPos, FTransform surfaceTransform);
protected:
	// Called when the game starts or when spawned

	virtual void BeginPlay() override;
	bool CurrentyActive = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlacementCollider");
	UBoxComponent* BoxColliderForObjectPlacement;
	FOnTimelineEvent TowerEndAction; 
	bool RequiresReset = false; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerWaitTimeToReset");
	float MaxWaitTimeToReset;


	float WaitTimeToReset = 0.0f; 
    
	UFUNCTION()
	virtual void TowerTimeLineEnd();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerTriggerBox")
	UBoxComponent* TriggerRangeBox;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerTriggerBoxDim")
	FVector TriggerBoxDim;  

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerPlacementSize");
	float PlacementSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StartingFacingDirection") 
	FVector InitialFacingDirection = FVector(0.0f, 0.0f, 1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerSurfaceAlignmentVector"); 
	FVector AlignmentVector = FVector::ZeroVector; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerSurfaceAlignmentAxis");
	FVector AlignmentAxis = FVector::ZeroVector;



protected:
	
	
	bool NeedsNewTargets = true;
	virtual void OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void HandleNewEnemy(AEnemyBase* EnemyBase); 
	virtual void TowerReset();
	virtual void TowerSetUp();
	virtual void TowerActive(float& DeltaTime) ;
	virtual void CheckForEnemies();
	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};