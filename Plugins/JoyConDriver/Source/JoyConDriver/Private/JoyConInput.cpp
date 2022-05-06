// Fill out your copyright notice in the Description page of Project Settings.

#include "JoyConInput.h"

#include "hidapi.h"
#include "JoyConState.h"
#include "Engine/Engine.h"
#include "HAL/RunnableThread.h"
#include "Misc/CoreDelegates.h"
#include "Misc/ConfigCacheIni.h"

#define LOCTEXT_NAMESPACE "JoyConInput"

// Setup Keys
const FKey FJoyConKey::JoyCon_DPad_Up("JoyCon_DPad_Up");
const FKey FJoyConKey::JoyCon_DPad_Left("JoyCon_DPad_Left");
const FKey FJoyConKey::JoyCon_DPad_Right("JoyCon_DPad_Right");
const FKey FJoyConKey::JoyCon_DPad_Down("JoyCon_DPad_Down");

const FKey FJoyConKey::JoyCon_Minus("JoyCon_Minus");
const FKey FJoyConKey::JoyCon_Plus("JoyCon_Plus");
const FKey FJoyConKey::JoyCon_Home("JoyCon_Home");
const FKey FJoyConKey::JoyCon_Capture("JoyCon_Capture");

const FKey FJoyConKey::JoyCon_Left_ThumbStick("JoyCon_Left_ThumbStick");
const FKey FJoyConKey::JoyCon_Left_ThumbStick_X("JoyCon_Left_ThumbStick_X");
const FKey FJoyConKey::JoyCon_Left_ThumbStick_Y("JoyCon_Left_ThumbStick_Y");

const FKey FJoyConKey::JoyCon_Sr("JoyCon_Sr");
const FKey FJoyConKey::JoyCon_Sl("JoyCon_Sl");

const FKey FJoyConKey::JoyCon_L("JoyCon_L");
const FKey FJoyConKey::JoyCon_Zl("JoyCon_Zl");

// Setup Extra Keys
const FKey FJoyConKey::JoyCon_X("JoyCon_X");
const FKey FJoyConKey::JoyCon_Y("JoyCon_Y");
const FKey FJoyConKey::JoyCon_A("JoyCon_A");
const FKey FJoyConKey::JoyCon_B("JoyCon_B");

const FKey FJoyConKey::JoyCon_Right_ThumbStick("JoyCon_Right_ThumbStick");
const FKey FJoyConKey::JoyCon_Right_ThumbStick_X("JoyCon_Right_ThumbStick_X");
const FKey FJoyConKey::JoyCon_Right_ThumbStick_Y("JoyCon_Right_ThumbStick_Y");

const FKey FJoyConKey::JoyCon_Zr("JoyCon_Zr");
const FKey FJoyConKey::JoyCon_R("JoyCon_R");

// Setup Keys Names
const FJoyConKeyNames::Type FJoyConKeyNames::JoyCon_DPad_Up("JoyCon_DPad_Up");
const FJoyConKeyNames::Type FJoyConKeyNames::JoyCon_DPad_Left("JoyCon_DPad_Left");
const FJoyConKeyNames::Type FJoyConKeyNames::JoyCon_DPad_Right("JoyCon_DPad_Right");
const FJoyConKeyNames::Type FJoyConKeyNames::JoyCon_DPad_Down("JoyCon_DPad_Down");

const FJoyConKeyNames::Type FJoyConKeyNames::JoyCon_Minus("JoyCon_Minus");
const FJoyConKeyNames::Type FJoyConKeyNames::JoyCon_Plus("JoyCon_Plus");
const FJoyConKeyNames::Type FJoyConKeyNames::JoyCon_Home("JoyCon_Home");
const FJoyConKeyNames::Type FJoyConKeyNames::JoyCon_Capture("JoyCon_Capture");

const FJoyConKeyNames::Type FJoyConKeyNames::JoyCon_Left_ThumbStick("JoyCon_Left_ThumbStick");
const FJoyConKeyNames::Type FJoyConKeyNames::JoyCon_Left_ThumbStick_X("JoyCon_Left_ThumbStick_X");
const FJoyConKeyNames::Type FJoyConKeyNames::JoyCon_Left_ThumbStick_Y("JoyCon_Left_ThumbStick_Y");

const FJoyConKeyNames::Type FJoyConKeyNames::JoyCon_Sr("JoyCon_Sr");
const FJoyConKeyNames::Type FJoyConKeyNames::JoyCon_Sl("JoyCon_Sl");

const FJoyConKeyNames::Type FJoyConKeyNames::JoyCon_L("JoyCon_L");
const FJoyConKeyNames::Type FJoyConKeyNames::JoyCon_Zl("JoyCon_Zl");

// Setup Extra Keys Names
const FJoyConKeyNames::Type FJoyConKeyNames::JoyCon_X("JoyCon_X");
const FJoyConKeyNames::Type FJoyConKeyNames::JoyCon_Y("JoyCon_Y");
const FJoyConKeyNames::Type FJoyConKeyNames::JoyCon_A("JoyCon_A");
const FJoyConKeyNames::Type FJoyConKeyNames::JoyCon_B("JoyCon_B");

const FJoyConKeyNames::Type FJoyConKeyNames::JoyCon_Right_ThumbStick("JoyCon_Right_ThumbStick");
const FJoyConKeyNames::Type FJoyConKeyNames::JoyCon_Right_ThumbStick_X("JoyCon_Right_ThumbStick_X");
const FJoyConKeyNames::Type FJoyConKeyNames::JoyCon_Right_ThumbStick_Y("JoyCon_Right_ThumbStick_Y");

const FJoyConKeyNames::Type FJoyConKeyNames::JoyCon_Zr("JoyCon_Zr");
const FJoyConKeyNames::Type FJoyConKeyNames::JoyCon_R("JoyCon_R");

float FJoyConInput::InitialButtonRepeatDelay = 0.2f;
float FJoyConInput::ButtonRepeatDelay = 0.1f;

FJoyConInput::FJoyConInput(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler) : MessageHandler(InMessageHandler) {
	IModularFeatures::Get().RegisterModularFeature(GetModularFeatureName(), this);
	if (hid_init() == 0) HidInitialized = true;
	else {
		HidInitialized = false;
		UE_LOG(LogTemp, Fatal, TEXT("HIDAPI failed to initialize"));
	}
	Grips[0].GripIndex = 0;
	Grips[1].GripIndex = 1;
	Grips[2].GripIndex = 2;
	Grips[3].GripIndex = 3;
	Grips[4].GripIndex = 4;
	Grips[5].GripIndex = 5;
	Grips[6].GripIndex = 6;
	Grips[7].GripIndex = 7;
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

	// Register the FKeys
	EKeys::AddMenuCategoryDisplayInfo("JoyCon", LOCTEXT("JoyConSubCategory", "JoyCon"), TEXT("GraphEditor.PadEvent_16x"));

	EKeys::AddKey(FKeyDetails(FJoyConKey::JoyCon_DPad_Up, LOCTEXT("JoyCon_DPad_Up", "JoyCon D-pad Up"), FKeyDetails::GamepadKey, "JoyCon"));
	EKeys::AddKey(FKeyDetails(FJoyConKey::JoyCon_DPad_Left, LOCTEXT("JoyCon_DPad_Left", "JoyCon D-pad Left"), FKeyDetails::GamepadKey, "JoyCon"));
	EKeys::AddKey(FKeyDetails(FJoyConKey::JoyCon_DPad_Right, LOCTEXT("JoyCon_DPad_Right", "JoyCon D-pad Right"), FKeyDetails::GamepadKey, "JoyCon"));
	EKeys::AddKey(FKeyDetails(FJoyConKey::JoyCon_DPad_Down, LOCTEXT("JoyCon_DPad_Down", "JoyCon D-pad Down"), FKeyDetails::GamepadKey, "JoyCon"));

	EKeys::AddKey(FKeyDetails(FJoyConKey::JoyCon_Minus, LOCTEXT("JoyCon_Minus", "JoyCon Minus"), FKeyDetails::GamepadKey, "JoyCon"));
	EKeys::AddKey(FKeyDetails(FJoyConKey::JoyCon_Plus, LOCTEXT("JoyCon_Plus", "JoyCon Plus"), FKeyDetails::GamepadKey, "JoyCon"));
	EKeys::AddKey(FKeyDetails(FJoyConKey::JoyCon_Home, LOCTEXT("JoyCon_Home", "JoyCon Home"), FKeyDetails::GamepadKey, "JoyCon"));
	EKeys::AddKey(FKeyDetails(FJoyConKey::JoyCon_Capture, LOCTEXT("JoyCon_Capture", "JoyCon Capture"), FKeyDetails::GamepadKey, "JoyCon"));

	EKeys::AddKey(FKeyDetails(FJoyConKey::JoyCon_Left_ThumbStick, LOCTEXT("JoyCon_Left_ThumbStick", "JoyCon Left Thumbstick Click"), FKeyDetails::GamepadKey, "JoyCon"));
	EKeys::AddKey(FKeyDetails(FJoyConKey::JoyCon_Left_ThumbStick_X, LOCTEXT("JoyCon_Left_ThumbStick_X", "JoyCon Left Thumbstick X"), FKeyDetails::GamepadKey | FKeyDetails::Axis1D | FKeyDetails::NotBlueprintBindableKey, "JoyCon"));
	EKeys::AddKey(FKeyDetails(FJoyConKey::JoyCon_Left_ThumbStick_Y, LOCTEXT("JoyCon_Left_ThumbStick_Y", "JoyCon Left Thumbstick Y"), FKeyDetails::GamepadKey | FKeyDetails::Axis1D | FKeyDetails::NotBlueprintBindableKey, "JoyCon"));

	EKeys::AddKey(FKeyDetails(FJoyConKey::JoyCon_Sr, LOCTEXT("JoyCon_Sr", "JoyCon Sr"), FKeyDetails::GamepadKey, "JoyCon"));
	EKeys::AddKey(FKeyDetails(FJoyConKey::JoyCon_Sl, LOCTEXT("JoyCon_Sl", "JoyCon Sl"), FKeyDetails::GamepadKey, "JoyCon"));

	EKeys::AddKey(FKeyDetails(FJoyConKey::JoyCon_L, LOCTEXT("JoyCon_L", "JoyCon L"), FKeyDetails::GamepadKey, "JoyCon"));
	EKeys::AddKey(FKeyDetails(FJoyConKey::JoyCon_Zl, LOCTEXT("JoyCon_Zl", "JoyCon ZL"), FKeyDetails::GamepadKey, "JoyCon"));

	// Extra Keys
	EKeys::AddKey(FKeyDetails(FJoyConKey::JoyCon_X, LOCTEXT("JoyCon_X", "JoyCon X"), FKeyDetails::GamepadKey, "JoyCon"));
	EKeys::AddKey(FKeyDetails(FJoyConKey::JoyCon_Y, LOCTEXT("JoyCon_Y", "JoyCon Y"), FKeyDetails::GamepadKey, "JoyCon"));
	EKeys::AddKey(FKeyDetails(FJoyConKey::JoyCon_A, LOCTEXT("JoyCon_A", "JoyCon A"), FKeyDetails::GamepadKey, "JoyCon"));
	EKeys::AddKey(FKeyDetails(FJoyConKey::JoyCon_B, LOCTEXT("JoyCon_B", "JoyCon B"), FKeyDetails::GamepadKey, "JoyCon"));

	EKeys::AddKey(FKeyDetails(FJoyConKey::JoyCon_Right_ThumbStick, LOCTEXT("JoyCon_Right_ThumbStick", "JoyCon Right Thumbstick Click"), FKeyDetails::GamepadKey, "JoyCon"));
	EKeys::AddKey(FKeyDetails(FJoyConKey::JoyCon_Right_ThumbStick_X, LOCTEXT("JoyCon_Right_ThumbStick_X", "JoyCon Right Thumbstick X"), FKeyDetails::GamepadKey | FKeyDetails::Axis1D | FKeyDetails::NotBlueprintBindableKey, "JoyCon"));
	EKeys::AddKey(FKeyDetails(FJoyConKey::JoyCon_Right_ThumbStick_Y, LOCTEXT("JoyCon_Right_ThumbStick_Y", "JoyCon Right Thumbstick Y"), FKeyDetails::GamepadKey | FKeyDetails::Axis1D | FKeyDetails::NotBlueprintBindableKey, "JoyCon"));

	EKeys::AddKey(FKeyDetails(FJoyConKey::JoyCon_Zr, LOCTEXT("JoyCon_Zr", "JoyCon ZR"), FKeyDetails::GamepadKey, "JoyCon"));
	EKeys::AddKey(FKeyDetails(FJoyConKey::JoyCon_R, LOCTEXT("JoyCon_R", "JoyCon R"), FKeyDetails::GamepadKey, "JoyCon"));

	UE_LOG(LogTemp, Log, TEXT("JoyConInput pre-init called"));
}

void FJoyConInput::LoadConfig() {
	GConfig->GetFloat(TEXT("/Script/Engine.InputSettings"), TEXT("InitialButtonRepeatDelay"), InitialButtonRepeatDelay, GInputIni);
	GConfig->GetFloat(TEXT("/Script/Engine.InputSettings"), TEXT("ButtonRepeatDelay"), ButtonRepeatDelay, GInputIni);
}

TArray<FJoyConInformation>* FJoyConInput::SearchJoyCons() {
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
	int ControllerId = 0;
	while (Device != nullptr) {
		if (Device->product_id == 0x2006 || Device->product_id == 0x2007) {
			FString SerialNumber(Device->serial_number);
			FString BluetoothPath(Device->path);
			bool IsConnected = false;
			if (Controllers.Num() > 0) {
				for (FJoyConController* Controller : Controllers) {
					if (Controller->JoyConInformation.SerialNumber.Equals(SerialNumber) && Controller->JoyConInformation.BluetoothPath.Equals(BluetoothPath)) {
						IsConnected = true;
						break;
					}
				}
			}
			bool IsLeft = false;
			if (Device->product_id == 0x2006) {
				IsLeft = true;
			} else if (Device->product_id == 0x2007) {
				IsLeft = false;
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
				ControllerId,
				Device->usage,
				Device->usage_page,
				IsLeft,
				IsConnected
			);
			Data->Add(JoyConInformation);
			ControllerId++;
		}
		Device = Device->next;
	}
	hid_free_enumeration(Devices);
	return Data;
}

TArray<FJoyConInformation>* FJoyConInput::GetAttachedJoyCons() {
	TArray<FJoyConInformation>* Data = new TArray<FJoyConInformation>();
	if (!HidInitialized) return Data;
	for (FJoyConController* Controller : Controllers) {
		if (Controller->JoyConInformation.IsAttached) Data->Add(Controller->JoyConInformation);
	}
	return Data;
}

TArray<FJoyConInformation>* FJoyConInput::GetConnectedJoyCons() {
	TArray<FJoyConInformation>* Data = new TArray<FJoyConInformation>();
	if (!HidInitialized) return Data;
	for (FJoyConController* Controller : Controllers) {
		Data->Add(Controller->JoyConInformation);
	}
	return Data;
}

bool FJoyConInput::ResumeJoyConConnection() {
	if (!HidInitialized) return false;
	bool Success = false;
	for (FJoyConController* Controller : Controllers) {
		if (Controller->JoyConInformation.IsAttached) {
			Success = Controller->StartListenThread();
			if (Success == false) return Success;
		}
	}
	return Success;
}

bool FJoyConInput::ConnectJoyCon(const FJoyConInformation JoyConInformation, const bool UseImu, const bool UseLocalize, const float Alpha, int& ControllerId) {
	if (!HidInitialized) return false;
	if (JoyConInformation.IsConnected) return false;
	char* Path = TCHAR_TO_ANSI(*JoyConInformation.BluetoothPath);
	hid_device* Handle = hid_open_path(Path);
	hid_set_nonblocking(Handle, 1);
	FJoyConController* Controller = new FJoyConController(JoyConInformation, Handle, UseImu, UseLocalize, Alpha, JoyConInformation.IsLeft);
	Controllers.Add(Controller);
	Controller->JoyConInformation.IsConnected = true;
	Controller->JoyConInformation.ControllerId = GetNextControllerId();
	ControllersMap.Add(Controller->JoyConInformation.ControllerId, Controller);
	ControllerId = Controller->JoyConInformation.ControllerId;
	return true;
}

bool FJoyConInput::AttachJoyCon(const int ControllerId, const int GripIndex) {
	if (!ControllersMap.Contains(ControllerId)) return false;
	FJoyConController* Controller = ControllersMap[ControllerId];
	if (GripIndex < 0 || GripIndex > 7) return false;
	if (Controller->JoyConInformation.IsAttached) return false;
	uint8 Leds = 0x0;
	Leds |= static_cast<uint8>(0x1 << GripIndex);
	Grips[GripIndex].Controllers.Add(Controller);
	Controller->Attach(Leds);
	Controller->StartListenThread();
	Controller->JoyConInformation.IsAttached = true;
	return true;
}

bool FJoyConInput::DisconnectJoyCon(const int ControllerId) {
	if (!HidInitialized) return false;
	if (!ControllersMap.Contains(ControllerId)) return false;
	FJoyConController* Controller = ControllersMap[ControllerId];
	if (Controller->JoyConInformation.IsAttached) return false;
	Controllers.RemoveAt(Controllers.IndexOfByKey(Controller));
	ControllersMap.Remove(ControllerId);
	Controller->Stop();
	delete Controller;
	return true;
}

bool FJoyConInput::DetachJoyCon(const int ControllerId) {
	if (!ControllersMap.Contains(ControllerId)) return false;
	FJoyConController* Controller = ControllersMap[ControllerId];
	for (int i = 0; i < 8; i++) {
		if (Grips[i].ContainsController(Controller->JoyConInformation)) {
			Grips[i].Controllers.Remove(Controller);
			Controller->Detach();
			Controller->JoyConInformation.IsAttached = false;
			return true;
		}
	}
	return false;
}

bool FJoyConInput::GetJoyConAccelerometer(const int ControllerId, FVector& Out) {
	if (!HidInitialized) return false;
	Out = FVector::ZeroVector;
	if (!ControllersMap.Contains(ControllerId)) return false;
	FJoyConController* Controller = ControllersMap[ControllerId];
	Out = Controller->GetAccelerometer();
	return true;
}

bool FJoyConInput::GetJoyConGyroscope(const int ControllerId, FVector& Out) {
	if (!HidInitialized) return false;
	Out = FVector::ZeroVector;
	if (!ControllersMap.Contains(ControllerId)) return false;
	FJoyConController* Controller = ControllersMap[ControllerId];
	Out = Controller->GetGyroscope();
	return true;
}

bool FJoyConInput::GetJoyConVector(const int ControllerId, FRotator& Out) {
	if (!HidInitialized) return false;
	Out = FRotator::ZeroRotator;
	if (!ControllersMap.Contains(ControllerId)) return false;
	FJoyConController* Controller = ControllersMap[ControllerId];
	Out = Controller->GetVector();
	return true;
}

bool FJoyConInput::ReCenterJoyCon(const int ControllerId) {
	if (!HidInitialized) return false;
	if (!ControllersMap.Contains(ControllerId)) return false;
	FJoyConController* Controller = ControllersMap[ControllerId];
	Controller->ReCenter();
	return true;
}

bool FJoyConInput::SetJoyConFilterCoefficient(const int ControllerId, const float Coefficient) {
	if (!HidInitialized) return false;
	if (!ControllersMap.Contains(ControllerId)) return false;
	FJoyConController* Controller = ControllersMap[ControllerId];
	Controller->SetFilterCoefficient(Coefficient);
	return true;
}

bool FJoyConInput::SetJoyConGripMode(const int GripIndex, const EGripMode GripMode) {
	if (GripIndex < 0 || GripIndex > 7) return false;
	Grips[GripIndex].Mode = GripMode;
	return true;
}

bool FJoyConInput::SetJoyConRumble(const int ControllerId, const float LowFrequency, const float HighFrequency, const float Amplitude, const int Time) {
	if (!HidInitialized) return false;
	if (!ControllersMap.Contains(ControllerId)) return false;
	FJoyConController* Controller = ControllersMap[ControllerId];
	Controller->SetRumble(LowFrequency, HighFrequency, Amplitude, Time);
	return true;
}

void FJoyConInput::Tick(float DeltaTime) {

}

void FJoyConInput::SendControllerEvents() {
	const double CurrentTime = FPlatformTime::Seconds();

	for (FJoyConController* Controller : Controllers) {
		Controller->Update();
	}

	for (int i = 0; i < 8; i++) {
		for (FJoyConController* Controller : Grips[i].Controllers) {
			for (int32 ButtonIndex = 0; ButtonIndex < static_cast<int32>(EJoyConControllerButton::TotalButtonCount); ++ButtonIndex) {
				FJoyConButtonState& ButtonState = Controller->ControllerState.Buttons[ButtonIndex];
				check(!ButtonState.Key.IsNone()); // is button's name initialized?

				// Determine if the button is pressed down
				const bool bButtonPressed = Controller->Buttons[ButtonIndex];

				if (Grips[i].Mode == EGripMode::Auto) {
					if (Grips[i].Controllers.Num() > 1) {
						SendAnalogEvents(Controller->JoyConInformation.IsLeft, Grips[i].GripIndex, Controller->GetStick(), &Controller->ControllerState.Stick);
						if (Controller->JoyConInformation.IsLeft) {
							SendButtonEvents(bButtonPressed, CurrentTime, Grips[i].GripIndex, ButtonState.Key, &ButtonState);
						} else {
							const FName KeyName = GetRightJoyConKeyName(ButtonIndex, ButtonState.Key);
							SendButtonEvents(bButtonPressed, CurrentTime, Grips[i].GripIndex, KeyName, &ButtonState);
						}
					} else {
						SendButtonEvents(bButtonPressed, CurrentTime, Grips[i].GripIndex, ButtonState.Key, &ButtonState);
					}
				} else if (Grips[i].Mode == EGripMode::Landscape) {
					SendAnalogEvents(true, Grips[i].GripIndex, Controller->GetStick(), &Controller->ControllerState.Stick);
					SendButtonEvents(bButtonPressed, CurrentTime, Grips[i].GripIndex, ButtonState.Key, &ButtonState);
				} else if (Grips[i].Mode == EGripMode::Portrait) {
					SendAnalogEvents(true, Grips[i].GripIndex, Controller->GetStick(), &Controller->ControllerState.Stick);
					SendButtonEvents(bButtonPressed, CurrentTime, Grips[i].GripIndex, ButtonState.Key, &ButtonState);
				} else if (Grips[i].Mode == EGripMode::GamePad) {
					SendAnalogEvents(Controller->JoyConInformation.IsLeft, Grips[i].GripIndex, Controller->GetStick(), &Controller->ControllerState.Stick);
					if (Controller->JoyConInformation.IsLeft) {
						SendButtonEvents(bButtonPressed, CurrentTime, Grips[i].GripIndex, ButtonState.Key, &ButtonState);
					} else {
						const FName KeyName = GetRightJoyConKeyName(ButtonIndex, ButtonState.Key);
						SendButtonEvents(bButtonPressed, CurrentTime, Grips[i].GripIndex, KeyName, &ButtonState);
					}
				}
			}
		}
	}
}

void FJoyConInput::SetMessageHandler(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler) {
	MessageHandler = InMessageHandler;
}

bool FJoyConInput::Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar) {
	return false;
}

void FJoyConInput::SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value) {}

void FJoyConInput::SetChannelValues(int32 ControllerId, const FForceFeedbackValues& Values) {}

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
	return;
	if (ControllerId < 0 || ControllerId > 7) return;
	for (FJoyConController* Controller : Grips[ControllerId].Controllers) {
		if (Values.Frequency > 160) Controller->SetRumble(0, Values.Frequency, Values.Amplitude);
		else Controller->SetRumble(Values.Frequency, 0, Values.Amplitude);
	}
}

void FJoyConInput::GetHapticFrequencyRange(float& MinFrequency, float& MaxFrequency) const {
	MinFrequency = 0.0f;
	MaxFrequency = 1.0f;
}

float FJoyConInput::GetHapticAmplitudeScale() const {
	return 1.0f;
}

int FJoyConInput::GetNextControllerId() const {
	TArray<int> Keys;
	int NextId = 0;
	ControllersMap.GetKeys(Keys);
	for (int Key : Keys) {
		if (Key == NextId) NextId++;
	}
	return NextId;
}

FName FJoyConInput::GetRightJoyConKeyName(const int Index, const FName OriginalKeyName) {
	switch (Index) {

	case EJoyConControllerButton::DPad_Up:
		return FJoyConKeyNames::JoyCon_X;
	case EJoyConControllerButton::DPad_Down:
		return FJoyConKeyNames::JoyCon_B;
	case EJoyConControllerButton::DPad_Left:
		return FJoyConKeyNames::JoyCon_Y;
	case EJoyConControllerButton::DPad_Right:
		return FJoyConKeyNames::JoyCon_A;

	case EJoyConControllerButton::Left_ThumbStick:
		return FJoyConKeyNames::JoyCon_Right_ThumbStick;

	case EJoyConControllerButton::L:
		return FJoyConKeyNames::JoyCon_R;
	case EJoyConControllerButton::Zl:
		return FJoyConKeyNames::JoyCon_Zr;

	default:
		return OriginalKeyName;
	}
}

void FJoyConInput::SendButtonEvents(const bool bButtonPressed, const float CurrentTime, const int GripIndex, const FName KeyName, FJoyConButtonState* ButtonState) const {
	// Update button state
	if (bButtonPressed != ButtonState->bIsPressed) {
		ButtonState->bIsPressed = bButtonPressed;
		if (ButtonState->bIsPressed) {
			MessageHandler->OnControllerButtonPressed(KeyName, GripIndex, false);

			// Set the timer for the first repeat
			ButtonState->NextRepeatTime = CurrentTime + FJoyConInput::ButtonRepeatDelay;
		} else {
			MessageHandler->OnControllerButtonReleased(KeyName, GripIndex, false);
		}
	}

	// Apply key repeat, if its time for that
	if (ButtonState->bIsPressed && ButtonState->NextRepeatTime <= CurrentTime) {
		MessageHandler->OnControllerButtonPressed(KeyName, GripIndex, true);

		// Set the timer for the next repeat
		ButtonState->NextRepeatTime = CurrentTime + FJoyConInput::ButtonRepeatDelay;
	}
}

void FJoyConInput::SendAnalogEvents(const bool bIsLeft, const int GripIndex, const FVector2D StickVector, FJoyConAnalogState* AnalogState) const {
	if (StickVector.X != AnalogState->X) {
		AnalogState->X = StickVector.X;
		MessageHandler->OnControllerAnalog(bIsLeft ? FJoyConKeyNames::JoyCon_Left_ThumbStick_X : FJoyConKeyNames::JoyCon_Right_ThumbStick_X, GripIndex, AnalogState->X);
	}
	if (StickVector.Y != AnalogState->Y) {
		AnalogState->Y = StickVector.Y;
		MessageHandler->OnControllerAnalog(bIsLeft ? FJoyConKeyNames::JoyCon_Left_ThumbStick_Y : FJoyConKeyNames::JoyCon_Right_ThumbStick_Y, GripIndex, AnalogState->Y);
	}
}
