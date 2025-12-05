// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SiegeSmasher/MyMainCharacterTest.h"
#include "UObject/CoreNet.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyMainCharacterTest() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
SIEGESMASHER_API UClass* Z_Construct_UClass_AMainCharacterTest();
SIEGESMASHER_API UClass* Z_Construct_UClass_AMainCharacterTest_NoRegister();
SIEGESMASHER_API UClass* Z_Construct_UClass_AMCArrow_NoRegister();
SIEGESMASHER_API UClass* Z_Construct_UClass_ATowePrePlaceObjectHelper_NoRegister();
SIEGESMASHER_API UClass* Z_Construct_UClass_ATowerBase_NoRegister();
SIEGESMASHER_API UClass* Z_Construct_UClass_UChargeWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
UPackage* Z_Construct_UPackage__Script_SiegeSmasher();
// End Cross Module References

// Begin Class AMainCharacterTest Function CallClientTravel
struct Z_Construct_UFunction_AMainCharacterTest_CallClientTravel_Statics
{
	struct MainCharacterTest_eventCallClientTravel_Parms
	{
		FString Address;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Address_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Address;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AMainCharacterTest_CallClientTravel_Statics::NewProp_Address = { "Address", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventCallClientTravel_Parms, Address), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Address_MetaData), NewProp_Address_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_CallClientTravel_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_CallClientTravel_Statics::NewProp_Address,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_CallClientTravel_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_CallClientTravel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "CallClientTravel", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_CallClientTravel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_CallClientTravel_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMainCharacterTest_CallClientTravel_Statics::MainCharacterTest_eventCallClientTravel_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_CallClientTravel_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_CallClientTravel_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMainCharacterTest_CallClientTravel_Statics::MainCharacterTest_eventCallClientTravel_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_CallClientTravel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_CallClientTravel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execCallClientTravel)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Address);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CallClientTravel(Z_Param_Address);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function CallClientTravel

// Begin Class AMainCharacterTest Function CallCreateLobby
struct Z_Construct_UFunction_AMainCharacterTest_CallCreateLobby_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Online Lobby \n" },
#endif
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Online Lobby" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_CallCreateLobby_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "CallCreateLobby", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_CallCreateLobby_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_CallCreateLobby_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMainCharacterTest_CallCreateLobby()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_CallCreateLobby_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execCallCreateLobby)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CallCreateLobby();
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function CallCreateLobby

// Begin Class AMainCharacterTest Function GameOver
struct Z_Construct_UFunction_AMainCharacterTest_GameOver_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_GameOver_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "GameOver", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_GameOver_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_GameOver_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMainCharacterTest_GameOver()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_GameOver_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execGameOver)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GameOver();
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function GameOver

// Begin Class AMainCharacterTest Function GetArrowDrawn
struct Z_Construct_UFunction_AMainCharacterTest_GetArrowDrawn_Statics
{
	struct MainCharacterTest_eventGetArrowDrawn_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//getters and seeters for the bools for the animation blueprint\n" },
#endif
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "getters and seeters for the bools for the animation blueprint" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AMainCharacterTest_GetArrowDrawn_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((MainCharacterTest_eventGetArrowDrawn_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMainCharacterTest_GetArrowDrawn_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MainCharacterTest_eventGetArrowDrawn_Parms), &Z_Construct_UFunction_AMainCharacterTest_GetArrowDrawn_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_GetArrowDrawn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_GetArrowDrawn_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_GetArrowDrawn_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_GetArrowDrawn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "GetArrowDrawn", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_GetArrowDrawn_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_GetArrowDrawn_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMainCharacterTest_GetArrowDrawn_Statics::MainCharacterTest_eventGetArrowDrawn_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_GetArrowDrawn_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_GetArrowDrawn_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMainCharacterTest_GetArrowDrawn_Statics::MainCharacterTest_eventGetArrowDrawn_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_GetArrowDrawn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_GetArrowDrawn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execGetArrowDrawn)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetArrowDrawn();
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function GetArrowDrawn

// Begin Class AMainCharacterTest Function GetArrowFired
struct Z_Construct_UFunction_AMainCharacterTest_GetArrowFired_Statics
{
	struct MainCharacterTest_eventGetArrowFired_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AMainCharacterTest_GetArrowFired_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((MainCharacterTest_eventGetArrowFired_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMainCharacterTest_GetArrowFired_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MainCharacterTest_eventGetArrowFired_Parms), &Z_Construct_UFunction_AMainCharacterTest_GetArrowFired_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_GetArrowFired_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_GetArrowFired_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_GetArrowFired_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_GetArrowFired_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "GetArrowFired", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_GetArrowFired_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_GetArrowFired_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMainCharacterTest_GetArrowFired_Statics::MainCharacterTest_eventGetArrowFired_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_GetArrowFired_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_GetArrowFired_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMainCharacterTest_GetArrowFired_Statics::MainCharacterTest_eventGetArrowFired_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_GetArrowFired()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_GetArrowFired_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execGetArrowFired)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetArrowFired();
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function GetArrowFired

// Begin Class AMainCharacterTest Function GetCurrentCharge
struct Z_Construct_UFunction_AMainCharacterTest_GetCurrentCharge_Statics
{
	struct MainCharacterTest_eventGetCurrentCharge_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMainCharacterTest_GetCurrentCharge_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventGetCurrentCharge_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_GetCurrentCharge_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_GetCurrentCharge_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_GetCurrentCharge_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_GetCurrentCharge_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "GetCurrentCharge", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_GetCurrentCharge_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_GetCurrentCharge_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMainCharacterTest_GetCurrentCharge_Statics::MainCharacterTest_eventGetCurrentCharge_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_GetCurrentCharge_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_GetCurrentCharge_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMainCharacterTest_GetCurrentCharge_Statics::MainCharacterTest_eventGetCurrentCharge_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_GetCurrentCharge()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_GetCurrentCharge_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execGetCurrentCharge)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetCurrentCharge();
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function GetCurrentCharge

// Begin Class AMainCharacterTest Function Multi_PlaySound
struct MainCharacterTest_eventMulti_PlaySound_Parms
{
	USoundBase* Sound;
};
static const FName NAME_AMainCharacterTest_Multi_PlaySound = FName(TEXT("Multi_PlaySound"));
void AMainCharacterTest::Multi_PlaySound(USoundBase* Sound)
{
	MainCharacterTest_eventMulti_PlaySound_Parms Parms;
	Parms.Sound=Sound;
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Multi_PlaySound);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMainCharacterTest_Multi_PlaySound_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Sound;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMainCharacterTest_Multi_PlaySound_Statics::NewProp_Sound = { "Sound", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventMulti_PlaySound_Parms, Sound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_Multi_PlaySound_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Multi_PlaySound_Statics::NewProp_Sound,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Multi_PlaySound_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Multi_PlaySound_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Multi_PlaySound", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_Multi_PlaySound_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Multi_PlaySound_Statics::PropPointers), sizeof(MainCharacterTest_eventMulti_PlaySound_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80024CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Multi_PlaySound_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Multi_PlaySound_Statics::Function_MetaDataParams) };
static_assert(sizeof(MainCharacterTest_eventMulti_PlaySound_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_Multi_PlaySound()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Multi_PlaySound_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execMulti_PlaySound)
{
	P_GET_OBJECT(USoundBase,Z_Param_Sound);
	P_FINISH;
	P_NATIVE_BEGIN;
	if (!P_THIS->Multi_PlaySound_Validate(Z_Param_Sound))
	{
		RPC_ValidateFailed(TEXT("Multi_PlaySound_Validate"));
		return;
	}
	P_THIS->Multi_PlaySound_Implementation(Z_Param_Sound);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Multi_PlaySound

// Begin Class AMainCharacterTest Function Multicast_HighlightPlayerId
struct MainCharacterTest_eventMulticast_HighlightPlayerId_Parms
{
	int32 PlayerServerId;
};
static const FName NAME_AMainCharacterTest_Multicast_HighlightPlayerId = FName(TEXT("Multicast_HighlightPlayerId"));
void AMainCharacterTest::Multicast_HighlightPlayerId(int32 PlayerServerId)
{
	MainCharacterTest_eventMulticast_HighlightPlayerId_Parms Parms;
	Parms.PlayerServerId=PlayerServerId;
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Multicast_HighlightPlayerId);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMainCharacterTest_Multicast_HighlightPlayerId_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_PlayerServerId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMainCharacterTest_Multicast_HighlightPlayerId_Statics::NewProp_PlayerServerId = { "PlayerServerId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventMulticast_HighlightPlayerId_Parms, PlayerServerId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_Multicast_HighlightPlayerId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Multicast_HighlightPlayerId_Statics::NewProp_PlayerServerId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Multicast_HighlightPlayerId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Multicast_HighlightPlayerId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Multicast_HighlightPlayerId", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_Multicast_HighlightPlayerId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Multicast_HighlightPlayerId_Statics::PropPointers), sizeof(MainCharacterTest_eventMulticast_HighlightPlayerId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00024CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Multicast_HighlightPlayerId_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Multicast_HighlightPlayerId_Statics::Function_MetaDataParams) };
static_assert(sizeof(MainCharacterTest_eventMulticast_HighlightPlayerId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_Multicast_HighlightPlayerId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Multicast_HighlightPlayerId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execMulticast_HighlightPlayerId)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_PlayerServerId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Multicast_HighlightPlayerId_Implementation(Z_Param_PlayerServerId);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Multicast_HighlightPlayerId

// Begin Class AMainCharacterTest Function Multicast_RefreshLeaderboard
static const FName NAME_AMainCharacterTest_Multicast_RefreshLeaderboard = FName(TEXT("Multicast_RefreshLeaderboard"));
void AMainCharacterTest::Multicast_RefreshLeaderboard()
{
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Multicast_RefreshLeaderboard);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_AMainCharacterTest_Multicast_RefreshLeaderboard_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Multicast_RefreshLeaderboard_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Multicast_RefreshLeaderboard", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00024CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Multicast_RefreshLeaderboard_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Multicast_RefreshLeaderboard_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMainCharacterTest_Multicast_RefreshLeaderboard()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Multicast_RefreshLeaderboard_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execMulticast_RefreshLeaderboard)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Multicast_RefreshLeaderboard_Implementation();
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Multicast_RefreshLeaderboard

// Begin Class AMainCharacterTest Function Multicast_SetLeaderBoardTxt
struct MainCharacterTest_eventMulticast_SetLeaderBoardTxt_Parms
{
	int32 NewPlayerPoint;
	int32 NewPlayerKills;
	int32 LeaderBoardPlayerId;
};
static const FName NAME_AMainCharacterTest_Multicast_SetLeaderBoardTxt = FName(TEXT("Multicast_SetLeaderBoardTxt"));
void AMainCharacterTest::Multicast_SetLeaderBoardTxt(int32 NewPlayerPoint, int32 NewPlayerKills, int32 LeaderBoardPlayerId)
{
	MainCharacterTest_eventMulticast_SetLeaderBoardTxt_Parms Parms;
	Parms.NewPlayerPoint=NewPlayerPoint;
	Parms.NewPlayerKills=NewPlayerKills;
	Parms.LeaderBoardPlayerId=LeaderBoardPlayerId;
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Multicast_SetLeaderBoardTxt);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMainCharacterTest_Multicast_SetLeaderBoardTxt_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_NewPlayerPoint;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NewPlayerKills;
	static const UECodeGen_Private::FIntPropertyParams NewProp_LeaderBoardPlayerId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMainCharacterTest_Multicast_SetLeaderBoardTxt_Statics::NewProp_NewPlayerPoint = { "NewPlayerPoint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventMulticast_SetLeaderBoardTxt_Parms, NewPlayerPoint), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMainCharacterTest_Multicast_SetLeaderBoardTxt_Statics::NewProp_NewPlayerKills = { "NewPlayerKills", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventMulticast_SetLeaderBoardTxt_Parms, NewPlayerKills), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMainCharacterTest_Multicast_SetLeaderBoardTxt_Statics::NewProp_LeaderBoardPlayerId = { "LeaderBoardPlayerId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventMulticast_SetLeaderBoardTxt_Parms, LeaderBoardPlayerId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_Multicast_SetLeaderBoardTxt_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Multicast_SetLeaderBoardTxt_Statics::NewProp_NewPlayerPoint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Multicast_SetLeaderBoardTxt_Statics::NewProp_NewPlayerKills,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Multicast_SetLeaderBoardTxt_Statics::NewProp_LeaderBoardPlayerId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Multicast_SetLeaderBoardTxt_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Multicast_SetLeaderBoardTxt_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Multicast_SetLeaderBoardTxt", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_Multicast_SetLeaderBoardTxt_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Multicast_SetLeaderBoardTxt_Statics::PropPointers), sizeof(MainCharacterTest_eventMulticast_SetLeaderBoardTxt_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00084CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Multicast_SetLeaderBoardTxt_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Multicast_SetLeaderBoardTxt_Statics::Function_MetaDataParams) };
static_assert(sizeof(MainCharacterTest_eventMulticast_SetLeaderBoardTxt_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_Multicast_SetLeaderBoardTxt()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Multicast_SetLeaderBoardTxt_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execMulticast_SetLeaderBoardTxt)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_NewPlayerPoint);
	P_GET_PROPERTY(FIntProperty,Z_Param_NewPlayerKills);
	P_GET_PROPERTY(FIntProperty,Z_Param_LeaderBoardPlayerId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Multicast_SetLeaderBoardTxt_Implementation(Z_Param_NewPlayerPoint,Z_Param_NewPlayerKills,Z_Param_LeaderBoardPlayerId);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Multicast_SetLeaderBoardTxt

// Begin Class AMainCharacterTest Function Multicast_SetPlayerOwnerShip
struct MainCharacterTest_eventMulticast_SetPlayerOwnerShip_Parms
{
	AActor* ActorToOwn;
};
static const FName NAME_AMainCharacterTest_Multicast_SetPlayerOwnerShip = FName(TEXT("Multicast_SetPlayerOwnerShip"));
void AMainCharacterTest::Multicast_SetPlayerOwnerShip(AActor* ActorToOwn)
{
	MainCharacterTest_eventMulticast_SetPlayerOwnerShip_Parms Parms;
	Parms.ActorToOwn=ActorToOwn;
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Multicast_SetPlayerOwnerShip);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerOwnerShip_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActorToOwn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerOwnerShip_Statics::NewProp_ActorToOwn = { "ActorToOwn", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventMulticast_SetPlayerOwnerShip_Parms, ActorToOwn), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerOwnerShip_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerOwnerShip_Statics::NewProp_ActorToOwn,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerOwnerShip_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerOwnerShip_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Multicast_SetPlayerOwnerShip", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerOwnerShip_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerOwnerShip_Statics::PropPointers), sizeof(MainCharacterTest_eventMulticast_SetPlayerOwnerShip_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00024CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerOwnerShip_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerOwnerShip_Statics::Function_MetaDataParams) };
static_assert(sizeof(MainCharacterTest_eventMulticast_SetPlayerOwnerShip_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerOwnerShip()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerOwnerShip_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execMulticast_SetPlayerOwnerShip)
{
	P_GET_OBJECT(AActor,Z_Param_ActorToOwn);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Multicast_SetPlayerOwnerShip_Implementation(Z_Param_ActorToOwn);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Multicast_SetPlayerOwnerShip

// Begin Class AMainCharacterTest Function Multicast_UpdateChargeBar
static const FName NAME_AMainCharacterTest_Multicast_UpdateChargeBar = FName(TEXT("Multicast_UpdateChargeBar"));
void AMainCharacterTest::Multicast_UpdateChargeBar()
{
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Multicast_UpdateChargeBar);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_AMainCharacterTest_Multicast_UpdateChargeBar_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Multicast_UpdateChargeBar_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Multicast_UpdateChargeBar", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00024CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Multicast_UpdateChargeBar_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Multicast_UpdateChargeBar_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMainCharacterTest_Multicast_UpdateChargeBar()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Multicast_UpdateChargeBar_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execMulticast_UpdateChargeBar)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Multicast_UpdateChargeBar_Implementation();
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Multicast_UpdateChargeBar

// Begin Class AMainCharacterTest Function MultiCast_UpdateLeaderBoardInfo
struct MainCharacterTest_eventMultiCast_UpdateLeaderBoardInfo_Parms
{
	int32 NewPlayerPoints;
	int32 NewPlayerKills;
	int32 TargetPlayerId;
};
static const FName NAME_AMainCharacterTest_MultiCast_UpdateLeaderBoardInfo = FName(TEXT("MultiCast_UpdateLeaderBoardInfo"));
void AMainCharacterTest::MultiCast_UpdateLeaderBoardInfo(int32 NewPlayerPoints, int32 NewPlayerKills, int32 TargetPlayerId)
{
	MainCharacterTest_eventMultiCast_UpdateLeaderBoardInfo_Parms Parms;
	Parms.NewPlayerPoints=NewPlayerPoints;
	Parms.NewPlayerKills=NewPlayerKills;
	Parms.TargetPlayerId=TargetPlayerId;
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_MultiCast_UpdateLeaderBoardInfo);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMainCharacterTest_MultiCast_UpdateLeaderBoardInfo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_NewPlayerPoints;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NewPlayerKills;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TargetPlayerId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMainCharacterTest_MultiCast_UpdateLeaderBoardInfo_Statics::NewProp_NewPlayerPoints = { "NewPlayerPoints", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventMultiCast_UpdateLeaderBoardInfo_Parms, NewPlayerPoints), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMainCharacterTest_MultiCast_UpdateLeaderBoardInfo_Statics::NewProp_NewPlayerKills = { "NewPlayerKills", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventMultiCast_UpdateLeaderBoardInfo_Parms, NewPlayerKills), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMainCharacterTest_MultiCast_UpdateLeaderBoardInfo_Statics::NewProp_TargetPlayerId = { "TargetPlayerId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventMultiCast_UpdateLeaderBoardInfo_Parms, TargetPlayerId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_MultiCast_UpdateLeaderBoardInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_MultiCast_UpdateLeaderBoardInfo_Statics::NewProp_NewPlayerPoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_MultiCast_UpdateLeaderBoardInfo_Statics::NewProp_NewPlayerKills,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_MultiCast_UpdateLeaderBoardInfo_Statics::NewProp_TargetPlayerId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_MultiCast_UpdateLeaderBoardInfo_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_MultiCast_UpdateLeaderBoardInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "MultiCast_UpdateLeaderBoardInfo", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_MultiCast_UpdateLeaderBoardInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_MultiCast_UpdateLeaderBoardInfo_Statics::PropPointers), sizeof(MainCharacterTest_eventMultiCast_UpdateLeaderBoardInfo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00084CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_MultiCast_UpdateLeaderBoardInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_MultiCast_UpdateLeaderBoardInfo_Statics::Function_MetaDataParams) };
static_assert(sizeof(MainCharacterTest_eventMultiCast_UpdateLeaderBoardInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_MultiCast_UpdateLeaderBoardInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_MultiCast_UpdateLeaderBoardInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execMultiCast_UpdateLeaderBoardInfo)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_NewPlayerPoints);
	P_GET_PROPERTY(FIntProperty,Z_Param_NewPlayerKills);
	P_GET_PROPERTY(FIntProperty,Z_Param_TargetPlayerId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->MultiCast_UpdateLeaderBoardInfo_Implementation(Z_Param_NewPlayerPoints,Z_Param_NewPlayerKills,Z_Param_TargetPlayerId);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function MultiCast_UpdateLeaderBoardInfo

// Begin Class AMainCharacterTest Function PlayerDeath
struct Z_Construct_UFunction_AMainCharacterTest_PlayerDeath_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_PlayerDeath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "PlayerDeath", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_PlayerDeath_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_PlayerDeath_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMainCharacterTest_PlayerDeath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_PlayerDeath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execPlayerDeath)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PlayerDeath();
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function PlayerDeath

// Begin Class AMainCharacterTest Function PlayImpactSound
struct Z_Construct_UFunction_AMainCharacterTest_PlayImpactSound_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_PlayImpactSound_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "PlayImpactSound", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_PlayImpactSound_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_PlayImpactSound_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMainCharacterTest_PlayImpactSound()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_PlayImpactSound_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execPlayImpactSound)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PlayImpactSound();
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function PlayImpactSound

// Begin Class AMainCharacterTest Function Server_AssignPlayerId
struct MainCharacterTest_eventServer_AssignPlayerId_Parms
{
	int32 Id;
};
static const FName NAME_AMainCharacterTest_Server_AssignPlayerId = FName(TEXT("Server_AssignPlayerId"));
void AMainCharacterTest::Server_AssignPlayerId(int32 Id)
{
	MainCharacterTest_eventServer_AssignPlayerId_Parms Parms;
	Parms.Id=Id;
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Server_AssignPlayerId);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMainCharacterTest_Server_AssignPlayerId_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Id;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMainCharacterTest_Server_AssignPlayerId_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventServer_AssignPlayerId_Parms, Id), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_Server_AssignPlayerId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Server_AssignPlayerId_Statics::NewProp_Id,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_AssignPlayerId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Server_AssignPlayerId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Server_AssignPlayerId", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_Server_AssignPlayerId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_AssignPlayerId_Statics::PropPointers), sizeof(MainCharacterTest_eventServer_AssignPlayerId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_AssignPlayerId_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Server_AssignPlayerId_Statics::Function_MetaDataParams) };
static_assert(sizeof(MainCharacterTest_eventServer_AssignPlayerId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_Server_AssignPlayerId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Server_AssignPlayerId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execServer_AssignPlayerId)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Id);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_AssignPlayerId_Implementation(Z_Param_Id);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Server_AssignPlayerId

// Begin Class AMainCharacterTest Function Server_ChargeShot
struct MainCharacterTest_eventServer_ChargeShot_Parms
{
	float DeltaTime;
};
static const FName NAME_AMainCharacterTest_Server_ChargeShot = FName(TEXT("Server_ChargeShot"));
void AMainCharacterTest::Server_ChargeShot(float DeltaTime)
{
	MainCharacterTest_eventServer_ChargeShot_Parms Parms;
	Parms.DeltaTime=DeltaTime;
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Server_ChargeShot);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMainCharacterTest_Server_ChargeShot_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMainCharacterTest_Server_ChargeShot_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventServer_ChargeShot_Parms, DeltaTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_Server_ChargeShot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Server_ChargeShot_Statics::NewProp_DeltaTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_ChargeShot_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Server_ChargeShot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Server_ChargeShot", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_Server_ChargeShot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_ChargeShot_Statics::PropPointers), sizeof(MainCharacterTest_eventServer_ChargeShot_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_ChargeShot_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Server_ChargeShot_Statics::Function_MetaDataParams) };
static_assert(sizeof(MainCharacterTest_eventServer_ChargeShot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_Server_ChargeShot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Server_ChargeShot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execServer_ChargeShot)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaTime);
	P_FINISH;
	P_NATIVE_BEGIN;
	if (!P_THIS->Server_ChargeShot_Validate(Z_Param_DeltaTime))
	{
		RPC_ValidateFailed(TEXT("Server_ChargeShot_Validate"));
		return;
	}
	P_THIS->Server_ChargeShot_Implementation(Z_Param_DeltaTime);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Server_ChargeShot

// Begin Class AMainCharacterTest Function Server_DisplaySelected
static const FName NAME_AMainCharacterTest_Server_DisplaySelected = FName(TEXT("Server_DisplaySelected"));
void AMainCharacterTest::Server_DisplaySelected()
{
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Server_DisplaySelected);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_AMainCharacterTest_Server_DisplaySelected_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Server_DisplaySelected_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Server_DisplaySelected", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_DisplaySelected_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Server_DisplaySelected_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMainCharacterTest_Server_DisplaySelected()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Server_DisplaySelected_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execServer_DisplaySelected)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_DisplaySelected_Implementation();
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Server_DisplaySelected

// Begin Class AMainCharacterTest Function Server_DrawBow
static const FName NAME_AMainCharacterTest_Server_DrawBow = FName(TEXT("Server_DrawBow"));
void AMainCharacterTest::Server_DrawBow()
{
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Server_DrawBow);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_AMainCharacterTest_Server_DrawBow_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Server_DrawBow_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Server_DrawBow", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_DrawBow_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Server_DrawBow_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMainCharacterTest_Server_DrawBow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Server_DrawBow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execServer_DrawBow)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	if (!P_THIS->Server_DrawBow_Validate())
	{
		RPC_ValidateFailed(TEXT("Server_DrawBow_Validate"));
		return;
	}
	P_THIS->Server_DrawBow_Implementation();
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Server_DrawBow

// Begin Class AMainCharacterTest Function Server_HandleTowerPlacement
struct MainCharacterTest_eventServer_HandleTowerPlacement_Parms
{
	FVector CamForward;
	FVector CamPosition;
};
static const FName NAME_AMainCharacterTest_Server_HandleTowerPlacement = FName(TEXT("Server_HandleTowerPlacement"));
void AMainCharacterTest::Server_HandleTowerPlacement(FVector CamForward, FVector CamPosition)
{
	MainCharacterTest_eventServer_HandleTowerPlacement_Parms Parms;
	Parms.CamForward=CamForward;
	Parms.CamPosition=CamPosition;
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Server_HandleTowerPlacement);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMainCharacterTest_Server_HandleTowerPlacement_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CamForward;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CamPosition;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMainCharacterTest_Server_HandleTowerPlacement_Statics::NewProp_CamForward = { "CamForward", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventServer_HandleTowerPlacement_Parms, CamForward), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMainCharacterTest_Server_HandleTowerPlacement_Statics::NewProp_CamPosition = { "CamPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventServer_HandleTowerPlacement_Parms, CamPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_Server_HandleTowerPlacement_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Server_HandleTowerPlacement_Statics::NewProp_CamForward,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Server_HandleTowerPlacement_Statics::NewProp_CamPosition,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_HandleTowerPlacement_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Server_HandleTowerPlacement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Server_HandleTowerPlacement", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_Server_HandleTowerPlacement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_HandleTowerPlacement_Statics::PropPointers), sizeof(MainCharacterTest_eventServer_HandleTowerPlacement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00A20CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_HandleTowerPlacement_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Server_HandleTowerPlacement_Statics::Function_MetaDataParams) };
static_assert(sizeof(MainCharacterTest_eventServer_HandleTowerPlacement_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_Server_HandleTowerPlacement()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Server_HandleTowerPlacement_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execServer_HandleTowerPlacement)
{
	P_GET_STRUCT(FVector,Z_Param_CamForward);
	P_GET_STRUCT(FVector,Z_Param_CamPosition);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_HandleTowerPlacement_Implementation(Z_Param_CamForward,Z_Param_CamPosition);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Server_HandleTowerPlacement

// Begin Class AMainCharacterTest Function Server_HideSelected
static const FName NAME_AMainCharacterTest_Server_HideSelected = FName(TEXT("Server_HideSelected"));
void AMainCharacterTest::Server_HideSelected()
{
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Server_HideSelected);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_AMainCharacterTest_Server_HideSelected_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Server_HideSelected_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Server_HideSelected", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_HideSelected_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Server_HideSelected_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMainCharacterTest_Server_HideSelected()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Server_HideSelected_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execServer_HideSelected)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_HideSelected_Implementation();
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Server_HideSelected

// Begin Class AMainCharacterTest Function Server_IncrementLoggedPlayerCount
static const FName NAME_AMainCharacterTest_Server_IncrementLoggedPlayerCount = FName(TEXT("Server_IncrementLoggedPlayerCount"));
void AMainCharacterTest::Server_IncrementLoggedPlayerCount()
{
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Server_IncrementLoggedPlayerCount);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_AMainCharacterTest_Server_IncrementLoggedPlayerCount_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Server_IncrementLoggedPlayerCount_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Server_IncrementLoggedPlayerCount", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_IncrementLoggedPlayerCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Server_IncrementLoggedPlayerCount_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMainCharacterTest_Server_IncrementLoggedPlayerCount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Server_IncrementLoggedPlayerCount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execServer_IncrementLoggedPlayerCount)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_IncrementLoggedPlayerCount_Implementation();
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Server_IncrementLoggedPlayerCount

// Begin Class AMainCharacterTest Function Server_IncrementPlayerScore
struct MainCharacterTest_eventServer_IncrementPlayerScore_Parms
{
	int32 increment;
};
static const FName NAME_AMainCharacterTest_Server_IncrementPlayerScore = FName(TEXT("Server_IncrementPlayerScore"));
void AMainCharacterTest::Server_IncrementPlayerScore(int32 increment)
{
	MainCharacterTest_eventServer_IncrementPlayerScore_Parms Parms;
	Parms.increment=increment;
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Server_IncrementPlayerScore);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMainCharacterTest_Server_IncrementPlayerScore_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_increment;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMainCharacterTest_Server_IncrementPlayerScore_Statics::NewProp_increment = { "increment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventServer_IncrementPlayerScore_Parms, increment), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_Server_IncrementPlayerScore_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Server_IncrementPlayerScore_Statics::NewProp_increment,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_IncrementPlayerScore_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Server_IncrementPlayerScore_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Server_IncrementPlayerScore", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_Server_IncrementPlayerScore_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_IncrementPlayerScore_Statics::PropPointers), sizeof(MainCharacterTest_eventServer_IncrementPlayerScore_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_IncrementPlayerScore_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Server_IncrementPlayerScore_Statics::Function_MetaDataParams) };
static_assert(sizeof(MainCharacterTest_eventServer_IncrementPlayerScore_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_Server_IncrementPlayerScore()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Server_IncrementPlayerScore_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execServer_IncrementPlayerScore)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_increment);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_IncrementPlayerScore_Implementation(Z_Param_increment);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Server_IncrementPlayerScore

// Begin Class AMainCharacterTest Function Server_PushSelected
struct MainCharacterTest_eventServer_PushSelected_Parms
{
	FTransform ClientSelectedTransform;
	FVector SelectRayStart;
	FVector SelectRayEnd;
	FVector SelectedRayDir;
};
static const FName NAME_AMainCharacterTest_Server_PushSelected = FName(TEXT("Server_PushSelected"));
void AMainCharacterTest::Server_PushSelected(FTransform ClientSelectedTransform, FVector SelectRayStart, FVector SelectRayEnd, FVector SelectedRayDir)
{
	MainCharacterTest_eventServer_PushSelected_Parms Parms;
	Parms.ClientSelectedTransform=ClientSelectedTransform;
	Parms.SelectRayStart=SelectRayStart;
	Parms.SelectRayEnd=SelectRayEnd;
	Parms.SelectedRayDir=SelectedRayDir;
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Server_PushSelected);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMainCharacterTest_Server_PushSelected_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ClientSelectedTransform;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SelectRayStart;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SelectRayEnd;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SelectedRayDir;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMainCharacterTest_Server_PushSelected_Statics::NewProp_ClientSelectedTransform = { "ClientSelectedTransform", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventServer_PushSelected_Parms, ClientSelectedTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMainCharacterTest_Server_PushSelected_Statics::NewProp_SelectRayStart = { "SelectRayStart", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventServer_PushSelected_Parms, SelectRayStart), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMainCharacterTest_Server_PushSelected_Statics::NewProp_SelectRayEnd = { "SelectRayEnd", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventServer_PushSelected_Parms, SelectRayEnd), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMainCharacterTest_Server_PushSelected_Statics::NewProp_SelectedRayDir = { "SelectedRayDir", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventServer_PushSelected_Parms, SelectedRayDir), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_Server_PushSelected_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Server_PushSelected_Statics::NewProp_ClientSelectedTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Server_PushSelected_Statics::NewProp_SelectRayStart,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Server_PushSelected_Statics::NewProp_SelectRayEnd,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Server_PushSelected_Statics::NewProp_SelectedRayDir,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_PushSelected_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Server_PushSelected_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Server_PushSelected", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_Server_PushSelected_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_PushSelected_Statics::PropPointers), sizeof(MainCharacterTest_eventServer_PushSelected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00A20C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_PushSelected_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Server_PushSelected_Statics::Function_MetaDataParams) };
static_assert(sizeof(MainCharacterTest_eventServer_PushSelected_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_Server_PushSelected()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Server_PushSelected_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execServer_PushSelected)
{
	P_GET_STRUCT(FTransform,Z_Param_ClientSelectedTransform);
	P_GET_STRUCT(FVector,Z_Param_SelectRayStart);
	P_GET_STRUCT(FVector,Z_Param_SelectRayEnd);
	P_GET_STRUCT(FVector,Z_Param_SelectedRayDir);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_PushSelected_Implementation(Z_Param_ClientSelectedTransform,Z_Param_SelectRayStart,Z_Param_SelectRayEnd,Z_Param_SelectedRayDir);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Server_PushSelected

// Begin Class AMainCharacterTest Function Server_RefreshLeaderboard
static const FName NAME_AMainCharacterTest_Server_RefreshLeaderboard = FName(TEXT("Server_RefreshLeaderboard"));
void AMainCharacterTest::Server_RefreshLeaderboard()
{
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Server_RefreshLeaderboard);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_AMainCharacterTest_Server_RefreshLeaderboard_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Server_RefreshLeaderboard_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Server_RefreshLeaderboard", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_RefreshLeaderboard_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Server_RefreshLeaderboard_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMainCharacterTest_Server_RefreshLeaderboard()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Server_RefreshLeaderboard_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execServer_RefreshLeaderboard)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_RefreshLeaderboard_Implementation();
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Server_RefreshLeaderboard

// Begin Class AMainCharacterTest Function Server_SetHealth
struct MainCharacterTest_eventServer_SetHealth_Parms
{
	float HealthStore;
};
static const FName NAME_AMainCharacterTest_Server_SetHealth = FName(TEXT("Server_SetHealth"));
void AMainCharacterTest::Server_SetHealth(float HealthStore)
{
	MainCharacterTest_eventServer_SetHealth_Parms Parms;
	Parms.HealthStore=HealthStore;
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Server_SetHealth);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMainCharacterTest_Server_SetHealth_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HealthStore;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMainCharacterTest_Server_SetHealth_Statics::NewProp_HealthStore = { "HealthStore", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventServer_SetHealth_Parms, HealthStore), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_Server_SetHealth_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Server_SetHealth_Statics::NewProp_HealthStore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_SetHealth_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Server_SetHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Server_SetHealth", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_Server_SetHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_SetHealth_Statics::PropPointers), sizeof(MainCharacterTest_eventServer_SetHealth_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_SetHealth_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Server_SetHealth_Statics::Function_MetaDataParams) };
static_assert(sizeof(MainCharacterTest_eventServer_SetHealth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_Server_SetHealth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Server_SetHealth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execServer_SetHealth)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_HealthStore);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_SetHealth_Implementation(Z_Param_HealthStore);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Server_SetHealth

// Begin Class AMainCharacterTest Function Server_SetPlaceTower
struct MainCharacterTest_eventServer_SetPlaceTower_Parms
{
	bool PlaceTower;
};
static const FName NAME_AMainCharacterTest_Server_SetPlaceTower = FName(TEXT("Server_SetPlaceTower"));
void AMainCharacterTest::Server_SetPlaceTower(bool PlaceTower)
{
	MainCharacterTest_eventServer_SetPlaceTower_Parms Parms;
	Parms.PlaceTower=PlaceTower ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Server_SetPlaceTower);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMainCharacterTest_Server_SetPlaceTower_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static void NewProp_PlaceTower_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_PlaceTower;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AMainCharacterTest_Server_SetPlaceTower_Statics::NewProp_PlaceTower_SetBit(void* Obj)
{
	((MainCharacterTest_eventServer_SetPlaceTower_Parms*)Obj)->PlaceTower = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMainCharacterTest_Server_SetPlaceTower_Statics::NewProp_PlaceTower = { "PlaceTower", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MainCharacterTest_eventServer_SetPlaceTower_Parms), &Z_Construct_UFunction_AMainCharacterTest_Server_SetPlaceTower_Statics::NewProp_PlaceTower_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_Server_SetPlaceTower_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Server_SetPlaceTower_Statics::NewProp_PlaceTower,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_SetPlaceTower_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Server_SetPlaceTower_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Server_SetPlaceTower", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_Server_SetPlaceTower_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_SetPlaceTower_Statics::PropPointers), sizeof(MainCharacterTest_eventServer_SetPlaceTower_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_SetPlaceTower_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Server_SetPlaceTower_Statics::Function_MetaDataParams) };
static_assert(sizeof(MainCharacterTest_eventServer_SetPlaceTower_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_Server_SetPlaceTower()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Server_SetPlaceTower_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execServer_SetPlaceTower)
{
	P_GET_UBOOL(Z_Param_PlaceTower);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_SetPlaceTower_Implementation(Z_Param_PlaceTower);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Server_SetPlaceTower

// Begin Class AMainCharacterTest Function Server_SetPlayerOwnerShip
struct MainCharacterTest_eventServer_SetPlayerOwnerShip_Parms
{
	AActor* ActorToOwn;
};
static const FName NAME_AMainCharacterTest_Server_SetPlayerOwnerShip = FName(TEXT("Server_SetPlayerOwnerShip"));
void AMainCharacterTest::Server_SetPlayerOwnerShip(AActor* ActorToOwn)
{
	MainCharacterTest_eventServer_SetPlayerOwnerShip_Parms Parms;
	Parms.ActorToOwn=ActorToOwn;
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Server_SetPlayerOwnerShip);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerOwnerShip_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActorToOwn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerOwnerShip_Statics::NewProp_ActorToOwn = { "ActorToOwn", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventServer_SetPlayerOwnerShip_Parms, ActorToOwn), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerOwnerShip_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerOwnerShip_Statics::NewProp_ActorToOwn,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerOwnerShip_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerOwnerShip_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Server_SetPlayerOwnerShip", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerOwnerShip_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerOwnerShip_Statics::PropPointers), sizeof(MainCharacterTest_eventServer_SetPlayerOwnerShip_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerOwnerShip_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerOwnerShip_Statics::Function_MetaDataParams) };
static_assert(sizeof(MainCharacterTest_eventServer_SetPlayerOwnerShip_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerOwnerShip()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerOwnerShip_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execServer_SetPlayerOwnerShip)
{
	P_GET_OBJECT(AActor,Z_Param_ActorToOwn);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_SetPlayerOwnerShip_Implementation(Z_Param_ActorToOwn);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Server_SetPlayerOwnerShip

// Begin Class AMainCharacterTest Function Server_SpawnProjectile
struct MainCharacterTest_eventServer_SpawnProjectile_Parms
{
	FRotator CamRotation;
	FRotator BowRot;
};
static const FName NAME_AMainCharacterTest_Server_SpawnProjectile = FName(TEXT("Server_SpawnProjectile"));
void AMainCharacterTest::Server_SpawnProjectile(FRotator CamRotation, FRotator BowRot)
{
	MainCharacterTest_eventServer_SpawnProjectile_Parms Parms;
	Parms.CamRotation=CamRotation;
	Parms.BowRot=BowRot;
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Server_SpawnProjectile);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMainCharacterTest_Server_SpawnProjectile_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CamRotation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BowRot;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMainCharacterTest_Server_SpawnProjectile_Statics::NewProp_CamRotation = { "CamRotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventServer_SpawnProjectile_Parms, CamRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMainCharacterTest_Server_SpawnProjectile_Statics::NewProp_BowRot = { "BowRot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventServer_SpawnProjectile_Parms, BowRot), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_Server_SpawnProjectile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Server_SpawnProjectile_Statics::NewProp_CamRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Server_SpawnProjectile_Statics::NewProp_BowRot,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_SpawnProjectile_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Server_SpawnProjectile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Server_SpawnProjectile", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_Server_SpawnProjectile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_SpawnProjectile_Statics::PropPointers), sizeof(MainCharacterTest_eventServer_SpawnProjectile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80A20CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_SpawnProjectile_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Server_SpawnProjectile_Statics::Function_MetaDataParams) };
static_assert(sizeof(MainCharacterTest_eventServer_SpawnProjectile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_Server_SpawnProjectile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Server_SpawnProjectile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execServer_SpawnProjectile)
{
	P_GET_STRUCT(FRotator,Z_Param_CamRotation);
	P_GET_STRUCT(FRotator,Z_Param_BowRot);
	P_FINISH;
	P_NATIVE_BEGIN;
	if (!P_THIS->Server_SpawnProjectile_Validate(Z_Param_CamRotation,Z_Param_BowRot))
	{
		RPC_ValidateFailed(TEXT("Server_SpawnProjectile_Validate"));
		return;
	}
	P_THIS->Server_SpawnProjectile_Implementation(Z_Param_CamRotation,Z_Param_BowRot);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Server_SpawnProjectile

// Begin Class AMainCharacterTest Function Server_SpawnSelected
struct MainCharacterTest_eventServer_SpawnSelected_Parms
{
	bool PlacingTower;
	bool ToggleTower;
};
static const FName NAME_AMainCharacterTest_Server_SpawnSelected = FName(TEXT("Server_SpawnSelected"));
void AMainCharacterTest::Server_SpawnSelected(bool PlacingTower, bool ToggleTower)
{
	MainCharacterTest_eventServer_SpawnSelected_Parms Parms;
	Parms.PlacingTower=PlacingTower ? true : false;
	Parms.ToggleTower=ToggleTower ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Server_SpawnSelected);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMainCharacterTest_Server_SpawnSelected_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static void NewProp_PlacingTower_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_PlacingTower;
	static void NewProp_ToggleTower_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ToggleTower;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AMainCharacterTest_Server_SpawnSelected_Statics::NewProp_PlacingTower_SetBit(void* Obj)
{
	((MainCharacterTest_eventServer_SpawnSelected_Parms*)Obj)->PlacingTower = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMainCharacterTest_Server_SpawnSelected_Statics::NewProp_PlacingTower = { "PlacingTower", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MainCharacterTest_eventServer_SpawnSelected_Parms), &Z_Construct_UFunction_AMainCharacterTest_Server_SpawnSelected_Statics::NewProp_PlacingTower_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AMainCharacterTest_Server_SpawnSelected_Statics::NewProp_ToggleTower_SetBit(void* Obj)
{
	((MainCharacterTest_eventServer_SpawnSelected_Parms*)Obj)->ToggleTower = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMainCharacterTest_Server_SpawnSelected_Statics::NewProp_ToggleTower = { "ToggleTower", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MainCharacterTest_eventServer_SpawnSelected_Parms), &Z_Construct_UFunction_AMainCharacterTest_Server_SpawnSelected_Statics::NewProp_ToggleTower_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_Server_SpawnSelected_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Server_SpawnSelected_Statics::NewProp_PlacingTower,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Server_SpawnSelected_Statics::NewProp_ToggleTower,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_SpawnSelected_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Server_SpawnSelected_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Server_SpawnSelected", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_Server_SpawnSelected_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_SpawnSelected_Statics::PropPointers), sizeof(MainCharacterTest_eventServer_SpawnSelected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_SpawnSelected_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Server_SpawnSelected_Statics::Function_MetaDataParams) };
static_assert(sizeof(MainCharacterTest_eventServer_SpawnSelected_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_Server_SpawnSelected()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Server_SpawnSelected_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execServer_SpawnSelected)
{
	P_GET_UBOOL(Z_Param_PlacingTower);
	P_GET_UBOOL(Z_Param_ToggleTower);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_SpawnSelected_Implementation(Z_Param_PlacingTower,Z_Param_ToggleTower);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Server_SpawnSelected

// Begin Class AMainCharacterTest Function Server_StopAim
static const FName NAME_AMainCharacterTest_Server_StopAim = FName(TEXT("Server_StopAim"));
void AMainCharacterTest::Server_StopAim()
{
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Server_StopAim);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_AMainCharacterTest_Server_StopAim_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Server_StopAim_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Server_StopAim", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_StopAim_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Server_StopAim_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMainCharacterTest_Server_StopAim()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Server_StopAim_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execServer_StopAim)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	if (!P_THIS->Server_StopAim_Validate())
	{
		RPC_ValidateFailed(TEXT("Server_StopAim_Validate"));
		return;
	}
	P_THIS->Server_StopAim_Implementation();
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Server_StopAim

// Begin Class AMainCharacterTest Function Server_SwitchTower
struct MainCharacterTest_eventServer_SwitchTower_Parms
{
	int32 SelectedIndex;
	bool ToggleTower;
};
static const FName NAME_AMainCharacterTest_Server_SwitchTower = FName(TEXT("Server_SwitchTower"));
void AMainCharacterTest::Server_SwitchTower(int32 SelectedIndex, bool ToggleTower)
{
	MainCharacterTest_eventServer_SwitchTower_Parms Parms;
	Parms.SelectedIndex=SelectedIndex;
	Parms.ToggleTower=ToggleTower ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Server_SwitchTower);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMainCharacterTest_Server_SwitchTower_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_SelectedIndex;
	static void NewProp_ToggleTower_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ToggleTower;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMainCharacterTest_Server_SwitchTower_Statics::NewProp_SelectedIndex = { "SelectedIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventServer_SwitchTower_Parms, SelectedIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AMainCharacterTest_Server_SwitchTower_Statics::NewProp_ToggleTower_SetBit(void* Obj)
{
	((MainCharacterTest_eventServer_SwitchTower_Parms*)Obj)->ToggleTower = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMainCharacterTest_Server_SwitchTower_Statics::NewProp_ToggleTower = { "ToggleTower", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MainCharacterTest_eventServer_SwitchTower_Parms), &Z_Construct_UFunction_AMainCharacterTest_Server_SwitchTower_Statics::NewProp_ToggleTower_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_Server_SwitchTower_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Server_SwitchTower_Statics::NewProp_SelectedIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Server_SwitchTower_Statics::NewProp_ToggleTower,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_SwitchTower_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Server_SwitchTower_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Server_SwitchTower", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_Server_SwitchTower_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_SwitchTower_Statics::PropPointers), sizeof(MainCharacterTest_eventServer_SwitchTower_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_SwitchTower_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Server_SwitchTower_Statics::Function_MetaDataParams) };
static_assert(sizeof(MainCharacterTest_eventServer_SwitchTower_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_Server_SwitchTower()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Server_SwitchTower_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execServer_SwitchTower)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_SelectedIndex);
	P_GET_UBOOL(Z_Param_ToggleTower);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_SwitchTower_Implementation(Z_Param_SelectedIndex,Z_Param_ToggleTower);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Server_SwitchTower

// Begin Class AMainCharacterTest Function Server_ToggleTowers
struct MainCharacterTest_eventServer_ToggleTowers_Parms
{
	bool ToggleTower;
};
static const FName NAME_AMainCharacterTest_Server_ToggleTowers = FName(TEXT("Server_ToggleTowers"));
void AMainCharacterTest::Server_ToggleTowers(bool ToggleTower)
{
	MainCharacterTest_eventServer_ToggleTowers_Parms Parms;
	Parms.ToggleTower=ToggleTower ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Server_ToggleTowers);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMainCharacterTest_Server_ToggleTowers_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ToggleTower_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ToggleTower;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AMainCharacterTest_Server_ToggleTowers_Statics::NewProp_ToggleTower_SetBit(void* Obj)
{
	((MainCharacterTest_eventServer_ToggleTowers_Parms*)Obj)->ToggleTower = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMainCharacterTest_Server_ToggleTowers_Statics::NewProp_ToggleTower = { "ToggleTower", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MainCharacterTest_eventServer_ToggleTowers_Parms), &Z_Construct_UFunction_AMainCharacterTest_Server_ToggleTowers_Statics::NewProp_ToggleTower_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_Server_ToggleTowers_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Server_ToggleTowers_Statics::NewProp_ToggleTower,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_ToggleTowers_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Server_ToggleTowers_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Server_ToggleTowers", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_Server_ToggleTowers_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_ToggleTowers_Statics::PropPointers), sizeof(MainCharacterTest_eventServer_ToggleTowers_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_ToggleTowers_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Server_ToggleTowers_Statics::Function_MetaDataParams) };
static_assert(sizeof(MainCharacterTest_eventServer_ToggleTowers_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_Server_ToggleTowers()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Server_ToggleTowers_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execServer_ToggleTowers)
{
	P_GET_UBOOL(Z_Param_ToggleTower);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_ToggleTowers_Implementation(Z_Param_ToggleTower);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Server_ToggleTowers

// Begin Class AMainCharacterTest Function Server_UpdateCharge
struct MainCharacterTest_eventServer_UpdateCharge_Parms
{
	float ClientCharge;
};
static const FName NAME_AMainCharacterTest_Server_UpdateCharge = FName(TEXT("Server_UpdateCharge"));
void AMainCharacterTest::Server_UpdateCharge(float ClientCharge)
{
	MainCharacterTest_eventServer_UpdateCharge_Parms Parms;
	Parms.ClientCharge=ClientCharge;
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Server_UpdateCharge);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMainCharacterTest_Server_UpdateCharge_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ClientCharge;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMainCharacterTest_Server_UpdateCharge_Statics::NewProp_ClientCharge = { "ClientCharge", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventServer_UpdateCharge_Parms, ClientCharge), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_Server_UpdateCharge_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Server_UpdateCharge_Statics::NewProp_ClientCharge,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_UpdateCharge_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Server_UpdateCharge_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Server_UpdateCharge", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_Server_UpdateCharge_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_UpdateCharge_Statics::PropPointers), sizeof(MainCharacterTest_eventServer_UpdateCharge_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_UpdateCharge_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Server_UpdateCharge_Statics::Function_MetaDataParams) };
static_assert(sizeof(MainCharacterTest_eventServer_UpdateCharge_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_Server_UpdateCharge()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Server_UpdateCharge_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execServer_UpdateCharge)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_ClientCharge);
	P_FINISH;
	P_NATIVE_BEGIN;
	if (!P_THIS->Server_UpdateCharge_Validate(Z_Param_ClientCharge))
	{
		RPC_ValidateFailed(TEXT("Server_UpdateCharge_Validate"));
		return;
	}
	P_THIS->Server_UpdateCharge_Implementation(Z_Param_ClientCharge);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Server_UpdateCharge

// Begin Class AMainCharacterTest Function Server_UpdatePlayerInfoKills
static const FName NAME_AMainCharacterTest_Server_UpdatePlayerInfoKills = FName(TEXT("Server_UpdatePlayerInfoKills"));
void AMainCharacterTest::Server_UpdatePlayerInfoKills()
{
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Server_UpdatePlayerInfoKills);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_AMainCharacterTest_Server_UpdatePlayerInfoKills_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Server_UpdatePlayerInfoKills_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Server_UpdatePlayerInfoKills", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_UpdatePlayerInfoKills_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Server_UpdatePlayerInfoKills_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMainCharacterTest_Server_UpdatePlayerInfoKills()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Server_UpdatePlayerInfoKills_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execServer_UpdatePlayerInfoKills)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_UpdatePlayerInfoKills_Implementation();
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Server_UpdatePlayerInfoKills

// Begin Class AMainCharacterTest Function Server_UpdatePlayerInfoKillsInc
struct MainCharacterTest_eventServer_UpdatePlayerInfoKillsInc_Parms
{
	int32 inc;
};
static const FName NAME_AMainCharacterTest_Server_UpdatePlayerInfoKillsInc = FName(TEXT("Server_UpdatePlayerInfoKillsInc"));
void AMainCharacterTest::Server_UpdatePlayerInfoKillsInc(int32 inc)
{
	MainCharacterTest_eventServer_UpdatePlayerInfoKillsInc_Parms Parms;
	Parms.inc=inc;
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Server_UpdatePlayerInfoKillsInc);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMainCharacterTest_Server_UpdatePlayerInfoKillsInc_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_inc;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMainCharacterTest_Server_UpdatePlayerInfoKillsInc_Statics::NewProp_inc = { "inc", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventServer_UpdatePlayerInfoKillsInc_Parms, inc), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_Server_UpdatePlayerInfoKillsInc_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Server_UpdatePlayerInfoKillsInc_Statics::NewProp_inc,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_UpdatePlayerInfoKillsInc_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Server_UpdatePlayerInfoKillsInc_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Server_UpdatePlayerInfoKillsInc", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_Server_UpdatePlayerInfoKillsInc_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_UpdatePlayerInfoKillsInc_Statics::PropPointers), sizeof(MainCharacterTest_eventServer_UpdatePlayerInfoKillsInc_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_UpdatePlayerInfoKillsInc_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Server_UpdatePlayerInfoKillsInc_Statics::Function_MetaDataParams) };
static_assert(sizeof(MainCharacterTest_eventServer_UpdatePlayerInfoKillsInc_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_Server_UpdatePlayerInfoKillsInc()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Server_UpdatePlayerInfoKillsInc_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execServer_UpdatePlayerInfoKillsInc)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_inc);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_UpdatePlayerInfoKillsInc_Implementation(Z_Param_inc);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Server_UpdatePlayerInfoKillsInc

// Begin Class AMainCharacterTest Function SetArrowDrawn
struct Z_Construct_UFunction_AMainCharacterTest_SetArrowDrawn_Statics
{
	struct MainCharacterTest_eventSetArrowDrawn_Parms
	{
		bool isArrowDrawn;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static void NewProp_isArrowDrawn_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_isArrowDrawn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AMainCharacterTest_SetArrowDrawn_Statics::NewProp_isArrowDrawn_SetBit(void* Obj)
{
	((MainCharacterTest_eventSetArrowDrawn_Parms*)Obj)->isArrowDrawn = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMainCharacterTest_SetArrowDrawn_Statics::NewProp_isArrowDrawn = { "isArrowDrawn", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MainCharacterTest_eventSetArrowDrawn_Parms), &Z_Construct_UFunction_AMainCharacterTest_SetArrowDrawn_Statics::NewProp_isArrowDrawn_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_SetArrowDrawn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_SetArrowDrawn_Statics::NewProp_isArrowDrawn,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_SetArrowDrawn_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_SetArrowDrawn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "SetArrowDrawn", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_SetArrowDrawn_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_SetArrowDrawn_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMainCharacterTest_SetArrowDrawn_Statics::MainCharacterTest_eventSetArrowDrawn_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_SetArrowDrawn_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_SetArrowDrawn_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMainCharacterTest_SetArrowDrawn_Statics::MainCharacterTest_eventSetArrowDrawn_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_SetArrowDrawn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_SetArrowDrawn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execSetArrowDrawn)
{
	P_GET_UBOOL(Z_Param_isArrowDrawn);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetArrowDrawn(Z_Param_isArrowDrawn);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function SetArrowDrawn

// Begin Class AMainCharacterTest Function SetArrowFired
struct Z_Construct_UFunction_AMainCharacterTest_SetArrowFired_Statics
{
	struct MainCharacterTest_eventSetArrowFired_Parms
	{
		bool isArrowDrawn;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static void NewProp_isArrowDrawn_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_isArrowDrawn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AMainCharacterTest_SetArrowFired_Statics::NewProp_isArrowDrawn_SetBit(void* Obj)
{
	((MainCharacterTest_eventSetArrowFired_Parms*)Obj)->isArrowDrawn = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMainCharacterTest_SetArrowFired_Statics::NewProp_isArrowDrawn = { "isArrowDrawn", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MainCharacterTest_eventSetArrowFired_Parms), &Z_Construct_UFunction_AMainCharacterTest_SetArrowFired_Statics::NewProp_isArrowDrawn_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_SetArrowFired_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_SetArrowFired_Statics::NewProp_isArrowDrawn,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_SetArrowFired_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_SetArrowFired_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "SetArrowFired", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_SetArrowFired_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_SetArrowFired_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMainCharacterTest_SetArrowFired_Statics::MainCharacterTest_eventSetArrowFired_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_SetArrowFired_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_SetArrowFired_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMainCharacterTest_SetArrowFired_Statics::MainCharacterTest_eventSetArrowFired_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_SetArrowFired()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_SetArrowFired_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execSetArrowFired)
{
	P_GET_UBOOL(Z_Param_isArrowDrawn);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetArrowFired(Z_Param_isArrowDrawn);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function SetArrowFired

// Begin Class AMainCharacterTest Function SetBaseHealth
struct Z_Construct_UFunction_AMainCharacterTest_SetBaseHealth_Statics
{
	struct MainCharacterTest_eventSetBaseHealth_Parms
	{
		int32 NewHealth;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_NewHealth;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMainCharacterTest_SetBaseHealth_Statics::NewProp_NewHealth = { "NewHealth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventSetBaseHealth_Parms, NewHealth), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_SetBaseHealth_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_SetBaseHealth_Statics::NewProp_NewHealth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_SetBaseHealth_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_SetBaseHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "SetBaseHealth", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_SetBaseHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_SetBaseHealth_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMainCharacterTest_SetBaseHealth_Statics::MainCharacterTest_eventSetBaseHealth_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_SetBaseHealth_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_SetBaseHealth_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMainCharacterTest_SetBaseHealth_Statics::MainCharacterTest_eventSetBaseHealth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_SetBaseHealth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_SetBaseHealth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execSetBaseHealth)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_NewHealth);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetBaseHealth(Z_Param_NewHealth);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function SetBaseHealth

// Begin Class AMainCharacterTest Function UpdateHealthWidget
struct Z_Construct_UFunction_AMainCharacterTest_UpdateHealthWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_UpdateHealthWidget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "UpdateHealthWidget", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_UpdateHealthWidget_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_UpdateHealthWidget_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMainCharacterTest_UpdateHealthWidget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_UpdateHealthWidget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execUpdateHealthWidget)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateHealthWidget();
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function UpdateHealthWidget

// Begin Class AMainCharacterTest Function UpdatePlayerScoreUi
struct Z_Construct_UFunction_AMainCharacterTest_UpdatePlayerScoreUi_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_UpdatePlayerScoreUi_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "UpdatePlayerScoreUi", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_UpdatePlayerScoreUi_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_UpdatePlayerScoreUi_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMainCharacterTest_UpdatePlayerScoreUi()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_UpdatePlayerScoreUi_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execUpdatePlayerScoreUi)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdatePlayerScoreUi();
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function UpdatePlayerScoreUi

// Begin Class AMainCharacterTest
void AMainCharacterTest::StaticRegisterNativesAMainCharacterTest()
{
	UClass* Class = AMainCharacterTest::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CallClientTravel", &AMainCharacterTest::execCallClientTravel },
		{ "CallCreateLobby", &AMainCharacterTest::execCallCreateLobby },
		{ "GameOver", &AMainCharacterTest::execGameOver },
		{ "GetArrowDrawn", &AMainCharacterTest::execGetArrowDrawn },
		{ "GetArrowFired", &AMainCharacterTest::execGetArrowFired },
		{ "GetCurrentCharge", &AMainCharacterTest::execGetCurrentCharge },
		{ "Multi_PlaySound", &AMainCharacterTest::execMulti_PlaySound },
		{ "Multicast_HighlightPlayerId", &AMainCharacterTest::execMulticast_HighlightPlayerId },
		{ "Multicast_RefreshLeaderboard", &AMainCharacterTest::execMulticast_RefreshLeaderboard },
		{ "Multicast_SetLeaderBoardTxt", &AMainCharacterTest::execMulticast_SetLeaderBoardTxt },
		{ "Multicast_SetPlayerOwnerShip", &AMainCharacterTest::execMulticast_SetPlayerOwnerShip },
		{ "Multicast_UpdateChargeBar", &AMainCharacterTest::execMulticast_UpdateChargeBar },
		{ "MultiCast_UpdateLeaderBoardInfo", &AMainCharacterTest::execMultiCast_UpdateLeaderBoardInfo },
		{ "PlayerDeath", &AMainCharacterTest::execPlayerDeath },
		{ "PlayImpactSound", &AMainCharacterTest::execPlayImpactSound },
		{ "Server_AssignPlayerId", &AMainCharacterTest::execServer_AssignPlayerId },
		{ "Server_ChargeShot", &AMainCharacterTest::execServer_ChargeShot },
		{ "Server_DisplaySelected", &AMainCharacterTest::execServer_DisplaySelected },
		{ "Server_DrawBow", &AMainCharacterTest::execServer_DrawBow },
		{ "Server_HandleTowerPlacement", &AMainCharacterTest::execServer_HandleTowerPlacement },
		{ "Server_HideSelected", &AMainCharacterTest::execServer_HideSelected },
		{ "Server_IncrementLoggedPlayerCount", &AMainCharacterTest::execServer_IncrementLoggedPlayerCount },
		{ "Server_IncrementPlayerScore", &AMainCharacterTest::execServer_IncrementPlayerScore },
		{ "Server_PushSelected", &AMainCharacterTest::execServer_PushSelected },
		{ "Server_RefreshLeaderboard", &AMainCharacterTest::execServer_RefreshLeaderboard },
		{ "Server_SetHealth", &AMainCharacterTest::execServer_SetHealth },
		{ "Server_SetPlaceTower", &AMainCharacterTest::execServer_SetPlaceTower },
		{ "Server_SetPlayerOwnerShip", &AMainCharacterTest::execServer_SetPlayerOwnerShip },
		{ "Server_SpawnProjectile", &AMainCharacterTest::execServer_SpawnProjectile },
		{ "Server_SpawnSelected", &AMainCharacterTest::execServer_SpawnSelected },
		{ "Server_StopAim", &AMainCharacterTest::execServer_StopAim },
		{ "Server_SwitchTower", &AMainCharacterTest::execServer_SwitchTower },
		{ "Server_ToggleTowers", &AMainCharacterTest::execServer_ToggleTowers },
		{ "Server_UpdateCharge", &AMainCharacterTest::execServer_UpdateCharge },
		{ "Server_UpdatePlayerInfoKills", &AMainCharacterTest::execServer_UpdatePlayerInfoKills },
		{ "Server_UpdatePlayerInfoKillsInc", &AMainCharacterTest::execServer_UpdatePlayerInfoKillsInc },
		{ "SetArrowDrawn", &AMainCharacterTest::execSetArrowDrawn },
		{ "SetArrowFired", &AMainCharacterTest::execSetArrowFired },
		{ "SetBaseHealth", &AMainCharacterTest::execSetBaseHealth },
		{ "UpdateHealthWidget", &AMainCharacterTest::execUpdateHealthWidget },
		{ "UpdatePlayerScoreUi", &AMainCharacterTest::execUpdatePlayerScoreUi },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMainCharacterTest);
UClass* Z_Construct_UClass_AMainCharacterTest_NoRegister()
{
	return AMainCharacterTest::StaticClass();
}
struct Z_Construct_UClass_AMainCharacterTest_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "MyMainCharacterTest.h" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TPSCameraComponent_MetaData[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Camera and Spring arm components\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera and Spring arm components" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpringArmComponent_MetaData[] = {
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArrowDrawn_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Bools that handle animations \n" },
#endif
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Bools that handle animations" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArrowFired_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxCharge_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//flaot and bool for the Charging mechanic \n" },
#endif
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "flaot and bool for the Charging mechanic" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChargeRate_MetaData[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentCharge_MetaData[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_isCharging_MetaData[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChargeFinal_MetaData[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CanShoot_MetaData[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultContext_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Jump Input Action\n" },
#endif
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Jump Input Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Move input action\n" },
#endif
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Move input action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Look Input Action\n" },
#endif
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Look Input Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TowerPlacementAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SwitchTowerAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToggleTowerPlacementAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToggleLeaderboardAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShootAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//input for triggering the shooting action\n" },
#endif
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "input for triggering the shooting action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DrawAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//input for triggering the draw action\n" },
#endif
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "input for triggering the draw action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StopAimAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//input that triggers stop aiming, which makes the player go back to their default animations\n" },
#endif
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "input that triggers stop aiming, which makes the player go back to their default animations" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArrowClass_MetaData[] = {
		{ "Category", "Projectile" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Projectile class to spawn.\n" },
#endif
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Projectile class to spawn." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BowPosition_MetaData[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Static mesh that serves as a spawning point for the arrows\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Static mesh that serves as a spawning point for the arrows" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerHUD_MetaData[] = {
		{ "Category", "Charge" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Reference to the widget that will be created, it has to be a subclass of the UserWidget\n" },
#endif
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reference to the widget that will be created, it has to be a subclass of the UserWidget" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChargeWidget_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Holds the created widget\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Holds the created widget" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerGameOverWidgetToCreate_MetaData[] = {
		{ "Category", "GameOver" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClientGameOverWidgetToCreate_MetaData[] = {
		{ "Category", "GameOver" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerGameOverWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClientGameOverWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TowerTypesToSpawn_MetaData[] = {
		{ "Category", "TowersTypesToSpawn" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TowerPrePlacementObjectsToSpawn_MetaData[] = {
		{ "Category", "TowerPlacementObjects" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerPlacementDistances_MetaData[] = {
		{ "Category", "Player Placement distances" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerRespawnPoint_MetaData[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerKills_MetaData[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerPoints_MetaData[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FiringSound_MetaData[] = {
		{ "Category", "Sound" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DrawingSound_MetaData[] = {
		{ "Category", "Sound" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArrowImpact_MetaData[] = {
		{ "Category", "Sound" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerId_MetaData[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartingPoints_MetaData[] = {
		{ "Category", "Points" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedTowerIndex_MetaData[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsPlacingTower_MetaData[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TPSCameraComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArmComponent;
	static void NewProp_ArrowDrawn_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ArrowDrawn;
	static void NewProp_ArrowFired_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ArrowFired;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxCharge;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ChargeRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentCharge;
	static void NewProp_isCharging_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_isCharging;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ChargeFinal;
	static void NewProp_CanShoot_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_CanShoot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TowerPlacementAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SwitchTowerAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ToggleTowerPlacementAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ToggleLeaderboardAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ShootAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DrawAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StopAimAction;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ArrowClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BowPosition;
	static const UECodeGen_Private::FClassPropertyParams NewProp_PlayerHUD;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ChargeWidget;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ServerGameOverWidgetToCreate;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ClientGameOverWidgetToCreate;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ServerGameOverWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ClientGameOverWidget;
	static const UECodeGen_Private::FClassPropertyParams NewProp_TowerTypesToSpawn_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_TowerTypesToSpawn;
	static const UECodeGen_Private::FClassPropertyParams NewProp_TowerPrePlacementObjectsToSpawn_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_TowerPrePlacementObjectsToSpawn;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PlayerPlacementDistances;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PlayerRespawnPoint;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PlayerKills;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PlayerPoints;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FiringSound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DrawingSound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ArrowImpact;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PlayerId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_StartingPoints;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SelectedTowerIndex;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Health;
	static void NewProp_IsPlacingTower_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsPlacingTower;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMainCharacterTest_CallClientTravel, "CallClientTravel" }, // 60708357
		{ &Z_Construct_UFunction_AMainCharacterTest_CallCreateLobby, "CallCreateLobby" }, // 2808711649
		{ &Z_Construct_UFunction_AMainCharacterTest_GameOver, "GameOver" }, // 3982272053
		{ &Z_Construct_UFunction_AMainCharacterTest_GetArrowDrawn, "GetArrowDrawn" }, // 3054430967
		{ &Z_Construct_UFunction_AMainCharacterTest_GetArrowFired, "GetArrowFired" }, // 1961892374
		{ &Z_Construct_UFunction_AMainCharacterTest_GetCurrentCharge, "GetCurrentCharge" }, // 2381322748
		{ &Z_Construct_UFunction_AMainCharacterTest_Multi_PlaySound, "Multi_PlaySound" }, // 392478787
		{ &Z_Construct_UFunction_AMainCharacterTest_Multicast_HighlightPlayerId, "Multicast_HighlightPlayerId" }, // 3038855002
		{ &Z_Construct_UFunction_AMainCharacterTest_Multicast_RefreshLeaderboard, "Multicast_RefreshLeaderboard" }, // 1719534208
		{ &Z_Construct_UFunction_AMainCharacterTest_Multicast_SetLeaderBoardTxt, "Multicast_SetLeaderBoardTxt" }, // 2627821470
		{ &Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerOwnerShip, "Multicast_SetPlayerOwnerShip" }, // 2508787000
		{ &Z_Construct_UFunction_AMainCharacterTest_Multicast_UpdateChargeBar, "Multicast_UpdateChargeBar" }, // 3134933563
		{ &Z_Construct_UFunction_AMainCharacterTest_MultiCast_UpdateLeaderBoardInfo, "MultiCast_UpdateLeaderBoardInfo" }, // 903030730
		{ &Z_Construct_UFunction_AMainCharacterTest_PlayerDeath, "PlayerDeath" }, // 90301063
		{ &Z_Construct_UFunction_AMainCharacterTest_PlayImpactSound, "PlayImpactSound" }, // 726518344
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_AssignPlayerId, "Server_AssignPlayerId" }, // 2447794298
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_ChargeShot, "Server_ChargeShot" }, // 2527664862
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_DisplaySelected, "Server_DisplaySelected" }, // 1541395764
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_DrawBow, "Server_DrawBow" }, // 2904301876
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_HandleTowerPlacement, "Server_HandleTowerPlacement" }, // 1548410931
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_HideSelected, "Server_HideSelected" }, // 3583241420
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_IncrementLoggedPlayerCount, "Server_IncrementLoggedPlayerCount" }, // 3689756712
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_IncrementPlayerScore, "Server_IncrementPlayerScore" }, // 3027720613
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_PushSelected, "Server_PushSelected" }, // 468828593
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_RefreshLeaderboard, "Server_RefreshLeaderboard" }, // 1557732749
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_SetHealth, "Server_SetHealth" }, // 1769299309
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_SetPlaceTower, "Server_SetPlaceTower" }, // 2021991398
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerOwnerShip, "Server_SetPlayerOwnerShip" }, // 1835589500
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_SpawnProjectile, "Server_SpawnProjectile" }, // 3106002752
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_SpawnSelected, "Server_SpawnSelected" }, // 60122345
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_StopAim, "Server_StopAim" }, // 4091541373
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_SwitchTower, "Server_SwitchTower" }, // 3244193479
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_ToggleTowers, "Server_ToggleTowers" }, // 1517511467
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_UpdateCharge, "Server_UpdateCharge" }, // 4062297299
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_UpdatePlayerInfoKills, "Server_UpdatePlayerInfoKills" }, // 274155441
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_UpdatePlayerInfoKillsInc, "Server_UpdatePlayerInfoKillsInc" }, // 3316097570
		{ &Z_Construct_UFunction_AMainCharacterTest_SetArrowDrawn, "SetArrowDrawn" }, // 3575965496
		{ &Z_Construct_UFunction_AMainCharacterTest_SetArrowFired, "SetArrowFired" }, // 3819814932
		{ &Z_Construct_UFunction_AMainCharacterTest_SetBaseHealth, "SetBaseHealth" }, // 2385082601
		{ &Z_Construct_UFunction_AMainCharacterTest_UpdateHealthWidget, "UpdateHealthWidget" }, // 3702287881
		{ &Z_Construct_UFunction_AMainCharacterTest_UpdatePlayerScoreUi, "UpdatePlayerScoreUi" }, // 2999621134
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMainCharacterTest>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TPSCameraComponent = { "TPSCameraComponent", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, TPSCameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TPSCameraComponent_MetaData), NewProp_TPSCameraComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_SpringArmComponent = { "SpringArmComponent", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, SpringArmComponent), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpringArmComponent_MetaData), NewProp_SpringArmComponent_MetaData) };
void Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowDrawn_SetBit(void* Obj)
{
	((AMainCharacterTest*)Obj)->ArrowDrawn = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowDrawn = { "ArrowDrawn", nullptr, (EPropertyFlags)0x0010000000020021, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMainCharacterTest), &Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowDrawn_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArrowDrawn_MetaData), NewProp_ArrowDrawn_MetaData) };
void Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowFired_SetBit(void* Obj)
{
	((AMainCharacterTest*)Obj)->ArrowFired = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowFired = { "ArrowFired", nullptr, (EPropertyFlags)0x0010000000020021, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMainCharacterTest), &Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowFired_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArrowFired_MetaData), NewProp_ArrowFired_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_MaxCharge = { "MaxCharge", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, MaxCharge), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxCharge_MetaData), NewProp_MaxCharge_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ChargeRate = { "ChargeRate", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, ChargeRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChargeRate_MetaData), NewProp_ChargeRate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_CurrentCharge = { "CurrentCharge", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, CurrentCharge), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentCharge_MetaData), NewProp_CurrentCharge_MetaData) };
void Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_isCharging_SetBit(void* Obj)
{
	((AMainCharacterTest*)Obj)->isCharging = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_isCharging = { "isCharging", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMainCharacterTest), &Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_isCharging_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_isCharging_MetaData), NewProp_isCharging_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ChargeFinal = { "ChargeFinal", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, ChargeFinal), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChargeFinal_MetaData), NewProp_ChargeFinal_MetaData) };
void Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_CanShoot_SetBit(void* Obj)
{
	((AMainCharacterTest*)Obj)->CanShoot = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_CanShoot = { "CanShoot", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMainCharacterTest), &Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_CanShoot_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CanShoot_MetaData), NewProp_CanShoot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_DefaultContext = { "DefaultContext", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, DefaultContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultContext_MetaData), NewProp_DefaultContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpAction_MetaData), NewProp_JumpAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookAction_MetaData), NewProp_LookAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TowerPlacementAction = { "TowerPlacementAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, TowerPlacementAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TowerPlacementAction_MetaData), NewProp_TowerPlacementAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_SwitchTowerAction = { "SwitchTowerAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, SwitchTowerAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SwitchTowerAction_MetaData), NewProp_SwitchTowerAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ToggleTowerPlacementAction = { "ToggleTowerPlacementAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, ToggleTowerPlacementAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToggleTowerPlacementAction_MetaData), NewProp_ToggleTowerPlacementAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ToggleLeaderboardAction = { "ToggleLeaderboardAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, ToggleLeaderboardAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToggleLeaderboardAction_MetaData), NewProp_ToggleLeaderboardAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ShootAction = { "ShootAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, ShootAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShootAction_MetaData), NewProp_ShootAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_DrawAction = { "DrawAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, DrawAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DrawAction_MetaData), NewProp_DrawAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_StopAimAction = { "StopAimAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, StopAimAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StopAimAction_MetaData), NewProp_StopAimAction_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowClass = { "ArrowClass", nullptr, (EPropertyFlags)0x0014000000010021, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, ArrowClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AMCArrow_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArrowClass_MetaData), NewProp_ArrowClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_BowPosition = { "BowPosition", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, BowPosition), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BowPosition_MetaData), NewProp_BowPosition_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_PlayerHUD = { "PlayerHUD", nullptr, (EPropertyFlags)0x0014000000010005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, PlayerHUD), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerHUD_MetaData), NewProp_PlayerHUD_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ChargeWidget = { "ChargeWidget", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, ChargeWidget), Z_Construct_UClass_UChargeWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChargeWidget_MetaData), NewProp_ChargeWidget_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ServerGameOverWidgetToCreate = { "ServerGameOverWidgetToCreate", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, ServerGameOverWidgetToCreate), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerGameOverWidgetToCreate_MetaData), NewProp_ServerGameOverWidgetToCreate_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ClientGameOverWidgetToCreate = { "ClientGameOverWidgetToCreate", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, ClientGameOverWidgetToCreate), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClientGameOverWidgetToCreate_MetaData), NewProp_ClientGameOverWidgetToCreate_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ServerGameOverWidget = { "ServerGameOverWidget", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, ServerGameOverWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerGameOverWidget_MetaData), NewProp_ServerGameOverWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ClientGameOverWidget = { "ClientGameOverWidget", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, ClientGameOverWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClientGameOverWidget_MetaData), NewProp_ClientGameOverWidget_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TowerTypesToSpawn_Inner = { "TowerTypesToSpawn", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_ATowerBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TowerTypesToSpawn = { "TowerTypesToSpawn", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, TowerTypesToSpawn), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TowerTypesToSpawn_MetaData), NewProp_TowerTypesToSpawn_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TowerPrePlacementObjectsToSpawn_Inner = { "TowerPrePlacementObjectsToSpawn", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_ATowePrePlaceObjectHelper_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TowerPrePlacementObjectsToSpawn = { "TowerPrePlacementObjectsToSpawn", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, TowerPrePlacementObjectsToSpawn), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TowerPrePlacementObjectsToSpawn_MetaData), NewProp_TowerPrePlacementObjectsToSpawn_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_PlayerPlacementDistances = { "PlayerPlacementDistances", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, PlayerPlacementDistances), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerPlacementDistances_MetaData), NewProp_PlayerPlacementDistances_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_PlayerRespawnPoint = { "PlayerRespawnPoint", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, PlayerRespawnPoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerRespawnPoint_MetaData), NewProp_PlayerRespawnPoint_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_PlayerKills = { "PlayerKills", nullptr, (EPropertyFlags)0x0020080000000020, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, PlayerKills), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerKills_MetaData), NewProp_PlayerKills_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_PlayerPoints = { "PlayerPoints", "UpdatePlayerScoreUi", (EPropertyFlags)0x0020080100000020, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, PlayerPoints), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerPoints_MetaData), NewProp_PlayerPoints_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_FiringSound = { "FiringSound", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, FiringSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FiringSound_MetaData), NewProp_FiringSound_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_DrawingSound = { "DrawingSound", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, DrawingSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DrawingSound_MetaData), NewProp_DrawingSound_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowImpact = { "ArrowImpact", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, ArrowImpact), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArrowImpact_MetaData), NewProp_ArrowImpact_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_PlayerId = { "PlayerId", nullptr, (EPropertyFlags)0x0020080000000020, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, PlayerId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerId_MetaData), NewProp_PlayerId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_StartingPoints = { "StartingPoints", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, StartingPoints), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartingPoints_MetaData), NewProp_StartingPoints_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_SelectedTowerIndex = { "SelectedTowerIndex", nullptr, (EPropertyFlags)0x0040000000000020, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, SelectedTowerIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedTowerIndex_MetaData), NewProp_SelectedTowerIndex_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_Health = { "Health", "UpdateHealthWidget", (EPropertyFlags)0x0040000100000020, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, Health), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Health_MetaData), NewProp_Health_MetaData) };
void Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_IsPlacingTower_SetBit(void* Obj)
{
	((AMainCharacterTest*)Obj)->IsPlacingTower = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_IsPlacingTower = { "IsPlacingTower", nullptr, (EPropertyFlags)0x0040000000000020, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMainCharacterTest), &Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_IsPlacingTower_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsPlacingTower_MetaData), NewProp_IsPlacingTower_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMainCharacterTest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TPSCameraComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_SpringArmComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowDrawn,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowFired,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_MaxCharge,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ChargeRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_CurrentCharge,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_isCharging,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ChargeFinal,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_CanShoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_DefaultContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_JumpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_LookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TowerPlacementAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_SwitchTowerAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ToggleTowerPlacementAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ToggleLeaderboardAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ShootAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_DrawAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_StopAimAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_BowPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_PlayerHUD,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ChargeWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ServerGameOverWidgetToCreate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ClientGameOverWidgetToCreate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ServerGameOverWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ClientGameOverWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TowerTypesToSpawn_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TowerTypesToSpawn,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TowerPrePlacementObjectsToSpawn_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TowerPrePlacementObjectsToSpawn,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_PlayerPlacementDistances,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_PlayerRespawnPoint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_PlayerKills,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_PlayerPoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_FiringSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_DrawingSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowImpact,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_PlayerId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_StartingPoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_SelectedTowerIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_Health,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_IsPlacingTower,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMainCharacterTest_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMainCharacterTest_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_SiegeSmasher,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMainCharacterTest_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMainCharacterTest_Statics::ClassParams = {
	&AMainCharacterTest::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AMainCharacterTest_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AMainCharacterTest_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMainCharacterTest_Statics::Class_MetaDataParams), Z_Construct_UClass_AMainCharacterTest_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMainCharacterTest()
{
	if (!Z_Registration_Info_UClass_AMainCharacterTest.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMainCharacterTest.OuterSingleton, Z_Construct_UClass_AMainCharacterTest_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMainCharacterTest.OuterSingleton;
}
template<> SIEGESMASHER_API UClass* StaticClass<AMainCharacterTest>()
{
	return AMainCharacterTest::StaticClass();
}
void AMainCharacterTest::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static const FName Name_ArrowDrawn(TEXT("ArrowDrawn"));
	static const FName Name_ArrowFired(TEXT("ArrowFired"));
	static const FName Name_MaxCharge(TEXT("MaxCharge"));
	static const FName Name_ChargeRate(TEXT("ChargeRate"));
	static const FName Name_CurrentCharge(TEXT("CurrentCharge"));
	static const FName Name_isCharging(TEXT("isCharging"));
	static const FName Name_ChargeFinal(TEXT("ChargeFinal"));
	static const FName Name_ArrowClass(TEXT("ArrowClass"));
	static const FName Name_PlayerKills(TEXT("PlayerKills"));
	static const FName Name_PlayerPoints(TEXT("PlayerPoints"));
	static const FName Name_PlayerId(TEXT("PlayerId"));
	static const FName Name_SelectedTowerIndex(TEXT("SelectedTowerIndex"));
	static const FName Name_Health(TEXT("Health"));
	static const FName Name_IsPlacingTower(TEXT("IsPlacingTower"));
	const bool bIsValid = true
		&& Name_ArrowDrawn == ClassReps[(int32)ENetFields_Private::ArrowDrawn].Property->GetFName()
		&& Name_ArrowFired == ClassReps[(int32)ENetFields_Private::ArrowFired].Property->GetFName()
		&& Name_MaxCharge == ClassReps[(int32)ENetFields_Private::MaxCharge].Property->GetFName()
		&& Name_ChargeRate == ClassReps[(int32)ENetFields_Private::ChargeRate].Property->GetFName()
		&& Name_CurrentCharge == ClassReps[(int32)ENetFields_Private::CurrentCharge].Property->GetFName()
		&& Name_isCharging == ClassReps[(int32)ENetFields_Private::isCharging].Property->GetFName()
		&& Name_ChargeFinal == ClassReps[(int32)ENetFields_Private::ChargeFinal].Property->GetFName()
		&& Name_ArrowClass == ClassReps[(int32)ENetFields_Private::ArrowClass].Property->GetFName()
		&& Name_PlayerKills == ClassReps[(int32)ENetFields_Private::PlayerKills].Property->GetFName()
		&& Name_PlayerPoints == ClassReps[(int32)ENetFields_Private::PlayerPoints].Property->GetFName()
		&& Name_PlayerId == ClassReps[(int32)ENetFields_Private::PlayerId].Property->GetFName()
		&& Name_SelectedTowerIndex == ClassReps[(int32)ENetFields_Private::SelectedTowerIndex].Property->GetFName()
		&& Name_Health == ClassReps[(int32)ENetFields_Private::Health].Property->GetFName()
		&& Name_IsPlacingTower == ClassReps[(int32)ENetFields_Private::IsPlacingTower].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AMainCharacterTest"));
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMainCharacterTest);
AMainCharacterTest::~AMainCharacterTest() {}
// End Class AMainCharacterTest

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_richa_OneDrive_Desktop_SiegeSmasher_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMainCharacterTest, AMainCharacterTest::StaticClass, TEXT("AMainCharacterTest"), &Z_Registration_Info_UClass_AMainCharacterTest, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMainCharacterTest), 3431297961U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_richa_OneDrive_Desktop_SiegeSmasher_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_3870788195(TEXT("/Script/SiegeSmasher"),
	Z_CompiledInDeferFile_FID_Users_richa_OneDrive_Desktop_SiegeSmasher_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_richa_OneDrive_Desktop_SiegeSmasher_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
