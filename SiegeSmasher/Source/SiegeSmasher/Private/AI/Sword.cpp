// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/Sword.h"


// Sets default values
ASword::ASword()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	//Mesh->BodyInstance.SetCollisionProfileName(TEXT("Enemy"));
	//Mesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	Mesh->BodyInstance.SetInstanceNotifyRBCollision(true);
	Mesh->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform);

	Mesh->SetupAttachment(Root);
	//Mesh->OnComponentHit.AddDynamic(this, &ASword::OnHit);
	
	Mesh->OnComponentBeginOverlap.AddDynamic(this, &ASword::OnOverLapBegin);
	Mesh->OnComponentEndOverlap.AddDynamic(this, &ASword::OnOverLapEnd);
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

//void ASword::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
//{
//	
//	if (Cast<AMainCharacter>(OtherActor))
//	{
//		GetWorldTimerManager().ClearTimer(TimerHandle);
//		GetWorldTimerManager().SetTimer(TimerHandle, this, &ASword::ResetHit, 1.0f, false, 0.1f);
//
//		//if (bHitDetected == false)
//		//{
//			AMainCharacter* MainChar = Cast<AMainCharacter>(OtherActor);
//			MainChar->setHealth(MainChar->getHealth() - Damage);
//			GLog->Log(FString::Printf(TEXT("PlayerHealth: %f"), MainChar->getHealth()));
//			//GLog->Log(FString::SanitizeFloat(MainChar->GetVelocity().Length()));
//		//}
//		
//	}
//}

void ASword::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (OtherActor && (OtherActor != this))
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlap detected with: %s"), *OtherActor->GetName());
	}
	if (Cast<AMainCharacter>(OtherActor) )
	{
		GetWorldTimerManager().ClearTimer(TimerHandle);
		GetWorldTimerManager().SetTimer(TimerHandle, this, &ASword::ResetHit, 1.0f, false, 1.5f);
		if (bHit == false)
		{
			AMainCharacter* MainChar = Cast<AMainCharacter>(OtherActor);
			MainChar->setHealth(MainChar->getHealth() - Damage);
			bHit = true;
			GLog->Log(FString::Printf(TEXT("PlayerHealth: %f"), MainChar->getHealth()));
		}

	}
}

void ASword::OnOverLapEnd(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this))
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlap Ended with: %s"), *OtherActor->GetName());
	}
	bHit = false;
}

void ASword::ResetHit()
{
	bHitDetected = false;
}

void ASword::setCollisionEnemy()
{
	Mesh->BodyInstance.SetCollisionProfileName(TEXT("Enemy"));
}

void ASword::setCollisionDefault()
{
	Mesh->SetCollisionResponseToAllChannels(ECR_Ignore);
}
