// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerBase.h"
#include "../MyMainCharacterTest.h"

// Sets default values
ATowerBase::ATowerBase()
{
	bReplicates = true;
	SetReplicateMovement(true);
	PrimaryActorTick.bCanEverTick = true;
	BoxColliderForObjectPlacement = CreateDefaultSubobject<UBoxComponent>(TEXT("Box collider for placement"));
	TowerTimeLine = CreateDefaultSubobject<UTimelineComponent>("TowerTimeLine");
	
	RootComponent = BoxColliderForObjectPlacement;
	TriggerRangeBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box For Range"));
	TriggerRangeBox->SetupAttachment(RootComponent);
	TriggerRangeBox->SetCollisionResponseToChannel(PlacingSurface, ECollisionResponse::ECR_Ignore);
	TowerTimeLineCurve = CreateDefaultSubobject<UCurveFloat>("Tower Time Line Curve");
	TowerHitBox = CreateDefaultSubobject<UBoxComponent>("Tower Hit Box");

	TriggerRangeBox->SetCollisionProfileName(FName("TowerPreset"));
	TowerHitBox->SetCollisionProfileName(FName("TowerPreset"));
	BoxColliderForObjectPlacement->SetCollisionProfileName(FName("TowerPreset")); 
	BoxColliderForObjectPlacement->SetCollisionObjectType(TowerPlacementBox); 
	BoxColliderForObjectPlacement->SetCollisionResponseToChannel(TowerPlacementBox, ECollisionResponse::ECR_Overlap);
	TowerHitBox->SetBoxExtent(FVector::ZeroVector); 


	StimuliSourceComponent = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("StimuliSourceComponent"));
	StimuliSourceComponent->RegisterForSense(UAISense_Sight::StaticClass()); 
	TowerTimeLine->SetIsReplicated(true);
	TeamID = FGenericTeamId(1);

	/*PlayerRef = nullptr;*/
}

void ATowerBase::DisableTick()
{

	PrimaryActorTick.SetTickFunctionEnable(false);
}

void ATowerBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)const {

	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ATowerBase, CurrentyActive);

}

void ATowerBase::Multicast_SetTowerHitBoxCollisionResponse_Implementation(ECollisionChannel Channel, ECollisionResponse CollisionResponse)
{
	TowerHitBox->SetCollisionResponseToChannel(Channel, CollisionResponse);

}

void ATowerBase::MultiCast_SetTowerHitBoxEnabled_Implementation(ECollisionEnabled::Type CollisionEnabled)
{
	TowerHitBox->SetCollisionEnabled(CollisionEnabled);

}



// Called when the game starts or when spawned
void ATowerBase::BeginPlay()
{
	Super::BeginPlay();
	WaitTimeToReset = MaxWaitTimeToReset; 
	CoolDownAfterReset = MaxCoolDownAfterReset;
	TriggerRangeBox->OnComponentBeginOverlap.AddDynamic(this, &ATowerBase::OnOverLapBegin);
	TowerHitBox->OnComponentBeginOverlap.AddDynamic(this, &ATowerBase::OnOverlapHitBox);  

	

	TriggerBoxDim = TriggerRangeBox->GetCollisionShape().GetExtent(); 
	/*TriggerRangeBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	TowerHitBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);*/
	
	for (int i = 0; i < AllowedDirections.Num(); i++) {

		FacingDirSum += AllowedDirections[i];

	}

	TowerSetUp();
}


FVector ATowerBase::GetPlacementColliderHalfExtents()
{
	return  BoxColliderForObjectPlacement->GetCollisionShape().GetExtent();

}

bool ATowerBase::ResolvePlacement(FVector& SurfaceBoxExtents, FVector& SurfacePos, FVector& PlacementPosition, FVector& CamDir,FVector& CamPos,FTransform& surfaceTransform)
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
	
	bool Contained = (CollisionResNormal.X + CollisionResNormal.Y + CollisionResNormal.Z)  >0;
  
	FVector AllowedDirection = CollisionResNormal + FacingDirSum - FVector::OneVector;


	FVector TransformedNormal = WorldRotation.RotateVector( CollisionResNormal);
	
	FVector TransformedTowerNormal = WorldRotation.RotateVector(AllowedDirection); 

	

	float normalDir = 1 + ((TransformedNormal.Dot(CamDir) > 0.0f) * -2.0f);
	TransformedNormal *= normalDir;

	FVector ResolvedPosition = PlacementPosition + TransformedNormal * (PlacementSize);
	SetActorLocation(ResolvedPosition); 
	FVector TrueNormalSigned = CollisionResNormal * normalDir;
	bool CeilingCheck = roundf(TrueNormalSigned.Dot(FVector::UpVector)) != 0.0f;
	bool IncorrectSurfaceDir = TransformedTowerNormal.Dot(AllowedDirection * normalDir) == 0.0f;
	if (!Contained ) {
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Tower cannot be placed on this surface")));
		
	/*	SetActorRotation(GetActorRotation() * !(Contained && IncorrectSurfaceDir));*/

		return false;
	}

	
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

	return true;
}

void ATowerBase::TowerTimeLineInterp(float value){}

void ATowerBase::SetHitBoxActive(bool HitBoxActive)
{

	TowerHitBox->SetActive(HitBoxActive);

}

UBoxComponent* ATowerBase::GetPlacmentBox()
{
	return BoxColliderForObjectPlacement;
}

void ATowerBase::OnOverLapBegin(UPrimitiveComponent* OverlapedComponent, AActor* OverlapedActor, UPrimitiveComponent* OtherComp,int32 OtherBodyIndex,bool SweepBool ,const FHitResult& HitResult) {
	
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("tower overlap begin ")));
	if (HasAuthority() ) {
		AEnemyBase* EnemyToHandle = Cast<AEnemyBase>(OverlapedActor);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("tower overlap begin ")));

		if (EnemyToHandle != nullptr && EnemyToHandle->GetHealth() >0.0f) {
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("tower overlap begin hit ")));

			CurrentyActive = true;
		}
	}
	


	
}

void ATowerBase::OnOverlapHitBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (AEnemyBase* Enemy = Cast<AEnemyBase>(OtherActor)) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Tower hit box hit enemy")));

		ApplyDamage(Enemy);

	}



}

void ATowerBase::OnHitBoxHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Tower hit box hit event enemy")));

	if (AEnemyBase* Enemy = Cast<AEnemyBase>(OtherActor)) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Tower hit box hit event on  enemy")));

		ApplyDamage(Enemy);

	}

}

// methods to be inherited and overriden by  child classes unreal does have a macro for defining 
// null implemented(abstract methods) inside UObjects but all it does is create the methods for you 
// and implement them as stubs anyway as unreal needs to create an instance for UObjects to see them
void ATowerBase::HandleNewEnemy(AEnemyBase* EnemyBase){}
void ATowerBase::TowerReset() {}
void ATowerBase::TowerActive(float& DeltaTime) {}
void ATowerBase::ApplyDamage(AEnemyBase* Enemy){}
void ATowerBase::TowerDormant(float& DeltaTime) {}
void ATowerBase::TowerSetUp(){}

void ATowerBase::DamageEnemyAndUpdatePlayerInfo(AEnemyBase* Enemy, float Damage)
{

	if (HasAuthority()) {

		Enemy->DamageEnemy(Damage, PlayerRef);
	}
}

void ATowerBase::Multicast_PlayTowerTimeLine_Implementation(float PlayBackSpeed)
{
	/*if (HasAuthority()) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Multi cast play timeline host called")));

	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("Multi cast reverse timeline called")));

	}
	*/
	TowerTimeLine->SetPlayRate(PlayBackSpeed); 
	TowerTimeLine->PlayFromStart();
}

void ATowerBase::Multicast_ReverseTowerTimeLine_Implementation(float PlayBackSpeed)
{
	/*if (HasAuthority()) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Multi cast reverse timeline host called")));

	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("Multi cast reverse timeline called")));

	}*/

	TowerTimeLine->SetPlayRate(PlayBackSpeed);
	TowerTimeLine->ReverseFromEnd();
}

void ATowerBase::Multicast_SetTriggerBoxCollision_Implementation(ECollisionEnabled::Type ColType)
{

	TriggerRangeBox->SetCollisionEnabled(ColType);
}

// generic method for resseting towers once they have finished there timeline based animation
//this is bound to the TowerTimeLine component via method pointer in this base class(can be overriden if needed)
void ATowerBase::TowerTimeLineEnd() 
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("tower time line end ")));
	
	RequiresReset = true;
}




FGenericTeamId ATowerBase::GetGenericTeamId() const
{
	return TeamID;
}


// Called every frame
void ATowerBase::Tick(float DeltaTime)
{



	Super::Tick(DeltaTime); 
	if (CurrentyActive) {
	 

		TowerActive(DeltaTime); 
		
		
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("wait time to reset %f"), WaitTimeToReset));
		if (HasAuthority() && RequiresReset && (WaitTimeToReset -= DeltaTime) <= 0.0f) {
			//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("reset called  wait time to reset %f"), WaitTimeToReset));

			RequiresReset = false;
			WaitTimeToReset = MaxWaitTimeToReset;
			TowerReset();
				
		}
		return;
	}
	TowerDormant(DeltaTime);
	
	

}

void ATowerBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (EndPlayReason == EEndPlayReason::Destroyed)
	{
		StimuliSourceComponent->UnregisterFromPerceptionSystem();
	}
}

void ATowerBase::setHealth(float HealthStore)
{
	Health = HealthStore;

	if (Health <= 0.0f)
	{
		Destroy();
	}
}

float ATowerBase::getHealth()
{
	return Health;
}

void ATowerBase::SetPlayerRef(AMainCharacterTest* PlayerPtr) {
	PlayerRef = PlayerPtr;
}




void ATowerBase::IncrementAssignedPlayersScore(int increment)
{

	if (HasAuthority() && PlayerRef != nullptr) {
		PlayerRef->IncrementPlayerScore(increment);
		PlayerRef->UpdateLeaderBoardInfo();


	}

}
