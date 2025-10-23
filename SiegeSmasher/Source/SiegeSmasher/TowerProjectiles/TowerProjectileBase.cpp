// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerProjectileBase.h"

// Sets default values
ATowerProjectileBase::ATowerProjectileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>("Projectile Mesh"); 
	ProjectileMesh->SetCollisionProfileName(FName("TowerProjectile"));


	World = GetWorld(); 
	//ProjectileMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

}

// Called when the game starts or when spawned
void ATowerProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	ProjectileMesh->OnComponentBeginOverlap.AddDynamic(this, &ATowerProjectileBase::OnOverLapBegin);


}

void ATowerProjectileBase::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	if (AEnemyBase* Enemy = Cast<AEnemyBase>(OtherActor)) {

		Enemy->DamageEnemy(Damage);
		
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Tower projectile hitting enemy")));
		


	}

	
	World->DestroyActor(this);






} 



// Called every frame
void ATowerProjectileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 

	MoveToTarget(DeltaTime);


}

void ATowerProjectileBase::SetEnemyTarget(AEnemyBase* Enemy)
{

	Target = Enemy;

}

void ATowerProjectileBase::MoveToTarget(float DeltaTime)
{
	
	if (Target != nullptr) {
		TargetPosition = Target->GetActorLocation(); 


	}

	
	FVector CurrentDifference = TargetPosition - GetActorLocation(); 

	double currentRotationAngleYaw = atan2(CurrentDifference.Y,CurrentDifference.X);  


	FQuat TravelRot = FRotator(InitalPitch, FMath::RadiansToDegrees(currentRotationAngleYaw),0.0f).Quaternion();

	

	SetActorLocation(FMath::VInterpConstantTo(GetActorLocation(), TargetPosition, DeltaTime, ProjectileSpeed));


	SetActorRotation(TravelRot);


}

void ATowerProjectileBase::SetInitialPitch(float Pitch)
{
	InitalPitch = Pitch;
}

