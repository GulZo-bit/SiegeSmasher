// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileTowerBase.h"

// Sets default values
AProjectileTowerBase::AProjectileTowerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; 
	World = GetWorld(); 
	ProjectileSpawnParameters = FActorSpawnParameters(); 
	ProjectileSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	TowerFiringPoint = CreateDefaultSubobject<USceneComponent>("TowerFiringPoint");
	/*TowerFiringPoint->SetupAttachment(RootComponent);*/

}

// Called when the game starts or when spawned
void AProjectileTowerBase::BeginPlay()
{
	Super::BeginPlay();
	
}


void AProjectileTowerBase::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {


	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("projectile tower called")));

	AEnemyBase* NewEnemy = Cast<AEnemyBase>(OtherActor);
	if (NoTargetsInRange && NewEnemy != nullptr){
		CurrentyActive = true;
		
		HandleNewEnemy(NewEnemy);

	}


}

void AProjectileTowerBase::HandleNewEnemy(AEnemyBase* Enemy) {


	
	NoTargetsInRange = false;
	EnemySingleTarget = Enemy;


}

void AProjectileTowerBase::ShootProjectile(FRotator rotation)
{
	
	ATowerProjectileBase * ProjectilRef =  World->SpawnActor<ATowerProjectileBase>(Projectile, FTransform(rotation, TowerFiringPoint->GetComponentLocation(), FVector::OneVector), ProjectileSpawnParameters);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Ballista shooting projectile")));
	ProjectilRef->SetEnemyTarget(EnemySingleTarget);
	RequiresReset = true;

}


// Called every frame
void AProjectileTowerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

