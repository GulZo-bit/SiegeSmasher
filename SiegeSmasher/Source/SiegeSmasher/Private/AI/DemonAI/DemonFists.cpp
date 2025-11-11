// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/DemonAI/DemonFists.h"

// Sets default values
ADemonFists::ADemonFists()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->BodyInstance.SetInstanceNotifyRBCollision(true);
	Capsule->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform);
	Capsule->SetupAttachment(Root);

	Capsule->OnComponentBeginOverlap.AddDynamic(this, &ADemonFists::OnOverLapBegin);
	Capsule->OnComponentEndOverlap.AddDynamic(this, &ADemonFists::OnOverLapEnd);

	bAlwaysRelevant = true;
	NetCullDistanceSquared = 0;
}

// Called when the game starts or when spawned
void ADemonFists::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADemonFists::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADemonFists::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<ATowerBase>(OtherActor))
	{
		if (bHit == false)
		{
			ATowerBase* Tower = Cast<ATowerBase>(OtherActor);
			Tower->setHealth(Tower->getHealth() - Damage);
			GLog->Log(FString::Printf(TEXT("TowerHealth: %f"), Tower->getHealth()));
			bHit = true;
		}
	}
}

void ADemonFists::OnOverLapEnd(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (Cast<ATowerBase>(OtherActor))
	{
		bHit = false;
	}
	
}

void ADemonFists::ResetFistsOnDeath()
{
	Multicast_ResetFistsOnDeath();
}

void ADemonFists::ResetFistsOnSpawn()
{
	Multicast_ResetFistsOnRespawn();
}

void ADemonFists::Multicast_ResetFistsOnDeath_Implementation()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	SetActorTickEnabled(false);
}

void ADemonFists::Multicast_ResetFistsOnRespawn_Implementation()
{
	SetActorHiddenInGame(false);
	//SetActorEnableCollision(true);
	SetActorTickEnabled(true);
}
