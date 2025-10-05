// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AI/MyAIController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SIEGESMASHER_MyAIController_generated_h
#error "MyAIController.generated.h already included, missing '#pragma once' in MyAIController.h"
#endif
#define SIEGESMASHER_MyAIController_generated_h

#define FID_Unreal_Projects_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Public_AI_MyAIController_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyAIController(); \
	friend struct Z_Construct_UClass_AMyAIController_Statics; \
public: \
	DECLARE_CLASS(AMyAIController, AAIController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SiegeSmasher"), NO_API) \
	DECLARE_SERIALIZER(AMyAIController)


#define FID_Unreal_Projects_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Public_AI_MyAIController_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyAIController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AMyAIController(AMyAIController&&); \
	AMyAIController(const AMyAIController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyAIController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyAIController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyAIController) \
	NO_API virtual ~AMyAIController();


#define FID_Unreal_Projects_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Public_AI_MyAIController_h_13_PROLOG
#define FID_Unreal_Projects_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Public_AI_MyAIController_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Projects_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Public_AI_MyAIController_h_16_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Projects_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Public_AI_MyAIController_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SIEGESMASHER_API UClass* StaticClass<class AMyAIController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Projects_SiegeSmasher_SiegeSmasher_Source_SiegeSmasher_Public_AI_MyAIController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
