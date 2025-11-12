// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SiegeSmasher/MainCharacter.h"
#include "SiegeSmasher/MyMainCharacterTest.h"
#include "Sword.generated.h"

UCLASS()
class SIEGESMASHER_API ASword : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASword();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "default")
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "default")
	UStaticMeshComponent* Mesh;

	UFUNCTION()
	void OnOverLapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverLapEnd(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void setCollisionEnemy();
	void setCollisionDefault();

	UPROPERTY(EditAnywhere)
	float Damage = 5;

	bool bHitDetected;
	FTimerHandle TimerHandle;
	FString ColStore = "";
	bool bHit = false;
	void ResetHit();

	void ResetSwordOnDeath();
	void ResetSwordOnRespawn();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_ResetSwordOnDeath();
	void Multicast_ResetSwordOnDeath_Implementation();


	UFUNCTION(NetMulticast, Reliable)
	void Multicast_ResetSwordOnRespawn();
	void Multicast_ResetSwordOnRespawn_Implementation();
private:
	
};
