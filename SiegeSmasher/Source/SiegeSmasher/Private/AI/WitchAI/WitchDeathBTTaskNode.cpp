// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/WitchAI/WitchDeathBTTaskNode.h"
#include "AIController.h"

EBTNodeResult::Type UWitchDeathBTTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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
		AAIWitch* Witch = Cast<AAIWitch>(ControlledPawn);
		Witch->PlayDeathMontage();
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}