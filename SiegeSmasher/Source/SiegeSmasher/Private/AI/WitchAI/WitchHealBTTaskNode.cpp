// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/WitchAI/WitchHealBTTaskNode.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UWitchHealBTTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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
		Controller->GetBlackboardComponent()->SetValueAsBool(TEXT("bCanHeal"), false);
		AAIWitch* Witch = Cast<AAIWitch>(ControlledPawn);
		Witch->PlayHealSpellMontage();
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Succeeded;
}
