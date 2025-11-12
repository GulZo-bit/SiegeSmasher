// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components//PrimitiveComponent.h"
#include "Net/UnrealNetwork.h"
#include "Throne.generated.h"

class AMainCharacterTest;
class AEnemyBase;

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
	//material
	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
	UMaterialInstanceDynamic* ThroneMaterialInstance;
	//decreases health variable
	UFUNCTION()
	void DecrementThroneHealth();
	//Calls a function through the player ref to update the widget

	UFUNCTION()
	void UpdateThroneHealth();
	//Replicated using calls the function every time this value is updated on the server
	UPROPERTY(ReplicatedUsing = UpdateThroneHealth)
	int ThroneHealth = 20;
	//gives the throne a reference to the player 
	UFUNCTION()
	void SetPlayerRef(AMainCharacterTest* PlayerPtr);
	//overlapp event that takes away throne health when an enemy overlaps with it
	UFUNCTION()
	void EnemyOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
