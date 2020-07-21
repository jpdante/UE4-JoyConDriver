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

void UJoyConDriverFunctionLibrary::ConnectJoyCon(const FJoyConInformation JoyConInformation, const bool UseImu, const bool UseLocalize, bool& Success, int& ControllerIndex, const float Alpha) {
	const FJoyConDriverModule* JoyConInputApi = GetJoyConControllerAPI();
	if (JoyConInputApi == nullptr) {
		Success = false;
	} else {
		Success = JoyConInputApi->ConnectJoyCon(JoyConInformation, UseImu, UseLocalize, Alpha, ControllerIndex);
	}
}

void UJoyConDriverFunctionLibrary::AttachJoyCon(const int ControllerIndex, const int GripIndex, bool& Success) {
	const FJoyConDriverModule* JoyConInputApi = GetJoyConControllerAPI();
	if (JoyConInputApi == nullptr) {
		Success = false;
	} else {
		Success = JoyConInputApi->AttachJoyCon(ControllerIndex, GripIndex);
	}
}

void UJoyConDriverFunctionLibrary::DisconnectJoyCon(const int ControllerIndex, bool& Success) {
	const FJoyConDriverModule* JoyConInputApi = GetJoyConControllerAPI();
	if (JoyConInputApi == nullptr) {
		Success = false;
	} else {
		Success = JoyConInputApi->DisconnectJoyCon(ControllerIndex);
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

void UJoyConDriverFunctionLibrary::GetAttachedJoyCons(TArray<FJoyConInformation>& JoyCons) {
	const FJoyConDriverModule* JoyConInputApi = GetJoyConControllerAPI();
	if (JoyConInputApi == nullptr) {
		JoyCons = TArray<FJoyConInformation>();
	} else {
		TArray<FJoyConInformation>* Data = JoyConInputApi->GetAttachedJoyCons();
		if (Data == nullptr) {
			JoyCons = TArray<FJoyConInformation>();
		}
		const TArray<FJoyConInformation> ArrayFrom = *Data;
		JoyCons = ArrayFrom;
	}
}

void UJoyConDriverFunctionLibrary::GetConnectedJoyCons(TArray<FJoyConInformation>& JoyCons) {
	const FJoyConDriverModule* JoyConInputApi = GetJoyConControllerAPI();
	if (JoyConInputApi == nullptr) {
		JoyCons = TArray<FJoyConInformation>();
	} else {
		TArray<FJoyConInformation>* Data = JoyConInputApi->GetConnectedJoyCons();
		if (Data == nullptr) {
			JoyCons = TArray<FJoyConInformation>();
		}
		const TArray<FJoyConInformation> ArrayFrom = *Data;
		JoyCons = ArrayFrom;
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

void UJoyConDriverFunctionLibrary::ReCenterJoyCon(const int ControllerIndex, bool& Success) {
	const FJoyConDriverModule* JoyConInputApi = GetJoyConControllerAPI();
	if (JoyConInputApi == nullptr) {
		Success = false;
	} else {
		Success = JoyConInputApi->ReCenterJoyCon(ControllerIndex);
	}
}

void UJoyConDriverFunctionLibrary::SetJoyConFilterCoefficient(const int ControllerIndex, const float Coefficient, bool& Success) {
	const FJoyConDriverModule* JoyConInputApi = GetJoyConControllerAPI();
	if (JoyConInputApi == nullptr) {
		Success = false;
	} else {
		Success = JoyConInputApi->SetJoyConFilterCoefficient(ControllerIndex, Coefficient);
	}
}

void UJoyConDriverFunctionLibrary::SetJoyConGripMode(const int GripIndex, const EGripMode GripMode, bool& Success) {
	const FJoyConDriverModule* JoyConInputApi = GetJoyConControllerAPI();
	if (JoyConInputApi == nullptr) {
		Success = false;
	} else {
		Success = JoyConInputApi->SetJoyConGripMode(GripIndex, static_cast<uint8>(GripMode));
	}
}
