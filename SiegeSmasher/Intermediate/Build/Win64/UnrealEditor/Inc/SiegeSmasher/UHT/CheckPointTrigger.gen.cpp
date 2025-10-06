// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SiegeSmasher/Public/AI/CheckPointTrigger.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCheckPointTrigger() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ATriggerVolume_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
SIEGESMASHER_API UClass* Z_Construct_UClass_UCheckPointTrigger();
SIEGESMASHER_API UClass* Z_Construct_UClass_UCheckPointTrigger_NoRegister();
UPackage* Z_Construct_UPackage__Script_SiegeSmasher();
// End Cross Module References

// Begin Class UCheckPointTrigger
void UCheckPointTrigger::StaticRegisterNativesUCheckPointTrigger()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCheckPointTrigger);
UClass* Z_Construct_UClass_UCheckPointTrigger_NoRegister()
{
	return UCheckPointTrigger::StaticClass();
}
struct Z_Construct_UClass_UCheckPointTrigger_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "AI/CheckPointTrigger.h" },
		{ "ModuleRelativePath", "Public/AI/CheckPointTrigger.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TriggerVol_MetaData[] = {
		{ "Category", "CheckpointTriggers" },
		{ "ModuleRelativePath", "Public/AI/CheckPointTrigger.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TriggerVol;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCheckPointTrigger>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCheckPointTrigger_Statics::NewProp_TriggerVol = { "TriggerVol", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCheckPointTrigger, TriggerVol), Z_Construct_UClass_ATriggerVolume_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TriggerVol_MetaData), NewProp_TriggerVol_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCheckPointTrigger_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCheckPointTrigger_Statics::NewProp_TriggerVol,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCheckPointTrigger_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCheckPointTrigger_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_SiegeSmasher,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCheckPointTrigger_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCheckPointTrigger_Statics::ClassParams = {
	&UCheckPointTrigger::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCheckPointTrigger_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCheckPointTrigger_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCheckPointTrigger_Statics::Class_MetaDataParams), Z_Construct_UClass_UCheckPointTrigger_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCheckPointTrigger()
{
	if (!Z_Registration_Info_UClass_UCheckPointTrigger.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCheckPointTrigger.OuterSingleton, Z_Construct_UClass_UCheckPointTrigger_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCheckPointTrigger.OuterSingleton;
}
template<> SIEGESMASHER_API UClass* StaticClass<UCheckPointTrigger>()
{
	return UCheckPointTrigger::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCheckPointTrigger);
UCheckPointTrigger::~UCheckPointTrigger() {}
// End Class UCheckPointTrigger

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Public_AI_CheckPointTrigger_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCheckPointTrigger, UCheckPointTrigger::StaticClass, TEXT("UCheckPointTrigger"), &Z_Registration_Info_UClass_UCheckPointTrigger, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCheckPointTrigger), 3505701040U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Public_AI_CheckPointTrigger_h_1498886406(TEXT("/Script/SiegeSmasher"),
	Z_CompiledInDeferFile_FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Public_AI_CheckPointTrigger_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Public_AI_CheckPointTrigger_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
