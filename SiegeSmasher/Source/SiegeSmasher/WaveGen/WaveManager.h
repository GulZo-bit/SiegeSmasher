// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h" 
#include "SpawnPoint.h" 
#include"../Enemies/EnemyBase.h"
#include "../ServerObject/ServerObject.h"
#include "WaveManager.generated.h"




// this is the main class for managing the current wave satte and the process for spanwing enemies using a series of timers and data structures to manage the waves current state 
// all while maintinng the sync between the client and server using authority checks to ensure that enemies are only spawned on the server so no duplicate spawning happens 

UCLASS()
class SIEGESMASHER_API AWaveManager : public AActor
{

	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AWaveManager();



protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// store the eney objects that are hidden within the level that we use to copy certain values from such as 
	// enemy id's that are used to determine which enemy we are spanwing this is a uproperty so different enemy types 
	//can be easily added to the wave manager within the particualr level it is being used in 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemiesToSpawn");
	TArray<AEnemyBase*> EnemiesToSpawn;
	// dynamic array of spawn points around the current level to wave manager is in 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WaveSpawnPoints");
	TArray<ASpawnPoint*> SpawnPoints;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	int GetTotalWaveEnemyCount();
	int GetCurrentEnemyWaveCount();
	// update the wave state
	void UpdateCurrentWave(float deltaTime);

	bool CheckWaveEnd();
	// set up the new wave 
	void BeginWave();
	
	void CalculateNextEnemyWaveCount(float WaveNumFractional);
	void GetNewSpawnPoint();
	// set up any new enemy types and caluclate each available enmy's new wave contribution 
	void EnemySetUp();
	// variables for wave generation
private:
	// wait timer to start the wave
	float WaveGlobalWaitTimerMax = 10.0f;
	float WaveGlobalWaitTimer = 0.0f;
	// current wave players are on
	int WaveNumber = 0;
	int TotalEnemiesSpawned = 0;
	int WaveEnemyCount = 0;
	int AliveEnemyCount = 0;
	int baseStartingEnemyCount = 8;
	float WavePolynomialConstantOne = 0.7f;
	float WavePolynomialConstantTwo = 0.2f;
	
	// used to spawn enenmies associated with the wave
	void UpdateSpawning(float DeltaTime);
	void CheckSpawnPoints(float DeltaTime);
	void EvaluateEnemySpawning();
	// used for object pooling to see if we can grab an already existing enemy from one of the pools 
	// mapped to the enemies specifc enemy id saving on calls to instantiate and destory enemies, as we just reuse the ones that we can(the ones dead or disabled)  
	// so there is no constant allocation and deallocation for spawning enemies
	AEnemyBase* GetExistingInstance(EnemyTypes EnemyType);

	// track current spawn point status
private:
	// manager how long we spend on a specifc spawn point if there is more than one 
	float CurrentTimeForSpawnPoint = 0.0f;
	// cap how many enemies can spawn at specifc spawn point chosen if there is more than one 
	int CurrentSpawnPointCap = 0;
	int EnemiesSpawnedOnPoint = 0;
	// used to track which type of enemy we are currenlty spawning and to efficiently randomise it each time 
	int CurrentAvailableEnemyIndex = 0;
	bool SpawnDebugTest = true;
	FRandomStream random;
	ASpawnPoint* CurrentSpawnPoint = nullptr;
	// refernce to the server object that has the ability to update each players ui based on the current wave state 
	AServerObject* ServerObjectRef = nullptr;
	//EnemyStorage	
private:
	// curent types of enemies we can spawn
	TArray<AEnemyBase*> AvailableEnemies;
	// map a particualr enemy type to an array of aready spawned enemies allowing for effective object pooling 
	// based on the type of enemy we are spawning 
	TMap<EnemyTypes, TArray<AEnemyBase*>> EnemyPools;
	// keep track of how much each enemy type is contributing to the wave 
	TMap<EnemyTypes, int> EnemyWaveContribution;
	// track the current index we are on in each of the enemy pools ensuring that we know when we need to spawn more enemies 
	// and which enemy in the pool  we can currently reuse (based on the index into that pool)
	TMap<EnemyTypes, int> EnemyAvailablePoolIndicies;
	
	UWorld* World = nullptr;


};
