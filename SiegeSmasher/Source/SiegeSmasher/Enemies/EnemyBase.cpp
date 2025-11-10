// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"
#include "../StatusEffects/BleedStatusEffect.h"  
#include "../MyMainCharacterTest.h"
#include "MCArrow.h"
// Sets default values
AEnemyBase::AEnemyBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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

void AEnemyBase::DamageEnemy(float Damage)
{
	if (HasAuthority()) {
		CurrentHealth -= Damage;
		GEngine->AddOnScreenDebugMessage (-1,3.0f,FColor::Orange,FString::Printf(TEXT("Current Health for enemy: %f"), CurrentHealth));

		
	
	}

}

void AEnemyBase::DamageEnemy(float Damage, AMainCharacterTest* PlayerRef)
{
	if (HasAuthority() && PlayerRef != nullptr) {
		CurrentHealth -= Damage;
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Orange, FString::Printf(TEXT("Current Health for enemy: %f"), CurrentHealth));
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

void AEnemyBase::AddToHealth(float Increase)
{
	 CurrentHealth  = std::min((CurrentHealth + Increase),MaxHealth);
}

void AEnemyBase::ResetEnemyOnDeath()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	SetActorTickEnabled(false); 
	Disabled = true;

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("enemy reset on death disabled %d"), (int)Disabled));
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*GLog->Log(FString::Printf(TEXT("Current health for enemy %f"), CurrentHealth));
	GEngine->AddOnScreenDebugMessage(-1, 8.0f, FColor::Red, FString::Printf(TEXT("Current health for enemy %f"),CurrentHealth));*/


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

bool AEnemyBase::GetIsDisabled()
{
	return Disabled;
}




void AEnemyBase::ResetOnSpawn()
{
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetActorTickEnabled(true); 
	Disabled = false;
	CurrentHealth = MaxHealth;

	if (HasAuthority())
	{
		//UBoolAnimInstance* Temp = Cast<UBoolAnimInstance>(GetMesh()->GetAnimInstance());
		//Temp->setIsDeadBool(false);

		Multicast_AnimIsDead(false);
	}
	

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

	/*if (OtherActor && (OtherActor != this))
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlap Begun with: %s"), *OtherActor->GetName());
	}*/
	
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

void AEnemyBase::DecrementWaveEnemyAliveCount()
{


	if (HasAuthority()) {
		if (WaveEnemyAliveCountRef != nullptr) {

			(*WaveEnemyAliveCountRef)--;
			GEngine->AddOnScreenDebugMessage(-1, 8.0f, FColor::Orange, FString::Printf(TEXT("Enemy alive count decremented by enemy new count %d"), (*WaveEnemyAliveCountRef)));
		}
		else {
			GEngine->AddOnScreenDebugMessage(-1, 8.0f, FColor::Red, FString::Printf(TEXT("WAVE ENEMY ALIVE COUNT ON ENEMY WAS NULL")));


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



