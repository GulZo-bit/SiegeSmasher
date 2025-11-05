// Fill out your copyright notice in the Description page of Project Settings.


#include "MCArrow.h"

// Sets default values
AMCArrow::AMCArrow()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	bReplicates = true;
	PrimaryActorTick.bCanEverTick = true;
	InitialLifeSpan = 3.0f;

	//creates the default scene root component if it doesn't exist already
	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSceneComponent"));
	}

	if (!ArrowCollision)
	{
		// Use a sphere as a simple collision representation.
		ArrowCollision = CreateDefaultSubobject<USphereComponent>(TEXT("ArrowCollision"));
		// Set the sphere's collision profile name to "Projectile".
		ArrowCollision->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));
		// Event called when component hits something.
		ArrowCollision->OnComponentHit.AddDynamic(this, &AMCArrow::OnHit);
		// Set the sphere's collision radius.
		ArrowCollision->InitSphereRadius(15.0f);
		// Set the root component to be the collision component.
		RootComponent = ArrowCollision;
	}

	if (!SoundTrigger) 
	{
		SoundTrigger = CreateDefaultSubobject<USphereComponent>(TEXT("SoundTrigger"));
		SoundTrigger->SetupAttachment(RootComponent);
	}

	if (!ArrowMovement)
	{
		// Movement component controls the Arrows movement properties like speed, gravity etc
		ArrowMovement =
			CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
		ArrowMovement->SetUpdatedComponent(ArrowCollision);
		ArrowMovement->InitialSpeed = 5000.0f;
		ArrowMovement->MaxSpeed = 5000.0f;
		ArrowMovement->bRotationFollowsVelocity = true;
		ArrowMovement->bShouldBounce = false;
		ArrowMovement->ProjectileGravityScale = 0.5f;
	}

	if (!ArrowMesh)
	{
		//sets the static mesh to the Arrow static mesh
		ArrowMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ArrowMesh"));
		static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh
		(TEXT("/Game/MainCharacter/MCAssets/Arrow/Arrow.Arrow"));

		if (Mesh.Succeeded())
		{
			ArrowMesh->SetStaticMesh(Mesh.Object);
		}
		//sets the material for the static mesh to the arrow material
		static ConstructorHelpers::FObjectFinder<UMaterial>Material
		(TEXT("/Game/MainCharacter/MCAssets/Arrow/M_Arrow.M_Arrow"));
		if (Material.Succeeded())
		{
			ArrowMaterialInstance = UMaterialInstanceDynamic::Create(Material.Object, ArrowMesh);
		}
		ArrowMesh->SetupAttachment(RootComponent);
		ArrowMesh->SetRelativeLocation(FVector(-70.0f, 0.0f, 0.0f));
		ArrowMesh->SetRelativeScale3D(FVector(3.0f, 2.0f, 2.0f));
		ArrowMesh->SetRelativeRotation(FQuat(FVector(0.0f, 0.0f, 1.0f), FMath::DegreesToRadians(90.0f)));
	}
}

// Called when the game starts or when spawned
void AMCArrow::BeginPlay()
{
	Super::BeginPlay();
	ArrowMesh->SetMaterial(0, ArrowMaterialInstance);

	SoundTrigger->OnComponentBeginOverlap.AddDynamic(this, &AMCArrow::ArrowOverlap);
}

// Called every frame
void AMCArrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//called when the projectile hits something
void AMCArrow::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	Destroy();
}

void AMCArrow::ArrowOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (WhooshingSound != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, FString::Printf(TEXT("Arrow Overlapped Player")));
		UGameplayStatics::PlaySoundAtLocation(this, WhooshingSound, GetActorLocation());
	}
}

void AMCArrow::FireInDirection(const FVector& ShootDirection, float Charge)
{
	float ArrowSpeed = ArrowMovement->InitialSpeed * (Charge / 100);
	ArrowDamage = ArrowDamage * (Charge/10);
	//UE_LOG(LogTemp, Warning, TEXT("ArrowSpeed: %f"), ArrowSpeed);
	//UE_LOG(LogTemp, Warning, TEXT("Arrow Function FireInDirection called"));
	ArrowMovement->Velocity = ShootDirection * ArrowSpeed;
}

float AMCArrow::getDamage()
{
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, FString::Printf(TEXT("Arrow Damage: %f"), ArrowDamage));
	return ArrowDamage;
}


