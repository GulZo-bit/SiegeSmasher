// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/DemonAI/DemonDeathBTTaskNode.h"
#include "AIController.h"
#include "AI/DemonAI/AIDemon.h"

EBTNodeResult::Type UDemonDeathBTTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	if (OwnerComp.GetAIOwner() == nullptr)
	{
		GLog->Log(FString::Printf(TEXT("Failed OwnerComp")));
		return EBTNodeResult::Failed;
	}

	AAIController* Controller = OwnerComp.GetAIOwner();
	APawn* ControlledPawn = Controller->GetPawn();

	if (ControlledPawn != nullptr)
	{
		AAIDemon* Demon = Cast<AAIDemon>(ControlledPawn);
		if (Demon != nullptr)
		{
			Demon->PlayDeathMontage();
			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}