// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../MyMainCharacterTest.h"
#include "Witch_Projectile.generated.h"

UCLASS()
class SIEGESMASHER_API AWitch_Projectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWitch_Projectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "default")
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "default")
	UStaticMeshComponent* Mesh;

	AMainCharacterTest* Player;
	FVector StartLocation;

	int32 PlayerIndex = 0;
	APawn* PlayerPawn;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	float Damage = 10;
	float StartTime;

	UPROPERTY(EditAnywhere, Category = "Spell Move")
	bool bMove = false;

	void setPlayerIndex(int32 Store);
};
