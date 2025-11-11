// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/HealAuraLight.h"

// Sets default values
AHealAuraLight::AHealAuraLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OuterSpotLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("OuterSpotLight"));
	InnerSpotLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("InnerSpotLight"));
	LightTimeLineComp = CreateDefaultSubobject<UTimelineComponent>(TEXT("TimelineComp"));

	RootComponent = OuterSpotLight;
	InnerSpotLight->AttachToComponent(OuterSpotLight, FAttachmentTransformRules::KeepRelativeTransform);
	BrightnessMultiplier = 20.0f;

	bReplicates = true;
}

// Called when the game starts or when spawned
void AHealAuraLight::BeginPlay()
{
	Super::BeginPlay();
	
	UpdateBrightnessTrack.BindDynamic(this, &AHealAuraLight::UpdateLightBrightness);

	if (LightFloatCurve)
	{
		GLog->Log("Found Float Curve");
		LightTimeLineComp->AddInterpFloat(LightFloatCurve, UpdateBrightnessTrack);
	}

	//LightTimeLineComp->Play();
}

void AHealAuraLight::UpdateLightBrightness(float BrightnessOutput)
{
	GLog->Log("Updating brightness");
	/*OuterSpotLight->SetLightBrightness(BrightnessOutput * 20.0f);
	InnerSpotLight->SetLightBrightness(BrightnessOutput * 20.0f);*/
	OuterSpotLight->SetIntensity(BrightnessOutput * 20.0f);
	InnerSpotLight->SetIntensity(BrightnessOutput * 20.0f);
}

// Called every frame
void AHealAuraLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UTimelineComponent* AHealAuraLight::getLightTimeLineComp()
{
	return LightTimeLineComp;
}

