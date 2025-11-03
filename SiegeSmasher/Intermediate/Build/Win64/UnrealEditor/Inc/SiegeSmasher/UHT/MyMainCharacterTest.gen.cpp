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
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
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

// Begin Class AMainCharacterTest Function Multi_SpawnProjectile
struct MainCharacterTest_eventMulti_SpawnProjectile_Parms
{
	FRotator CamRotation;
	FRotator BowRot;
};
static const FName NAME_AMainCharacterTest_Multi_SpawnProjectile = FName(TEXT("Multi_SpawnProjectile"));
void AMainCharacterTest::Multi_SpawnProjectile(FRotator CamRotation, FRotator BowRot)
{
	MainCharacterTest_eventMulti_SpawnProjectile_Parms Parms;
	Parms.CamRotation=CamRotation;
	Parms.BowRot=BowRot;
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Multi_SpawnProjectile);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMainCharacterTest_Multi_SpawnProjectile_Statics
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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMainCharacterTest_Multi_SpawnProjectile_Statics::NewProp_CamRotation = { "CamRotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventMulti_SpawnProjectile_Parms, CamRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMainCharacterTest_Multi_SpawnProjectile_Statics::NewProp_BowRot = { "BowRot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventMulti_SpawnProjectile_Parms, BowRot), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_Multi_SpawnProjectile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Multi_SpawnProjectile_Statics::NewProp_CamRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Multi_SpawnProjectile_Statics::NewProp_BowRot,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Multi_SpawnProjectile_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Multi_SpawnProjectile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Multi_SpawnProjectile", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_Multi_SpawnProjectile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Multi_SpawnProjectile_Statics::PropPointers), sizeof(MainCharacterTest_eventMulti_SpawnProjectile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80824CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Multi_SpawnProjectile_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Multi_SpawnProjectile_Statics::Function_MetaDataParams) };
static_assert(sizeof(MainCharacterTest_eventMulti_SpawnProjectile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_Multi_SpawnProjectile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Multi_SpawnProjectile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execMulti_SpawnProjectile)
{
	P_GET_STRUCT(FRotator,Z_Param_CamRotation);
	P_GET_STRUCT(FRotator,Z_Param_BowRot);
	P_FINISH;
	P_NATIVE_BEGIN;
	if (!P_THIS->Multi_SpawnProjectile_Validate(Z_Param_CamRotation,Z_Param_BowRot))
	{
		RPC_ValidateFailed(TEXT("Multi_SpawnProjectile_Validate"));
		return;
	}
	P_THIS->Multi_SpawnProjectile_Implementation(Z_Param_CamRotation,Z_Param_BowRot);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Multi_SpawnProjectile

// Begin Class AMainCharacterTest Function Multi_UpdateCharge
static const FName NAME_AMainCharacterTest_Multi_UpdateCharge = FName(TEXT("Multi_UpdateCharge"));
void AMainCharacterTest::Multi_UpdateCharge()
{
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Multi_UpdateCharge);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_AMainCharacterTest_Multi_UpdateCharge_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Multi_UpdateCharge_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Multi_UpdateCharge", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80024CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Multi_UpdateCharge_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Multi_UpdateCharge_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMainCharacterTest_Multi_UpdateCharge()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Multi_UpdateCharge_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execMulti_UpdateCharge)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	if (!P_THIS->Multi_UpdateCharge_Validate())
	{
		RPC_ValidateFailed(TEXT("Multi_UpdateCharge_Validate"));
		return;
	}
	P_THIS->Multi_UpdateCharge_Implementation();
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Multi_UpdateCharge

// Begin Class AMainCharacterTest Function Multicast_HandleTowerPlacement
struct MainCharacterTest_eventMulticast_HandleTowerPlacement_Parms
{
	FVector CamForward;
	FVector CamPosition;
};
static const FName NAME_AMainCharacterTest_Multicast_HandleTowerPlacement = FName(TEXT("Multicast_HandleTowerPlacement"));
void AMainCharacterTest::Multicast_HandleTowerPlacement(FVector CamForward, FVector CamPosition)
{
	MainCharacterTest_eventMulticast_HandleTowerPlacement_Parms Parms;
	Parms.CamForward=CamForward;
	Parms.CamPosition=CamPosition;
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Multicast_HandleTowerPlacement);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMainCharacterTest_Multicast_HandleTowerPlacement_Statics
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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMainCharacterTest_Multicast_HandleTowerPlacement_Statics::NewProp_CamForward = { "CamForward", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventMulticast_HandleTowerPlacement_Parms, CamForward), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMainCharacterTest_Multicast_HandleTowerPlacement_Statics::NewProp_CamPosition = { "CamPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventMulticast_HandleTowerPlacement_Parms, CamPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_Multicast_HandleTowerPlacement_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Multicast_HandleTowerPlacement_Statics::NewProp_CamForward,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Multicast_HandleTowerPlacement_Statics::NewProp_CamPosition,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Multicast_HandleTowerPlacement_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Multicast_HandleTowerPlacement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Multicast_HandleTowerPlacement", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_Multicast_HandleTowerPlacement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Multicast_HandleTowerPlacement_Statics::PropPointers), sizeof(MainCharacterTest_eventMulticast_HandleTowerPlacement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00824CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Multicast_HandleTowerPlacement_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Multicast_HandleTowerPlacement_Statics::Function_MetaDataParams) };
static_assert(sizeof(MainCharacterTest_eventMulticast_HandleTowerPlacement_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_Multicast_HandleTowerPlacement()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Multicast_HandleTowerPlacement_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execMulticast_HandleTowerPlacement)
{
	P_GET_STRUCT(FVector,Z_Param_CamForward);
	P_GET_STRUCT(FVector,Z_Param_CamPosition);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Multicast_HandleTowerPlacement_Implementation(Z_Param_CamForward,Z_Param_CamPosition);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Multicast_HandleTowerPlacement

// Begin Class AMainCharacterTest Function Multicast_SetPlayerId
struct MainCharacterTest_eventMulticast_SetPlayerId_Parms
{
	int32 Id;
};
static const FName NAME_AMainCharacterTest_Multicast_SetPlayerId = FName(TEXT("Multicast_SetPlayerId"));
void AMainCharacterTest::Multicast_SetPlayerId(int32 Id)
{
	MainCharacterTest_eventMulticast_SetPlayerId_Parms Parms;
	Parms.Id=Id;
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Multicast_SetPlayerId);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerId_Statics
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
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerId_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventMulticast_SetPlayerId_Parms, Id), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerId_Statics::NewProp_Id,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Multicast_SetPlayerId", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerId_Statics::PropPointers), sizeof(MainCharacterTest_eventMulticast_SetPlayerId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00024CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerId_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerId_Statics::Function_MetaDataParams) };
static_assert(sizeof(MainCharacterTest_eventMulticast_SetPlayerId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execMulticast_SetPlayerId)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Id);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Multicast_SetPlayerId_Implementation(Z_Param_Id);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Multicast_SetPlayerId

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

// Begin Class AMainCharacterTest Function Server_SetPlayerId
struct MainCharacterTest_eventServer_SetPlayerId_Parms
{
	int32 Id;
};
static const FName NAME_AMainCharacterTest_Server_SetPlayerId = FName(TEXT("Server_SetPlayerId"));
void AMainCharacterTest::Server_SetPlayerId(int32 Id)
{
	MainCharacterTest_eventServer_SetPlayerId_Parms Parms;
	Parms.Id=Id;
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Server_SetPlayerId);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerId_Statics
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
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerId_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventServer_SetPlayerId_Parms, Id), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerId_Statics::NewProp_Id,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Server_SetPlayerId", nullptr, nullptr, Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerId_Statics::PropPointers), sizeof(MainCharacterTest_eventServer_SetPlayerId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerId_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerId_Statics::Function_MetaDataParams) };
static_assert(sizeof(MainCharacterTest_eventServer_SetPlayerId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainCharacterTest::execServer_SetPlayerId)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Id);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_SetPlayerId_Implementation(Z_Param_Id);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Server_SetPlayerId

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
static const FName NAME_AMainCharacterTest_Server_SpawnSelected = FName(TEXT("Server_SpawnSelected"));
void AMainCharacterTest::Server_SpawnSelected()
{
	UFunction* Func = FindFunctionChecked(NAME_AMainCharacterTest_Server_SpawnSelected);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_AMainCharacterTest_Server_SpawnSelected_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainCharacterTest_Server_SpawnSelected_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainCharacterTest, nullptr, "Server_SpawnSelected", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainCharacterTest_Server_SpawnSelected_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainCharacterTest_Server_SpawnSelected_Statics::Function_MetaDataParams) };
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
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_SpawnSelected_Implementation();
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
};
static const FName NAME_AMainCharacterTest_Server_SwitchTower = FName(TEXT("Server_SwitchTower"));
void AMainCharacterTest::Server_SwitchTower(int32 SelectedIndex)
{
	MainCharacterTest_eventServer_SwitchTower_Parms Parms;
	Parms.SelectedIndex=SelectedIndex;
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
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMainCharacterTest_Server_SwitchTower_Statics::NewProp_SelectedIndex = { "SelectedIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainCharacterTest_eventServer_SwitchTower_Parms, SelectedIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainCharacterTest_Server_SwitchTower_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainCharacterTest_Server_SwitchTower_Statics::NewProp_SelectedIndex,
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
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_SwitchTower_Implementation(Z_Param_SelectedIndex);
	P_NATIVE_END;
}
// End Class AMainCharacterTest Function Server_SwitchTower

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

// Begin Class AMainCharacterTest
void AMainCharacterTest::StaticRegisterNativesAMainCharacterTest()
{
	UClass* Class = AMainCharacterTest::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CallClientTravel", &AMainCharacterTest::execCallClientTravel },
		{ "CallCreateLobby", &AMainCharacterTest::execCallCreateLobby },
		{ "GetArrowDrawn", &AMainCharacterTest::execGetArrowDrawn },
		{ "GetArrowFired", &AMainCharacterTest::execGetArrowFired },
		{ "GetCurrentCharge", &AMainCharacterTest::execGetCurrentCharge },
		{ "Multi_SpawnProjectile", &AMainCharacterTest::execMulti_SpawnProjectile },
		{ "Multi_UpdateCharge", &AMainCharacterTest::execMulti_UpdateCharge },
		{ "Multicast_HandleTowerPlacement", &AMainCharacterTest::execMulticast_HandleTowerPlacement },
		{ "Multicast_SetPlayerId", &AMainCharacterTest::execMulticast_SetPlayerId },
		{ "Multicast_SetPlayerOwnerShip", &AMainCharacterTest::execMulticast_SetPlayerOwnerShip },
		{ "Server_ChargeShot", &AMainCharacterTest::execServer_ChargeShot },
		{ "Server_DrawBow", &AMainCharacterTest::execServer_DrawBow },
		{ "Server_HandleTowerPlacement", &AMainCharacterTest::execServer_HandleTowerPlacement },
		{ "Server_SetPlayerId", &AMainCharacterTest::execServer_SetPlayerId },
		{ "Server_SetPlayerOwnerShip", &AMainCharacterTest::execServer_SetPlayerOwnerShip },
		{ "Server_SpawnProjectile", &AMainCharacterTest::execServer_SpawnProjectile },
		{ "Server_SpawnSelected", &AMainCharacterTest::execServer_SpawnSelected },
		{ "Server_StopAim", &AMainCharacterTest::execServer_StopAim },
		{ "Server_SwitchTower", &AMainCharacterTest::execServer_SwitchTower },
		{ "Server_UpdateCharge", &AMainCharacterTest::execServer_UpdateCharge },
		{ "SetArrowDrawn", &AMainCharacterTest::execSetArrowDrawn },
		{ "SetArrowFired", &AMainCharacterTest::execSetArrowFired },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Selected_MetaData[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedTowerIndex_MetaData[] = {
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
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TowerPlacementAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SwitchTowerAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ShootAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DrawAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StopAimAction;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ArrowClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BowPosition;
	static const UECodeGen_Private::FClassPropertyParams NewProp_PlayerHUD;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ChargeWidget;
	static const UECodeGen_Private::FClassPropertyParams NewProp_TowerTypesToSpawn_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_TowerTypesToSpawn;
	static const UECodeGen_Private::FClassPropertyParams NewProp_TowerPrePlacementObjectsToSpawn_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_TowerPrePlacementObjectsToSpawn;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PlayerPlacementDistances;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Selected;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SelectedTowerIndex;
	static void NewProp_IsPlacingTower_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsPlacingTower;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMainCharacterTest_CallClientTravel, "CallClientTravel" }, // 60708357
		{ &Z_Construct_UFunction_AMainCharacterTest_CallCreateLobby, "CallCreateLobby" }, // 2808711649
		{ &Z_Construct_UFunction_AMainCharacterTest_GetArrowDrawn, "GetArrowDrawn" }, // 3054430967
		{ &Z_Construct_UFunction_AMainCharacterTest_GetArrowFired, "GetArrowFired" }, // 1961892374
		{ &Z_Construct_UFunction_AMainCharacterTest_GetCurrentCharge, "GetCurrentCharge" }, // 2381322748
		{ &Z_Construct_UFunction_AMainCharacterTest_Multi_SpawnProjectile, "Multi_SpawnProjectile" }, // 1735609979
		{ &Z_Construct_UFunction_AMainCharacterTest_Multi_UpdateCharge, "Multi_UpdateCharge" }, // 1037512913
		{ &Z_Construct_UFunction_AMainCharacterTest_Multicast_HandleTowerPlacement, "Multicast_HandleTowerPlacement" }, // 1903970403
		{ &Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerId, "Multicast_SetPlayerId" }, // 2722036901
		{ &Z_Construct_UFunction_AMainCharacterTest_Multicast_SetPlayerOwnerShip, "Multicast_SetPlayerOwnerShip" }, // 2508787000
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_ChargeShot, "Server_ChargeShot" }, // 2527664862
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_DrawBow, "Server_DrawBow" }, // 2904301876
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_HandleTowerPlacement, "Server_HandleTowerPlacement" }, // 1548410931
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerId, "Server_SetPlayerId" }, // 636525269
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_SetPlayerOwnerShip, "Server_SetPlayerOwnerShip" }, // 1835589500
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_SpawnProjectile, "Server_SpawnProjectile" }, // 3106002752
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_SpawnSelected, "Server_SpawnSelected" }, // 2173040193
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_StopAim, "Server_StopAim" }, // 4091541373
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_SwitchTower, "Server_SwitchTower" }, // 2617035848
		{ &Z_Construct_UFunction_AMainCharacterTest_Server_UpdateCharge, "Server_UpdateCharge" }, // 4062297299
		{ &Z_Construct_UFunction_AMainCharacterTest_SetArrowDrawn, "SetArrowDrawn" }, // 3575965496
		{ &Z_Construct_UFunction_AMainCharacterTest_SetArrowFired, "SetArrowFired" }, // 3819814932
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
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_DefaultContext = { "DefaultContext", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, DefaultContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultContext_MetaData), NewProp_DefaultContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpAction_MetaData), NewProp_JumpAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookAction_MetaData), NewProp_LookAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TowerPlacementAction = { "TowerPlacementAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, TowerPlacementAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TowerPlacementAction_MetaData), NewProp_TowerPlacementAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_SwitchTowerAction = { "SwitchTowerAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, SwitchTowerAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SwitchTowerAction_MetaData), NewProp_SwitchTowerAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ShootAction = { "ShootAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, ShootAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShootAction_MetaData), NewProp_ShootAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_DrawAction = { "DrawAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, DrawAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DrawAction_MetaData), NewProp_DrawAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_StopAimAction = { "StopAimAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, StopAimAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StopAimAction_MetaData), NewProp_StopAimAction_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowClass = { "ArrowClass", nullptr, (EPropertyFlags)0x0014000000010021, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, ArrowClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AMCArrow_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArrowClass_MetaData), NewProp_ArrowClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_BowPosition = { "BowPosition", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, BowPosition), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BowPosition_MetaData), NewProp_BowPosition_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_PlayerHUD = { "PlayerHUD", nullptr, (EPropertyFlags)0x0014000000010005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, PlayerHUD), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerHUD_MetaData), NewProp_PlayerHUD_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ChargeWidget = { "ChargeWidget", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, ChargeWidget), Z_Construct_UClass_UChargeWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChargeWidget_MetaData), NewProp_ChargeWidget_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TowerTypesToSpawn_Inner = { "TowerTypesToSpawn", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_ATowerBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TowerTypesToSpawn = { "TowerTypesToSpawn", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, TowerTypesToSpawn), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TowerTypesToSpawn_MetaData), NewProp_TowerTypesToSpawn_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TowerPrePlacementObjectsToSpawn_Inner = { "TowerPrePlacementObjectsToSpawn", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_ATowePrePlaceObjectHelper_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TowerPrePlacementObjectsToSpawn = { "TowerPrePlacementObjectsToSpawn", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, TowerPrePlacementObjectsToSpawn), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TowerPrePlacementObjectsToSpawn_MetaData), NewProp_TowerPrePlacementObjectsToSpawn_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_PlayerPlacementDistances = { "PlayerPlacementDistances", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, PlayerPlacementDistances), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerPlacementDistances_MetaData), NewProp_PlayerPlacementDistances_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_Selected = { "Selected", nullptr, (EPropertyFlags)0x0040000000000020, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, Selected), Z_Construct_UClass_ATowePrePlaceObjectHelper_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Selected_MetaData), NewProp_Selected_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_SelectedTowerIndex = { "SelectedTowerIndex", nullptr, (EPropertyFlags)0x0040000000000020, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, SelectedTowerIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedTowerIndex_MetaData), NewProp_SelectedTowerIndex_MetaData) };
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
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_DefaultContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_JumpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_LookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TowerPlacementAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_SwitchTowerAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ShootAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_DrawAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_StopAimAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_BowPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_PlayerHUD,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ChargeWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TowerTypesToSpawn_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TowerTypesToSpawn,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TowerPrePlacementObjectsToSpawn_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TowerPrePlacementObjectsToSpawn,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_PlayerPlacementDistances,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_Selected,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_SelectedTowerIndex,
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
	static const FName Name_Selected(TEXT("Selected"));
	static const FName Name_SelectedTowerIndex(TEXT("SelectedTowerIndex"));
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
		&& Name_Selected == ClassReps[(int32)ENetFields_Private::Selected].Property->GetFName()
		&& Name_SelectedTowerIndex == ClassReps[(int32)ENetFields_Private::SelectedTowerIndex].Property->GetFName()
		&& Name_IsPlacingTower == ClassReps[(int32)ENetFields_Private::IsPlacingTower].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AMainCharacterTest"));
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMainCharacterTest);
AMainCharacterTest::~AMainCharacterTest() {}
// End Class AMainCharacterTest

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMainCharacterTest, AMainCharacterTest::StaticClass, TEXT("AMainCharacterTest"), &Z_Registration_Info_UClass_AMainCharacterTest, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMainCharacterTest), 1594706331U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_707529575(TEXT("/Script/SiegeSmasher"),
	Z_CompiledInDeferFile_FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
