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
	
	
}



// Called every frame
void ATowePrePlaceObjectHelper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int ATowePrePlaceObjectHelper::GetTowerCost()
{
	return TowerCost;
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




// this method is used to resolve the tower placement based on a rotated or axis aligned box that the player is looking at 
// within their placement range 
bool ATowePrePlaceObjectHelper::ResolvePlacement(FVector& SurfaceBoxExtents, FVector& SurfacePos, FVector& PlacementPosition, FVector& CamDir, FVector& CamPos, FTransform& surfaceTransform)
{

	// min and max for box containing surface	
	FVector PlacementBox = GetPlacementColliderHalfExtents();
	// transofmr the towrr placement position back to its local space on the local space surface
	FVector LocalPlacementPosition = (PlacementPosition - SurfacePos);
	// get the world rotation of the surface 
	FQuat WorldRotation = surfaceTransform.GetRotation();

	
	FQuat WorldRotExcludePitch = FQuat(WorldRotation.X, WorldRotation.Y, WorldRotation.Z, WorldRotation.W);
	// resablish the inverse rotation of the surface to rotate the placement vector and translate it back to a local point in the 
	//local space of the surface we are placing on 
	VectorRegister4 LocalTowerTest4 = (VectorQuaternionInverseRotateVector(MakeVectorRegister(WorldRotExcludePitch.X, WorldRotExcludePitch.Y, WorldRotExcludePitch.Z, WorldRotExcludePitch.W),
		MakeVectorRegister(LocalPlacementPosition.X, LocalPlacementPosition.Y, LocalPlacementPosition.Z, (double)0.0f)));


	FVector LocalTowerTestPos = FVector();
	VectorStoreFloat3(LocalTowerTest4, &LocalTowerTestPos);
	// establish the min and max for the placement box of the tower to determine if it can fit on the surface
	FVector TowerMin = LocalTowerTestPos + FVector(-PlacementBox.X, -PlacementBox.Y, -PlacementBox.Z);
	FVector TowerMax = LocalTowerTestPos + FVector(PlacementBox.X, PlacementBox.Y, PlacementBox.Z);
	// get the world min and max for the placement box of the tower
	// get the min and max of the surface at the origin
	FVector LocalBoxMin = -SurfaceBoxExtents;
	FVector LocalBoxMax = SurfaceBoxExtents;


	



	//is it contained in width 
	bool IsContainedWidth = TowerMin.Y >= LocalBoxMin.Y && TowerMax.Y <= LocalBoxMax.Y;

	//is it contained in height
	bool IsContainedHeight = TowerMin.Z >= LocalBoxMin.Z && TowerMax.Z <= LocalBoxMax.Z;

	// is it contained in length
	bool IsContainedLength = TowerMin.X >= LocalBoxMin.X && TowerMax.X <= LocalBoxMax.X;

	// establish the collision normal to resolve the placement of the tower based on where its position was on the local space surface of the box 
	FVector3d CollisionResNormal = FVector3d(IsContainedWidth && IsContainedHeight, IsContainedHeight && IsContainedLength, IsContainedLength && IsContainedWidth);
	// if we are containe din at least two axis 
	bool Contained = (CollisionResNormal.X + CollisionResNormal.Y + CollisionResNormal.Z) > 0;


	
	// get the rotated normal of the surface we are placing on 
	FVector TransformedNormal = WorldRotation.RotateVector(CollisionResNormal);


	
	// check if we need to invert the surface normal based on the cameras looking direction
	float normalDir = 1 + ((TransformedNormal.Dot(CamDir) > 0.0f) * -2.0f);
	TransformedNormal *= normalDir;
	// push the tower along the resolved colllsion normal so it isnt clipping into the surface
	FVector ResolvedPosition = PlacementPosition + TransformedNormal * (PlacementSize);
	SetActorLocation(ResolvedPosition);
	// get the normal in local space signed based on the world space normal
	FVector TrueNormalSigned = CollisionResNormal * normalDir;
	// used to check if we are looking at a ceiling as the axis we use for rotation will change 
	bool CeilingCheck = roundf(TrueNormalSigned.Dot(FVector::UpVector)) != 0.0f;
	
	

	// establish are local space axes of the we will use to align the tower in the local space as we have 
	// its position on the surface in local space
	FVector currentAxisUp = FVector::UpVector * (1.0f - CeilingCheck) + FVector::RightVector * CeilingCheck;
	// get the axis of rotation we will use in pitch
	FVector axisOfRotation = (CollisionResNormal.Cross(currentAxisUp)).GetAbs();
	// get the transofrmed axis of rotation in world space 
	FVector TransFormedAxisOfRotation = TransformedNormal.Cross(currentAxisUp);




	// if our local acis of rotation is 90 degrees to our true world space axis of rotation we need to flip our axis of roatation
	// we established in local space
	bool CheckOppositeRotation = roundf(TransFormedAxisOfRotation.Dot(axisOfRotation)) == 0.0f;

	FVector opposite = (axisOfRotation.Cross(currentAxisUp)) * ((float)CheckOppositeRotation);



	// get the transformed world space normal rounded to elimnate decimals 
	VectorRegister4Float RoundedNormal = VectorRound(MakeVectorRegisterFloat(TransformedNormal.X, TransformedNormal.Y, TransformedNormal.Z, 0.0f));
	FVector TransformNormalRounded = FVector();
	VectorStoreFloat3(RoundedNormal, &TransformNormalRounded);

	// check if the tower has restrictions on where it can be placed 
	FVector AllowedDirectionSign = (FacingDirSum *(1.0f-ShouldSignAllowedDirection)) + (FacingDirSum * (TransformNormalRounded * ShouldSignAllowedDirection));
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("rounded normal multipled by facing dir sum")));
	// flip axis of rotation based on if we are looking at a ceiling and if we need to use the opposite axis of rotation
	if (CheckOppositeRotation) {
		
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("opposite rotation")));
		axisOfRotation = (axisOfRotation.Cross(currentAxisUp)) * (1.0f - CeilingCheck) + axisOfRotation * CeilingCheck;
		
	}
	// check if the surface placement for the tower is valid and it can be placed on the surface using the dot product between
	// the rounded normal and the signed allowed direction vector for the tower
	float CheckValidSurfaceDot = roundf(TransformNormalRounded.Dot((AllowedDirectionSign)));

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("check valid surface dot %f"), CheckValidSurfaceDot));
	// if the tower is not contained or we have an incorrect surface it cant be placed
	bool IsCorrectSurfaceDir = CheckValidSurfaceDot > 0.0f;
	if (!Contained || !IsCorrectSurfaceDir) {
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Tower cannot be placed on this surface")));
		SetActorRotation(FRotator());
		/*	SetActorRotation(GetActorRotation() * !(Contained && IncorrectSurfaceDir));*/

		return false;
	}

	DrawDebugLine(GetWorld(), PlacementPosition, PlacementPosition + axisOfRotation * FVector(400.0f, 400.0f, 400.0f), FColor::Yellow);

	// if the tower needs to be aligned to the surface before we rotate it  we establish its alignment rotation here 
	float AlignementDot = TransformedNormal.Dot(AlignmentVector);
	FVector AlignedAlignmentVector = WorldRotation.RotateVector(AlignmentVector);

	double AlignmentAngle = 0.0f;

	FVector AlignmentCross = TransformedNormal.Cross(AlignmentVector) * AlignmentAxis;
	float AlignmentCrossSum = AlignmentCross.X + AlignmentCross.Y + AlignmentCross.Z;
	AlignmentAngle = -atan2(AlignmentCrossSum, AlignementDot);
	bool AlignementAngleGreater = AlignmentAngle != 0.0f;


	//AlignedAxisOfRotation = axisOfRotation * (1.0f - ((float)AlignementAngleGreater)) +  AlignmentAxisCros * ((float)AlignementAngleGreater);

	// establish the cos and sin of the angle between the local up vector of the tower 
	// as we are algining it to the surface in local space
	float anglePicthDot = TransformedNormal.Dot(FVector::UpVector);
	FVector pitchCross = TransformedNormal.Cross(FVector::UpVector) * axisOfRotation.GetAbs();
	// this will extract sin of the angle between the up vector and the  normal
	float anglePitchCross = pitchCross.X + pitchCross.Y + pitchCross.Z;

	
	if (AlignmentVector != FVector::ZeroVector && AlignmentAngle != 0.0f) {

		// this is executed if the tower need to be aligned to the surface before the rotation is performed 
		// requriing a different sequence of rotation

		// get the cross product between the vector we use to detect if the tower is missaligned 
		// and the vector we use to rotate the tower and align it which will give us our axis of rotation we need 
		// to rotate and pitch the tower 
		FVector AlignmentAxisCros = AlignmentAxis.Cross(AlignmentVector);
		FQuat AligmentRotation = FQuat(AlignmentAxis, AlignmentAngle);

		FVector rotatedAlignementVector = AligmentRotation.RotateVector(AlignmentVector);
		double FinalAngleForAlignment = atan2(anglePitchCross, anglePicthDot);


		FQuat FinalRotationForAlignment = FQuat(AlignmentAxisCros, abs(FinalAngleForAlignment));
		
		// once the alignement is taken care of all we need to do is rotate the tower in the left over axis
		// which could be pitch yaw or roll depending on what the alignment axis and alignemnt vector was
		SetActorRotation(AligmentRotation.Rotator() + FinalRotationForAlignment.Rotator() );

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Is correct surface %d"), (int)IsCorrectSurfaceDir));
			
		return true;

	}

	// if the tower didint require any specifc alignment we execute a generic rotation algorithm for the tower
	//
	FQuat rotationForAxis = FQuat(FVector(0.0f, 0.0f, surfaceTransform.Rotator().GetComponentForAxis(EAxis::Z)), surfaceTransform.GetRotation().Euler().Z);
	FVector AxisOfRotationSkewed = rotationForAxis.RotateVector(axisOfRotation);
	FVector trueAxisOfRotation = CollisionResNormal.Cross(currentAxisUp);
	VectorRegister4 AxisRotationNoSkewStore = VectorRound(MakeVectorRegisterFloat(axisOfRotation.X, axisOfRotation.Y, axisOfRotation.Z, 0.0f));

	VectorStoreFloat3(AxisRotationNoSkewStore, &AxisOfRotationSkewed);

   
	// get the angle between the transformed local space normal and our current actor up vector 
	FVector PitchAxis = currentAxisUp.Cross(FVector::ForwardVector);
	FVector test = TransformedNormal.Cross(FVector::UpVector);
	FVector pitchCrossTest = TransformedNormal.Cross(FVector::UpVector);
	double angle = atan2(anglePitchCross, anglePicthDot);
	double angleDeg = FMath::RadiansToDegrees(angle);

	// establish a rotator to picth the tower andalign its up vector to the transformed normal of the surface
	FRotator RotatorPitch = (FRotator(angleDeg * axisOfRotation.Y, angleDeg * axisOfRotation.Z, angleDeg * axisOfRotation.X));

	SetActorRotation(RotatorPitch);


	// get the newly pitched up vectors
	FVector actorUp = GetActorUpVector();

	//adjust the rotation axes for yaw if their was an opposite rotation required compared to what we got in local space

	if (CheckOppositeRotation && CeilingCheck) {
		CollisionResNormal = trueAxisOfRotation;
		trueAxisOfRotation = currentAxisUp;
		currentAxisUp = FVector::UpVector;

	}




    // establish the angle in sin of the angle left that we need to use to get the correct rotation to fully align our seleves in yaw 
	// with the transformed normal of the surface  
	FVector AtanSinRatioYaw = actorUp.Cross(TransformedNormal);
	// we only want to extract the sin of the angle in the axis we ant to rotate on so we perform a cross product between 
	// the local space normal and the axis of rotation that we established for the pitch to get the axis of rotation we need for the yaw 
	FVector CrossForYRatio = (CollisionResNormal.Cross(trueAxisOfRotation).GetAbs());
	FVector AtanYRatio = AtanSinRatioYaw * CrossForYRatio; // elminate the sin of the angle in all other axis except the one we want
	// invert the axis of rotation if it was the opposite to what we got in local space chaning the cross product we use to extract the sin of the
	
	FVector crossForNormal = (CollisionResNormal.Cross(currentAxisUp).GetAbs() * (1.0f - CheckOppositeRotation)) + axisOfRotation * CheckOppositeRotation;
	// extract the direction of the normal in the axis we need for yaw 
	FVector YRatioForNormal = (TransformedNormal)*crossForNormal;

	// check if we need to invert the sin of the angle we established above 
	bool IsNotNegative = (AtanYRatio.X + AtanYRatio.Y + AtanYRatio.Z) > 0.0f && (YRatioForNormal.X + YRatioForNormal.Y + YRatioForNormal.Z) > 0.0f ||
		(AtanYRatio.X + AtanYRatio.Y + AtanYRatio.Z) < 0.0f && (YRatioForNormal.X + YRatioForNormal.Y + YRatioForNormal.Z) < 0.0f;
	// extract the sin of the angle in the axis we need to yaw around 
	float YRatio = (YRatioForNormal.X + YRatioForNormal.Y + YRatioForNormal.Z);
	// invert the unsigned angle in sin that we extracted if the direction ins the axis we are yawring around is negative 
	// for the trasnformed normal
	float YRatioNegate = ((float)IsNotNegative) * 2.0f - 1.0f;
	float XRatio = actorUp.Dot(TransformedNormal);
	double YawAtan = atan2(YRatio * YRatioNegate, XRatio) * (XRatio != 0.0f); // if the dot product was already algined we dont need to yaw
	// get the angle we need in yaw based on the ratio in x and y we established between our pitched 
	// actor up vector and our transformed normal
	float angleYaw = (acosf(actorUp.Dot(TransformedNormal)));

	// establish a quaternion with the angle in yaw that we derived
	FQuat YawRot = FQuat(currentAxisUp, YawAtan);

	FVector YawRotatedUp = YawRot.RotateVector(actorUp);

	FVector finalRot = YawRot.RotateVector(actorUp);

	SetActorRotation(RotatorPitch + YawRot.Rotator()  );
	return true;
} 

void ATowePrePlaceObjectHelper::DisableTick() {

	PrimaryActorTick.SetTickFunctionEnable(false);

}