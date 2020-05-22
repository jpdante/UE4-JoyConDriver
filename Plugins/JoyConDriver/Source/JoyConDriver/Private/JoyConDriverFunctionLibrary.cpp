// Fill out your copyright notice in the Description page of Project Settings.


#include "JoyConDriverFunctionLibrary.h"

#include "JoyConDriverModule.h"
#include "Features/IModularFeatures.h"

FJoyConDriverModule* GetJoyConControllerAPI() {
	TArray<FJoyConDriverModule*> JoyConInputApis = IModularFeatures::Get().GetModularFeatureImplementations<FJoyConDriverModule>(FJoyConDriverModule::GetModularFeatureName());
	for (auto JoyConInputApi : JoyConInputApis) {
		if (JoyConInputApi != nullptr) {
			return JoyConInputApi;
		}
	}
	return nullptr;
}

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

void UJoyConDriverFunctionLibrary::SearchForJoyCons(bool& Success, int& Count) {
	const auto JoyConInputApi = GetJoyConControllerAPI();
	if (JoyConInputApi == nullptr) {
		Success = false;
	} else {
		try {
			//Count = JoyConInputApi->GetNumberOfControllers();
			Count = 0;
			Success = true;
		}
		catch (...) {
			Success = false;
		}
	}
}

void UJoyConDriverFunctionLibrary::DisconnectJoyCons(bool& Success) {
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
}