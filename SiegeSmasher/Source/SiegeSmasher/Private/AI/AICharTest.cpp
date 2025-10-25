// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AICharTest.h"
#include "AI/Sword.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAICharTest::AAICharTest()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAICharTest::BeginPlay()
{
	Super::BeginPlay();
	
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
				Count = GetWorld()->GetTimeSeconds();
			}
		}
	}


}

// Called every frame
void AAICharTest::Tick(float DeltaTime)
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

// Called to bind functionality to input
void AAICharTest::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAICharTest::PlayAttackMontage()
{
	//Checks to see if the client is the one asking to play the animation.
	if (GetLocalRole() < ROLE_Authority)
	{
		//If it is then we play the attack animation on the server.
		//This is also here to validate the request by the client initiating the action then it calls the multicast.
		Server_PlayAttackMontage();
	}
	else
	{
		//Otherwise we play it locally and replicate it to the clients.
		Multicast_PlayAttackMontage();
	}
}

void AAICharTest::Server_PlayAttackMontage_Implementation()
{
	Multicast_PlayAttackMontage();
}

//Plays the attack animation.
void AAICharTest::Multicast_PlayAttackMontage_Implementation()
{
	if (AttackMontage != nullptr)
	{
		UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
		if (AnimInstance != nullptr)
		{
			AnimInstance->Montage_Play(AttackMontage);
		}
	}
}



void AAICharTest::setbCanActorMove(bool bStore)
{
	bCanActorMove = bStore;
}

TArray<AActor*> AAICharTest::getCheckpoints()
{
	return CheckpointStore;
}

