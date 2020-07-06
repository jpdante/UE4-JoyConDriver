// Fill out your copyright notice in the Description page of Project Settings.


#include "JoyConDriverModule.h"

#include "JoyConInput.h"

#define LOCTEXT_NAMESPACE "JoyConDriver"

void FJoyConDriverModule::StartupModule() {
	IInputDeviceModule::StartupModule();
	FJoyConInput::PreInit();
}

TArray<FJoyConInformation>* FJoyConDriverModule::SearchForJoyCons() const {
	return JoyConInputDevice.Pin()->SearchJoyCons();
}

TArray<FJoyConInformation>* FJoyConDriverModule::GetAttachedJoyCons() const {
	return JoyConInputDevice.Pin()->GetAttachedJoyCons();
}

TArray<FJoyConInformation>* FJoyConDriverModule::GetConnectedJoyCons() const {
	return JoyConInputDevice.Pin()->GetConnectedJoyCons();
}

bool FJoyConDriverModule::ConnectJoyCon(const FJoyConInformation JoyConInformation, int& ControllerIndex) const {
	return JoyConInputDevice.Pin()->ConnectJoyCon(JoyConInformation, ControllerIndex);
}

bool FJoyConDriverModule::AttachJoyCon(const int ControllerIndex, const int GripIndex) const {
	return JoyConInputDevice.Pin()->AttachJoyCon(ControllerIndex, GripIndex);
}

bool FJoyConDriverModule::DisconnectJoyCon(const int ControllerIndex) const {
	return JoyConInputDevice.Pin()->DisconnectJoyCon(ControllerIndex);
}

bool FJoyConDriverModule::DetachJoyCon(const int ControllerIndex) const {
	return JoyConInputDevice.Pin()->DetachJoyCon(ControllerIndex);
}

bool FJoyConDriverModule::GetJoyConAccelerometer(const int ControllerIndex, FVector& Out) const {
	return JoyConInputDevice.Pin()->GetJoyConAccelerometer(ControllerIndex, Out);
}

bool FJoyConDriverModule::GetJoyConGyroscope(const int ControllerIndex, FVector& Out) const {
	return JoyConInputDevice.Pin()->GetJoyConGyroscope(ControllerIndex, Out);
}

bool FJoyConDriverModule::GetJoyConVector(const int ControllerIndex, FRotator& Out) const {
	return JoyConInputDevice.Pin()->GetJoyConVector(ControllerIndex, Out);
}

bool FJoyConDriverModule::ReCenterJoyCon(const int ControllerIndex) const {
	return JoyConInputDevice.Pin()->ReCenterJoyCon(ControllerIndex);
}

bool FJoyConDriverModule::SetJoyConFilterCoefficient(const int ControllerIndex, const float Coefficient) const {
	return JoyConInputDevice.Pin()->SetJoyConFilterCoefficient(ControllerIndex, Coefficient);
}

bool FJoyConDriverModule::SetJoyConGripMode(const int GripIndex, const uint8 GripMode) const {
	return JoyConInputDevice.Pin()->SetJoyConGripMode(GripIndex, static_cast<EGripMode>(GripMode));
}

TSharedPtr<class IInputDevice> FJoyConDriverModule::CreateInputDevice(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler) {
	TSharedPtr<FJoyConInput> InputDevice(new FJoyConInput(InMessageHandler));
	JoyConInputDevice = InputDevice;
	return InputDevice;
}

IMPLEMENT_MODULE(FJoyConDriverModule, JoyConDriver)

#undef LOCTEXT_NAMESPACE