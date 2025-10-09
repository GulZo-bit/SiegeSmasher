// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SiegeSmasher/MainCharacter.h"
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
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	void setCollisionEnemy();
	void setCollisionDefault();

	UPROPERTY(EditAnywhere)
	float Damage = 10;

	bool bHitDetected;
	FTimerHandle TimerHandle;
	FString ColStore = "";
	void ResetHit();
private:
	
};
