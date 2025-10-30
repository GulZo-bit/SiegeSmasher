// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Public/MCArrow.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerHud/ChargeWidget.h"
#include "Blueprint/UserWidget.h"
#include "Net/UnrealNetwork.h"
#include "MyMainCharacterTest.generated.h"

UCLASS()
class SIEGESMASHER_API AMainCharacterTest : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacterTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//Camera and Spring arm components
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	UCameraComponent* TPSCameraComponent;
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	USpringArmComponent* SpringArmComponent;

	//Bools that handle animations 
	UPROPERTY(VisibleAnywhere, Category = "Input", Replicated);
	bool ArrowDrawn;

	UPROPERTY(VisibleAnywhere, Category = "Input", Replicated);
	bool ArrowFired;
	
	//flaot and bool for the Charging mechanic 
	UPROPERTY(Replicated);
	float MaxCharge;

	UPROPERTY(Replicated);
	float ChargeRate;

	UPROPERTY(Replicated);
	float CurrentCharge;

	UPROPERTY(Replicated);
	bool isCharging;

	UPROPERTY(Replicated);
	float ChargeFinal;


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

	//Calling for movement input
	void Move(const FInputActionValue& Value);

	//Calling for look input
	void Look(const FInputActionValue& Value);

	//calling for Jump input
	void Jumping();

	//input for triggering the shooting action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* ShootAction;
	//input for triggering the draw action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* DrawAction;
	//input that triggers stop aiming, which makes the player go back to their default animations
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* StopAimAction;

	//Projectile class to spawn.
	UPROPERTY(EditDefaultsOnly, Replicated,  Category = "Projectile")
	TSubclassOf<class AMCArrow> ArrowClass;
	//Static mesh that serves as a spawning point for the arrows
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay");
	UStaticMeshComponent* BowPosition;
	//Reference to the widget that will be created, it has to be a subclass of the UserWidget
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Charge")
	TSubclassOf<class UUserWidget> PlayerHUD;
	//Holds the created widget
	UPROPERTY()
	class UChargeWidget* ChargeWidget;


	//function that handles shooting
	void Shoot();
	//sets bools for animations and starts the charging of the arrow
	void DrawBow();
	//same as draw bow but in reverse
	void StopAim();
	//increments the Current Charge variable
	void ChargeShot(float DeltaTime);

	//getters and seeters for the bools for the animation blueprint
	UFUNCTION(BlueprintCallable)
	bool GetArrowDrawn();

	UFUNCTION(BlueprintCallable)
	void SetArrowDrawn(bool isArrowDrawn);

	UFUNCTION(BlueprintCallable)
	bool GetArrowFired();

	UFUNCTION(BlueprintCallable)
	void SetArrowFired(bool isArrowDrawn);

	UFUNCTION()
	float GetCurrentCharge();
	UFUNCTION(Server, Reliable, WithValidation)
	void Server_SpawnProjectile(FRotator CamRotation, FRotator BowRot);
	void Server_SpawnProjectile_Implementation(FRotator CamRotation, FRotator BowRot);
	bool Server_SpawnProjectile_Validate(FRotator CamRotation, FRotator BowRot);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ChargeShot(float DeltaTime);
	void Server_ChargeShot_Implementation(float DeltaTime);
	bool Server_ChargeShot_Validate(float DeltaTime);

	UFUNCTION(NetMulticast, Reliable, WithValidation)
	void Multi_SpawnProjectile(FRotator CamRotation, FRotator BowRot);
	void Multi_SpawnProjectile_Implementation(FRotator CamRotation, FRotator BowRot);
	bool Multi_SpawnProjectile_Validate(FRotator CamRotation, FRotator BowRot);


	UFUNCTION(NetMulticast, Reliable, WithValidation)
	void Multi_UpdateCharge();
	void Multi_UpdateCharge_Implementation();
	bool Multi_UpdateCharge_Validate();

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_UpdateCharge(float ClientCharge);
	void Server_UpdateCharge_Implementation(float ClientCharge);
	bool Server_UpdateCharge_Validate(float ClientCharge);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_DrawBow();
	void Server_DrawBow_Implementation();
	bool Server_DrawBow_Validate();

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_StopAim();
	void Server_StopAim_Implementation();
	bool Server_StopAim_Validate();
};
