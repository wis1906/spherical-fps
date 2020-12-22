// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SPHERICALFPS_FPSCharacter_generated_h
#error "FPSCharacter.generated.h already included, missing '#pragma once' in FPSCharacter.h"
#endif
#define SPHERICALFPS_FPSCharacter_generated_h

#define SphericalFPS_Source_SphericalFPS_FPSCharacter_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execFire) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Fire(); \
		P_NATIVE_END; \
	}


#define SphericalFPS_Source_SphericalFPS_FPSCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execFire) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Fire(); \
		P_NATIVE_END; \
	}


#define SphericalFPS_Source_SphericalFPS_FPSCharacter_h_14_EVENT_PARMS
#define SphericalFPS_Source_SphericalFPS_FPSCharacter_h_14_CALLBACK_WRAPPERS
#define SphericalFPS_Source_SphericalFPS_FPSCharacter_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFPSCharacter(); \
	friend SPHERICALFPS_API class UClass* Z_Construct_UClass_AFPSCharacter(); \
public: \
	DECLARE_CLASS(AFPSCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/SphericalFPS"), NO_API) \
	DECLARE_SERIALIZER(AFPSCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define SphericalFPS_Source_SphericalFPS_FPSCharacter_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAFPSCharacter(); \
	friend SPHERICALFPS_API class UClass* Z_Construct_UClass_AFPSCharacter(); \
public: \
	DECLARE_CLASS(AFPSCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/SphericalFPS"), NO_API) \
	DECLARE_SERIALIZER(AFPSCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define SphericalFPS_Source_SphericalFPS_FPSCharacter_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFPSCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFPSCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSCharacter(AFPSCharacter&&); \
	NO_API AFPSCharacter(const AFPSCharacter&); \
public:


#define SphericalFPS_Source_SphericalFPS_FPSCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSCharacter(AFPSCharacter&&); \
	NO_API AFPSCharacter(const AFPSCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFPSCharacter)


#define SphericalFPS_Source_SphericalFPS_FPSCharacter_h_14_PRIVATE_PROPERTY_OFFSET
#define SphericalFPS_Source_SphericalFPS_FPSCharacter_h_11_PROLOG \
	SphericalFPS_Source_SphericalFPS_FPSCharacter_h_14_EVENT_PARMS


#define SphericalFPS_Source_SphericalFPS_FPSCharacter_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SphericalFPS_Source_SphericalFPS_FPSCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	SphericalFPS_Source_SphericalFPS_FPSCharacter_h_14_RPC_WRAPPERS \
	SphericalFPS_Source_SphericalFPS_FPSCharacter_h_14_CALLBACK_WRAPPERS \
	SphericalFPS_Source_SphericalFPS_FPSCharacter_h_14_INCLASS \
	SphericalFPS_Source_SphericalFPS_FPSCharacter_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SphericalFPS_Source_SphericalFPS_FPSCharacter_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SphericalFPS_Source_SphericalFPS_FPSCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	SphericalFPS_Source_SphericalFPS_FPSCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	SphericalFPS_Source_SphericalFPS_FPSCharacter_h_14_CALLBACK_WRAPPERS \
	SphericalFPS_Source_SphericalFPS_FPSCharacter_h_14_INCLASS_NO_PURE_DECLS \
	SphericalFPS_Source_SphericalFPS_FPSCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SphericalFPS_Source_SphericalFPS_FPSCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
