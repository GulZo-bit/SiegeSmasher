// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "RunSpeedBTTaskNode.generated.h"

/**
 * 
 */
UCLASS()
class SIEGESMASHER_API URunSpeedBTTaskNode : public UBTTaskNode
{
	GENERATED_BODY()
public:

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
public:
	UPROPERTY(EditAnywhere)
	float MaxWalkSpeed;
};
