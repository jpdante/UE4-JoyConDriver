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
		if (Data == nullptr) {
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

void UJoyConDriverFunctionLibrary::GetJoyConAccelerometer(const FJoyConInformation JoyConInformation, bool& Success, FVector& Accelerometer) {
	const FJoyConDriverModule* JoyConInputApi = GetJoyConControllerAPI();
	if (JoyConInputApi == nullptr) {
		Success = false;
		Accelerometer = FVector::ZeroVector;
	} else {
		Success = JoyConInputApi->GetJoyConAccelerometer(JoyConInformation, Accelerometer);
	}
}

void UJoyConDriverFunctionLibrary::GetJoyConGyroscope(FJoyConInformation JoyConInformation, bool& Success, FVector& Gyroscope) {
	const FJoyConDriverModule* JoyConInputApi = GetJoyConControllerAPI();
	if (JoyConInputApi == nullptr) {
		Success = false;
		Gyroscope = FVector::ZeroVector;
	} else {
		Success = JoyConInputApi->GetJoyConGyroscope(JoyConInformation, Gyroscope);
	}
}

void UJoyConDriverFunctionLibrary::GetJoyConVector(FJoyConInformation JoyConInformation, bool& Success, FRotator& Vector) {
	const FJoyConDriverModule* JoyConInputApi = GetJoyConControllerAPI();
	if (JoyConInputApi == nullptr) {
		Success = false;
		Vector = FRotator::ZeroRotator;
	} else {
		Success = JoyConInputApi->GetJoyConVector(JoyConInformation, Vector);
	}
}
