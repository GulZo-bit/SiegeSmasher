// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHud/ChargeWidget.h"
#include "../MyMainCharacterTest.h"
void UChargeWidget::NativeConstruct() {

	Super::NativeConstruct();

	
	LeaderboardBorder = WidgetTree->FindWidget<UBorder>(FName(LeaderBoardBorderName));
	LeaderboardGrid = WidgetTree->FindWidget<UGridPanel>(FName(LeaderBoardGridPanelName));
	LeaderboardHeader = WidgetTree->FindWidget<UBorder>(FName(LeaderBoardHeaderName));
	if (LeaderboardGrid && LeaderboardHeader && LeaderboardBorder) {
		
		GenerateLeaderBoard();
	}
	
	




}






void UChargeWidget::GenerateLeaderBoard()
{
	LeaderBoardItems = {};

	



	if (UCanvasPanelSlot* LeaderboardCanvasSlot = Cast<UCanvasPanelSlot>(LeaderboardGrid->Slot)) {

		FVector2D LeaderboardTopLeft = LeaderboardCanvasSlot->GetPosition();
		FVector2D LeaderboardSize = LeaderboardCanvasSlot->GetSize();
		for (int i = 0; i < MaxPlayerNum; i++) {

			FVector2D TextPosition = FVector2D(LeaderboardTopLeft.X, (LeaderboardTopLeft.Y + LeaderboardTextPadding * i) + LeaderboardTopPadding);
			FString PlayerTag = LeaderBoardTagName + FString::FromInt(i + 1);
			UTextBlock* Text = CreateText(PlayerTag);

			UScaleBox* TextScaleBox = CreateScaleBox(FString("Scale " + FString::FromInt(i)));
			LeaderboardGrid->GetParent()->AddChild(TextScaleBox);

			UCanvasPanelSlot* TextScaleCanvasSlot = Cast<UCanvasPanelSlot>(TextScaleBox->Slot);

			TextScaleCanvasSlot->SetSize(FVector2D(LeaderboardSize.X - LeaderboardScaleBoxRightPadding, LeaderboardScaleBoxHeight));

			TextScaleCanvasSlot->SetAnchors(LeaderboardCanvasSlot->GetAnchors());
			TextScaleCanvasSlot->SetPosition(TextPosition);
			TextScaleBox->AddChild(Text);

			Text->SetVisibility(ESlateVisibility::Visible);

			Text->SetOpacity(0.0f);
			LeaderBoardItems.Add(Text);

		

			
		}
		 LeaderboardBorder->SetRenderOpacity(0.0f); 
         LeaderboardHeader->SetRenderOpacity(0.0f); 
		 LeaderboardGrid->SetRenderOpacity(0.0f);
	}

}

UTextBlock* UChargeWidget::CreateText(FString TextContent)
{
	UTextBlock* Text = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), FName(TextContent));

	Text->SetFont(LeaderboardFont);
	Text->SetColorAndOpacity(LeaderboardTextColour);
	Text->SetText(FText::FromString(TextContent));
	return Text;
}
	

UScaleBox* UChargeWidget::CreateScaleBox(FString Name)
{
	UScaleBox* ScaleBox = WidgetTree->ConstructWidget<UScaleBox>(UScaleBox::StaticClass(), FName(Name));

	ScaleBox->SetStretch(EStretch::ScaleToFit); 

	



	return ScaleBox;
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
	float NewOpacity = ((float)ShouldHide); 
	LeaderboardBorder->SetRenderOpacity(NewOpacity);
	LeaderboardHeader->SetRenderOpacity(NewOpacity); 
	LeaderboardGrid->SetRenderOpacity(NewOpacity);

	if (ServerobjectRef != nullptr) {
		int CurrentPlayerCount = ServerobjectRef->GetPlayerCurrentCount(); 
		for (int i = 0; i < CurrentPlayerCount; i++) {

			LeaderBoardItems[i]->SetOpacity(NewOpacity );
	    }
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

void UChargeWidget::SetServerObjectRef(AServerObject* ServerObjectPtr)
{
	ServerobjectRef = ServerObjectPtr;
}



void UChargeWidget::UpdatePlayerLeaderBoardInfo(int Points, int Kills, int PlayerId)
{
	if (PlayerId >= 0 && PlayerId < LeaderBoardItems.Num()) {
		FString LeaderboardTxt = LeaderBoardTagName + FString::FromInt(PlayerId + 1) + " " + "Points:" + FString::FromInt(Points) + " Kills:" + FString::FromInt(Kills);

		LeaderBoardItems[PlayerId]->SetText(FText::FromString(LeaderboardTxt));
		LeaderBoardItems[PlayerId]->SetOpacity((LeaderboardBorder->GetRenderOpacity() > 0.0f));
		return;
	}

	
}

void UChargeWidget::RefreshPlayerLeaderboardInfo()
{
	
	
	FPlayerLeaderBoardInfo info = FPlayerLeaderBoardInfo();

	for (int i = 0; i < ServerobjectRef->GetPlayerCurrentCount(); i++) {
		info = ServerobjectRef->GetPlayerInfo(i);
        

		FString LeaderboardTxt = LeaderBoardTagName + FString::FromInt(i + 1) + " " + "Points:" + FString::FromInt(info.LeaderboardPlayerScore) + " Kills:" + FString::FromInt(info.LeaderboardPlayerKills);

		LeaderBoardItems[i]->SetText(FText::FromString(LeaderboardTxt)); 
	    
		LeaderBoardItems[i]->SetOpacity( ((float)(LeaderboardHeader->GetRenderOpacity() > 0.0f)));

	}

	






}




void UChargeWidget::HighlightPlayerTag(int PlayerIdForTag)
{
	try {
		LeaderBoardItems[PlayerIdForTag]->SetColorAndOpacity(LeaderboardHighlightColour); 
		LeaderBoardItems[PlayerIdForTag]->SetOpacity(((float)(LeaderboardHeader->GetRenderOpacity() > 0.0f)));

	}
	catch (...) {
	}




}

int UChargeWidget::GetThroneHealth()
{
	return ThroneHealth;
}

void UChargeWidget::SetThroneHealth(int NewHealth)
{
	ThroneHealth = NewHealth;
}

int UChargeWidget::GetPlayerWaveNumber()
{
	return DisplayedPlayerWaveNumber;
}


void UChargeWidget::SetPlayerWaveNumber(int WaveNumber) {

	DisplayedPlayerWaveNumber = WaveNumber;

}