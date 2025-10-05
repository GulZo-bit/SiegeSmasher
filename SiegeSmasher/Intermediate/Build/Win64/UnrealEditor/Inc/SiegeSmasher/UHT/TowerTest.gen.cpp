// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SiegeSmasher/Towers/TowerTest.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTowerTest() {}

// Begin Cross Module References
SIEGESMASHER_API UClass* Z_Construct_UClass_ATowerBase();
SIEGESMASHER_API UClass* Z_Construct_UClass_ATowerTest();
SIEGESMASHER_API UClass* Z_Construct_UClass_ATowerTest_NoRegister();
UPackage* Z_Construct_UPackage__Script_SiegeSmasher();
// End Cross Module References

// Begin Class ATowerTest
void ATowerTest::StaticRegisterNativesATowerTest()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATowerTest);
UClass* Z_Construct_UClass_ATowerTest_NoRegister()
{
	return ATowerTest::StaticClass();
}
struct Z_Construct_UClass_ATowerTest_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Towers/TowerTest.h" },
		{ "ModuleRelativePath", "Towers/TowerTest.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATowerTest>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ATowerTest_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ATowerBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SiegeSmasher,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATowerTest_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATowerTest_Statics::ClassParams = {
	&ATowerTest::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATowerTest_Statics::Class_MetaDataParams), Z_Construct_UClass_ATowerTest_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ATowerTest()
{
	if (!Z_Registration_Info_UClass_ATowerTest.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATowerTest.OuterSingleton, Z_Construct_UClass_ATowerTest_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATowerTest.OuterSingleton;
}
template<> SIEGESMASHER_API UClass* StaticClass<ATowerTest>()
{
	return ATowerTest::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ATowerTest);
ATowerTest::~ATowerTest() {}
// End Class ATowerTest

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_richa_OneDrive_Desktop_SiegeSmasher_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Towers_TowerTest_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATowerTest, ATowerTest::StaticClass, TEXT("ATowerTest"), &Z_Registration_Info_UClass_ATowerTest, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATowerTest), 3407058551U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_richa_OneDrive_Desktop_SiegeSmasher_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Towers_TowerTest_h_257815348(TEXT("/Script/SiegeSmasher"),
	Z_CompiledInDeferFile_FID_Users_richa_OneDrive_Desktop_SiegeSmasher_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Towers_TowerTest_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_richa_OneDrive_Desktop_SiegeSmasher_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Towers_TowerTest_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
