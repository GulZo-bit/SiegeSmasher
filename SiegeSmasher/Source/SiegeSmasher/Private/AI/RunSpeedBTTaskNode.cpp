// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/RunSpeedBTTaskNode.h"
#include "SiegeSmasher/MainCharacter.h"
#include "AIController.h"
#include "GameFramework/CharacterMovementComponent.h"



EBTNodeResult::Type URunSpeedBTTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	if (OwnerComp.GetAIOwner() == nullptr) 
	{
		return EBTNodeResult::Failed; 
	}
	AMainCharacter* PlayerCharacter = Cast<AMainCharacter>(OwnerComp.GetAIOwner()->GetPawn());

	if (PlayerCharacter == nullptr)
	{
		return EBTNodeResult::Failed; 
	}

	else
	{
		PlayerCharacter->GetCharacterMovement()->MaxWalkSpeed = MaxWalkSpeed;
	}
	return EBTNodeResult::Succeeded;
}

