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
ENGINE_API UClass* Z_Construct_UClass_UAnimBlueprint_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
SIEGESMASHER_API UClass* Z_Construct_UClass_AMainCharacterTest();
SIEGESMASHER_API UClass* Z_Construct_UClass_AMainCharacterTest_NoRegister();
SIEGESMASHER_API UClass* Z_Construct_UClass_APlayerArrow_NoRegister();
UPackage* Z_Construct_UPackage__Script_SiegeSmasher();
// End Cross Module References

// Begin Class AMainCharacterTest
void AMainCharacterTest::StaticRegisterNativesAMainCharacterTest()
{
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
		{ "Category", "MainCharacterTest" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerAnimBP_MetaData[] = {
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultContext_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//UPROPERTY(VisibleAnywhere, Category = \"Input\");\n//bool ArrowDrawn;\n" },
#endif
		{ "ModuleRelativePath", "MyMainCharacterTest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UPROPERTY(VisibleAnywhere, Category = \"Input\");\nbool ArrowDrawn;" },
#endif
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
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TPSCameraComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArmComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerAnimBP;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ShootAction;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BowOffset;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ArrowClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMainCharacterTest>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TPSCameraComponent = { "TPSCameraComponent", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, TPSCameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TPSCameraComponent_MetaData), NewProp_TPSCameraComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_SpringArmComponent = { "SpringArmComponent", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, SpringArmComponent), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpringArmComponent_MetaData), NewProp_SpringArmComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_PlayerAnimBP = { "PlayerAnimBP", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, PlayerAnimBP), Z_Construct_UClass_UAnimBlueprint_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerAnimBP_MetaData), NewProp_PlayerAnimBP_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_DefaultContext = { "DefaultContext", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, DefaultContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultContext_MetaData), NewProp_DefaultContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpAction_MetaData), NewProp_JumpAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookAction_MetaData), NewProp_LookAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ShootAction = { "ShootAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, ShootAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShootAction_MetaData), NewProp_ShootAction_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_BowOffset = { "BowOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, BowOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BowOffset_MetaData), NewProp_BowOffset_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowClass = { "ArrowClass", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainCharacterTest, ArrowClass), Z_Construct_UClass_UClass, Z_Construct_UClass_APlayerArrow_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArrowClass_MetaData), NewProp_ArrowClass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMainCharacterTest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_TPSCameraComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_SpringArmComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_PlayerAnimBP,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_DefaultContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_JumpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_LookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ShootAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_BowOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainCharacterTest_Statics::NewProp_ArrowClass,
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
	nullptr,
	Z_Construct_UClass_AMainCharacterTest_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
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
		{ Z_Construct_UClass_AMainCharacterTest, AMainCharacterTest::StaticClass, TEXT("AMainCharacterTest"), &Z_Registration_Info_UClass_AMainCharacterTest, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMainCharacterTest), 2132927555U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_kewin_Desktop_C__Unreal_Engine_Assigment_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_999774360(TEXT("/Script/SiegeSmasher"),
	Z_CompiledInDeferFile_FID_Users_kewin_Desktop_C__Unreal_Engine_Assigment_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_kewin_Desktop_C__Unreal_Engine_Assigment_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
