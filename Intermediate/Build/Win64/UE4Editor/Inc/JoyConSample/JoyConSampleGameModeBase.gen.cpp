// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JoyConSample/JoyConSampleGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeJoyConSampleGameModeBase() {}
// Cross Module References
	JOYCONSAMPLE_API UClass* Z_Construct_UClass_AJoyConSampleGameModeBase_NoRegister();
	JOYCONSAMPLE_API UClass* Z_Construct_UClass_AJoyConSampleGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_JoyConSample();
// End Cross Module References
	void AJoyConSampleGameModeBase::StaticRegisterNativesAJoyConSampleGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AJoyConSampleGameModeBase_NoRegister()
	{
		return AJoyConSampleGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AJoyConSampleGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AJoyConSampleGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_JoyConSample,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AJoyConSampleGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "JoyConSampleGameModeBase.h" },
		{ "ModuleRelativePath", "JoyConSampleGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AJoyConSampleGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AJoyConSampleGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AJoyConSampleGameModeBase_Statics::ClassParams = {
		&AJoyConSampleGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AJoyConSampleGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AJoyConSampleGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AJoyConSampleGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AJoyConSampleGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AJoyConSampleGameModeBase, 1629861161);
	template<> JOYCONSAMPLE_API UClass* StaticClass<AJoyConSampleGameModeBase>()
	{
		return AJoyConSampleGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AJoyConSampleGameModeBase(Z_Construct_UClass_AJoyConSampleGameModeBase, &AJoyConSampleGameModeBase::StaticClass, TEXT("/Script/JoyConSample"), TEXT("AJoyConSampleGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AJoyConSampleGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
