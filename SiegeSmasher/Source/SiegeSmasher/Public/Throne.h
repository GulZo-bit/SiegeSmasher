// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components//PrimitiveComponent.h"
#include "Net/UnrealNetwork.h"
#include "Throne.generated.h"

class AMainCharacterTest;

UCLASS()
class SIEGESMASHER_API AThrone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AThrone();
	AMainCharacterTest* PlayerRef = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//Mesh
	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
	UStaticMeshComponent* ThroneMesh;
	//Area the enemies have to reach
	UPROPERTY(VisibleDefaultsOnly, Category = "OverlapArea")
	USphereComponent* ThroneArea;

	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
	UMaterialInstanceDynamic* ThroneMaterialInstance;

	UFUNCTION()
	void DecrementThroneHealth();

	UFUNCTION()
	void UpdateThroneHealth();

	UPROPERTY(ReplicatedUsing = UpdateThroneHealth)
	int ThroneHealth = 20;
	UFUNCTION()
	void SetPlayerRef(AMainCharacterTest* PlayerPtr);

	UFUNCTION()
	void EnemyOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
