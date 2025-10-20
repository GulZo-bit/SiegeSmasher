// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/WitchAI/Witch_Projectile.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AWitch_Projectile::AWitch_Projectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	Mesh->BodyInstance.SetInstanceNotifyRBCollision(true);
	Mesh->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform);

	Mesh->SetupAttachment(Root);

	Mesh->OnComponentBeginOverlap.AddDynamic(this, &AWitch_Projectile::OnOverLapBegin);
}

// Called when the game starts or when spawned
void AWitch_Projectile::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = this->GetActorLocation();

	
}

// Called every frame
void AWitch_Projectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	FVector Target = FMath::VInterpTo(GetActorLocation(), PlayerPawn->GetActorLocation(), DeltaTime, 2.0f);
	SetActorLocation(Target);
}

void AWitch_Projectile::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Spell overlap with: %s"), *OtherActor->GetName());
	/*if (OtherActor && (OtherActor != this))
	{
		UE_LOG(LogTemp, Warning, TEXT("Spell overlap with: %s"), *OtherActor->GetName());
	}
	this->Destroy();
	if (Cast<AMainCharacter>(OtherActor))
	{
		this->Destroy();
	}*/

}


