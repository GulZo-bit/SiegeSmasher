// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Public/PlayerHud/ChargeWidget.h"
#include "MyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SIEGESMASHER_API AMyGameModeBase : public AGameMode
{
	GENERATED_BODY()
	virtual void BeginPlay() override;

//protected:
//
//	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Charge")
//	TSubclassOf<class UUserWidget> PlayerHUD;
//
//	UPROPERTY()
//	class UChargeWidget* ChargeWidget;
};
