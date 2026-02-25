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
	//sets the mech and the material of the base
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
	//the material is set in the begin play because unreal sometimes just doesn't let you save when you do it in the constructor
	ThroneMesh->SetMaterial(0, ThroneMaterialInstance);
	MiniMapManagerRef = Cast<AMiniMapManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AMiniMapManager::StaticClass()));



	UMaterial* parent = LoadObject<UMaterial>(nullptr, TEXT("/Script/Engine.Material'/Game/MiniMapMaterials/ThroneMiniMapMat.ThroneMiniMapMat'"));
	MiniMapMat = UMaterialInstanceDynamic::Create(parent, this, FName("ThroneMiniMapMat"));

	MiniMapMat->SetVectorParameterValue("ThroneMiniMapCol", ThroneDefaultColour);

	miniMapSectionRadius = defaultMiniMapSectionRadius;

}

void AThrone::WriteToMinMap(double DeltaTime)
{
	    ThroneHitMiniMapAnim(DeltaTime);
		MiniMapManagerRef->WriteToMiniMap(GetActorLocation(), 0, miniMapSectionRadius, MiniMapMat);
		  


}

// Called every frame
void AThrone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	WriteToMinMap(DeltaTime);
}
//replicates the health variable
void AThrone::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AThrone, ThroneHealth);
}
//decreases health by 1
void AThrone::DecrementThroneHealth()
{
	ThroneHealth -= 1;
}
//gets called on clients whenever the health variable gets changed on the server
void AThrone::UpdateThroneHealth()
{
	if (PlayerRef != nullptr)
	{
		//updates the widget and if it fell to 0, calls game over
		PlayerRef->SetBaseHealth(ThroneHealth);
		if (ThroneHealth <= 0)
		{
			PlayerRef->GameOver();
		}
	}
}
//gets player reference
void AThrone::SetPlayerRef(AMainCharacterTest* PlayerPtr)
{
	PlayerRef = PlayerPtr;
}
//if enemy overlapps
void AThrone::EnemyOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	
	
	AEnemyBase* Enemy = Cast<AEnemyBase>(OtherActor);
	if (Enemy)
	{//cast to enemy, set their variables to be the same as if they had died
		Enemy->EnemyReachedBase();
		//On the server we just take away the health and then check if its 0, this will call the update throne health function on the clients
		ThronePlayHitAnim = true;
		if (HasAuthority() && PlayerRef != nullptr)
		{
			DecrementThroneHealth();
			PlayerRef->SetBaseHealth(ThroneHealth);
			if(ThroneHealth <= 0)
			{
				PlayerRef->GameOver();
			}
		}
	}

	

	
}

void AThrone::ThroneHitMiniMapAnim(double DeltaTime)
{

	 if(ThronePlayHitAnim && !ThroneHitAnimreverse )
	 {
		 
		ThroneAnimHitInterp += DeltaTime;
		
		float animPercent = (ThroneAnimHitInterp / ThroneAnimHitTimeMax);
		float lerpSize = (miniMapSectionRadiusMax - miniMapSectionRadius) * animPercent;
		 
		miniMapSectionRadius = miniMapSectionRadius + lerpSize;
		ThronePlayHitAnim = !(ThroneAnimHitInterp >= ThroneAnimHitTimeMax);
		ThroneAnimHitInterp *= ThronePlayHitAnim;
		ThroneHitAnimreverse = !ThronePlayHitAnim;

		return;
	 }
	   
	 
	 if(ThroneHitAnimreverse)
	 {
		 ThronePlayHitAnim = false;
	 
		 ThroneAnimHitInterp += DeltaTime;

		 float animPercent = (ThroneAnimHitInterp / ThroneAnimHitTimeMax);
		 float lerpSize = (defaultMiniMapSectionRadius - miniMapSectionRadius) * animPercent;
		
		 miniMapSectionRadius = miniMapSectionRadius + lerpSize;
		 ThroneHitAnimreverse = !(ThroneAnimHitInterp >= ThroneAnimHitTimeMax);
		 ThroneAnimHitInterp *= ThroneHitAnimreverse;


	 
	 }
	   
	  













}

