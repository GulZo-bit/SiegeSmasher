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


void AFloorSpikeTrapTower::TowerSetUp() {

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Tower SETUP ")));


	TowerTimeLineInterpEvent.BindUFunction(this, FName("TowerTimeLineInterp"));
	TowerEndAction.BindUFunction(this, FName("TowerTimeLineEnd"));
	TowerTimeLine->SetTimelineFinishedFunc(TowerEndAction);
	TowerTimeLine->AddInterpFloat(TowerTimeLineCurve, TowerTimeLineInterpEvent, FName("Alpha"), FName("Alpha"));
	TowerTimeLine->SetPlayRate(5.0f);
	TowerTimeLine->SetLooping(false); 
	SpikesStartPos = SpikesMesh->GetComponentLocation();
	SpikesMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
}


void AFloorSpikeTrapTower::TowerTimeLineInterp(float value) {

	     
		SpikesMesh->SetWorldLocation(FMath::Lerp(SpikesStartPos, SpikeTrapBaseMesh->GetComponentLocation(), value));

	


	
}
void AFloorSpikeTrapTower::TowerTimeLineEnd() {



	if ( HasAuthority() && TowerTimeLine->GetPlaybackPosition() >= 1.0f) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Tower time line end called %f"), TowerTimeLine->GetPlaybackPosition()));

		RequiresReset = true;
		SpikesUp = false;
	}



}

void AFloorSpikeTrapTower::TowerDormant(float& DeltaTime) {

	

	  if ( HasAuthority() && StartedReset && !TowerTimeLine->IsReversing() && (CoolDownAfterReset -= DeltaTime) <= 0.0f) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("TowerRest timer %f"), CoolDownAfterReset));

		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Tower fully reset")));
		CoolDownAfterReset = MaxCoolDownAfterReset;
		Multicast_SetTriggerBoxCollision(ECollisionEnabled::QueryOnly);
		StartedReset = false;




		}
	


}
void AFloorSpikeTrapTower::TowerActive(float& DeltaTime) {

	/*if (HasAuthority()) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("Server requires reset %d"), (int)RequiresReset));

		}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("client requires reset %d"), (int)RequiresReset));

	}*/
		if (HasAuthority() && !RequiresReset && !SpikesUp && !TowerTimeLine->IsReversing()) {
			 
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Tower begin swing ")));

			/*	TowerTimeLine->SetPlayRate(UpwardPlayBackSpeed);
				TowerTimeLine->PlayFromStart();*/			
			Multicast_PlayTowerTimeLine(UpwardPlayBackSpeed);
			SpikesUp = true;

			
			
				
		
			/*TowerTimeLine->SetPlayRate(UpwardPlayBackSpeed);
			TowerTimeLine->PlayFromStart();*/
			//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Tower play back rate %f"), TowerTimeLine->GetPlayRate()));


		}
	




}





void AFloorSpikeTrapTower::TowerReset()
{
	
		if (HasAuthority()) {
			//Multicast_SetTriggerBoxCollision(ECollisionEnabled::NoCollision);

			/*	TowerTimeLine->SetPlayRate(DownWardPlayBackSpeed);
				TowerTimeLine->ReverseFromEnd();*/
			Multicast_ReverseTowerTimeLine(DownWardPlayBackSpeed);
			StartedReset = true;
			CurrentyActive = false;
			Multicast_SetTriggerBoxCollision(ECollisionEnabled::NoCollision);
		}
		


	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Tower starting reset ")));


}




void AFloorSpikeTrapTower::ApplyDamage(AEnemyBase* Enemy) {
	if (( RequiresReset || SpikesUp )) {

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT(" Spike Trap Damaging enemy")));
		Enemy->DamageEnemy(TowerDamage);

	}
}

