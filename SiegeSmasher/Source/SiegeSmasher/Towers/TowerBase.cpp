// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerBase.h"

// Sets default values
ATowerBase::ATowerBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxColliderForObjectPlacement = CreateDefaultSubobject<UBoxComponent>(TEXT("Box collider for placement"));
	RootComponent = BoxColliderForObjectPlacement;
	StaticMeshForTower = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("static mesh"));
	StaticMeshForTower->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ATowerBase::BeginPlay()
{




}






FVector ATowerBase::GetPlacementColliderHalfExtents()
{
	return  BoxColliderForObjectPlacement->GetCollisionShape().GetExtent();

}

void ATowerBase::ResolvePlacement(FVector SurfaceHalfExtents, FVector SurfacePos, FVector PlacementPosition, FVector CamDir)
{


	// min and max for box containing surface
	FVector SurfaceWorldMin = SurfacePos + FVector(SurfaceHalfExtents.X, -SurfaceHalfExtents.Y, SurfaceHalfExtents.Z);
	FVector SurfaceWorldMax = SurfacePos + FVector(-SurfaceHalfExtents.X, SurfaceHalfExtents.Y, -SurfaceHalfExtents.Z);

	FVector PlacementBox = GetPlacementColliderHalfExtents();
	//min and max of tower placement box
	FVector TowerMin = PlacementPosition + FVector(PlacementBox.X, -PlacementBox.Y, PlacementBox.Z);
	FVector TowerMax = PlacementPosition + FVector(-PlacementBox.X, PlacementBox.Y, -PlacementBox.Z);
	DrawDebugSphere(GetWorld(), SurfaceWorldMin, 50.0f, 8, FColor::Blue);
	DrawDebugSphere(GetWorld(), SurfaceWorldMax, 50.0f, 8, FColor::Blue);

	DrawDebugSphere(GetWorld(), TowerMin, 20.0f, 8, FColor::Emerald);
	DrawDebugSphere(GetWorld(), TowerMax, 20.0f, 8, FColor::Emerald);
	//width
	bool IsContainedWidth = TowerMin.Y >= SurfaceWorldMin.Y && TowerMax.Y <= SurfaceWorldMax.Y;
	//height
	bool IsContainedHeight = TowerMin.Z <= SurfaceWorldMin.Z && TowerMax.Z >= SurfaceWorldMax.Z;
	//length
	bool IsContainedLength = TowerMin.X <= SurfaceWorldMin.X && TowerMax.X >= SurfaceWorldMax.X;



	////GLog->Log(FString::Printf(TEXT("Is contained width:%d Is contained Height:%d Is contained Length:%d "), IsContainedWidth, IsContainedHeight, IsContainedLength));
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("Is contained width:%d Is contained Height:%d Is contained Length:%d "), IsContainedWidth, IsContainedHeight, IsContainedLength));

	FVector3d CollisionResNormal = FVector3d(IsContainedWidth && IsContainedHeight, IsContainedHeight && IsContainedLength, IsContainedLength && IsContainedWidth);
	FVector InvertedCamDir = -CamDir;
	//  invert collision normal based on direction the camera is looking 
	//  as we start by assuming that the collision normal is positive 
	// this inversion esnures that the normal points out of the surface 
	// so we dont shift the tower into it when resolving the placement position
	CollisionResNormal.X *= (2.0f * ((float)InvertedCamDir.X > 0.0f) - 1.0f);
	CollisionResNormal.Y *= (2.0f * ((float)InvertedCamDir.Y > 0.0f) - 1.0f);
	CollisionResNormal.Z *= (2.0f * ((float)InvertedCamDir.Z > 0.0f) - 1.0f);

	// resolve placement position using the placement box extents multiplied by dir of collison normal(direction of the placement surface) to get correct direction
	// for the shift 
	FVector ResolvedPosition = PlacementPosition + CollisionResNormal * PlacementBox.Z;
	//GLog->Log(FString::Printf(TEXT("Collision res normal scaled X:%f Y:%f Z:%f"), CollisionResNormal.X * PlacementBox.Z, CollisionResNormal.Y *PlacementBox.Z, CollisionResNormal.Z * PlacementBox.Z));
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("Collision res normal scaled X:%f Y:%f Z:%f"), CollisionResNormal.X * PlacementBox.Z, CollisionResNormal.Y * PlacementBox.Z, CollisionResNormal.Z * PlacementBox.Z));

	/// this dot product is used to check if we need to swap the axis of rotation as there is a case 
	// where the collision normal will want us to not rotate(when it is 0,0,-1) 
	// i.e when the player is looking at a ceiling, when we actually need to rotate around the y axis 
	// the dot product will be used to check for this case as the collision normal when the player is loooking to the ceiling 
	// will be 0,0,-1 and the up vector we use is 0,0,1 meaning the result of the dot product in this case will be -1 
	// so we know that we need to pitch the tower -180 to flip it onto the ceiling  rather than using the axis of rotation derrived from the collision normal 
	// which will actually be 0,0,0 in this case(no rotation) as we use cross product for that
	float ColNormalDir = CollisionResNormal.Dot(FVector::UpVector);
	GLog->Log(FString::Printf(TEXT("Dot for normal direction with up %f "), ColNormalDir));
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("Dot for normal direction with up %f "), ColNormalDir));
	// case that character is looking direclty up when placing tower meaning that we need to pitch around the Y axis instead of using the derrived axis of rotation
	// from the cross product between the lok up vector of the tower(0,0,1) and the collision normal 
	FVector axisOfRotation = CollisionResNormal.Cross(FVector::UpVector) + FVector::RightVector * (ColNormalDir * ((float)ColNormalDir < 0.0f));
	/*GLog->Log(FString::Printf(TEXT("axis rot X:%f Y:%f Z:%f"), axisOfRotation.X, axisOfRotation.Y, axisOfRotation.Z));
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("axis rot X:%f Y:%f Z:%f"), axisOfRotation.X, axisOfRotation.Y, axisOfRotation.Z));*/

	// taking into account z axis having different rotation(discussed above) i.e no rotation when up right and -180 rotation when tower is being placed on ceiling
	float angle = 90.0f * ((float)ColNormalDir == 0.0f) + 180.0f * (float(ColNormalDir < 0.0f));
	GLog->Log(FString::Printf(TEXT("rot angle %f "), angle));
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("rot angle %f "), angle));

	FRotator rotator = FRotator(angle * axisOfRotation.Y, angle * axisOfRotation.Z, angle * axisOfRotation.X);

	FTransform transform = FTransform(rotator, ResolvedPosition, GetActorScale());
	SetActorTransform(transform);

	FVector res = GetActorTransform().GetRotation().GetRotationAxis();
	/*  GLog->Log(FString::Printf(TEXT("axis result rot X:%f Y:%f Z:%f"), res.X, res.Y, res.Z));
	  GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, FString::Printf(TEXT("axis result rot X:%f Y:%f Z:%f"), res.X, res.Y, res.Z));
	  */






}

// Called every frame
void ATowerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

