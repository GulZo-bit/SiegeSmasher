// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/SphereComponent.h"
#include "Components//PrimitiveComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerArrow.generated.h"

UCLASS()
class SIEGESMASHER_API APlayerArrow : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerArrow();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	//Sphere collision component, will be used to detect when the projectile hits something
	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile")
	USphereComponent* ArrowCollision;
	//static mesh component for the arrow mesh
	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile")
	UStaticMeshComponent* ArrowMesh;
	// projectile movement component so that the arrow can fly after being shot
	UPROPERTY(VisibleDefaultsOnly, Category = "Movement")
	UProjectileMovementComponent* ArrowMovement;

	// Projectile material
	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile")
	UMaterialInstanceDynamic* ArrowMaterialInstance;
	//function that initialises the arrow in the shoot direction
	void FireInDirection(const FVector& ShootDirection);
};
