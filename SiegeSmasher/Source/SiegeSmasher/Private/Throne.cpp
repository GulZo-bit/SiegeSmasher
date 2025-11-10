// Fill out your copyright notice in the Description page of Project Settings.


#include "Throne.h"
#include "../MyMainCharacterTest.h"
#include "SiegeSmasher/Enemies/EnemyBase.h"

// Sets default values
AThrone::AThrone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;
	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ThroneSceneComponent"));
	}

	if (!ThroneMesh)
	{
		//sets the static mesh to the Arrow static mesh
		ThroneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ThroneMesh"));
		static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh
		(TEXT("Game/Dwarven_city/Meshes/Throne/SM_Throne.SM_Throne"));

		if (Mesh.Succeeded())
		{
			ThroneMesh->SetStaticMesh(Mesh.Object);
		}

		static ConstructorHelpers::FObjectFinder<UMaterial>Material
		(TEXT("Game/Dwarven_city/Materials/MI_throne.MI_throne"));
		if (Material.Succeeded())
		{
			ThroneMaterialInstance = UMaterialInstanceDynamic::Create(Material.Object, ThroneMesh);
		}
		ThroneMesh->SetupAttachment(RootComponent);
	}
	if (!ThroneArea) 
	{
		// Use a sphere as a simple collision representation.
		ThroneArea = CreateDefaultSubobject<USphereComponent>(TEXT("ThroneCollision"));
		// Event called when component overlaps something.
		// Set the sphere's overlap radius.
		ThroneArea->InitSphereRadius(600.0f);

		ThroneArea->SetupAttachment(ThroneMesh);

		ThroneArea->OnComponentBeginOverlap.AddDynamic(this, &AThrone::EnemyOverlap);
	}

}

// Called when the game starts or when spawned
void AThrone::BeginPlay()
{
	Super::BeginPlay();

	ThroneMesh->SetMaterial(0, ThroneMaterialInstance);
	
}

// Called every frame
void AThrone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//if (PlayerRef != nullptr) 
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("PlayerRef isn't null"));
	//}

}

void AThrone::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AThrone, ThroneHealth);
}

void AThrone::DecrementThroneHealth()
{
	ThroneHealth -= 1;

	if (ThroneHealth <= 0) 
	{


	}
}

void AThrone::UpdateThroneHealth()
{
	if (PlayerRef != nullptr)
	{
		PlayerRef->SetBaseHealth(ThroneHealth);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Purple, FString::Printf(TEXT("Update Widget Replicate Using Called AFTER checking for null player ref")));
	}
}

void AThrone::SetPlayerRef(AMainCharacterTest* PlayerPtr)
{
	PlayerRef = PlayerPtr;
}

void AThrone::EnemyOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (HasAuthority())
	{
		GEngine->AddOnScreenDebugMessage(-1, 65.0f, FColor::Purple, FString::Printf(TEXT("Is player refnull %d"), (int) (PlayerRef != nullptr)));
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Purple, FString::Printf(TEXT("Enemy Overlapped Base BEFORE checking null")));
		if (PlayerRef != nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Red, FString::Printf(TEXT("ENEMY OVERLAPPED BASE")));
			DecrementThroneHealth();
			PlayerRef->SetBaseHealth(ThroneHealth);
		}
	}

	AEnemyBase* Enemy = Cast<AEnemyBase>(OtherActor);

	if (Enemy) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Enemy cast success")));
	}
}

