// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/Sword.h"
#include "SiegeSmasher/MainCharacter.h"

// Sets default values
ASword::ASword()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	Mesh->SetCollisionResponseToAllChannels(ECR_Block);
	Mesh->BodyInstance.SetInstanceNotifyRBCollision(true);
	Mesh->SetupAttachment(Root);

	Mesh->OnComponentHit.AddDynamic(this, &ASword::OnHit);
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

void ASword::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	GLog->Log("In hit");
	if (Cast<AMainCharacter>(OtherActor))
	{
		GLog->Log("Character Hit Detected");
	}
}

