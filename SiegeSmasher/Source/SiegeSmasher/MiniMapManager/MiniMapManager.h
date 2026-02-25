// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MiniMapManager.generated.h"

UCLASS()
class SIEGESMASHER_API AMiniMapManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMiniMapManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "MiniMapLevelAnchorTopLeft");
	AActor* m_miniMapAnchorTop;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "MiniMapLevelAnchorBottomRight");
	AActor* m_miniMapAnchorBottom;
	
	UPROPERTY(Transient);
	UTextureRenderTarget2D* MiniMapFrontBuffer = nullptr;
	





	bool FirstFrameWrite = true;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetMiniMapRenderTargetRef(UTextureRenderTarget2D* MiniMapTexTargetRef);
	void SetMiniMapParams(int32 Width, int32 Height);
	UTextureRenderTarget2D* GetMiniMapBuffer();


	void ShouldClearNextFrame(bool Clear);
	//void WriteEnemyToMiniMap(FVector WorldPosition, double EnemyRadi, FName EnemyCircleRadiName,double EnemyMiniMapSectionRadius,  UMaterialInstanceDynamic* Material);
	void WriteToMiniMap(FVector WorldPosition, double rotAngle, double MiniMapSectionRadius, UMaterialInstanceDynamic* Material);
	//void WritePlayerToMiniMap(FVector WorldPosition, double rotAngle, double MiniMapSectionRadius, UMaterialInstanceDynamic* material);
	FVector2D CalcMiniMapPos(FVector WorldPosition);
};
