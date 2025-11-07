// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHud/ChargeWidget.h"

void UChargeWidget::NativeConstruct() {

	Super::NativeConstruct();

	
	LeaderboardBorder = WidgetTree->FindWidget<UBorder>(FName(LeaderBoardBorderName));
	LeaderboardGrid = WidgetTree->FindWidget<UGridPanel>(FName(LeaderBoardGridPanelName));
	LeaderboardHeader = WidgetTree->FindWidget<UBorder>(FName(LeaderBoardHeaderName));
	if (LeaderboardGrid && LeaderboardHeader && LeaderboardBorder) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Leaderboard border found")));
		
		//GenerateLeaderBoard();
	}
		
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("NO LEADER BOARD border ")));

	}
	
	




}






void UChargeWidget::GenerateLeaderBoard()
{
	LeaderBoardItems = {};
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Bound leader board grid pannel sucessfully")));


	if (UCanvasPanelSlot* LeaderboardCanvasSlot = Cast<UCanvasPanelSlot>(LeaderboardGrid->Slot)) {

		FVector2D LeaderboardTopLeft = LeaderboardCanvasSlot->GetPosition();
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT(" max player num %d"), MaxPlayerNum));

		for (int i = 0; i < MaxPlayerNum; i++) {

			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("Itertaing max player num")));
			FVector2D TextPosition = FVector2D(LeaderboardTopLeft.X, (LeaderboardTopLeft.Y + LeaderboardTextPadding * i) + LeaderboardTopPadding);
			FString PlayerTag = LeaderBoardTagName + FString::FromInt(i + 1);
			UTextBlock* Text = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), FName(PlayerTag));

			Text->SetFont(LeaderboardFont);
			Text->SetColorAndOpacity(LeaderboardTextColour);
			Text->SetText(FText::FromString(PlayerTag));
			LeaderboardGrid->GetParent()->AddChild(Text);
			UCanvasPanelSlot* TextCanvasSlot = Cast<UCanvasPanelSlot>(Text->Slot);
			 

			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("canvas text slot is null %d "), (int)(TextCanvasSlot == nullptr)));
			TextCanvasSlot->SetAnchors(LeaderboardCanvasSlot->GetAnchors());
			TextCanvasSlot->SetPosition(TextPosition);
			LeaderBoardItems.Add(Text);

			if(ServerobjectRef->HasPlayerInfo(i)){

				//Text->SetText(FText::FromString(PlayerTag + ":" + " Current Points:" + FString::FromInt(Info->LeaderboardPlayerScore) + " Kills:" + FString::FromInt(Info->LeaderboardPlayerKills)));



			
		    }
			LeaderBoardItems[i]->SetRenderOpacity(0.0f);

			
		}

	}

}
	
	//LeaderboardBorder->SetRenderOpacity(0.0f); 
	//LeaderboardHeader->SetRenderOpacity(0.0f); 
	//LeaderboardGrid->SetRenderOpacity(0.0f);
	
	



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
	LeaderboardGrid->SetRenderOpacity(NewOpacity);

	if (ServerobjectRef != nullptr) {
		int CurrentPlayerCount = ServerobjectRef->GetPlayerCurrentCount();
		for (int i = 0; i < CurrentPlayerCount; i++) {

			LeaderBoardItems[i]->SetRenderOpacity(NewOpacity);
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
	FString LeaderboardTxt = LeaderBoardTagName + FString::FromInt( PlayerId + 1) +":" + " Current Points:" + FString::FromInt(Points) + " Kills:" + FString::FromInt(Kills);
	LeaderBoardItems[PlayerId]->SetText(FText::FromString(LeaderboardTxt));
	LeaderBoardItems[PlayerId]->SetOpacity(((float)LeaderboardBorder->GetRenderOpacity() > 0.0f ));
}

void UChargeWidget::InitialisePlayerLeaderboardInfo()
{
	



}

