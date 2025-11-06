// Fill out your copyright notice in the Description page of Project Settings.


//#include "ServerObject.h"

// Sets default values
//AServerObject::AServerObject()
//{
// 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
//	PrimaryActorTick.bCanEverTick = true;
//	bReplicates = true;
//	CurrentPlayerId = 0;
//	MaxPlayerIdCount = 4; 
//
//
//	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
//
//}
//
//int AServerObject::GetPlayerCurrentId()
//{
//
//	GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Emerald, FString::Printf(TEXT("getting player id from assigned server object %d"), CurrentPlayerId));
//
//
//	return CurrentPlayerId;
//}
//
//// Called when the game starts or when spawned
//void AServerObject::BeginPlay()
//{
//	Super::BeginPlay();
//
//	UWorld* World = GetWorld();
//	if (World != nullptr) {
//		//GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Green, FString::Printf(TEXT("Found world")));
//
//
//		if (APlayerController* PlayerController = GetGameInstance()->GetFirstLocalPlayerController()) {
//
//
//
//			TArray<AActor*> MainChars = {};
//			UGameplayStatics::GetAllActorsOfClass(World, AMainCharacter::StaticClass(), MainChars);
//
//			if (AMainCharacter* MainChar = Cast<AMainCharacter>(UGameplayStatics::GetActorOfClass(World, AMainCharacter::StaticClass())))
//			{
//
//				GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Green, FString::Printf(TEXT(" Found local character num %d"),MainChars.Num()));
//				MainChar->SetPlayerOwnerShip(this);
//				
//				//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("Owner ship was set to SERVER OBJECT")));
//				IncrementPlayerId();
//				
//
//				//MultiCast_IncrementPlayerId();
//
//
//
//
//			}
//
//
//			//if (HasAuthority()) {
//			//	//GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Green, FString::Printf(TEXT("local host Found local player")));
//
//
//			//}
//			//else {
//			//	//GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Green, FString::Printf(TEXT("client Found local player")));
//
//			//}
//
//
//
//
//
//
//
//		}
//	}
//}
//
//
//
//	
//
//
//
//
//
//
//void AServerObject::AssignOwner(APlayerController* Controller)
//{
//	
//		Server_AssignOwner(Controller);
//	
//
//
//}
//void AServerObject::Server_AssignOwner_Implementation(APlayerController* Controller)
//{
//	GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Blue, FString::Printf(TEXT("assigning player controlle on server ")));
//	SetOwner(Controller);
//}
//
//
//void AServerObject::MultiCast_IncrementPlayerId_Implementation()
//{
//	CurrentPlayerId = (CurrentPlayerId + 1) % MaxPlayerIdCount;
//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Incremeting player id new id is %d"),CurrentPlayerId));
//
//	if (HasAuthority()) {
//
//
//		//GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Green, FString::Printf(TEXT("Incremented player id on local host %d"), CurrentPlayerId));
//		//GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Green, FString::Printf(TEXT("max id %d"), MaxPlayerIdCount));
//
//	}
//	else {
//		/*GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Green, FString::Printf(TEXT("Incremented player id on client  %d"), CurrentPlayerId));
//		GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Green, FString::Printf(TEXT("max id %d"), MaxPlayerIdCount));*/
//
//	}
//}
//  
//
//
//
//void AServerObject::Server_IncrementPlayerId_Implementation()
//{ 
//	GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Magenta, FString::Printf(TEXT("SERVER implmentation called")));
//	MultiCast_IncrementPlayerId();
//
//}
//
//
//
//
//// Called every frame
//void AServerObject::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}
//
//void AServerObject::IncrementPlayerId()
//{
//	if (!HasAuthority()) {
//		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Purple, FString::Printf(TEXT("CLIENT DETECTED INCREMENTING PLAYER ID ON SERVER")));
//		Server_IncrementPlayerId();
//
//		return;
//	}
//
//	MultiCast_IncrementPlayerId();
//
//
//	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Incrementing current player id on local host and multicasting to clients new id: %d"), CurrentPlayerId));
//
//
//
//}
//
