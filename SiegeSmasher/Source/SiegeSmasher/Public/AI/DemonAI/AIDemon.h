// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AI/SplineController.h"
#include "../Enemies/EnemyBase.h"
#include "AI/DemonAI/DemonFists.h"
#include "AI/BoolAnimInstance.h"
#include "AIDemon.generated.h"

UCLASS()
class SIEGESMASHER_API AAIDemon : public AEnemyBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAIDemon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FName Tag = FName(TEXT("SplineMovementActor")); //Tag used to find the correct child actor.
	UPROPERTY()
	TArray<ASplineController*> SplineControllerStore; //Stores the multiple splines in the scene
	UPROPERTY()
	AActor* CubeStore; //Stores the cube of the enmey.
	int32 SplineNum; //Number that will be set randomly based on how many splines are in the scene.
	float StartTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	UAnimMontage* AttackAnimation;

	UFUNCTION(Server, Reliable)
	void Server_PlayAttackMontage();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_PlayAttackMontage();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	UAnimMontage* DeathMontage;

	UFUNCTION(Server, Reliable)
	void Server_PlayDeathMontage();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_PlayDeathMontage();

	UPROPERTY(EditAnywhere, Category = "Sound")
	USoundBase* AttackSound;

	bool bDeathAnimFinished = false;

	UPROPERTY(EditAnywhere, Category = "Sound")
	USoundBase* DeathSound;
	int32 SoundCount = 0;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool bCanActorMove = true;
	void setbCanActorMove(bool bStore);
	float Count = 0.0f;

	UAnimInstance* AnimInstance;
	void PlayAttack();
	void PlayDeathMontage();

	UPROPERTY(EditAnywhere)
	TSubclassOf<ADemonFists> DemonFistClass;

	UPROPERTY()
	ADemonFists* RightFist;

	UPROPERTY()
	ADemonFists* LeftFist;

	virtual void EnemyReachedBase() override;

	bool getDeathAnimFinsihed();
};
