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
	JOYCONDRIVER_API UFunction* Z_Construct_UFunction_UJoyConDriverFunctionLibrary_AttachJoyCon();
	JOYCONDRIVER_API UScriptStruct* Z_Construct_UScriptStruct_FJoyConInformation();
	JOYCONDRIVER_API UFunction* Z_Construct_UFunction_UJoyConDriverFunctionLibrary_DetachJoyCon();
	JOYCONDRIVER_API UFunction* Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConAccelerometer();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	JOYCONDRIVER_API UFunction* Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConGyroscope();
	JOYCONDRIVER_API UFunction* Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	JOYCONDRIVER_API UFunction* Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons();
// End Cross Module References
	void UJoyConDriverFunctionLibrary::StaticRegisterNativesUJoyConDriverFunctionLibrary()
	{
		UClass* Class = UJoyConDriverFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AttachJoyCon", &UJoyConDriverFunctionLibrary::execAttachJoyCon },
			{ "DetachJoyCon", &UJoyConDriverFunctionLibrary::execDetachJoyCon },
			{ "GetJoyConAccelerometer", &UJoyConDriverFunctionLibrary::execGetJoyConAccelerometer },
			{ "GetJoyConGyroscope", &UJoyConDriverFunctionLibrary::execGetJoyConGyroscope },
			{ "GetJoyConVector", &UJoyConDriverFunctionLibrary::execGetJoyConVector },
			{ "SearchForJoyCons", &UJoyConDriverFunctionLibrary::execSearchForJoyCons },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UJoyConDriverFunctionLibrary_AttachJoyCon_Statics
	{
		struct JoyConDriverFunctionLibrary_eventAttachJoyCon_Parms
		{
			FJoyConInformation JoyConInformation;
			bool Success;
			int32 ControllerIndex;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ControllerIndex;
		static void NewProp_Success_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Success;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_JoyConInformation;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_AttachJoyCon_Statics::NewProp_ControllerIndex = { "ControllerIndex", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(JoyConDriverFunctionLibrary_eventAttachJoyCon_Parms, ControllerIndex), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UJoyConDriverFunctionLibrary_AttachJoyCon_Statics::NewProp_Success_SetBit(void* Obj)
	{
		((JoyConDriverFunctionLibrary_eventAttachJoyCon_Parms*)Obj)->Success = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_AttachJoyCon_Statics::NewProp_Success = { "Success", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(JoyConDriverFunctionLibrary_eventAttachJoyCon_Parms), &Z_Construct_UFunction_UJoyConDriverFunctionLibrary_AttachJoyCon_Statics::NewProp_Success_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_AttachJoyCon_Statics::NewProp_JoyConInformation = { "JoyConInformation", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(JoyConDriverFunctionLibrary_eventAttachJoyCon_Parms, JoyConInformation), Z_Construct_UScriptStruct_FJoyConInformation, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJoyConDriverFunctionLibrary_AttachJoyCon_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJoyConDriverFunctionLibrary_AttachJoyCon_Statics::NewProp_ControllerIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJoyConDriverFunctionLibrary_AttachJoyCon_Statics::NewProp_Success,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJoyConDriverFunctionLibrary_AttachJoyCon_Statics::NewProp_JoyConInformation,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UJoyConDriverFunctionLibrary_AttachJoyCon_Statics::Function_MetaDataParams[] = {
		{ "Category", "JoyCon" },
		{ "Keywords", "Nintendo Switch Joy Con Cons JoyCon JoyCons Attach" },
		{ "ModuleRelativePath", "Public/JoyConDriverFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_AttachJoyCon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UJoyConDriverFunctionLibrary, nullptr, "AttachJoyCon", nullptr, nullptr, sizeof(JoyConDriverFunctionLibrary_eventAttachJoyCon_Parms), Z_Construct_UFunction_UJoyConDriverFunctionLibrary_AttachJoyCon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UJoyConDriverFunctionLibrary_AttachJoyCon_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UJoyConDriverFunctionLibrary_AttachJoyCon_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UJoyConDriverFunctionLibrary_AttachJoyCon_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UJoyConDriverFunctionLibrary_AttachJoyCon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UJoyConDriverFunctionLibrary_AttachJoyCon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UJoyConDriverFunctionLibrary_DetachJoyCon_Statics
	{
		struct JoyConDriverFunctionLibrary_eventDetachJoyCon_Parms
		{
			int32 ControllerIndex;
			bool Success;
		};
		static void NewProp_Success_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Success;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ControllerIndex;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UJoyConDriverFunctionLibrary_DetachJoyCon_Statics::NewProp_Success_SetBit(void* Obj)
	{
		((JoyConDriverFunctionLibrary_eventDetachJoyCon_Parms*)Obj)->Success = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_DetachJoyCon_Statics::NewProp_Success = { "Success", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(JoyConDriverFunctionLibrary_eventDetachJoyCon_Parms), &Z_Construct_UFunction_UJoyConDriverFunctionLibrary_DetachJoyCon_Statics::NewProp_Success_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_DetachJoyCon_Statics::NewProp_ControllerIndex = { "ControllerIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(JoyConDriverFunctionLibrary_eventDetachJoyCon_Parms, ControllerIndex), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJoyConDriverFunctionLibrary_DetachJoyCon_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJoyConDriverFunctionLibrary_DetachJoyCon_Statics::NewProp_Success,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJoyConDriverFunctionLibrary_DetachJoyCon_Statics::NewProp_ControllerIndex,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UJoyConDriverFunctionLibrary_DetachJoyCon_Statics::Function_MetaDataParams[] = {
		{ "Category", "JoyCon" },
		{ "Keywords", "Nintendo Switch Joy Con Cons JoyCon JoyCons Detach" },
		{ "ModuleRelativePath", "Public/JoyConDriverFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_DetachJoyCon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UJoyConDriverFunctionLibrary, nullptr, "DetachJoyCon", nullptr, nullptr, sizeof(JoyConDriverFunctionLibrary_eventDetachJoyCon_Parms), Z_Construct_UFunction_UJoyConDriverFunctionLibrary_DetachJoyCon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UJoyConDriverFunctionLibrary_DetachJoyCon_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UJoyConDriverFunctionLibrary_DetachJoyCon_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UJoyConDriverFunctionLibrary_DetachJoyCon_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UJoyConDriverFunctionLibrary_DetachJoyCon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UJoyConDriverFunctionLibrary_DetachJoyCon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConAccelerometer_Statics
	{
		struct JoyConDriverFunctionLibrary_eventGetJoyConAccelerometer_Parms
		{
			int32 ControllerIndex;
			bool Success;
			FVector Accelerometer;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Accelerometer;
		static void NewProp_Success_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Success;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ControllerIndex;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConAccelerometer_Statics::NewProp_Accelerometer = { "Accelerometer", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(JoyConDriverFunctionLibrary_eventGetJoyConAccelerometer_Parms, Accelerometer), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConAccelerometer_Statics::NewProp_Success_SetBit(void* Obj)
	{
		((JoyConDriverFunctionLibrary_eventGetJoyConAccelerometer_Parms*)Obj)->Success = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConAccelerometer_Statics::NewProp_Success = { "Success", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(JoyConDriverFunctionLibrary_eventGetJoyConAccelerometer_Parms), &Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConAccelerometer_Statics::NewProp_Success_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConAccelerometer_Statics::NewProp_ControllerIndex = { "ControllerIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(JoyConDriverFunctionLibrary_eventGetJoyConAccelerometer_Parms, ControllerIndex), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConAccelerometer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConAccelerometer_Statics::NewProp_Accelerometer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConAccelerometer_Statics::NewProp_Success,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConAccelerometer_Statics::NewProp_ControllerIndex,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConAccelerometer_Statics::Function_MetaDataParams[] = {
		{ "Category", "JoyCon" },
		{ "Keywords", "Nintendo Switch Joy Con Cons JoyCon JoyCons Accelerometer" },
		{ "ModuleRelativePath", "Public/JoyConDriverFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConAccelerometer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UJoyConDriverFunctionLibrary, nullptr, "GetJoyConAccelerometer", nullptr, nullptr, sizeof(JoyConDriverFunctionLibrary_eventGetJoyConAccelerometer_Parms), Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConAccelerometer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConAccelerometer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConAccelerometer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConAccelerometer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConAccelerometer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConAccelerometer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConGyroscope_Statics
	{
		struct JoyConDriverFunctionLibrary_eventGetJoyConGyroscope_Parms
		{
			int32 ControllerIndex;
			bool Success;
			FVector Gyroscope;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Gyroscope;
		static void NewProp_Success_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Success;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ControllerIndex;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConGyroscope_Statics::NewProp_Gyroscope = { "Gyroscope", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(JoyConDriverFunctionLibrary_eventGetJoyConGyroscope_Parms, Gyroscope), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConGyroscope_Statics::NewProp_Success_SetBit(void* Obj)
	{
		((JoyConDriverFunctionLibrary_eventGetJoyConGyroscope_Parms*)Obj)->Success = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConGyroscope_Statics::NewProp_Success = { "Success", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(JoyConDriverFunctionLibrary_eventGetJoyConGyroscope_Parms), &Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConGyroscope_Statics::NewProp_Success_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConGyroscope_Statics::NewProp_ControllerIndex = { "ControllerIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(JoyConDriverFunctionLibrary_eventGetJoyConGyroscope_Parms, ControllerIndex), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConGyroscope_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConGyroscope_Statics::NewProp_Gyroscope,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConGyroscope_Statics::NewProp_Success,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConGyroscope_Statics::NewProp_ControllerIndex,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConGyroscope_Statics::Function_MetaDataParams[] = {
		{ "Category", "JoyCon" },
		{ "Keywords", "Nintendo Switch Joy Con Cons JoyCon JoyCons Gyroscope" },
		{ "ModuleRelativePath", "Public/JoyConDriverFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConGyroscope_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UJoyConDriverFunctionLibrary, nullptr, "GetJoyConGyroscope", nullptr, nullptr, sizeof(JoyConDriverFunctionLibrary_eventGetJoyConGyroscope_Parms), Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConGyroscope_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConGyroscope_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConGyroscope_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConGyroscope_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConGyroscope()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConGyroscope_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConVector_Statics
	{
		struct JoyConDriverFunctionLibrary_eventGetJoyConVector_Parms
		{
			int32 ControllerIndex;
			bool Success;
			FRotator Vector;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Vector;
		static void NewProp_Success_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Success;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ControllerIndex;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConVector_Statics::NewProp_Vector = { "Vector", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(JoyConDriverFunctionLibrary_eventGetJoyConVector_Parms, Vector), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConVector_Statics::NewProp_Success_SetBit(void* Obj)
	{
		((JoyConDriverFunctionLibrary_eventGetJoyConVector_Parms*)Obj)->Success = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConVector_Statics::NewProp_Success = { "Success", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(JoyConDriverFunctionLibrary_eventGetJoyConVector_Parms), &Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConVector_Statics::NewProp_Success_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConVector_Statics::NewProp_ControllerIndex = { "ControllerIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(JoyConDriverFunctionLibrary_eventGetJoyConVector_Parms, ControllerIndex), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConVector_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConVector_Statics::NewProp_Vector,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConVector_Statics::NewProp_Success,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConVector_Statics::NewProp_ControllerIndex,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConVector_Statics::Function_MetaDataParams[] = {
		{ "Category", "JoyCon" },
		{ "Keywords", "Nintendo Switch Joy Con Cons JoyCon JoyCons Gyroscope" },
		{ "ModuleRelativePath", "Public/JoyConDriverFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConVector_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UJoyConDriverFunctionLibrary, nullptr, "GetJoyConVector", nullptr, nullptr, sizeof(JoyConDriverFunctionLibrary_eventGetJoyConVector_Parms), Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConVector_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConVector_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConVector_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConVector_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConVector()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConVector_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics
	{
		struct JoyConDriverFunctionLibrary_eventSearchForJoyCons_Parms
		{
			TArray<FJoyConInformation> JoyCons;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_JoyCons;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_JoyCons_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics::NewProp_JoyCons = { "JoyCons", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(JoyConDriverFunctionLibrary_eventSearchForJoyCons_Parms, JoyCons), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics::NewProp_JoyCons_Inner = { "JoyCons", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FJoyConInformation, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics::NewProp_JoyCons,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics::NewProp_JoyCons_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics::Function_MetaDataParams[] = {
		{ "Category", "JoyCon" },
		{ "Keywords", "Nintendo Switch Joy Con Cons JoyCon JoyCons Search" },
		{ "ModuleRelativePath", "Public/JoyConDriverFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UJoyConDriverFunctionLibrary, nullptr, "SearchForJoyCons", nullptr, nullptr, sizeof(JoyConDriverFunctionLibrary_eventSearchForJoyCons_Parms), Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons_Statics::Function_MetaDataParams)) };
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
		{ &Z_Construct_UFunction_UJoyConDriverFunctionLibrary_AttachJoyCon, "AttachJoyCon" }, // 3764357400
		{ &Z_Construct_UFunction_UJoyConDriverFunctionLibrary_DetachJoyCon, "DetachJoyCon" }, // 4280147407
		{ &Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConAccelerometer, "GetJoyConAccelerometer" }, // 3672024749
		{ &Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConGyroscope, "GetJoyConGyroscope" }, // 2644063629
		{ &Z_Construct_UFunction_UJoyConDriverFunctionLibrary_GetJoyConVector, "GetJoyConVector" }, // 3831142025
		{ &Z_Construct_UFunction_UJoyConDriverFunctionLibrary_SearchForJoyCons, "SearchForJoyCons" }, // 102983304
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UJoyConDriverFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
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
	IMPLEMENT_CLASS(UJoyConDriverFunctionLibrary, 2439205426);
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
