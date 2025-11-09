// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMainCharacterTest.h"

// Fill out your copyright notice in the Description page of Project Settings.
#include "DrawDebugHelpers.h"
#include "GameFramework/Controller.h"

// Sets default values
AMainCharacterTest::AMainCharacterTest()
{
	TowerSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;


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
	//Allows the tick function to play
	PrimaryActorTick.bCanEverTick = true;

	//Creates the static mesh and assigns it to the socket 
	BowPosition = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BowPosition"));
	BowPosition->SetupAttachment(AMainCharacterTest::GetMesh(), TEXT("BowPosition"));
	//Default values for the charge mechanic
	isCharging = false;
	MaxCharge = 100.0f;
	CurrentCharge = 0.0f;
	ChargeRate = 50.0f;
}

// Called when the game starts or when spawned
void AMainCharacterTest::BeginPlay()
{
	Super::BeginPlay();
	World = GetWorld();
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
	AssignedPlayerController = Cast<APlayerController>(Controller);

	if (AssignedPlayerController)
	{

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Bgeing play called for character ")));
		InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(AssignedPlayerController->GetLocalPlayer());
		
		if (InputSubsystem)
		{
			//Adding our defaultcontext to the input subsystem that each local player has.
			//The zero refers to its priority. With zero being the lowest priority.
			//If we had multiple we would assign them differnt priority with asscending giving them higher priority.
			InputSubsystem->AddMappingContext(DefaultContext, 0);
		}
	}
	
	ServerObjectRef = Cast<AServerObject>(UGameplayStatics::GetActorOfClass(World,AServerObject::StaticClass()));
	
	//checks if the reference to the player hud is not empty

	if (PlayerHUD != nullptr) 
	{

		if (IsLocallyControlled()) 
		{
			//creates the widget of the ChargeWidget class in the current world
			ChargeWidget = CreateWidget<UChargeWidget>(GetWorld(), PlayerHUD);
			//if the widget was created successfully, add it to viewport

			

			if (ChargeWidget != nullptr )
			{

				ChargeWidget->AddToViewport();
				ChargeWidget->SetHealthAmount(Health);
				
				
				ChargeWidget->SetServerObjectRef(ServerObjectRef);
				ServerObjectRef->SetPlayerStateToHandle(this);

				if (HasAuthority()) {
					ServerObjectRef->SetHost(this);
				}
			}

			
		}
	}
	

	InitialiseTowers();

	TraceParams = FCollisionQueryParams();
	TraceParams.AddIgnoredActor(this);
	GLog->Log(FString::Printf(TEXT("cam is nullptr %d"), (int)(TPSCameraComponent == nullptr)));

	PlayerRespawnPoint = GetActorLocation();


	SetUpPlayerId();


	//RefreshLeaderBoard();
	

}

// Called every frame
void AMainCharacterTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ChargeShot(DeltaTime);
	//if Charge widget is not empty, update the charge amount in the widget
	if (ChargeWidget != nullptr)
	{
		ChargeWidget->SetChargeAmount(CurrentCharge);

		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Leaderboard player count %d"), ChargeWidget->GetLoggedPlayerNum()));


	}
	


	TowerPlacementHandle();

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

		EnhancedInputComponent->BindAction(TowerPlacementAction, ETriggerEvent::Started, this, &AMainCharacterTest::PlaceTower);

		EnhancedInputComponent->BindAction(SwitchTowerAction, ETriggerEvent::Started, this, &AMainCharacterTest::SwitchTowers);
		
		EnhancedInputComponent->BindAction(ToggleTowerPlacementAction, ETriggerEvent::Triggered, this, &AMainCharacterTest::ToggleTowerPlacement);


		EnhancedInputComponent->BindAction(SelfDamage, ETriggerEvent::Triggered, this, &AMainCharacterTest::DamageYourself);
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

	Server_SetPlaceTower(!IsPlacingTower);
	Jump();
}

void AMainCharacterTest::Shoot()
{
	if (TogglePlacingTowers == false)
	{



		//Attempt to shoot a projectile.
		if (ArrowClass)
		{
			// Get the camera transform.
			FVector CameraLocation;
			FRotator CameraRotation;
			GetActorEyesViewPoint(CameraLocation, CameraRotation);
			FRotator BowRotation = CameraRotation;
			//gets the world the player is in
			//UWorld* World = GetWorld();
			if (World)
			{//spawn parameters of the arrow
				if (!HasAuthority())
				{
					//on client 
					Server_UpdateCharge(CurrentCharge);
					//Server_SpawnProjectile(CameraRotation, BowRotation);
					Server_SpawnProjectile(CameraRotation, BowRotation);
					CurrentCharge = 0;
				}

				else
				{
					if (FiringSound != nullptr)
					{
						UGameplayStatics::PlaySoundAtLocation(this, FiringSound, GetActorLocation());
					}
					//on Server
					FActorSpawnParameters SpawnParams;
					SpawnParams.Owner = this;
					SpawnParams.Instigator = GetInstigator();
					//creates an actor of the Arrow class in the world, passes in the class, position to spawm, rotation and the parameters
					AMCArrow* Arrow = World->SpawnActor<AMCArrow>(ArrowClass, BowPosition->GetComponentLocation(), CameraRotation, SpawnParams);


					//if arrow has been succesfully created
					if (Arrow)
					{
						Arrow->SetPlayerRef(this);
						//changes the Bow rotation to be changed into a vector so that it shows a direction
						FVector LaunchDirection = BowRotation.Vector();
						//calls the fire in direction function from the arrow which makes it fly into the direction the player is rotated in, also takes charge to scale arrow speed
						Arrow->FireInDirection(LaunchDirection, CurrentCharge);
						//sets the bools for animations and turns off charging and resets the charge
						SetArrowDrawn(false);
						SetArrowFired(true);
						isCharging = false;
						//UE_LOG(LogTemp, Warning, TEXT("Function called on the server The Charge: %f Percent"), CurrentCharge);
						CurrentCharge = 0;

					}
				}
			}
		}
	}
}

void AMainCharacterTest::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AMainCharacterTest, ArrowDrawn);
	DOREPLIFETIME(AMainCharacterTest, ArrowFired);
	DOREPLIFETIME(AMainCharacterTest, MaxCharge);
	DOREPLIFETIME(AMainCharacterTest, ChargeRate);

	DOREPLIFETIME(AMainCharacterTest, SelectedTowerIndex);
	DOREPLIFETIME(AMainCharacterTest, IsPlacingTower);
	//DOREPLIFETIME(AMainCharacterTest, CurrentCharge);
	DOREPLIFETIME(AMainCharacterTest, isCharging);
	DOREPLIFETIME(AMainCharacterTest, ArrowClass);
	DOREPLIFETIME(AMainCharacterTest, ChargeFinal);  

	DOREPLIFETIME(AMainCharacterTest, Health);

	DOREPLIFETIME(AMainCharacterTest, PlayerPoints); 
	DOREPLIFETIME(AMainCharacterTest, PlayerKills); 
	DOREPLIFETIME(AMainCharacterTest, PlayerId);
	
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

float AMainCharacterTest::GetCurrentCharge()
{
	return CurrentCharge;
}

void AMainCharacterTest::Server_SpawnProjectile_Implementation(FRotator CamRotation, FRotator BowRot)
{

	Multi_PlaySound(FiringSound);
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = GetInstigator();
	AMCArrow* Arrow = GetWorld()->SpawnActor<AMCArrow>(ArrowClass, BowPosition->GetComponentLocation(), CamRotation, SpawnParams);
	//if arrow has been succesfully created
	if (Arrow)
	{

		Arrow->SetPlayerRef(this);
		//changes the Bow rotation to be changed into a vector so that it shows a direction
		FVector LaunchDirection = BowRot.Vector();
		//calls the fire in direction function from the arrow which makes it fly into the direction the player is rotated in, also takes charge to scale arrow speed
		Arrow->FireInDirection(LaunchDirection, ChargeFinal);
		//sets the bools for animations and turns off charging and resets the charge
		SetArrowDrawn(false);
		SetArrowFired(true);
		isCharging = false;
		//UE_LOG(LogTemp, Warning, TEXT("Server Charge: %f Percent"), ChargeFinal);
		CurrentCharge = 0;
	}
}

bool AMainCharacterTest::Server_SpawnProjectile_Validate(FRotator CamRotation, FRotator BowRot)
{
	return true;
}

void AMainCharacterTest::Server_ChargeShot_Implementation(float DeltaTime)
{
	if (isCharging == true)
	{
		CurrentCharge += ChargeRate * DeltaTime;
		CurrentCharge = FMath::Clamp(CurrentCharge, 0.0f, MaxCharge);
	}
}

bool AMainCharacterTest::Server_ChargeShot_Validate(float DeltaTime)
{
	return true;
}

void AMainCharacterTest::Multi_SpawnProjectile_Implementation(FRotator CamRotation, FRotator BowRot)
{
	Multi_UpdateCharge();
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = GetInstigator();
	AMCArrow* Arrow = GetWorld()->SpawnActor<AMCArrow>(ArrowClass, BowPosition->GetComponentLocation(), CamRotation, SpawnParams);
	//if arrow has been succesfully created
	if (Arrow)
	{
		Arrow->SetPlayerRef(this);

		//changes the Bow rotation to be changed into a vector so that it shows a direction
		FVector LaunchDirection = BowRot.Vector();
		//calls the fire in direction function from the arrow which makes it fly into the direction the player is rotated in, also takes charge to scale arrow speed
		Arrow->FireInDirection(LaunchDirection, ChargeFinal);
		//sets the bools for animations and turns off charging and resets the charge
		SetArrowDrawn(false);
		SetArrowFired(true);
		isCharging = false;
		//UE_LOG(LogTemp, Warning, TEXT("Multi Charge: %f Percent"), ChargeFinal);
		CurrentCharge = 0;
	}
}

bool AMainCharacterTest::Multi_SpawnProjectile_Validate(FRotator CamRotation, FRotator BowRot)
{
	return true;
}

void AMainCharacterTest::Multi_UpdateCharge_Implementation()
{
	ChargeFinal = CurrentCharge;
}

bool AMainCharacterTest::Multi_UpdateCharge_Validate()
{
	return true;
}


void AMainCharacterTest::Multicast_UpdateChargeBar_Implementation()
{
	if (ChargeWidget != nullptr)
	{
		CurrentCharge = 0.0f;
		ChargeWidget->SetChargeAmount(CurrentCharge);

	}
}


void AMainCharacterTest::Server_UpdateCharge_Implementation(float ClientCharge)
{
	ChargeFinal = ClientCharge;
	//UE_LOG(LogTemp, Warning, TEXT("Server Charge: %f Percent"), ChargeFinal);
}

bool AMainCharacterTest::Server_UpdateCharge_Validate(float ClientCharge)
{
	return true;
}

void AMainCharacterTest::Server_DrawBow_Implementation()
{
	Multi_PlaySound(DrawingSound);
	SetArrowFired(false);
	SetArrowDrawn(true);
	isCharging = true;
}

bool AMainCharacterTest::Server_DrawBow_Validate()
{
	return true;
}

void AMainCharacterTest::Server_StopAim_Implementation()
{
	SetArrowDrawn(false);
	SetArrowFired(true);
	isCharging = false;

	CurrentCharge = 0.0f;
	Multicast_UpdateChargeBar();

	CurrentCharge = 0.0f;
	if (ChargeWidget != nullptr)
	{
		ChargeWidget->SetChargeAmount(CurrentCharge);
	}
}

bool AMainCharacterTest::Server_StopAim_Validate()
{
	return true;
}

void AMainCharacterTest::DrawBow()
{

	if (IsPlacingTower == false)
	{



		if (!HasAuthority())
		{
			//Client
			Server_DrawBow();

		}
		else
		{
			if (DrawingSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, DrawingSound, GetActorLocation());

			}
			//Server
			SetArrowFired(false);
			SetArrowDrawn(true);
			isCharging = true;
		}
	}
}

void AMainCharacterTest::StopAim()
{
	if (!HasAuthority()) 
	{
		//Client
		Server_StopAim();
	}

	else 
	{
		//Server
		SetArrowDrawn(false);
		SetArrowFired(true);
		isCharging = false;

		CurrentCharge = 0.0f;
		if (ChargeWidget != nullptr)
		{
			ChargeWidget->SetChargeAmount(CurrentCharge);
		}
	}
}

void AMainCharacterTest::ChargeShot(float DeltaTime)
{
	if (isCharging == true) 
	{
		CurrentCharge += ChargeRate * DeltaTime;
		CurrentCharge = FMath::Clamp(CurrentCharge, 0.0f, MaxCharge);
	}
}

void AMainCharacterTest::Multi_PlaySound_Implementation(USoundBase* Sound)
{
	if (Sound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, Sound, GetActorLocation());
	}
}

bool AMainCharacterTest::Multi_PlaySound_Validate(USoundBase* Sound)
{
	return true;
}


void AMainCharacterTest::PlayerDeath()
{
	SetActorLocation(PlayerRespawnPoint);
	DecrementPlayerScore(100);
	if (PlayerPoints < 0)
	{
		PlayerPoints = 0;
	}
	Health = 100.0f;

	if (ChargeWidget != nullptr) {

		UpdateHealthWidget();
	}
}



//Abandon hope all who go past this line

void AMainCharacterTest::Server_SetPlayerOwnerShip_Implementation(AActor* ActorToOwn)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("server ownership of actor changed to player character")));
	Multicast_SetPlayerOwnerShip(ActorToOwn);
}

void AMainCharacterTest::SetPlayerOwnerShip(AActor* ActorToOwn)
{

	if (!HasAuthority()) 
	{
		//Client
		GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Green, FString::Printf(TEXT("setting owner ship of actor on server for client")));
		Server_SetPlayerOwnerShip(ActorToOwn);
	}
	else 
	{
		//Server
		GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Green, FString::Printf(TEXT("setting owner ship of actor on local")));
		Multicast_SetPlayerOwnerShip(ActorToOwn);
	}

}

void AMainCharacterTest::Multicast_SetPlayerOwnerShip_Implementation(AActor* ActorToOwn)
{
	ActorToOwn->SetOwner(Controller);
}


void AMainCharacterTest::PlaceTower()
{

	Server_LogPlaceTower();

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Input to place tower called")));
	SpawnSelected();
}

void AMainCharacterTest::ToggleTowerPlacement()
{
	TogglePlacingTowers = !TogglePlacingTowers;
	
	if (!HasAuthority()) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Toggle place tower client %d"), (int)TogglePlacingTowers));

		Server_ToggleTowers(TogglePlacingTowers);

	}
	else { 
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Toggle place tower local hosts %d"),(int)TogglePlacingTowers));
		if (Selected != nullptr && !TogglePlacingTowers) {
			HideSelected();
		}
	}

}
	





void AMainCharacterTest::DisplaySelected()
{
	if (HasAuthority()) {
		Selected->SetActorHiddenInGame(false);
		Selected->SetActorEnableCollision(true);
	}

}

void AMainCharacterTest::HideSelected()
{
	
	Selected->SetActorHiddenInGame(true);
	Selected->SetActorEnableCollision(false);
	Selected->SetActorTickEnabled(false);
}

void AMainCharacterTest::ClientSwitchTower()
{

	int index = 0;
	TArray<FKey> InputKeysToSwitchTower = InputSubsystem->QueryKeysMappedToAction(SwitchTowerAction);
	for (int i = 0; i < InputKeysToSwitchTower.Num(); i++) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Switch tower called")));

		if (i < TowerPrePlacementObjects.Num() &&
			AssignedPlayerController->WasInputKeyJustPressed(InputKeysToSwitchTower[i])) {

			index = i;
			break;
		}
	}

	


	Server_SwitchTower(index,TogglePlacingTowers);



}

void AMainCharacterTest::HandleTowerPlacement()
{

	if (TogglePlacingTowers && Selected != nullptr) {
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue,FString::Printf(TEXT("PlayerPlacingTower")));
		FVector PlayerCameForward = TPSCameraComponent->GetForwardVector();

		FHitResult PlacementSurfaceResult = FHitResult();

		FVector start = TPSCameraComponent->GetComponentLocation() + PlayerCameForward;

		FVector end = start + PlayerCameForward * PlayerPlacementDistances;
		IsPlacingTower = false;

		if (World->LineTraceSingleByChannel(PlacementSurfaceResult, start, end, PlacingSurface, TraceParams))
		{ 
			DrawDebugLine(World, start, end, FColor::Blue);
			//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("line trace hit")));
			DisplaySelected();

			UPrimitiveComponent* HitComponent = PlacementSurfaceResult.GetComponent();

			FVector SurfaceOrigin = HitComponent->GetComponentLocation();
			FTransform SurfaceTransform = HitComponent->GetComponentToWorld();
			FVector SurfaceLocalExtents = HitComponent->GetLocalBounds().GetBox().GetExtent() * SurfaceTransform.GetScale3D();
			FVector CamPos = TPSCameraComponent->GetComponentLocation();
			DrawDebugLine(World, start, end, FColor::Blue);
			DrawDebugSphere(World, PlacementSurfaceResult.ImpactPoint, 15.0f, 8, FColor::Green);
			IsPlacingTower = Selected->ResolvePlacement(SurfaceLocalExtents, SurfaceOrigin, PlacementSurfaceResult.ImpactPoint, PlayerCameForward, CamPos, SurfaceTransform);

			//Selected->SetActorHiddenInGame(IsPlacingTower);

			return;
		} 

		HideSelected();
	}
}

void AMainCharacterTest::InitialiseTowers()
{

	ATowePrePlaceObjectHelper* currentInstance = nullptr;
	UWorld* world = GetWorld();
	FTransform SpawnTransForm = FTransform();
	FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	GLog->Log(FString::Printf(TEXT("towers types to spawn count:%d"), TowerTypesToSpawn.Num()));
	for (TSubclassOf<ATowePrePlaceObjectHelper>& towerType : TowerPrePlacementObjectsToSpawn) {

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

void AMainCharacterTest::ClientTowerPlacment()
{

	if (TogglePlacingTowers && Selected != nullptr) {
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue,FString::Printf(TEXT("PlayerPlacingTower")));
		FVector PlayerCamForward = TPSCameraComponent->GetForwardVector();

		FHitResult PlacementSurfaceResult = FHitResult();

		FVector start = TPSCameraComponent->GetComponentLocation() + PlayerCamForward;

		FVector end = start + PlayerCamForward * PlayerPlacementDistances;
		


		if (World->LineTraceSingleByChannel(PlacementSurfaceResult, start, end, PlacingSurface, TraceParams))
		{

			Server_DisplaySelected();
			//DrawDebugLine(World, start, end, FColor::Blue);
			//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("line trace hit cleint")));

			
			Server_PushSelected(Selected->GetActorTransform(),start,end,PlayerCamForward);


			//Selected->SetActorHiddenInGame(IsPlacingTower);

			return;
		}

		Server_HideSelected();
	}



}

void AMainCharacterTest::CallCreateLobby()
{
	UWorld* MultiWorld = GetWorld();
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0F, FColor::Red, FString::Printf(TEXT("Lobby Created")));
		MultiWorld->ServerTravel("/Game/Lobby?listen");
	}
}

void AMainCharacterTest::CallClientTravel(const FString& Address)
{
	APlayerController* PlayerController = GetGameInstance()->GetFirstLocalPlayerController();
	if (PlayerController)
	{
		PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
	}
}


void AMainCharacterTest::AdjustLeaderBoardValues(int LeaderboardPlayerPoints, int LeaderboardPlayerKils)
{
	if (HasAuthority()) {


		ServerObjectRef->AdjustLeaderBoardPlayerInfo(LeaderboardPlayerPoints, LeaderboardPlayerKils, PlayerId);



	}


}



void AMainCharacterTest::UpdatePlayerScoreUi()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, FString::Printf(TEXT("Update charge ui called")));
	

	if (ChargeWidget != nullptr) {
		ChargeWidget->SetPoints(PlayerPoints);
	}
	
}


void AMainCharacterTest::MultiCast_UpdateLeaderBoardInfo_Implementation(int NewPlayerPoints, int NewPlayerKills, int TargetPlayerId)
{
	if (ChargeWidget != nullptr) {

		ChargeWidget->UpdatePlayerLeaderBoardInfo(NewPlayerPoints, NewPlayerKills, TargetPlayerId);

	}



}



void AMainCharacterTest::UpdateLeaderBoardInfo()
{
	if (HasAuthority()) {

		ServerObjectRef->UpdateStoredLeaderBoardInfo(PlayerPoints, PlayerKills, PlayerId);
		MultiCast_UpdateLeaderBoardInfo(PlayerPoints, PlayerKills, PlayerId);

		

	}


}

void AMainCharacterTest::DamageYourself()
{
	setHealth(10);
}

void AMainCharacterTest::UpdateHealthWidget()
{
	if (ChargeWidget != nullptr) 
	{

		ChargeWidget->SetHealthAmount(Health);
	}
}
void AMainCharacterTest::SetUpPlayerId()
{

	if (HasAuthority() && ServerObjectRef != nullptr) {

		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Magenta, FString::Printf(TEXT("INCREMENTING PLAYER ID ON SERVER OBJECT BEFORE INCREMENT %d"),ServerObjectRef->GetPlayerCurrentCount()));
		ServerObjectRef->IncrementPlayerCount();
		PlayerId = ServerObjectRef->GetCurrentPlayerId();  

	
		/*GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Orange, FString::Printf(TEXT("PLAYER ID ON SERVER %d"), PlayerId));

		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("INCREMENTING PLAYER ID ON SERVER OBJECT AFTER INCREMENT %d"), ServerObjectRef->GetPlayerCurrentCount()));*/

	}
	

}



void AMainCharacterTest::Multicast_SetLeaderBoardTxt_Implementation(int NewPlayerPoints, int NewPlayerKills, int LeaderboardPlayerId)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("multi cast to set leaderboard called")));
	if (ChargeWidget != nullptr) {

		//ChargeWidget->UpdatePlayerLeaderBoardInfo(NewPlayerPoints, NewPlayerKills, LeaderboardPlayerId);



	}

}

void AMainCharacterTest::setHealth(float HealthStore)
{
	if (HasAuthority()) 
	{
		Health = HealthStore;
		if (ChargeWidget != nullptr)
		{
			ChargeWidget->SetHealthAmount(Health);
		}

		if (Health <= 0)
		{
			PlayerDeath();
		}

	}
	else 
	{
		Server_SetHealth(HealthStore);
	}
}

void AMainCharacterTest::Server_SetHealth_Implementation(float HealthStore)
{
	Health = HealthStore;

	if (Health <= 0)
	{
		PlayerDeath();

	}

}

void AMainCharacterTest::PlayImpactSound()
{
	if (ArrowImpact != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, ArrowImpact, GetActorLocation());
	}
}

float AMainCharacterTest::getHealth()
{
	return Health;
}





void AMainCharacterTest::SwitchTowers()
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
			if (TogglePlacingTowers) {
				DisplaySelected();
			}
		
			break;

		}
		}
	
	if(!HasAuthority()) { 
		ClientSwitchTower();
	}
	
}




void AMainCharacterTest::TowerPlacementHandle()
{
	if (!HasAuthority() ) {
		
		ClientTowerPlacment();
	}
	else if(IsLocallyControlled()) {

		HandleTowerPlacement();

	}



}

void AMainCharacterTest::Server_HandleTowerPlacement_Implementation(FVector CamFoward, FVector CamPosition)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Tower placement server called")));
	if (Selected != nullptr) {
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("PlayerPlacingTower")));
		
		FVector PlayerCamForward = CamFoward;

		FHitResult PlacementSurfaceResult = FHitResult();

		FVector start = CamPosition + PlayerCamForward;

		FVector end = start + PlayerCamForward * PlayerPlacementDistances;


		if (World->LineTraceSingleByChannel(PlacementSurfaceResult, start, end, PlacingSurface, TraceParams))
		{
			DrawDebugLine(World, start, end, FColor::Blue);
			//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("line trace hit")));

			UPrimitiveComponent* HitComponent = PlacementSurfaceResult.GetComponent();

			FVector SurfaceOrigin = HitComponent->GetComponentLocation();
			FTransform SurfaceTransform = HitComponent->GetComponentToWorld();
			FVector SurfaceLocalExtents = HitComponent->GetLocalBounds().GetBox().GetExtent() * SurfaceTransform.GetScale3D();
			DrawDebugLine(World, start, end, FColor::Blue);
			DrawDebugSphere(World, PlacementSurfaceResult.ImpactPoint, 15.0f, 8, FColor::Green);
		    Server_SetPlaceTower(  Selected->ResolvePlacement(SurfaceLocalExtents, SurfaceOrigin, PlacementSurfaceResult.ImpactPoint, PlayerCamForward, CamPosition, SurfaceTransform));
			//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("is placing tower is %d"), (int)IsPlacingTower));
			//Selected->SetActorHiddenInGame(IsPlacingTower);

			return;
		}
		Server_SetPlaceTower(false);

	}

}



void AMainCharacterTest::Server_SetPlaceTower_Implementation(bool PlaceTower)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Silver, FString::Printf(TEXT("Set place tower called %d "), PlaceTower));
	IsPlacingTower = PlaceTower;
}


void AMainCharacterTest::SpawnSelected()
{

	if (HasAuthority() && IsLocallyControlled()) {
		if (TogglePlacingTowers 
			&& IsPlacingTower 
			&& Selected->GetCanPlaceTower() 
			&& PlayerPoints >= Selected->GetTowerCost()) 
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("local host Placing tower")));
			ATowerBase* TowerRef = World->SpawnActor<ATowerBase>(TowerTypesToSpawn[SelectedTowerIndex], Selected->GetTransform(), TowerSpawnParameters);
			if (TowerRef) {
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Local Host Set Owner")));
				TowerRef->SetOwner(Controller); 
				TowerRef->SetPlayerRef(this);
				DecrementPlayerScore(Selected->GetTowerCost());
				//TowerRef->SetPlayerRef(this);

			}
		}
	}
	else {
		//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("client  tower")));
		
		Server_SpawnSelected(IsPlacingTower,TogglePlacingTowers);
	}

}
void AMainCharacterTest::Server_LogPlaceTower_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("is placing tower %d"), (int)IsPlacingTower));
}
void AMainCharacterTest::Server_PushSelected_Implementation(FTransform ClientSelectedTransform, FVector SelectRayStart, FVector SelectRayEnd,FVector SelectedRayDir)
{

	if (Selected != nullptr) {
		FHitResult result = FHitResult(); 
		
		if (World->LineTraceSingleByChannel(result, SelectRayStart, SelectRayEnd, PlacingSurface)) {

			DrawDebugLine(World, SelectRayStart, SelectRayEnd, FColor::Magenta);
			UPrimitiveComponent* HitComponent = result.GetComponent();

			FVector SurfaceOrigin = HitComponent->GetComponentLocation();
			FTransform SurfaceTransform = HitComponent->GetComponentToWorld();
			FVector SurfaceLocalExtents = HitComponent->GetLocalBounds().GetBox().GetExtent() * SurfaceTransform.GetScale3D();
			DrawDebugSphere(World, result.ImpactPoint, 15.0f, 8, FColor::Green);
			IsPlacingTower = Selected->ResolvePlacement(SurfaceLocalExtents, SurfaceOrigin, result.ImpactPoint, SelectedRayDir, SelectRayStart, SurfaceTransform);


			//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("line trace hit server")));

			return;
		}
		
		HideSelected();
		


	}
	//Multicast_PushSelected(ClientSelectedTransform, SelectRayStart, SelectRayEnd, SelectedRayDir);



}
void AMainCharacterTest::Multicast_PushSelected_Implementation(FTransform ClientSelectedTransform, FVector SelectRayStart, FVector SelectRayEnd, FVector SelectedRayDir)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("multi cast push selected")));
	
	if (Selected != nullptr) {
		FHitResult result = FHitResult();
		if (World->LineTraceSingleByChannel(result, SelectRayStart, SelectRayEnd, PlacingSurface)) {

			DrawDebugLine(World, SelectRayStart, SelectRayEnd, FColor::Magenta);
			UPrimitiveComponent* HitComponent = result.GetComponent();

			FVector SurfaceOrigin = HitComponent->GetComponentLocation();
			FTransform SurfaceTransform = HitComponent->GetComponentToWorld();
			FVector SurfaceLocalExtents = HitComponent->GetLocalBounds().GetBox().GetExtent() * SurfaceTransform.GetScale3D();
			DrawDebugSphere(World, result.ImpactPoint, 15.0f, 8, FColor::Green);
			IsPlacingTower = Selected->ResolvePlacement(SurfaceLocalExtents, SurfaceOrigin, result.ImpactPoint, SelectedRayDir, SelectRayStart, SurfaceTransform);


			//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("line trace hit server")));


		}



	}


}
void AMainCharacterTest::Server_SpawnSelected_Implementation(bool PlacingTower,bool ToggleTower)
{
	//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("client Placing tower selected get can place tower %d"), (int)IsPlacingTower));
	
	if (ToggleTower && IsPlacingTower && 
		Selected->GetCanPlaceTower() && 
		PlayerPoints >= Selected->GetTowerCost() ) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("client Placing tower")));
		ATowerBase* TowerRef = World->SpawnActor<ATowerBase>(TowerTypesToSpawn[SelectedTowerIndex], Selected->GetTransform(), TowerSpawnParameters);
		if (TowerRef) {
			TowerRef->SetPlayerRef(this);
			DecrementPlayerScore(Selected->GetTowerCost());

		}
	}
	
}

void AMainCharacterTest::Server_RefreshLeaderboard_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("server refreshing leaderboard for client with id %d"), PlayerId));
	Multicast_RefreshLeaderboard();


}

void AMainCharacterTest::Multicast_RefreshLeaderboard_Implementation()
{

	if (ChargeWidget != nullptr && ServerObjectRef != nullptr) {

		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT(" multi cats called refreshing leaderboard for player with id %d"), PlayerId));
		ChargeWidget->RefreshPlayerLeaderboardInfo();


	}


}

void AMainCharacterTest::RefreshLeaderBoard()
{
	
	if (HasAuthority() ) {

		//GEngine->AddOnScreenDebugMessage(-1,25.0f,FColor::Magenta,FString::Printf(TEXT("SERVER OBJECT HOST WAS NULL %d"), (int)(ServerObjectRef->GetHost() == nullptr)));
		
		Multicast_RefreshLeaderboard();
		/*if (ChargeWidget == nullptr) {
			ServerObjectRef->GetHost()->RefreshLeaderBoard();
			return;
		}*/
		
	
		
	}
	else {
		Server_RefreshLeaderboard();

	}


	
}	
	





void AMainCharacterTest::Server_SwitchTower_Implementation(int NewSelectedIndex, bool ToggleTower)
{
	 
	if (Selected != nullptr) {
		HideSelected();
	}
	SelectedTowerIndex = NewSelectedIndex;
	Selected = TowerPrePlacementObjects[SelectedTowerIndex];
	if (ToggleTower) {
		DisplaySelected();
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("updating selected index on client %d "),SelectedTowerIndex));

}

void AMainCharacterTest::Server_HideSelected_Implementation()
{

	HideSelected();



}

void AMainCharacterTest::Server_DisplaySelected_Implementation()
{
	DisplaySelected();


}

void AMainCharacterTest::Server_AssignPlayerId_Implementation(int Id)
{

	PlayerId = Id;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Incemeting player count for leader board %d"), PlayerId));


}






void AMainCharacterTest::Server_IncrementLoggedPlayerCount_Implementation()
{
	if ( HasAuthority() && ServerObjectRef != nullptr) {

		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Magenta, FString::Printf(TEXT("INCREMENTING PLAYER ID FOR CLIENT SERVER OBJECT ID BEFORE INC %d"), ServerObjectRef->GetPlayerCurrentCount()));
		ServerObjectRef->IncrementPlayerCount();  

		PlayerId = ServerObjectRef->GetCurrentPlayerId();

		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Orange, FString::Printf(TEXT("INCREMENTED PLAYER ID ON CLIENT %d"), PlayerId));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("PLAYER ID FOR CLIENT SERVER OBJECT ID AFTER INC %d"), ServerObjectRef->GetPlayerCurrentCount()));

	}
	

}

int AMainCharacterTest::GetScore()
{
	return PlayerPoints;
}

int AMainCharacterTest::GetKills()
{
	return PlayerKills;
}

void AMainCharacterTest::Server_ToggleTowers_Implementation(bool ToggleTower)
{
	if (Selected != nullptr && !ToggleTower) {

		HideSelected();

	}


}
void AMainCharacterTest::IncrementPlayerScore(int Increment)
{
	
	if (HasAuthority()) { 


		PlayerPoints += Increment;  
		if (IsLocallyControlled()) {
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Incrementing player score server %d "), PlayerPoints));

			UpdatePlayerScoreUi();
		}
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Incrementing player score %d "), PlayerPoints));
	}


}



void AMainCharacterTest::DecrementPlayerScore(int Increment)
{

	if (HasAuthority()) {


		PlayerPoints -= Increment;
		if (IsLocallyControlled()) {
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Incrementing player score server %d "), PlayerPoints));

			UpdatePlayerScoreUi();
		}
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Incrementing player score %d "), PlayerPoints));
	}


}


void AMainCharacterTest::IncrementPlayerKills()
{

	
	if (HasAuthority()) {
		PlayerKills++; 
		
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Incrementing Player kills %d"), PlayerKills));
	}

}

UChargeWidget* AMainCharacterTest::GetPlayerWidget()
{
	return ChargeWidget;
}


