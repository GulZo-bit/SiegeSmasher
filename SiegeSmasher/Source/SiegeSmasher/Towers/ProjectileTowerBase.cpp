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
	
	// keeps track of the current enemies in range pre alloacting a chunk of memeory to making adding to 
	// the array more efficient 
	CurrentEnemiesInRange.Reserve(MAX_ENEMY_NUM);
	LOSResult = FHitResult(); 

}

// Called when the game starts or when spawned
void AProjectileTowerBase::BeginPlay()
{
	Super::BeginPlay();
	// bindning the overlap end event delegate for the trigger box(declared in the enemy base class)
	TriggerRangeBox->OnComponentEndOverlap.AddDynamic(this,&AProjectileTowerBase::OnOverlapEnd);
	HalfTriggerBoxDimLength = (FVector(TriggerBoxDim.X, TriggerBoxDim.Y, 0.0f).Length()); 
	TriggerBoxAABB = FBox::BuildAABB(TriggerRangeBox->GetComponentLocation(),TriggerBoxDim); 


}

void AProjectileTowerBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
   
	// define how we will replciate variables marked for replication in this class 
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AProjectileTowerBase, CurrentEnemyOutOfRange); 
	DOREPLIFETIME(AProjectileTowerBase, NoTargetsInRange);
	DOREPLIFETIME(AProjectileTowerBase, EnemySingleTarget);


}

void AProjectileTowerBase::OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {


	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("projectile tower called")));
	
	    
		AEnemyBase* NewEnemy = Cast<AEnemyBase>(OtherActor);
		if (NewEnemy != nullptr) {
			// if the cast to the enemy was valid and we have line of sight and we dont have a 
			// current target
			if (NoTargetsInRange && (HasLineOfSite(NewEnemy->GetActorLocation()))) {

				// call the overriden handle new enemy method from the tower base class
				HandleNewEnemy(NewEnemy);

			}
			// if this particualr insatcne of the prkectile tower is on the server we log the enemy 
			// that just walked into range and add them to the currentenemiesinrange TArray
			if (HasAuthority()) {
				//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Enemy now in range index is: %d "), CurrentEnemiesInRange.Num()));
				GLog->Log(FString::Printf(TEXT("Enemy now in range index is: %d "), CurrentEnemiesInRange.Num()));
				IndicesForEnemiesInRange.Add(NewEnemy, CurrentEnemiesInRange.Num());
				CurrentEnemiesInRange.Add(NewEnemy);
			}
		




		}
	
	
	


}

void AProjectileTowerBase::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// if the projecitle tower instance is on the server 
	if (HasAuthority()) {
		// if an enemy just walked out of range 
		if (AEnemyBase* Enemy = Cast<AEnemyBase>(OtherActor)) {
			
			//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("enemy went out of trigger box for ballista removing")));
			GLog->Log(FString::Printf(TEXT("enemy went out of trigger box for ballista removing")));
			//    abs( CurrentEnemiesInRange.Num() - Previous)  ;
			//  sizeOf(AEnemyBase*) *  

			// if the enemy was logged meaning its ptr refernce was mapped to an index in the currentenemiesinrange TArray
			//( a TMap is used to associatie a particualr enemy refernce with an index into the TArray for efficnet removal
			//  of constant time)
			if (IndicesForEnemiesInRange.Find(Enemy)) {

				// get the index of the enemy to remove as it has either been killed or has gone out of range 
				int IndexOfEnemyToRemove = IndicesForEnemiesInRange[Enemy];
				//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Enemy being removed  index is: %d"), IndexOfEnemyToRemove));
				GLog->Log(FString::Printf(TEXT("Enemy being removed  index is: %d"), IndexOfEnemyToRemove));

				// here we are assigning  index set in the map for the current enemy reference at the back of the array 
				// to the index we are about to remove 
				IndicesForEnemiesInRange[CurrentEnemiesInRange[CurrentEnemiesInRange.Num() - 1]] = IndexOfEnemyToRemove;
				//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("new index for enemy that was swapped is: %d"), IndicesForEnemiesInRange[CurrentEnemiesInRange[CurrentEnemiesInRange.Num() - 1]]));
				GLog->Log(FString::Printf(TEXT("new index for enemy that was swapped is: %d"), IndicesForEnemiesInRange[CurrentEnemiesInRange[CurrentEnemiesInRange.Num() - 1]]));
				// perform a remove at swap on the current enemies in range TArray swapping the back element 
				// with the one we mark at the specifc index to remove(which is why we perform the swap above to ensure the map 
				// we use to track indicies of coming in enemies is synced with the TArray)
				CurrentEnemiesInRange.RemoveAtSwap(IndexOfEnemyToRemove, EAllowShrinking::No);


			}
			// check if the enemy that went out of range is the one we were targeting
			CurrentEnemyOutOfRange = Enemy == EnemySingleTarget;
		}


	}

		
		


	



}

void AProjectileTowerBase::HandleNewEnemy(AEnemyBase* Enemy) {

	// set the new enemy as the target and set up the required data for the child projectile tower to go into the active state 
	// this method can be overriden if a child projecitle tower needs different behavior on aquiring a new target
	if (HasAuthority()) {
		NoTargetsInRange = false;
		EnemySingleTarget = Enemy;
		CurrentEnemyOutOfRange = false;
	}
	// projectile tower becomes active when aquiring a new target 

	CurrentyActive = true; 
	

}
	

float AProjectileTowerBase::GetTargetingRangeSqr()
{
	return TargetingRange * TargetingRange;
}

// used to spawn and set the target for  instanced object of the asscoiated projectile class 
// that is created in this method 
void AProjectileTowerBase::ShootProjectile(FVector Position,FRotator Rotation)
{
	
	//spawining is done on the server to ensure it is visible to all clients and that we dont get duplicate spawns 
	//across all connected machines 
	if (HasAuthority()) {
		ATowerProjectileBase* ProjectilRef = World->SpawnActor<ATowerProjectileBase>(Projectile, FTransform(Rotation, Position, FVector::OneVector), ProjectileSpawnParameters);

		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Ballista shooting projectile")));
		if (ProjectilRef != nullptr) {
			ProjectilRef->SetInitialPitch(Rotation.Pitch);
			ProjectilRef->SetEnemyTarget(EnemySingleTarget); 
			ProjectilRef->SetPlayerRef(PlayerRef);

		}

		
	}
	// after the projectile tower shoots it needs to reload so it requires a reset
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


// this particualr method is a generic method across all projectile towers that allows for line of sight to be checked for 
// for enemies that are currenlty in range this is done via batch itteration to save on performance 
void AProjectileTowerBase::TrackEnemies(FVector Location)
{

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("Enemy num %d"), CurrentEnemiesInRange.Num()));
	// enemies in ranges
	if (CurrentEnemiesInRange.Num()) {
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Batching Enemies For Tower Los")));
		//used  keep track of the closest enemy out of the bacth we a itterating through 
		float MinDist = FLT_MAX;
		// if the batch count(number of enemies we ittertae through in the CurrentEnemiesInRange TArray per batch) is smaller than or equal to the size 
		// we can use it for this portion of the bacth ittertaion(this ensures that we dont go out of range fo the current enemies 
		// in range TArray as it is gettting adjusted dynamically)
		bool ShouldUseFullBatchCount = CurrentEnemiesInRange.Num() >= ProjectileTowerBatchCount;
		// batch count will either get set to the full batch count or the size of the CurrentEnemeisInRange array if the full batch count exceeds the size of the CurrentEnemiesInRange TArray
		int EnemyBatchCount = ProjectileTowerBatchCount * ShouldUseFullBatchCount + (1 - ShouldUseFullBatchCount) * CurrentEnemiesInRange.Num();
		AEnemyBase* ChosenEnemyFromBatch = nullptr;
		FHitResult LOSHitResultForBatching = FHitResult();
		bool LOSSuccess = false;
		bool CanUseBatchIndex = ProjectileBacthIndex < CurrentEnemiesInRange.Num();
		// if we have hit a point where the batch index has out grown the CurrentEnemiesInRange TArray reset it to zero
		ProjectileBacthIndex = ProjectileBacthIndex * CanUseBatchIndex;
		if (!CanUseBatchIndex) {
			//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald,FString::Printf(TEXT("Projectile Batch Index Was Too Large For Current Batch Resetting"))); 
			GLog->Log(FString::Printf(TEXT("Projectile Batch Index Was Too Large For Current Batch Resetting")));

		}
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Starting batch index is %d "), ProjectileBacthIndex));
		GLog->Log(FString::Printf(TEXT("Starting batch index is %d "), ProjectileBacthIndex));
		int StartingBatchIndex = ProjectileBacthIndex;
		int MostOptimalIndex = 0;

		// starting from our current batch index itterate to the next index on using our full batch size as the marker for where we stop(Starting batch index + projectile tower bacth count) 
		// and check that the batch index doesnt exceed the size of the curren enemies in range also 
		for (ProjectileBacthIndex; ProjectileBacthIndex < (StartingBatchIndex + ProjectileTowerBatchCount) && ProjectileBacthIndex < CurrentEnemiesInRange.Num(); ProjectileBacthIndex++) {
			GLog->Log(FString::Printf(TEXT("Enemy  being checked during LOS batching number %d "), ProjectileBacthIndex));


			// if the distance of the current enemy we are checking is smaller than the previous one and we have line of sight and the enemy isnt in the process of dying 
			if (float dist = FVector::DistSquared(Location, CurrentEnemiesInRange[ProjectileBacthIndex]->GetActorLocation()) < MinDist &&
				CurrentEnemiesInRange[ProjectileBacthIndex]->GetHealth() > 0.0f &&
				!World->LineTraceSingleByChannel(LOSHitResultForBatching, Location, CurrentEnemiesInRange[ProjectileBacthIndex]->GetActorLocation(), TowerNoLOSChannel)
				) {

				//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Enemy found during LOS batching number %d "), ProjectileBacthIndex));
				GLog->Log(FString::Printf(TEXT("Enemy found during LOS batching number %d "), ProjectileBacthIndex));

				// mark the batch as successful and record the new min dist and set the new chosen enemy from the batch
				LOSSuccess = true;
				MinDist = dist;
				ChosenEnemyFromBatch = CurrentEnemiesInRange[ProjectileBacthIndex];
				MostOptimalIndex = ProjectileBacthIndex;

			}


		}
		// if we obtained an enemy from the batch we itterated through to see if we could regain line of sight to enemies in range 
		if (ChosenEnemyFromBatch) {
			// if this tower instance is on the server side
			if (HasAuthority()) {
				//set that we have a target and that we should go into the active state 
				EnemySingleTarget = ChosenEnemyFromBatch;
				CurrentyActive = true;
				NoTargetsInRange = false;
				CurrentEnemyOutOfRange = false;
				//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Found optimal enemy from batch index was %d "), MostOptimalIndex));
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
			//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Sort Called for enemy")));
			GLog->Log(FString::Printf(TEXT("Sort Called for enemy ")));
			return (((AActor*)EnemySingleTarget) != &target) && ToCurrentTarget < ToOtherTarget;

	});
	

}

// Called every frame
void AProjectileTowerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

