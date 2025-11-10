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
// here we increment the player count for the server object 
void AServerObject::IncrementPlayerCount()
{
	
	//LeaderBoardPlayerInfo.Add({ CurrentPlayerCount,PlayerRef});
	
   CurrentPlayerCount += 1;
   // add the item to the replciated TArray used to track leaderboard state 
   int32 Index = LeaderBoardInfo.Items.Add(FPlayerLeaderBoardInfo());  

   // mark the item as dirty meaning that the FFastArraySerializer interface will pick up that the
   // there has been an additon to the TArray and modifiy it accordingly  on each client 
   LeaderBoardInfo.MarkItemDirty(LeaderBoardInfo.Items[Index]);

   // as we are using a replciation call back to modify the TArray storing leaderboard state on the client 
   // that wont get called for the server so when we are adding an item to the leaderboard we check if the server 
   // object we are modififying has a host and if they do we also update and refresh their leaderboard to show the new player 
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



void AServerObject::UpdateStoredLeaderBoardInfo(int PlayerPoints, int PlayerKills, int PlayerId)
{

	if (HasPlayerInfo(PlayerId)) {
		LeaderBoardInfo.Items[PlayerId].LeaderboardPlayerScore = PlayerPoints;
		LeaderBoardInfo.Items[PlayerId].LeaderboardPlayerKills = PlayerKills;

	}
	/*try {
	    LeaderBoardInfo.Items[PlayerId].LeaderboardPlayerScore = PlayerPoints;
		LeaderBoardInfo.Items[PlayerId].LeaderboardPlayerKills = PlayerKills;
	
	}
	catch (...) {

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("PLAYER ID FOR LEADER BOARD INFO FOR SERVER OBJECT WAS NULL %d"), PlayerId));
	}*/



	

	

}










bool AServerObject::HasPlayerInfo(int PlayerId)
{


	return PlayerId >= 0 && PlayerId < LeaderBoardInfo.Items.Num();
	//try {

	//	LeaderBoardInfo.Items[PlayerId]; 

	//	return true;


	//}
	//catch (...) {

	//	//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString::Printf(TEXT("Player id did not exists %d"), PlayerId));
	//	return false;
	//}
}
// used to check if the server object has a particualr player id on the leaderboard 
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
	// when we recive a replciation call back for our TArray that is storing the leaderboard state
	// we track if the Array size increased meaning a player was added on the server side 
	// so we update the player UI using the player ref that is assigned on begin play 
	// (this being the locally controlled player for this server object on the client) 
	// and we also ensure to refresh the players highlight on the leaderboard ensuring they know
	// which player they are
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















