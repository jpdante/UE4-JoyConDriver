// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JoyConDriver/Public/JoyConDriverFunctionLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeJoyConDriverFunctionLibrary() {}
// Cross Module References
	JOYCONDRIVER_API UClass* Z_Construct_UClass_UJoyConDriverFunctionLibrary_NoRegister();
	JOYCONDRIVER_API UClass* Z_Construct_UClass_UJoyConDriverFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_JoyConDriver();
	JOYCONDRIVER_API UFunction* Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons();
	JOYCONDRIVER_API UScriptStruct* Z_Construct_UScriptStruct_FJoyConInformation();
// End Cross Module References
	void UJoyConDriverFunctionLibrary::StaticRegisterNativesUJoyConDriverFunctionLibrary()
	{
		UClass* Class = UJoyConDriverFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SearchForJoyCons", &UJoyConDriverFunctionLibrary::execSearchForJoyCons },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics
	{
		struct JoyConDriverFunctionLibrary_eventSearchForJoyCons_Parms
		{
			TArray<FJoyConInformation> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(JoyConDriverFunctionLibrary_eventSearchForJoyCons_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FJoyConInformation, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics::NewProp_ReturnValue_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics::Function_MetaDataParams[] = {
		{ "Category", "JoyCon" },
		{ "Comment", "/*UFUNCTION(BlueprintPure, Category = \"JoyCon\", meta = (Keywords = \"Nintendo Switch Joy Con Cons JoyCon JoyCons Connect\"))\n\x09static void ConnectJoyCons(bool& Success);*/" },
		{ "Keywords", "Nintendo Switch Joy Con Cons JoyCon JoyCons Search" },
		{ "ModuleRelativePath", "Public/JoyConDriverFunctionLibrary.h" },
		{ "ToolTip", "UFUNCTION(BlueprintPure, Category = \"JoyCon\", meta = (Keywords = \"Nintendo Switch Joy Con Cons JoyCon JoyCons Connect\"))\n       static void ConnectJoyCons(bool& Success);" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UJoyConDriverFunctionLibrary, nullptr, "SearchForJoyCons", nullptr, nullptr, sizeof(JoyConDriverFunctionLibrary_eventSearchForJoyCons_Parms), Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UJoyConDriverFunctionLibrary_NoRegister()
	{
		return UJoyConDriverFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UJoyConDriverFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UJoyConDriverFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_JoyConDriver,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UJoyConDriverFunctionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons, "SearchForJoyCons" }, // 1611448741
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UJoyConDriverFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "JoyConDriverFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/JoyConDriverFunctionLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UJoyConDriverFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJoyConDriverFunctionLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UJoyConDriverFunctionLibrary_Statics::ClassParams = {
		&UJoyConDriverFunctionLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UJoyConDriverFunctionLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UJoyConDriverFunctionLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UJoyConDriverFunctionLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UJoyConDriverFunctionLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UJoyConDriverFunctionLibrary, 698145693);
	template<> JOYCONDRIVER_API UClass* StaticClass<UJoyConDriverFunctionLibrary>()
	{
		return UJoyConDriverFunctionLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UJoyConDriverFunctionLibrary(Z_Construct_UClass_UJoyConDriverFunctionLibrary, &UJoyConDriverFunctionLibrary::StaticClass, TEXT("/Script/JoyConDriver"), TEXT("UJoyConDriverFunctionLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UJoyConDriverFunctionLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
