// Fill out your copyright notice in the Description page of Project Settings.


#include "../MiniMapManager/MiniMapManager.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Engine/Canvas.h"
// Sets default values
AMiniMapManager::AMiniMapManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMiniMapManager::BeginPlay()
{
	Super::BeginPlay();
	

	if(m_miniMapAnchorBottom && m_miniMapAnchorTop)
		
	{
		FVector2D Temp = Temp = FVector2D(m_miniMapAnchorBottom->GetActorLocation());
	     // mini map bottom should always be greater in x and y than mini map top 
	     if(m_miniMapAnchorBottom->GetActorLocation().Y < m_miniMapAnchorTop->GetActorLocation().Y)
		 {
			 FVector miniMapBottom = m_miniMapAnchorBottom->GetActorLocation();
			 FVector miniMapTop = m_miniMapAnchorTop->GetActorLocation();
			 m_miniMapAnchorBottom->SetActorLocation(FVector(miniMapBottom.X, miniMapTop.Y, miniMapBottom.Z));

			 m_miniMapAnchorTop->SetActorLocation(FVector(miniMapTop.X,Temp.Y,miniMapTop.Z));

		 }

		 if (m_miniMapAnchorBottom->GetActorLocation().X < m_miniMapAnchorTop->GetActorLocation().X)
		 {
			 FVector miniMapBottom = m_miniMapAnchorBottom->GetActorLocation();
			 FVector miniMapTop = m_miniMapAnchorTop->GetActorLocation();
			 m_miniMapAnchorBottom->SetActorLocation(FVector(miniMapTop.X, miniMapBottom.Y, miniMapBottom.Z));

			 m_miniMapAnchorTop->SetActorLocation(FVector(Temp.X, miniMapTop.Y, miniMapTop.Z));





		 }
	 
	
	}




}

// Called every frame
void AMiniMapManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMiniMapManager::SetMiniMapRenderTargetRef(UTextureRenderTarget2D* MiniMapTexTargetRef)
{
	MiniMapFrontBuffer = MiniMapTexTargetRef;
}

void AMiniMapManager::SetMiniMapParams(int32 Width, int32 Height)
{

	MiniMapFrontBuffer = UKismetRenderingLibrary::CreateRenderTarget2D(this, Width, Height);
	UKismetRenderingLibrary::ClearRenderTarget2D(this, MiniMapFrontBuffer);




}





UTextureRenderTarget2D* AMiniMapManager::GetMiniMapBuffer()
{
	return MiniMapFrontBuffer;
}


void AMiniMapManager::ShouldClearNextFrame(bool Clear)
{
	FirstFrameWrite = Clear;
}


void AMiniMapManager::WriteToMiniMap(FVector WorldPosition, double rotAngle, double MiniMapSectionRadius, UMaterialInstanceDynamic* Material)
{

	if (Material && MiniMapFrontBuffer && MiniMapFrontBuffer->GetResource())
	{

		if(FirstFrameWrite)
		{
			UKismetRenderingLibrary::ClearRenderTarget2D(this, MiniMapFrontBuffer);
			FirstFrameWrite = false;
		}


		FVector2D normalisedCooridnates = CalcMiniMapPos(WorldPosition);

		UCanvas* canvas;
		FVector2D canvasSize;
		FDrawToRenderTargetContext context;
		UKismetRenderingLibrary::BeginDrawCanvasToRenderTarget(this, MiniMapFrontBuffer, canvas, canvasSize, context);
		FVector2D screenSize = FVector2D(MiniMapFrontBuffer->GetSurfaceWidth(), MiniMapFrontBuffer->GetSurfaceHeight());
		FVector2D radi = FVector2D(MiniMapSectionRadius);

		FVector2D centre = (normalisedCooridnates) * screenSize;
		 

		FVector2D topLeft = (centre - (radi * screenSize));

		FVector2D bottomRight = ((radi * 2.0) * screenSize);


		canvas->K2_DrawMaterial(Material, topLeft, bottomRight, FVector2D(0.0), FVector2D(1.0), rotAngle, FVector2D(0.5, 0.5));

		UKismetRenderingLibrary::EndDrawCanvasToRenderTarget(this, context);
		
	}


}




FVector2D AMiniMapManager::CalcMiniMapPos(FVector WorldPosition)
{
	
	if(m_miniMapAnchorTop && m_miniMapAnchorBottom)
	{
		float VerticalPercent = (WorldPosition.X - m_miniMapAnchorTop->GetActorLocation().X) / (m_miniMapAnchorBottom->GetActorLocation().X - m_miniMapAnchorTop->GetActorLocation().X);
		float HorizontalPercent = (WorldPosition.Y - m_miniMapAnchorTop->GetActorLocation().Y) / (m_miniMapAnchorBottom->GetActorLocation().Y - m_miniMapAnchorTop->GetActorLocation().Y);

		return FVector2D(HorizontalPercent,1.0 - VerticalPercent);
	}


	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("MINI MAP WORLD ANCHORS NOT ASSIGNED IN MINI MAP MANAGER")));

	return FVector2D();


}