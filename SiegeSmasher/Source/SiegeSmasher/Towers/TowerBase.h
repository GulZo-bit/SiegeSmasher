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


// the tower base class is the main parent class for all of the towers that are seen in game 
// and it is used to create an interface that all the child classes can tap into and override based on what functionaility they need 
//to add. it acts as a state machine with states such as dormant active and resetting providing virtual functions to the child 
// tower classes that they can overide to add fucntionaility to the state machine 
// this makes it much quicker to create new towers with different functionaility and also reduces code duplication 
// across the board for the tower classes


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
	// used to increment the players score who is assigned to a specifc tower 
	// this refernce is created when the player creates and spawns a tower on the server  
	void IncrementAssignedPlayersScore(int increment);
	// get the box used to determine if the player has correctly fit the tower to the surface they are trying to place the tower on
	UBoxComponent* GetPlacmentBox();
protected:
	// Called when the game starts or when spawned

	virtual void BeginPlay() override;
	// determine if the tower is in the active state 
	UPROPERTY(Replicated);
	bool CurrentyActive = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlacementCollider");
	UBoxComponent* BoxColliderForObjectPlacement;

	// timline  call back events that can be bound to using the asscoiatied virtual methods in this class 
	//if the tower makes use of a timeline for animation 
	FOnTimelineEvent TowerEndAction;  
	FOnTimelineFloat TowerTimeLineInterpEvent; 

	// represent the reset state of the tower 
	bool RequiresReset = false; 
	bool StartedReset = false;
	
	//used to damage a player and update the associated players leaderboard info
	void DamageEnemyAndUpdatePlayerInfo(AEnemyBase* Enemy, float Damage);
	// timers for cooldown of tower 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerWaitTimeToReset");
	float MaxWaitTimeToReset;
	float WaitTimeToReset = 0.0f;
	
	// mutlicast method that is called on the server to play the timeline asscoiated with the towers action 
    // playing the time line for every client and the server
	UFUNCTION(NetMulticast,Reliable)
	void Multicast_PlayTowerTimeLine(float PlayBackSpeed);
	void Multicast_PlayTowerTimeLine_Implementation(float PlayBackSpeed);

	// opposite of above 
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_ReverseTowerTimeLine(float PlayBackSpeed);
	void Multicast_ReverseTowerTimeLine_Implementation(float PlayBackSpeed); 

	// used to disable and enable collision for towers across the network from the server 
	UFUNCTION(NetMulticast,Reliable)
	void Multicast_SetTriggerBoxCollision(ECollisionEnabled::Type ColType); 
	void Multicast_SetTriggerBoxCollision_Implementation(ECollisionEnabled::Type ColType);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerHitBox");  
	UBoxComponent* TowerHitBox;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CoolDownAfterReset");
	float MaxCoolDownAfterReset = 0.0f; 

	float CoolDownAfterReset = 0.0f;
	
	// virtual function associated with the end state for the timeline used for the towers action 
	// allowing the child class to ovveride this and manipluate any data they need once their timeline animation has finished 
	//(they have performed their action)
	UFUNCTION()
	virtual void TowerTimeLineEnd();
	
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


	// curve used to control the pace of the tower time line
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerTimeLineCurve"); 
	UCurveFloat* TowerTimeLineCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerDamage");
	float TowerDamage = 0.0f;
	
	// intepalation method that is bound to the tower time line that can be overriden to suite the child class needs 
	UFUNCTION() 
	virtual void TowerTimeLineInterp(float value); 

	void SetHitBoxActive(bool HitBoxActive);
protected:

	
	//bool NeedsNewTargets = true; 

	// overlap begin method for detecting objects entering the range of the tower 
	UFUNCTION()
	virtual void OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	// used to damage objects(primarily enemies) that are in the towers range  
	UFUNCTION() 
	virtual void OnOverlapHitBox(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	virtual void OnHitBoxHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);


	virtual void HandleNewEnemy(AEnemyBase* EnemyBase); 
	// represent  the towers inactive state
	virtual void TowerDormant(float& DeltaTime);
	// maniuplate the towers state when the reset timer is finished 
	virtual void TowerReset();
	// called in begin play of base class allowing child classes to set up any extra variables they need 
	virtual void TowerSetUp(); 
	//represent active state of tower
	virtual void TowerActive(float& DeltaTime) ;
	// how the tower effects enemies when  it damages them 
	virtual void ApplyDamage(AEnemyBase* Enemy);

	// used for AI perception to allow for certain enemies such as the demon enemy to sense towers 
	FGenericTeamId TeamID;
	virtual FGenericTeamId GetGenericTeamId() const override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower Stats")
	float Health = 100.0f;
	// used for replciating any variables that are associated with the state of the tower(in the scope of enemy base)
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerMainStatusEffect")
	// certain towers such as the floor spike trap can apply a status effect to enemies 
	// the id of the main status effect for the tower is represented by this variable 
	EnemyStatusEffect TowerMainStatusEffect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerMainStatusEffect"); 
	float MainStatusEffectDuration = 0.0f; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerMainStatusEffect", meta = (ClampMin = "0.1", ClampMax = "1.0"));
	float MainStatusEffectIncreaseScalar = 0.0f;
	AMainCharacterTest* PlayerRef; 
	
	// allows the response of the various collision boxes on the tower to be set for a certain collision channel 
	// useful for situations  where towers shouldnt  or should overlap a specifc collision object type 
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

	// perception component that allows AI such as the demon to sense the towers and attack them 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components") 
	UAIPerceptionStimuliSourceComponent* StimuliSourceComponent;
	void SetPlayerRef(AMainCharacterTest* PlayerPtr);
	void setHealth(float HealthStore);
	float getHealth();
private: 
	FVector FacingDirSum;
	

};