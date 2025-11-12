// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/Sword.h"


// Sets default values
ASword::ASword()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Setting up the sword
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	Mesh->BodyInstance.SetInstanceNotifyRBCollision(true);
	Mesh->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform);

	Mesh->SetupAttachment(Root);
	
	Mesh->OnComponentBeginOverlap.AddDynamic(this, &ASword::OnOverLapBegin);
	Mesh->OnComponentEndOverlap.AddDynamic(this, &ASword::OnOverLapEnd);

	bAlwaysRelevant = true;
	NetCullDistanceSquared = 0;
}

// Called when the game starts or when spawned
void ASword::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASword::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASword::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//On overlap with the main character we apply damage to them.
	if (Cast<AMainCharacterTest>(OtherActor) )
	{
		GetWorldTimerManager().ClearTimer(TimerHandle);
		GetWorldTimerManager().SetTimer(TimerHandle, this, &ASword::ResetHit, 1.0f, false, 1.5f);
		if (bHit == false)
		{
			AMainCharacterTest* MainChar = Cast<AMainCharacterTest>(OtherActor);
			MainChar->setHealth(MainChar->getHealth() - Damage);
			bHit = true;
			GLog->Log(FString::Printf(TEXT("PlayerHealth: %f"), MainChar->getHealth()));
		}

	}
}

//Once the overlap is done we don't want to be hitting the player anymore so we won't apply the damage.
void ASword::OnOverLapEnd(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	bHit = false;
}

void ASword::ResetHit()
{
	bHitDetected = false;
}

void ASword::ResetSwordOnDeath()
{
	Multicast_ResetSwordOnDeath();
}

void ASword::ResetSwordOnRespawn()
{
	Multicast_ResetSwordOnRespawn();
}

void ASword::Multicast_ResetSwordOnDeath_Implementation()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	SetActorTickEnabled(false);
}

void ASword::Multicast_ResetSwordOnRespawn_Implementation()
{
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetActorTickEnabled(true);
}

void ASword::setCollisionEnemy()
{
	Mesh->BodyInstance.SetCollisionProfileName(TEXT("Enemy"));
}

void ASword::setCollisionDefault()
{
	Mesh->SetCollisionResponseToAllChannels(ECR_Ignore);
}
