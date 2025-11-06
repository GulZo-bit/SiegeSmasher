// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "AI/BoolAnimInstance.h"
#include "EnemyBase.generated.h"
#ifndef MAX_ENEMY_NUM
 #define MAX_ENEMY_NUM 150
#endif // !MAX_ENEMY_NUM


UENUM(BlueprintType)
enum class EnemyTypes : uint8
{
	BASE UMETA(DisplayName = "BASE"),
	BASE1 UMETA(DisplayName = "BASE1"),
	VAMPIRE UMETA(DisplayName = "VAMPIRE"),
	WITCH UMETA(DisplayName = "WITCH"),
	DEMON UMETA(DisplayName = "Demon")

};
// enum bit flags for chekcing if an enemy already has a status effect we can have each enum go up in a power of two as that will give 
// us a binary number of 32 bits where only one bit is positive allowing us to easily combine bit field flags using bitwise operators
// to check if an enemy already has a status effect applied to them(so we dont reapply status effects or add them when its not neccessary)
UENUM()
enum class EnemyStatusEffect : int32
{
	NONE = 0 UMETA(DisplayName = "NONE"),
	BLEED = 1 UMETA(DisplayName = "BLEED"),
	

};

static inline  EnemyStatusEffect operator |  (EnemyStatusEffect  Lhs, EnemyStatusEffect Rhs) {

	return static_cast<EnemyStatusEffect>(static_cast<int32>(Lhs) | static_cast<int32>(Rhs));

}
static inline  int32 operator &  (EnemyStatusEffect  Lhs, EnemyStatusEffect Rhs) {

	return (static_cast<int32>(Lhs) & static_cast<int32>(Rhs));

}
static inline  EnemyStatusEffect AndNotBitwise (EnemyStatusEffect  Lhs, EnemyStatusEffect Rhs) {

	return StaticCast<EnemyStatusEffect>((int)Lhs & (~(int)Rhs));
}

class UStatusEffectBase;
class UBleedStatusEffect; 
class AMainCharacterTest;
UCLASS()
class SIEGESMASHER_API AEnemyBase : public ACharacter
{

	GENERATED_BODY()

public:
	AEnemyBase();

protected:

	virtual void BeginPlay() override;
	int EnemyTest();
	int EnemyStartingCount = 8;
	


	float WavePolynomialConstantOne = 0.7f;
	float WavePolynomialConstantTwo = 0.2f;
	int CurrentWaveContribution = 0;
	UPROPERTY(); 
	UStatusEffectBase* StatusEffectTest;

	UPROPERTY();
	UBleedStatusEffect* BleedStatusEffect;

	TMap<EnemyStatusEffect, UStatusEffectBase*> AvailableStatusEffects;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyVariables")
	EnemyTypes EnemyType = EnemyTypes::BASE;
	UPROPERTY(Replicated)
	float CurrentHealth = 100.0f; 

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyVariables")
	float MaxHealth = 100.0f;

	int StartingWave = 0; // wave 0 = 1(starts counting from 0) 
	
	void DecrementWaveEnemyAliveCount();
	bool Disabled = false;

	UBoolAnimInstance* AnimIsDead;

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_AnimIsDead(bool bStore);
	void Multicast_AnimIsDead_Implementation(bool bStore);
public:
	int32 CheckHasTowerStatusEffect(EnemyStatusEffect StatusEffect);
	void ApplyTowerStatusEffect(EnemyStatusEffect  StatusEffect); 
	void RemoveTowerStatusEffect(EnemyStatusEffect StatusEffect);
	void IncreaseTowerStatusEffectDuration(EnemyStatusEffect Id,float Increment,AMainCharacterTest* EffectPlayerRef);
	void SetBleedBaseDamage(float BleedDamage);
	void SetUpTowerStatusEffectDuration(EnemyStatusEffect Id, float MaxDuration,AMainCharacterTest* EffectPlayerRef);
	virtual void Tick(float DeltaTime) override;
	virtual int CalculateWaveContribution(float FractionalWaveNumber);
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override; 

	bool GetIsDisabled();
	// method used for objects pooling can be overidden by defining it in a child class 
	// but i suggest calling the AEnemyBase class method 
	// by doing AEnemyBase::ResetOnSpawn() inside your overidden method
	virtual void ResetOnSpawn();
	int GetCurrentWaveContribution();
	void SetCurrentWaveContribution(int WaveContrib);
	int GetStartingWave();
	virtual void DamageEnemy(float Damage);
	void SetHealth(float Health); 
	float GetHealth(); 
	void AddToHealth(float Increase);
	void ResetEnemyOnDeath();
	EnemyTypes GetEnemyWaveType();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PointIncrementOnHit"); 
	int ScoreIncrementOnHit = 0; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PointIncrementOnKill"); 
	int ScoreIncrementOnKill = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "default")
	UCapsuleComponent* CapsuleStore;

	UFUNCTION()
	void OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UPROPERTY(Replicated);
	EnemyStatusEffect CurrentStatusEffects;
	void SetEnemyAliveCountref(int* WaveEnemyAliveCount); 


	int GetScoreIncOnKill(); 
	int GetScoreIncOnHit();

private:
	int* WaveEnemyAliveCountRef;

	
	
	void InitialiseBleedStatusEffect();
	




};
