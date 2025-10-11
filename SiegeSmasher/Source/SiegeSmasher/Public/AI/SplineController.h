// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "SplineController.generated.h"

UCLASS()
class SIEGESMASHER_API ASplineController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASplineController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SplineController")
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SplineController")
	USplineComponent* Spline;

	UPROPERTY(EditAnywhere, Category = "SplineController")
	float TotalPathTimeController;

	float StartTime;

	UPROPERTY(EditDefaultsOnly, Category = "SplineController")
	TSubclassOf<class AActor> ActorToMoveClass;

	class AActor* ActorToMove;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void setTotalPathTimeController(float TotalPathTimeStore);

	float getTotalPathTimeController();

	USplineComponent* getSpline();
};
