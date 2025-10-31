// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/DemonAI/AIDemon.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAIDemon::AAIDemon()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAIDemon::BeginPlay()
{
	Super::BeginPlay();
	
	//Attach Fists
	RightFist = GetWorld()->SpawnActor<ADemonFists>(DemonFistClass);
	LeftFist = GetWorld()->SpawnActor<ADemonFists>(DemonFistClass);

	if (RightFist != nullptr)
	{
		RightFist->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("RightHandSocket"));
		RightFist->SetOwner(this);
	}

	if (LeftFist != nullptr)
	{
		LeftFist->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("LeftHandSocket"));
		LeftFist->SetOwner(this);
	}

	/*AIPerception->OnPerceptionUpdated.AddDynamic(this, &AAIDemon::HandlePerceptionUpdate);*/
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

	AnimInstance = GetMesh()->GetAnimInstance();
}

// Called every frame
void AAIDemon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (this->GetHealth() <= 0)
	{
		if (AnimInstance != nullptr)
		{
			if (AnimInstance->Montage_IsPlaying(DeathMontage))
			{
				float MontageTimeStore = AnimInstance->Montage_GetPosition(DeathMontage);

				if (MontageTimeStore >= 4.0f)
				{
					this->ResetEnemyOnDeath();
					RightFist->ResetFistsOnDeath();
					LeftFist->ResetFistsOnDeath();
					CubeStore->SetActorHiddenInGame(false);
					CubeStore->SetActorTransform(SplineControllerStore[SplineNum]->getSpline()->GetComponentTransform());
					Count = StartTime;
					bCanActorMove = true;
				}
			}
		}
	}

	else
	{
		RightFist->ResetFistsOnSpawn();
		LeftFist->ResetFistsOnSpawn();
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
	
}

// Called to bind functionality to input
void AAIDemon::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAIDemon::PlayAttack()
{
	if (GetLocalRole() < ROLE_Authority)
	{
		Server_PlayAttackMontage();
	}

	else
	{
		Multicast_PlayAttackMontage();
	}
}

void AAIDemon::Server_PlayAttackMontage_Implementation()
{
	Multicast_PlayAttackMontage();
}


void AAIDemon::Multicast_PlayAttackMontage_Implementation()
{
	if (AttackAnimation != nullptr)
	{
		if (AnimInstance != nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Green, FString::Printf(TEXT("Playing Animation")));
			AnimInstance->Montage_Play(AttackAnimation);
		}
	}
}

void AAIDemon::PlayDeathMontage()
{
	if (GetLocalRole() < ROLE_Authority)
	{
		Server_PlayDeathMontage();
	}

	else
	{
		Multicast_PlayDeathMontage();
	}
}

void AAIDemon::Server_PlayDeathMontage_Implementation()
{
	Multicast_PlayDeathMontage();
}

void AAIDemon::Multicast_PlayDeathMontage_Implementation()
{
	bCanActorMove = false;
	if (DeathMontage != nullptr)
	{
		if (AnimInstance != nullptr)
		{
			UBoolAnimInstance* BoolAnimInstance = Cast<UBoolAnimInstance>(AnimInstance);
			if (BoolAnimInstance != nullptr) { BoolAnimInstance->setIsDeadBool(true); }

			AnimInstance->Montage_Play(DeathMontage);
			bCanActorMove = false;
		}
	}

}

void AAIDemon::setbCanActorMove(bool bStore)
{
	bCanActorMove = bStore;
}

