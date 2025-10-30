// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "GameFramework/Controller.h" 
#include "DrawDebugHelpers.h"




// Sets default values
AMainCharacter::AMainCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	TowerSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn; 
	


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
	AssignedPlayerController = Cast<APlayerController>(Controller);
	if (AssignedPlayerController)
	{
		InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(AssignedPlayerController->GetLocalPlayer());
		if (InputSubsystem)
		{
			//Adding our defaultcontext to the input subsystem that each local player has.
			//The zero refers to its priority. With zero being the lowest priority.
			//If we had multiple we would assign them differnt priority with asscending giving them higher priority.
			InputSubsystem->AddMappingContext(DefaultContext, 0);

		
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

		EnhancedInputComponent->BindAction(TowerPlacementAction, ETriggerEvent::Started, this, &AMainCharacter::PlaceTower);

		EnhancedInputComponent->BindAction(SwitchTowerAction, ETriggerEvent::Started, this, &AMainCharacter::SwitchTowers);




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

void AMainCharacter::PlaceTower()
{
	if (IsPlacingTower && Selected->GetCanPlaceTower() ) {
		
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Placing tower")));
		ATowerBase * TowerRef =  World->SpawnActor<ATowerBase>(TowerTypesToSpawn[SelectedTowerIndex], Selected->GetTransform(), TowerSpawnParameters);
	

	}

}

void AMainCharacter::DisplaySelected()
{
	Selected->SetActorHiddenInGame(false);
	Selected->SetActorEnableCollision(true);


}


void AMainCharacter::HideSelected()
{
	Selected->SetActorHiddenInGame(true);
	Selected->SetActorEnableCollision(false);
	Selected->SetActorTickEnabled(false);

}

void AMainCharacter::HandleTowerPlacement()
{

	if (Selected != nullptr) {
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue,FString::Printf(TEXT("PlayerPlacingTower")));
		FVector PlayerCameForward = camera->GetForwardVector();

		FHitResult PlacementSurfaceResult = FHitResult();

		FVector start = camera->GetComponentLocation() + PlayerCameForward;

		FVector end = start + PlayerCameForward * PlayerPlacementDistances; 
		IsPlacingTower = false;
		

		if ( World->LineTraceSingleByChannel(PlacementSurfaceResult, start, end, PlacingSurface, TraceParams))
		{
			UPrimitiveComponent* HitComponent = PlacementSurfaceResult.GetComponent();

			FVector SurfaceOrigin = HitComponent->GetComponentLocation();
			FTransform SurfaceTransform = HitComponent->GetComponentToWorld();
			FVector SurfaceLocalExtents = HitComponent->GetLocalBounds().GetBox().GetExtent() * SurfaceTransform.GetScale3D();
			FVector CamPos = camera->GetComponentLocation();
			DrawDebugLine(World, start, end, FColor::Blue);
			DrawDebugSphere(World, PlacementSurfaceResult.ImpactPoint, 15.0f, 8, FColor::Green);
			IsPlacingTower =  Selected->ResolvePlacement(SurfaceLocalExtents, SurfaceOrigin, PlacementSurfaceResult.ImpactPoint, PlayerCameForward, CamPos, SurfaceTransform); 
			
			//Selected->SetActorHiddenInGame(IsPlacingTower);
		
			return;
		} 

		



		

	}
	


}


void AMainCharacter::InitialiseTowers()
{

	ATowePrePlaceObjectHelper* currentInstance = nullptr;
	UWorld* world = GetWorld();
	FTransform SpawnTransForm = FTransform();
	FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn; 

	GLog->Log(FString::Printf(TEXT("towers types to spawn count:%d"), TowerTypesToSpawn.Num()));
	for (TSubclassOf<ATowePrePlaceObjectHelper>& towerType : TowerPrePlacementObjectsToSpawn ) {

		currentInstance = world->SpawnActor<ATowePrePlaceObjectHelper>(towerType, SpawnTransForm, SpawnParameters);
		TowerPrePlacementObjects.Add(currentInstance);
		currentInstance->SetActorHiddenInGame(true);
		currentInstance->SetActorEnableCollision(false);
		currentInstance->DisableTick();
		
	
	}


	/*if (TowerPrePlacementObjects.Num() > 0) {

		Selected = TowerPrePlacementObjects[0];
	 	DisplaySelected();

	}*/




}

void AMainCharacter::AlignTowerBeforePlacement()
{
	 
	/*FVector ToSelected = (GetActorLocation() - Selected->GetActorLocation()).GetSafeNormal();
	

	 VectorRegister4 RoundedDiff =  VectorRound(MakeVectorRegisterFloat(ToSelected.X, ToSelected.Y, ToSelected.Z, 0.0f)); 

	 VectorStoreFloat3(RoundedDiff, &ToSelected);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Difference between player %f %f %f"), ToSelected.X, ToSelected.Y, ToSelected.Z));

	FVector Right = ToSelected.Cross(FVector::UpVector); 


	double Angle = atan2(ToSelected.Y,ToSelected.X);
	
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("angle for snapping %f"), FMath::RadiansToDegrees( Angle)));
	*/
	//Selected->SetActorRotation(FQuat(FVector::UpVector, Angle));

	






}

void AMainCharacter::CallCreateLobby()
{
	UWorld* MultiWorld = GetWorld();
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Red, FString::Printf(TEXT("Lobby Created")));
		MultiWorld->ServerTravel("/Game/Lobby?listen");
	}
}

void AMainCharacter::CallClientTravel(const FString& Address)
{
	APlayerController* PlayerController = GetGameInstance()->GetFirstLocalPlayerController();
	if (PlayerController)
	{
		PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
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

void AMainCharacter::SwitchTowers()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Switch  called")));

	TArray<FKey> InputKeysToSwitchTower = InputSubsystem->QueryKeysMappedToAction(SwitchTowerAction);
	for (int i = 0; i < InputKeysToSwitchTower.Num(); i++) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Switch tower called")));
		
		if (i < TowerPrePlacementObjects.Num() && 
			AssignedPlayerController->WasInputKeyJustPressed(InputKeysToSwitchTower[i])) {
			    
		    if (Selected != nullptr) {
				HideSelected();
			}
			    
			SelectedTowerIndex = i;
			Selected = TowerPrePlacementObjects[SelectedTowerIndex];
			DisplaySelected();
			break;
			
		}

	}
	



}
