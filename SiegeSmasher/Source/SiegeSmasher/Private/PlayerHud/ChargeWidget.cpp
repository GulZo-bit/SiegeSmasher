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
