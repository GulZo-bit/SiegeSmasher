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
	LOSResult = FHitResult();
}

// Called when the game starts or when spawned
void AProjectileTowerBase::BeginPlay()
{
	Super::BeginPlay();
	TriggerRangeBox->OnComponentEndOverlap.AddDynamic(this,&AProjectileTowerBase::OnOverlapEnd);

}

void AProjectileTowerBase::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {


	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("projectile tower called")));

	AEnemyBase* NewEnemy = Cast<AEnemyBase>(OtherActor);
	if (NewEnemy != nullptr  ) {
		if (NoTargetsInRange && (HasLineOfSite(NewEnemy->GetActorLocation()))){

			HandleNewEnemy(NewEnemy);

		}
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Enemy now in range index is: %d "),CurrentEnemiesInRange.Num()));

		IndicesForEnemiesInRange.Add(NewEnemy, CurrentEnemiesInRange.Num());
		CurrentEnemiesInRange.Add(NewEnemy);

	}
	


}

void AProjectileTowerBase::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (AEnemyBase* Enemy = Cast<AEnemyBase>(OtherActor)) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("enemy went out of trigger box for ballista removing")));
		//    abs( CurrentEnemiesInRange.Num() - Previous)  ;
		//  sizeOf(AEnemyBase*) *  

		int IndexOfEnemyToRemove = IndicesForEnemiesInRange[Enemy];
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Enemy being removed  index is: %d"), IndexOfEnemyToRemove));

		IndicesForEnemiesInRange[CurrentEnemiesInRange[CurrentEnemiesInRange.Num() - 1]] = IndexOfEnemyToRemove;
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("new index for enemy that was swapped is: %d"), IndicesForEnemiesInRange[CurrentEnemiesInRange[CurrentEnemiesInRange.Num() - 1]]));

	    CurrentEnemiesInRange.RemoveAtSwap(IndexOfEnemyToRemove);

		
		if (IndicesForEnemiesInRange.Remove(Enemy) > 1) 
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString::Printf(TEXT("MULTIPLE ENEMIES REMOVED FROM ENEMY INDEX MAP FOR TOWER TARGETING THIS SHOULD NOT HAPPEN")));
		};


	}



}

void AProjectileTowerBase::HandleNewEnemy(AEnemyBase* Enemy) {

	NoTargetsInRange = false;
	EnemySingleTarget = Enemy;
	CurrentyActive = true;

}
	

float AProjectileTowerBase::GetTargetingRangeSqr()
{
	return TargetingRange * TargetingRange;
}
void AProjectileTowerBase::ShootProjectile(FVector Position,FRotator Rotation)
{
	
	ATowerProjectileBase * ProjectilRef =  World->SpawnActor<ATowerProjectileBase>(Projectile, FTransform(Rotation, Position, FVector::OneVector), ProjectileSpawnParameters);
	
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Ballista shooting projectile")));
	if (ProjectilRef != nullptr) {
		ProjectilRef->SetInitialPitch(Rotation.Pitch);
		ProjectilRef->SetEnemyTarget(EnemySingleTarget);

	}
	
	RequiresReset = true; 
	

}

bool AProjectileTowerBase::HasLineOfSite(FVector To)
{
	FHitResult LOSRes = FHitResult();
	FVector Between = To - GetActorLocation();
	return !(World->LineTraceSingleByChannel(LOSRes,
		GetActorLocation(),
		GetActorLocation() +
		(Between).GetSafeNormal() * Between.Length(),
		TowerNoLOSChannel));
}

void AProjectileTowerBase::TrackEnemyForLos()
{

	/*for (int i = 0; i < EnemiesToTrackForLOS.Num();++i) {
		if (EnemiesToTrackForLOS[i] != nullptr) {
			FHitResult HitResultForLOS = FHitResult();
			FVector ActorLoc = GetActorLocation();
			FVector Direction = (EnemiesToTrackForLOS[i]->GetActorLocation() - ActorLoc).GetSafeNormal();
			World->LineTraceSingleByChannel(HitResultForLOS, GetActorLocation(), GetActorLocation() + Direction * (TargetingRange * TargetingRange));



		}
	}*/
	




}





void AProjectileTowerBase::SortedClosestEnemiesInRange()
{
	CurrentEnemiesInRange.Sort([this](const AActor& target, const AActor& Other)
	{
			float ToCurrentTarget = (target.GetActorLocation() - GetActorLocation()).SquaredLength();
			float ToOtherTarget = (Other.GetActorLocation() - GetActorLocation()).SquaredLength();
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Sort Called for enemy")));
			return (((AActor*)EnemySingleTarget) != &target) && ToCurrentTarget < ToOtherTarget;

	});
	

}

// Called every frame
void AProjectileTowerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

