// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "GameFramework/Controller.h" 
#include "DrawDebugHelpers.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h" 

#define PlacingSurface ECC_GameTraceChannel1

// Sets default values
AMainCharacter::AMainCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;




}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	camera = GetComponentByClass<UCameraComponent>();
	World = GetWorld();
	InitialiseTowers();
	TraceParams = FCollisionQueryParams();
	TraceParams.AddIgnoredActor(this);
	GLog->Log(FString::Printf(TEXT("cam is nullptr %d"), (int)(camera == nullptr)));
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
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector camForward = camera->GetForwardVector();
	//   GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Blue,FString::Printf(TEXT("Cam forward vector X:%f Y:%f Z:%f"),	camForward.X,camForward.Y,camForward.Z));
	   //GLog->Log(FString::Printf(TEXT("Cam forward vector X:%f Y:%f Z:%f"), camForward.X, camForward.Y, camForward.Z));

	HandleTowerPlacement();

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	//Setting up the actual bindings to the keys now.
	//We check if the EnhancedInputComponenet has been casted to the PlayerInputComponent. If the check returns false the program will crash.
	//Because the player wont be able to do any actions.
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AMainCharacter::Jumping);

		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMainCharacter::Move);

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMainCharacter::Look);

	}
}

void AMainCharacter::Move(const FInputActionValue& Value)
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

void AMainCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		//Add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AMainCharacter::Jumping()
{
	Jump();
}

void AMainCharacter::DisplaySelected()
{
	Selected->SetActorHiddenInGame(false);


}


void AMainCharacter::HideSelected()
{
	Selected->SetActorHiddenInGame(true);
	Selected->SetActorEnableCollision(false);

}

void AMainCharacter::HandleTowerPlacement()
{

	FVector PlayerCameForward = camera->GetForwardVector();

	FHitResult PlacementSurfaceResult = FHitResult();

	FVector start = camera->GetComponentLocation() + PlayerCameForward;

	FVector end = start + PlayerCameForward * PlayerPlacementDistances;
	DrawDebugLine(World, start, end, FColor::Blue);
	DrawDebugSphere(World, PlacementSurfaceResult.ImpactPoint, 15.0f, 8, FColor::Green);

	if (World->LineTraceSingleByChannel(PlacementSurfaceResult, start, end, PlacingSurface, TraceParams))
	{
		FVector SurfaceExtents = PlacementSurfaceResult.GetComponent()->GetCollisionShape().GetBox();
		FVector SurfaceOrigin = PlacementSurfaceResult.GetComponent()->GetComponentLocation();

		Selected->ResolvePlacement(SurfaceExtents, SurfaceOrigin, PlacementSurfaceResult.ImpactPoint, PlayerCameForward);
	};


}

void AMainCharacter::InitialiseTowers()
{

	ATowerBase* currentInstance = nullptr;
	UWorld* world = GetWorld();
	FTransform SpawnTransForm = FTransform();
	FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	GLog->Log(FString::Printf(TEXT("towers types to spawn count:%d"), TowerTypesToSpawn.Num()));
	for (TSubclassOf<ATowerBase>& towerType : TowerTypesToSpawn) {

		currentInstance = world->SpawnActor<ATowerBase>(towerType, SpawnTransForm, SpawnParameters);
		TowersToSpawn.Add(currentInstance);
		currentInstance->SetActorHiddenInGame(true);
		currentInstance->SetActorEnableCollision(false);
		currentInstance->SetActorTickEnabled(false);

	}


	if (TowersToSpawn.Num() > 0) {

		Selected = TowersToSpawn[0];
		DisplaySelected();

	}




}

void AMainCharacter::setHealth(float HealthStore)
{
	Health = HealthStore;
}

float AMainCharacter::getHealth()
{
	return Health;
}
