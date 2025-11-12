// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/WitchAI/Witch_Projectile.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AWitch_Projectile::AWitch_Projectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Setup the fireball
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	Mesh->BodyInstance.SetInstanceNotifyRBCollision(true);
	Mesh->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform);

	Mesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AWitch_Projectile::BeginPlay()
{
	Super::BeginPlay();

	StartTime = GetWorld()->GetTimeSeconds();
	StartLocation = this->GetActorLocation();
	Mesh->OnComponentBeginOverlap.AddDynamic(this, &AWitch_Projectile::OnOverLapBegin);
	
}

// Called every frame
void AWitch_Projectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),PlayerIndex);										//cm/s
	
	//If the spell is a moving spell.
	if (bMove == true)
	{
		//The spell is homing and hones in onto the player location.
		FVector Target = FMath::VInterpConstantTo(GetActorLocation(), PlayerPawn->GetActorLocation(), DeltaTime, 1000.0f);
		SetActorLocation(Target);
	}
	
	//If it isn't then the spell is purely visual and destroys itself after some time.
	else
	{
		float CurrentTime = (GetWorld()->GetTimeSeconds() - StartTime) / DeltaTime;
		//GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Green, FString::Printf(TEXT("Current Time: %f"), CurrentTime));

		if (CurrentTime >= 50.0f)
		{
			this->Destroy();
		}
	}
}

void AWitch_Projectile::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//If the spell overlaps with the player then it damages them.
	if (Cast<AMainCharacterTest>(OtherActor))
	{
		AMainCharacterTest* MainChar = Cast<AMainCharacterTest>(OtherActor);
		MainChar->setHealth(MainChar->getHealth() - Damage);
		GLog->Log(FString::Printf(TEXT("PlayerHealth: %f"), MainChar->getHealth()));
		//this->Destroy();
	}
	this->Destroy();
	
}

void AWitch_Projectile::setPlayerIndex(int32 Store)
{
	PlayerIndex = Store;
}



