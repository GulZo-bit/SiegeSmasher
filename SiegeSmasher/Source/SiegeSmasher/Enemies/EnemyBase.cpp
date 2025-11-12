// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"
#include "../StatusEffects/BleedStatusEffect.h"  
#include "../MyMainCharacterTest.h"
#include "Components/ChildActorComponent.h"
#include "MCArrow.h"
// Sets default values
AEnemyBase::AEnemyBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	StatusEffectTest = CreateDefaultSubobject<UStatusEffectBase>("StatusEffectTest");
	BleedStatusEffect = CreateDefaultSubobject<UBleedStatusEffect>("BleedStatusEffect");
	bAlwaysRelevant = true;
	NetCullDistanceSquared = 0;
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
	
	InitialiseBleedStatusEffect();

	AnimIsDead = Cast<UBoolAnimInstance>(GetMesh()->GetAnimInstance());



}

int AEnemyBase::EnemyTest()
{
	return 0;
}

//Damaging the enemy.
void AEnemyBase::DamageEnemy(float Damage)
{
	if (HasAuthority()) {
		CurrentHealth -= Damage;
	}

}

void AEnemyBase::DamageEnemy(float Damage, AMainCharacterTest* PlayerRef)
{
	if (HasAuthority() && PlayerRef != nullptr) {
		CurrentHealth -= Damage;
		bool BelowZero = CurrentHealth <= 0.0f;
		PlayerRef->IncrementPlayerScore(ScoreIncrementOnKill * BelowZero);
		PlayerRef->IncrementPlayerKills(1 * BelowZero);
		PlayerRef->IncrementPlayerScore(ScoreIncrementOnHit);
	   
		PlayerRef->UpdateLeaderBoardInfo();

	}

}

void AEnemyBase::SetHealth(float Health)
{
	CurrentHealth = Health;
}

float AEnemyBase::GetHealth()
{
	return CurrentHealth;
}

//Increase enemy health. Used for healing in the witch.
void AEnemyBase::AddToHealth(float Increase)
{
	 CurrentHealth  = std::min((CurrentHealth + Increase),MaxHealth);
}

void AEnemyBase::ResetEnemyOnDeath()
{
	if (HasAuthority())
	{
		Multicast_ResetOnDeath();
	}

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("enemy reset on death disabled %d"), (int)Disabled));
}


void AEnemyBase::SetTick(bool DisableTick) {

	PrimaryActorTick.SetTickFunctionEnable(DisableTick);

}

//On death we need to hide our enemies and make sure the player can't collide with them.
void AEnemyBase::Multicast_ResetOnDeath_Implementation()
{
	SetActorHiddenInGame(true);
	//SetActorEnableCollision(false);
	SetActorEnableCollision(false);
	//GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Magenta, FString::Printf(TEXT("Multi cast for reset death")));
	//SetActorTickEnabled(false);
	SetTick(false);
	Disabled = true;
	bHasBeenReset = false;
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*GLog->Log(FString::Printf(TEXT("Current health for enemy %f"), CurrentHealth));
	GEngine->AddOnScreenDebugMessage(-1, 8.0f, FColor::Red, FString::Printf(TEXT("Current health for enemy %f"),CurrentHealth));*/

	
}

//Called from the wave manage and is used to calculate how many of each enemy should appear.
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

//For when the enemy reaches the base we need to hide them.
void AEnemyBase::EnemyReachedBase()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	SetActorTickEnabled(false);
	Disabled = true;
}

bool AEnemyBase::GetIsDisabled()
{
	return Disabled;
}




void AEnemyBase::ResetOnSpawn()
{

	if (HasAuthority())
	{
		Multicast_ResetOnSpawn();
	}
	

}

//When the enemy respawns we need to essentially enable them again.
void AEnemyBase::Multicast_ResetOnSpawn_Implementation()
{
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetTick(true);
	Disabled = false; 

	CurrentHealth = MaxHealth;
	if (AnimIsDead != nullptr)
	{
		GLog->Log("Anim Instance is not null");
		AnimIsDead->setIsDeadBool(false);
	}
	bHasBeenReset = true;
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

//For the leader board.
void AEnemyBase::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
		//On overlap with a ballista arrow we damage the enemy and increase the points of the player and their kill count if the enemy dies.
		if (Cast<AMCArrow>(OtherActor))
		{
			AMCArrow* TempArrow = Cast<AMCArrow>(OtherActor);
			//GLog->Log(FString::Printf(TEXT("Arrow Damage: %f"), TempArrow->getDamage()));
			if (HasAuthority()) {
				this->SetHealth(GetHealth() - TempArrow->getDamage());
				if (CurrentHealth <= 0.0f) {
					TempArrow->IncrementPlayerKillsRef();
					TempArrow->IncrementPlayerPointsRef(ScoreIncrementOnKill);

				}
				else {
					TempArrow->IncrementPlayerPointsRef(ScoreIncrementOnHit);

				}
			   
			} 

			OtherActor->Destroy();
		}
	
	
}

void AEnemyBase::SetEnemyAliveCountref(int* WaveEnemyAliveCount)
{
	WaveEnemyAliveCountRef = WaveEnemyAliveCount;

}

int AEnemyBase::GetScoreIncOnKill()
{
	return ScoreIncrementOnKill;
}

int AEnemyBase::GetScoreIncOnHit()
{
	return ScoreIncrementOnHit;
}

void AEnemyBase::setHasBeenReset(bool bResetStore)
{
	bHasBeenReset = bResetStore;
}

bool AEnemyBase::getHasBeenReset()
{
	return bHasBeenReset;
}

//Decreases the amount of enemies in the wave.
void AEnemyBase::DecrementWaveEnemyAliveCount()
{


	if (HasAuthority()) {
		if (WaveEnemyAliveCountRef != nullptr) {

			(*WaveEnemyAliveCountRef)--;
			//GEngine->AddOnScreenDebugMessage(-1, 8.0f, FColor::Orange, FString::Printf(TEXT("Enemy alive count decremented by enemy new count %d"), (*WaveEnemyAliveCountRef)));
		}
		else {
			//GEngine->AddOnScreenDebugMessage(-1, 8.0f, FColor::Red, FString::Printf(TEXT("WAVE ENEMY ALIVE COUNT ON ENEMY WAS NULL")));


		}
	}
	
}


void AEnemyBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {

	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AEnemyBase, CurrentHealth);
	DOREPLIFETIME(AEnemyBase, CurrentStatusEffects);




}

void AEnemyBase::Multicast_AnimIsDead_Implementation(bool bStore)
{
	if (AnimIsDead != nullptr)
	{
		GLog->Log("Anim Instance is not null");
		AnimIsDead->setIsDeadBool(bStore);
	}
}

int32 AEnemyBase::CheckHasTowerStatusEffect(EnemyStatusEffect StatusEffect)
{
	return (CurrentStatusEffects & StatusEffect)  ;
}

//Applies the status effect associated with a tower to the enemy.
void AEnemyBase::ApplyTowerStatusEffect(EnemyStatusEffect StatusEffect) {
	if (HasAuthority()) {
		AvailableStatusEffects[StatusEffect]->SetComponentTickEnabled(true);
		CurrentStatusEffects = CurrentStatusEffects | StatusEffect;

	}
}

void AEnemyBase::RemoveTowerStatusEffect(EnemyStatusEffect StatusEffect)
{
	if (HasAuthority()) {

		CurrentStatusEffects = AndNotBitwise(CurrentStatusEffects, StatusEffect);


	}
}

//If the enemy comes into contact with another tower whilst having a status effect. Increase the status effects duration.
void AEnemyBase::IncreaseTowerStatusEffectDuration(EnemyStatusEffect Id, float Increment,AMainCharacterTest* EffectPlayerRef)
{	
		AvailableStatusEffects[Id]->IncreaseDuration(Increment);
		AvailableStatusEffects[Id]->SetPlayerRef(EffectPlayerRef);
}

void AEnemyBase::SetBleedBaseDamage(float BleedDamage)
{	
		BleedStatusEffect->SetBaseDamage(BleedDamage);

}

void AEnemyBase::SetUpTowerStatusEffectDuration(EnemyStatusEffect Id, float MaxDuration, AMainCharacterTest* EffectPlayerRef)
{
	AvailableStatusEffects[Id]->SetCurrentDuration(MaxDuration);
	AvailableStatusEffects[Id]->SetPlayerRef(EffectPlayerRef);


}


void AEnemyBase::InitialiseBleedStatusEffect()
{
	AvailableStatusEffects.Add(EnemyStatusEffect::BLEED, BleedStatusEffect);
	BleedStatusEffect->SetEnemyRef(this);

}


void AEnemyBase::DisablePrimaryTick()
{
    
	PrimaryActorTick.bCanEverTick = false;
}