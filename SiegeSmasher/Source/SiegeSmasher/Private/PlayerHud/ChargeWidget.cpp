// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHud/ChargeWidget.h"

void UChargeWidget::NativeConstruct() {

	Super::NativeConstruct();

	
	LeaderboardBorder = WidgetTree->FindWidget<UBorder>(FName(LeaderBoardBorderName));
	LeaderboardGrid = WidgetTree->FindWidget<UGridPanel>(FName(LeaderBoardGridPanelName));
	LeaderboardHeader = WidgetTree->FindWidget<UBorder>(FName(LeaderBoardHeaderName));
	if (LeaderboardGrid) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Leaderboard border found")));
		GenerateLeaderBoard();
	}
		
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("NO LEADER BOARD border ")));

	}
	
	




}


void UChargeWidget::SetLoggedPlayerNum(int LoggedNum)
{

	LoggedPlayerNumber =  std::min(LoggedNum,MaxPlayerNum);
}

void UChargeWidget::GenerateLeaderBoard()
{
	LeaderBoardItems = {};
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Bound leader board grid pannel sucessfully")));
	UCanvasPanelSlot* LeaderboardCanvasSlot = Cast<UCanvasPanelSlot>(LeaderboardGrid->Slot);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("canvas slot was null %d"),(int)(LeaderboardCanvasSlot == nullptr)));

	if (LeaderboardCanvasSlot) {
		
		FVector2D LeaderboardTopLeft = LeaderboardCanvasSlot->GetPosition();
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT(" max player num %d"),MaxPlayerNum));

		
		for (int i = 0; i < MaxPlayerNum; i++) {
			
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Itertaing max player num")));
			FVector2D TextPosition = FVector2D(LeaderboardTopLeft.X,(LeaderboardTopLeft.Y + LeaderboardTextPadding * i) + LeaderboardTopPadding);
			FString PlayerTag = LeaderBoardTagName + FString::FromInt(i+1);
			UTextBlock* Text = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), FName(PlayerTag));

			if (Text) {

			
				Text->SetFont(LeaderboardFont);  
				Text->SetColorAndOpacity(LeaderboardTextColour);
				Text->SetText(FText::FromString(PlayerTag));
				
				LeaderboardGrid->GetParent()->AddChild(Text);
				
				if (UCanvasPanelSlot* TextCanvasSlot = Cast<UCanvasPanelSlot>(Text->Slot)) {

					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("canvas text slot is null %d "), (int)(TextCanvasSlot == nullptr)));
					TextCanvasSlot->SetAnchors(LeaderboardCanvasSlot->GetAnchors());
					TextCanvasSlot->SetPosition(TextPosition);


					LeaderBoardItems.Add(Text);

					
				}

				
				




		/*		TextCanvasSlot->SetPosition(TextPosition);*/


				//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Text block created in widget")));
				 

			}

		}

	}
	

	

	
	

}

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

void UChargeWidget::HideLeaderBoard(bool ShouldHide)
{
	float NewOpacity = (float)ShouldHide;
	LeaderboardBorder->SetRenderOpacity(NewOpacity);
	LeaderboardHeader->SetRenderOpacity(NewOpacity); 
	


	for (int i = 0; i < LoggedPlayerNumber;i++) {

		LeaderBoardItems[i]->SetRenderOpacity(NewOpacity);
	}


}

void UChargeWidget::SetPoints(int NewPoints)
{
	PlayerPoints = NewPoints;



}

int UChargeWidget::GetPoints()
{
	return PlayerPoints;
}
