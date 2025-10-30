// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"
#include "AI/BoolAnimInstance.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();

	//this->OnActorBeginOverlap.AddDynamic(this, &AEnemyBase::OnOverLapBegin);
	CapsuleStore = this->GetCapsuleComponent();
	if (CapsuleStore != nullptr)
	{
		CapsuleStore->OnComponentBeginOverlap.AddDynamic(this, &AEnemyBase::OnOverLapBegin);
		GLog->Log("Found capsule for enemy base");
	}
	CurrentHealth = MaxHealth;
}

int AEnemyBase::EnemyTest()
{
	return 0;
}

void AEnemyBase::DamageEnemy(float Damage)
{
	CurrentHealth -= Damage;
	GLog->Log(FString::Printf(TEXT("Current Health: %f"), CurrentHealth));
}

void AEnemyBase::SetHealth(float Health)
{
	CurrentHealth = Health;
}

float AEnemyBase::GetHealth()
{
	return CurrentHealth;
}

void AEnemyBase::AddToHealth(float Increase)
{
	 CurrentHealth  = std::min((CurrentHealth + Increase),MaxHealth);
}

void AEnemyBase::ResetEnemyOnDeath()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	SetActorTickEnabled(false);


}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int  AEnemyBase::CalculateWaveContribution(float FractionalWaveNumber)
{

	CurrentWaveContribution = EnemyStartingCount + ceil(FractionalWaveNumber * WavePolynomialConstantOne + (FractionalWaveNumber * FractionalWaveNumber) * WavePolynomialConstantTwo);
	return CurrentWaveContribution;
}

// Called to bind functionality to input
void AEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}




void AEnemyBase::ResetOnSpawn()
{
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetActorTickEnabled(true);
	CurrentHealth = MaxHealth;
	UBoolAnimInstance* Temp = Cast<UBoolAnimInstance>(GetMesh()->GetAnimInstance());
	Temp->setIsDeadBool(false);

}

int AEnemyBase::GetCurrentWaveContribution()
{
	return CurrentWaveContribution;
}

void AEnemyBase::SetCurrentWaveContribution(int WaveContrib)
{
	CurrentWaveContribution = WaveContrib;
}

int AEnemyBase::GetStartingWave()
{
	return StartingWave;
}

EnemyTypes AEnemyBase::GetEnemyWaveType()
{
	return EnemyType;
}

void AEnemyBase::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//GLog->Log("Enemy base is overlapping");

	if (OtherActor && (OtherActor != this))
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlap Begun with: %s"), *OtherActor->GetName());
	}
	if (Cast<APlayerArrow>(OtherActor))
	{
		GLog->Log("Overlapped with arrow");
		this->SetHealth(GetHealth() - 50);
	}
}

void AEnemyBase::SetEnemyAliveCountref(int* WaveEnemyAliveCount)
{
	WaveEnemyAliveCountRef = WaveEnemyAliveCount;

}

void AEnemyBase::DecrementWaveEnemyAliveCount()
{

	if (WaveEnemyAliveCountRef != nullptr) {

		(*WaveEnemyAliveCountRef)--;
		GEngine->AddOnScreenDebugMessage(-1, 8.0f, FColor::Orange, FString::Printf(TEXT("Enemy alive count decremented by enemy new count %d"), (*WaveEnemyAliveCountRef)));
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 8.0f, FColor::Red, FString::Printf(TEXT("WAVE ENEMY ALIVE COUNT ON ENEMY WAS NULL")));


	}
}
