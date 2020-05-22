// Fill out your copyright notice in the Description page of Project Settings.

#include "JoyConInput.h"

#include "Misc/CoreDelegates.h"
#include "Misc/ConfigCacheIni.h"

JoyConDriver::FJoyConInput::FJoyConInput(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler) : MessageHandler(InMessageHandler) {

}

JoyConDriver::FJoyConInput::~FJoyConInput() {

}

void JoyConDriver::FJoyConInput::PreInit() {
	// Load the config, even if we failed to initialize a controller
	LoadConfig();
}

void JoyConDriver::FJoyConInput::LoadConfig() {
	
}

void JoyConDriver::FJoyConInput::Tick(float DeltaTime) {

}

void JoyConDriver::FJoyConInput::SendControllerEvents() {
	/*if (Controller == nullptr) return;
	Controller->Pool();*/
}

void JoyConDriver::FJoyConInput::SetMessageHandler(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler) {
	MessageHandler = InMessageHandler;
}

bool JoyConDriver::FJoyConInput::Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar) {
	return false;
}

void JoyConDriver::FJoyConInput::SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value) {
}

void JoyConDriver::FJoyConInput::SetChannelValues(int32 ControllerId, const FForceFeedbackValues& Values) {
}

FName JoyConDriver::FJoyConInput::GetMotionControllerDeviceTypeName() const {
	const static FName DefaultName(TEXT("JoyConInputDevice"));
	return DefaultName;
}

bool JoyConDriver::FJoyConInput::GetControllerOrientationAndPosition(const int32 ControllerIndex, const EControllerHand DeviceHand, FRotator& OutOrientation, FVector& OutPosition, float WorldToMetersScale) const {
	return false;
}

ETrackingStatus JoyConDriver::FJoyConInput::GetControllerTrackingStatus(const int32 ControllerIndex, const EControllerHand DeviceHand) const {
	return ETrackingStatus::NotTracked;
}

void JoyConDriver::FJoyConInput::SetHapticFeedbackValues(int32 ControllerId, int32 Hand, const FHapticFeedbackValues& Values) {
}

void JoyConDriver::FJoyConInput::GetHapticFrequencyRange(float& MinFrequency, float& MaxFrequency) const {
	MinFrequency = 0.f;
	MaxFrequency = 1.f;
}

float JoyConDriver::FJoyConInput::GetHapticAmplitudeScale() const {
	return 1.f;
}