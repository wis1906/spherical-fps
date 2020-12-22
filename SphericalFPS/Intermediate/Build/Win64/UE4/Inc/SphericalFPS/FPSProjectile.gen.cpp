// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "FPSProjectile.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFPSProjectile() {}
// Cross Module References
	SPHERICALFPS_API UClass* Z_Construct_UClass_AFPSProjectile_NoRegister();
	SPHERICALFPS_API UClass* Z_Construct_UClass_AFPSProjectile();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SphericalFPS();
	SPHERICALFPS_API UFunction* Z_Construct_UFunction_AFPSProjectile_getPatch();
	SPHERICALFPS_API UFunction* Z_Construct_UFunction_AFPSProjectile_OnHit();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	SPHERICALFPS_API UFunction* Z_Construct_UFunction_AFPSProjectile_setLifeTimerByDepth();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystem_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	ENGINE_API UClass* Z_Construct_UClass_UProjectileMovementComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
// End Cross Module References
	static FName NAME_AFPSProjectile_setLifeTimerByDepth = FName(TEXT("setLifeTimerByDepth"));
	void AFPSProjectile::setLifeTimerByDepth(float lifeTime)
	{
		FPSProjectile_eventsetLifeTimerByDepth_Parms Parms;
		Parms.lifeTime=lifeTime;
		ProcessEvent(FindFunctionChecked(NAME_AFPSProjectile_setLifeTimerByDepth),&Parms);
	}
	void AFPSProjectile::StaticRegisterNativesAFPSProjectile()
	{
		UClass* Class = AFPSProjectile::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "getPatch", &AFPSProjectile::execgetPatch },
			{ "OnHit", &AFPSProjectile::execOnHit },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_AFPSProjectile_getPatch()
	{
		struct FPSProjectile_eventgetPatch_Parms
		{
			int32 ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Int, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(FPSProjectile_eventgetPatch_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "FPSProjectile.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSProjectile, "getPatch", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(FPSProjectile_eventgetPatch_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFPSProjectile_OnHit()
	{
		struct FPSProjectile_eventOnHit_Parms
		{
			UPrimitiveComponent* HitComponent;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComponent;
			FVector NormalImpulse;
			FHitResult Hit;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_Hit = { UE4CodeGen_Private::EPropertyClass::Struct, "Hit", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010008008000182, 1, nullptr, STRUCT_OFFSET(FPSProjectile_eventOnHit_Parms, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(NewProp_Hit_MetaData, ARRAY_COUNT(NewProp_Hit_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_NormalImpulse = { UE4CodeGen_Private::EPropertyClass::Struct, "NormalImpulse", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(FPSProjectile_eventOnHit_Parms, NormalImpulse), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherComponent_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherComponent = { UE4CodeGen_Private::EPropertyClass::Object, "OtherComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(FPSProjectile_eventOnHit_Parms, OtherComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(NewProp_OtherComponent_MetaData, ARRAY_COUNT(NewProp_OtherComponent_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor = { UE4CodeGen_Private::EPropertyClass::Object, "OtherActor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(FPSProjectile_eventOnHit_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HitComponent_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HitComponent = { UE4CodeGen_Private::EPropertyClass::Object, "HitComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(FPSProjectile_eventOnHit_Parms, HitComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(NewProp_HitComponent_MetaData, ARRAY_COUNT(NewProp_HitComponent_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Hit,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_NormalImpulse,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OtherComponent,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OtherActor,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_HitComponent,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "FPSProjectile.h" },
				{ "ToolTip", "??????\xc5\xb8???? ???\xf0\xb0\xa1\xbf? ?????? \xc8\xa3???\xc7\xb4? ?\xd4\xbc??\xd4\xb4\xcf\xb4?." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSProjectile, "OnHit", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00C20401, sizeof(FPSProjectile_eventOnHit_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFPSProjectile_setLifeTimerByDepth()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_lifeTime = { UE4CodeGen_Private::EPropertyClass::Float, "lifeTime", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(FPSProjectile_eventsetLifeTimerByDepth_Parms, lifeTime), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_lifeTime,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "FPSProjectile.h" },
				{ "ToolTip", "For blueprint functions" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSProjectile, "setLifeTimerByDepth", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, sizeof(FPSProjectile_eventsetLifeTimerByDepth_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AFPSProjectile_NoRegister()
	{
		return AFPSProjectile::StaticClass();
	}
	UClass* Z_Construct_UClass_AFPSProjectile()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_SphericalFPS,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_AFPSProjectile_getPatch, "getPatch" }, // 1345549018
				{ &Z_Construct_UFunction_AFPSProjectile_OnHit, "OnHit" }, // 3665250725
				{ &Z_Construct_UFunction_AFPSProjectile_setLifeTimerByDepth, "setLifeTimerByDepth" }, // 1447193454
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "FPSProjectile.h" },
				{ "ModuleRelativePath", "FPSProjectile.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_depthTheshold_MetaData[] = {
				{ "Category", "FPSProjectile" },
				{ "ModuleRelativePath", "FPSProjectile.h" },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_depthTheshold = { UE4CodeGen_Private::EPropertyClass::Int, "depthTheshold", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AFPSProjectile, depthTheshold), METADATA_PARAMS(NewProp_depthTheshold_MetaData, ARRAY_COUNT(NewProp_depthTheshold_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_soundPitchVal_MetaData[] = {
				{ "Category", "FPSProjectile" },
				{ "ModuleRelativePath", "FPSProjectile.h" },
				{ "ToolTip", "?\xd2\xb8? ??\xc4\xa1??" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_soundPitchVal = { UE4CodeGen_Private::EPropertyClass::Float, "soundPitchVal", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000004, 1, nullptr, STRUCT_OFFSET(AFPSProjectile, soundPitchVal), METADATA_PARAMS(NewProp_soundPitchVal_MetaData, ARRAY_COUNT(NewProp_soundPitchVal_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_depthVal_MetaData[] = {
				{ "Category", "FPSProjectile" },
				{ "ModuleRelativePath", "FPSProjectile.h" },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_depthVal = { UE4CodeGen_Private::EPropertyClass::Int, "depthVal", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000004, 1, nullptr, STRUCT_OFFSET(AFPSProjectile, depthVal), METADATA_PARAMS(NewProp_depthVal_MetaData, ARRAY_COUNT(NewProp_depthVal_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_effectsByMaterial_MetaData[] = {
				{ "Category", "FPSProjectile" },
				{ "ModuleRelativePath", "FPSProjectile.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_effectsByMaterial = { UE4CodeGen_Private::EPropertyClass::Array, "effectsByMaterial", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AFPSProjectile, effectsByMaterial), METADATA_PARAMS(NewProp_effectsByMaterial_MetaData, ARRAY_COUNT(NewProp_effectsByMaterial_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_effectsByMaterial_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "effectsByMaterial", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_soundsByMaterial_MetaData[] = {
				{ "Category", "FPSProjectile" },
				{ "ModuleRelativePath", "FPSProjectile.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_soundsByMaterial = { UE4CodeGen_Private::EPropertyClass::Array, "soundsByMaterial", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AFPSProjectile, soundsByMaterial), METADATA_PARAMS(NewProp_soundsByMaterial_MetaData, ARRAY_COUNT(NewProp_soundsByMaterial_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_soundsByMaterial_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "soundsByMaterial", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_initialRotation_MetaData[] = {
				{ "Category", "Movement" },
				{ "ModuleRelativePath", "FPSProjectile.h" },
				{ "ToolTip", "??\xc3\xbc?? ?\xdf\xbb??? ?????? \xc4\xab?\xde\xb6? \xc8\xb8????" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_initialRotation = { UE4CodeGen_Private::EPropertyClass::Struct, "initialRotation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AFPSProjectile, initialRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(NewProp_initialRotation_MetaData, ARRAY_COUNT(NewProp_initialRotation_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProjectileMovementComponent_MetaData[] = {
				{ "Category", "Movement" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "FPSProjectile.h" },
				{ "ToolTip", "??????\xc5\xb8?? ??????\xc6\xae ??????\xc6\xae" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ProjectileMovementComponent = { UE4CodeGen_Private::EPropertyClass::Object, "ProjectileMovementComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x00100000000a0009, 1, nullptr, STRUCT_OFFSET(AFPSProjectile, ProjectileMovementComponent), Z_Construct_UClass_UProjectileMovementComponent_NoRegister, METADATA_PARAMS(NewProp_ProjectileMovementComponent_MetaData, ARRAY_COUNT(NewProp_ProjectileMovementComponent_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CollisionComponent_MetaData[] = {
				{ "Category", "Projectile" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "FPSProjectile.h" },
				{ "ToolTip", "??\xc3\xbc ?\xdd\xb8??? ??????\xc6\xae?\xd4\xb4\xcf\xb4?." },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CollisionComponent = { UE4CodeGen_Private::EPropertyClass::Object, "CollisionComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x00100000000b0009, 1, nullptr, STRUCT_OFFSET(AFPSProjectile, CollisionComponent), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(NewProp_CollisionComponent_MetaData, ARRAY_COUNT(NewProp_CollisionComponent_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_depthTheshold,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_soundPitchVal,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_depthVal,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_effectsByMaterial,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_effectsByMaterial_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_soundsByMaterial,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_soundsByMaterial_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_initialRotation,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProjectileMovementComponent,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CollisionComponent,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AFPSProjectile>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AFPSProjectile::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFPSProjectile, 617876792);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFPSProjectile(Z_Construct_UClass_AFPSProjectile, &AFPSProjectile::StaticClass, TEXT("/Script/SphericalFPS"), TEXT("AFPSProjectile"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFPSProjectile);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
