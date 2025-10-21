// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileTowerBase.h"

// Sets default values
AProjectileTowerBase::AProjectileTowerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProjectileTowerBase::BeginPlay()
{
	Super::BeginPlay();
	
}


void AProjectileTowerBase::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	CurrentyActive = true; 
	AEnemyBase* NewEnemy = Cast<AEnemyBase>(OtherActor);
	if (NoTargetsInRange && NewEnemy){

		HandleNewEnemy(NewEnemy);

	}


}

void AProjectileTowerBase::HandleNewEnemy(AEnemyBase* Enemy) {


	NoTargetsInRange = false;
	EnemySingleTarget = Enemy;



}

// Called every frame
void AProjectileTowerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

