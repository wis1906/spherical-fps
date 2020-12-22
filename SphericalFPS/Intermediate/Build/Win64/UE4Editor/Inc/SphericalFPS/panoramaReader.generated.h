// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SPHERICALFPS_panoramaReader_generated_h
#error "panoramaReader.generated.h already included, missing '#pragma once' in panoramaReader.h"
#endif
#define SPHERICALFPS_panoramaReader_generated_h

#define SphericalFPS_Source_SphericalFPS_panoramaReader_h_29_RPC_WRAPPERS
#define SphericalFPS_Source_SphericalFPS_panoramaReader_h_29_RPC_WRAPPERS_NO_PURE_DECLS
#define SphericalFPS_Source_SphericalFPS_panoramaReader_h_29_EVENT_PARMS
#define SphericalFPS_Source_SphericalFPS_panoramaReader_h_29_CALLBACK_WRAPPERS
#define SphericalFPS_Source_SphericalFPS_panoramaReader_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesApanoramaReader(); \
	friend SPHERICALFPS_API class UClass* Z_Construct_UClass_ApanoramaReader(); \
public: \
	DECLARE_CLASS(ApanoramaReader, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/SphericalFPS"), NO_API) \
	DECLARE_SERIALIZER(ApanoramaReader) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define SphericalFPS_Source_SphericalFPS_panoramaReader_h_29_INCLASS \
private: \
	static void StaticRegisterNativesApanoramaReader(); \
	friend SPHERICALFPS_API class UClass* Z_Construct_UClass_ApanoramaReader(); \
public: \
	DECLARE_CLASS(ApanoramaReader, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/SphericalFPS"), NO_API) \
	DECLARE_SERIALIZER(ApanoramaReader) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define SphericalFPS_Source_SphericalFPS_panoramaReader_h_29_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ApanoramaReader(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ApanoramaReader) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ApanoramaReader); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ApanoramaReader); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ApanoramaReader(ApanoramaReader&&); \
	NO_API ApanoramaReader(const ApanoramaReader&); \
public:


#define SphericalFPS_Source_SphericalFPS_panoramaReader_h_29_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ApanoramaReader(ApanoramaReader&&); \
	NO_API ApanoramaReader(const ApanoramaReader&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ApanoramaReader); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ApanoramaReader); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ApanoramaReader)


#define SphericalFPS_Source_SphericalFPS_panoramaReader_h_29_PRIVATE_PROPERTY_OFFSET
#define SphericalFPS_Source_SphericalFPS_panoramaReader_h_26_PROLOG \
	SphericalFPS_Source_SphericalFPS_panoramaReader_h_29_EVENT_PARMS


#define SphericalFPS_Source_SphericalFPS_panoramaReader_h_29_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SphericalFPS_Source_SphericalFPS_panoramaReader_h_29_PRIVATE_PROPERTY_OFFSET \
	SphericalFPS_Source_SphericalFPS_panoramaReader_h_29_RPC_WRAPPERS \
	SphericalFPS_Source_SphericalFPS_panoramaReader_h_29_CALLBACK_WRAPPERS \
	SphericalFPS_Source_SphericalFPS_panoramaReader_h_29_INCLASS \
	SphericalFPS_Source_SphericalFPS_panoramaReader_h_29_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SphericalFPS_Source_SphericalFPS_panoramaReader_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SphericalFPS_Source_SphericalFPS_panoramaReader_h_29_PRIVATE_PROPERTY_OFFSET \
	SphericalFPS_Source_SphericalFPS_panoramaReader_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	SphericalFPS_Source_SphericalFPS_panoramaReader_h_29_CALLBACK_WRAPPERS \
	SphericalFPS_Source_SphericalFPS_panoramaReader_h_29_INCLASS_NO_PURE_DECLS \
	SphericalFPS_Source_SphericalFPS_panoramaReader_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SphericalFPS_Source_SphericalFPS_panoramaReader_h


#define FOREACH_ENUM_PLAYMODE(op) \
	op(PlayMode::Image) \
	op(PlayMode::Video) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
