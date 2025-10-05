// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Math/MathFwd.h"
#include "TowerBase.generated.h"

UCLASS()
class SIEGESMASHER_API ATowerBase : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ATowerBase();
	UFUNCTION(BlueprintCallable, Category = "PlacementCollisionResolution")
	FVector GetPlacementColliderHalfExtents();
	UFUNCTION(BlueprintCallable, Category = "PlacementCollisionResolution")
	void ResolvePlacement(FVector SurfaceHalfExtents, FVector SurfacePos, FVector PlacementPosition, FVector CamDir);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticMeshForTower");
	UStaticMeshComponent* StaticMeshForTower;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlacementCollider");
	UBoxComponent* BoxColliderForObjectPlacement;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
