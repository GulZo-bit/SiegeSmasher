// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h" 
#include "Components/BoxComponent.h" 
#include  "Net/UnrealNetwork.h"
#include "TowePrePlaceObjectHelper.generated.h"

#ifndef TowerPlacementBoxObjectType
  #define TowerPlacementBoxObjectType ECC_GameTraceChannel9
#endif // !TowerPlacementBoxObjectType

UCLASS()
class SIEGESMASHER_API ATowePrePlaceObjectHelper : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATowePrePlaceObjectHelper();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlacementBox");
	UBoxComponent* BoxColliderForObjectPlacement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlacementSize");
	float PlacementSize = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AllowedPlacementDirectionsCanBeNegative"); 
	bool ShouldSignAllowedDirection = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StartingFacingDirection");
	TArray<FVector> AllowedDirections;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerSurfaceAlignmentVector");
	FVector AlignmentVector = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerSurfaceAlignmentAxis");
	FVector AlignmentAxis = FVector::ZeroVector;
	UFUNCTION()
    void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex ,bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor*  OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:	
	// Called every frame
	bool ResolvePlacement(FVector& SurfaceBoxExtents, FVector& SurfacePos, FVector& PlacementPosition, FVector& CamDir, FVector& CamPos, FTransform& surfaceTransform);
	FVector GetPlacementColliderHalfExtents();
	void DisableTick();
	virtual void Tick(float DeltaTime) override;

	bool GetCanPlaceTower();

private: 
	FVector FacingDirSum;
	bool CanPlaceTower = true;
};
