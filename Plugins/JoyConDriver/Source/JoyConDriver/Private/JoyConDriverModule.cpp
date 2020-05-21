// Fill out your copyright notice in the Description page of Project Settings.


#include "JoyConDriverModule.h"

#include "JoyConInput.h"

#define LOCTEXT_NAMESPACE "JoyConDriver"

void FJoyConDriverModule::StartupModule() {
	IInputDeviceModule::StartupModule();
	FJoyConInput::PreInit();
}

TSharedPtr<class IInputDevice> FJoyConDriverModule::CreateInputDevice(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler) {
	TSharedPtr<FJoyConInput > InputDevice(new FJoyConInput(InMessageHandler));
	JoyConInputDevice = InputDevice;
	return InputDevice;
}

uint32 FJoyConDriverModule::GetNumberOfControllers() const {
	const uint32 Count = JoyConInputDevice.Pin()->SearchForJoyCons();
	UE_LOG(LogTemp, Log, TEXT("JoyConDriver found some controllers"), Count);
	return Count;
}

bool FJoyConDriverModule::ConnectJoyCons() const {
	return JoyConInputDevice.Pin()->ConnectJoyCons();
}

bool FJoyConDriverModule::DisconnectJoyCons() const {
	return JoyConInputDevice.Pin()->DisconnectJoyCons();
}

IMPLEMENT_MODULE(FJoyConDriverModule, JoyConDriver)

#undef LOCTEXT_NAMESPACE