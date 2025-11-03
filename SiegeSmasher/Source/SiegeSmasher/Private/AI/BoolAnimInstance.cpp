// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BoolAnimInstance.h"

void UBoolAnimInstance::setIsDeadBool(bool bStore)
{
	bAnimIsDead = bStore;
}

bool UBoolAnimInstance::getBool()
{
	return bAnimIsDead;
}
