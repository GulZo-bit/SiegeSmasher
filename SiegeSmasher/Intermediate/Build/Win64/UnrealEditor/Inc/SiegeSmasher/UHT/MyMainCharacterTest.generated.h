// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyMainCharacterTest.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SIEGESMASHER_MyMainCharacterTest_generated_h
#error "MyMainCharacterTest.generated.h already included, missing '#pragma once' in MyMainCharacterTest.h"
#endif
#define SIEGESMASHER_MyMainCharacterTest_generated_h

#define FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetArrowFired); \
	DECLARE_FUNCTION(execGetArrowFired); \
	DECLARE_FUNCTION(execSetArrowDrawn); \
	DECLARE_FUNCTION(execGetArrowDrawn);


#define FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMainCharacterTest(); \
	friend struct Z_Construct_UClass_AMainCharacterTest_Statics; \
public: \
	DECLARE_CLASS(AMainCharacterTest, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SiegeSmasher"), NO_API) \
	DECLARE_SERIALIZER(AMainCharacterTest)


#define FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AMainCharacterTest(AMainCharacterTest&&); \
	AMainCharacterTest(const AMainCharacterTest&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMainCharacterTest); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMainCharacterTest); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMainCharacterTest) \
	NO_API virtual ~AMainCharacterTest();


#define FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_14_PROLOG
#define FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_17_INCLASS_NO_PURE_DECLS \
	FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SIEGESMASHER_API UClass* StaticClass<class AMainCharacterTest>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Github_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_MyMainCharacterTest_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
