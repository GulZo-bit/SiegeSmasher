// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h" 
#include "../Enemies/EnemyBase.h"
#include "TowerProjectileBase.generated.h"

UCLASS()
class SIEGESMASHER_API ATowerProjectileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATowerProjectileBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileDamage"); 
	float Damage = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileMesh");
	UStaticMeshComponent* ProjectileMesh; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileSpeed")
	float ProjectileSpeed = 0.0f; 


	
	UFUNCTION()
	virtual void OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	AEnemyBase* Target = nullptr; 
	float InitalPitch = 0.0f;

	
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetEnemyTarget(AEnemyBase * Enemy); 

	virtual void MoveToTarget(float DeltaTime); 
	void SetInitialPitch(float Pitch); 
	
private:
	FVector TargetPosition = FVector::ZeroVector;
	UWorld* World = nullptr;
};
