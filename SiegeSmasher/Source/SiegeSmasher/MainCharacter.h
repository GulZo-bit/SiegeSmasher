// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h" 
#include "Camera/CameraComponent.h"
#include "InputActionValue.h"  
#include "../TowerPrePlacementObject/TowePrePlaceObjectHelper.h"
#include "Towers/TowerBase.h" 
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h" 
#include "MainCharacter.generated.h" 


UCLASS()
class SIEGESMASHER_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();
	void SetPlayerOwnerShip(AActor* ActorToOwn);
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input");
	class UInputAction* TowerPlacementAction;

	//Jump Input Action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input");
	class UInputAction* JumpAction;

	//Move input action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input");
	class UInputAction* MoveAction;

	//Look Input Action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input");
	class UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input"); 
	class UInputAction* SwitchTowerAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowersTypesToSpawn");
	TArray<TSubclassOf<ATowerBase>> TowerTypesToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TowerPlacementObjects")
	TArray<TSubclassOf<ATowePrePlaceObjectHelper>> TowerPrePlacementObjectsToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Placement distances");
	FVector PlayerPlacementDistances;

	UFUNCTION(Server, Reliable)
	void Server_SetPlayerOwnerShip(AActor* ActorToOwn);
	
	UFUNCTION(NetMulticast,Reliable)
	void Multicast_SetPlayerOwnerShip(AActor* ActorToOwn);

	

	//Calling for movement input
	void Move(const FInputActionValue& Value);

	//Calling for look input
	void Look(const FInputActionValue& Value);

	void Jumping();

	void PlaceTower();

	void setHealth(float HealthStore);

	float getHealth();  

	void SwitchTowers();

	void SetPlayerId(int Id);

	
	UFUNCTION(Server,Reliable)
	void Server_SetPlayerId(int Id); 
	UFUNCTION(NetMulticast,Reliable)
	void Multicast_SetPlayerId(int Id);
	
	//Online Lobby 
	UFUNCTION(BlueprintCallable)
	void CallCreateLobby();

	

	UFUNCTION(BlueprintCallable)
	void CallClientTravel(const FString& Address);
private:

	UCameraComponent* camera = nullptr;  
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = nullptr;
	TArray<ATowePrePlaceObjectHelper*> TowerPrePlacementObjects;
	ATowePrePlaceObjectHelper* Selected = nullptr;
	UWorld* World = nullptr;  
	APlayerController* AssignedPlayerController = nullptr;
	FActorSpawnParameters TowerSpawnParameters; 
	int PlayerId = 0;

	int SelectedTowerIndex = -1; 
	
	float Health = 100.0f; 
	bool IsPlacingTower = false;

private:


	FCollisionQueryParams TraceParams;
	void DisplaySelected();
	void HideSelected();

	void HandleTowerPlacement();
	void InitialiseTowers();
	void AlignTowerBeforePlacement();


};
