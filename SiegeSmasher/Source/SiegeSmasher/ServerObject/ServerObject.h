// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h" 
#include "../MainCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "ServerObject.generated.h"

UCLASS()
class SIEGESMASHER_API AServerObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AServerObject();
	int GetPlayerCurrentId();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(Server,Reliable) 
	void Server_AssignOwner(APlayerController* Controller);

	void AssignOwner(APlayerController* Controller);

	UFUNCTION(Server,Reliable)
	void Server_IncrementPlayerId();
	UFUNCTION(NetMulticast,Reliable)
	void MultiCast_IncrementPlayerId();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override; 
	void IncrementPlayerId();
private: 

    
	int CurrentPlayerId; 
	int MaxPlayerIdCount;

};
