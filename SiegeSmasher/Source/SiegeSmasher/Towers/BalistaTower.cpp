// Fill out your copyright notice in the Description page of Project Settings.


#include "BalistaTower.h"

// Sets default values
ABalistaTower::ABalistaTower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BallistaBase = CreateDefaultSubobject<UStaticMeshComponent>("BallistaBase"); 
	BallistaBase->SetupAttachment(RootComponent); 
	BallistaTurret = CreateDefaultSubobject<UStaticMeshComponent>("BallistaTurret");
	BallistaTurret->SetupAttachment(RootComponent);
	TowerFiringPoint->SetupAttachment(BallistaTurret);




}
void ABalistaTower::TowerActive(float& DeltaTime) {
	 
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Ballista Tower Active ")));
	
	FVector ToTarget = EnemySingleTarget->GetActorLocation() - BallistaTurret->GetComponentLocation();
	float toTargetLength = ToTarget.Length();
	DrawDebugLine(GetWorld(), BallistaTurret->GetComponentLocation(), BallistaTurret->GetComponentLocation() + ToTarget.GetSafeNormal() * FVector(toTargetLength, toTargetLength, toTargetLength), FColor::Cyan);
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Target distance %f"), ToTarget.SquaredLength()));
	if ( ToTarget.SquaredLength() < (TargetingRange * TargetingRange) ) {
		
		
		FVector TargetDir = ToTarget.GetSafeNormal();

		float Alignment = TargetDir.Dot(BallistaTurret->GetForwardVector()); 
		FVector FromTarget = BallistaTurret->GetComponentLocation() - EnemySingleTarget->GetActorLocation();
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("alignment  for turret %f "), Alignment));
		FVector PitchVector = FVector(0.0f, 0.0f, TargetDir.Z); 
		float DistanceForPitch = sqrt(ToTarget.X * ToTarget.X + ToTarget.Y * ToTarget.Y);
		float PitchAngle = atan2f(ToTarget.Z,DistanceForPitch);
		float YawAngle = atan2f(ToTarget.Y, ToTarget.X);

		FQuat RequiredRotation= FRotator(FMath::RadiansToDegrees(PitchAngle), FMath::RadiansToDegrees(YawAngle), 0.0f).Quaternion();

		
		FVector YawAlignedActorForward = GetActorForwardVector();
		FQuat TurretRotation = FQuat::Slerp(BallistaTurret->GetComponentRotation().Quaternion(),(RequiredRotation ), 0.5f);
		BallistaTurret->SetWorldRotation(TurretRotation);

		if (Alignment > FovSnappingThreshold && !RequiresReset) {


			ShootProjectile(RequiredRotation.Rotator());




		}

	  

		


	} 

	





	
} 








