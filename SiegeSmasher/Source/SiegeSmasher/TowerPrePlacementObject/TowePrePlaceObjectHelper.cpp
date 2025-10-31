// Fill out your copyright notice in the Description page of Project Settings.


#include "TowePrePlaceObjectHelper.h"

// Sets default values
ATowePrePlaceObjectHelper::ATowePrePlaceObjectHelper()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	bReplicates = true;
	SetReplicateMovement(true);
	PrimaryActorTick.bCanEverTick = true;
	BoxColliderForObjectPlacement = CreateDefaultSubobject<UBoxComponent>("BoxColliderForObjectPlacement");
	RootComponent = BoxColliderForObjectPlacement;

	BoxColliderForObjectPlacement->SetCollisionProfileName(FName("TowerPrePlacement"));

}
// Called when the game starts or when spawned
void ATowePrePlaceObjectHelper::BeginPlay()
{
	Super::BeginPlay();
	for (int i = 0; i < AllowedDirections.Num(); i++) {

		FacingDirSum += AllowedDirections[i];

	}
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Begin play called for tower pre place helper")));

	BoxColliderForObjectPlacement->OnComponentBeginOverlap.AddDynamic(this, &ATowePrePlaceObjectHelper::OnComponentBeginOverlap);
	BoxColliderForObjectPlacement->OnComponentEndOverlap.AddDynamic(this, &ATowePrePlaceObjectHelper::OnComponentEndOverlap);

}



// Called every frame
void ATowePrePlaceObjectHelper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ATowePrePlaceObjectHelper::GetCanPlaceTower()
{
	TArray<UPrimitiveComponent*> OverlappedTowers = {};
	BoxColliderForObjectPlacement->GetOverlappingComponents(OverlappedTowers); 
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("Attemted to place tower number of towers overlapping %d"), OverlappedTowers.Num()));
	return OverlappedTowers.Num() == 0;
}

FVector ATowePrePlaceObjectHelper::GetPlacementColliderHalfExtents()
{
	return  BoxColliderForObjectPlacement->GetCollisionShape().GetExtent();

}
void ATowePrePlaceObjectHelper::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Ghost placement box overlapped component")));

	if (OtherComp->GetCollisionObjectType() == TowerPlacementBoxObjectType) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Ghost Placement box overlapping cant place tower")));

		CanPlaceTower = false;

	}



}

void ATowePrePlaceObjectHelper::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Ghost placement box ended overlap with component")));

	if (OtherComp->GetCollisionObjectType() == TowerPlacementBoxObjectType) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Ghost Placement box end overlap can place tower")));

		CanPlaceTower = true;

	}
}


bool ATowePrePlaceObjectHelper::ResolvePlacement(FVector& SurfaceBoxExtents, FVector& SurfacePos, FVector& PlacementPosition, FVector& CamDir, FVector& CamPos, FTransform& surfaceTransform)
{



	DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + GetActorUpVector() * FVector(700.0f, 700.0f, 700.0f), FColor::Green);
	FVector ActorRight = GetActorRightVector();
	// min and max for box containing surface	
	FVector PlacementBox = GetPlacementColliderHalfExtents();
	FVector LocalPlacementPosition = (PlacementPosition - SurfacePos);
	FQuat WorldRotation = surfaceTransform.GetRotation();


	FQuat WorldRotExcludePitch = FQuat(WorldRotation.X, WorldRotation.Y, WorldRotation.Z, WorldRotation.W);
	VectorRegister4 LocalTowerTest4 = (VectorQuaternionInverseRotateVector(MakeVectorRegister(WorldRotExcludePitch.X, WorldRotExcludePitch.Y, WorldRotExcludePitch.Z, WorldRotExcludePitch.W),
		MakeVectorRegister(LocalPlacementPosition.X, LocalPlacementPosition.Y, LocalPlacementPosition.Z, (double)0.0f)));
	FVector InvertedCamDir = -CamDir;

	FVector RotatedCamDir = -CamDir;

	FVector LocalTowerTestPos = FVector();
	VectorStoreFloat3(LocalTowerTest4, &LocalTowerTestPos);
	FVector TowerMin = LocalTowerTestPos + FVector(-PlacementBox.X, -PlacementBox.Y, -PlacementBox.Z);
	FVector TowerMax = LocalTowerTestPos + FVector(PlacementBox.X, PlacementBox.Y, PlacementBox.Z);
	FVector TowerMinWorld = PlacementPosition + surfaceTransform.Rotator().RotateVector(FVector(-PlacementBox.X, -PlacementBox.Y, -PlacementBox.Z));
	FVector TowerMaxWorld = PlacementPosition + surfaceTransform.Rotator().RotateVector(FVector(PlacementBox.X, PlacementBox.Y, PlacementBox.Z));
	FVector LocalBoxMin = -SurfaceBoxExtents;
	FVector LocalBoxMax = SurfaceBoxExtents;
	FVector Range = LocalBoxMax - LocalBoxMin;
	FVector WorldBoxMax = SurfacePos + surfaceTransform.GetRotation().RotateVector(LocalBoxMax);
	FVector WorldBoxMin = SurfacePos + surfaceTransform.GetRotation().RotateVector(LocalBoxMin);


	DrawDebugSphere(GetWorld(), LocalTowerTestPos, 50.0f, 8, FColor::Magenta);

	DrawDebugBox(GetWorld(), FVector(LocalBoxMin.X, LocalBoxMin.Y, LocalBoxMin.Z), FVector(20.0f, 20.0f, 20.0f), FColor::Yellow);
	DrawDebugBox(GetWorld(), FVector(LocalBoxMax.X, LocalBoxMax.Y, LocalBoxMax.Z), FVector(20.0f, 20.0f, 20.0f), FColor::Magenta);
	DrawDebugSphere(GetWorld(), TowerMin, 20.0f, 8, FColor::Emerald);
	DrawDebugSphere(GetWorld(), TowerMax, 20.0f, 8, FColor::Emerald);
	DrawDebugSphere(GetWorld(), TowerMinWorld, 20.0f, 8, FColor::Emerald);
	DrawDebugSphere(GetWorld(), TowerMaxWorld, 20.0f, 8, FColor::Emerald);
	DrawDebugSphere(GetWorld(), WorldBoxMin, 20.0f, 8, FColor::Blue);
	DrawDebugSphere(GetWorld(), WorldBoxMax, 20.0f, 8, FColor::Emerald);



	//width 
	bool IsContainedWidth = TowerMin.Y >= LocalBoxMin.Y && TowerMax.Y <= LocalBoxMax.Y;

	//height
	bool IsContainedHeight = TowerMin.Z >= LocalBoxMin.Z && TowerMax.Z <= LocalBoxMax.Z;

	//length
	bool IsContainedLength = TowerMin.X >= LocalBoxMin.X && TowerMax.X <= LocalBoxMax.X;


	FVector3d CollisionResNormal = FVector3d(IsContainedWidth && IsContainedHeight, IsContainedHeight && IsContainedLength, IsContainedLength && IsContainedWidth);

	bool Contained = (CollisionResNormal.X + CollisionResNormal.Y + CollisionResNormal.Z) > 0;


	

	FVector TransformedNormal = WorldRotation.RotateVector(CollisionResNormal);




	float normalDir = 1 + ((TransformedNormal.Dot(CamDir) > 0.0f) * -2.0f);
	TransformedNormal *= normalDir;

	FVector ResolvedPosition = PlacementPosition + TransformedNormal * (PlacementSize);
	SetActorLocation(ResolvedPosition);
	FVector TrueNormalSigned = CollisionResNormal * normalDir;
	bool CeilingCheck = roundf(TrueNormalSigned.Dot(FVector::UpVector)) != 0.0f;
	
	


	FVector currentAxisUp = FVector::UpVector * (1.0f - CeilingCheck) + FVector::RightVector * CeilingCheck;

	FVector axisOfRotation = (CollisionResNormal.Cross(currentAxisUp)).GetAbs();

	FVector TransFormedAxisOfRotation = TransformedNormal.Cross(currentAxisUp);

	DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + AlignmentVector * FVector(700.0f, 700.0f, 700.0f), FColor::Red);




	bool CheckOppositeRotation = roundf(TransFormedAxisOfRotation.Dot(axisOfRotation)) == 0.0f;

	FVector opposite = (axisOfRotation.Cross(currentAxisUp)) * ((float)CheckOppositeRotation);




	VectorRegister4Float RoundedNormal = VectorRound(MakeVectorRegisterFloat(TransformedNormal.X, TransformedNormal.Y, TransformedNormal.Z, 0.0f));
	FVector TransformNormalRounded = FVector();
	VectorStoreFloat3(RoundedNormal, &TransformNormalRounded);


	FVector AllowedDirectionSign = (FacingDirSum *(1.0f-ShouldSignAllowedDirection)) + (FacingDirSum * (TransformNormalRounded * ShouldSignAllowedDirection));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("rounded normal multipled by facing dir sum")));

	if (CheckOppositeRotation) {
		
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("opposite rotation")));
		axisOfRotation = (axisOfRotation.Cross(currentAxisUp)) * (1.0f - CeilingCheck) + axisOfRotation * CeilingCheck;
		
	}

	float CheckValidSurfaceDot = roundf(TransformNormalRounded.Dot((AllowedDirectionSign)));

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("check valid surface dot %f"), CheckValidSurfaceDot));

	bool IsCorrectSurfaceDir = CheckValidSurfaceDot > 0.0f;
	if (!Contained || !IsCorrectSurfaceDir) {
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Tower cannot be placed on this surface")));
		SetActorRotation(FRotator());
		/*	SetActorRotation(GetActorRotation() * !(Contained && IncorrectSurfaceDir));*/

		return false;
	}

	DrawDebugLine(GetWorld(), PlacementPosition, PlacementPosition + axisOfRotation * FVector(400.0f, 400.0f, 400.0f), FColor::Yellow);

	float AlignementDot = TransformedNormal.Dot(AlignmentVector);
	FVector AlignedAlignmentVector = WorldRotation.RotateVector(AlignmentVector);

	double AlignmentAngle = 0.0f;

	FVector AlignmentCross = TransformedNormal.Cross(AlignmentVector) * AlignmentAxis;
	float AlignmentCrossSum = AlignmentCross.X + AlignmentCross.Y + AlignmentCross.Z;
	AlignmentAngle = -atan2(AlignmentCrossSum, AlignementDot);
	bool AlignementAngleGreater = AlignmentAngle != 0.0f;


	//AlignedAxisOfRotation = axisOfRotation * (1.0f - ((float)AlignementAngleGreater)) +  AlignmentAxisCros * ((float)AlignementAngleGreater);

	float anglePicthDot = TransformedNormal.Dot(FVector::UpVector);
	FVector pitchCross = TransformedNormal.Cross(FVector::UpVector) * axisOfRotation.GetAbs();
	float anglePitchCross = pitchCross.X + pitchCross.Y + pitchCross.Z;


	if (AlignmentVector != FVector::ZeroVector && AlignmentAngle != 0.0f) {

		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Alignment angle not equal to zero "), AlignmentAngle)); 
		FVector AlignmentAxisCros = AlignmentAxis.Cross(AlignmentVector);
		//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Magenta, FString::Printf(TEXT("alignment axis cross after alignment check X:%f Y:%f Z:%f  "), AlignmentAxisCros.X, AlignmentAxisCros.Y, AlignmentAxisCros.Z));
		FQuat AligmentRotation = FQuat(AlignmentAxis, AlignmentAngle);

		FVector rotatedAlignementVector = AligmentRotation.RotateVector(AlignmentVector);
		double PitchAngleForAlingment = atan2(anglePitchCross, anglePicthDot);

		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("pitch angle for alignmen :%f"), PitchAngleForAlingment));

		FQuat PicthRotationForAlignment = FQuat(AlignmentAxisCros, abs(PitchAngleForAlingment));
		SetActorRotation(AligmentRotation.Rotator() + PicthRotationForAlignment.Rotator());

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Is correct surface %d"), (int)IsCorrectSurfaceDir));
			
		return true;

	}


	FQuat rotationForAxis = FQuat(FVector(0.0f, 0.0f, surfaceTransform.Rotator().GetComponentForAxis(EAxis::Z)), surfaceTransform.GetRotation().Euler().Z);
	FVector AxisOfRotationSkewed = rotationForAxis.RotateVector(axisOfRotation);
	FVector trueAxisOfRotation = CollisionResNormal.Cross(currentAxisUp);
	VectorRegister4 AxisRotationNoSkewStore = VectorRound(MakeVectorRegisterFloat(axisOfRotation.X, axisOfRotation.Y, axisOfRotation.Z, 0.0f));

	VectorStoreFloat3(AxisRotationNoSkewStore, &AxisOfRotationSkewed);


	FVector PitchAxis = currentAxisUp.Cross(FVector::ForwardVector);
	FVector test = TransformedNormal.Cross(FVector::UpVector);
	FVector pitchCrossTest = TransformedNormal.Cross(FVector::UpVector);


	double angle = atan2(anglePitchCross, anglePicthDot);
	double angleDeg = FMath::RadiansToDegrees(angle);


	FRotator RotatorPitch = (FRotator(angleDeg * axisOfRotation.Y, angleDeg * axisOfRotation.Z, angleDeg * axisOfRotation.X));

	SetActorRotation(RotatorPitch);



	FVector actorUp = GetActorUpVector();

	//yaws

	if (CheckOppositeRotation && CeilingCheck) {
		CollisionResNormal = trueAxisOfRotation;

		trueAxisOfRotation = currentAxisUp;
		currentAxisUp = FVector::UpVector;


	}





	FVector AtanSinRatioYaw = actorUp.Cross(TransformedNormal);

	FVector CrossForYRatio = (CollisionResNormal.Cross(trueAxisOfRotation).GetAbs());
	FVector AtanYRatio = AtanSinRatioYaw * CrossForYRatio;
	FVector crossForNormal = (CollisionResNormal.Cross(currentAxisUp).GetAbs() * (1.0f - CheckOppositeRotation)) + axisOfRotation * CheckOppositeRotation;
	FVector YRatioForNormal = (TransformedNormal)*crossForNormal;

	FVector compare = (GetActorUpVector() * CrossForYRatio);

	bool IsNotNegative = (AtanYRatio.X + AtanYRatio.Y + AtanYRatio.Z) > 0.0f && (YRatioForNormal.X + YRatioForNormal.Y + YRatioForNormal.Z) > 0.0f ||
		(AtanYRatio.X + AtanYRatio.Y + AtanYRatio.Z) < 0.0f && (YRatioForNormal.X + YRatioForNormal.Y + YRatioForNormal.Z) < 0.0f;

	float YRatio = (YRatioForNormal.X + YRatioForNormal.Y + YRatioForNormal.Z);

	float YRatioNegate = ((float)IsNotNegative) * 2.0f - 1.0f;
	float XRatio = actorUp.Dot(TransformedNormal);
	double YawAtan = atan2(YRatio * YRatioNegate, XRatio) * (XRatio != 0.0f);
	float angleYaw = (acosf(actorUp.Dot(TransformedNormal)));

	FQuat YawRot = FQuat(currentAxisUp, YawAtan);

	FVector YawRotatedUp = YawRot.RotateVector(actorUp);

	FVector finalRot = YawRot.RotateVector(actorUp);
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Final angles pitch %f yaw %f roll %f "), angleDeg, FMath::RadiansToDegrees(YawAtan)));
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("final rot  %f %f %f"), finalRot.X, finalRot.Y, finalRot.Z));
	DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + TransformedNormal * FVector(700.0f, 700.0f, 700.0f), FColor::Blue);
	DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + AlignedAlignmentVector * FVector(700.0f, 700.0f, 700.0f), FColor::Green);
	SetActorRotation(RotatorPitch + YawRot.Rotator());
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Is correct surface %d"), (int)IsCorrectSurfaceDir));
	return true;
} 

void ATowePrePlaceObjectHelper::DisableTick() {

	PrimaryActorTick.SetTickFunctionEnable(false);

}