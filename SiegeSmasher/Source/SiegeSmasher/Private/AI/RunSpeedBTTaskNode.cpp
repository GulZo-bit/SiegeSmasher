// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/RunSpeedBTTaskNode.h"
#include "AIController.h"
#include "SiegeSmasher/MainCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"



EBTNodeResult::Type URunSpeedBTTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	if (OwnerComp.GetAIOwner() == nullptr) 
	{
		GLog->Log(FString::Printf(TEXT("Failed OwnerComp")));
		return EBTNodeResult::Failed; 
	}

	AMainCharacter* PlayerCharacter = Cast<AMainCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (PlayerCharacter == nullptr)
	{
		GLog->Log(FString::Printf(TEXT("Failed PlayerChar")));
		return EBTNodeResult::Failed; 
	}

	else
	{
		PlayerCharacter->GetCharacterMovement()->MaxWalkSpeed = MaxWalkSpeed;
	}
	return EBTNodeResult::Succeeded;
}

