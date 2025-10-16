// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h" 
#include "Camera/CameraComponent.h"
#include "InputActionValue.h" 
#include "Towers/TowerBase.h"
#include "MainCharacter.generated.h"

UCLASS()
class SIEGESMASHER_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input");
	class UInputMappingContext* DefaultContext; //The defult input mapping context. This will change depending on what context the player is in such as driving.

	//Jump Input Action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input");
	class UInputAction* JumpAction;

	//Move input action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input");
	class UInputAction* MoveAction;

	//Look Input Action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input");
	class UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowersTypesToSpawn");
	TArray<TSubclassOf<ATowerBase>> TowerTypesToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Placement distances");
	FVector PlayerPlacementDistances;




	//Calling for movement input
	void Move(const FInputActionValue& Value);

	//Calling for look input
	void Look(const FInputActionValue& Value);

	void Jumping();

	void setHealth(float HealthStore);

	float getHealth();

	//Online Lobby 
	UFUNCTION(BlueprintCallable)
	void CallCreateLobby();

	UFUNCTION(BlueprintCallable)
	void CallClientTravel(const FString& Address);
private:

	UCameraComponent* camera;
	TArray<ATowerBase*> TowersToSpawn;
	ATowerBase* Selected;
	UWorld* World;

	float Health = 100.0f;

private:


	FCollisionQueryParams TraceParams;
	void DisplaySelected();
	void HideSelected();

	void HandleTowerPlacement();
	void InitialiseTowers();


};
