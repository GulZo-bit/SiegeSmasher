// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHud/MyHUD.h"


AMyHUD::AMyHUD() 
{


}

void AMyHUD::DrawHUD()
{
	//provides some simple functions to draw textures and primitives
	Super::DrawHUD();

	if (CrosshairTexture)
	{
		//finds the centre of the canvas
		FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
		//offsets by half of crosshair's dimetions so that the centre of the crosshair allignes with the centre of the canvas
		FVector2D CrossHairDrawPosition(Center.X - (CrosshairTexture -> GetSurfaceWidth() * 0.5f) - 60.0f, Center.Y - (CrosshairTexture->GetSurfaceHeight() *0.5f) + 55.0f);
		//draws the crosshair
		FCanvasTileItem TileItem(CrossHairDrawPosition, CrosshairTexture->GetResource(), FLinearColor::White);
		TileItem.BlendMode = SE_BLEND_Translucent;
		Canvas->DrawItem(TileItem);
	}

}
