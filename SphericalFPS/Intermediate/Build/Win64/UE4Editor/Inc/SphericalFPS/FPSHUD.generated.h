// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SPHERICALFPS_FPSHUD_generated_h
#error "FPSHUD.generated.h already included, missing '#pragma once' in FPSHUD.h"
#endif
#define SPHERICALFPS_FPSHUD_generated_h

#define SphericalFPS_Source_SphericalFPS_FPSHUD_h_16_RPC_WRAPPERS
#define SphericalFPS_Source_SphericalFPS_FPSHUD_h_16_RPC_WRAPPERS_NO_PURE_DECLS
#define SphericalFPS_Source_SphericalFPS_FPSHUD_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFPSHUD(); \
	friend SPHERICALFPS_API class UClass* Z_Construct_UClass_AFPSHUD(); \
public: \
	DECLARE_CLASS(AFPSHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, TEXT("/Script/SphericalFPS"), NO_API) \
	DECLARE_SERIALIZER(AFPSHUD) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define SphericalFPS_Source_SphericalFPS_FPSHUD_h_16_INCLASS \
private: \
	static void StaticRegisterNativesAFPSHUD(); \
	friend SPHERICALFPS_API class UClass* Z_Construct_UClass_AFPSHUD(); \
public: \
	DECLARE_CLASS(AFPSHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, TEXT("/Script/SphericalFPS"), NO_API) \
	DECLARE_SERIALIZER(AFPSHUD) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define SphericalFPS_Source_SphericalFPS_FPSHUD_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFPSHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFPSHUD) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSHUD); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSHUD(AFPSHUD&&); \
	NO_API AFPSHUD(const AFPSHUD&); \
public:


#define SphericalFPS_Source_SphericalFPS_FPSHUD_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFPSHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSHUD(AFPSHUD&&); \
	NO_API AFPSHUD(const AFPSHUD&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSHUD); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFPSHUD)


#define SphericalFPS_Source_SphericalFPS_FPSHUD_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CrosshairTexture() { return STRUCT_OFFSET(AFPSHUD, CrosshairTexture); }


#define SphericalFPS_Source_SphericalFPS_FPSHUD_h_13_PROLOG
#define SphericalFPS_Source_SphericalFPS_FPSHUD_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SphericalFPS_Source_SphericalFPS_FPSHUD_h_16_PRIVATE_PROPERTY_OFFSET \
	SphericalFPS_Source_SphericalFPS_FPSHUD_h_16_RPC_WRAPPERS \
	SphericalFPS_Source_SphericalFPS_FPSHUD_h_16_INCLASS \
	SphericalFPS_Source_SphericalFPS_FPSHUD_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SphericalFPS_Source_SphericalFPS_FPSHUD_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SphericalFPS_Source_SphericalFPS_FPSHUD_h_16_PRIVATE_PROPERTY_OFFSET \
	SphericalFPS_Source_SphericalFPS_FPSHUD_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	SphericalFPS_Source_SphericalFPS_FPSHUD_h_16_INCLASS_NO_PURE_DECLS \
	SphericalFPS_Source_SphericalFPS_FPSHUD_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SphericalFPS_Source_SphericalFPS_FPSHUD_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
