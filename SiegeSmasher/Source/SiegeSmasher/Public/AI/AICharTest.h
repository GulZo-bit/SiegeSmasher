// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CheckPointTest.h"
#include "AI/SplineController.h"
#include "../Enemies/EnemyBase.h"
#include "AICharTest.generated.h"

class ASword;

UCLASS()
class SIEGESMASHER_API AAICharTest : public AEnemyBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAICharTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "Checkpoints")
	TArray<AActor*> CheckpointStore;

	FName Tag = FName(TEXT("SplineMovementActor")); //Tag used to find the correct child actor.
	UPROPERTY()
	TArray<ASplineController*> SplineControllerStore; //Stores the multiple splines in the scene
	UPROPERTY()
	AActor* CubeStore; //Stores the cube of the enmey.
	int32 SplineNum; //Number that will be set randomly based on how many splines are in the scene.
	float StartTime;

	//For the attack animation
	//An animation montage instance that we will apply in the blueprint.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	UAnimMontage* AttackMontage;

	//==========================================================================================================================
	//Animation replication.
	//Requires a remote procedure call (RPC) to tell all the clients to play the animation at the exact same time.
	//==========================================================================================================================

	//A Function that is only executed on the server. That is what the server specifier is for. 
	//The server identifier also declares an additional function that has the same name except it has IMPLEMENTATION at the end this is where the code actually goes.
	//Reliable means that the function is replicated over the network and is guaranteed to arrive regardless of bandwidth or network error.
	//This will execute the Attack montage on the server.
	UFUNCTION(Server, Reliable)
	void Server_PlayAttackMontage();

	//This function will play the attack montage both locally on the server and replicated to all clients.
	//That is what the multicast specifier is for.
	//It also declares an additional IMPLEMENTATION function where the code actually goes.
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_PlayAttackMontage();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	TArray<AActor*> getCheckpoints();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASword> SwordClass;

	UPROPERTY()
	ASword* Sword;

	//The public function that other classes will call to play the attack animation.
	void PlayAttackMontage();

};
