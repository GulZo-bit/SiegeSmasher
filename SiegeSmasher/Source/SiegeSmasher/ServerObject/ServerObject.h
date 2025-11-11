// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "GameFramework/Actor.h" 
#include "Kismet/GameplayStatics.h" 
#include "Net/UnrealNetwork.h"
#include "ServerObject.generated.h"

// forward declare player class to avoid any circualr dependencies 
class AMainCharacterTest;


/// Here we are making use of the fast tarray replication interface  that unreal provides 
// allowing us to replciate specifc parts of the TArray  that is used to keep track of the Leaderboard state and 
// broad cast it to all players increasing effecieny of network usage and the speed of replciating the TArray 
// used to keep track of the leaderboard state

// we use the FFastArraySerializerItem inteface which is used by the FFastArraySerializer 
// to store specifc information about each item for replciation allowing unreal to 
// keep track of the items within the array using the FFastArraySerilazier interface(discussed below)  as they 
// specifc elements of the TArray are replciated across the network from the server to the clients 


USTRUCT() 
struct FPlayerLeaderBoardInfo: public FFastArraySerializerItem {

	GENERATED_BODY() 
	// the data we want the item within the array to store 
	UPROPERTY();
	int LeaderboardPlayerScore;
	UPROPERTY();
	int LeaderboardPlayerKills;

	// constructors required to set the data for the items contained within the TArray we are serializing 
	FPlayerLeaderBoardInfo(): LeaderboardPlayerScore(0), LeaderboardPlayerKills(0) {};
    FPlayerLeaderBoardInfo(int _PlayerScore,int _PlayerKills):LeaderboardPlayerScore(_PlayerScore), LeaderboardPlayerKills(_PlayerKills){}

	// declaring interface for reciving replciation notifications associated with the TArray containing the 
	// item 
	void PreReplicatedRemove(struct FLeaderboardItems& InArraySerializer);
	void PostReplicatedAdd(struct FLeaderboardItems& InArraySerializer);
	void PostReplicatedChange(struct FLeaderboardItems& InArraySerializer);
	
  
  

};



// here we are implementing the fast TArray interface through the use of a USTRUCT as the interface is primarly mean to 
// be implmenetd for structures this particualr struct will contain the actual TArray to be used for fast TArray replication 
// allowing us to use the FFastArraySerializer to mark specifc items of the array after an opertaion such as adding or modififying to 
// to be repilcated across the network, meaning that in the case of the leaderboard only parts of the TArray used to track player additions 
// and leaderboard info are replicated(meaning that it is not the whole TArray that is copied for each replication) reducing bandwidth usage 
// across the network
USTRUCT()
struct FLeaderboardItems:public FFastArraySerializer
{
	GENERATED_BODY()


	// here we have a TArray member variable that is the array we will replicate using the FFastArraySerializer interface
	UPROPERTY();
	TArray<FPlayerLeaderBoardInfo> Items; 
	
	AMainCharacterTest* PlayerRef = nullptr;

	// this is what allows the Interface to interact with and Serialize are TArray passing in the type of 
	// both the Struct being used to replicate the TArray(this one) and our FPlayerLeaderBoardInfo struct 
	// which implements the FFastArraySerializerItem interface essentially telling unreal the type of data 
	/// to serialize and which TArray the data is located in
	bool NetDeltaSerialize(FNetDeltaSerializeInfo& DeltaParms)
	{
		return FFastArraySerializer::FastArrayDeltaSerialize<FPlayerLeaderBoardInfo, FLeaderboardItems>(Items, DeltaParms, *this);
	}

	
	


};
// defning a struct trait that promises we have implmenetd everhting we need for our FLeaderboardItems struct 
//to use fast array serialization
template<>
struct TStructOpsTypeTraits< FLeaderboardItems > : public TStructOpsTypeTraitsBase2< FLeaderboardItems >
{
	enum
	{
		WithNetDeltaSerializer = true,
	};
};
// defining interface for the replication call backs used by items within the TArray being serialized 
inline void FPlayerLeaderBoardInfo::PostReplicatedAdd(FLeaderboardItems& InArraySerializer){};
inline void FPlayerLeaderBoardInfo::PreReplicatedRemove(FLeaderboardItems& InArraySerializer) {};
inline void FPlayerLeaderBoardInfo::PostReplicatedChange(FLeaderboardItems& InArraySerializer) {};



// this is a class that acts as an absrtaction for the current state of information that needs to be replciated 
// across multiple players rather than on an individual basis making the process much cleaner and easier to work with 
// as we only need to store data on a singualr class that will keep track of things such as leaderboard state 
// as calls are made to it from relevant classes 
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
	// this is an inherited method  that allows us to define how are properties marked for replication 
	// are replciated
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)const;
	// if this server object is on the authroitive machine it will be assigned a refence to the locally 
	// controlled player on that machine allowing us to update the server when using things such as replciation call 
	// backs to update the clients(as they wont be called for the server player)
	AMainCharacterTest* Host  = nullptr;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override; 
	
	void IncrementPlayerCount(); 
	int GetPlayerCurrentCount();
	int GetCurrentPlayerId();  
	void SetHost(AMainCharacterTest* Character);
	AMainCharacterTest* GetHost();


	UPROPERTY(Transient,Replicated);
	int CurrentPlayerCount = 0;  


	void SetPlayerStateToHandle(AMainCharacterTest* PlayerPtr);

	
	void UpdateStoredLeaderBoardInfo(int PlayerPoints, int PlayerKills, int PlayerId);

	bool HasPlayerInfo(int PlayerId);

	FPlayerLeaderBoardInfo GetPlayerInfo(int PlayerId);
	UFUNCTION()
	void OnRep_PlayerWaveNumber();

	void LogMap();

	void IncrementPlayerWaveNumber();
	AMainCharacterTest* GetLocalPlayer();
	//FPlayerLeaderBoardInfo* GetPlayerInfo(int PlayerId);
protected:
	UFUNCTION()
	void OnRep_LeaderBoardState(FLeaderboardItems Old);
	UPROPERTY(Transient,ReplicatedUsing = OnRep_LeaderBoardState);
	FLeaderboardItems LeaderBoardInfo;

	AMainCharacterTest* PlayerRef;
	UPROPERTY(ReplicatedUsing  = OnRep_PlayerWaveNumber);
	int PlayerWaveNumber = 0;

 private: 



	TMap<int,FPlayerLeaderBoardInfo> LeaderBoardPlayerInfo;

	

};
