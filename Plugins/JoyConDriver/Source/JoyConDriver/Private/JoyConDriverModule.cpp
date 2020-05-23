// Fill out your copyright notice in the Description page of Project Settings.


#include "JoyConDriverModule.h"

#include "JoyConInput.h"

#define LOCTEXT_NAMESPACE "JoyConDriver"

void FJoyConDriverModule::StartupModule() {
	IInputDeviceModule::StartupModule();
	JoyConDriver::FJoyConInput::PreInit();
}

TArray<FJoyConInformation>* FJoyConDriverModule::SearchForJoyCons() const {
	return JoyConInputDevice.Pin()->SearchJoyCons();
}

bool FJoyConDriverModule::AttachJoyCon(const FJoyConInformation JoyConInformation) const {
	return JoyConInputDevice.Pin()->AttachJoyCon(JoyConInformation);
}

bool FJoyConDriverModule::DetachJoyCon(const FJoyConInformation JoyConInformation) const {
	return JoyConInputDevice.Pin()->DetachJoyCon(JoyConInformation);
}

TSharedPtr<class IInputDevice> FJoyConDriverModule::CreateInputDevice(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler) {
	TSharedPtr<JoyConDriver::FJoyConInput> InputDevice(new JoyConDriver::FJoyConInput(InMessageHandler));
	JoyConInputDevice = InputDevice;
	return InputDevice;
}

IMPLEMENT_MODULE(FJoyConDriverModule, JoyConDriver)

#undef LOCTEXT_NAMESPACE