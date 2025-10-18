// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerBase.h"

// Sets default values
ATowerBase::ATowerBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxColliderForObjectPlacement = CreateDefaultSubobject<UBoxComponent>(TEXT("Box collider for placement"));
	RootComponent = BoxColliderForObjectPlacement;
	TriggerRangeBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box For Range"));

	TriggerRangeBox->SetupAttachment(RootComponent);

    

}

// Called when the game starts or when spawned
void ATowerBase::BeginPlay()
{




}






FVector ATowerBase::GetPlacementColliderHalfExtents()
{
	return  BoxColliderForObjectPlacement->GetCollisionShape().GetExtent();

}

void ATowerBase::ResolvePlacement(FVector SurfaceBoxExtents, FVector SurfacePos, FVector PlacementPosition, FVector CamDir,FVector CamPos,FTransform surfaceTransform)
{


	// min and max for box containing surface

	
	//FBox box = FBox::BuildAABB(SurfacePos, SurfaceHalfExtents); 
	//GLog->Log(FString::Printf(TEXT("surface min %f %f %f"), SurfaceMin.X,SurfaceMin.Y, SurfaceMin.Z));
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("surface min %f %f %f"), SurfaceMin.X, SurfaceMin.Y, SurfaceMin.Z));
	FVector PlacementBox = GetPlacementColliderHalfExtents();
	FVector LocalPlacementPosition = (PlacementPosition - SurfacePos);
	FQuat WorldRotation = surfaceTransform.GetRotation(); 
	
	
	FQuat WorldRotExcludePitch= FQuat(WorldRotation.X, WorldRotation.Y, WorldRotation.Z, WorldRotation.W);
	VectorRegister4 LocalTowerTest4 = (VectorQuaternionInverseRotateVector(MakeVectorRegister(WorldRotExcludePitch.X, WorldRotExcludePitch.Y, WorldRotExcludePitch.Z, WorldRotExcludePitch.W),
		MakeVectorRegister(LocalPlacementPosition.X, LocalPlacementPosition.Y, LocalPlacementPosition.Z, (double)0.0f)));
	FVector InvertedCamDir = -CamDir;
	
	FVector RotatedCamDir = -CamDir;
	//DrawDebugLine(GetWorld(), FVector::ZeroVector, PlacementPosition + RotatedCamDir * FVector(200.0f, 200.0f, 200.0f), FColor::Cyan);
	
	//min and max of tower placement box 
	FVector LocalTowerTestPos = FVector();
	VectorStoreFloat3(LocalTowerTest4, &LocalTowerTestPos);
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("local pos %f %f %f"),dir.X,dir.Y
	//	,dir.Z ));
	/*GLog->Log(FString::Printf(TEXT("local box pos  X:%f Y:%f Z:%f"), LocalBoxPos.X, LocalBoxPos.Y, LocalBoxPos.Z));
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("local box pos rot X:%f Y:%f Z:%f"), LocalBoxPos.X, LocalBoxPos.Y, LocalBoxPos.Z));
	GLog->Log(FString::Printf(TEXT("local tower pos  X:%f Y:%f Z:%f"), LocalTowerTestPos.X,LocalTowerTestPos.Y, LocalTowerTestPos.Z));
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("local box pos rot X:%f Y:%f Z:%f"), LocalBoxPos.X, LocalBoxPos.Y, LocalBoxPos.Z));

	*/

    

	


	FVector TowerMin = LocalTowerTestPos + FVector(-PlacementBox.X, -PlacementBox.Y, -PlacementBox.Z);
	FVector TowerMax = LocalTowerTestPos + FVector(PlacementBox.X, PlacementBox.Y, PlacementBox.Z);
	FVector TowerMinWorld =  PlacementPosition + surfaceTransform.Rotator().RotateVector(  FVector(-PlacementBox.X, -PlacementBox.Y, -PlacementBox.Z));
	FVector TowerMaxWorld = PlacementPosition + surfaceTransform.Rotator().RotateVector( FVector(PlacementBox.X, PlacementBox.Y, PlacementBox.Z));
	FVector LocalBoxMin = -SurfaceBoxExtents;
	FVector LocalBoxMax = SurfaceBoxExtents; 
	FVector Range = LocalBoxMax - LocalBoxMin;
	FVector WorldBoxMax = SurfacePos + surfaceTransform.GetRotation().RotateVector(LocalBoxMax); 
	FVector WorldBoxMin = SurfacePos + surfaceTransform.GetRotation().RotateVector(LocalBoxMin);  


	FBox LocalBox = FBox::BuildAABB(SurfacePos, SurfaceBoxExtents);


	FVector worldRange = WorldBoxMax - WorldBoxMin;
	



	//float BoundsMinY =  std::min(WorldBoxMax.Y, WorldBoxMin.Y); 
	//float BoundsMinX = std::min(WorldBoxMax.X, WorldBoxMin.X);
	//float BoundsMinZ = std::min(WorldBoxMax.Z, WorldBoxMin.Z);

	//float BoundsMaxY = WorldBoxMax.Y * (WorldBoxMax.Y > BoundsMinY) + WorldBoxMin.Y * (WorldBoxMin.Y > BoundsMinY);
	//float BoundsMaxX = WorldBoxMax.X * (WorldBoxMax.X > BoundsMinX) + WorldBoxMin.X * (WorldBoxMin.X > BoundsMinX);
	//float BoundsMaxZ = WorldBoxMax.Z * (WorldBoxMax.Z > BoundsMinZ) + WorldBoxMin.Z * (WorldBoxMin.Z > BoundsMinZ);



	//float PercentBoundsY = ((PlacementPosition.Y - BoundsMinY) / ( BoundsMaxY - BoundsMinY));
	//float PercentBoundsX = ((PlacementPosition.X - BoundsMinX) / (BoundsMaxX - BoundsMinX));
	//float PercentBoundsZ = ((PlacementPosition.Z - BoundsMinZ) / (BoundsMaxZ - BoundsMinZ));
	
	/*PercentBoundsY *= ((float(PlacementPosition.Y > SurfacePos.Y )) * 2.0f - 1.0f);
	PercentBoundsX *= ((float(PlacementPosition.X > SurfacePos.X )) * 2.0f - 1.0f);
	PercentBoundsZ *= ((float(PlacementPosition.Z > SurfacePos.Z )) * 2.0f - 1.0f);*/
	
	


	

	/*FVector LocalPlacementPositionPercent = FVector(PercentBoundsX ,PercentBoundsY,PercentBoundsZ) * SurfaceBoxExtents; 


    LocalPlacementPosition.X *= (((PlacementPosition.X > SurfacePos.X) * 2.0f) - 1.0f);
	LocalPlacementPosition.Y *= (((PlacementPosition.Y > SurfacePos.Y) * 2.0f) - 1.0f );
	LocalPlacementPosition.Z *= (((PlacementPosition.Z > SurfacePos.Z) * 2.0f) - 1.0f );*/
	
	//potential solution to make placement position in lcoal space would be to use the percentage of the Bounds 
	//that we are along in world space and then translate from the origin using those instead of trying to 
	//a reverse transfomration which ends up being skewed due to us sometimes being further into the surface in world 
	//than we would ever be in local space
	//float minYPercentX = std::min(WorldBoxMin.X, WorldBoxMin.X);
	//float minYPercentY = std::min(WorldBoxMin.Y,WorldBoxMin.Y);
	//float minYPercentZ = std::min(WorldBoxMin.Z, WorldBoxMin.Z);

	


	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("box extents %f %f %f"), SurfaceBoxExtents.X, SurfaceBoxExtents.Y, SurfaceBoxExtents.Z));
	//local min
	//DrawDebugLine(GetWorld(), FVector::ZeroVector,  LocalTowerTestPos , FColor::Red);
	DrawDebugSphere(GetWorld(), LocalTowerTestPos, 50.0f, 8, FColor::Magenta);
	//DrawDebugSphere(GetWorld(), LocalTowerTestPos, 50.0f, 8, FColor::Magenta);
	/*DrawDebugSphere(GetWorld(), LocalPlacementPositionPercent, 50.0f, 8, FColor::Red);*/
	DrawDebugBox(GetWorld(), FVector(LocalBoxMin.X,LocalBoxMin.Y,LocalBoxMin.Z  ), FVector(20.0f, 20.0f, 20.0f), FColor::Yellow);
	DrawDebugBox(GetWorld(), FVector(LocalBoxMax.X, LocalBoxMax.Y, LocalBoxMax.Z ), FVector(20.0f, 20.0f, 20.0f), FColor::Magenta);
	DrawDebugSphere(GetWorld(), TowerMin, 20.0f, 8, FColor::Emerald);
	DrawDebugSphere(GetWorld(), TowerMax, 20.0f, 8, FColor::Emerald);
	DrawDebugSphere(GetWorld(), TowerMinWorld, 20.0f, 8, FColor::Emerald);
	DrawDebugSphere(GetWorld(), TowerMaxWorld, 20.0f, 8, FColor::Emerald); 
	DrawDebugSphere(GetWorld(),  WorldBoxMin, 20.0f, 8, FColor::Blue); 
	DrawDebugSphere(GetWorld(),  WorldBoxMax, 20.0f, 8, FColor::Emerald);

	/*DrawDebugLine(GetWorld(), WorldBoxMin, TowerMinWorld, FColor::Red);
	DrawDebugLine(GetWorld(), WorldBoxMax, TowerMaxWorld, FColor::Magenta);*/
	//FVector SurfaceTransformRot surfaceTransform.GetRotation().Euler();
	//width

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("placement position percents  X:%f Y: %f z: %f"), PercentBoundsX, PercentBoundsY, PercentBoundsZ));

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("placement position bounds  X:%f Y: %f z: %f"), LocalPlacementPositionPercent.X, LocalPlacementPositionPercent.Y, LocalPlacementPositionPercent.Z));


	/*GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("min for box X:%f Y:%f Z:%f"), WorldBoxMin.X, WorldBoxMin.Y, WorldBoxMin.Z));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("max for box X:%f Y:%f Z:%f"), WorldBoxMax.X, WorldBoxMax.Y, WorldBoxMax.Z));*/


	//width 



	bool IsContainedWidth = TowerMin.Y >= LocalBoxMin.Y && TowerMax.Y <= LocalBoxMax.Y;  
		/*((WorldBoxMin.Y > WorldBoxMax.Y) && (TowerMinWorld.Y >= WorldBoxMax.Y && TowerMaxWorld.Y <= WorldBoxMin.Y));
		 */
	//height
	bool IsContainedHeight = TowerMin.Z >= LocalBoxMin.Z && TowerMax.Z <= LocalBoxMax.Z;
		/*((WorldBoxMin.Z > WorldBoxMax.Z) && (TowerMinWorld.Z >= WorldBoxMax.Z && TowerMaxWorld.Z <= WorldBoxMin.Z));
		*/
	//length
	bool IsContainedLength = TowerMin.X >= LocalBoxMin.X && TowerMax.X <= LocalBoxMax.X;
		/*((WorldBoxMin.X > WorldBoxMax.X) && (TowerMinWorld.X >= WorldBoxMax.X && TowerMaxWorld.X <= WorldBoxMin.X));
		*/


	FVector3d CollisionResNormal = FVector3d(IsContainedWidth && IsContainedHeight, IsContainedHeight && IsContainedLength, IsContainedLength && IsContainedWidth);
	
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("normal x: %f y: %f z: %f"), CollisionResNormal.X, CollisionResNormal.Y, CollisionResNormal.Z));



	////  invert collision normal based on direction the camera is looking 
	////  as we start by assuming that the collision normal is positive 
	//// this inversion esnures that the normal points out of the surface 
	//// so we dont shift the tower into it when resolving the placement position
	
	//FVector tangent = InvertedCamDir.Cross(FVector::UpVector); 

	FVector TransformedNormal = WorldRotation.RotateVector( CollisionResNormal);
	


	float normalDir = 1 + ((TransformedNormal.Dot(CamDir) > 0.0f) * -2.0f);
	TransformedNormal *= normalDir;
	FVector TrueNormalSigned = CollisionResNormal * normalDir; 

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("transformedNormal X:%f Y: %f z: %f"), TransformedNormal.X, TransformedNormal.Y, TransformedNormal.Z));
	//DrawDebugLine(GetWorld(), PlacementPosition, PlacementPosition + TransformedNormal * FVector(200.0f, 200.0f, 200.0f),FColor::Blue);
	
	//// resolve placement position using the placement box extents multiplied by dir of collison normal(direction of the placement surface) to get correct direction
	//// for the shift 
	FVector ResolvedPosition = PlacementPosition + TransformedNormal * (PlacementBox.Z ) ;
	//GLog->Log(FString::Printf(TEXT("Collision res normal X:%f Y:%f Z:%f"), CollisionResNormal.X , CollisionResNormal.Y , CollisionResNormal.Z));
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("Collision res normal scaled X:%f Y:%f Z:%f"), CollisionResNormal.X , CollisionResNormal.Y , CollisionResNormal.Z ));
	///// this dot product is used to check if we need to swap the axis of rotation as there is a case 
	//// where the collision normal will want us to not rotate(when it is 0,0,-1) 
	//// i.e when the player is looking at a ceiling, when we actually need to rotate around the y axis 
	//// the dot product will be used to check for this case as the collision normal when the player is loooking to the ceiling 
	//// will be 0,0,-1 and the up vector we use is 0,0,1 meaning the result of the dot product in this case will be -1 
	//// so we know that we need to pitch the tower -180 to flip it onto the ceiling  rather than using the axis of rotation derrived from the collision normal 
	//// which will actually be 0,0,0 in this case(no rotation) as we use cross product for that
	

	/*GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("rot angle %f"), angle));*/
	bool CeilingCheck = roundf(TrueNormalSigned.Dot(FVector::UpVector)) != 0.0f;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Ceiling check %d"), (int)CeilingCheck));


	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("Dot for normal direction signed %f %f %f "), TrueNormalSigned.X,TrueNormalSigned.Y,TrueNormalSigned.Z));
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("angle between  normal and local up %f"), angle));
	////GLog->Log(FString::Printf(TEXT("Dot for normal direction with up %f "), ColNormalDir));
	////GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("Dot for normal direction with up %f "), ColNormalDir));
	//// case that character is looking direclty up when placing tower meaning that we need to pitch around the Y axis instead of using the derrived axis of rotation
	//// from the cross product between the lok up vector of the tower(0,0,1) and the collision normal 
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("collision normal dot with up:%d"), (int)CeilingCheck));
	


	FVector currentAxisUp = FVector::UpVector * (1.0f - CeilingCheck) + FVector::RightVector * CeilingCheck;
	 


	FVector axisOfRotation = CollisionResNormal.Cross(currentAxisUp).GetAbs();

	FVector TransFormedAxisOfRotation = TransformedNormal.Cross(currentAxisUp);

	

	bool CheckOppositeRotation = roundf(TransFormedAxisOfRotation.Dot(axisOfRotation)) == 0.0f;  

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("check opposite rotation: %d "), (int)CheckOppositeRotation));
	FVector opposite = (axisOfRotation.Cross(currentAxisUp))*   ((float)CheckOppositeRotation);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("check opposite rotation v : %f %f %f "), opposite.X, opposite.Y, opposite.Z ));


	if (CheckOppositeRotation){
		axisOfRotation = (axisOfRotation.Cross(currentAxisUp)) *(1.0f - CeilingCheck) + axisOfRotation * CeilingCheck;
	    
	}

	//currentAxisUp = currentAxisUp * (1.0f - (CeilingCheck && CheckOppositeRotation) + opposite.Cross(currentAxisUp) * (CeilingCheck && CheckOppositeRotation));



	//(1.0f - CeilingCheck)) + (CollisionResNormal.Cross(FVector::ForwardVector) * CeilingCheck); 
	FQuat rotationForAxis = FQuat(FVector(0.0f, 0.0f, surfaceTransform.Rotator().GetComponentForAxis(EAxis::Z)), surfaceTransform.GetRotation().Euler().Z);
	FVector AxisOfRotationSkewed = rotationForAxis.RotateVector(axisOfRotation);
	FVector trueAxisOfRotation = CollisionResNormal.Cross(currentAxisUp); 
	VectorRegister4 AxisRotationNoSkewStore = VectorRound(MakeVectorRegisterFloat(axisOfRotation.X,axisOfRotation.Y,axisOfRotation.Z,0.0f));

	VectorStoreFloat3(AxisRotationNoSkewStore, &AxisOfRotationSkewed);
	float anglePicthDot = TransformedNormal.Dot(FVector::UpVector);
	FVector PitchAxis = currentAxisUp.Cross(FVector::ForwardVector);;
	FVector test = TransformedNormal.Cross(FVector::UpVector) ;
	FVector pitchCrossTest = TransformedNormal.Cross(FVector::UpVector);

	FVector pitchCross =  TransformedNormal.Cross(FVector::UpVector) * axisOfRotation.GetAbs() ;
	float anglePitchCross = pitchCross.X + pitchCross.Y + pitchCross.Z;
	

	double angle = atan2(anglePitchCross, anglePicthDot);




     
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("pitchc x %f  pitchc y %f pitchc z %f"), pitchCrossTest.X, pitchCrossTest.Y, pitchCrossTest.Z));

	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("pitch dot %f"), anglePicthDot));

	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, FString::Printf(TEXT("pitch cross dot %f"), FMath::RadiansToDegrees(anglePitchCross)));







	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("pitch dot %f  pitch cross %f pitch angle %f"), anglePicthDot, anglePitchCross, FMath::RadiansToDegrees(angle)));

	//angle *= sin(angle); 

	double angleDeg =   FMath::RadiansToDegrees(angle);



	

    /* FQuat(currentAxisUp,angle).RotateVector( CollisionResNormal.Cross(currentAxisUp)) ; */
	//DrawDebugLine(GetWorld(), PlacementPosition, PlacementPosition + up * FVector(200.0f, 200.0f, 200.0f), FColor::Magenta);


	DrawDebugLine(GetWorld(), PlacementPosition, PlacementPosition + axisOfRotation * FVector(400.0f, 400.0f, 400.0f), FColor::Yellow);
	DrawDebugLine(GetWorld(), PlacementPosition, PlacementPosition + TransFormedAxisOfRotation * FVector(400.0f, 400.0f, 400.0f), FColor::Green);

	//DrawDebugLine(GetWorld(), PlacementPosition, PlacementPosition + AxisOfRotationSkewed * FVector(400.0f, 400.0f, 400.0f), FColor::Red);


	//GLog->Log(FString::Printf(TEXT("axis rot X:%f Y:%f Z:%f"), axisOfRotation.X, axisOfRotation.Y, axisOfRotation.Z));
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("true axis rot X:%f Y:%f Z:%f"), trueAxisOfRotation.X, trueAxisOfRotation.Y, trueAxisOfRotation.Z));
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("axis rot X:%f Y:%f Z:%f"), axisOfRotation.X, axisOfRotation.Y, axisOfRotation.Z));


	//GLog->Log(FString::Printf(TEXT("axis of rotation skewed X:%f Y:%f Z:%f"), AxisOfRotationSkewed.X, AxisOfRotationSkewed.Y, AxisOfRotationSkewed.Z));
	//////GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("up rot X:%f Y:%f Z:%f"), up.X, up.Y, up.Z));

	//// taking into account z axis having different rotation(discussed above) i.e no rotation when up right and -180 rotation when tower is being placed on ceiling
	//float angle = 90.0f * ((float)ColNormalDir == 0.0f) + 180.0f * (float(ColNormalDir < 0.0f));
	////GLog->Log(FString::Printf(TEXT("rot angle %f "), angle));
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("rot angle %f "), angleDeg));
	//
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("pitcDir %f "), pitchDir));


	FRotator RotatorPitch= FRotator(angleDeg * axisOfRotation.Y  , angleDeg * axisOfRotation.Z , angleDeg * axisOfRotation.X );
	FTransform transform = FTransform(RotatorPitch, ResolvedPosition, GetActorScale());

	 
	/*GLog->Log(FString::Printf(TEXT("up rot X:%f Y:%f Z:%f"), SnapToSurface.X, SnapToSurface.Y, SnapToSurface.Z));
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("up rot X:%f Y:%f Z:%f"), SnapToSurface.X, SnapToSurface.Y, SnapToSurface.Z));
*/ 


	SetActorRotation(RotatorPitch  );



	


	// yaw 
	

	////float Yaw = ((sin(angleYaw) ));
 //   GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("angleYawSign %f"),FMath::RadiansToDegrees( YawAtan)));
	////GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("cos %f"), actorUp.Dot(TransformedNormal)));
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("angle %f"), angleDeg ));

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Yaw %f"), FMath::RadiansToDegrees(angleYaw)));
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("sinpitch %f"), FMath::RadiansToDegrees(sinofpitch)));

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("angleYaw %f"), FMath::RadiansToDegrees((angleYaw))));
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("sin %f"), sin(angle)));
	   
	//float rotSign =  (1.0f - ((GetActorUpVector().Dot(axisOfRotation) < 0.0f) * 2.0f)); 
	//float corectAngleSign = rotSign * (1.0f - CeilingCheck) + -rotSign * CeilingCheck;


	////GLog->Log(FString::Printf(TEXT("old up X:%f Y:%f Z:%f"), oldUp.X, oldUp.Y, oldUp.Z));
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("old up X:%f Y:%f Z:%f"), oldUp.X, oldUp.Y, oldUp.Z));  
	//GLog->Log(FString::Printf(TEXT("rot sign %f"),rotSign));
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("rot sign %f"),rotSign));

	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("sin of surface pitch %f  surface pitch %f yaw scalar %f"), FMath::RadiansToDegrees( fabs(sinf( FMath::DegreesToRadians( surfaceTransform.Rotator().Pitch)))), surfaceTransform.Rotator().Pitch));

	
	

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("rot angle yaw %f"), FMath::RadiansToDegrees( angleYaw * rotSign)));
	// set position
	SetActorLocation(ResolvedPosition);
	  
    //DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + GetActorUpVector() * FVector(700.0f, 700.0f, 700.0f), FColor::Green);
    //DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + currentAxisUp * FVector(700.0f, 700.0f, 700.0f), FColor::Red);

	
	//DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + axisOfRotation * FVector(700.0f, 700.0f, 700.0f), FColor::Yellow);
	//DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + GetActorForwardVector()  * FVector(700.0f, 700.0f, 700.0f), FColor::Green);
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("rotated  up X:%f Y:%f Z:%f  normal X:%f   Y:%f Z:%f   "),rotatedUp.X, rotatedUp.Y, rotatedUp.Z,TransformedNormal.X,TransformedNormal.Y,TransformedNormal.Z));

	/*GLog->Log(FString::Printf(TEXT("quat rot X:%f Y:%f Z:%f"), euler.X, euler.Y, euler.Z));
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("quat rot X:%f Y:%f Z:%f"), euler.X, euler.Y, euler.Z));*/
	// set position
	//roll
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, FString::Printf(TEXT("up X:%f Y:%f Z:%f"), TrueUp.X, TrueUp.Y, TrueUp.Z));

	

	FVector actorUp = GetActorUpVector();
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("actor up X:%f Y:%f Z:%f"), actorUp.X, actorUp.Y, actorUp.Z));

	//yaws
	FVector right = TransformedNormal.Cross(currentAxisUp);
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("right  X:%f Y:%f Z:%f"), right.X, right.Y, right.Z));
	

	//FVector YawScalerVClose = actorUp.Cross(currentAxisUp) * right.GetAbs();
	//FVector YawScalerV = right;
	
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT(" yaw scalar sub x: %f y: %f z: %f"), YawScalerV.X, YawScalerV.Y, YawScalerV.Z));
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT(" yaw scalar  x: %f y: %f z: %f"), YawScalerV.X, YawScalerV.Y, YawScalerV.Z));
	//VectorStoreFloat3(,);
	
	//float YawScalarClose = YawScalerVClose.X + YawScalerVClose.Y + YawScalerVClose.Z; 
	if (CheckOppositeRotation && CeilingCheck) {
		CollisionResNormal = trueAxisOfRotation; 
		
		trueAxisOfRotation = currentAxisUp;
		currentAxisUp =  FVector::UpVector;
	

	}

	

	FVector AtanSinRatioYaw = actorUp.Cross(TransformedNormal); 
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT(" atan ratio x: %f y: %f z: %f"), AtanSinRatioYaw.X, AtanSinRatioYaw.Y, AtanSinRatioYaw.Z));

	FVector CrossForYRatio = (CollisionResNormal.Cross(currentAxisUp)).GetAbs(); 
	CrossForYRatio = CollisionResNormal.Cross(trueAxisOfRotation).GetAbs();
	FVector AtanYRatio = AtanSinRatioYaw * CrossForYRatio;  
	FVector crossForNormal = (CollisionResNormal.Cross(currentAxisUp).GetAbs() * (1.0f- CheckOppositeRotation)) + axisOfRotation * CheckOppositeRotation ;
	FVector YRatioForNormal = (TransformedNormal) * crossForNormal;
	//YRatioForNormal = TransformedNormal * axisOfRotation;
	//YRatioForNormal = TransformedNormal * currentAxisUp;
	//FVector AtanYRatioScalar = (CrossForYRatio * TransformedNormal).GetAbs(); 
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT(" cross y ratio x: %f y: %f z: %f"), CrossForYRatio.X, CrossForYRatio.Y, CrossForYRatio.Z));
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT(" cross normal ratio x: %f y: %f z: %f"), crossForNormal.X, crossForNormal.Y, crossForNormal.Z));

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT(" cross ratio x: %f y: %f z: %f"), AtanSinRatioYaw.X, AtanSinRatioYaw.Y, AtanSinRatioYaw.Z));
	FVector compare = (GetActorUpVector() * CrossForYRatio) ;
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT(" atan ratio x: %f y: %f z: %f"), AtanSinRatioYaw.X, AtanSinRatioYaw.Y, AtanSinRatioYaw.Z));
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT(" compare x: %f y: %f z: %f"), compare.X, compare.Y, compare.Z));

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Ratios normal : %f  sin: %f "), (YRatioForNormal.X + YRatioForNormal.Y + YRatioForNormal.Z), (AtanYRatio.X + AtanYRatio.Y + AtanYRatio.Z)));

	bool IsNotNegative =   (AtanYRatio.X + AtanYRatio.Y + AtanYRatio.Z) > 0.0f && (YRatioForNormal.X + YRatioForNormal.Y + YRatioForNormal.Z) > 0.0f ||
		                   (AtanYRatio.X + AtanYRatio.Y + AtanYRatio.Z) < 0.0f && (YRatioForNormal.X + YRatioForNormal.Y + YRatioForNormal.Z) < 0.0f;
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT(" is not negative %d"), (int)IsNotNegative));
	
	float YRatio = (YRatioForNormal.X + YRatioForNormal.Y + YRatioForNormal.Z);
	
	float YRatioNegate = ((float)IsNotNegative) * 2.0f - 1.0f;
	float XRatio = actorUp.Dot(TransformedNormal);
	
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT(" yaw angle x ratio %f"),   XRatio));
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT(" yaw angle  y ratio %f"), YRatio * YRatioNegate));

	//float YawScalar = (YawScalerV.X + YawScalerV.Y + YawScalerV.Z);
	
	//DrawDebugLine(GetWorld(), PlacementPosition, PlacementPosition + TrueUp * FVector(1000.0f, 1000.0f, 1000.0f), FColor::Green);
	double YawAtan = atan2(YRatio * YRatioNegate  , XRatio) * (  XRatio != 0.0f );

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT(" yaw angle %f"), FMath::RadiansToDegrees( YawAtan)));

	float angleYaw = (acosf(actorUp.Dot(TransformedNormal)));



	FQuat YawRot = FQuat(currentAxisUp, YawAtan);





	FVector YawRotatedUp = YawRot.RotateVector(actorUp);
	FVector rollAxis =  CollisionResNormal;
	FVector rollScalarV = actorUp.Cross( YawRotatedUp); 
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("roll vector scalar: %f %f %f "), rollScalarV.X, rollScalarV.Y, rollScalarV.Z));
	
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("roll up scalar: %f %f %f "), TrueUp.X, TrueUp.Y, TrueUp.Z));
	//FVector RollYRatioCheck = TransformedNormal * currentAxisUp; 
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("yaw roll ratio check roll %f"),));


	float YawScalarRoll = ((rollAxis.X + rollAxis.Y + rollAxis.Z));
	float RollScalar = rollScalarV.X + rollScalarV.Y + rollScalarV.Z;
	float ratioRoll = YawRotatedUp.Dot(TransformedNormal);
	double Roll = atan2(RollScalar, ratioRoll);
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("yaw scalar roll %f"), YawScalarRoll));

	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("roll  %f"), Roll));
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("roll axis X:%f Y:%f Z:%f"), rollAxis.X, rollAxis.Y, rollAxis.Z));
	////GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("roll scalar: %f "), RollScalar))

	//
	FQuat RollRot = FQuat(rollAxis, Roll);

	//DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + right * FVector(400.0f, 400.0f, 400.0f), FColor::Black);

	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("cross actor up X:%f Y:%f Z:%f"), (actorUp.Cross(TransformedNormal)* currentAxisUp).X, (actorUp.Cross(TransformedNormal)* currentAxisUp).Y, (actorUp.Cross(TransformedNormal)* currentAxisUp).Z));
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("right X:%f Y:%f Z:%f"), right.X, right.Y, right.Z));

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("y scalar %f"), YawScalar));
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("xsratio %f"), YawScalar));

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("angleRoll %f"), FMath::RadiansToDegrees( roll)));
    //DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + finalRot * FVector(700.0f, 700.0f, 700.0f), FColor::Magenta);

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("cos pitch %f"),cos(angle)));
	 //GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("sin pitch %f"), FMath::RadiansToDegrees( asinf(angleYaw))));
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("final rot  %f %f %f"),finalRot.X,finalRot.Y,finalRot.Z ));
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("roll %f"), roll));
	FVector finalRot = YawRot.RotateVector( actorUp); 
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Final angles pitch %f yaw %f roll %f "), angleDeg, FMath::RadiansToDegrees(YawAtan)));
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("final rot  %f %f %f"), finalRot.X, finalRot.Y, finalRot.Z));
	DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + TransformedNormal * FVector(700.0f, 700.0f, 700.0f), FColor::Blue);
	DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + finalRot * FVector(700.0f, 700.0f, 700.0f), FColor::Magenta);
	//DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + FVector(finalRot.X,0.0f,0.0f) * FVector(700.0f, 700.0f, 700.0f), FColor::Red);
	//DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + FVector(0.0f, finalRot.Y, 0.0f) * FVector(700.0f, 700.0f, 700.0f), FColor::Green);
	//DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + FVector(0.0f, 0.0f, finalRot.Z) * FVector(700.0f, 700.0f, 700.0f), FColor::Blue);
	/*DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + FVector(TransformedNormal.X, 0.0f, 0.0f) * FVector(700.0f, 700.0f, 700.0f), FColor::Blue);
	DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + FVector(0.0f, TransformedNormal.Y, 0.0f) * FVector(700.0f, 700.0f, 700.0f), FColor::Red);
	DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + FVector(0.0f, 0.0f, TransformedNormal.Z) * FVector(700.0f, 700.0f, 700.0f), FColor::Green);
	*/
	
	//SetActorRotation(RotatorPitch+ YawRot.Rotator());
 //   

	SetActorRotation(RotatorPitch  + YawRot.Rotator());
	/*  GLog->Log(FString::Printf(TEXT("axis result rot X:%f Y:%f Z:%f"), res.X, res.Y, res.Z));
	  GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("axis result rot X:%f Y:%f Z:%f"), res.X, res.Y, res.Z));
	  */






}

void ATowerBase::OnOverLapBegin(UPrimitiveComponent* OverlapedComponent, AActor* OverlapedActor, UPrimitiveComponent* OtherComp,int32 OtherBodyIndex,bool SweepBool ,const FHitResult& HitResult) {
	
	CurrentyActive = true;
	if (ShouldGetTargets == true ) {
		
		AEnemyBase* EnemyTOHandle = Cast<AEnemyBase>(OverlapedActor);
		HandleNewEnemy(EnemyTOHandle);
	}

	
} 





void ATowerBase::CheckForEnemies(){}
void ATowerBase::HandleNewEnemy(AEnemyBase* EnemyBase){}
void ATowerBase::TowerActive() {}
void ATowerBase::DamageEnemy(AEnemyBase* enemy) {}




void ATowerBase::TowerSetUp()
{ 
	TriggerRangeBox->OnComponentBeginOverlap.AddDynamic(this,&ATowerBase::OnOverLapBegin);


}



// Called every frame
void ATowerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 

	if (CurrentyActive) {
		
		TowerActive();
        
	}



}

