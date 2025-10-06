// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SiegeSmasher/Public/AI/MyAIController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyAIController() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_AAIController();
SIEGESMASHER_API UClass* Z_Construct_UClass_AMyAIController();
SIEGESMASHER_API UClass* Z_Construct_UClass_AMyAIController_NoRegister();
UPackage* Z_Construct_UPackage__Script_SiegeSmasher();
// End Cross Module References

// Begin Class AMyAIController
void AMyAIController::StaticRegisterNativesAMyAIController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyAIController);
UClass* Z_Construct_UClass_AMyAIController_NoRegister()
{
	return AMyAIController::StaticClass();
}
struct Z_Construct_UClass_AMyAIController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "AI/MyAIController.h" },
		{ "ModuleRelativePath", "Public/AI/MyAIController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IndexStart_MetaData[] = {
		{ "Category", "MyVariables" },
		{ "ModuleRelativePath", "Public/AI/MyAIController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_IndexStart;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyAIController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMyAIController_Statics::NewProp_IndexStart = { "IndexStart", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyAIController, IndexStart), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IndexStart_MetaData), NewProp_IndexStart_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyAIController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyAIController_Statics::NewProp_IndexStart,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyAIController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMyAIController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AAIController,
	(UObject* (*)())Z_Construct_UPackage__Script_SiegeSmasher,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyAIController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyAIController_Statics::ClassParams = {
	&AMyAIController::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AMyAIController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AMyAIController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyAIController_Statics::Class_MetaDataParams), Z_Construct_UClass_AMyAIController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMyAIController()
{
	if (!Z_Registration_Info_UClass_AMyAIController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyAIController.OuterSingleton, Z_Construct_UClass_AMyAIController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMyAIController.OuterSingleton;
}
template<> SIEGESMASHER_API UClass* StaticClass<AMyAIController>()
{
	return AMyAIController::StaticClass();
}
AMyAIController::AMyAIController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMyAIController);
AMyAIController::~AMyAIController() {}
// End Class AMyAIController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Public_AI_MyAIController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMyAIController, AMyAIController::StaticClass, TEXT("AMyAIController"), &Z_Registration_Info_UClass_AMyAIController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyAIController), 3072394918U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Public_AI_MyAIController_h_4157843721(TEXT("/Script/SiegeSmasher"),
	Z_CompiledInDeferFile_FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Public_AI_MyAIController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Public_AI_MyAIController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
