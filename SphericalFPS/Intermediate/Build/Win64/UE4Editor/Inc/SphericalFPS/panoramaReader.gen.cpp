// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "panoramaReader.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodepanoramaReader() {}
// Cross Module References
	SPHERICALFPS_API UEnum* Z_Construct_UEnum_SphericalFPS_PlayMode();
	UPackage* Z_Construct_UPackage__Script_SphericalFPS();
	SPHERICALFPS_API UClass* Z_Construct_UClass_ApanoramaReader_NoRegister();
	SPHERICALFPS_API UClass* Z_Construct_UClass_ApanoramaReader();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	SPHERICALFPS_API UFunction* Z_Construct_UFunction_ApanoramaReader_OnNextVideoFrame();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
// End Cross Module References
	static UEnum* PlayMode_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_SphericalFPS_PlayMode, Z_Construct_UPackage__Script_SphericalFPS(), TEXT("PlayMode"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_PlayMode(PlayMode_StaticEnum, TEXT("/Script/SphericalFPS"), TEXT("PlayMode"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_SphericalFPS_PlayMode_CRC() { return 1014727683U; }
	UEnum* Z_Construct_UEnum_SphericalFPS_PlayMode()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_SphericalFPS();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("PlayMode"), 0, Get_Z_Construct_UEnum_SphericalFPS_PlayMode_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "PlayMode::Image", (int64)PlayMode::Image },
				{ "PlayMode::Video", (int64)PlayMode::Video },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Image.DisplayName", "Image" },
				{ "ModuleRelativePath", "panoramaReader.h" },
				{ "Video.DisplayName", "Video" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_SphericalFPS,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"PlayMode",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"PlayMode",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static FName NAME_ApanoramaReader_OnNextVideoFrame = FName(TEXT("OnNextVideoFrame"));
	void ApanoramaReader::OnNextVideoFrame()
	{
		ProcessEvent(FindFunctionChecked(NAME_ApanoramaReader_OnNextVideoFrame),NULL);
	}
	void ApanoramaReader::StaticRegisterNativesApanoramaReader()
	{
	}
	UFunction* Z_Construct_UFunction_ApanoramaReader_OnNextVideoFrame()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "panoramaReader.h" },
				{ "ToolTip", "For blueprint functions" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ApanoramaReader, "OnNextVideoFrame", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ApanoramaReader_NoRegister()
	{
		return ApanoramaReader::StaticClass();
	}
	UClass* Z_Construct_UClass_ApanoramaReader()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_SphericalFPS,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ApanoramaReader_OnNextVideoFrame, "OnNextVideoFrame" }, // 2637203762
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "panoramaReader.h" },
				{ "ModuleRelativePath", "panoramaReader.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RightTexture_MetaData[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "panoramaReader.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RightTexture = { UE4CodeGen_Private::EPropertyClass::Object, "RightTexture", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(ApanoramaReader, RightTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(NewProp_RightTexture_MetaData, ARRAY_COUNT(NewProp_RightTexture_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FrontTexture_MetaData[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "panoramaReader.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FrontTexture = { UE4CodeGen_Private::EPropertyClass::Object, "FrontTexture", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(ApanoramaReader, FrontTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(NewProp_FrontTexture_MetaData, ARRAY_COUNT(NewProp_FrontTexture_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LeftTexture_MetaData[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "panoramaReader.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LeftTexture = { UE4CodeGen_Private::EPropertyClass::Object, "LeftTexture", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(ApanoramaReader, LeftTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(NewProp_LeftTexture_MetaData, ARRAY_COUNT(NewProp_LeftTexture_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RearTexture_MetaData[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "panoramaReader.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RearTexture = { UE4CodeGen_Private::EPropertyClass::Object, "RearTexture", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(ApanoramaReader, RearTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(NewProp_RearTexture_MetaData, ARRAY_COUNT(NewProp_RearTexture_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BottomTexture_MetaData[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "panoramaReader.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BottomTexture = { UE4CodeGen_Private::EPropertyClass::Object, "BottomTexture", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(ApanoramaReader, BottomTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(NewProp_BottomTexture_MetaData, ARRAY_COUNT(NewProp_BottomTexture_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TopTexture_MetaData[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "panoramaReader.h" },
				{ "ToolTip", "Image textures" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TopTexture = { UE4CodeGen_Private::EPropertyClass::Object, "TopTexture", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(ApanoramaReader, TopTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(NewProp_TopTexture_MetaData, ARRAY_COUNT(NewProp_TopTexture_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_playMode_MetaData[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "panoramaReader.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_playMode = { UE4CodeGen_Private::EPropertyClass::Enum, "playMode", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ApanoramaReader, playMode), Z_Construct_UEnum_SphericalFPS_PlayMode, METADATA_PARAMS(NewProp_playMode_MetaData, ARRAY_COUNT(NewProp_playMode_MetaData)) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_playMode_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_imagePath_Depth_MetaData[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "panoramaReader.h" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_imagePath_Depth = { UE4CodeGen_Private::EPropertyClass::Str, "imagePath_Depth", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ApanoramaReader, imagePath_Depth), METADATA_PARAMS(NewProp_imagePath_Depth_MetaData, ARRAY_COUNT(NewProp_imagePath_Depth_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_imagePath_RGB_MetaData[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "panoramaReader.h" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_imagePath_RGB = { UE4CodeGen_Private::EPropertyClass::Str, "imagePath_RGB", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ApanoramaReader, imagePath_RGB), METADATA_PARAMS(NewProp_imagePath_RGB_MetaData, ARRAY_COUNT(NewProp_imagePath_RGB_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_filePath_MetaData[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "panoramaReader.h" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_filePath = { UE4CodeGen_Private::EPropertyClass::Str, "filePath", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ApanoramaReader, filePath), METADATA_PARAMS(NewProp_filePath_MetaData, ARRAY_COUNT(NewProp_filePath_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isShowPaintball_MetaData[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "panoramaReader.h" },
			};
#endif
			auto NewProp_isShowPaintball_SetBit = [](void* Obj){ ((ApanoramaReader*)Obj)->isShowPaintball = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isShowPaintball = { UE4CodeGen_Private::EPropertyClass::Bool, "isShowPaintball", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ApanoramaReader), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_isShowPaintball_SetBit)>::SetBit, METADATA_PARAMS(NewProp_isShowPaintball_MetaData, ARRAY_COUNT(NewProp_isShowPaintball_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isShowPanoImage_MetaData[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "panoramaReader.h" },
			};
#endif
			auto NewProp_isShowPanoImage_SetBit = [](void* Obj){ ((ApanoramaReader*)Obj)->isShowPanoImage = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isShowPanoImage = { UE4CodeGen_Private::EPropertyClass::Bool, "isShowPanoImage", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ApanoramaReader), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_isShowPanoImage_SetBit)>::SetBit, METADATA_PARAMS(NewProp_isShowPanoImage_MetaData, ARRAY_COUNT(NewProp_isShowPanoImage_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_viewRatio_MetaData[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "panoramaReader.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_viewRatio = { UE4CodeGen_Private::EPropertyClass::Float, "viewRatio", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ApanoramaReader, viewRatio), METADATA_PARAMS(NewProp_viewRatio_MetaData, ARRAY_COUNT(NewProp_viewRatio_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_panoramaHeight_MetaData[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "panoramaReader.h" },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_panoramaHeight = { UE4CodeGen_Private::EPropertyClass::Int, "panoramaHeight", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ApanoramaReader, panoramaHeight), METADATA_PARAMS(NewProp_panoramaHeight_MetaData, ARRAY_COUNT(NewProp_panoramaHeight_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_panoramaWidth_MetaData[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "panoramaReader.h" },
				{ "ToolTip", "Editor Adjustable Field" },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_panoramaWidth = { UE4CodeGen_Private::EPropertyClass::Int, "panoramaWidth", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ApanoramaReader, panoramaWidth), METADATA_PARAMS(NewProp_panoramaWidth_MetaData, ARRAY_COUNT(NewProp_panoramaWidth_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RightTexture,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_FrontTexture,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_LeftTexture,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RearTexture,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BottomTexture,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TopTexture,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_playMode,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_playMode_Underlying,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_imagePath_Depth,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_imagePath_RGB,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_filePath,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_isShowPaintball,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_isShowPanoImage,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_viewRatio,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_panoramaHeight,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_panoramaWidth,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ApanoramaReader>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ApanoramaReader::StaticClass,
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
	IMPLEMENT_CLASS(ApanoramaReader, 2403310226);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ApanoramaReader(Z_Construct_UClass_ApanoramaReader, &ApanoramaReader::StaticClass, TEXT("/Script/SphericalFPS"), TEXT("ApanoramaReader"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ApanoramaReader);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
