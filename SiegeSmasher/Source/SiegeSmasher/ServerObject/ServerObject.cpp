// Fill out your copyright notice in the Description page of Project Settings.


#include "ServerObject.h"
#include "../MyMainCharacterTest.h"
// Sets default values




AServerObject::AServerObject()
{
	bReplicates = true;
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");

	

}


void AServerObject::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)const {

	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AServerObject, LeaderBoardInfo);
	DOREPLIFETIME(AServerObject, CurrentPlayerCount);
}

void AServerObject::BeginPlay()
{
	Super::BeginPlay(); 

	


}
AMainCharacterTest* AServerObject::GetHost() {

	return Host;


}


void AServerObject::Tick(float DeltaTime)
{


}

void AServerObject::IncrementPlayerCount()
{
	
	//LeaderBoardPlayerInfo.Add({ CurrentPlayerCount,PlayerRef});
	
   CurrentPlayerCount += 1;

   int32 Index = LeaderBoardInfo.Items.Add(FPlayerLeaderBoardInfo());  
   int32 RepId = LeaderBoardInfo.Items[LeaderBoardInfo.Items.Num() - 1].ReplicationID;



   //LeaderBoardInfo.AddPlayerIdMappedToRepId(GetCurrentPlayerId(), RepId);
   LeaderBoardInfo.MarkItemDirty(LeaderBoardInfo.Items[Index]);

   if (Host != nullptr) {

	   GEngine->AddOnScreenDebugMessage(-1, 35.0f, FColor::Green, FString::Printf(TEXT("Refreshing server leaderboard new player was added")));

	   Host->GetPlayerWidget()->RefreshPlayerLeaderboardInfo();
   }

   //GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Black, FString::Printf(TEXT("incremeting server obejct count %d"), CurrentPlayerCount));
   //GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("Replciated Tarray for leader board count for index for array %d "), LeaderBoardInfo.Items.Num() - 1));
 /*  GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, FString::Printf("Server  current player id %d"), LeaderBoardInfo.ServerObjectRef->GetCurrentPlayerId());*/
}

int AServerObject::GetPlayerCurrentCount()
{
	return CurrentPlayerCount;
}





int AServerObject::GetCurrentPlayerId() {

	return CurrentPlayerCount - 1;
}

void AServerObject::SetHost(AMainCharacterTest* LocalHost)
{
	Host = LocalHost;


}




void AServerObject::SetPlayerStateToHandle(AMainCharacterTest* PlayerPtr)
{

	PlayerRef = PlayerPtr;


}

void AServerObject::MappPlayerIdToReplicatedId(int32 ReplicatedId)
{

	//PlayerIdsToPlayerInfoIndex.Add({ GetCurrentPlayerId(),ReplicatedId });

}

void AServerObject::UpdateStoredLeaderBoardInfo(int PlayerPoints, int PlayerKills, int PlayerId)
{

	try {

		LeaderBoardInfo.Items[PlayerId].LeaderboardPlayerScore = PlayerPoints;
		LeaderBoardInfo.Items[PlayerId].LeaderboardPlayerKills = PlayerKills;

	}
	catch (...) {

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("PLAYER ID FOR LEADER BOARD INFO FOR SERVER OBJECT WAS NULL %d"), PlayerId));
	}



	

	

}

void AServerObject::AdjustLeaderBoardPlayerInfo(int PlayerPoints, int PlayerKills, int PlayerId)
{
	Multicast_AdjustPlayerInfo(PlayerPoints, PlayerKills, PlayerId);

}



void AServerObject::Multicast_AdjustPlayerInfo_Implementation(int PlayerPoints, int PlayerKills, int PlayerId)
{

	if (LeaderBoardPlayerInfo.Find(PlayerId)) {

	}


}





bool AServerObject::HasPlayerInfo(int PlayerId)
{
	try {

		LeaderBoardInfo.Items[PlayerId]; 

		return true;


	}
	catch (...) {

		//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString::Printf(TEXT("Player id did not exists %d"), PlayerId));
		return false;
	}
}

FPlayerLeaderBoardInfo AServerObject::GetPlayerInfo(int PlayerId)
{
	if (HasPlayerInfo(PlayerId)) {

		return LeaderBoardInfo.Items[PlayerId];

	}

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("COULD NOT FIND PLAYER ID WHEN REFRESHING LEADERBOARD ID: %d"), PlayerId)); 
	
	return FPlayerLeaderBoardInfo();


}





void AServerObject::LogMap()
{


	/*for(TTuple<int,AMainCharacterTest*> pair: LeaderBoardPlayerInfo) {

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, FString::Printf(TEXT("Leaderboard map: p:%d k:%d id:%d"), pair.Value->GetScore(), pair.Value->GetKills(), pair.Key));

	}*/

}

void AServerObject::OnRep_LeaderBoardState(FLeaderboardItems Old)
{

	if (Old.Items.Num() < LeaderBoardInfo.Items.Num() && PlayerRef->GetPlayerWidget()) {

		GEngine->AddOnScreenDebugMessage(-1, 35.0f, FColor::Green, FString::Printf(TEXT("Refreshing client leaderboard new player was added %d"),CurrentPlayerCount));

		PlayerRef->GetPlayerWidget()->RefreshPlayerLeaderboardInfo();

		PlayerRef->HighlightPlayerTagOnLeaderboard();


	}

	

}

AMainCharacterTest* AServerObject::GetLocalPlayer()
{
	return PlayerRef;
}

void AServerObject::Multicast_UpdatePlayerLeaderboardInfo_Implementation(int PlayerPoints, int PlayerKills, int PlayerId)
{

	try {

		LeaderBoardInfo.Items[PlayerId].LeaderboardPlayerScore = PlayerPoints;
		LeaderBoardInfo.Items[PlayerId].LeaderboardPlayerKills = PlayerKills;



	}
	catch (...) {

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("PLAYER ID FOR LEADER BOARD INFO FOR SERVER OBJECT WAS NULL %d"), PlayerId));
	}


}















