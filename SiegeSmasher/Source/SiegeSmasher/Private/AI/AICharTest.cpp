// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AICharTest.h"
#include "AIController.h"
#include "AI/Sword.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAICharTest::AAICharTest()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//AIControllerClass = AEnemyBTAISplineController::StaticClass();

	//AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

// Called when the game starts or when spawned
void AAICharTest::BeginPlay()
{
	Super::BeginPlay();

	//GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Red, FString::Printf(TEXT("Begin play called")));
	//PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	////Controller = Cast<AController*> (AEnemyBTAISplineController());
	////AEnemyBTAISplineController* Temp = Cast<AEnemyBTAISplineController>(GetController());
	//if (GetController() == nullptr)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Red, FString::Printf(TEXT("Controller null")));
	//}

	
	

	//Sword Stuff
	Sword = GetWorld()->SpawnActor<ASword>(SwordClass);

	if (Sword != nullptr)
	{
		Sword->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("SwordSocket"));
		Sword->SetOwner(this);
	}

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
			}
		}
	}


}

// Called every frame
void AAICharTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//How long the current spline has been going for.
	float CurrentSplineTime = (GetWorld()->GetTimeSeconds() - StartTime) / SplineControllerStore[SplineNum]->getTotalPathTimeController();

	//Find the distance we are along the spline.
	float Distance = SplineControllerStore[SplineNum]->getSpline()->GetSplineLength() * CurrentSplineTime;

	//Translate that distance into world space. Then move the cube to it,
	FVector Position = SplineControllerStore[SplineNum]->getSpline()->GetLocationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
	CubeStore->SetActorLocation(Position);

	//Rotate the cube in world space.
	FVector Direction = SplineControllerStore[SplineNum]->getSpline()->GetDirectionAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
	FRotator Rotator = FRotationMatrix::MakeFromX(Direction).Rotator();
	CubeStore->SetActorRotation(Rotator);
	
	
}

// Called to bind functionality to input
void AAICharTest::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


TArray<AActor*> AAICharTest::getCheckpoints()
{
	return CheckpointStore;
}

