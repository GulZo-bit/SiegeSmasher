// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PlayerArrow.h"
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

	UPROPERTY(VisibleAnywhere, Category = "Input");
	bool ArrowDrawn;

	UPROPERTY(VisibleAnywhere, Category = "Input");
	bool ArrowFired;
	
	UPROPERTY();
	float MaxCharge;

	UPROPERTY();
	float ChargeRate;

	UPROPERTY();
	float CurrentCharge;

	UPROPERTY();
	bool isCharging;

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

	void Jumping();

	//input for triggering the shooting action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* ShootAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* DrawAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* StopAimAction;
	//Offset of the bow from the camera
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FVector BowOffset;

	//Projectile class to spawn.
	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	TSubclassOf<class APlayerArrow> ArrowClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay");
	UStaticMeshComponent* BowPosition;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Charge")
	TSubclassOf<class UUserWidget> PlayerHUD;

	UPROPERTY()
	class UChargeWidget* ChargeWidget;


	//function that handles shooting
	void Shoot();

	void DrawBow();

	void StopAim();

	void ChargeShot(float DeltaTime);

	UFUNCTION(BlueprintCallable)
	bool GetArrowDrawn();

	UFUNCTION(BlueprintCallable)
	void SetArrowDrawn(bool isArrowDrawn);

	UFUNCTION(BlueprintCallable)
	bool GetArrowFired();

	UFUNCTION(BlueprintCallable)
	void SetArrowFired(bool isArrowDrawn);
};
