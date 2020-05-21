// Fill out your copyright notice in the Description page of Project Settings.

#include "JoyConInput.h"

#include "Misc/CoreDelegates.h"
#include "Features/IModularFeatures.h"
#include "Misc/ConfigCacheIni.h"

FJoyConInput::FJoyConInput(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler) : MessageHandler(InMessageHandler) {

}

FJoyConInput::~FJoyConInput() {
}

void FJoyConInput::Tick(float DeltaTime) {
}

void FJoyConInput::SendControllerEvents() {
}

void FJoyConInput::SetMessageHandler(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler) {
}

bool FJoyConInput::Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar) {
	return false;
}

void FJoyConInput::SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value) {
}

void FJoyConInput::SetChannelValues(int32 ControllerId, const FForceFeedbackValues& values) {
}

FName FJoyConInput::GetMotionControllerDeviceTypeName() const {
	const static FName DefaultName(TEXT("JoyConInputDevice"));
	return DefaultName;
}

bool FJoyConInput::GetControllerOrientationAndPosition(const int32 ControllerIndex, const EControllerHand DeviceHand, FRotator& OutOrientation, FVector& OutPosition, float WorldToMetersScale) const {
	return false;
}

ETrackingStatus FJoyConInput::GetControllerTrackingStatus(const int32 ControllerIndex, const EControllerHand DeviceHand) const {
	return ETrackingStatus::NotTracked;
}

void FJoyConInput::SetHapticFeedbackValues(int32 ControllerId, int32 Hand, const FHapticFeedbackValues& Values) {
}

void FJoyConInput::GetHapticFrequencyRange(float& MinFrequency, float& MaxFrequency) const {
}

float FJoyConInput::GetHapticAmplitudeScale() const {
	return 0.0f;
}
