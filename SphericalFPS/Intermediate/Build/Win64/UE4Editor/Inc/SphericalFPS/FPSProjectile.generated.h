// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef SPHERICALFPS_FPSProjectile_generated_h
#error "FPSProjectile.generated.h already included, missing '#pragma once' in FPSProjectile.h"
#endif
#define SPHERICALFPS_FPSProjectile_generated_h

#define SphericalFPS_Source_SphericalFPS_FPSProjectile_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComponent); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHit(Z_Param_HitComponent,Z_Param_OtherActor,Z_Param_OtherComponent,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execgetPatch) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->getPatch(); \
		P_NATIVE_END; \
	}


#define SphericalFPS_Source_SphericalFPS_FPSProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComponent); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHit(Z_Param_HitComponent,Z_Param_OtherActor,Z_Param_OtherComponent,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execgetPatch) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->getPatch(); \
		P_NATIVE_END; \
	}


#define SphericalFPS_Source_SphericalFPS_FPSProjectile_h_15_EVENT_PARMS \
	struct FPSProjectile_eventsetLifeTimerByDepth_Parms \
	{ \
		float lifeTime; \
	};


#define SphericalFPS_Source_SphericalFPS_FPSProjectile_h_15_CALLBACK_WRAPPERS
#define SphericalFPS_Source_SphericalFPS_FPSProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFPSProjectile(); \
	friend SPHERICALFPS_API class UClass* Z_Construct_UClass_AFPSProjectile(); \
public: \
	DECLARE_CLASS(AFPSProjectile, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/SphericalFPS"), NO_API) \
	DECLARE_SERIALIZER(AFPSProjectile) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define SphericalFPS_Source_SphericalFPS_FPSProjectile_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAFPSProjectile(); \
	friend SPHERICALFPS_API class UClass* Z_Construct_UClass_AFPSProjectile(); \
public: \
	DECLARE_CLASS(AFPSProjectile, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/SphericalFPS"), NO_API) \
	DECLARE_SERIALIZER(AFPSProjectile) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define SphericalFPS_Source_SphericalFPS_FPSProjectile_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFPSProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFPSProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSProjectile(AFPSProjectile&&); \
	NO_API AFPSProjectile(const AFPSProjectile&); \
public:


#define SphericalFPS_Source_SphericalFPS_FPSProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSProjectile(AFPSProjectile&&); \
	NO_API AFPSProjectile(const AFPSProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFPSProjectile)


#define SphericalFPS_Source_SphericalFPS_FPSProjectile_h_15_PRIVATE_PROPERTY_OFFSET
#define SphericalFPS_Source_SphericalFPS_FPSProjectile_h_12_PROLOG \
	SphericalFPS_Source_SphericalFPS_FPSProjectile_h_15_EVENT_PARMS


#define SphericalFPS_Source_SphericalFPS_FPSProjectile_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SphericalFPS_Source_SphericalFPS_FPSProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	SphericalFPS_Source_SphericalFPS_FPSProjectile_h_15_RPC_WRAPPERS \
	SphericalFPS_Source_SphericalFPS_FPSProjectile_h_15_CALLBACK_WRAPPERS \
	SphericalFPS_Source_SphericalFPS_FPSProjectile_h_15_INCLASS \
	SphericalFPS_Source_SphericalFPS_FPSProjectile_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SphericalFPS_Source_SphericalFPS_FPSProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SphericalFPS_Source_SphericalFPS_FPSProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	SphericalFPS_Source_SphericalFPS_FPSProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	SphericalFPS_Source_SphericalFPS_FPSProjectile_h_15_CALLBACK_WRAPPERS \
	SphericalFPS_Source_SphericalFPS_FPSProjectile_h_15_INCLASS_NO_PURE_DECLS \
	SphericalFPS_Source_SphericalFPS_FPSProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SphericalFPS_Source_SphericalFPS_FPSProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
