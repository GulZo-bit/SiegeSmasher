// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/DemonAI/AIDemon.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAIDemon::AAIDemon()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	SightConfig->SightRadius = 3000;
	SightConfig->LoseSightRadius = 3500;
	SightConfig->PeripheralVisionAngleDegrees = 90;
	SightConfig->SetMaxAge(10.0f);
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = false;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = false;

	AIPerception->ConfigureSense(*SightConfig);
	AIPerception->SetDominantSense(SightConfig->GetSenseImplementation());

	
}

// Called when the game starts or when spawned
void AAIDemon::BeginPlay()
{
	Super::BeginPlay();

	AIPerception->OnPerceptionUpdated.AddDynamic(this, &AAIDemon::HandlePerceptionUpdate);
	//Spline controller stuff.
	//Get all the spline controllers in the scene.
	TArray<AActor*> SplineControllerAsActor;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASplineController::StaticClass(), SplineControllerAsActor);

	//Cast the actor to the correct class.
	for (int i = 0; i < SplineControllerAsActor.Num(); i++)
	{
		if (SplineControllerAsActor[i] != nullptr)
		{
			GLog->Log("Actor has elements");
			SplineControllerStore.Add(Cast<ASplineController>(SplineControllerAsActor[i]));
		}

	}

	//Get the UChildActorComponents attached to the parent actor.
	TArray<UChildActorComponent*> ChildActors;
	this->GetComponents(ChildActors, true);
	SplineNum = FMath::RandRange(0, SplineControllerStore.Num() - 1);


	//Loop through the array.
	for (int i = 0; i < ChildActors.Num(); i++)
	{
		if (ChildActors[i] != nullptr)
		{
			GLog->Log("Has child actors");

			//If the component has the correct tag then we...
			if (ChildActors[i]->ComponentHasTag(Tag))
			{
				//Get the child actor of the ChildActorComponent
				GLog->Log("Found Spline Movement Actor");
				CubeStore = ChildActors[i]->GetChildActor();
				CubeStore->SetActorTransform(SplineControllerStore[SplineNum]->getSpline()->GetComponentTransform());

				StartTime = GetWorld()->GetTimeSeconds();
				Count = GetWorld()->GetTimeSeconds();
			}
		}
	}
}

// Called every frame
void AAIDemon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bCanActorMove == true)
	{
		//How long the current spline has been going for.
		float CurrentSplineTime = (Count - StartTime) / SplineControllerStore[SplineNum]->getTotalPathTimeController();

		//Find the distance we are along the spline.
		float Distance = SplineControllerStore[SplineNum]->getSpline()->GetSplineLength() * CurrentSplineTime;

		//Translate that distance into world space. Then move the cube to it,
		FVector Position = SplineControllerStore[SplineNum]->getSpline()->GetLocationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
		CubeStore->SetActorLocation(Position);

		//Rotate the cube in world space.
		FVector Direction = SplineControllerStore[SplineNum]->getSpline()->GetDirectionAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
		FRotator Rotator = FRotationMatrix::MakeFromX(Direction).Rotator();
		CubeStore->SetActorRotation(Rotator);

		Count += 1.0f * DeltaTime;
	}
}

void AAIDemon::HandlePerceptionUpdate(const TArray<AActor*>& UpdatedActors)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Red, FString::Printf(TEXT("Seen Tower")));
	/*for (AActor* Actor : UpdatedActors)
	{
		if (Actor)
		{
			UE_LOG(LogTemp, Warning, TEXT("Perception updated for actor: %s"), *Actor->GetName());
		}
	}*/
}

// Called to bind functionality to input
void AAIDemon::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAIDemon::setbCanActorMove(bool bStore)
{
	bCanActorMove = bStore;
}

