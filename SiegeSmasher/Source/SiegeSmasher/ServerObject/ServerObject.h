// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "GameFramework/Actor.h" 
#include "Kismet/GameplayStatics.h" 
#include "Net/UnrealNetwork.h"
#include "ServerObject.generated.h"



USTRUCT() 
struct FPlayerLeaderBoardInfo: public FFastArraySerializerItem {

	GENERATED_BODY() 

	UPROPERTY();
	int LeaderboardPlayerScore;
	UPROPERTY();
	int LeaderboardPlayerKills;


	FPlayerLeaderBoardInfo(): LeaderboardPlayerScore(0), LeaderboardPlayerKills(0) {};
    FPlayerLeaderBoardInfo(int _PlayerScore,int _PlayerKills):LeaderboardPlayerScore(_PlayerScore), LeaderboardPlayerKills(_PlayerKills){}

	void PreReplicatedRemove(const struct FLeaderboardItems& InArraySerializer);
	void PostReplicatedAdd(const struct FLeaderboardItems& InArraySerializer);
	void PostReplicatedChange(const struct FLeaderboardItems& InArraySerializer);
	

};




USTRUCT()
struct FLeaderboardItems:public FFastArraySerializer
{
	GENERATED_BODY()

	UPROPERTY();
	TArray<FPlayerLeaderBoardInfo> Items; 
	


	bool NetDeltaSerialize(FNetDeltaSerializeInfo& DeltaParms)
	{
		return FFastArraySerializer::FastArrayDeltaSerialize<FPlayerLeaderBoardInfo, FLeaderboardItems>(Items, DeltaParms, *this);
	}

	


};

template<>
struct TStructOpsTypeTraits< FLeaderboardItems > : public TStructOpsTypeTraitsBase2< FLeaderboardItems >
{
	enum
	{
		WithNetDeltaSerializer = true,
	};
};
inline void FPlayerLeaderBoardInfo::PostReplicatedAdd(const FLeaderboardItems& InArraySerializer)
{

	int32 RepId = InArraySerializer.Items[InArraySerializer.Items.Num() - 1].ReplicationID;
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("Replciated Tarray for leader board count for index for array %d "), InArraySerializer.Items.Num() - 1));
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, FString::Printf("Server client current player id %d"), InArraySerializer.ServerObjectRef->GetCurrentPlayerId());
	



};
inline void FPlayerLeaderBoardInfo::PreReplicatedRemove(const FLeaderboardItems& InArraySerializer) {};
inline void FPlayerLeaderBoardInfo::PostReplicatedChange(const FLeaderboardItems& InArraySerializer) {};




class AMainCharacterTest;
UCLASS()
class SIEGESMASHER_API AServerObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AServerObject();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)const;
	
	AMainCharacterTest* Host  = nullptr;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override; 
	void IncrementPlayerCount(); 
	int GetPlayerCurrentCount();
	int GetCurrentPlayerId();  
	void SetHost(AMainCharacterTest* Character);
	AMainCharacterTest* GetHost();
	UFUNCTION()
	void AddLeaderBoardInfoOnIdInc();
	UPROPERTY(ReplicatedUsing  = AddLeaderBoardInfoOnIdInc);
	int CurrentPlayerCount = 0;  

	
	void MappPlayerIdToReplicatedId(int32 ReplicatedId);
	
	void UpdateStoredLeaderBoardInfo(int PlayerPoints, int PlayerKills, int PlayerId);
	void AdjustLeaderBoardPlayerInfo(int PlayerPoints, int PlayerKills, int PlayerId);
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_AdjustPlayerInfo(int PlayerPoints, int PlayerKills, int PlayerId);
	void Multicast_AdjustPlayerInfo_Implementation(int PlayerPoints, int PlayerKills, int PlayerId);

	bool HasPlayerInfo(int PlayerId);

	FPlayerLeaderBoardInfo GetPlayerInfo(int PlayerId);

	void LogMap();

	//FPlayerLeaderBoardInfo* GetPlayerInfo(int PlayerId);
protected:

	UPROPERTY(Replicated); 
	FLeaderboardItems LeaderBoardInfo;


private: 

	TMap<int,FPlayerLeaderBoardInfo> LeaderBoardPlayerInfo;

	

};
