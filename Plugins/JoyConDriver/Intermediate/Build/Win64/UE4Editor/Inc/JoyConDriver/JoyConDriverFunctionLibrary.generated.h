// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FRotator;
struct FVector;
struct FJoyConInformation;
#ifdef JOYCONDRIVER_JoyConDriverFunctionLibrary_generated_h
#error "JoyConDriverFunctionLibrary.generated.h already included, missing '#pragma once' in JoyConDriverFunctionLibrary.h"
#endif
#define JOYCONDRIVER_JoyConDriverFunctionLibrary_generated_h

#define JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_15_SPARSE_DATA
#define JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetJoyConVector) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_ControllerIndex); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_STRUCT_REF(FRotator,Z_Param_Out_Vector); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UJoyConDriverFunctionLibrary::GetJoyConVector(Z_Param_ControllerIndex,Z_Param_Out_Success,Z_Param_Out_Vector); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetJoyConGyroscope) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_ControllerIndex); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Gyroscope); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UJoyConDriverFunctionLibrary::GetJoyConGyroscope(Z_Param_ControllerIndex,Z_Param_Out_Success,Z_Param_Out_Gyroscope); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetJoyConAccelerometer) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_ControllerIndex); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Accelerometer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UJoyConDriverFunctionLibrary::GetJoyConAccelerometer(Z_Param_ControllerIndex,Z_Param_Out_Success,Z_Param_Out_Accelerometer); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDetachJoyCon) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_ControllerIndex); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UJoyConDriverFunctionLibrary::DetachJoyCon(Z_Param_ControllerIndex,Z_Param_Out_Success); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSearchForJoyCons) \
	{ \
		P_GET_TARRAY_REF(FJoyConInformation,Z_Param_Out_JoyCons); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UJoyConDriverFunctionLibrary::SearchForJoyCons(Z_Param_Out_JoyCons); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAttachJoyCon) \
	{ \
		P_GET_STRUCT(FJoyConInformation,Z_Param_JoyConInformation); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_ControllerIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UJoyConDriverFunctionLibrary::AttachJoyCon(Z_Param_JoyConInformation,Z_Param_Out_Success,Z_Param_Out_ControllerIndex); \
		P_NATIVE_END; \
	}


#define JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetJoyConVector) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_ControllerIndex); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_STRUCT_REF(FRotator,Z_Param_Out_Vector); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UJoyConDriverFunctionLibrary::GetJoyConVector(Z_Param_ControllerIndex,Z_Param_Out_Success,Z_Param_Out_Vector); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetJoyConGyroscope) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_ControllerIndex); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Gyroscope); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UJoyConDriverFunctionLibrary::GetJoyConGyroscope(Z_Param_ControllerIndex,Z_Param_Out_Success,Z_Param_Out_Gyroscope); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetJoyConAccelerometer) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_ControllerIndex); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Accelerometer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UJoyConDriverFunctionLibrary::GetJoyConAccelerometer(Z_Param_ControllerIndex,Z_Param_Out_Success,Z_Param_Out_Accelerometer); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDetachJoyCon) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_ControllerIndex); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UJoyConDriverFunctionLibrary::DetachJoyCon(Z_Param_ControllerIndex,Z_Param_Out_Success); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSearchForJoyCons) \
	{ \
		P_GET_TARRAY_REF(FJoyConInformation,Z_Param_Out_JoyCons); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UJoyConDriverFunctionLibrary::SearchForJoyCons(Z_Param_Out_JoyCons); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAttachJoyCon) \
	{ \
		P_GET_STRUCT(FJoyConInformation,Z_Param_JoyConInformation); \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_ControllerIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UJoyConDriverFunctionLibrary::AttachJoyCon(Z_Param_JoyConInformation,Z_Param_Out_Success,Z_Param_Out_ControllerIndex); \
		P_NATIVE_END; \
	}


#define JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJoyConDriverFunctionLibrary(); \
	friend struct Z_Construct_UClass_UJoyConDriverFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UJoyConDriverFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/JoyConDriver"), NO_API) \
	DECLARE_SERIALIZER(UJoyConDriverFunctionLibrary)


#define JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUJoyConDriverFunctionLibrary(); \
	friend struct Z_Construct_UClass_UJoyConDriverFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UJoyConDriverFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/JoyConDriver"), NO_API) \
	DECLARE_SERIALIZER(UJoyConDriverFunctionLibrary)


#define JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJoyConDriverFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJoyConDriverFunctionLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJoyConDriverFunctionLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJoyConDriverFunctionLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UJoyConDriverFunctionLibrary(UJoyConDriverFunctionLibrary&&); \
	NO_API UJoyConDriverFunctionLibrary(const UJoyConDriverFunctionLibrary&); \
public:


#define JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJoyConDriverFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UJoyConDriverFunctionLibrary(UJoyConDriverFunctionLibrary&&); \
	NO_API UJoyConDriverFunctionLibrary(const UJoyConDriverFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJoyConDriverFunctionLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJoyConDriverFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJoyConDriverFunctionLibrary)


#define JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_15_PRIVATE_PROPERTY_OFFSET
#define JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_13_PROLOG
#define JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_15_PRIVATE_PROPERTY_OFFSET \
	JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_15_SPARSE_DATA \
	JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_15_RPC_WRAPPERS \
	JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_15_INCLASS \
	JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_15_PRIVATE_PROPERTY_OFFSET \
	JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_15_SPARSE_DATA \
	JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_15_INCLASS_NO_PURE_DECLS \
	JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> JOYCONDRIVER_API UClass* StaticClass<class UJoyConDriverFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
