// Fill out your copyright notice in the Description page of Project Settings.


#include "BalistaTower.h"

// Sets default values
ABalistaTower::ABalistaTower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
void ABalistaTower::TowerActive() {
	 

	FVector ToTarget = FirstTarget->GetActorLocation() - GetActorLocation();
	if (ToTarget.SquaredLength() < TargetingRange ) {
		FVector TargetDir = ToTarget.GetSafeNormal(); 
		FVector ActorForward = GetActorForwardVector(); 
		float CosAngle = ActorForward.Dot(TargetDir);
		FVector SinAngle = ActorForward.Cross(TargetDir) * FVector::UpVector; 
		

		float PitchAngle = atan2f(ToTarget.Z, ToTarget.X); 
		float YawAngle = atan2(ToTarget.X, ToTarget.Y);
		FQuat RequiredRotation = FRotator(FMath::RadiansToDegrees(PitchAngle), FMath::RadiansToDegrees(YawAngle), 0.0f).Quaternion();
		
		FQuat ActorRotation = FQuat::Slerp(GetActorRotation().Quaternion(), RequiredRotation, RotationLerpSpeed);
	   if (CosAngle > FovSnappingThreshold) {

		   
          

		}
	



	} 





} 


void ABalistaTower::HandleNewEnemy(AEnemyBase* Enemy) {

	    
	    ShouldGetTargets = false;
		FirstTarget = Enemy;
	    
	




}  






// Called when the game starts or when spawned
void ABalistaTower::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABalistaTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

