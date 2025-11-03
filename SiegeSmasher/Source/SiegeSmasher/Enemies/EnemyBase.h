// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MCArrow.h"
#include "Components/CapsuleComponent.h"
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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyVariables")
	EnemyTypes EnemyType = EnemyTypes::BASE;
	UPROPERTY(Replicated)
	float CurrentHealth = 100.0f; 

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyVariables")
	float MaxHealth = 100.0f;

	int StartingWave = 0; // wave 0 = 1(starts counting from 0) 


	

public:

	virtual void Tick(float DeltaTime) override;
	virtual int CalculateWaveContribution(float FractionalWaveNumber);
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "default")
	UCapsuleComponent* CapsuleStore;

	UFUNCTION()
	void OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
private:
		int* WaveEnemyAliveCountRef;

		void SetEnemyAliveCountref(int* WaveEnemyAliveCount); 
		void DecrementWaveEnemyAliveCount();



};
