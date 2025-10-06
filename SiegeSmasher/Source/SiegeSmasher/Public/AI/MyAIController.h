// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CheckpointTest.h"
#include "CheckPointTrigger.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class SIEGESMASHER_API AMyAIController : public AAIController
{
	GENERATED_BODY()
public:
	
protected:
	virtual void BeginPlay() override;

	TArray<AActor*> CheckpointStore;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "MyVariables");
	int32 IndexStart = 0;
	//AActor CheckpointTrigger;
	UCheckPointTrigger* CheckpointTrigger;
public:
	virtual void Tick(float DeltaSeconds) override;
};
