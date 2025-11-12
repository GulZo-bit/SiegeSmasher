// Fill out your copyright notice in the Description page of Project Settings.


#include "WaveManager.h"

// Sets default values
AWaveManager::AWaveManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UE_LOG(LogTemp, Display, TEXT("Constructor called"));


}

// Called when the game starts or when spawned
void AWaveManager::BeginPlay()
{
	Super::BeginPlay(); 
	
	UE_LOG(LogTemp, Display, TEXT("Wave Manager Begin play called"));
	UE_LOG(LogTemp, Display, TEXT("Wave manger enemies to spawn before iterating is %d"), EnemiesToSpawn.Num());

	World = GetWorld();
	// iterate through the enemies we are using to spawn other enemies and disable their tick
	for (int i = 0; i < EnemiesToSpawn.Num(); i++)
	{
		
		EnemiesToSpawn[i]->SetActorTickEnabled(false); 
		EnemiesToSpawn[i]->DisablePrimaryTick();
		
	}

	UE_LOG(LogTemp, Display, TEXT("Wave manger enemies to spawn after iteration is %d"), EnemiesToSpawn.Num());
	// get a refernec to the server object within the world of this particualr wave manager as each client and server has a different game instance

	ServerObjectRef = Cast<AServerObject>( UGameplayStatics::GetActorOfClass(World, AServerObject::StaticClass()));


}


// Called every frame
void AWaveManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
   // update the wave state and cycle through the enemies that we need to spawn based on timers and their enemy types
	if (HasAuthority()) 
	{
		UpdateCurrentWave(DeltaTime);
	}



}

void AWaveManager::UpdateCurrentWave(float DeltaTime)
{
	// check if the wave has ended and reset timers to begin the wave if so
	CheckWaveEnd();
	if (WaveGlobalWaitTimer <= 0.0f ) {
		// if the wave didint reset we continue spawning as the wait time till the next wave is 0
		UpdateSpawning(DeltaTime);
		return;
	}

	WaveGlobalWaitTimer -= DeltaTime;


	GLog->Log(FString::Printf(TEXT("Wait timer %f"), WaveGlobalWaitTimer));



}




bool AWaveManager::CheckWaveEnd() {

	// if we have reached are total to spawn for the wave and all enemies associated with the wave are dead 
	if (HasAuthority() && WaveEnemyCount == TotalEnemiesSpawned && AliveEnemyCount == 0) {

		if (HasAuthority() && ServerObjectRef != nullptr) {
			// update the state of the wave which gets broadcated across all clients and updated on the server 
			// this ensures things such as player ui will update and inform them about the new wave number
			ServerObjectRef->IncrementPlayerWaveNumber();
		}

		BeginWave();
		
		WaveNumber++;
		WaveGlobalWaitTimer = WaveGlobalWaitTimerMax;
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("wave global wait timer reset to %f"), WaveGlobalWaitTimer));
		


		GLog->Log(FString::Printf(TEXT("wave global wait timer reset to %f"), WaveGlobalWaitTimer));
		return true;
	}
	return false;


}

void AWaveManager::BeginWave()
{

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT(" beggining wave, wave number is %d"), WaveNumber));

	EnemySetUp(); 
	/// if we have multiple spawn points divide the wave count between them and set it to the spawn point cap 
	CurrentSpawnPointCap = ceil((float)WaveEnemyCount / (float)SpawnPoints.Num());
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT(" spawn point cap for wave %d"), CurrentSpawnPointCap));
	//GLog->Log(FString::Printf(TEXT(" spawn point cap for wave %d"), CurrentSpawnPointCap));
	GetNewSpawnPoint();
}
void AWaveManager::CalculateNextEnemyWaveCount(float WaveNumFractional)
{
	WaveEnemyCount = baseStartingEnemyCount + ceil(WaveNumFractional * WavePolynomialConstantOne + (WaveNumFractional * WaveNumFractional) * WavePolynomialConstantTwo);
	AliveEnemyCount = WaveEnemyCount;
}

void AWaveManager::GetNewSpawnPoint()
{
	if (SpawnPoints.Num() > 0) {

		
		// reset the number of enemies spawned on the spawn point as we are selecting a new one
		EnemiesSpawnedOnPoint = 0;
		// get a random spawn pojnt
		int randIndex = random.RandRange(0, SpawnPoints.Num() - 1);
		// set it to the current spawn points
		CurrentSpawnPoint = SpawnPoints[randIndex];
		// reset any cool down the spawn point had
		CurrentSpawnPoint->ResetCoolDownTimer();
		// set the time the wave manager spends on the spawn point
		CurrentTimeForSpawnPoint = CurrentSpawnPoint->GetNewSpawnTime();
		
	}
}







void AWaveManager::CheckSpawnPoints(float DeltaTime)
{

	// if we have met the time to spend on this spawn point or we have reached the cap of enemies that can be spawned by the spawn point
	if (CurrentTimeForSpawnPoint <= 0.0f || EnemiesSpawnedOnPoint == CurrentSpawnPointCap) {
		GetNewSpawnPoint();
		return;
	}
	CurrentTimeForSpawnPoint -= DeltaTime;
	


}





void AWaveManager::EnemySetUp()
{

	
	// reset values associated with spawning enemies
	// reset the index into the array we are using to randomly selected enemies to spawn 
	CurrentAvailableEnemyIndex = 0;
	// no enemies have spawned
	TotalEnemiesSpawned = 0;
	// total count for wave reset
	WaveEnemyCount = 0;
	// for each of the enemies that we could spawn we check if they are not already included in the pooling process 
	// and that they are able to spawn within the wave and if so we add them as a new enemy type to be spawned 
	// usiing the AvailableEnemies TArray
	for (int i = 0; i < EnemiesToSpawn.Num(); i++) {
		EnemyTypes EnemyType = EnemiesToSpawn[i]->GetEnemyWaveType();
		if ( (EnemyAvailablePoolIndicies.Find(EnemyType) == nullptr) &&  EnemiesToSpawn[i]->GetStartingWave() <= WaveNumber) {

			GLog->Log( 
				FString::Printf(TEXT(" new enemy added to available enemies %d wave number was %d"), (int)EnemyType, WaveNumber));
			GLog->Log(FString::Printf(TEXT(" new enemy added to available enemies %d wave number was %d"), (int)EnemyType, WaveNumber));

			// create a new pool for the new enemy type
			EnemyPools.Add(EnemyType, {});
			// set up the pooling index for that enemy type to start at 0
			EnemyAvailablePoolIndicies.Add(EnemyType, 0);
			// add the enmey id to the wave contirbtuion map to track how much it should contribute to each wave
			EnemyWaveContribution.Add(EnemyType, 0);
			// add it to the avaible enemies array
			AvailableEnemies.Add(EnemiesToSpawn[i]);
		    
		}

	
	 }
	GLog->Log(FString::Printf(TEXT("number of available enemies %d"), (int)AvailableEnemies.Num()));
	
	
	for (int i = 0; i < AvailableEnemies.Num(); i++) {

		
		GLog->Log(FString::Printf(TEXT("number of available enemies %d"), (int)AvailableEnemies.Num()));
		// calculate the new wave contrib for the enemy type 
		int NewEnemyWaveContrib = AvailableEnemies[i]->CalculateWaveContribution(WaveNumber); 
		// get the enemy type of the current avaialbe enemy at the current index
		EnemyTypes EnemyType = AvailableEnemies[i]->GetEnemyWaveType();
		// add to the wave count the enemy WaveEnemyCount  tracking the total number of enemies for the wave 
		WaveEnemyCount += NewEnemyWaveContrib; 

		GLog->Log(FString::Printf(TEXT("summing up wave contribution for enemy type: %d Contribution: %d"), EnemyType, NewEnemyWaveContrib));
		// reset the pooling index for the enemy type to 0 as we have begun a new wave 
		// this means we will reuse all the enemies that were spawned of this enemy type in this wave
		EnemyAvailablePoolIndicies[EnemyType] = 0;
		// update the map used to track the current enemy type's wave contribution
		EnemyWaveContribution[EnemyType] = NewEnemyWaveContrib;

		GLog->Log(FString::Printf(TEXT("Total wave contribution is now %d singualr contirbution is %d EnemyPool indicies is %d  "), WaveEnemyCount, EnemyWaveContribution[EnemyType],EnemyAvailablePoolIndicies[EnemyType]));


	    GLog->Log(FString::Printf(TEXT(" new enemy added to  enemy pools type %d  wave number %d"), (int)EnemyType, WaveNumber));
		GLog->Log(FString::Printf(TEXT(" new enemy added to  enemy pools type %d  wave number %d"), (int)EnemyType, WaveNumber));
	}

	// set the number of alive enemies to be the total number of enemies calculated for this wave as it begins
	AliveEnemyCount = WaveEnemyCount;


	GLog->Log(FString::Printf(TEXT(" total enemies for this wave : % d"), AliveEnemyCount));


}


void AWaveManager::UpdateSpawning(float DeltaTime)
{

	// if we havent reached are total number of enemies for the wave update spawning 
	if (TotalEnemiesSpawned != WaveEnemyCount) {
		CheckSpawnPoints(DeltaTime);
		EvaluateEnemySpawning();

	}




}

void AWaveManager::EvaluateEnemySpawning()
{
	// we only spawn the enemies on the server as they are replicated and synced witht the client 
	// we also check that the current spawn point doesnt have a cool down applied so that we are not spawning 
	// enemies on top of one another
	if (HasAuthority() && CurrentSpawnPoint->IsAvailable() ) {

		// select a random enemy type to spawn within range of the current available enemy index and the 
		// last index this is done to keep track of the enemy types that we should currenlty select by shifting 
		// any that we should no longer select behind the current available enemy index
		int randomAvailableEnemyIndex = random.RandRange(CurrentAvailableEnemyIndex, AvailableEnemies.Num() - 1);
		
		GLog->Log(FString::Printf(TEXT("Current number of enemies spawned"), TotalEnemiesSpawned));
		GLog->Log(FString::Printf(TEXT("available index before accessing available enemies"), CurrentAvailableEnemyIndex));
		GLog->Log(FString::Printf(TEXT("random index available enemies %d"), randomAvailableEnemyIndex));
		//  acces the enemy we are spawning
		AEnemyBase* CurrentEnemyToSpawn = AvailableEnemies[randomAvailableEnemyIndex]; 
		// check if we have an existing enemy to spawn from the pool associated with its id
		AEnemyBase* PotentialEnemyInstance = GetExistingInstance(CurrentEnemyToSpawn->GetEnemyWaveType());
		// if we couldnt get an existing instance
		if (PotentialEnemyInstance == nullptr) {

			if (HasAuthority())
			{
				//  instaniate a new enemy on the server and add it to the pool
				PotentialEnemyInstance = CurrentSpawnPoint->SpawnEnemy(CurrentEnemyToSpawn); 
				// give the enemy a refernce to the current wave alive count so it can decrement it when it dies 
				PotentialEnemyInstance->SetEnemyAliveCountref(&AliveEnemyCount);
				// add the newly spawned enemy to the specifc pool associated with its enemy type

				PotentialEnemyInstance->SetActorTickEnabled(true);
				EnemyPools[CurrentEnemyToSpawn->GetEnemyWaveType()].Add(PotentialEnemyInstance);
			}
			
		}
		// decrement the wave contribution for the specifc enemy type we just spawned/reused 
		EnemyWaveContribution[CurrentEnemyToSpawn->GetEnemyWaveType()] -= 1;

		// if the wave contribution for the current wave enemy type hit 0
		if (EnemyWaveContribution[CurrentEnemyToSpawn->GetEnemyWaveType()] == 0 )
		{
			
			// get the enmy we are using to spawn from the and access it using the current avaialble enemies index
			AEnemyBase* temp = AvailableEnemies[CurrentAvailableEnemyIndex];


			GLog->Log(FString::Printf(TEXT("Available enemy swapped at incremented %d"), CurrentAvailableEnemyIndex));

			// get the enemy located at the index we just randomly selected 
			AvailableEnemies[CurrentAvailableEnemyIndex] = AvailableEnemies[randomAvailableEnemyIndex];
			GLog->Log(FString::Printf(TEXT("Swapped index is %d"), randomAvailableEnemyIndex));
			
			GLog->Log(FString::Printf(TEXT("Swapped index is %d"), randomAvailableEnemyIndex));



		   // swap the enemy we randomly selcted with the enemy stored at the current avaialble enemy index and 
		   // increment the current available enemy index exxentially ensuring we can no longer get enemy enemies associated with the 
			//random enemy type we selected 
			AvailableEnemies[randomAvailableEnemyIndex] = temp;
			CurrentAvailableEnemyIndex++;

			GLog->Log(FString::Printf(TEXT("Available enemy index incremented %d"), CurrentAvailableEnemyIndex));

			GLog->Log(FString::Printf(TEXT("Enemy wave contirbtuion reached 0 for enemy type %d new available index is %d"), (int)CurrentEnemyToSpawn->GetEnemyWaveType(), CurrentAvailableEnemyIndex));

		}
		// increment total enemies spaed and the number of enemies spanwed on the particualr spawn point we have selected
		TotalEnemiesSpawned++;
		EnemiesSpawnedOnPoint++;

	}
}




AEnemyBase* AWaveManager::GetExistingInstance(EnemyTypes EnemyType)
{
	// if we are tracking the enemy type selected within a pool located in the map
	if (EnemyAvailablePoolIndicies.Find(EnemyType) != nullptr) {
		int availableIndex = EnemyAvailablePoolIndicies[EnemyType];
		
		// if we find a pool associated with the enemy type and the current index we are using into the pool hasnt hit the size of the 
		//pool and the current enemy we are pointing to within that pool is not currently active
		if (EnemyPools.Find(EnemyType) != nullptr && availableIndex != EnemyPools[EnemyType].Num() && EnemyPools[EnemyType][availableIndex]->GetIsDisabled()) {

			// increment the index we are using to track available enemies within the pool as we are about to renable this one 
			EnemyAvailablePoolIndicies[EnemyType] = (availableIndex + 1);

			// get the enmey we are going to reuse 
			int EnemyToUse = EnemyAvailablePoolIndicies[EnemyType] - 1;

			// reset the existing instance and set its location  using the currently selected spawn point
			return CurrentSpawnPoint->SpawnAndResetExistingEnemyInstance(EnemyPools[EnemyType][EnemyToUse]);

		}
		return nullptr;
	}

	return nullptr;
}

int AWaveManager::GetTotalWaveEnemyCount()
{
	return WaveEnemyCount;
}

int AWaveManager::GetCurrentEnemyWaveCount()
{
	return AliveEnemyCount;
}

