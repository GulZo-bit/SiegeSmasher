// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AttackBTTaskNode.h"
#include "AIController.h"
#include "AI/Sword.h"
#include "AI/AICharTest.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"

EBTNodeResult::Type UAttackBTTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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
		AAICharTest* Enemy = Cast<AAICharTest>(ControlledPawn);
		if (Enemy != nullptr)
		{
			Enemy->PlayAttackMontage();
			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}