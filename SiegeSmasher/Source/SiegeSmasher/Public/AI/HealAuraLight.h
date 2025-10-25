// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "Components/SpotLightComponent.h"
#include "HealAuraLight.generated.h"

UCLASS()
class SIEGESMASHER_API AHealAuraLight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHealAuraLight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FOnTimelineFloat UpdateBrightnessTrack;

	UFUNCTION()
	void UpdateLightBrightness(float BrightnessOutput);

	UPROPERTY(EditDefaultsOnly)
	float BrightnessMultiplier;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UCurveFloat* LightFloatCurve;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SpotLight")
	USpotLightComponent* OuterSpotLight;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SpotLight")
	USpotLightComponent* InnerSpotLight;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "TimeLine")
	UTimelineComponent* LightTimeLineComp;

	UTimelineComponent* getLightTimeLineComp();
};
