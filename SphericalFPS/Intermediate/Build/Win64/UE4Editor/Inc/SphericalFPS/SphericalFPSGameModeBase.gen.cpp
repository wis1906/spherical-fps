// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "SphericalFPSGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSphericalFPSGameModeBase() {}
// Cross Module References
	SPHERICALFPS_API UClass* Z_Construct_UClass_ASphericalFPSGameModeBase_NoRegister();
	SPHERICALFPS_API UClass* Z_Construct_UClass_ASphericalFPSGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_SphericalFPS();
// End Cross Module References
	void ASphericalFPSGameModeBase::StaticRegisterNativesASphericalFPSGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ASphericalFPSGameModeBase_NoRegister()
	{
		return ASphericalFPSGameModeBase::StaticClass();
	}
	UClass* Z_Construct_UClass_ASphericalFPSGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AGameModeBase,
				(UObject* (*)())Z_Construct_UPackage__Script_SphericalFPS,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "SphericalFPSGameModeBase.h" },
				{ "ModuleRelativePath", "SphericalFPSGameModeBase.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ASphericalFPSGameModeBase>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ASphericalFPSGameModeBase::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900288u,
				nullptr, 0,
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASphericalFPSGameModeBase, 369731133);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASphericalFPSGameModeBase(Z_Construct_UClass_ASphericalFPSGameModeBase, &ASphericalFPSGameModeBase::StaticClass, TEXT("/Script/SphericalFPS"), TEXT("ASphericalFPSGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASphericalFPSGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
