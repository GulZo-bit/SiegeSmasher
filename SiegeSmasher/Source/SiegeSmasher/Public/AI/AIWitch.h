// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AI/SplineController.h"
#include "../Enemies/EnemyBase.h"
#include "WitchAI/Witch_Projectile.h"
#include "AI/HealAuraLight.h"
#include "AIWitch.generated.h"

UCLASS()
class SIEGESMASHER_API AAIWitch : public AEnemyBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAIWitch();

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

	//Animation for attack spell
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	UAnimMontage* AttackSpellMontage;

	UFUNCTION(Server, Reliable)
	void Server_PlayAttackMontage();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_PlayAttackMontage();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	UAnimMontage* HealSpellMontage;

	UFUNCTION(Server, Reliable)
	void Server_PlayHealSpellMontage();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_PlayHealSpellMontage();

	UFUNCTION(Server, Reliable)
	void Server_PlayLightTimeLine(AHealAuraLight* LightStore);

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_PlayLightTimeLine(AHealAuraLight* LightStore);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	UAnimMontage* DeathMontage;

	UFUNCTION(Server, Reliable)
	void Server_PlayDeathMontage();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_PlayDeathMontage();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool bCanActorMove = true;

	UAnimInstance* AnimInstance;
	int32 iCount = 0;
	void PlayAttack();

	TArray<UActorComponent*> HealStore;
	UBoxComponent* HealZone;
	int32 iHealCount = 0;
	void HealEnemy();
	void PlayHealSpellMontage();
	void PlayDeathMontage();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AWitch_Projectile> SpellClass;
	UPROPERTY()
	AWitch_Projectile* Spell;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AWitch_Projectile> HealSpell;

	void setbCanActorMove(bool bStore);

	AWitch_Projectile* getSpell();
	bool getbCanActorMove();
	float Count = 0.0f;

	UWorld* World;
};
