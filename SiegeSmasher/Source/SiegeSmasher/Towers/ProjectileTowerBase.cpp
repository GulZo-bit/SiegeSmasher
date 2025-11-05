// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileTowerBase.h"

// Sets default values
AProjectileTowerBase::AProjectileTowerBase()
{
	bReplicates = true;
	SetReplicateMovement(true);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; 
	World = GetWorld(); 
	ProjectileSpawnParameters = FActorSpawnParameters(); 
	ProjectileSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	CurrentEnemiesInRange.Reserve(MAX_ENEMY_NUM);
	LOSResult = FHitResult(); 

}

// Called when the game starts or when spawned
void AProjectileTowerBase::BeginPlay()
{
	Super::BeginPlay();
	TriggerRangeBox->OnComponentEndOverlap.AddDynamic(this,&AProjectileTowerBase::OnOverlapEnd);
	HalfTriggerBoxDimLength = (FVector(TriggerBoxDim.X, TriggerBoxDim.Y, 0.0f).Length()); 
	TriggerBoxAABB = FBox::BuildAABB(TriggerRangeBox->GetComponentLocation(),TriggerBoxDim); 


}

void AProjectileTowerBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
   
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AProjectileTowerBase, CurrentEnemyOutOfRange); 
	DOREPLIFETIME(AProjectileTowerBase, NoTargetsInRange);
	DOREPLIFETIME(AProjectileTowerBase, EnemySingleTarget);


}

void AProjectileTowerBase::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {


	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("projectile tower called")));
	
		AEnemyBase* NewEnemy = Cast<AEnemyBase>(OtherActor);
		if (NewEnemy != nullptr) {
			if (NoTargetsInRange && (HasLineOfSite(NewEnemy->GetActorLocation()))) {

				HandleNewEnemy(NewEnemy);

			}
			
			if (HasAuthority()) {
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Enemy now in range index is: %d "), CurrentEnemiesInRange.Num()));
				GLog->Log(FString::Printf(TEXT("Enemy now in range index is: %d "), CurrentEnemiesInRange.Num()));
				IndicesForEnemiesInRange.Add(NewEnemy, CurrentEnemiesInRange.Num());
				CurrentEnemiesInRange.Add(NewEnemy);
			}
		




		}
	
	
	


}

void AProjectileTowerBase::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (HasAuthority()) {
		if (AEnemyBase* Enemy = Cast<AEnemyBase>(OtherActor)) {
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("enemy went out of trigger box for ballista removing")));
			GLog->Log(FString::Printf(TEXT("enemy went out of trigger box for ballista removing")));
			//    abs( CurrentEnemiesInRange.Num() - Previous)  ;
			//  sizeOf(AEnemyBase*) *  

			if (IndicesForEnemiesInRange.Find(Enemy)) {
				int IndexOfEnemyToRemove = IndicesForEnemiesInRange[Enemy];
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Enemy being removed  index is: %d"), IndexOfEnemyToRemove));
				GLog->Log(FString::Printf(TEXT("Enemy being removed  index is: %d"), IndexOfEnemyToRemove));
				IndicesForEnemiesInRange[CurrentEnemiesInRange[CurrentEnemiesInRange.Num() - 1]] = IndexOfEnemyToRemove;
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("new index for enemy that was swapped is: %d"), IndicesForEnemiesInRange[CurrentEnemiesInRange[CurrentEnemiesInRange.Num() - 1]]));
				GLog->Log(FString::Printf(TEXT("new index for enemy that was swapped is: %d"), IndicesForEnemiesInRange[CurrentEnemiesInRange[CurrentEnemiesInRange.Num() - 1]]));
				CurrentEnemiesInRange.RemoveAtSwap(IndexOfEnemyToRemove, EAllowShrinking::No);


			}
			CurrentEnemyOutOfRange = Enemy == EnemySingleTarget;
		}


	}
		
		


	



}

void AProjectileTowerBase::HandleNewEnemy(AEnemyBase* Enemy) {

	if (HasAuthority()) {
		NoTargetsInRange = false;
		EnemySingleTarget = Enemy;
		CurrentEnemyOutOfRange = false;
	}

	CurrentyActive = true; 
	

}
	

float AProjectileTowerBase::GetTargetingRangeSqr()
{
	return TargetingRange * TargetingRange;
}
void AProjectileTowerBase::ShootProjectile(FVector Position,FRotator Rotation)
{
	
	if (HasAuthority()) {
		ATowerProjectileBase* ProjectilRef = World->SpawnActor<ATowerProjectileBase>(Projectile, FTransform(Rotation, Position, FVector::OneVector), ProjectileSpawnParameters);

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Ballista shooting projectile")));
		if (ProjectilRef != nullptr) {
			ProjectilRef->SetInitialPitch(Rotation.Pitch);
			ProjectilRef->SetEnemyTarget(EnemySingleTarget); 
			ProjectilRef->SetPlayerRef(PlayerRef);

		}

		
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

void AProjectileTowerBase::TrackEnemies(FVector Location)
{

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("Enemy num %d"), CurrentEnemiesInRange.Num()));
	if (CurrentEnemiesInRange.Num()) {
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Batching Enemies For Tower Los")));

		float MinDist = FLT_MAX;
		bool ShouldUseFullBatchCount = CurrentEnemiesInRange.Num() >= ProjectileTowerBatchCount;
		int EnemyBatchCount = ProjectileTowerBatchCount * ShouldUseFullBatchCount + (1 - ShouldUseFullBatchCount) * CurrentEnemiesInRange.Num();
		AEnemyBase* ChosenEnemyFromBatch = nullptr;
		FHitResult LOSHitResultForBatching = FHitResult();
		bool LOSSuccess = false;
		bool CanUseBatchIndex = ProjectileBacthIndex < CurrentEnemiesInRange.Num();

		ProjectileBacthIndex = ProjectileBacthIndex * CanUseBatchIndex;
		if (!CanUseBatchIndex) {
			//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald,FString::Printf(TEXT("Projectile Batch Index Was Too Large For Current Batch Resetting"))); 
			GLog->Log(FString::Printf(TEXT("Projectile Batch Index Was Too Large For Current Batch Resetting")));

		}
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Starting batch index is %d "), ProjectileBacthIndex));
		GLog->Log(FString::Printf(TEXT("Starting batch index is %d "), ProjectileBacthIndex));
		int StartingBatchIndex = ProjectileBacthIndex;
		int MostOptimalIndex = 0;
		for (ProjectileBacthIndex; ProjectileBacthIndex < (StartingBatchIndex + ProjectileTowerBatchCount) && ProjectileBacthIndex < CurrentEnemiesInRange.Num(); ProjectileBacthIndex++) {
			GLog->Log(FString::Printf(TEXT("Enemy  being checked during LOS batching number %d "), ProjectileBacthIndex));

			if (float dist = FVector::DistSquared(Location, CurrentEnemiesInRange[ProjectileBacthIndex]->GetActorLocation()) < MinDist &&
				CurrentEnemiesInRange[ProjectileBacthIndex]->GetHealth() > 0.0f &&
				!World->LineTraceSingleByChannel(LOSHitResultForBatching, Location, CurrentEnemiesInRange[ProjectileBacthIndex]->GetActorLocation(), TowerNoLOSChannel)
				) {

				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Enemy found during LOS batching number %d "), ProjectileBacthIndex));
				GLog->Log(FString::Printf(TEXT("Enemy found during LOS batching number %d "), ProjectileBacthIndex));

				LOSSuccess = true;
				MinDist = dist;
				ChosenEnemyFromBatch = CurrentEnemiesInRange[ProjectileBacthIndex];
				MostOptimalIndex = ProjectileBacthIndex;

			}


		}
		if (ChosenEnemyFromBatch) {
			if (HasAuthority()) {
				EnemySingleTarget = ChosenEnemyFromBatch;
				CurrentyActive = true;
				NoTargetsInRange = false;
				CurrentEnemyOutOfRange = false;
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Found optimal enemy from batch index was %d "), MostOptimalIndex));
				GLog->Log(FString::Printf(TEXT("Found optimal enemy from batch index was %d "), MostOptimalIndex));

				
			}
			
		}
	}
}





void AProjectileTowerBase::SortedClosestEnemiesInRange()
{

	CurrentEnemiesInRange.Sort([this](const AActor& target, const AActor& Other)
	{
			float ToCurrentTarget = (target.GetActorLocation() - GetActorLocation()).SquaredLength();
			float ToOtherTarget = (Other.GetActorLocation() - GetActorLocation()).SquaredLength();
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Sort Called for enemy")));
			GLog->Log(FString::Printf(TEXT("Sort Called for enemy ")));
			return (((AActor*)EnemySingleTarget) != &target) && ToCurrentTarget < ToOtherTarget;

	});
	

}

// Called every frame
void AProjectileTowerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

