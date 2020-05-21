// Fill out your copyright notice in the Description page of Project Settings.

#include "JoyConInput.h"


#include "hidapi.h"
#include "Misc/CoreDelegates.h"
#include "Features/IModularFeatures.h"
#include "Misc/ConfigCacheIni.h"

FJoyConInput::FJoyConInput(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler) : MessageHandler(InMessageHandler) {
	IModularFeatures::Get().RegisterModularFeature(GetModularFeatureName(), this);
	if(hid_init() == 0) HidInitialized = true;
	else {
		HidInitialized = false;
		UE_LOG(LogTemp, Fatal, TEXT("HIDAPI failed to initialize"));
	}
	UE_LOG(LogTemp, Log, TEXT("JoyConDriver is initialized"));
}

FJoyConInput::~FJoyConInput() {
	IModularFeatures::Get().UnregisterModularFeature(GetModularFeatureName(), this);
	if (hid_exit() == 0) HidInitialized = false;
	else {
		HidInitialized = true;
		UE_LOG(LogTemp, Fatal, TEXT("HIDAPI failed to uninitialize"));
	}
	UE_LOG(LogTemp, Log, TEXT("JoyConDriver is uninitialized"));
}

void FJoyConInput::PreInit() {
	// Load the config, even if we failed to initialize a controller
	LoadConfig();

	
}

void FJoyConInput::LoadConfig() {
	
}

uint32 FJoyConInput::SearchForJoyCons() const {
	if (!HidInitialized) return 0;
	auto* Devices = hid_enumerate(0x57e, 0x0);
	if (Devices == nullptr) {
		hid_free_enumeration(Devices);
		Devices = hid_enumerate(0x057e, 0x0);
		if (Devices == nullptr) {
			hid_free_enumeration(Devices);
			return 0;
		}
	}
	auto* Device = Devices;
	uint32 Count = 0;
	while (Device != nullptr) {
		Count++;
		Device = Device->next;
	}
	hid_free_enumeration(Devices);
	return Count;
}

bool FJoyConInput::ConnectJoyCons() {
	if (!HidInitialized) return false;
	if (Controller != nullptr) return false;
	auto* Devices = hid_enumerate(0x57e, 0x0);
	if (Devices == nullptr) {
		hid_free_enumeration(Devices);
		Devices = hid_enumerate(0x057e, 0x0);
		if (Devices == nullptr) {
			hid_free_enumeration(Devices);
			return false;
		}
	}
	auto* Device = Devices;
	while (Device != nullptr) {
		if (Device->product_id == 0x2006 || Device->product_id == 0x2007) {
			auto IsLeft = false;
			if (Device->product_id == 0x2006) {
				UE_LOG(LogTemp, Log, TEXT("Left JoyCon detected!"));
				IsLeft = true;
			}
			else if (Device->product_id == 0x2007) {
				UE_LOG(LogTemp, Log, TEXT("Right JoyCon detected!"));
				IsLeft = false;
			}
			const auto Handle = hid_open_path(Device->path);
			hid_set_nonblocking(Handle, 1);
			Controller = new FJoyConController(Handle, true, true, 0.05f, IsLeft);
			break;
		}
		Device = Device->next;
	}
	hid_free_enumeration(Devices);
	/*for (auto i = 0; i < Controllers.Num(); i++) {
		uint8 Leds = 0x0;
		Leds |= static_cast<uint8>(0x1 << i);
		Controllers[i]->Attach(Leds);
	}*/
	uint8 Leds = 0x0;
	Leds |= static_cast<uint8>(0x1 << 0);
	Controller->Attach(Leds);
	return true;
}

bool FJoyConInput::DisconnectJoyCons() {
	if (!HidInitialized) return false;
	if (Controller == nullptr) return false;
	Controller->Detach();
	delete Controller;
	Controller = nullptr;
	return true;
}

void FJoyConInput::Tick(float DeltaTime) {
	if (Controller == nullptr) return;
	Controller->Update();
}

void FJoyConInput::SendControllerEvents() {
	if (Controller == nullptr) return;
	Controller->Pool();
}

void FJoyConInput::SetMessageHandler(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler) {
	MessageHandler = InMessageHandler;
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
	MinFrequency = 0.f;
	MaxFrequency = 1.f;
}

float FJoyConInput::GetHapticAmplitudeScale() const {
	return 1.f;
}
