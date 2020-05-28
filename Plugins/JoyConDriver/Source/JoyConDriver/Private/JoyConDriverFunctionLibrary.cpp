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

void UJoyConDriverFunctionLibrary::AttachJoyCon(const FJoyConInformation JoyConInformation, bool& Success, int& ControllerIndex) {
	const FJoyConDriverModule* JoyConInputApi = GetJoyConControllerAPI();
	if (JoyConInputApi == nullptr) {
		Success = false;
	} else {
		Success = JoyConInputApi->AttachJoyCon(JoyConInformation, ControllerIndex);
	}
}

void UJoyConDriverFunctionLibrary::SearchForJoyCons(TArray<FJoyConInformation>& JoyCons) {
	const FJoyConDriverModule* JoyConInputApi = GetJoyConControllerAPI();
	if (JoyConInputApi == nullptr) {
		JoyCons = TArray<FJoyConInformation>();
	} else {
		TArray<FJoyConInformation>* Data = JoyConInputApi->SearchForJoyCons();
		if (Data == nullptr) {
			JoyCons = TArray<FJoyConInformation>();
		}
		const TArray<FJoyConInformation> ArrayFrom = *Data;
		JoyCons = ArrayFrom;
	}
}

void UJoyConDriverFunctionLibrary::DetachJoyCon(const int ControllerIndex, bool& Success) {
	const FJoyConDriverModule* JoyConInputApi = GetJoyConControllerAPI();
	if (JoyConInputApi == nullptr) {
		Success = false;
	} else {
		Success = JoyConInputApi->DetachJoyCon(ControllerIndex);
	}
}

void UJoyConDriverFunctionLibrary::GetJoyConAccelerometer(const int ControllerIndex, bool& Success, FVector& Accelerometer) {
	const FJoyConDriverModule* JoyConInputApi = GetJoyConControllerAPI();
	if (JoyConInputApi == nullptr) {
		Success = false;
		Accelerometer = FVector::ZeroVector;
	} else {
		Success = JoyConInputApi->GetJoyConAccelerometer(ControllerIndex, Accelerometer);
	}
}

void UJoyConDriverFunctionLibrary::GetJoyConGyroscope(const int ControllerIndex, bool& Success, FVector& Gyroscope) {
	const FJoyConDriverModule* JoyConInputApi = GetJoyConControllerAPI();
	if (JoyConInputApi == nullptr) {
		Success = false;
		Gyroscope = FVector::ZeroVector;
	} else {
		Success = JoyConInputApi->GetJoyConGyroscope(ControllerIndex, Gyroscope);
	}
}

void UJoyConDriverFunctionLibrary::GetJoyConVector(const int ControllerIndex, bool& Success, FRotator& Vector) {
	const FJoyConDriverModule* JoyConInputApi = GetJoyConControllerAPI();
	if (JoyConInputApi == nullptr) {
		Success = false;
		Vector = FRotator::ZeroRotator;
	} else {
		Success = JoyConInputApi->GetJoyConVector(ControllerIndex, Vector);
	}
}