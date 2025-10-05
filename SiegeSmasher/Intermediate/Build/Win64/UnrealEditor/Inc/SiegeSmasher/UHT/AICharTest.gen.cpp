// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SiegeSmasher/Public/AI/AICharTest.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAICharTest() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
SIEGESMASHER_API UClass* Z_Construct_UClass_AAICharTest();
SIEGESMASHER_API UClass* Z_Construct_UClass_AAICharTest_NoRegister();
UPackage* Z_Construct_UPackage__Script_SiegeSmasher();
// End Cross Module References

// Begin Class AAICharTest
void AAICharTest::StaticRegisterNativesAAICharTest()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AAICharTest);
UClass* Z_Construct_UClass_AAICharTest_NoRegister()
{
	return AAICharTest::StaticClass();
}
struct Z_Construct_UClass_AAICharTest_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "AI/AICharTest.h" },
		{ "ModuleRelativePath", "Public/AI/AICharTest.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAICharTest>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AAICharTest_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_SiegeSmasher,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAICharTest_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AAICharTest_Statics::ClassParams = {
	&AAICharTest::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAICharTest_Statics::Class_MetaDataParams), Z_Construct_UClass_AAICharTest_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AAICharTest()
{
	if (!Z_Registration_Info_UClass_AAICharTest.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAICharTest.OuterSingleton, Z_Construct_UClass_AAICharTest_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AAICharTest.OuterSingleton;
}
template<> SIEGESMASHER_API UClass* StaticClass<AAICharTest>()
{
	return AAICharTest::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AAICharTest);
AAICharTest::~AAICharTest() {}
// End Class AAICharTest

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Projects_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Public_AI_AICharTest_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AAICharTest, AAICharTest::StaticClass, TEXT("AAICharTest"), &Z_Registration_Info_UClass_AAICharTest, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAICharTest), 345197410U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Public_AI_AICharTest_h_1121586047(TEXT("/Script/SiegeSmasher"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Public_AI_AICharTest_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Public_AI_AICharTest_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
