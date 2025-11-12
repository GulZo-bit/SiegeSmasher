// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AIWitch.h"
#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"
#include "AI/AICharTest.h"

// Sets default values
AAIWitch::AAIWitch()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAIWitch::BeginPlay()
{
	Super::BeginPlay();
	AnimInstance = GetMesh()->GetAnimInstance();
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
	//Box component used to find overlapping actors.
	HealZone = this->FindComponentByClass<UBoxComponent>();
}

//Play attack animation
void AAIWitch::PlayAttack()
{
	
	if (GetLocalRole() < ROLE_Authority)
	{
		Server_PlayAttackMontage();
		if (FireballSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, FireballSound, GetActorLocation());
		}
	}
	
	else
	{
		Multicast_PlayAttackMontage();
	}
}

void AAIWitch::Server_PlayAttackMontage_Implementation()
{
	Multicast_PlayAttackMontage();
}


void AAIWitch::Multicast_PlayAttackMontage_Implementation()
{
	if (AttackSpellMontage != nullptr)
	{

		if (FireballSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, FireballSound, GetActorLocation());
		}


		if (AnimInstance != nullptr)
		{
			AnimInstance->Montage_Play(AttackSpellMontage);
			iCount = 0;
		}
	}
}

void AAIWitch::Server_PlayLightTimeLine_Implementation(AHealAuraLight* LightStore)
{
	Multicast_PlayLightTimeLine(LightStore);
}

void AAIWitch::Multicast_PlayLightTimeLine_Implementation(AHealAuraLight* LightStore)
{
	LightStore->getLightTimeLineComp()->PlayFromStart();
}

//Healing other enemies
void AAIWitch::HealEnemy()
{
	if (HasAuthority() && HealZone != nullptr)
	{
		GLog->Log("Found HealZone");

		//Store all the actors that are in the heal zone
		TArray<AActor*> ActorStore;
		HealZone->GetOverlappingActors(ActorStore);

		//Every enemy that is in the heal zone gets healed with 20 health.
		for (int i = 0; i < ActorStore.Num(); i++)
		{
			if (ActorStore[i] != nullptr)
			{
				if (Cast<AEnemyBase>(ActorStore[i]))
				{
					GLog->Log("Healing Enemies");
					AEnemyBase* AICharTemp = Cast<AEnemyBase>(ActorStore[i]);
					AICharTemp->AddToHealth(20);
				}
			}
		}
	}
}

//Play heal animation
void AAIWitch::PlayHealSpellMontage()
{
	if (GetLocalRole() < ROLE_Authority)
	{

		if (HealingSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, HealingSound, GetActorLocation());
		}
		Server_PlayHealSpellMontage();
	}

	else
	{
		Multicast_PlayHealSpellMontage();
	}
}

void AAIWitch::Server_PlayHealSpellMontage_Implementation()
{
	Multicast_PlayHealSpellMontage();
}

void AAIWitch::Multicast_PlayHealSpellMontage_Implementation()
{

	if (HealSpellMontage != nullptr && AnimInstance != nullptr)
	{
		if (HealingSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, HealingSound, GetActorLocation());
		}
		AnimInstance->Montage_Play(HealSpellMontage);
		iHealCount = 0;
		
	}

}

//Play death montage
void AAIWitch::PlayDeathMontage()
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

void AAIWitch::Server_PlayDeathMontage_Implementation()
{
	Multicast_PlayDeathMontage();
}

void AAIWitch::Multicast_PlayDeathMontage_Implementation()
{
	if (DeathMontage != nullptr && AnimInstance != nullptr && AnimIsDead != nullptr)
	{
			GLog->Log("Anim Instance is not null");
			AnimIsDead->setIsDeadBool(true);

			if (SoundCount == 0)
			{
				UGameplayStatics::PlaySoundAtLocation(this, DeathSound, GetActorLocation());
				SoundCount += 1;
			}
			

			AnimInstance->Montage_Play(DeathMontage);
			bCanActorMove = false;
		
	}

}


// Called every frame
void AAIWitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Resetting the witch when she is killed
	if (this->GetHealth() <= 0)
	{
		if (AnimInstance != nullptr && AnimInstance->Montage_IsPlaying(DeathMontage))
		{
			float MontageTimeStore = AnimInstance->Montage_GetPosition(DeathMontage);

			if (MontageTimeStore >= 3.0f)
			{
				DecrementWaveEnemyAliveCount();
				CubeStore->SetActorHiddenInGame(false);
				CubeStore->SetActorTransform(SplineControllerStore[SplineNum]->getSpline()->GetComponentTransform());
				Count = StartTime;
				this->ResetEnemyOnDeath();
				bCanActorMove = false;
				bDeathAnimFinished = true;
				
			}
		}
	}

	//If the witch is alive we do the math for moving across the spline.
	else
	{
		bDeathAnimFinished = false;
		SoundCount = 0;
		if (bCanActorMove == true && SplineControllerStore.Num() > 0)
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
		bCanActorMove = true;
	}
	
	

	if (AnimInstance != nullptr )
	{
		//Make sure to spawn the spell at the correct stage of the animation.
		
		if (AnimInstance->Montage_IsPlaying(AttackSpellMontage))
		{
			float AttackMontageTimeStore = AnimInstance->Montage_GetPosition(AttackSpellMontage);
			//UE_LOG(LogTemp, Log, TEXT("Current Montage Time: %f"), MontageTimeStore);
			if (AttackMontageTimeStore >= 1.23f && iCount < 1)
			{
				if (HasAuthority())
				{
					Spell = GetWorld()->SpawnActor<AWitch_Projectile>(SpellClass, FTransform(FRotator(), GetMesh()->GetSocketLocation(TEXT("SpellSocket")), FVector(1.0f, 1.0f, 1.0f)));
				}
				iCount++;

			}
		}
		

		//Make sure to spawn the spell at the correct stage of the animation.
		else if (AnimInstance->Montage_IsPlaying(HealSpellMontage))
		{
			float MontageTimeStore = AnimInstance->Montage_GetPosition(HealSpellMontage);
			//UE_LOG(LogTemp, Log, TEXT("Current Montage Time: %f"), MontageTimeStore);
			if (MontageTimeStore >= 0.97f && iHealCount < 1)
			{
				if (HasAuthority())
				{
					Spell = GetWorld()->SpawnActor<AWitch_Projectile>(HealSpell, FTransform(FRotator(), GetMesh()->GetSocketLocation(TEXT("SpellSocket")), FVector(1.0f, 1.0f, 1.0f)));
				}
				HealEnemy();
				
				iHealCount++;
			}
		}
	}
	
}

// Called to bind functionality to input
void AAIWitch::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAIWitch::setbCanActorMove(bool bStore)
{
	bCanActorMove = bStore;
}


bool AAIWitch::getbCanActorMove()
{
	return bCanActorMove;
}

//Reset the witch if she reaches the end of the level.
void AAIWitch::EnemyReachedBase()
{
	DecrementWaveEnemyAliveCount();
	CubeStore->SetActorHiddenInGame(false);
	CubeStore->SetActorTransform(SplineControllerStore[SplineNum]->getSpline()->GetComponentTransform());
	Count = StartTime;
	this->ResetEnemyOnDeath();
	bCanActorMove = false;
}

AWitch_Projectile* AAIWitch::getSpell()
{
	if (Spell != nullptr)
	{
		return Spell;
	}

	else
	{
		return nullptr;
	}
}

bool AAIWitch::getDeathAnimFinsihed()
{
	return bDeathAnimFinished;
}

