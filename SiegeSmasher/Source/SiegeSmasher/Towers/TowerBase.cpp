// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerBase.h"

// Sets default values
ATowerBase::ATowerBase()
{
	
	PrimaryActorTick.bCanEverTick = true;
	BoxColliderForObjectPlacement = CreateDefaultSubobject<UBoxComponent>(TEXT("Box collider for placement"));

	RootComponent = BoxColliderForObjectPlacement;
	TriggerRangeBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box For Range"));
	TriggerRangeBox->SetupAttachment(RootComponent);   
	TriggerRangeBox->SetCollisionResponseToChannel(PlacingSurface, ECollisionResponse::ECR_Ignore);
	
	

	
}

void ATowerBase::DisableTick()
{

	PrimaryActorTick.SetTickFunctionEnable(false);
}




// Called when the game starts or when spawned
void ATowerBase::BeginPlay()
{

	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("tower begin play called")));

	WaitTimeToReset = MaxWaitTimeToReset;
	TriggerRangeBox->OnComponentBeginOverlap.AddDynamic(this, &ATowerBase::OnOverLapBegin);

	TowerSetUp();

}



void ATowerBase::TowerTimeLineEnd()
{
	RequiresReset = true;
}






FVector ATowerBase::GetPlacementColliderHalfExtents()
{
	return  BoxColliderForObjectPlacement->GetCollisionShape().GetExtent();

}

void ATowerBase::ResolvePlacement(FVector SurfaceBoxExtents, FVector SurfacePos, FVector PlacementPosition, FVector CamDir,FVector CamPos,FTransform surfaceTransform)
{



   DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + GetActorUpVector() * FVector(700.0f, 700.0f, 700.0f), FColor::Green);
   FVector ActorRight = GetActorRightVector();  
	// min and max for box containing surface	
	FVector PlacementBox = GetPlacementColliderHalfExtents();
	FVector LocalPlacementPosition = (PlacementPosition - SurfacePos);
	FQuat WorldRotation = surfaceTransform.GetRotation(); 
	
	
	FQuat WorldRotExcludePitch= FQuat(WorldRotation.X, WorldRotation.Y, WorldRotation.Z, WorldRotation.W);
	VectorRegister4 LocalTowerTest4 = (VectorQuaternionInverseRotateVector(MakeVectorRegister(WorldRotExcludePitch.X, WorldRotExcludePitch.Y, WorldRotExcludePitch.Z, WorldRotExcludePitch.W),
		MakeVectorRegister(LocalPlacementPosition.X, LocalPlacementPosition.Y, LocalPlacementPosition.Z, (double)0.0f)));
	FVector InvertedCamDir = -CamDir;
	
	FVector RotatedCamDir = -CamDir;
	
	FVector LocalTowerTestPos = FVector();
	VectorStoreFloat3(LocalTowerTest4, &LocalTowerTestPos);
	FVector TowerMin = LocalTowerTestPos + FVector(-PlacementBox.X, -PlacementBox.Y, -PlacementBox.Z);
	FVector TowerMax = LocalTowerTestPos + FVector(PlacementBox.X, PlacementBox.Y, PlacementBox.Z);
	FVector TowerMinWorld =  PlacementPosition + surfaceTransform.Rotator().RotateVector(  FVector(-PlacementBox.X, -PlacementBox.Y, -PlacementBox.Z));
	FVector TowerMaxWorld = PlacementPosition + surfaceTransform.Rotator().RotateVector( FVector(PlacementBox.X, PlacementBox.Y, PlacementBox.Z));
	FVector LocalBoxMin = -SurfaceBoxExtents;
	FVector LocalBoxMax = SurfaceBoxExtents; 
	FVector Range = LocalBoxMax - LocalBoxMin;
	FVector WorldBoxMax = SurfacePos + surfaceTransform.GetRotation().RotateVector(LocalBoxMax); 
	FVector WorldBoxMin = SurfacePos + surfaceTransform.GetRotation().RotateVector(LocalBoxMin);  

	
	DrawDebugSphere(GetWorld(), LocalTowerTestPos, 50.0f, 8, FColor::Magenta);

	DrawDebugBox(GetWorld(), FVector(LocalBoxMin.X,LocalBoxMin.Y,LocalBoxMin.Z  ), FVector(20.0f, 20.0f, 20.0f), FColor::Yellow);
	DrawDebugBox(GetWorld(), FVector(LocalBoxMax.X, LocalBoxMax.Y, LocalBoxMax.Z ), FVector(20.0f, 20.0f, 20.0f), FColor::Magenta);
	DrawDebugSphere(GetWorld(), TowerMin, 20.0f, 8, FColor::Emerald);
	DrawDebugSphere(GetWorld(), TowerMax, 20.0f, 8, FColor::Emerald);
	DrawDebugSphere(GetWorld(), TowerMinWorld, 20.0f, 8, FColor::Emerald);
	DrawDebugSphere(GetWorld(), TowerMaxWorld, 20.0f, 8, FColor::Emerald); 
	DrawDebugSphere(GetWorld(),  WorldBoxMin, 20.0f, 8, FColor::Blue); 
	DrawDebugSphere(GetWorld(),  WorldBoxMax, 20.0f, 8, FColor::Emerald);

	

	//width 
	bool IsContainedWidth = TowerMin.Y >= LocalBoxMin.Y && TowerMax.Y <= LocalBoxMax.Y;  
		
	//height
	bool IsContainedHeight = TowerMin.Z >= LocalBoxMin.Z && TowerMax.Z <= LocalBoxMax.Z;
		
	//length
	bool IsContainedLength = TowerMin.X >= LocalBoxMin.X && TowerMax.X <= LocalBoxMax.X;
	

	FVector3d CollisionResNormal = FVector3d(IsContainedWidth && IsContainedHeight, IsContainedHeight && IsContainedLength, IsContainedLength && IsContainedWidth);
	

	FVector TransformedNormal = WorldRotation.RotateVector( CollisionResNormal);
	

	float normalDir = 1 + ((TransformedNormal.Dot(CamDir) > 0.0f) * -2.0f);
	TransformedNormal *= normalDir;


	FVector FacingDirSigned =  InitialFacingDirection * normalDir;
	FVector TrueNormalSigned = CollisionResNormal * normalDir; 

	FVector ResolvedPosition = PlacementPosition + TransformedNormal * (PlacementSize ) ;
	
	bool CeilingCheck = roundf(TrueNormalSigned.Dot(FVector::UpVector)) != 0.0f;
	FVector currentAxisUp = FVector::UpVector * (1.0f - CeilingCheck) + FVector::RightVector * CeilingCheck;
	 
	FVector axisOfRotation = (CollisionResNormal.Cross(currentAxisUp)).GetAbs();
	
	FVector TransFormedAxisOfRotation = TransformedNormal.Cross(currentAxisUp);

	DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + AlignmentVector * FVector(700.0f, 700.0f, 700.0f), FColor::Red);

	


	bool CheckOppositeRotation = roundf(TransFormedAxisOfRotation.Dot(axisOfRotation)) == 0.0f;  

	FVector opposite = (axisOfRotation.Cross(currentAxisUp))*   ((float)CheckOppositeRotation);


	if (CheckOppositeRotation){
		axisOfRotation = (axisOfRotation.Cross(currentAxisUp)) *(1.0f - CeilingCheck) + axisOfRotation * CeilingCheck;
	    
	}

	

	DrawDebugLine(GetWorld(), PlacementPosition, PlacementPosition + axisOfRotation * FVector(400.0f, 400.0f, 400.0f), FColor::Yellow);

	float AlignementDot = TransformedNormal.Dot(AlignmentVector);
	FVector AlignedAlignmentVector = WorldRotation.RotateVector(AlignmentVector);

	double AlignmentAngle = 0.0f;

	FVector AlignmentCross = TransformedNormal.Cross(AlignmentVector) * AlignmentAxis;
	float AlignmentCrossSum = AlignmentCross.X + AlignmentCross.Y + AlignmentCross.Z;
	AlignmentAngle = -atan2(AlignmentCrossSum, AlignementDot) ;
	bool AlignementAngleGreater = AlignmentAngle != 0.0f;


	//AlignedAxisOfRotation = axisOfRotation * (1.0f - ((float)AlignementAngleGreater)) +  AlignmentAxisCros * ((float)AlignementAngleGreater);

	float anglePicthDot = TransformedNormal.Dot(FVector::UpVector);
	FVector pitchCross = TransformedNormal.Cross(FVector::UpVector) * axisOfRotation.GetAbs();
	float anglePitchCross = pitchCross.X + pitchCross.Y + pitchCross.Z;
	SetActorLocation(ResolvedPosition);

	if (AlignmentVector != FVector::ZeroVector && AlignmentAngle != 0.0f) {

		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Alignment angle not equal to zero "), AlignmentAngle)); 
		FVector AlignmentAxisCros = AlignmentAxis.Cross(AlignmentVector);
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Magenta, FString::Printf(TEXT("alignment axis cross after alignment check X:%f Y:%f Z:%f  "), AlignmentAxisCros.X, AlignmentAxisCros.Y, AlignmentAxisCros.Z));
		FQuat AligmentRotation = FQuat(AlignmentAxis, AlignmentAngle);

		FVector rotatedAlignementVector = AligmentRotation.RotateVector(AlignmentVector);
		double PitchAngleForAlingment = atan2(anglePitchCross, anglePicthDot); 

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("pitch angle for alignmen :%f"), PitchAngleForAlingment));

		FQuat PicthRotationForAlignment = FQuat(AlignmentAxisCros, abs(PitchAngleForAlingment));
		SetActorRotation(AligmentRotation.Rotator() + PicthRotationForAlignment.Rotator());
	    

		return;

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
		currentAxisUp =  FVector::UpVector;
	

	}


	
	

	FVector AtanSinRatioYaw = actorUp.Cross(TransformedNormal); 

	FVector CrossForYRatio = (CollisionResNormal.Cross(trueAxisOfRotation).GetAbs());
	FVector AtanYRatio = AtanSinRatioYaw * CrossForYRatio;  
	FVector crossForNormal = (CollisionResNormal.Cross(currentAxisUp).GetAbs() * (1.0f- CheckOppositeRotation)) + axisOfRotation * CheckOppositeRotation ;
	FVector YRatioForNormal = (TransformedNormal) * crossForNormal;
	
	FVector compare = (GetActorUpVector() * CrossForYRatio) ;
	
	bool IsNotNegative =   (AtanYRatio.X + AtanYRatio.Y + AtanYRatio.Z) > 0.0f && (YRatioForNormal.X + YRatioForNormal.Y + YRatioForNormal.Z) > 0.0f ||
		                   (AtanYRatio.X + AtanYRatio.Y + AtanYRatio.Z) < 0.0f && (YRatioForNormal.X + YRatioForNormal.Y + YRatioForNormal.Z) < 0.0f;
	
	float YRatio = (YRatioForNormal.X + YRatioForNormal.Y + YRatioForNormal.Z);
	
	float YRatioNegate = ((float)IsNotNegative) * 2.0f - 1.0f;
	float XRatio = actorUp.Dot(TransformedNormal);
	double YawAtan = atan2(YRatio * YRatioNegate  , XRatio) * (  XRatio != 0.0f );
	float angleYaw = (acosf(actorUp.Dot(TransformedNormal)));

	FQuat YawRot = FQuat(currentAxisUp, YawAtan);

	FVector YawRotatedUp = YawRot.RotateVector(actorUp);
	
	FVector finalRot = YawRot.RotateVector(actorUp);
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Final angles pitch %f yaw %f roll %f "), angleDeg, FMath::RadiansToDegrees(YawAtan)));
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("final rot  %f %f %f"), finalRot.X, finalRot.Y, finalRot.Z));
	DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + TransformedNormal * FVector(700.0f, 700.0f, 700.0f), FColor::Blue);
	DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + AlignedAlignmentVector * FVector(700.0f, 700.0f, 700.0f), FColor::Green);	
	SetActorRotation( RotatorPitch + YawRot.Rotator());
}

void ATowerBase::OnOverLapBegin(UPrimitiveComponent* OverlapedComponent, AActor* OverlapedActor, UPrimitiveComponent* OtherComp,int32 OtherBodyIndex,bool SweepBool ,const FHitResult& HitResult) {
	
	CurrentyActive = true;
	if (AEnemyBase* EnemyTOHandle = Cast<AEnemyBase>(OverlapedActor)) {
		
		
		HandleNewEnemy(EnemyTOHandle); 


	}

	
} 





void ATowerBase::CheckForEnemies(){}

void ATowerBase::HandleNewEnemy(AEnemyBase* EnemyBase){}
void ATowerBase::TowerReset() {}
void ATowerBase::TowerActive(float &DeltaTime) {}


void ATowerBase::TowerSetUp(){}



// Called every frame
void ATowerBase::Tick(float DeltaTime)
{



	Super::Tick(DeltaTime); 

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("tower updating")));

	if (CurrentyActive) {
	
			TowerActive(DeltaTime); 
			if (RequiresReset && (WaitTimeToReset -= DeltaTime)<=0.0f) {

				RequiresReset = false;
				WaitTimeToReset = MaxWaitTimeToReset;
				TowerReset();
				
			}
			
	}
	

	
	

}

