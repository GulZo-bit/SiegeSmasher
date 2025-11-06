// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "../Enemies/EnemyBase.h" 
#include "Components/TimelineComponent.h" 
#include "Net/UnrealNetwork.h"
#include "Math/MathFwd.h" 
#include "Math/Vector.h" 
#include "GenericTeamAgentInterface.h"
#include "Perception/AIPerceptionSystem.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AISense_Sight.h"
#include "GenericTeamAgentInterface.h"
#include "Net/UnrealNetwork.h"
#include "TowerBase.generated.h" 


#ifndef PlacingSurface
 #define PlacingSurface ECC_GameTraceChannel1
#endif // !PlacingSurface

#ifndef TowerPlacementBox
 #define TowerPlacementBox ECC_GameTraceChannel9
#endif // !TowerPlacementBox
#ifndef EnemyObjects
 #define EnemyObjects ECC_GameTraceChannel3
#endif // !TowerPlacementBox






class AMainCharacterTest;
UCLASS()
class SIEGESMASHER_API ATowerBase : public AActor, public IGenericTeamAgentInterface
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	
	ATowerBase(); 
	void DisableTick();
	UFUNCTION(BlueprintCallable, Category = "PlacementCollisionResolution")
	FVector GetPlacementColliderHalfExtents();
	UFUNCTION(BlueprintCallable, Category = "PlacementCollisionResolution")
  	bool ResolvePlacement(FVector& SurfaceHalfExtents, FVector& SurfacePos, FVector& PlacementPosition, FVector& CamDir,FVector& CamPos, FTransform& surfaceTransform);

	//void SetPlayerRef(AMainCharacterTest* PlayerPtr);

	void IncrementAssignedPlayersScore(int increment);

	UBoxComponent* GetPlacmentBox();
protected:
	// Called when the game starts or when spawned

	virtual void BeginPlay() override;
	UPROPERTY(Replicated);
	bool CurrentyActive = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlacementCollider");
	UBoxComponent* BoxColliderForObjectPlacement;
	FOnTimelineEvent TowerEndAction;  
	FOnTimelineFloat TowerTimeLineInterpEvent; 
	bool RequiresReset = false; 
	bool StartedReset = false;
	
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerWaitTimeToReset");
	float MaxWaitTimeToReset;
	float WaitTimeToReset = 0.0f;
	
	UFUNCTION(NetMulticast,Reliable)
	void Multicast_PlayTowerTimeLine(float PlayBackSpeed);
	void Multicast_PlayTowerTimeLine_Implementation(float PlayBackSpeed);

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_ReverseTowerTimeLine(float PlayBackSpeed);
	void Multicast_ReverseTowerTimeLine_Implementation(float PlayBackSpeed); 

	UFUNCTION(NetMulticast,Reliable)
	void Multicast_SetTriggerBoxCollision(ECollisionEnabled::Type ColType); 
	void Multicast_SetTriggerBoxCollision_Implementation(ECollisionEnabled::Type ColType);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerHitBox");  
	UBoxComponent* TowerHitBox;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CoolDownAfterReset");
	float MaxCoolDownAfterReset = 0.0f; 

	float CoolDownAfterReset = 0.0f;
	
	UFUNCTION()
	virtual void TowerTimeLineEnd();
	virtual void TowerDormant(float& DeltaTime);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerTriggerBox")
	UBoxComponent* TriggerRangeBox;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerTriggerBoxDim")
	FVector TriggerBoxDim;  

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerTimeLine(CanBeUsedToAnimateTowers)");
	UTimelineComponent* TowerTimeLine;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerPlacementSize");
	float PlacementSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StartingFacingDirection");
	TArray<FVector> AllowedDirections;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerSurfaceAlignmentVector"); 
	FVector AlignmentVector = FVector::ZeroVector; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerSurfaceAlignmentAxis");
	FVector AlignmentAxis = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerTimeLineCurve"); 
	UCurveFloat* TowerTimeLineCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerDamage");
	float TowerDamage = 0.0f;
	
	UFUNCTION() 
	virtual void TowerTimeLineInterp(float value); 

	void SetHitBoxActive(bool HitBoxActive);
protected:

	
	//bool NeedsNewTargets = true; 
	UFUNCTION()
	virtual void OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION() 
	virtual void OnOverlapHitBox(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	virtual void OnHitBoxHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);


	virtual void HandleNewEnemy(AEnemyBase* EnemyBase); 
	virtual void TowerReset();
	virtual void TowerSetUp();
	virtual void TowerActive(float& DeltaTime) ;
	virtual void ApplyDamage(AEnemyBase* Enemy);

	FGenericTeamId TeamID;
	virtual FGenericTeamId GetGenericTeamId() const override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower Stats")
	float Health = 100.0f;
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerMainStatusEffect")
	EnemyStatusEffect TowerMainStatusEffect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerMainStatusEffect"); 
	float MainStatusEffectDuration = 0.0f; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerMainStatusEffect", meta = (ClampMin = "0.1", ClampMax = "1.0"));
	float MainStatusEffectIncreaseScalar = 0.0f;
	AMainCharacterTest* PlayerRef; 
	UFUNCTION(NetMulticast, Reliable) 
	void Multicast_SetTowerHitBoxCollisionResponse(ECollisionChannel Channel, ECollisionResponse CollisionResponse); 
	void Multicast_SetTowerHitBoxCollisionResponse_Implementation(ECollisionChannel Channel, ECollisionResponse CollisionResponse);
	UFUNCTION(NetMulticast,Reliable)
	void MultiCast_SetTowerHitBoxEnabled(ECollisionEnabled::Type CollisionEnabled); 
	void MultiCast_SetTowerHitBoxEnabled_Implementation(ECollisionEnabled::Type CollisionEnabled);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAIPerceptionStimuliSourceComponent* StimuliSourceComponent;
	void SetPlayerRef(AMainCharacterTest* PlayerPtr);
	void setHealth(float HealthStore);
	float getHealth();
private: 
	FVector FacingDirSum;
	

};