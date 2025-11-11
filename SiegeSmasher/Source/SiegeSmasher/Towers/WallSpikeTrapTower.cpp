// Fill out your copyright notice in the Description page of Project Settings.


#include "WallSpikeTrapTower.h"

// Sets default values
AWallSpikeTrapTower::AWallSpikeTrapTower()
{
	bReplicates = true;
	SetReplicateMovement(true);
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	WallTrapHinge = CreateDefaultSubobject<UStaticMeshComponent>("WallTrapHinge");
	WallTrapHinge->SetupAttachment(RootComponent);
	WallTrapSpikes = CreateDefaultSubobject<UStaticMeshComponent>("WallTrapSpikes");
	WallTrapSpikes->SetupAttachment(RootComponent);

	TriggerRangeBox->SetupAttachment(WallTrapHinge);
	TowerHitBox->SetupAttachment(WallTrapSpikes); 
	WallTrapSpikes->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WallTrapHinge->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	TowerHitBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);



	//trigger
}



void AWallSpikeTrapTower::TowerSetUp() {

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Tower SETUP ")));

	TowerTimeLineInterpEvent.BindUFunction(this, FName("TowerTimeLineInterp"));
	TowerEndAction.BindUFunction(this, FName("TowerTimeLineEnd")); 
	TowerTimeLine->SetTimelineFinishedFunc(TowerEndAction);
	TowerTimeLine->AddInterpFloat(TowerTimeLineCurve, TowerTimeLineInterpEvent,FName("Alpha"), FName("Alpha"));
	EulerAnglesOfSpikesOnPlace = WallTrapSpikes->GetComponentRotation().Euler(); 
	TowerTimeLine->SetPlayRate(SwingPlayBackSpeed);
	TowerTimeLine->SetLooping(false); 

	TowerHitBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);


}
void AWallSpikeTrapTower::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)const {

	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AWallSpikeTrapTower, IsSwinging);
	DOREPLIFETIME(AWallSpikeTrapTower, HasSwung);

}

/// here we override the interp method defined in the tower base classs that gets bound to the tower time line in the tower 
// base class to essentially lerp the rotation of the wall spike trap tower spikes rotating 90 degress away from the wall it 
// was placed on using its current rotation 
void AWallSpikeTrapTower::TowerTimeLineInterp(float value) {

	//float newRotation = FMath::Lerp(WallTrapSpikes->GetComponentRotation().Yaw, SwingRotationAngle,value);
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("Tower Interp Function Called %f"),value));
	//WallTrapSpikes->SetWorldRotation(FRotator(0.0f, newRotation, 0.0f));
	WallTrapSpikes->SetWorldRotation(FRotator(EulerAnglesOfSpikesOnPlace.Y, EulerAnglesOfSpikesOnPlace.Z + SwingRotationAngle * value, EulerAnglesOfSpikesOnPlace.X));
}
void AWallSpikeTrapTower::TowerTimeLineEnd() {


	// if we have authority and the time line has reached its max value when this time line call back is executed
	if (HasAuthority() && TowerTimeLine->GetPlaybackPosition() >= 1.0f) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Tower time line end called %f"), TowerTimeLine->GetPlaybackPosition()));
		
		// update variables associated with the current state of the tower 
		HasSwung = true;
		//we also now need to reset the tower and setting this to true will start decrementing the reset timer for the tower 
		RequiresReset = true;
		// no longer swining once tower time line has reached its max value
		IsSwinging = false;
       
	}



}

void AWallSpikeTrapTower::TowerDormant(float& DeltaTime) {
	

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("TowerRest timer %f"), CoolDownAfterReset));
	// if  cooldowns for resetting the wall spike trap tower have been met 
	if (HasAuthority() && StartedReset && !TowerTimeLine->IsReversing() && (CoolDownAfterReset -= DeltaTime) <= 0.0f){
		 
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Tower fully reset")));
		// reset cooldwon timer during reset
		CoolDownAfterReset = MaxCoolDownAfterReset;
		// alow tirgger box to detect enemies ensuring that the collision is synced across all connected machines
		Multicast_SetTriggerBoxCollision(ECollisionEnabled::QueryOnly);

		// we are no longer resetting 
		StartedReset = false;
		
		
	}



}
void AWallSpikeTrapTower::TowerActive(float& DeltaTime) {

	// if we have hit all the conditions to perform the action associated with this tower
	if (HasAuthority() && !RequiresReset && !IsSwinging && !TowerTimeLine->IsReversing()) {
	      
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Tower begin swing ")));
		// begin swing
		IsSwinging = true;
		// enable colllision on the hit box swining out
		MultiCast_SetTowerHitBoxEnabled(ECollisionEnabled::QueryOnly);
		// play timeline on all connected machines from this authorative server instance
		Multicast_PlayTowerTimeLine(SwingPlayBackSpeed);
		
		   
	}


	


}





void AWallSpikeTrapTower::TowerReset()
{

	if (HasAuthority()) {
		// we've started to reset
		StartedReset = true; 
		// diable collsion on both the hitbox and the trigger box 
		// this is to rpevent enemies from overlapping with these while the wall spike trap is in 
		// its dormant state otherwise it mat trigger an overlap too early and not register an event on an enemy when becoming active 
		Multicast_SetTriggerBoxCollision(ECollisionEnabled::NoCollision);
		MultiCast_SetTowerHitBoxEnabled(ECollisionEnabled::NoCollision);
		// not active
		CurrentyActive = false;
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Tower starting reset ")));
		// we have no longer swung out
		HasSwung = false; 
		// reverse the time,line play back position on all connected machines 
		Multicast_ReverseTowerTimeLine(SwingPlayBackSpeed);
	
	}


}

void AWallSpikeTrapTower::HandleNewEnemy(AEnemyBase * Enemy)
{

}




void AWallSpikeTrapTower::ApplyDamage(AEnemyBase* Enemy) {
	

		  GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Wall Spike Trap Damaging enemy")));
		
		  if (HasAuthority()) {
			  // if we are able to attack the enemy and have authority on the server
			  if (IsSwinging || HasSwung || RequiresReset) {

				  // call the generic method implmenetd in the tower base class to give the player points 
				  // base don if we both killed and hit an enemy or just hit an enemy this method also updates the players leaderboard
				  // status across all connections 
				  DamageEnemyAndUpdatePlayerInfo(Enemy, TowerDamage);
				  //Enemy->DamageEnemy(TowerDamage);
				 /* IncrementAssignedPlayersScore(Enemy->GetScoreIncOnHit() * (int)(Enemy->GetHealth() > 0.0f));

				  IncrementAssignedPlayersScore(Enemy->GetScoreIncOnKill() * (int)(Enemy->GetHealth() <= 0.0f)); */

				  GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, FString::Printf(TEXT("Incremeting score wall spike trap score ")));
			  }
		  }
}


