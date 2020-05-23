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

void UJoyConDriverFunctionLibrary::AttachJoyCon(const FJoyConInformation JoyConInformation, bool& Success) {
	const FJoyConDriverModule* JoyConInputApi = GetJoyConControllerAPI();
	if (JoyConInputApi == nullptr) {
		Success = false;
	} else {
		Success = JoyConInputApi->AttachJoyCon(JoyConInformation);
	}
}

void UJoyConDriverFunctionLibrary::SearchForJoyCons(TArray<FJoyConInformation>& JoyCons) {
	const FJoyConDriverModule* JoyConInputApi = GetJoyConControllerAPI();
	if (JoyConInputApi == nullptr) {
		JoyCons = TArray<FJoyConInformation>();
	} else {
		TArray<FJoyConInformation>* Data = JoyConInputApi->SearchForJoyCons();
		if(Data == nullptr) {
			JoyCons = TArray<FJoyConInformation>();
		}
		const TArray<FJoyConInformation> ArrayFrom = *Data;
		JoyCons = ArrayFrom;
	}
}

void UJoyConDriverFunctionLibrary::DetachJoyCon(const FJoyConInformation JoyConInformation, bool& Success) {
	const FJoyConDriverModule* JoyConInputApi = GetJoyConControllerAPI();
	if (JoyConInputApi == nullptr) {
		Success = false;
	} else {
		Success = JoyConInputApi->DetachJoyCon(JoyConInformation);
	}
}