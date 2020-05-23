// Fill out your copyright notice in the Description page of Project Settings.

#include "JoyConInput.h"

#include "hidapi.h"
#include "Engine/Engine.h"
#include "Misc/CoreDelegates.h"
#include "Misc/ConfigCacheIni.h"

JoyConDriver::FJoyConInput::FJoyConInput(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler) : MessageHandler(InMessageHandler) {
	IModularFeatures::Get().RegisterModularFeature(GetModularFeatureName(), this);
	if (hid_init() == 0) HidInitialized = true;
	else {
		HidInitialized = false;
		UE_LOG(LogTemp, Fatal, TEXT("HIDAPI failed to initialize"));
	}
	UE_LOG(LogTemp, Log, TEXT("JoyConDriver is initialized"));
}

JoyConDriver::FJoyConInput::~FJoyConInput() {
	IModularFeatures::Get().UnregisterModularFeature(GetModularFeatureName(), this);
	if (hid_exit() == 0) HidInitialized = false;
	else {
		HidInitialized = true;
		UE_LOG(LogTemp, Fatal, TEXT("HIDAPI failed to uninitialize"));
	}
	UE_LOG(LogTemp, Log, TEXT("JoyConDriver is uninitialized"));
}

void JoyConDriver::FJoyConInput::PreInit() {
	// Load the config, even if we failed to initialize a controller
	LoadConfig();
}

void JoyConDriver::FJoyConInput::LoadConfig() {
	
}

TArray<FJoyConInformation>* JoyConDriver::FJoyConInput::SearchJoyCons() {
	TArray<FJoyConInformation>* Data = new TArray<FJoyConInformation>();
	if (!HidInitialized) return Data;
	hid_device_info* Devices = hid_enumerate(0x57e, 0x0);
	if (Devices == nullptr) {
		hid_free_enumeration(Devices);
		Devices = hid_enumerate(0x057e, 0x0);
		if (Devices == nullptr) {
			hid_free_enumeration(Devices);
			return Data;
		}
	}
	hid_device_info* Device = Devices;
	while (Device != nullptr) {
		if (Device->product_id == 0x2006 || Device->product_id == 0x2007) {
			bool IsLeft = false;
			if (Device->product_id == 0x2006) {
				IsLeft = true;
			} else if (Device->product_id == 0x2007) {
				IsLeft = false;
			}
			int NextControllerId = 0;
			bool IsConnected = false;
			FString SerialNumber(Device->serial_number);
			FString BluetoothPath(Device->path);
			if(Controllers.Num() > 0) {
				NextControllerId = Controllers.Num() - 1;
				for (FJoyConController* Controller : Controllers) {
					if(Controller->SerialNumber.Equals(SerialNumber) && Controller->BluetoothPath.Equals(BluetoothPath)) {
						IsConnected = true;
						break;
					}
				}
			}
			const FJoyConInformation JoyConInformation(
				Device->product_id, 
				Device->vendor_id, 
				Device->interface_number, 
				Device->release_number,
				FString(Device->manufacturer_string),
				FString(Device->path),
				FString(Device->product_string),
				FString(Device->serial_number),
				NextControllerId,
				Device->usage,
				Device->usage_page,
				IsLeft,
				IsConnected
			);
			Data->Add(JoyConInformation);
		}
		Device = Device->next;
	}
	hid_free_enumeration(Devices);
	return Data;
}

bool JoyConDriver::FJoyConInput::AttachJoyCon(FJoyConInformation JoyConInformation) {
	if (!HidInitialized) return false;
	if (JoyConInformation.IsConnected) return false;
	char* Path = TCHAR_TO_ANSI(*JoyConInformation.BluetoothPath);
	hid_device* Handle = hid_open_path(Path);
	hid_set_nonblocking(Handle, 1);
	FJoyConController* Controller = new FJoyConController(Handle, JoyConInformation.SerialNumber, JoyConInformation.BluetoothPath, true, true, 0.05f, JoyConInformation.IsLeft);
	Controllers.Add(Controller);
	uint8 Leds = 0x0;
	Leds |= static_cast<uint8>(0x1 << 0);
	Controller->Attach(Leds);
	return true;
}

bool JoyConDriver::FJoyConInput::DetachJoyCon(const FJoyConInformation JoyConInformation) {
	if (!HidInitialized) return false;
	FJoyConController* TempController = nullptr;
	for (FJoyConController* Controller : Controllers) {
		if (Controller->SerialNumber.Equals(JoyConInformation.SerialNumber) && Controller->BluetoothPath.Equals(JoyConInformation.BluetoothPath)) {
			TempController = Controller;
			break;
		}
	}
	if (TempController == nullptr) return false;
	TempController->Detach();
	Controllers.Remove(TempController);
	return true;
}

bool JoyConDriver::FJoyConInput::GetJoyConAccelerometer(const FJoyConInformation JoyConInformation, FVector& Out) {
	if (!HidInitialized) return false;
	FJoyConController* TempController = nullptr;
	for (FJoyConController* Controller : Controllers) {
		if (Controller->SerialNumber.Equals(JoyConInformation.SerialNumber) && Controller->BluetoothPath.Equals(JoyConInformation.BluetoothPath)) {
			TempController = Controller;
			break;
		}
	}
	if (TempController == nullptr) {
		Out = FVector::ZeroVector;
		return false;
	}
	Out = TempController->GetAccelerometer();
	return true;
}

bool JoyConDriver::FJoyConInput::GetJoyConGyroscope(const FJoyConInformation JoyConInformation, FVector& Out) {
	if (!HidInitialized) return false;
	FJoyConController* TempController = nullptr;
	for (FJoyConController* Controller : Controllers) {
		if (Controller->SerialNumber.Equals(JoyConInformation.SerialNumber) && Controller->BluetoothPath.Equals(JoyConInformation.BluetoothPath)) {
			TempController = Controller;
			break;
		}
	}
	if (TempController == nullptr) {
		Out = FVector::ZeroVector;
		return false;
	}
	Out = TempController->GetGyroscope();
	return true;
}

bool JoyConDriver::FJoyConInput::GetJoyConVector(const FJoyConInformation JoyConInformation, FRotator& Out) {
	if (!HidInitialized) return false;
	FJoyConController* TempController = nullptr;
	for (FJoyConController* Controller : Controllers) {
		if (Controller->SerialNumber.Equals(JoyConInformation.SerialNumber) && Controller->BluetoothPath.Equals(JoyConInformation.BluetoothPath)) {
			TempController = Controller;
			break;
		}
	}
	if (TempController == nullptr) {
		Out = FRotator::ZeroRotator;
		return false;
	}
	Out = TempController->GetVector();
	return true;
}

void JoyConDriver::FJoyConInput::Tick(float DeltaTime) {
	for (FJoyConController* Controller : Controllers) {
		Controller->Update();
		const FVector Gyroscope = Controller->GetGyroscope();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Update Gyroscope: %f %f %f"), Gyroscope.X, Gyroscope.Y, Gyroscope.Z));
	}
}

void JoyConDriver::FJoyConInput::SendControllerEvents() {
	for(FJoyConController* Controller : Controllers) {
		Controller->Pool();
	}
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