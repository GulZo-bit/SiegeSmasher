// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnPoint.h"

// Sets default values
ASpawnPoint::ASpawnPoint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnPoint::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASpawnPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
// get a ranomd amount of time that will be allocated to the spawn point for it to spawn enemies
float ASpawnPoint::GetNewSpawnTime()
{
	return random.FRandRange(AllocatedSpawnTimeMin, AllocatedSpawnTimeMax);
}

AEnemyBase* ASpawnPoint::SpawnEnemy(AEnemyBase* EnemyRef)
{
	// spawning an new instance of an enemy ensuring that they always spawn despite collision to avoid any null reference cases 
	FActorSpawnParameters spawnParameters;
	spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	return GetWorld()->SpawnActor<AEnemyBase>(EnemyRef->GetClass(), GetActorTransform(), spawnParameters);

}

// reset an existing enemy and set their location to the spawn point
AEnemyBase* ASpawnPoint::SpawnAndResetExistingEnemyInstance(AEnemyBase* EnemyRef)
{
	
	EnemyRef->ResetOnSpawn();
	EnemyRef->SetActorLocation(GetActorLocation());
	return EnemyRef;
}

// spawn points have a cool down timer to avoid enemies overlapping each other when they get set to the spawn points location
void ASpawnPoint::ResetCoolDownTimer()
{

	CoolDownTimer = random.FRandRange(CoolDownTimerMin, CoolDownTimerMax);
	

}

// get if the spawn point is available and not on cooldown 
bool ASpawnPoint::IsAvailable()
{

	// if the cool down timer has reached 0
	if (CoolDownTimer <= 0.0f) {
		// reset the cool down timer
		ResetCoolDownTimer();
	}
	// subtract delta time(differnce in time between last and current frame) from the spawn point coold down timer ensuring it is synced when running on different machines
	CoolDownTimer -= GetWorld()->GetDeltaSeconds();

	return CoolDownTimer <= 0.0f;
}





