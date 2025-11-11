// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorSpikeTrapTower.h"

// Sets default values
AFloorSpikeTrapTower::AFloorSpikeTrapTower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	bReplicates = true;
	SetReplicateMovement(true);
	PrimaryActorTick.bCanEverTick = true; 

	SpikesMesh = CreateDefaultSubobject<UStaticMeshComponent>("SpikesMesh"); 
	SpikeTrapBaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("SpikeTrapBaseMesh"); 

	SpikesMesh->SetupAttachment(RootComponent);
	SpikeTrapBaseMesh->SetupAttachment(RootComponent);
	TowerHitBox->SetupAttachment(SpikesMesh);

	SpikesMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

// Called when the game starts or when spawned
void AFloorSpikeTrapTower::BeginPlay()
{
	Super::BeginPlay(); 

	
	
}
void AFloorSpikeTrapTower::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)const {

	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFloorSpikeTrapTower, SpikesUp);


}
// Called every frame
void AFloorSpikeTrapTower::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	CurrentDeltaTime = DeltaTime;

}

void AFloorSpikeTrapTower::ApplyBleedToEnemy(AEnemyBase* Enemy)
{
	// set the bleed damage for the bleed status effect component on the enemy
	Enemy->SetBleedBaseDamage(BleedBaseDamage);
	// if the enemy alrwayd has the bleed status effect
	if (Enemy->CheckHasTowerStatusEffect(TowerMainStatusEffect)) {
		
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, FString::Printf(TEXT("Enemy aleady had status effect increasing duration")));
	   // stack its duration rather than reapplying it
		Enemy->IncreaseTowerStatusEffectDuration(TowerMainStatusEffect,
			MainStatusEffectDuration * MainStatusEffectIncreaseScalar,PlayerRef);
		
		return;
	}
	// if the enemy didint have the bleed status effect
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, FString::Printf(TEXT("Enemy did not have status effect")));
	// apply the status effect and activate the bleed component on the enemy
	Enemy->ApplyTowerStatusEffect(TowerMainStatusEffect); 
	// set up the duration for the status effect and set the assinged player ref who's score/kills should be incremented if the enemy
	// dies to the status effect
	Enemy->SetUpTowerStatusEffectDuration(TowerMainStatusEffect, MainStatusEffectDuration,PlayerRef);

}


void AFloorSpikeTrapTower::TowerSetUp() {

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Tower SETUP ")));

	/// in this cas rthis tower uses the tower timeline so we bind the overriden methods for the tower timeline call backs 
	//provided by the tower base class 
	TowerTimeLineInterpEvent.BindUFunction(this, FName("TowerTimeLineInterp"));
	TowerEndAction.BindUFunction(this, FName("TowerTimeLineEnd"));
	TowerTimeLine->SetTimelineFinishedFunc(TowerEndAction);
	TowerTimeLine->AddInterpFloat(TowerTimeLineCurve, TowerTimeLineInterpEvent, FName("Alpha"), FName("Alpha"));
	TowerTimeLine->SetPlayRate(5.0f);
	TowerTimeLine->SetLooping(false); 
	SpikesStartPos = SpikesMesh->GetComponentLocation();
	SpikesMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
}

// overideen call bakc for the tower timeline that define what the time line should do with the value it is extracting from its 
// assigned UFloatCurve in this case we just interpolate the position of the spikes on the spike trap from start up to the point where 
// they are fully visible 
void AFloorSpikeTrapTower::TowerTimeLineInterp(float value) {

	
	
		SpikesMesh->SetWorldLocation(FMath::Lerp(SpikesStartPos, SpikeTrapBaseMesh->GetComponentLocation(), value));

	
	
}
void AFloorSpikeTrapTower::TowerTimeLineEnd() {


	// when the timline reaches its end and we are the authoritative instance
	if ( HasAuthority() && TowerTimeLine->GetPlaybackPosition() >= 1.0f) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Tower time line end called %f"), TowerTimeLine->GetPlaybackPosition()));

		// we require a reset to reverse the time line and bring the spikes down 
		RequiresReset = true;
		SpikesUp = false;
	}



}

void AFloorSpikeTrapTower::TowerDormant(float& DeltaTime) {

	
	// if we have hi =t our cooldown timers and the timeline has finished reversing
	  if ( HasAuthority() && StartedReset && !TowerTimeLine->IsReversing() && (CoolDownAfterReset -= DeltaTime) <= 0.0f) {

		///reset timers and renable the hit trigger box for the floor spike trap
		CoolDownAfterReset = MaxCoolDownAfterReset;
		Multicast_SetTriggerBoxCollision(ECollisionEnabled::QueryOnly);
		StartedReset = false;




	  }
	


}
void AFloorSpikeTrapTower::TowerActive(float& DeltaTime) {

	
		if (HasAuthority() && !RequiresReset && !SpikesUp && !TowerTimeLine->IsReversing()) {
			 
			// call the multicast rpc to play the timeline across all machines
			Multicast_PlayTowerTimeLine(UpwardPlayBackSpeed); 

			// spikes are up so we can deal damage
			SpikesUp = true;

		}
	




}





void AFloorSpikeTrapTower::TowerReset()
{
	
		if (HasAuthority()) {
			// reverese timeline on all connected machines
			Multicast_ReverseTowerTimeLine(DownWardPlayBackSpeed); 
			/// we've started a reset
			StartedReset = true;
			// no longer in active state
			CurrentyActive = false;
			// cant be triggered anymore across all connected machines
			Multicast_SetTriggerBoxCollision(ECollisionEnabled::NoCollision);
		}
		

}




void AFloorSpikeTrapTower::ApplyDamage(AEnemyBase* Enemy) {

	// if we are currenlty able to attack the enemy
	if ( SpikesUp || RequiresReset ) {

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT(" Spike Trap Damaging enemy")));
		// deal the initial damage
		Enemy->DamageEnemy(TowerDamage);
		
		if (HasAuthority()) {
			// call the method implmented in the tower base class to update the the  player's score
			IncrementAssignedPlayersScore(Enemy->GetScoreIncOnHit() * (Enemy->GetHealth() > 0.0f));
			//the flooor spike trap can apply a bleed status efffect to enemies which is applied to the enemy with authority as the enemy health is replicated acorss clients

			ApplyBleedToEnemy(Enemy);
		}
		




	}
}

