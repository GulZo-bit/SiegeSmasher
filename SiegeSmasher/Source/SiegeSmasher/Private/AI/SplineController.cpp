// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SplineController.h"


// Sets default values
ASplineController::ASplineController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	TotalPathTimeController = 10.0f;

	Spline = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
	Spline->SetupAttachment(Root);
	Spline->Duration = TotalPathTimeController;
	Spline->bDrawDebug = true;
}

// Called when the game starts or when spawned
void ASplineController::BeginPlay()
{
	Super::BeginPlay();
	
	if (ActorToMoveClass != nullptr)
	{
		ActorToMove = GetWorld()->SpawnActor<AActor>(ActorToMoveClass, Spline->GetComponentTransform());

		if (ActorToMove != nullptr)
		{
			StartTime = GetWorld()->GetTimeSeconds();
		}
	}
}

// Called every frame
void ASplineController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ActorToMove != nullptr)
	{
		float CurrentSplineTime = (GetWorld()->GetTimeSeconds() - StartTime) / TotalPathTimeController;

		float Distance = Spline->GetSplineLength() * CurrentSplineTime;

		//World Position
		FVector Position = Spline->GetLocationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
		ActorToMove->SetActorLocation(Position);

		//World Rotation
		FVector Direction = Spline->GetDirectionAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
		FRotator Rotator = FRotationMatrix::MakeFromX(Direction).Rotator();
		ActorToMove->SetActorRotation(Rotator);

	}
}

void ASplineController::setTotalPathTimeController(float TotalPathTimeStore)
{
	TotalPathTimeController = TotalPathTimeStore;
}

float ASplineController::getTotalPathTimeController()
{
	return TotalPathTimeController;
}

USplineComponent* ASplineController::getSpline()
{
	return Spline;
}

