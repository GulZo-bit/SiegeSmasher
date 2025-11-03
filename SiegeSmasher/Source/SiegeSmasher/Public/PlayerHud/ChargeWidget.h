// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "ChargeWidget.generated.h"

/**
 * 
 */
UCLASS()
class SIEGESMASHER_API UChargeWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	float Charge;

	UPROPERTY(BlueprintReadOnly)
	float Health;

	UFUNCTION()
	void SetChargeAmount(float ChargeAmount);

	UFUNCTION(BlueprintCallable)
	float GetChargePercent();

	UFUNCTION()
	void SetHealthAmount(float HealthAmount);

	UFUNCTION(BlueprintCallable)
	float GetHealthAmount();

	UFUNCTION(BlueprintCallable)
	float GetHealthPercent();
};
