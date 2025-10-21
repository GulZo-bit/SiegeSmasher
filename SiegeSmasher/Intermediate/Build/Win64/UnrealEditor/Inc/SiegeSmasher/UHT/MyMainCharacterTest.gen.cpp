// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SiegeSmasher/MyMainCharacterTest.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyMainCharacterTest() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
SIEGESMASHER_API UClass* Z_Construct_UClass_AMainCharacterTest();
SIEGESMASHER_API UClass* Z_Construct_UClass_AMainCharacterTest_NoRegister();
SIEGESMASHER_API UClass* Z_Construct_UClass_APlayerArrow_NoRegister();
SIEGESMASHER_API UClass* Z_Construct_UClass_UChargeWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
UPackage* Z_Construct_UPackage__Script_SiegeSmasher();
// End Cross Module References

// Begin Class AMainCharacterTest Function GetArrowDrawn
struct Z_Construct_UFunction_AMainCharacterTest_GetArrowDrawn_Statics
{
	struct MainCharacterTest_eventGetArrowDrawn_Parms
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
		{ "GetArrowDrawn", &AMainCharacterTest::execGetArrowDrawn },
		{ "GetArrowFired", &AMainCharacterTest::execGetArrowFired },
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
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArrowFired_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxCharge_MetaData[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
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
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StopAimAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BowOffset_MetaData[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Offset of the bow from the camera\n" },
#endif
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Offset of the bow from the camera" },
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
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerHUD_MetaData[] = {
		{ "Category", "Charge" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChargeWidget_MetaData[] = {
		{ "EditInline", "true" },
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
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ShootAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DrawAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StopAimAction;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BowOffset;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ArrowClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BowPosition;
	static const UECodeGen_Private::FClassPropertyParams NewProp_PlayerHUD;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ChargeWidget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMainCharacterTest_GetArrowDrawn, "GetArrowDrawn" }, // 2630938728
		{ &Z_Construct_UFunction_AMainCharacterTest_GetArrowFired, "GetArrowFired" }, // 1961892374
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
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowDrawn = { "ArrowDrawn", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMainCharacterTest), &Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowDrawn_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArrowDrawn_MetaData), NewProp_ArrowDrawn_MetaData) };
void Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowFired_SetBit(void* Obj)
{
	((AMainCharacterTest*)Obj)->ArrowFired = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowFired = { "ArrowFired", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMainCharacterTest), &Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowFired_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArrowFired_MetaData), NewProp_ArrowFired_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_MaxCharge = { "MaxCharge", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, MaxCharge), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxCharge_MetaData), NewProp_MaxCharge_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ChargeRate = { "ChargeRate", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, ChargeRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChargeRate_MetaData), NewProp_ChargeRate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_CurrentCharge = { "CurrentCharge", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, CurrentCharge), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentCharge_MetaData), NewProp_CurrentCharge_MetaData) };
void Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_isCharging_SetBit(void* Obj)
{
	((AMainCharacterTest*)Obj)->isCharging = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_isCharging = { "isCharging", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMainCharacterTest), &Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_isCharging_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_isCharging_MetaData), NewProp_isCharging_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_DefaultContext = { "DefaultContext", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, DefaultContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultContext_MetaData), NewProp_DefaultContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpAction_MetaData), NewProp_JumpAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookAction_MetaData), NewProp_LookAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ShootAction = { "ShootAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, ShootAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShootAction_MetaData), NewProp_ShootAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_DrawAction = { "DrawAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, DrawAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DrawAction_MetaData), NewProp_DrawAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_StopAimAction = { "StopAimAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, StopAimAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StopAimAction_MetaData), NewProp_StopAimAction_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_BowOffset = { "BowOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, BowOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BowOffset_MetaData), NewProp_BowOffset_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowClass = { "ArrowClass", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, ArrowClass), Z_Construct_UClass_UClass, Z_Construct_UClass_APlayerArrow_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArrowClass_MetaData), NewProp_ArrowClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_BowPosition = { "BowPosition", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, BowPosition), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BowPosition_MetaData), NewProp_BowPosition_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_PlayerHUD = { "PlayerHUD", nullptr, (EPropertyFlags)0x0014000000010005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, PlayerHUD), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerHUD_MetaData), NewProp_PlayerHUD_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ChargeWidget = { "ChargeWidget", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, ChargeWidget), Z_Construct_UClass_UChargeWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChargeWidget_MetaData), NewProp_ChargeWidget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMainCharacterTest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TPSCameraComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_SpringArmComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowDrawn,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowFired,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_MaxCharge,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ChargeRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_CurrentCharge,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_isCharging,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_DefaultContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_JumpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_LookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ShootAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_DrawAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_StopAimAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_BowOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_BowPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_PlayerHUD,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ChargeWidget,
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
DEFINE_VTABLE_PTR_HELPER_CTOR(AMainCharacterTest);
AMainCharacterTest::~AMainCharacterTest() {}
// End Class AMainCharacterTest

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_kewin_Desktop_C__Unreal_Engine_Assigment_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMainCharacterTest, AMainCharacterTest::StaticClass, TEXT("AMainCharacterTest"), &Z_Registration_Info_UClass_AMainCharacterTest, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMainCharacterTest), 557571865U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_kewin_Desktop_C__Unreal_Engine_Assigment_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_615193467(TEXT("/Script/SiegeSmasher"),
	Z_CompiledInDeferFile_FID_Users_kewin_Desktop_C__Unreal_Engine_Assigment_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_kewin_Desktop_C__Unreal_Engine_Assigment_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
