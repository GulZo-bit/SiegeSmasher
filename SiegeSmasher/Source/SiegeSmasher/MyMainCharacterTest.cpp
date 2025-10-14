// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMainCharacterTest.h"

// Fill out your copyright notice in the Description page of Project Settings.
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h" 


// Sets default values
AMainCharacterTest::AMainCharacterTest()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a Spring Arm Component
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	//Spring Arm Component is attached to Mesh
	SpringArmComponent->SetupAttachment(CastChecked<USceneComponent,
		UCapsuleComponent>(GetCapsuleComponent()));
	// Create a Third person camera component.
	TPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCamera"));
	//Attach CameraComponent as a child of Spring Arm
	TPSCameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);

	
}

// Called when the game starts or when spawned
void AMainCharacterTest::BeginPlay()
{
	Super::BeginPlay();

	if (SpringArmComponent != nullptr)
	{
		//Set Location and Rotation
		SpringArmComponent->SetRelativeLocation(FVector(0.0f, 80.0f, 100.0f));
		SpringArmComponent->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
		// Set How far away from character
		SpringArmComponent->TargetArmLength = 250.0f;
		// Set camera lag behaviour
		SpringArmComponent->bEnableCameraLag = true;
		SpringArmComponent->CameraLagSpeed = 20.0f;
	}
	if (TPSCameraComponent != nullptr)
	{
		// Camera pawn rotation must be enabled to allow player to move camera
		TPSCameraComponent->bUsePawnControlRotation = true;
	}

	//Adding the input mapping context to the main character
	/*A reference to the player controller class is being cast to the controller that is currently controlling this actor*/
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			//Adding our defaultcontext to the input subsystem that each local player has.
			//The zero refers to its priority. With zero being the lowest priority.
			//If we had multiple we would assign them differnt priority with asscending giving them higher priority.
			Subsystem->AddMappingContext(DefaultContext, 0);
		}
	}
}

// Called every frame
void AMainCharacterTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacterTest::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	//Setting up the actual bindings to the keys now.
	//We check if the EnhancedInputComponenet has been casted to the PlayerInputComponent. If the check returns false the program will crash.
	//Because the player wont be able to do any actions.
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AMainCharacterTest::Jumping);

		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMainCharacterTest::Move);

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMainCharacterTest::Look);

		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Triggered, this, &AMainCharacterTest::Shoot);

		EnhancedInputComponent->BindAction(DrawAction, ETriggerEvent::Triggered, this, &AMainCharacterTest::DrawBow);

		EnhancedInputComponent->BindAction(StopAimAction, ETriggerEvent::Triggered, this, &AMainCharacterTest::StopAim);

	}
}

void AMainCharacterTest::Move(const FInputActionValue& Value)
{
	//Input is a Vector2d
	FVector2D MovementVector = Value.Get<FVector2D>();

	//This is if the user is using a controller
	if (Controller != nullptr)
	{
		//Find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		//Get the forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		//Get the right vector
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		//Add movement
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AMainCharacterTest::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		//Add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AMainCharacterTest::Jumping()
{
	Jump();
}

void AMainCharacterTest::Shoot()
{
	//Attempt to shoot a projectile.
	if (ArrowClass)
	{
		// Get the camera transform.
		FVector CameraLocation;
		FRotator CameraRotation;
		GetActorEyesViewPoint(CameraLocation, CameraRotation);
		// Set MuzzleOffset to spawn projectiles slightly in front of the camera.
		BowOffset.Set(0.0f, 10.0f, 0.0f);
		// Transform MuzzleOffset from camera space to world space.
		FVector BowLocation = CameraLocation + FTransform(CameraRotation).TransformVector(BowOffset);
		FRotator BowRotation = CameraRotation;

		UWorld* World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();

			APlayerArrow* Arrow = World->SpawnActor<APlayerArrow>(ArrowClass, BowLocation, CameraRotation, SpawnParams);

			if (Arrow)
			{
				FVector LaunchDirection = BowRotation.Vector();
				Arrow->FireInDirection(LaunchDirection);
				SetArrowDrawn(false);
				SetArrowFired(true);
			}
		}
	}
}

void AMainCharacterTest::DrawBow()
{
	SetArrowFired(false);
	SetArrowDrawn(true);
	//UE_LOG(LogTemp, Warning, TEXT("bIsActive: %s"), ArrowDrawn ? TEXT("true") : TEXT("false"));
}

bool AMainCharacterTest::GetArrowDrawn()
{
	return ArrowDrawn;
}

void AMainCharacterTest::SetArrowDrawn(bool isArrowDrawn)
{
	ArrowDrawn = isArrowDrawn;
}

bool AMainCharacterTest::GetArrowFired()
{
	return ArrowFired;
}

void AMainCharacterTest::SetArrowFired(bool wasArrowShot)
{
	ArrowFired = wasArrowShot;
}

void AMainCharacterTest::StopAim()
{
	SetArrowDrawn(false);
	SetArrowFired(true);
}

