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


// this is a dummy class for when the player is placing the tower it doesnt have any functionaility that the associated tower has but it 
// has the necessary infomration to assits with placing the towers such as the size of their placement box to see if they will algin to a surface
// and the cost of the tower to see if it can be placed based on the players points
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerCost");
	int TowerCost = 0;
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerPlayerRotationInc");
	double PlayerAngleIncrement = 0.0f;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)const;

	UPROPERTY(Replicated);
	double PlayerRotationAngle = 0.0f;


public:	
	// Called every frame
	bool ResolvePlacement(FVector& SurfaceBoxExtents, FVector& SurfacePos, FVector& PlacementPosition, FVector& CamDir, FVector& CamPos, FTransform& surfaceTransform);
	FVector GetPlacementColliderHalfExtents();
	void DisableTick();
	virtual void Tick(float DeltaTime) override;
	int GetTowerCost();
	bool GetCanPlaceTower(); 
	void IncrementPlayerRotAngle();
	void SetPlayerRotationAngle(double Angle);
	float GetPlayerRot();

	

private: 
	FVector FacingDirSum; 
	
	bool CanPlaceTower = true;

};
