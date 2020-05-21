// Fill out your copyright notice in the Description page of Project Settings.


#include "JoyConDriverModule.h"

#include "JoyConInput.h"

#define LOCTEXT_NAMESPACE "SwitchController"

FJoyConDriverModule::FJoyConDriverModule() {
}

FJoyConDriverModule::~FJoyConDriverModule() {
}

void FJoyConDriverModule::StartupModule() {
}

TSharedPtr<class IInputDevice> FJoyConDriverModule::CreateInputDevice(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler) {
	TSharedPtr< FJoyConInput > InputDevice(new FJoyConInput(InMessageHandler));
	//JoyConInputDevice = InputDevice;
	return InputDevice;
}

IMPLEMENT_MODULE(FJoyConDriverModule, JoyConDriver)

#undef LOCTEXT_NAMESPACE