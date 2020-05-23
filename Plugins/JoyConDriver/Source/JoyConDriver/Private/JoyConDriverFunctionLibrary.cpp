// Fill out your copyright notice in the Description page of Project Settings.


#include "JoyConDriverFunctionLibrary.h"

#include "JoyConDriverModule.h"
#include "Features/IModularFeatures.h"

FJoyConDriverModule* GetJoyConControllerAPI() {
	TArray<FJoyConDriverModule*> JoyConInputApis = IModularFeatures::Get().GetModularFeatureImplementations<FJoyConDriverModule>(FJoyConDriverModule::GetModularFeatureName());
	for (FJoyConDriverModule* JoyConInputApi : JoyConInputApis) {
		if (JoyConInputApi != nullptr) {
			return JoyConInputApi;
		}
	}
	return nullptr;
}

/*
void UJoyConDriverFunctionLibrary::ConnectJoyCons(bool &Success) {
	const auto JoyConInputApi = GetJoyConControllerAPI();
	if(JoyConInputApi == nullptr) {
		Success = false;
	} else {
		try	{
			//Success = JoyConInputApi->ConnectJoyCons();
			Success = true;
		} catch (...) {
			Success = false;
		}
	}
}
*/

TArray<FJoyConInformation> UJoyConDriverFunctionLibrary::SearchForJoyCons() {
	const FJoyConDriverModule* JoyConInputApi = GetJoyConControllerAPI();
	if (JoyConInputApi == nullptr) {
		return TArray<FJoyConInformation>();
	} else {
		TArray<FJoyConInformation>* Data = JoyConInputApi->SearchForJoyCons();
		if(Data == nullptr) {
			return TArray<FJoyConInformation>();
		}
		TArray<FJoyConInformation> ArrayFrom = *Data;
		return ArrayFrom;
	}
}

/*void UJoyConDriverFunctionLibrary::DisconnectJoyCons(bool& Success) {
	const auto JoyConInputApi = GetJoyConControllerAPI();
	if (JoyConInputApi == nullptr) {
		Success = false;
	} else {
		try {
			//Success = JoyConInputApi->DisconnectJoyCons();
			Success = true;
		}
		catch (...) {
			Success = false;
		}
	}
}*/