// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "CheckPointTrigger.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SIEGESMASHER_API UCheckPointTrigger : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCheckPointTrigger();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void GetAllValidActors(float DeltaTime);
	
	//Setters
	void setIndexTrigger(int32 TriggerIndexStore);

	//Getters
	int32 getIndexTrigger();
	bool getBDone();
private:
	UPROPERTY(EditAnywhere, Category = "CheckpointTriggers")
	ATriggerVolume* TriggerVol;

	FVector CurrentLocation;
	int32 TriggerIndex = 0;
	bool bDone = false;
};
