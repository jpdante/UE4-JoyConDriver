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

bool FJoyConDriverModule::AttachJoyCon(const FJoyConInformation JoyConInformation, int& ControllerIndex) const {
	return JoyConInputDevice.Pin()->AttachJoyCon(JoyConInformation, ControllerIndex);
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

TSharedPtr<class IInputDevice> FJoyConDriverModule::CreateInputDevice(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler) {
	TSharedPtr<FJoyConInput> InputDevice(new FJoyConInput(InMessageHandler));
	JoyConInputDevice = InputDevice;
	return InputDevice;
}

IMPLEMENT_MODULE(FJoyConDriverModule, JoyConDriver)

#undef LOCTEXT_NAMESPACE