// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SphereComponent.h"
#include "Components//PrimitiveComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"
#include "MCArrow.generated.h"

class AMainCharacterTest;

UCLASS()
class SIEGESMASHER_API AMCArrow : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMCArrow();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	AMainCharacterTest* PlayerRef;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//on hit event for the arrow
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	UFUNCTION()
	void ArrowOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	//Sphere collision component, will be used to detect when the projectile hits something
	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile")
	USphereComponent* ArrowCollision;
	//static mesh component for the arrow mesh
	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile")
	UStaticMeshComponent* ArrowMesh;
	// projectile movement component so that the arrow can fly after being shot
	UPROPERTY(VisibleDefaultsOnly, Category = "Movement")
	UProjectileMovementComponent* ArrowMovement;

	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile")
	USphereComponent* SoundTrigger;

	UPROPERTY(EditAnywhere, Category = "Sound")
	USoundBase* WhooshingSound;

	// Projectile material
	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile")
	UMaterialInstanceDynamic* ArrowMaterialInstance;
	//function that initialises the arrow in the shoot direction
	void FireInDirection(const FVector& ShootDirection, float Charge);
	//increments player stats
	void IncrementPlayerPointsRef(int ScoreIncrement);
	void IncrementPlayerKillsRef();
	//sets player ref
	void SetPlayerRef(AMainCharacterTest* PlayerPtr);

	

	float ArrowDamage = 20.0f;
	//getter for damage
	float getDamage(); 


};
