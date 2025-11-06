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



}
void AWallSpikeTrapTower::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)const {

	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AWallSpikeTrapTower, IsSwinging);
	DOREPLIFETIME(AWallSpikeTrapTower, HasSwung);

}


void AWallSpikeTrapTower::TowerTimeLineInterp(float value) {

	//float newRotation = FMath::Lerp(WallTrapSpikes->GetComponentRotation().Yaw, SwingRotationAngle,value);
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("Tower Interp Function Called %f"),value));
	//WallTrapSpikes->SetWorldRotation(FRotator(0.0f, newRotation, 0.0f));
	WallTrapSpikes->SetWorldRotation(FRotator(EulerAnglesOfSpikesOnPlace.Y, EulerAnglesOfSpikesOnPlace.Z + SwingRotationAngle * value, EulerAnglesOfSpikesOnPlace.X));
}
void AWallSpikeTrapTower::TowerTimeLineEnd() {



	if (HasAuthority() && TowerTimeLine->GetPlaybackPosition() >= 1.0f) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Tower time line end called %f"), TowerTimeLine->GetPlaybackPosition()));
		HasSwung = true;
		RequiresReset = true;
		IsSwinging = false;
       
	}



}

void AWallSpikeTrapTower::TowerDormant(float& DeltaTime) {
	

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("TowerRest timer %f"), CoolDownAfterReset));
	if (HasAuthority() && StartedReset && !TowerTimeLine->IsReversing() && (CoolDownAfterReset -= DeltaTime) <= 0.0f){
		 
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Tower fully reset")));
		CoolDownAfterReset = MaxCoolDownAfterReset; 
		Multicast_SetTriggerBoxCollision(ECollisionEnabled::QueryOnly);


		StartedReset = false;
		
		
	}



}
void AWallSpikeTrapTower::TowerActive(float& DeltaTime) {

	
	if (HasAuthority() && !RequiresReset && !IsSwinging && !TowerTimeLine->IsReversing()) {
	      
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Tower begin swing ")));
		IsSwinging = true;
		Multicast_PlayTowerTimeLine(SwingPlayBackSpeed);
		MultiCast_SetTowerHitBoxEnabled(ECollisionEnabled::QueryOnly);
		
		   
	}


	


}





void AWallSpikeTrapTower::TowerReset()
{
	if (HasAuthority()) {
		StartedReset = true; 

		Multicast_SetTriggerBoxCollision(ECollisionEnabled::NoCollision);
		MultiCast_SetTowerHitBoxEnabled(ECollisionEnabled::NoCollision);

		CurrentyActive = false;
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Tower starting reset ")));
		HasSwung = false;
		Multicast_ReverseTowerTimeLine(SwingPlayBackSpeed);
	
	}


}

void AWallSpikeTrapTower::HandleNewEnemy(AEnemyBase * Enemy)
{

}




void AWallSpikeTrapTower::ApplyDamage(AEnemyBase* Enemy) {
	if (IsSwinging || HasSwung || RequiresReset) { 

		  GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Wall Spike Trap Damaging enemy")));
		
		  if (HasAuthority()) {

			  Enemy->DamageEnemy(TowerDamage);
			  IncrementAssignedPlayersScore(Enemy->GetScoreIncOnHit() * (int)(Enemy->GetHealth() > 0.0f));
                
			  IncrementAssignedPlayersScore(Enemy->GetScoreIncOnKill() * (int)(Enemy->GetHealth() <= 0.0f)); 

			  GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, FString::Printf(TEXT("Incremeting score wall spike trap score ")));

		  }
	}
}

