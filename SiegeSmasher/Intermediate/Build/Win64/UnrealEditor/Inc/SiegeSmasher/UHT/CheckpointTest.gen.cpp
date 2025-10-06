// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SiegeSmasher/Public/AI/CheckpointTest.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCheckpointTest() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
SIEGESMASHER_API UClass* Z_Construct_UClass_ACheckpointTest();
SIEGESMASHER_API UClass* Z_Construct_UClass_ACheckpointTest_NoRegister();
UPackage* Z_Construct_UPackage__Script_SiegeSmasher();
// End Cross Module References

// Begin Class ACheckpointTest
void ACheckpointTest::StaticRegisterNativesACheckpointTest()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACheckpointTest);
UClass* Z_Construct_UClass_ACheckpointTest_NoRegister()
{
	return ACheckpointTest::StaticClass();
}
struct Z_Construct_UClass_ACheckpointTest_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AI/CheckpointTest.h" },
		{ "ModuleRelativePath", "Public/AI/CheckpointTest.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACheckpointTest>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ACheckpointTest_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_SiegeSmasher,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACheckpointTest_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACheckpointTest_Statics::ClassParams = {
	&ACheckpointTest::StaticClass,
	"Engine",
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACheckpointTest_Statics::Class_MetaDataParams), Z_Construct_UClass_ACheckpointTest_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACheckpointTest()
{
	if (!Z_Registration_Info_UClass_ACheckpointTest.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACheckpointTest.OuterSingleton, Z_Construct_UClass_ACheckpointTest_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACheckpointTest.OuterSingleton;
}
template<> SIEGESMASHER_API UClass* StaticClass<ACheckpointTest>()
{
	return ACheckpointTest::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACheckpointTest);
ACheckpointTest::~ACheckpointTest() {}
// End Class ACheckpointTest

// Begin Registration
struct Z_CompiledInDeferFile_FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Public_AI_CheckpointTest_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACheckpointTest, ACheckpointTest::StaticClass, TEXT("ACheckpointTest"), &Z_Registration_Info_UClass_ACheckpointTest, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACheckpointTest), 1172670741U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Public_AI_CheckpointTest_h_3181629237(TEXT("/Script/SiegeSmasher"),
	Z_CompiledInDeferFile_FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Public_AI_CheckpointTest_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Public_AI_CheckpointTest_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
