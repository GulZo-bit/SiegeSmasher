// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BoolAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SIEGESMASHER_API UBoolAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category = "Animation Bools")
    void setIsDeadBool(bool bStore);

    bool getBool();

    // Expose this boolean to the Animation Blueprint
    UPROPERTY(BlueprintReadOnly, Category = "Animation Bools")
    bool bAnimIsDead = false;
};
