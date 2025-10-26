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
	BallistaArrow = CreateDefaultSubobject<UStaticMeshComponent>("BallistaArrow");
	BallistaArrow->SetupAttachment(BallistaTurret);

	

}




void ABalistaTower::TowerActive(float& DeltaTime) {

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Ballista Tower Active ")));


	FVector BallistaTurretLocation = BallistaTurret->GetComponentLocation();
	FVector ToTarget = EnemySingleTarget->GetActorLocation() - BallistaTurret->GetComponentLocation();
	/*float toTargetLength = ToTarget.Length();*/
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Target distance %f"), ToTarget.SquaredLength()));
	float FullTargetingRange = TargetingRange * TargetingRange;
	FVector TargetDir = ToTarget.GetSafeNormal();


	


	DrawDebugLine(GetWorld(), BallistaTurret->GetComponentLocation(), BallistaTurret->GetComponentLocation()+TargetDir * ToTarget.Length(), FColor::Cyan);

	
	bool LostLOs = World->LineTraceSingleByChannel(LOSResult, BallistaTurretLocation,
		           BallistaTurretLocation + TargetDir * ToTarget.Length(), TowerNoLOSChannel);
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("distance to target %f"), ToTarget.SquaredLength()));
	if (!LostLOs && ToTarget.SquaredLength() < (FullTargetingRange)) {

		float Alignment = TargetDir.Dot(BallistaTurret->GetForwardVector());
		FVector FromTarget = BallistaTurret->GetComponentLocation() - EnemySingleTarget->GetActorLocation();
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("alignment  for turret %f "), Alignment));
		FVector PitchVector = FVector(0.0f, 0.0f, TargetDir.Z);
		float DistanceForPitch = sqrt(ToTarget.X * ToTarget.X + ToTarget.Y * ToTarget.Y);
		float PitchAngle = atan2f(ToTarget.Z, DistanceForPitch);
		float YawAngle = atan2f(ToTarget.Y, ToTarget.X);

		FQuat RequiredRotation = FRotator(FMath::RadiansToDegrees(PitchAngle), FMath::RadiansToDegrees(YawAngle), 0.0f).Quaternion();
		FVector YawAlignedActorForward = GetActorForwardVector();
		FQuat TurretRotation = FQuat::Slerp(BallistaTurret->GetComponentRotation().Quaternion(), (RequiredRotation), 0.5f);

		BallistaTurret->SetWorldRotation(TurretRotation);

		if (Alignment > FovSnappingThreshold && !RequiresReset) {

			BallistaArrow->SetHiddenInGame(true);
			ShootProjectile(BallistaArrow->GetComponentLocation(), RequiredRotation.Rotator());

		}
		if (WaitTimeToReset <= MaxWaitTimeToReset * ProjectileReappearPercent) {
			BallistaArrow->SetHiddenInGame(false);

		}

		return;
	}

	

	SortedClosestEnemiesInRange();
	bool CanStayActive = false; 
	bool LostFullLos = false;
	if (CurrentEnemiesInRange.Num() > 0) {

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Ballista getting enemy in range number of enemmies %d"), CurrentEnemiesInRange.Num()));

		FVector ToNewTarget = CurrentEnemiesInRange[0]->GetActorLocation() - BallistaTurretLocation;
		LostFullLos = World->LineTraceSingleByChannel(LOSResult,
			BallistaTurretLocation,
			BallistaTurretLocation +
			ToNewTarget.GetSafeNormal() * ToNewTarget.Length(),
			TowerNoLOSChannel);
	    
		CanStayActive = !(CurrentEnemiesInRange[0] == EnemySingleTarget || LostFullLos);
		
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green,FString::Printf(TEXT("EnemyLostLos is: %d "), LostFullLos));

	   if (LostLOs ){
			
		   /*FVector MinFov = BallistaTurret->GetComponentRotation().Vector();
		   FVector MaxFov = MinFov.MirrorByVector(BallistaTurret->GetForwardVector()).GetSafeNormal(); 
		   
		   DrawDebugLine(World,BallistaTurretLocation, BallistaTurretLocation + MinFov * GetTargetingRangeSqr(), FColor::Green, false, 1000.0f);
		   DrawDebugLine(World, BallistaTurretLocation, BallistaTurretLocation + MaxFov * GetTargetingRangeSqr(), FColor::Red, false, 1000.0f);*/

		   /*DirectionsToRegainLos.Add(LOSResult.GetComponent()->GetOwner(),FVector());
			
		  EnemiesToTrackForLOS.Add(EnemySingleTarget);*/
		}
		EnemySingleTarget = Cast<AEnemyBase>(CurrentEnemiesInRange[0]);

	 } 
	 
	
	/*if (LostLOs) {
		CanLoseLOS = true;
	}*/
	CurrentyActive = CanStayActive;
	NoTargetsInRange = !CanStayActive;

	

	 GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Ballista could not find targets waiting for next overlap")));


	

	

	
} 

void ABalistaTower::TowerDormant(float& DeltaTime) {

	
	/*if (CanLoseLOS && !CurrentyActive ) {
		FHitResult HitResult = FHitResult();
		TArray<AActor*> EnemiesInRange = TArray<AActor*>{};
		SortedClosestEnemiesInRange(EnemiesInRange);  
		FVector ActorLoc = GetActorLocation();
		if( EnemiesInRange.Num() > 0 && 
			!World->LineTraceSingleByChannel(HitResult, ActorLoc, ActorLoc +
			(EnemiesInRange[0]->GetActorLocation() - ActorLoc).GetSafeNormal() * 
			(EnemiesInRange[0]->GetActorLocation() - ActorLoc).Length(), TowerNoLOSChannel)
		   )
		{

			EnemySingleTarget = Cast<AEnemyBase>(EnemiesInRange[0]);
			CurrentyActive = true; 
			NoTargetsInRange = false;

		}

		*/
		





}



bool ABalistaTower::HasLineOfSite(FVector To) {


	FHitResult LOSRes = FHitResult();
	FVector BallistaTurretLocation = BallistaTurret->GetComponentLocation();
	FVector ToTarget = To - BallistaTurretLocation;
	return !(World->LineTraceSingleByChannel(LOSRes,
		BallistaTurretLocation,
		BallistaTurretLocation +
		ToTarget.GetSafeNormal() * ToTarget.Length(),
		TowerNoLOSChannel));

}




