// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h" 
#include "Components/TextBlock.h"
#include "Blueprint/WidgetTree.h" 
#include "Components/GridPanel.h"
#include "Components/ProgressBar.h"  
#include "Components/CanvasPanel.h" 
#include  "Components/CanvasPanelSlot.h"  
#include "Components/Border.h" 
#include "Components/BorderSlot.h"
#include "../ServerObject/ServerObject.h"
#include "ChargeWidget.generated.h"


UCLASS()
class SIEGESMASHER_API UChargeWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	void NativeConstruct();
	

	UPROPERTY(BlueprintReadOnly)
	float Charge;

	UPROPERTY(BlueprintReadOnly)
	float Health; 

	UPROPERTY(BlueprintReadOnly) 
	int PlayerPoints;

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

	void HideLeaderBoard(bool ShouldHide);
	void SetPoints(int NewPoints);

	UFUNCTION(BlueprintCallable)
	int GetPoints();

	void SetServerObjectRef(AServerObject* ServerObjectPtr);
	void UpdatePlayerLeaderBoardInfo(int Points, int Kills, int PlayerId); 
	
	void InitialisePlayerLeaderboardInfo();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MaxPlayerNum", meta = (ClampMin = "1", ClampMax = "4"))
	int MaxPlayerNum = 4; 
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LeaderBoardGridPanelName"); 
	FString LeaderBoardGridPanelName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LeaderBoardGridPanelName");
	FString LeaderBoardBorderName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LeaderBoardHeaderName");
	FString LeaderBoardHeaderName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LeaderBoardVerticalPadding"); 
	float LeaderboardTextPadding;  
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LeaderBoardVerticalPadding");
	float LeaderboardTopPadding;
    


    
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LeaderBoardName");
	FString LeaderBoardTagName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LeaderboardFont"); 
	FSlateFontInfo LeaderboardFont;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LeaderboardTextColour");
	FSlateColor LeaderboardTextColour;

private:
	void GenerateLeaderBoard();
	TArray<UTextBlock*> LeaderBoardItems; 
	UBorder* LeaderboardBorder = nullptr; 
	UBorder* LeaderboardHeader = nullptr;
	UGridPanel* LeaderboardGrid = nullptr; 
	AServerObject* ServerobjectRef = nullptr;

	int LoggedPlayerNumber = 0;

};
