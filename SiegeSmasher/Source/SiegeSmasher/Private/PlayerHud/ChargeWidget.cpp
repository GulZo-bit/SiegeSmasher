// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHud/ChargeWidget.h"

void UChargeWidget::SetChargeAmount(float ChargeAmount)
{
	Charge = ChargeAmount;
}

float UChargeWidget::GetChargePercent()
{
	return Charge/100;
}

void UChargeWidget::SetHealthAmount(float HealthAmount)
{
	Health = HealthAmount;
}

float UChargeWidget::GetHealthAmount()
{
	return Health;
}

float UChargeWidget::GetHealthPercent()
{
	return Health/100;
}

void UChargeWidget::SetPoints(int NewPoints)
{
	PlayerPoints = NewPoints;



}

int UChargeWidget::GetPoints()
{
	return PlayerPoints;
}
