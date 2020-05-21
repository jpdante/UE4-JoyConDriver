// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef JOYCONDRIVER_JoyConDriverFunctionLibrary_generated_h
#error "JoyConDriverFunctionLibrary.generated.h already included, missing '#pragma once' in JoyConDriverFunctionLibrary.h"
#endif
#define JOYCONDRIVER_JoyConDriverFunctionLibrary_generated_h

#define JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_14_SPARSE_DATA
#define JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execDisconnectJoyCons) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UJoyConDriverFunctionLibrary::DisconnectJoyCons(Z_Param_Out_Success); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSearchForJoyCons) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Count); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UJoyConDriverFunctionLibrary::SearchForJoyCons(Z_Param_Out_Success,Z_Param_Out_Count); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConnectJoyCons) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UJoyConDriverFunctionLibrary::ConnectJoyCons(Z_Param_Out_Success); \
		P_NATIVE_END; \
	}


#define JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execDisconnectJoyCons) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UJoyConDriverFunctionLibrary::DisconnectJoyCons(Z_Param_Out_Success); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSearchForJoyCons) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Count); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UJoyConDriverFunctionLibrary::SearchForJoyCons(Z_Param_Out_Success,Z_Param_Out_Count); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConnectJoyCons) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_Success); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UJoyConDriverFunctionLibrary::ConnectJoyCons(Z_Param_Out_Success); \
		P_NATIVE_END; \
	}


#define JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJoyConDriverFunctionLibrary(); \
	friend struct Z_Construct_UClass_UJoyConDriverFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UJoyConDriverFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/JoyConDriver"), NO_API) \
	DECLARE_SERIALIZER(UJoyConDriverFunctionLibrary)


#define JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_14_INCLASS \
private: \
	static void StaticRegisterNativesUJoyConDriverFunctionLibrary(); \
	friend struct Z_Construct_UClass_UJoyConDriverFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UJoyConDriverFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/JoyConDriver"), NO_API) \
	DECLARE_SERIALIZER(UJoyConDriverFunctionLibrary)


#define JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_14_STANDARD_CONSTRUCTORS \
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


#define JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_14_ENHANCED_CONSTRUCTORS \
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


#define JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_14_PRIVATE_PROPERTY_OFFSET
#define JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_12_PROLOG
#define JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_14_PRIVATE_PROPERTY_OFFSET \
	JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_14_SPARSE_DATA \
	JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_14_RPC_WRAPPERS \
	JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_14_INCLASS \
	JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_14_PRIVATE_PROPERTY_OFFSET \
	JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_14_SPARSE_DATA \
	JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_14_INCLASS_NO_PURE_DECLS \
	JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> JOYCONDRIVER_API UClass* StaticClass<class UJoyConDriverFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID JoyConSample_Plugins_JoyConDriver_Source_JoyConDriver_Public_JoyConDriverFunctionLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
