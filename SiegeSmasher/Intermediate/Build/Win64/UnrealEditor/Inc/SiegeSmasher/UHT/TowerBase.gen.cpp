// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SiegeSmasher/Towers/TowerBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTowerBase() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
SIEGESMASHER_API UClass* Z_Construct_UClass_ATowerBase();
SIEGESMASHER_API UClass* Z_Construct_UClass_ATowerBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_SiegeSmasher();
// End Cross Module References

// Begin Class ATowerBase Function GetPlacementColliderHalfExtents
struct Z_Construct_UFunction_ATowerBase_GetPlacementColliderHalfExtents_Statics
{
	struct TowerBase_eventGetPlacementColliderHalfExtents_Parms
	{
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "PlacementCollisionResolution" },
		{ "ModuleRelativePath", "Towers/TowerBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATowerBase_GetPlacementColliderHalfExtents_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TowerBase_eventGetPlacementColliderHalfExtents_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATowerBase_GetPlacementColliderHalfExtents_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATowerBase_GetPlacementColliderHalfExtents_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATowerBase_GetPlacementColliderHalfExtents_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATowerBase_GetPlacementColliderHalfExtents_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATowerBase, nullptr, "GetPlacementColliderHalfExtents", nullptr, nullptr, Z_Construct_UFunction_ATowerBase_GetPlacementColliderHalfExtents_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATowerBase_GetPlacementColliderHalfExtents_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATowerBase_GetPlacementColliderHalfExtents_Statics::TowerBase_eventGetPlacementColliderHalfExtents_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATowerBase_GetPlacementColliderHalfExtents_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATowerBase_GetPlacementColliderHalfExtents_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ATowerBase_GetPlacementColliderHalfExtents_Statics::TowerBase_eventGetPlacementColliderHalfExtents_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATowerBase_GetPlacementColliderHalfExtents()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATowerBase_GetPlacementColliderHalfExtents_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATowerBase::execGetPlacementColliderHalfExtents)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->GetPlacementColliderHalfExtents();
	P_NATIVE_END;
}
// End Class ATowerBase Function GetPlacementColliderHalfExtents

// Begin Class ATowerBase Function ResolvePlacement
struct Z_Construct_UFunction_ATowerBase_ResolvePlacement_Statics
{
	struct TowerBase_eventResolvePlacement_Parms
	{
		FVector SurfaceHalfExtents;
		FVector SurfacePos;
		FVector PlacementPosition;
		FVector CamDir;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "PlacementCollisionResolution" },
		{ "ModuleRelativePath", "Towers/TowerBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_SurfaceHalfExtents;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SurfacePos;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PlacementPosition;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CamDir;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATowerBase_ResolvePlacement_Statics::NewProp_SurfaceHalfExtents = { "SurfaceHalfExtents", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TowerBase_eventResolvePlacement_Parms, SurfaceHalfExtents), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATowerBase_ResolvePlacement_Statics::NewProp_SurfacePos = { "SurfacePos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TowerBase_eventResolvePlacement_Parms, SurfacePos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATowerBase_ResolvePlacement_Statics::NewProp_PlacementPosition = { "PlacementPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TowerBase_eventResolvePlacement_Parms, PlacementPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATowerBase_ResolvePlacement_Statics::NewProp_CamDir = { "CamDir", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TowerBase_eventResolvePlacement_Parms, CamDir), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATowerBase_ResolvePlacement_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATowerBase_ResolvePlacement_Statics::NewProp_SurfaceHalfExtents,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATowerBase_ResolvePlacement_Statics::NewProp_SurfacePos,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATowerBase_ResolvePlacement_Statics::NewProp_PlacementPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATowerBase_ResolvePlacement_Statics::NewProp_CamDir,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATowerBase_ResolvePlacement_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATowerBase_ResolvePlacement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATowerBase, nullptr, "ResolvePlacement", nullptr, nullptr, Z_Construct_UFunction_ATowerBase_ResolvePlacement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATowerBase_ResolvePlacement_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATowerBase_ResolvePlacement_Statics::TowerBase_eventResolvePlacement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATowerBase_ResolvePlacement_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATowerBase_ResolvePlacement_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ATowerBase_ResolvePlacement_Statics::TowerBase_eventResolvePlacement_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATowerBase_ResolvePlacement()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATowerBase_ResolvePlacement_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATowerBase::execResolvePlacement)
{
	P_GET_STRUCT(FVector,Z_Param_SurfaceHalfExtents);
	P_GET_STRUCT(FVector,Z_Param_SurfacePos);
	P_GET_STRUCT(FVector,Z_Param_PlacementPosition);
	P_GET_STRUCT(FVector,Z_Param_CamDir);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResolvePlacement(Z_Param_SurfaceHalfExtents,Z_Param_SurfacePos,Z_Param_PlacementPosition,Z_Param_CamDir);
	P_NATIVE_END;
}
// End Class ATowerBase Function ResolvePlacement

// Begin Class ATowerBase
void ATowerBase::StaticRegisterNativesATowerBase()
{
	UClass* Class = ATowerBase::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetPlacementColliderHalfExtents", &ATowerBase::execGetPlacementColliderHalfExtents },
		{ "ResolvePlacement", &ATowerBase::execResolvePlacement },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATowerBase);
UClass* Z_Construct_UClass_ATowerBase_NoRegister()
{
	return ATowerBase::StaticClass();
}
struct Z_Construct_UClass_ATowerBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Towers/TowerBase.h" },
		{ "ModuleRelativePath", "Towers/TowerBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StaticMeshForTower_MetaData[] = {
		{ "Category", "StaticMeshForTower" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Towers/TowerBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoxColliderForObjectPlacement_MetaData[] = {
		{ "Category", "PlacementCollider" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Towers/TowerBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StaticMeshForTower;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BoxColliderForObjectPlacement;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ATowerBase_GetPlacementColliderHalfExtents, "GetPlacementColliderHalfExtents" }, // 3032848210
		{ &Z_Construct_UFunction_ATowerBase_ResolvePlacement, "ResolvePlacement" }, // 3319743703
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATowerBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATowerBase_Statics::NewProp_StaticMeshForTower = { "StaticMeshForTower", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATowerBase, StaticMeshForTower), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StaticMeshForTower_MetaData), NewProp_StaticMeshForTower_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATowerBase_Statics::NewProp_BoxColliderForObjectPlacement = { "BoxColliderForObjectPlacement", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATowerBase, BoxColliderForObjectPlacement), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoxColliderForObjectPlacement_MetaData), NewProp_BoxColliderForObjectPlacement_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATowerBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATowerBase_Statics::NewProp_StaticMeshForTower,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATowerBase_Statics::NewProp_BoxColliderForObjectPlacement,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATowerBase_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ATowerBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_SiegeSmasher,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATowerBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATowerBase_Statics::ClassParams = {
	&ATowerBase::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ATowerBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ATowerBase_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATowerBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ATowerBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ATowerBase()
{
	if (!Z_Registration_Info_UClass_ATowerBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATowerBase.OuterSingleton, Z_Construct_UClass_ATowerBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATowerBase.OuterSingleton;
}
template<> SIEGESMASHER_API UClass* StaticClass<ATowerBase>()
{
	return ATowerBase::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ATowerBase);
ATowerBase::~ATowerBase() {}
// End Class ATowerBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_richa_OneDrive_Desktop_SiegeSmasher_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Towers_TowerBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATowerBase, ATowerBase::StaticClass, TEXT("ATowerBase"), &Z_Registration_Info_UClass_ATowerBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATowerBase), 4127482009U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_richa_OneDrive_Desktop_SiegeSmasher_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Towers_TowerBase_h_3642443673(TEXT("/Script/SiegeSmasher"),
	Z_CompiledInDeferFile_FID_Users_richa_OneDrive_Desktop_SiegeSmasher_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Towers_TowerBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_richa_OneDrive_Desktop_SiegeSmasher_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Towers_TowerBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
