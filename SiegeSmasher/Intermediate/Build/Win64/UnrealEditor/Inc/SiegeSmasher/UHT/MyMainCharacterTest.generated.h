// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyMainCharacterTest.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef SIEGESMASHER_MyMainCharacterTest_generated_h
#error "MyMainCharacterTest.generated.h already included, missing '#pragma once' in MyMainCharacterTest.h"
#endif
#define SIEGESMASHER_MyMainCharacterTest_generated_h

#define FID_Unreal_Projects_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void Multicast_SetPlayerId_Implementation(int32 Id); \
	virtual void Server_SetPlayerId_Implementation(int32 Id); \
	virtual void Multicast_SetPlayerOwnerShip_Implementation(AActor* ActorToOwn); \
	virtual void Server_SetPlayerOwnerShip_Implementation(AActor* ActorToOwn); \
	DECLARE_FUNCTION(execCallClientTravel); \
	DECLARE_FUNCTION(execCallCreateLobby); \
	DECLARE_FUNCTION(execServer_SwitchTower); \
	DECLARE_FUNCTION(execServer_SpawnSelected); \
	DECLARE_FUNCTION(execMulticast_HandleTowerPlacement); \
	DECLARE_FUNCTION(execServer_HandleTowerPlacement); \
	DECLARE_FUNCTION(execMulticast_SetPlayerId); \
	DECLARE_FUNCTION(execServer_SetPlayerId); \
	DECLARE_FUNCTION(execMulticast_SetPlayerOwnerShip); \
	DECLARE_FUNCTION(execServer_SetPlayerOwnerShip); \
	DECLARE_FUNCTION(execServer_StopAim); \
	DECLARE_FUNCTION(execServer_DrawBow); \
	DECLARE_FUNCTION(execServer_UpdateCharge); \
	DECLARE_FUNCTION(execMulti_UpdateCharge); \
	DECLARE_FUNCTION(execMulti_SpawnProjectile); \
	DECLARE_FUNCTION(execServer_ChargeShot); \
	DECLARE_FUNCTION(execServer_SpawnProjectile); \
	DECLARE_FUNCTION(execGetCurrentCharge); \
	DECLARE_FUNCTION(execSetArrowFired); \
	DECLARE_FUNCTION(execGetArrowFired); \
	DECLARE_FUNCTION(execSetArrowDrawn); \
	DECLARE_FUNCTION(execGetArrowDrawn);


#define FID_Unreal_Projects_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_26_CALLBACK_WRAPPERS
#define FID_Unreal_Projects_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMainCharacterTest(); \
	friend struct Z_Construct_UClass_AMainCharacterTest_Statics; \
public: \
	DECLARE_CLASS(AMainCharacterTest, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SiegeSmasher"), NO_API) \
	DECLARE_SERIALIZER(AMainCharacterTest) \
	NO_API void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		ArrowDrawn=NETFIELD_REP_START, \
		ArrowFired, \
		MaxCharge, \
		ChargeRate, \
		CurrentCharge, \
		isCharging, \
		ChargeFinal, \
		ArrowClass, \
		Selected, \
		SelectedTowerIndex, \
		IsPlacingTower, \
		NETFIELD_REP_END=IsPlacingTower	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_Unreal_Projects_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_26_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AMainCharacterTest(AMainCharacterTest&&); \
	AMainCharacterTest(const AMainCharacterTest&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMainCharacterTest); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMainCharacterTest); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMainCharacterTest) \
	NO_API virtual ~AMainCharacterTest();


#define FID_Unreal_Projects_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_23_PROLOG
#define FID_Unreal_Projects_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Projects_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Projects_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_26_CALLBACK_WRAPPERS \
	FID_Unreal_Projects_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_26_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Projects_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SIEGESMASHER_API UClass* StaticClass<class AMainCharacterTest>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Projects_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
