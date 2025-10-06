// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/CheckPointTrigger.h"

// Sets default values for this component's properties
UCheckPointTrigger::UCheckPointTrigger()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
	// ...
}


// Called when the game starts
void UCheckPointTrigger::BeginPlay()
{
	Super::BeginPlay();
	CurrentLocation = GetOwner()->GetActorLocation();
	// ...
	
}


// Called every frame
void UCheckPointTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	GetAllValidActors(DeltaTime);
	// ...
}

void UCheckPointTrigger::GetAllValidActors(float DeltaTime)
{
	TArray<AActor*> OverlappingActors;

	if (TriggerVol != nullptr)
	{
		TriggerVol->GetOverlappingActors(OverlappingActors);

		for (AActor* Actor : OverlappingActors)
		{
			for (FName Tag : Actor->Tags)
			{
				GLog->Log(Tag.ToString());

				if (Tag == "Enemy" && bDone == false)
				{
					TriggerIndex += 1;
					bDone = true;
				}
			}
		}
	}
}

void UCheckPointTrigger::setIndexTrigger(int32 TriggerIndexStore)
{
	TriggerIndex = TriggerIndexStore;
}

int32 UCheckPointTrigger::getIndexTrigger()
{
	return TriggerIndex;
}

