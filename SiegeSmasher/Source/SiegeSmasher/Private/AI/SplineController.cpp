// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SplineController.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ASplineController::ASplineController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create a root.
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	//Acts as a speed variable. This determines how long it will take an actor to follow the path. Lower values equal faster.
	TotalPathTimeController = 10.0f;

	//Add a spline component to the root.
	Spline = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
	Spline->SetupAttachment(Root);
	Spline->Duration = TotalPathTimeController; //How long the path of the spline is will be dicatated by us.
	Spline->bDrawDebug = true;

	
}

// Called when the game starts or when spawned
void ASplineController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASplineController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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

