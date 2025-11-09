// Fill out your copyright notice in the Description page of Project Settings.


#include "BalistaTower.h"

// Sets default values
ABalistaTower::ABalistaTower()
{
	bReplicates = true;
	SetReplicateMovement(true);
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = BoxColliderForObjectPlacement;
	BallistaBase = CreateDefaultSubobject<UStaticMeshComponent>("BallistaBase"); 
	BallistaBase->SetupAttachment(RootComponent);
	BallistaTurret = CreateDefaultSubobject<UStaticMeshComponent>("BallistaTurret");
	BallistaTurret->SetupAttachment(RootComponent);
	BallistaArrow = CreateDefaultSubobject<UStaticMeshComponent>("BallistaArrow");
	BallistaArrow->SetupAttachment(BallistaTurret);

	BallistaBase->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BallistaArrow->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BallistaTurret->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	StimuliSourceComponent->UnregisterFromPerceptionSystem();

}


void ABalistaTower::BeginPlay() {
  
	Super::BeginPlay(); 



}

void ABalistaTower::Multicast_SetArrowHidden_Implementation(bool HideBallistaArrow)
{

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("setting ballista arrow hidden %d "), (int)HideBallistaArrow));
	BallistaArrow->SetHiddenInGame(HideBallistaArrow);


}

void ABalistaTower::HideArrow(bool ShouldHideArrow)
{

	if (HasAuthority() && BallistaArrow->bHiddenInGame != ShouldHideArrow) {

		Multicast_SetArrowHidden(ShouldHideArrow);

	}


}

void ABalistaTower::TowerActive(float& DeltaTime) {

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Ballista Tower Active ")));


	FVector BallistaTurretLocation = BallistaTurret->GetComponentLocation();
	FVector ToTarget = EnemySingleTarget->GetActorLocation() - BallistaTurret->GetComponentLocation();
	FVector TargetDir = ToTarget.GetSafeNormal();

	DrawDebugLine(GetWorld(), BallistaTurret->GetComponentLocation(), BallistaTurret->GetComponentLocation()+TargetDir * ToTarget.Length(), FColor::Cyan);

	
	bool LostLOs = World->LineTraceSingleByChannel(LOSResult, BallistaTurretLocation,
		           BallistaTurretLocation + TargetDir * ToTarget.Length(), TowerNoLOSChannel);
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("distance to target %f"), ToTarget.SquaredLength()));
	if (!LostLOs && !CurrentEnemyOutOfRange && EnemySingleTarget->GetHealth() > 0.0f) {


	

		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Ballista currently active")));
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

			HideArrow(true);
			ShootProjectile(BallistaArrow->GetComponentLocation(), RequiredRotation.Rotator());

		}
		if (WaitTimeToReset <= MaxWaitTimeToReset * ProjectileReappearPercent) {
			
			HideArrow(false);

		}

		return;
	}

	
	 //GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Ballista could not find targets waiting for next overlap")));
	if (HasAuthority()) {
		CurrentyActive = false;

		NoTargetsInRange = true;
	 }

	

	

	
} 




void ABalistaTower::TowerDormant(float& DeltaTime) {

	
	TrackEnemies(BallistaTurret->GetComponentLocation());

}

void ABalistaTower::EstablishLineOfSightRays()
{
	//FHitResult HitResult;
	//World->LineTraceSingleByChannel(HitResult, GetActorLocation(), GetActorLocation() + FVector::DownVector * GetTargetingRangeSqr(), PlacingSurface); 
	//
	//FVector TriggerBoxHalfExtents = TriggerBoxDim / 2.0f;
	//
	//float TriggerBoxDimXY = TriggerBoxHalfExtents.X * TriggerBoxHalfExtents.X + TriggerBoxHalfExtents.Y * TriggerBoxHalfExtents.Y;
	//GLog->Log(FString::Printf(TEXT("trigger box dim sqr lenght %f"), TriggerBoxDimXY));
	//LOSRayFiringPoint = HitResult.ImpactPoint; 
	//FHitResult CheckForObstacles;
	//for (float Angle = -PI; Angle <= PI; Angle += FMath::DegreesToRadians(RayDirectionAngleInc)) {
	//	
	//	GLog->Log(FString::Printf(TEXT("current angle for LOS directions:%f "), Angle));
	//	LineOfSightRays.Emplace(cos(Angle), sin(Angle), 0.0f);

	//    
	//	bool HasHitWall = World->LineTraceSingleByChannel(CheckForObstacles, LOSRayFiringPoint, LOSRayFiringPoint + LineOfSightRays[LineOfSightRays.Num()-1] * TriggerBoxDimXY, TowerNoLOSChannel);

	//	ObstaclePointsForLos.Add(FVector(CheckForObstacles.ImpactPoint.X, CheckForObstacles.ImpactPoint.Y, LOSRayFiringPoint.Z) * HasHitWall);
	//	//DrawDebugLine(GetWorld(), LOSRayFiringPoint, LOSRayFiringPoint + LineOfSightRays[LineOfSightRays.Num()-1] * (FVector(TriggerBoxDim.X,TriggerBoxDim.Y,0.0f).Length()), FColor::Blue, false, 10000.0f);



	//}


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




