// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/DeathBTTaskNode.h"
#include "AIController.h"
#include "AI/AICharTest.h"

EBTNodeResult::Type UDeathBTTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	if (OwnerComp.GetAIOwner() == nullptr)
	{
		GLog->Log(FString::Printf(TEXT("Failed OwnerComp")));
		return EBTNodeResult::Failed;
	}

	AAIController* Controller = OwnerComp.GetAIOwner();
	APawn* ControlledPawn = Controller->GetPawn();

	//Plays death animation using the BT.
	if (ControlledPawn != nullptr)
	{
		AAICharTest* Enemy = Cast<AAICharTest>(ControlledPawn);
		if (Enemy != nullptr)
		{
			Enemy->PlayDeathMontage();
			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}
