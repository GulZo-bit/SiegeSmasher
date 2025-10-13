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
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAICharTest::StaticClass(), EnemyActorStore);
	GLog->Log(FString::Printf(TEXT("Array Count:"), EnemyActorStore.Num()));
	

	/*if (EnemyActorStore[0] != nullptr)
	{
		GLog->Log("Found AICharTest");

		for (int i = 0; i < EnemyActorStore.Num(); i++)
		{


			EnemyStoreArray[i] = Cast<AAICharTest>(EnemyActorStore[i]);
			ChildActorArray[i] = EnemyStoreArray[i]->FindComponentByClass<UChildActorComponent>();

			if (ChildActorArray[i] != nullptr)
			{
				GLog->Log("Found Child Actors");
				CubeStoreArray[i] = ChildActorArray[i]->GetChildActor();
				CubeStoreArray[i]->SetActorTransform(Spline->GetComponentTransform());

				if (i == 0)
				{
					StartTime = GetWorld()->GetTimeSeconds();
				}
			}
		}
	}*/
	
	


	//AActor* Store = UGameplayStatics::GetActorOfClass(GetWorld(), AAICharTest::StaticClass());
	//EnemyStore = Cast<AAICharTest>(Store);
	//ChildActor = EnemyStore->FindComponentByClass<UChildActorComponent>();
	//if (ChildActor != nullptr)
	//{
	//	GLog->Log("Found Child Actor");
	//	CubeStore = ChildActor->GetChildActor();
	//	CubeStore->SetActorTransform(Spline->GetComponentTransform());
	//	StartTime = GetWorld()->GetTimeSeconds();
	//	//ActorToMove = GetWorld()->SpawnActor<AActor>(ActorToMoveClass, Spline->GetComponentTransform());
	//	//	
	//	//if (ActorToMove != nullptr)
	//	//{
	//	//	//Get the intial time. This will be used for a distance equation later.
	//	//	StartTime = GetWorld()->GetTimeSeconds();
	//	//}
	//}

	//if (ActorToMoveClass != nullptr)
	//{
	//	ActorToMove = GetWorld()->SpawnActor<AActor>(ActorToMoveClass, Spline->GetComponentTransform());
	//	
	//	if (ActorToMove != nullptr)
	//	{
	//		//Get the intial time. This will be used for a distance equation later.
	//		StartTime = GetWorld()->GetTimeSeconds();
	//	}
	//}
}

// Called every frame
void ASplineController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//if (ActorToMove != nullptr)
	//{
	//	//How long the current spliune has been going for.
	//	float CurrentSplineTime = (GetWorld()->GetTimeSeconds() - StartTime) / TotalPathTimeController;

	//	//Find the distance we are along the spline.
	//	float Distance = Spline->GetSplineLength() * CurrentSplineTime;

	//	//Translate that distance into world space. Then move our actor to it,
	//	FVector Position = Spline->GetLocationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
	//	ActorToMove->SetActorLocation(Position);

	//	//Rotate the actor in world space.
	//	FVector Direction = Spline->GetDirectionAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
	//	FRotator Rotator = FRotationMatrix::MakeFromX(Direction).Rotator();
	//	ActorToMove->SetActorRotation(Rotator);

	//}

	//for (int i = 0; i < CubeStoreArray.Num() - 1; i++)
	//{
		//if (CubeStoreArray[0] != nullptr)
		//{
		//	//How long the current spliune has been going for.
		//	float CurrentSplineTime = (GetWorld()->GetTimeSeconds() - StartTime) / TotalPathTimeController;

		//	//Find the distance we are along the spline.
		//	float Distance = Spline->GetSplineLength() * CurrentSplineTime;

		//	//Translate that distance into world space. Then move our actor to it,
		//	FVector Position = Spline->GetLocationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
		//	CubeStoreArray[0]->SetActorLocation(Position);

		//	//Rotate the actor in world space.
		//	FVector Direction = Spline->GetDirectionAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
		//	FRotator Rotator = FRotationMatrix::MakeFromX(Direction).Rotator();
		//	CubeStoreArray[0]->SetActorRotation(Rotator);

		//}
	//}
	//if (CubeStore != nullptr)
	//{
	//	//How long the current spliune has been going for.
	//	float CurrentSplineTime = (GetWorld()->GetTimeSeconds() - StartTime) / TotalPathTimeController;

	//	//Find the distance we are along the spline.
	//	float Distance = Spline->GetSplineLength() * CurrentSplineTime;

	//	//Translate that distance into world space. Then move our actor to it,
	//	FVector Position = Spline->GetLocationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
	//	CubeStore->SetActorLocation(Position);

	//	//Rotate the actor in world space.
	//	FVector Direction = Spline->GetDirectionAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
	//	FRotator Rotator = FRotationMatrix::MakeFromX(Direction).Rotator();
	//	CubeStore->SetActorRotation(Rotator);

	//}
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

