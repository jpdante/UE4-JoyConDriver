// Fill out your copyright notice in the Description page of Project Settings.


#include "JoyConDriverModule.h"

#include "JoyConInput.h"

#define LOCTEXT_NAMESPACE "JoyConDriver"

void FJoyConDriverModule::StartupModule() {
	IInputDeviceModule::StartupModule();
	FJoyConInput::PreInit();
}

TArray<FJoyConInformation>* FJoyConDriverModule::SearchForJoyCons() const {
	if (!JoyConInputDevice.IsValid()) return new TArray<FJoyConInformation>;;
	return JoyConInputDevice.Pin()->SearchJoyCons();
}

TArray<FJoyConInformation>* FJoyConDriverModule::GetAttachedJoyCons() const {
	if (!JoyConInputDevice.IsValid()) return new TArray<FJoyConInformation>;;
	return JoyConInputDevice.Pin()->GetAttachedJoyCons();
}

TArray<FJoyConInformation>* FJoyConDriverModule::GetConnectedJoyCons() const {
	if (!JoyConInputDevice.IsValid()) return new TArray<FJoyConInformation>;
	return JoyConInputDevice.Pin()->GetConnectedJoyCons();
}

bool FJoyConDriverModule::ResumeJoyConConnection() const {
	if (!JoyConInputDevice.IsValid()) return false;
	return JoyConInputDevice.Pin()->ResumeJoyConConnection();
}

bool FJoyConDriverModule::ConnectJoyCon(const FJoyConInformation JoyConInformation, const bool UseImu, const bool UseLocalize, const float Alpha, int& ControllerId) const {
	if (!JoyConInputDevice.IsValid()) return false;
	return JoyConInputDevice.Pin()->ConnectJoyCon(JoyConInformation, UseImu, UseLocalize, Alpha, ControllerId);
}

bool FJoyConDriverModule::AttachJoyCon(const int ControllerId, const int GripIndex) const {
	if (!JoyConInputDevice.IsValid()) return false;
	return JoyConInputDevice.Pin()->AttachJoyCon(ControllerId, GripIndex);
}

bool FJoyConDriverModule::DisconnectJoyCon(const int ControllerId) const {
	if (!JoyConInputDevice.IsValid()) return false;
	return JoyConInputDevice.Pin()->DisconnectJoyCon(ControllerId);
}

bool FJoyConDriverModule::DetachJoyCon(const int ControllerId) const {
	if (!JoyConInputDevice.IsValid()) return false;
	return JoyConInputDevice.Pin()->DetachJoyCon(ControllerId);
}

bool FJoyConDriverModule::GetJoyConAccelerometer(const int ControllerId, FVector& Out) const {
	if (!JoyConInputDevice.IsValid()) return false;
	return JoyConInputDevice.Pin()->GetJoyConAccelerometer(ControllerId, Out);
}

bool FJoyConDriverModule::GetJoyConGyroscope(const int ControllerId, FVector& Out) const {
	if (!JoyConInputDevice.IsValid()) return false;
	return JoyConInputDevice.Pin()->GetJoyConGyroscope(ControllerId, Out);
}

bool FJoyConDriverModule::GetJoyConVector(const int ControllerId, FRotator& Out) const {
	if (!JoyConInputDevice.IsValid()) return false;
	return JoyConInputDevice.Pin()->GetJoyConVector(ControllerId, Out);
}

bool FJoyConDriverModule::ReCenterJoyCon(const int ControllerId) const {
	if (!JoyConInputDevice.IsValid()) return false;
	return JoyConInputDevice.Pin()->ReCenterJoyCon(ControllerId);
}

bool FJoyConDriverModule::SetJoyConFilterCoefficient(const int ControllerId, const float Coefficient) const {
	if (!JoyConInputDevice.IsValid()) return false;
	return JoyConInputDevice.Pin()->SetJoyConFilterCoefficient(ControllerId, Coefficient);
}

bool FJoyConDriverModule::SetJoyConGripMode(const int GripIndex, const uint8 GripMode) const {
	if (!JoyConInputDevice.IsValid()) return false;
	return JoyConInputDevice.Pin()->SetJoyConGripMode(GripIndex, static_cast<EGripMode>(GripMode));
}

bool FJoyConDriverModule::SetJoyConRumble(const int ControllerId, const float LowFrequency, const float HighFrequency, const float Amplitude, const int Time) const {
	if (!JoyConInputDevice.IsValid()) return false;
	return JoyConInputDevice.Pin()->SetJoyConRumble(ControllerId, LowFrequency, HighFrequency, Amplitude, Time);
}

TSharedPtr<class IInputDevice> FJoyConDriverModule::CreateInputDevice(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler) {
	TSharedPtr<FJoyConInput> InputDevice(new FJoyConInput(InMessageHandler));
	JoyConInputDevice = InputDevice;
	return InputDevice;
}

IMPLEMENT_MODULE(FJoyConDriverModule, JoyConDriver)

#undef LOCTEXT_NAMESPACE