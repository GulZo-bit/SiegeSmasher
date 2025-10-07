// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AttackBTTaskNode.h"
#include "AIController.h"
#include "SiegeSmasher/MainCharacter.h"
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

	AActor* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	AMainCharacter* PlayerCharacter = Cast<AMainCharacter>(Player);

	if (PlayerCharacter == nullptr)
	{
		GLog->Log(FString::Printf(TEXT("Failed PlayerChar")));
		return EBTNodeResult::Failed;
	}

	else
	{
		PlayerCharacter->setHealth(PlayerCharacter->getHealth() - Damage);
		GLog->Log(FString::Printf(TEXT("PlayerHealth: %f"), PlayerCharacter->getHealth()));
	}
	return EBTNodeResult::Succeeded;
}